package PRAD.interconnect

import PRAD.common.MacroVar._
import PRAD.common._
import PRAD.ir._
import chisel3._
import chisel3.util._

import scala.collection.mutable
import scala.collection.mutable.{ArrayBuffer, ListBuffer}


object GIB{
  def Mod(x: Int, y: Int): Int = java.lang.Math.floorMod(x, y)
  // connection rule: Map[(src, dst), (src_idx, N) => dst_idx]
  val rule: Map[(Int, Int), Seq[Int] => Int] = Map(
    (WEST, EAST)   -> ((x: Seq[Int]) => Mod(x(0), x(1))),    // i%N
    (EAST, WEST)   -> ((x: Seq[Int]) => Mod(x(0), x(1))),
    (NORTH, SOUTH) -> ((x: Seq[Int]) => Mod(x(0), x(1))),
    (SOUTH, NORTH) -> ((x: Seq[Int]) => Mod(x(0), x(1))),
    (WEST, NORTH)  -> ((x: Seq[Int]) => Mod(-x(0), x(1))),   //(N-i)%N
    (NORTH, WEST)  -> ((x: Seq[Int]) => Mod(-x(0), x(1))),
    (EAST, SOUTH)  -> ((x: Seq[Int]) => Mod(-x(0)-2, x(1))), // (2*N-2-i)%N
    (SOUTH, EAST)  -> ((x: Seq[Int]) => Mod(-x(0)-2, x(1))),
    (NORTH, EAST)  -> ((x: Seq[Int]) => Mod(x(0)+1, x(1))),  // (i+1)%N
    (EAST, NORTH)  -> ((x: Seq[Int]) => Mod(x(0)-1, x(1))),  // (N+i-1)%N
    (SOUTH, WEST)  -> ((x: Seq[Int]) => Mod(x(0)+1, x(1))),
    (WEST, SOUTH)  -> ((x: Seq[Int]) => Mod(x(0)-1, x(1))),
    (NORTHWEST, EAST)  -> ((x: Seq[Int]) => Mod(x(0), x(1))),
    (NORTHWEST, NORTH) -> ((x: Seq[Int]) => Mod(-x(0), x(1))),
    (NORTHWEST, SOUTH) -> ((x: Seq[Int]) => Mod(x(0)-1, x(1))),
    (SOUTHWEST, NORTH) -> ((x: Seq[Int]) => Mod(x(0), x(1))),
    (SOUTHWEST, WEST)  -> ((x: Seq[Int]) => Mod(x(0)+1, x(1))),
    (SOUTHWEST, EAST)  -> ((x: Seq[Int]) => Mod(-x(0)-2, x(1))),
    (SOUTHEAST, WEST)  -> ((x: Seq[Int]) => Mod(x(0), x(1))),
    (SOUTHEAST, SOUTH) -> ((x: Seq[Int]) => Mod(-x(0)-2, x(1))),
    (SOUTHEAST, NORTH) -> ((x: Seq[Int]) => Mod(x(0)-1, x(1))),
    (NORTHEAST, SOUTH) -> ((x: Seq[Int]) => Mod(x(0), x(1))),
    (NORTHEAST, EAST)  -> ((x: Seq[Int]) => Mod(x(0)+1, x(1))),
    (NORTHEAST, WEST)  -> ((x: Seq[Int]) => Mod(-x(0), x(1))),
    (NORTHWEST, SOUTHEAST) -> ((x: Seq[Int]) => Mod(x(0), x(1))),    // i%N
    (SOUTHEAST, NORTHWEST) -> ((x: Seq[Int]) => Mod(x(0), x(1))),
    (NORTHEAST, SOUTHWEST) -> ((x: Seq[Int]) => Mod(x(0), x(1))),
    (SOUTHWEST, NORTHEAST) -> ((x: Seq[Int]) => Mod(x(0), x(1))),
    (NORTHWEST, NORTHEAST) -> ((x: Seq[Int]) => Mod(-x(0), x(1))),   //(N-i)%N
    (NORTHEAST, NORTHWEST) -> ((x: Seq[Int]) => Mod(-x(0), x(1))),
    (SOUTHEAST, SOUTHWEST) -> ((x: Seq[Int]) => Mod(-x(0)-2, x(1))), // (2*N-2-i)%N
    (SOUTHWEST, SOUTHEAST) -> ((x: Seq[Int]) => Mod(-x(0)-2, x(1))),
    (NORTHEAST, SOUTHEAST) -> ((x: Seq[Int]) => Mod(x(0)+1, x(1))),  // (i+1)%N
    (SOUTHEAST, NORTHEAST) -> ((x: Seq[Int]) => Mod(x(0)-1, x(1))),  // (N+i-1)%N
    (SOUTHWEST, NORTHWEST) -> ((x: Seq[Int]) => Mod(x(0)+1, x(1))),
    (NORTHWEST, SOUTHWEST) -> ((x: Seq[Int]) => Mod(x(0)-1, x(1)))
  )
  /** Track to track connection, the same as wilton SB connection
   *
   * @param numTrack  track number
   */
  def getTrack2TrackConnect(numTrack: Int): ListBuffer[Seq[Int]] = {
    val w = numTrack
    var connect = ListBuffer[Seq[Int]]() // (srcSide, srcTrack, dstSide, dstTrack)
    for(i <- 0 until w){
      connect += Seq(WEST, i, EAST, rule((WEST,EAST))(Seq(i, w)))
      connect += Seq(NORTH, i, SOUTH, rule((NORTH,SOUTH))(Seq(i, w)))
      connect += Seq(WEST, i, SOUTH, rule((WEST,SOUTH))(Seq(i, w)))
      connect += Seq(SOUTH, i, EAST, rule((SOUTH,EAST))(Seq(i, w)))
      connect += Seq(EAST, i, NORTH, rule((EAST,NORTH))(Seq(i, w)))
      connect += Seq(NORTH, i, WEST, rule((NORTH,WEST))(Seq(i, w)))
      connect += Seq(EAST, rule((WEST,EAST))(Seq(i, w)), WEST, i)
      connect += Seq(SOUTH, rule((NORTH,SOUTH))(Seq(i, w)), NORTH, i)
      connect += Seq(SOUTH, rule((WEST,SOUTH))(Seq(i, w)), WEST, i)
      connect += Seq(EAST, rule((SOUTH,EAST))(Seq(i, w)), SOUTH, i)
      connect += Seq(NORTH, rule((EAST,NORTH))(Seq(i, w)), EAST, i)
      connect += Seq(WEST, rule((NORTH,WEST))(Seq(i, w)), NORTH, i)
    }
    connect
  }
  def getTrack2TrackConnect(numTrack: Int,track_dirctions:ListBuffer[Int]): ListBuffer[Seq[Int]] = {
    val w = numTrack
    var connect = ListBuffer[Seq[Int]]() // (srcSide, srcTrack, dstSide, dstTrack)
    for(i <- 0 until w){
      connect += Seq(WEST, i, EAST, rule((WEST,EAST))(Seq(i, w)))
      connect += Seq(NORTH, i, SOUTH, rule((NORTH,SOUTH))(Seq(i, w)))
      connect += Seq(WEST, i, SOUTH, rule((WEST,SOUTH))(Seq(i, w)))
      connect += Seq(SOUTH, i, EAST, rule((SOUTH,EAST))(Seq(i, w)))
      connect += Seq(EAST, i, NORTH, rule((EAST,NORTH))(Seq(i, w)))
      connect += Seq(NORTH, i, WEST, rule((NORTH,WEST))(Seq(i, w)))
      connect += Seq(EAST, rule((WEST,EAST))(Seq(i, w)), WEST, i)
      connect += Seq(SOUTH, rule((NORTH,SOUTH))(Seq(i, w)), NORTH, i)
      connect += Seq(SOUTH, rule((WEST,SOUTH))(Seq(i, w)), WEST, i)
      connect += Seq(EAST, rule((SOUTH,EAST))(Seq(i, w)), SOUTH, i)
      connect += Seq(NORTH, rule((EAST,NORTH))(Seq(i, w)), EAST, i)
      connect += Seq(WEST, rule((NORTH,WEST))(Seq(i, w)), NORTH, i)
    }
    connect.distinct.filter(ins => {
      !((ins(0) <= 3 && track_dirctions(ins(0)) == 0) || (ins(2) <= 3 && track_dirctions(ins(2)) == 0))
    })
  }

