package ppa

import PRAD.interconnect.GIB.{getOPin2IPinConnect, getOPin2TrackConnect, getTrack2IPinConnect, getTrack2TrackConnect}
import chisel3.util.log2Ceil

import scala.{+:, ::}
import scala.collection.mutable
import scala.collection.mutable.{ListBuffer, Map}


object ppa_gib {


  def getMux(numTrack: Int, diagPinConect: Boolean, numIOPinList: List[Int], fcList: List[Int],track_directions:ListBuffer[Int]): (List[Int],List[Int],List[Int]) = {
    val totalconnect = (getTrack2TrackConnect(numTrack,track_directions) ++ getOPin2TrackConnect(numTrack, fcList(1), List(numIOPinList(1), numIOPinList(3), numIOPinList(5), numIOPinList(7)),track_directions )++
      getTrack2IPinConnect(numTrack, fcList(0), List(numIOPinList(0), numIOPinList(2), numIOPinList(4), numIOPinList(6)),track_directions)++
      getOPin2IPinConnect(fcList(2), diagPinConect, numIOPinList))       //++ : list ++ list
    val totalconnect_config = (getTrack2TrackConnect(numTrack) ++ getOPin2TrackConnect(numTrack, fcList(1), List(numIOPinList(1), numIOPinList(3), numIOPinList(5), numIOPinList(7)) )++
      getTrack2IPinConnect(numTrack, fcList(0), List(numIOPinList(0), numIOPinList(2), numIOPinList(4), numIOPinList(6)))++
      getOPin2IPinConnect(fcList(2), diagPinConect, numIOPinList))
    val totalsink = ListBuffer[Seq[Int]]()
    val totalsink_config = ListBuffer[Seq[Int]]()
    totalconnect.map{ins => totalsink.append(ins.tail.tail)}   
    totalconnect_config.map{ins => totalsink_config.append(ins.tail.tail)}
    //println("1" + totalconnect)
    //println("2" + totalsink)
    val totalsinkdst = totalsink.distinct    
    val totalsinkdst_config = totalsink_config.distinct
    //println("3" + totalsinkdst)
    //println("4" + totalsinkdst_config)
    val MuxList = totalsinkdst.map{dst =>totalsink.count( _== dst) }.toList   
    val MuxList_org = totalsinkdst_config.map{dst =>totalsink_config.count( _== dst)}.toList
    val trackmux = totalsinkdst.map{dst => if (dst(0) <=3) totalsink.count(_==dst) else 0 }.toList

    val muxlist_config = ListBuffer[Int]()

    for(i <- 0 until MuxList.size){
      for(j <- 0 until MuxList_org.size){
        if(totalsinkdst(i)==totalsinkdst_config(j)){
          muxlist_config.append(MuxList_org(j))
        }
      }
    }

    //println(MuxList)
    //println(MuxList_org)
    //println(trackmux)
    //println(muxlist_config)
    (MuxList,muxlist_config.toList,trackmux.filter(ins => ins!=0))
  }


  def getgibarea(datawidth:Int,numTrack: Int, diagPinConect: Boolean, num_iopin_list : Map[String,Int],
                 track_reged:Boolean,connect_flexibility:mutable.Map[String, Int],track_directions:ListBuffer[Int]): (Double,Double) = {

    val numIOPinMap = num_iopin_list
    val nNWi = numIOPinMap("ipin_nw")  // number of the PE input pins on the NORTHWEST side of the GIB
    val nNWo = numIOPinMap("opin_nw")  // number of the PE output pins on the NORTHWEST side of the GIB
    val nNEi = numIOPinMap("ipin_ne")  // number of the PE input pins on the NORTHEAST side of the GIB
    val nNEo = numIOPinMap("opin_ne")  // number of the PE output pins on the NORTHEAST side of the GIB
    val nSEi = numIOPinMap("ipin_se")  // number of the PE input pins on the SOUTHEAST side of the GIB
    val nSEo = numIOPinMap("opin_se")  // number of the PE output pins on the SOUTHEAST side of the GIB
    val nSWi = numIOPinMap("ipin_sw")  // number of the PE input pins on the SOUTHWEST side of the GIB
    val nSWo = numIOPinMap("opin_sw")  // number of the PE output pins on the SOUTHWEST side of the GIB
    val numIOPinList = List(nNWi, nNWo, nNEi, nNEo, nSEi, nSEo, nSWi, nSWo)

    val fcMap = connect_flexibility
    val fci  = fcMap("num_itrack_per_ipin")     // ipin-itrack connection flexibility, connected track number, 2n
    val fco  = fcMap("num_otrack_per_opin")     // opin-otrack connection flexibility, connected track number, 2n
    val fcio = fcMap("num_ipin_per_opin")       // opin-ipin  connection flexibility, connected ipin number, 2n
    val fcList = List(fci, fco, fcio)

//    println("track_directions:" + track_directions)
    val muxlist = getMux(numTrack, diagPinConect, numIOPinList, fcList,track_directions)._1.sortBy(ins => ins)
    val muxlist_config = getMux(numTrack, diagPinConect, numIOPinList, fcList,track_directions)._2.sortBy(ins => ins)
    val trackmuxlist = getMux(numTrack, diagPinConect, numIOPinList, fcList,track_directions)._3
    var area : Double = 0
    var index =0
    var rate : Double= 1
   //println("muxlist = "+muxlist)
    muxlist.map{mux => {
      if(index == area_par.cycle){
        index = 0
        rate = rate*(1 - area_par.reduce_rate)     
      }else {
        index += 1
      }
      area = area + area_par.area_mux_width_map(datawidth)(mux)*rate
      //println("area=" + area)
    }}



    if(track_reged){
      area = area + trackmuxlist.size * area_par.area_regnxt_width(datawidth)    
      area = area + trackmuxlist.size * area_par.area_mux_width_map(datawidth)(2)    
      area = area + trackmuxlist.size * area_par.area_cfgpre32   
      //println("area=" + area)
    }
    var muxconfigarea: Double = 0

    muxlist_config.map { ins => {
      muxconfigarea = muxconfigarea + log2Ceil(ins) * area_par.area_cfgpre32   
      }
    }

    area = muxconfigarea + area

//    println("gib mux area :" + muxconfigarea)
//    println("gib area:" + area )
    (area,muxconfigarea)
  }
}