  /** PE output pins to tracks connection,
   *  connect an opin in one side to the tracks on the opposite and right sides
   *
   * @param numTrack    track number
   * @param fc      connection flexibility of the output pins, 2n
   * @param numPinList  number of the PE Output Pins on four sides
   */
  def getOPin2TrackConnect(numTrack: Int, fc: Int, numPinList: List[Int]): ListBuffer[Seq[Int]] = {
    // numPinList
    val numNWpin = numPinList(0)  // NORTHWEST side
    val numNEpin = numPinList(1)  // NORTHEAST side
    val numSEpin = numPinList(2)  // SOUTHEAST side
    val numSWpin = numPinList(3)  // SOUTHWEST side

    val w = numTrack
    val fcStep = 2*w.toFloat/fc
    var connect = ListBuffer[Seq[Int]]() // (srcSide, srcTrack, dstSide, dstTrack)
    var pinStep = {
      if(numNWpin > 0) fcStep/numNWpin else 0.0
    }
    for(i <- 0 until numNWpin){
      for(j <- 0 until fc/2) { // connect the opposite and right sides
        val index = (i*pinStep + j*fcStep).toInt
        connect += Seq(NORTHWEST, i, EAST, rule((NORTHWEST,EAST))(Seq(index, w)))
        connect += Seq(NORTHWEST, i, SOUTH, rule((NORTHWEST,SOUTH))(Seq(index, w)))
      }
    }
    if(numNEpin > 0){
      pinStep = fcStep/numNEpin
    }
    for(i <- 0 until numNEpin){
      for(j <- 0 until fc/2) { // connect the opposite and right sides
        val index = (i*pinStep + j*fcStep).toInt
        connect += Seq(NORTHEAST, i, SOUTH, rule((NORTHEAST,SOUTH))(Seq(index, w)))
        connect += Seq(NORTHEAST, i, WEST, rule((NORTHEAST,WEST))(Seq(index, w)))
      }
    }
    if(numSEpin > 0){
      pinStep = fcStep/numSEpin
    }
    for(i <- 0 until numSEpin){
      for(j <- 0 until fc/2) { // connect the opposite and right sides
        val index = (i*pinStep + j*fcStep).toInt
        connect += Seq(SOUTHEAST, i, WEST, rule((SOUTHEAST,WEST))(Seq(index, w)))
        connect += Seq(SOUTHEAST, i, NORTH, rule((SOUTHEAST,NORTH))(Seq(index, w)))
      }
    }
    if(numSWpin > 0){
      pinStep = fcStep/numSWpin
    }
    for(i <- 0 until numSWpin){
      for(j <- 0 until fc/2) { // connect the opposite and right sides
        val index = (i*pinStep + j*fcStep).toInt
        connect += Seq(SOUTHWEST, i, NORTH, rule((SOUTHWEST,NORTH))(Seq(index, w)))
        connect += Seq(SOUTHWEST, i, EAST, rule((SOUTHWEST,EAST))(Seq(index, w)))
      }
    }
    connect
  }

  def getOPin2TrackConnect(numTrack: Int, fc: Int, numPinList: List[Int],track_dirctions:ListBuffer[Int]): ListBuffer[Seq[Int]] = {
    // numPinList
    val numNWpin = numPinList(0)  // NORTHWEST side
    val numNEpin = numPinList(1)  // NORTHEAST side
    val numSEpin = numPinList(2)  // SOUTHEAST side
    val numSWpin = numPinList(3)  // SOUTHWEST side

    val w = numTrack
    val fcStep = 2*w.toFloat/fc
    var connect = ListBuffer[Seq[Int]]() // (srcSide, srcTrack, dstSide, dstTrack)
    var pinStep = {
      if(numNWpin > 0) fcStep/numNWpin else 0.0
    }
    for(i <- 0 until numNWpin){
      for(j <- 0 until fc/2) { // connect the opposite and right sides
        val index = (i*pinStep + j*fcStep).toInt
        connect += Seq(NORTHWEST, i, EAST, rule((NORTHWEST,EAST))(Seq(index, w)))
        connect += Seq(NORTHWEST, i, SOUTH, rule((NORTHWEST,SOUTH))(Seq(index, w)))
      }
    }
    if(numNEpin > 0){
      pinStep = fcStep/numNEpin
    }
    for(i <- 0 until numNEpin){
      for(j <- 0 until fc/2) { // connect the opposite and right sides
        val index = (i*pinStep + j*fcStep).toInt
        connect += Seq(NORTHEAST, i, SOUTH, rule((NORTHEAST,SOUTH))(Seq(index, w)))
        connect += Seq(NORTHEAST, i, WEST, rule((NORTHEAST,WEST))(Seq(index, w)))
      }
    }
    if(numSEpin > 0){
      pinStep = fcStep/numSEpin
    }
    for(i <- 0 until numSEpin){
      for(j <- 0 until fc/2) { // connect the opposite and right sides
        val index = (i*pinStep + j*fcStep).toInt
        connect += Seq(SOUTHEAST, i, WEST, rule((SOUTHEAST,WEST))(Seq(index, w)))
        connect += Seq(SOUTHEAST, i, NORTH, rule((SOUTHEAST,NORTH))(Seq(index, w)))
      }
    }
    if(numSWpin > 0){
      pinStep = fcStep/numSWpin
    }
    for(i <- 0 until numSWpin){
      for(j <- 0 until fc/2) { // connect the opposite and right sides
        val index = (i*pinStep + j*fcStep).toInt
        connect += Seq(SOUTHWEST, i, NORTH, rule((SOUTHWEST,NORTH))(Seq(index, w)))
        connect += Seq(SOUTHWEST, i, EAST, rule((SOUTHWEST,EAST))(Seq(index, w)))
      }
    }
    connect.distinct.filter(ins =>
      ! ((ins(0) <= 3 && track_dirctions(ins(0)) == 0) || (ins(2) <= 3 && track_dirctions(ins(2)) == 0)) )
  }



  /** tracks to PE input pins connection,
   *  connect an ipin in one side to the tracks on the opposite and right sides
   *
   * @param numTrack    track number
   * @param fc          connection flexibility of the input pins, 2n
   * @param numPinList  number of the PE Input Pins on four sides
   */
  def getTrack2IPinConnect(numTrack: Int, fc: Int, numPinList: List[Int]): ListBuffer[Seq[Int]] = {
    // numPinList
    val numNWpin = numPinList(0)  // NORTHWEST side
    val numNEpin = numPinList(1)  // NORTHEAST side
    val numSEpin = numPinList(2)  // SOUTHEAST side
    val numSWpin = numPinList(3)  // SOUTHWEST side

    val w = numTrack
    val fcStep = 2*w.toFloat/fc
    var connect = ListBuffer[Seq[Int]]() // (srcSide, srcTrack, dstSide, dstTrack)
    var pinStep = {
      if(numNWpin > 0) fcStep/numNWpin else 0.0
    }
    for(i <- 0 until numNWpin){
      for(j <- 0 until fc/2) { // connect the opposite and right sides
        val index = (i*pinStep + j*fcStep).toInt
        connect += Seq(EAST, rule((NORTHWEST,EAST))(Seq(index, w)), NORTHWEST, i)
        connect += Seq(SOUTH, rule((NORTHWEST,SOUTH))(Seq(index, w)), NORTHWEST, i)
      }
    }
    if(numNEpin > 0){
      pinStep = fcStep/numNEpin
    }
    for(i <- 0 until numNEpin){
      for(j <- 0 until fc/2) { // connect the opposite and right sides
        val index = (i*pinStep + j*fcStep).toInt
        connect += Seq(SOUTH, rule((NORTHEAST,SOUTH))(Seq(index, w)), NORTHEAST, i)
        connect += Seq(WEST, rule((NORTHEAST,WEST))(Seq(index, w)), NORTHEAST, i)
      }
    }
    if(numSEpin > 0){
      pinStep = fcStep/numSEpin
    }
    for(i <- 0 until numSEpin){
      for(j <- 0 until fc/2) { // connect the opposite and right sides
        val index = (i*pinStep + j*fcStep).toInt
        connect += Seq(WEST, rule((SOUTHEAST,WEST))(Seq(index, w)), SOUTHEAST, i)
        connect += Seq(NORTH, rule((SOUTHEAST,NORTH))(Seq(index, w)), SOUTHEAST, i)
      }
    }
    if(numSWpin > 0){
      pinStep = fcStep/numSWpin
    }
    for(i <- 0 until numSWpin){
      for(j <- 0 until fc/2) { // connect the opposite and right sides
        val index = (i*pinStep + j*fcStep).toInt
        connect += Seq(NORTH, rule((SOUTHWEST,NORTH))(Seq(index, w)), SOUTHWEST, i)
        connect += Seq(EAST, rule((SOUTHWEST,EAST))(Seq(index, w)), SOUTHWEST, i)
      }
    }
    connect
  }

  def getTrack2IPinConnect(numTrack: Int, fc: Int, numPinList: List[Int],track_dirctions:ListBuffer[Int]): ListBuffer[Seq[Int]] = {
    // numPinList
    val numNWpin = numPinList(0)  // NORTHWEST side
    val numNEpin = numPinList(1)  // NORTHEAST side
    val numSEpin = numPinList(2)  // SOUTHEAST side
    val numSWpin = numPinList(3)  // SOUTHWEST side

    val w = numTrack
    val fcStep = 2*w.toFloat/fc
    var connect = ListBuffer[Seq[Int]]() // (srcSide, srcTrack, dstSide, dstTrack)
    var pinStep = {
      if(numNWpin > 0) fcStep/numNWpin else 0.0
    }
    for(i <- 0 until numNWpin){
      for(j <- 0 until fc/2) { // connect the opposite and right sides
        val index = (i*pinStep + j*fcStep).toInt
        connect += Seq(EAST, rule((NORTHWEST,EAST))(Seq(index, w)), NORTHWEST, i)
        connect += Seq(SOUTH, rule((NORTHWEST,SOUTH))(Seq(index, w)), NORTHWEST, i)
      }
    }
    if(numNEpin > 0){
      pinStep = fcStep/numNEpin
    }
    for(i <- 0 until numNEpin){
      for(j <- 0 until fc/2) { // connect the opposite and right sides
        val index = (i*pinStep + j*fcStep).toInt
        connect += Seq(SOUTH, rule((NORTHEAST,SOUTH))(Seq(index, w)), NORTHEAST, i)
        connect += Seq(WEST, rule((NORTHEAST,WEST))(Seq(index, w)), NORTHEAST, i)
      }
    }
    if(numSEpin > 0){
      pinStep = fcStep/numSEpin
    }
    for(i <- 0 until numSEpin){
      for(j <- 0 until fc/2) { // connect the opposite and right sides
        val index = (i*pinStep + j*fcStep).toInt
        connect += Seq(WEST, rule((SOUTHEAST,WEST))(Seq(index, w)), SOUTHEAST, i)
        connect += Seq(NORTH, rule((SOUTHEAST,NORTH))(Seq(index, w)), SOUTHEAST, i)
      }
    }
    if(numSWpin > 0){
      pinStep = fcStep/numSWpin
    }
    for(i <- 0 until numSWpin){
      for(j <- 0 until fc/2) { // connect the opposite and right sides
        val index = (i*pinStep + j*fcStep).toInt
        connect += Seq(NORTH, rule((SOUTHWEST,NORTH))(Seq(index, w)), SOUTHWEST, i)
        connect += Seq(EAST, rule((SOUTHWEST,EAST))(Seq(index, w)), SOUTHWEST, i)
      }
    }
    connect.distinct.filter(ins =>
      ! ((ins(0) <= 3 && track_dirctions(ins(0)) == 0) || (ins(2) <= 3 && track_dirctions(ins(2)) == 0)) )
  }


  /** PE output pins to PE input pins connection,
   *  connect an opin in one side to the ipins on the other one or two sides
   *
   * @param fc      connection flexibility of the output pins, 1n or 2n
   * @param diag    if support diagonal connections
   * @param numIOPinList  number of the PE I/O Pins on four sides
   */
  def getOPin2IPinConnect(fc: Int, diag: Boolean, numIOPinList: List[Int]): ListBuffer[Seq[Int]] = {
    // numIOPinList
    val nNWi = numIOPinList(0)  // number of the PE input pins on the NORTHWEST side of the GIB
    val nNWo = numIOPinList(1)  // number of the PE output pins on the NORTHWEST side of the GIB
    val nNEi = numIOPinList(2)  // number of the PE input pins on the NORTHEAST side of the GIB
    val nNEo = numIOPinList(3)  // number of the PE output pins on the NORTHEAST side of the GIB
    val nSEi = numIOPinList(4)  // number of the PE input pins on the SOUTHEAST side of the GIB
    val nSEo = numIOPinList(5)  // number of the PE output pins on the SOUTHEAST side of the GIB
    val nSWi = numIOPinList(6)  // number of the PE input pins on the SOUTHWEST side of the GIB
    val nSWo = numIOPinList(7)  // number of the PE output pins on the SOUTHWEST side of the GIB
    val fcPerSide = { if(diag) fc/2 else fc }
    var connect = ListBuffer[Seq[Int]]() // (srcSide, srcTrack, dstSide, dstTrack)
    val fcNWstep = nNWi/fcPerSide.toFloat
    val fcNEstep = nNEi/fcPerSide.toFloat
    val fcSEstep = nSEi/fcPerSide.toFloat
    val fcSWstep = nSWi/fcPerSide.toFloat
    for(i <- 0 until nNWo){
      for(j <- 0 until fcPerSide) { // connect to the other sides
        if(nSEi > 0 && diag){
          val iSE = (i*fcSEstep/nNWo + j*fcSEstep).toInt
          connect += Seq(NORTHWEST, i, SOUTHEAST, rule((NORTHWEST,SOUTHEAST))(Seq(iSE, nSEi)))
        }
        //        if(nSWi > 0){
        //          val iSW = (i*fcSWstep/nNWo + j*fcSWstep).toInt
        //          connect += Seq(NORTHWEST, i, SOUTHWEST, rule((NORTHWEST,SOUTHWEST))(Seq(iSW, nSWi)))
        //        }
        if(nNEi > 0){
          val iNE = (i*fcNEstep/nNWo + j*fcNEstep).toInt
          connect += Seq(NORTHWEST, i, NORTHEAST, rule((NORTHWEST,NORTHEAST))(Seq(iNE, nNEi)))
        }
      }
    }
    for(i <- 0 until nNEo){
      for(j <- 0 until fcPerSide) { // connect to the other sides
        if(nSEi > 0){
          val iSE = (i*fcSEstep/nNEo + j*fcSEstep).toInt
          connect += Seq(NORTHEAST, i, SOUTHEAST, rule((NORTHEAST,SOUTHEAST))(Seq(iSE, nSEi)))
        }
        if(nSWi > 0  && diag){
          val iSW = (i*fcSWstep/nNEo + j*fcSWstep).toInt
          connect += Seq(NORTHEAST, i, SOUTHWEST, rule((NORTHEAST,SOUTHWEST))(Seq(iSW, nSWi)))
        }
        //        if(nNWi > 0){
        //          val iNW = (i*fcNWstep/nNEo + j*fcNWstep).toInt
        //          connect += Seq(NORTHEAST, i, NORTHWEST, rule((NORTHEAST,NORTHWEST))(Seq(iNW, nNWi)))
        //        }
      }
    }
    for(i <- 0 until nSEo){
      for(j <- 0 until fcPerSide) { // connect to the other sides
        if(nSWi > 0){
          val iSW = (i*fcSWstep/nSEo + j*fcSWstep).toInt
          connect += Seq(SOUTHEAST, i, SOUTHWEST, rule((SOUTHEAST,SOUTHWEST))(Seq(iSW, nSWi)))
        }
        if(nNWi > 0  && diag){
          val iNW = (i*fcNWstep/nSEo + j*fcNWstep).toInt
          connect += Seq(SOUTHEAST, i, NORTHWEST, rule((SOUTHEAST,NORTHWEST))(Seq(iNW, nNWi)))
        }
        //        if(nNEi > 0){
        //          val iNE = (i*fcNEstep/nSEo + j*fcNEstep).toInt
        //          connect += Seq(SOUTHEAST, i, NORTHEAST, rule((SOUTHEAST,NORTHEAST))(Seq(iNE, nNEi)))
        //        }
      }
    }
    for(i <- 0 until nSWo){
      for(j <- 0 until fcPerSide) { // connect to the other sides
        //        if(nSEi > 0){
        //          val iSE = (i*fcSEstep/nSWo + j*fcSEstep).toInt
        //          connect += Seq(SOUTHWEST, i, SOUTHEAST, rule((SOUTHWEST,SOUTHEAST))(Seq(iSE, nSEi)))
        //        }
        if(nNWi > 0){
          val iNW = (i*fcNWstep/nSWo + j*fcNWstep).toInt
          connect += Seq(SOUTHWEST, i, NORTHWEST, rule((SOUTHWEST,NORTHWEST))(Seq(iNW, nNWi)))
        }
        if(nNEi > 0  && diag){
          val iNE = (i*fcNEstep/nSWo + j*fcNEstep).toInt
          connect += Seq(SOUTHWEST, i, NORTHEAST, rule((SOUTHWEST,NORTHEAST))(Seq(iNE, nNEi)))
        }
      }
    }
//    println(connect)
    connect.distinct
  }

  /** GIB internal connection,
   *  oPin2IPin, track2IPin, oPin2Track, track2Track
   *
   * @param numTrack      track number
   * @param diagPinConect if support diagonal connections between OPins and IPins
   * @param numIOPinList  number of the PE I/O Pins on four sides
   * @param fcList        connect flexibility
   */
  def getGIBConnect(numTrack: Int, diagPinConect: Boolean, numIOPinList: List[Int], fcList: List[Int]): ListBuffer[(Seq[Int], ListBuffer[Seq[Int]])] = {
    var dstList = ListBuffer[Seq[Int]]()
    var srcsList = ListBuffer[ListBuffer[Seq[Int]]]() // srcs connected to each dst
    val oPin2IPinConnect = getOPin2IPinConnect(fcList(2), diagPinConect, numIOPinList)
    oPin2IPinConnect.map{ dWire =>
      val dst = Seq(TYPE_IPIN, dWire(2), dWire(3)) // type, direction, index
      if(!dstList.contains(dst)){
        dstList += dst
      }
      val index = dstList.indexOf(dst)
      if(srcsList.size <= index){
        srcsList += ListBuffer(Seq(TYPE_OPIN, dWire(0), dWire(1)))
      } else{
        srcsList(index) += Seq(TYPE_OPIN, dWire(0), dWire(1))
      }
    }
    if(numTrack > 0) {
      val track2IPinConnect = getTrack2IPinConnect(numTrack, fcList(0), List(numIOPinList(0), numIOPinList(2), numIOPinList(4), numIOPinList(6)))
      track2IPinConnect.map { dWire =>
        val dst = Seq(TYPE_IPIN, dWire(2), dWire(3)) // type, direction, index
        if (!dstList.contains(dst)) {
          dstList += dst
        }
        val index = dstList.indexOf(dst)
        if (srcsList.size <= index) {
          srcsList += ListBuffer(Seq(TYPE_ITRACK, dWire(0), dWire(1)))
        } else {
          srcsList(index) += Seq(TYPE_ITRACK, dWire(0), dWire(1))
        }
      }
      val oPin2TrackConnect = getOPin2TrackConnect(numTrack, fcList(1), List(numIOPinList(1), numIOPinList(3), numIOPinList(5), numIOPinList(7)))
      oPin2TrackConnect.map { dWire =>
        val dst = Seq(TYPE_OTRACK, dWire(2), dWire(3)) // type, direction, index
        if (!dstList.contains(dst)) {
          dstList += dst
        }
        val index = dstList.indexOf(dst)
        if (srcsList.size <= index) {
          srcsList += ListBuffer(Seq(TYPE_OPIN, dWire(0), dWire(1)))
        } else {
          srcsList(index) += Seq(TYPE_OPIN, dWire(0), dWire(1))
        }
      }
      val track2TrackConnect = getTrack2TrackConnect(numTrack)
      track2TrackConnect.map { dWire =>
        val dst = Seq(TYPE_OTRACK, dWire(2), dWire(3)) // type, direction, index
        if (!dstList.contains(dst)) {
          dstList += dst
        }
        val index = dstList.indexOf(dst)
        if (srcsList.size <= index) {
          srcsList += ListBuffer(Seq(TYPE_ITRACK, dWire(0), dWire(1)))
        } else {
          srcsList(index) += Seq(TYPE_ITRACK, dWire(0), dWire(1))
        }
      }
    }

    // remove duplicates and sort by side and index
    srcsList = srcsList.map{ x => x.distinct.sortBy(dst => (dst(0), dst(1), dst(2))) }
    dstList.zip(srcsList).sortBy{case (dst, srcs) => (dst(0), dst(1), dst(2)) } // return ListBuffer(dst, srcs)
  }

  def getGIBConnect_ifo(numTrack: Int, diagPinConect: Boolean, numIOPinList: List[Int], fcList: List[Int]): ListBuffer[Seq[Int]] ={
    val oPin2IPinConnect = getOPin2IPinConnect(fcList(2), diagPinConect, numIOPinList)
    val track2IPinConnect = getTrack2IPinConnect(numTrack, fcList(0), List(numIOPinList(0), numIOPinList(2), numIOPinList(4), numIOPinList(6)))
    val oPin2TrackConnect = getOPin2TrackConnect(numTrack, fcList(1), List(numIOPinList(1), numIOPinList(3), numIOPinList(5), numIOPinList(7)))
    val track2TrackConnect = getTrack2TrackConnect(numTrack)
    val connect = track2TrackConnect.++(oPin2IPinConnect).++(track2IPinConnect).++(oPin2TrackConnect)
    connect
  }

}






/** Generic Interconnect Block including PE I/O pins and routing tracks
 *
 * @param attrs     module attributes
 */
class GIB(attrs: mutable.Map[String, Any]) extends Module with IR {
  apply(attrs)
  val x = getAttrValue("x").asInstanceOf[Int]
  val y = getAttrValue("y").asInstanceOf[Int]
  val width = getAttrValue("data_width").asInstanceOf[Int]
  // cfgParams
  val cfgDataWidth = getAttrValue("cfg_data_width").asInstanceOf[Int]
  val cfgAddrWidth = getAttrValue("cfg_addr_width").asInstanceOf[Int]
//  val cfgBlkIndex  = getAttrValue("cfg_blk_index").asInstanceOf[Int]     // configuration index of this block, cfg_addr[width-1 : offset]
//  val cfgBlkOffset = getAttrValue("cfg_blk_offset").asInstanceOf[Int]   // configuration offset bit of blocks

  val numTrack = getAttrValue("num_track").asInstanceOf[Int]
  // if support diagonal connections between OPins and IPins
  val diagPinConect = getAttrValue("diag_iopin_connect").asInstanceOf[Boolean]
  // numIOPinList
  val numIOPinMap = getAttrValue("num_iopin_list").asInstanceOf[mutable.Map[String, Int]]
  val nNWi = numIOPinMap("ipin_nw")  // number of the PE input pins on the NORTHWEST side of the GIB
  val nNWo = numIOPinMap("opin_nw")  // number of the PE output pins on the NORTHWEST side of the GIB
  val nNEi = numIOPinMap("ipin_ne")  // number of the PE input pins on the NORTHEAST side of the GIB
  val nNEo = numIOPinMap("opin_ne")  // number of the PE output pins on the NORTHEAST side of the GIB
  val nSEi = numIOPinMap("ipin_se")  // number of the PE input pins on the SOUTHEAST side of the GIB
  val nSEo = numIOPinMap("opin_se")  // number of the PE output pins on the SOUTHEAST side of the GIB
  val nSWi = numIOPinMap("ipin_sw")  // number of the PE input pins on the SOUTHWEST side of the GIB
  val nSWo = numIOPinMap("opin_sw")  // number of the PE output pins on the SOUTHWEST side of the GIB
  val numIOPinList = List(nNWi, nNWo, nNEi, nNEo, nSEi, nSEo, nSWi, nSWo)
  // fcList
  val fcMap = getAttrValue("connect_flexibility").asInstanceOf[mutable.Map[String, Int]]
  val fci  = fcMap("num_itrack_per_ipin")     // ipin-itrack connection flexibility, connected track number, 2n
  val fco  = fcMap("num_otrack_per_opin")     // opin-otrack connection flexibility, connected track number, 2n
  val fcio = fcMap("num_ipin_per_opin")       // opin-ipin  connection flexibility, connected ipin number, 2n
  val fcList = List(fci, fco, fcio)

  // if there are registers in the track output ports
  val trackReged = getAttrValue("track_reged").asInstanceOf[Boolean]

  val io = IO(new Bundle{
    val cfg_en   = Input(Bool())
    val cfg_addr = Input(UInt(cfgAddrWidth.W))
    val cfg_data = Input(UInt(cfgDataWidth.W))
    val ipinNW = Output(Vec(nNWi, UInt(width.W)))
    val opinNW = Input (Vec(nNWo, UInt(width.W)))
    val ipinNE = Output(Vec(nNEi, UInt(width.W)))
    val opinNE = Input (Vec(nNEo, UInt(width.W)))
    val ipinSE = Output(Vec(nSEi, UInt(width.W)))
    val opinSE = Input (Vec(nSEo, UInt(width.W)))
    val ipinSW = Output(Vec(nSWi, UInt(width.W)))
    val opinSW = Input (Vec(nSWo, UInt(width.W)))

    val itrackW = Input (Vec(numTrack, UInt(width.W)))
    val otrackW = Output(Vec(numTrack, UInt(width.W)))
    val itrackN = Input (Vec(numTrack, UInt(width.W)))
    val otrackN = Output(Vec(numTrack, UInt(width.W)))
    val itrackE = Input (Vec(numTrack, UInt(width.W)))
    val otrackE = Output(Vec(numTrack, UInt(width.W)))
    val itrackS = Input (Vec(numTrack, UInt(width.W)))
    val otrackS = Output(Vec(numTrack, UInt(width.W)))
  })

  io.ipinNW.map{ _ := 0.U }
  io.ipinNE.map{ _ := 0.U }
  io.ipinSW.map{ _ := 0.U }
  io.ipinSE.map{ _ := 0.U }
  io.otrackW.map{ _ := 0.U }
  io.otrackN.map{ _ := 0.U }
  io.otrackE.map{ _ := 0.U }
  io.otrackS.map{ _ := 0.U }

  val wireMap = Map(
    (TYPE_OPIN, NORTHWEST) -> io.opinNW,
    (TYPE_OPIN, NORTHEAST) -> io.opinNE,
    (TYPE_OPIN, SOUTHEAST) -> io.opinSE,
    (TYPE_OPIN, SOUTHWEST) -> io.opinSW,
    (TYPE_IPIN, NORTHWEST) -> io.ipinNW,
    (TYPE_IPIN, NORTHEAST) -> io.ipinNE,
    (TYPE_IPIN, SOUTHEAST) -> io.ipinSE,
    (TYPE_IPIN, SOUTHWEST) -> io.ipinSW,
    (TYPE_OTRACK, WEST ) -> io.otrackW,
    (TYPE_OTRACK, NORTH) -> io.otrackN,
    (TYPE_OTRACK, EAST ) -> io.otrackE,
    (TYPE_OTRACK, SOUTH) -> io.otrackS,
    (TYPE_ITRACK, WEST ) -> io.itrackW,
    (TYPE_ITRACK, NORTH) -> io.itrackN,
    (TYPE_ITRACK, EAST ) -> io.itrackE,
    (TYPE_ITRACK, SOUTH) -> io.itrackS)
  // wire connections
  val connect_ifo = GIB.getGIBConnect_ifo(numTrack, diagPinConect, numIOPinList, fcList)
//  println(connect_ifo)
  val connect = GIB.getGIBConnect(numTrack, diagPinConect, numIOPinList, fcList)
//  println(connect)
//  var cfgsBit = 0
//  if (connect.size != 0) {
//    cfgsBit = connect.map{case (dst, srcs) =>log2Ceil(srcs.size)}.reduce(_+_) + numTrack * 4// total configuration bits
//  }
  val cfgsBit = {
  if (connect.size == 0) numTrack * 4
  else connect.map{case (dst, srcs) =>log2Ceil(srcs.size)}.reduce(_+_) + numTrack * 4
}
//  val cfgsBit = connect.map{case (dst, srcs) =>log2Ceil(srcs.size)}.reduce(_+_) + numTrack * 4// total configuration bits

  //  println(cfgsBit)
  /** configuration bit sequence
   * LSB ------------> MSB
   * sorted by wire type
   *   sorted by side
   *     sorted by index
   */
   
  val GIBconnectIfo: mutable.Map[Any, Any] = mutable.Map() //ListBuffer[Seq[Int]]
  if(cfgsBit > 0) {
    val cfg = Module(new ConfigMem(cfgsBit, 1, cfgDataWidth)) // configuration memory
    cfg.io.cfg_en := io.cfg_en // && (cfgBlkIndex.U === io.cfg_addr(cfgAddrWidth - 1, cfgBlkOffset)) //aha得到8位地址，可能不需要再添加使能
    cfg.io.cfg_addr := io.cfg_addr
    cfg.io.cfg_data := io.cfg_data
//    assert(cfg.cfgAddrWidth <= cfgBlkOffset)
//    assert(cfgBlkIndex < (1 << (cfgAddrWidth-cfgBlkOffset)))

    var offset = numTrack*4
    connect.map { case (dst, srcs) =>
      if(srcs.size > 1) {
        val mux = Module(new Muxn(width, srcs.size))
        // connect src nodes to Mux inputs, and connect Mux output to dst node
        srcs.zipWithIndex.map { case (src, i) => mux.io.in(i) := wireMap((src(0), src(1)))(src(2)) }
        if (trackReged && (dst(0) == TYPE_OTRACK)){
          wireMap((dst(0), dst(1)))(dst(2)) := Mux(cfg.io.out(0)(dst(1)*numTrack+dst(2)) === 1.U,RegNext(mux.io.out),mux.io.out)
        } else {
          wireMap((dst(0), dst(1)))(dst(2)) := mux.io.out
        }

        // connect input configuration port to the Mux configuration ports
        val w = log2Ceil(srcs.size)
        mux.io.config := cfg.io.out(0)(offset + w - 1, offset)
        GIBconnectIfo += ((dst(1),dst(2)) -> (srcs-> (offset + w - 1, offset)))
        offset += w
      }else{
        val src = srcs(0)
        wireMap((dst(0), dst(1)))(dst(2)) := wireMap((src(0), src(1)))(src(2))
        GIBconnectIfo += ((dst(1),dst(2)) -> (srcs->(0,0)))
      }
    }
  }else{
    connect.map { case (dst, srcs) =>
      val src = srcs(0)
      wireMap((dst(0), dst(1)))(dst(2)) := wireMap((src(0), src(1)))(src(2))
      GIBconnectIfo += ((dst(1),dst(2)) -> (srcs->(0,0)))
    }
  }
//  println(GIBconnectIfo)
}





 object VerilogGen extends App {
   // test getGIBConnect
//   val connect = GIB.getGIBConnect(0, false, List(2,1,2,1,1,1,1,1), List(2, 4, 2))
//   println(connect.size)
//   var sum = 0
//   var i = 0
//   connect.map{ case (dst, srcs) =>
//     sum += srcs.size
//     println(i + ": " +  srcs.size)
//     i += 1
//     println(dst)
//     println(srcs)
//   }
//   println(sum)

   val num_iopin_list = mutable.Map(
     "ipin_nw" -> 3,
     "opin_nw" -> 1,
     "ipin_ne" -> 3,
     "opin_ne" -> 1,
     "ipin_se" -> 3,
     "opin_se" -> 1,
     "ipin_sw" -> 3,
     "opin_sw" -> 1
   )
   val connect_flexibility = mutable.Map(
     "num_itrack_per_ipin" -> 10,
     "num_otrack_per_opin" -> 10,
     "num_ipin_per_opin"   -> 6
   )
   val attrs: mutable.Map[String, Any] = mutable.Map(
     "data_width" -> 16,  
     "cfg_data_width" -> 32,
     "cfg_addr_width" -> 8,
//     "cfg_blk_index" -> 1,
//     "cfg_blk_offset" -> 4,
     "x" -> 0,
     "y" -> 0,
     "num_track" -> 5,    //track = 2
     "track_reged" -> true,
     "diag_iopin_connect" -> true,
     "num_iopin_list" -> num_iopin_list,
     "connect_flexibility" -> connect_flexibility
   )

   (new chisel3.stage.ChiselStage).emitVerilog(new GIB(attrs),args)
 }
