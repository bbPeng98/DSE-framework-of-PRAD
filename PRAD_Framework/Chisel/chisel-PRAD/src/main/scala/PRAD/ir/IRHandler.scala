package PRAD.ir

// Architecture Description IR

import PRAD.common.MacroVar._

import scala.io.Source
import java.io._
import com.fasterxml.jackson.core.`type`.TypeReference
import com.fasterxml.jackson.databind.json.JsonMapper
import com.fasterxml.jackson.databind.SerializationFeature
import com.fasterxml.jackson.module.scala.DefaultScalaModule

import scala.collection.mutable
import scala.collection.mutable.ListBuffer
import scala.reflect.internal.util.TableDef.Column



object IRHandler{
  /** Load JSON-format IR file into metadata
   *  @param filename   IR file name
   */
  def loadIR(filename: String): mutable.Map[String,Any]={
    val json = Source.fromFile(filename)
    // parse JSON with Jackson
    val mapper = JsonMapper.builder().addModule(DefaultScalaModule).build()
    val jsonMap = mapper.readValue(json.reader(), new TypeReference[mutable.Map[String, Any]]{})
    jsonMap
  }

  /** Dump JSON-format IR file from metadata
   *  @param filename   IR file name
   */
  def dumpIR(metadata: mutable.Map[String,Any], filename: String)={
    // dump JSON with Jackson
    val mapper = JsonMapper.builder().enable(SerializationFeature.INDENT_OUTPUT)
      .addModule(DefaultScalaModule).build()
    val jsonStr = mapper.writeValueAsString(metadata)
    // write file
    val pw = new PrintWriter(new File(filename))
    pw.write(jsonStr)
    pw.close
  }


  /** write blanks
  * */
  val blank: mutable.Map[Int, String] = mutable.Map(
    1 -> " ",
    2 -> "  ",
    3 -> "   ",
    4 -> "    ",
    5 -> "     ",
  )

  /** Dump graph from metadata
   *  @param filename   IR file name
   */
  def dumpGraph(conIfoMap: mutable.Map[Any, ListBuffer[Seq[Int]]],
                conIfoIndexMap : mutable.Map[Any,Int],
                GIBconIfo : mutable.Map[Any,Any],
                datawidth: Int,numtrackCoarse:Int,
                numtrackFine: Int,
                filename: String,
                row:Int,
                column:Int,
                pePort:mutable.Map[Any,Int],
                memPort:mutable.Map[Any,Int],
                opesize: Int,omemsize: Int, inpesize: Int, inmemsize: Int)={
    val num2track: mutable.Map[Int, String] = mutable.Map(
      0 -> "WEST",
      1 -> "NORTH",
      2 -> "EAST",
      3 -> "SOUTH"
    )
    var numtrack = 0

    if (datawidth == 16){
      numtrack = numtrackCoarse
    }else{
      numtrack = numtrackFine
    }

    val pw = new PrintWriter(new File(filename))
    //interconnection in all GIBs
    conIfoMap.keys.map{ key =>
      pw.println("SWITCH"+" "+datawidth+" "+conIfoIndexMap(key)+" "+numtrack)
      pw.println("BEGIN")
      conIfoMap(key).map{ xx =>
        pw.write(blank(2))
        xx.zipWithIndex.map{case (yy,k) =>
          if (k == xx.size-1) pw.println(yy)
          else pw.write(yy+" ")
        }
      }
      pw.println("END")
    }
    //uesd in tile that do not contain GIB
    pw.println("SWITCH"+" "+datawidth+" "+(conIfoIndexMap.values.max+1)+" "+numtrack)
    pw.println("BEGIN")
    pw.println("END")


    for (i <- 0 to column){
      for (j <- 0 to row){
        val x = 2*i
        val y = 2*j+1
        val unitX: mutable.Map[Int, Int] = mutable.Map(
          WEST -> (x-2),
          EAST -> (x+2),
          SOUTH -> x,
          NORTH -> x,
          NORTHWEST -> (x-1),
          NORTHEAST -> (x+1),
          SOUTHEAST -> (x+1),
          SOUTHWEST -> (x-1)
        )
        val unitY: mutable.Map[Int, Int] = mutable.Map(
          WEST -> y,
          EAST -> y,
          SOUTH -> (y+2),
          NORTH -> (y-2),
          NORTHWEST -> (y-1),
          NORTHEAST -> (y-1),
          SOUTHEAST -> (y+1),
          SOUTHWEST -> (y+1)
        )
        val opst: mutable.Map[Int,Int] = mutable.Map(
          WEST -> EAST,
          EAST -> WEST,
          SOUTH -> NORTH,
          NORTH -> SOUTH
        )
        //interconnection between GIB and unitPORT
//        def GIBPartGen(k:Int,x:Int,y:Int,l:Int,datawidth:Int,portExample:mutable.Map[Any,Int],unitType:String)={
//          val GIBlist = (k, x, y, l, 1, datawidth) //GIB to unit
//          pw.println(blank(2)+"GIB" + blank(1) + GIBlist)
//          pw.println(blank(2)+"BEGIN")
//          pw.println(blank(2)+blank(4) + "PORT" + blank(1) + "in" +unitType+ portExample(l,k) + blank(1) + (unitX(l), unitY(l), datawidth))
//          pw.println(blank(2)+"END")
//        }
        def GIBPartGen(k:Int,x:Int,y:Int,l:Int,datawidth:Int,portNum: Int,unitType:String)={
          val GIBlist = (k, x, y, l, 1, datawidth) //GIB to unit
          pw.println(blank(2)+"GIB" + blank(1) + GIBlist)
          pw.println(blank(2)+"BEGIN")
          pw.println(blank(2)+blank(4) + "PORT" + blank(1) + "in" +unitType+ portNum + blank(1) + (unitX(l), unitY(l), datawidth))
          pw.println(blank(2)+"END")
        }
        pw.println("TILE"+blank(1)+(x,y,1,conIfoIndexMap(GIBconIfo(x,y))))
        //GIB with IO
        if(j==0 && i<column){
          pw.println(blank(2)+"GIB" + blank(1) + (0,x,y,NORTHEAST,1,datawidth))
          pw.println(blank(2)+"BEGIN")
          pw.println(blank(2)+blank(4)+"PORT"+blank(1)+"f2io_"+datawidth+blank(1)+(unitX(NORTHEAST),0,datawidth))
          pw.println(blank(2)+"END")
        }
        //GIB with unit
        if ((i+1)%4 == 0){
          if (j > 0 && j < row){
            for (k <-0 until inpesize){
              GIBPartGen(k,x,y,SOUTHWEST,datawidth,k,"PE")
              GIBPartGen(k,x,y,NORTHWEST,datawidth,k,"PE")
            }
            if(i < column){
              for (k <-0 until inmemsize){
                GIBPartGen(k,x,y,SOUTHEAST,datawidth,k,"MEM")
                GIBPartGen(k,x,y,NORTHEAST,datawidth,k,"MEM")
              }
            }
          }else if(j == 0){
            for (k <-0 until inpesize){
              GIBPartGen(k,x,y,SOUTHWEST,datawidth,k,"PE")
            }
            if(i < column) {
              for (k <-0 until inmemsize){
                GIBPartGen(k,x,y,SOUTHEAST,datawidth,k,"MEM")
              }
            }
          }else{//j = row
            for (k <-0 until inpesize){
              GIBPartGen(k,x,y,NORTHWEST,datawidth,k,"PE")
            }
            if(i < column) {
              for (k <-0 until inmemsize){
                GIBPartGen(k,x,y,NORTHEAST,datawidth,k,"MEM")
              }
            }
          }
        }else if (i%4 == 0 && i > 0){ 
          if (j > 0 && j < row){
            for (k <-0 until inmemsize){
              GIBPartGen(k,x,y,SOUTHWEST,datawidth,k,"MEM")
              GIBPartGen(k,x,y,NORTHWEST,datawidth,k,"MEM")
            }
            if(i < column){
              for (k <-0 until inpesize){
                GIBPartGen(k,x,y,NORTHEAST,datawidth,k,"PE")
                GIBPartGen(k,x,y,SOUTHEAST,datawidth,k,"PE")
              }
            }
          }else if (j == 0){
            for (k <-0 until inmemsize){
              GIBPartGen(k,x,y,SOUTHWEST,datawidth,k,"MEM")
            }
            if(i < column) {
              for (k <-0 until inpesize){
                GIBPartGen(k,x,y,SOUTHEAST,datawidth,k,"PE")
              }
            }
          }else{//j = row
            for (k <-0 until inmemsize){
              GIBPartGen(k,x,y,NORTHWEST,datawidth,k,"MEM")
            }
            if(i < column) {
              for (k <-0 until inpesize){
                GIBPartGen(k,x,y,NORTHEAST,datawidth,k,"PE")
              }
            }
          }
        }else{ 
          if(i>0 && j>0 && i<column && j<row){
            for (l <- NORTHWEST to SOUTHWEST){
              for (k <-0 until inpesize){
                GIBPartGen(k,x,y,l,datawidth,k,"PE")
              }
            }
          }else if(i==0 && j==0){
            for (k <-0 until inpesize){
              GIBPartGen(k,x,y,SOUTHEAST,datawidth,k,"PE")
            }
          }else if(i==0 && j>0 && j<row){
            for (k <-0 until inpesize){
              GIBPartGen(k,x,y,SOUTHEAST,datawidth,k,"PE")
              GIBPartGen(k,x,y,NORTHEAST,datawidth,k,"PE")
            }
          }else if(i==0 && j==row){
            for (k <-0 until inpesize){
              GIBPartGen(k,x,y,NORTHEAST,datawidth,k,"PE")
            }
          }else if(i>0 && i<column && j==0){
            for (k <-0 until inpesize){
              GIBPartGen(k,x,y,SOUTHWEST,datawidth,k,"PE")
              GIBPartGen(k,x,y,SOUTHEAST,datawidth,k,"PE")
            }
          }else if(i==column && j==0){
            for (k <-0 until inpesize){
              GIBPartGen(k,x,y,SOUTHWEST,datawidth,k,"PE")
            }
          }else if(i==column && j>0 && j<row){
            for (k <-0 until inpesize){
              GIBPartGen(k,x,y,NORTHWEST,datawidth,k,"PE")
              GIBPartGen(k,x,y,SOUTHWEST,datawidth,k,"PE")
            }
          }else if(i==column && j==row){
            for (k <-0 until inpesize){
              GIBPartGen(k,x,y,NORTHWEST,datawidth,k,"PE")
            }
          }else{
            for (k <-0 until inpesize){
              GIBPartGen(k,x,y,NORTHWEST,datawidth,k,"PE")
              GIBPartGen(k,x,y,NORTHEAST,datawidth,k,"PE")
            }
          }
        }

        //interconnection between GIB and RMUX,REG
        for (t <- 0 until numtrack){
          for (l <- WEST to SOUTH){
            val GIBlist = (t, x, y, l, 1, datawidth) 
            pw.println(blank(2)+"GIB"+blank(1)+GIBlist)
            pw.println(blank(2)+"BEGIN")
            pw.println(blank(2)+blank(4)+"REG"+blank(1)+"T"+t+"_"+num2track(l)+blank(1)+(t,x,y,datawidth))
            pw.println(blank(2)+blank(4)+"RMUX"+blank(1)+(t,x,y,l,datawidth))
            pw.println(blank(2)+"END")
            pw.println(blank(2)+"REG"+blank(1)+"T"+t+"_"+num2track(l)+blank(1)+(t,x,y,datawidth))
            pw.println(blank(2)+"BEGIN")
            pw.println(blank(2)+blank(4)+"RMUX"+blank(1)+(t,x,y,l,datawidth))
            pw.println(blank(2)+"END")
            def RMUXGen(row: Int,track: Int,side: Int)={
              pw.println(blank(2)+"RMUX"+blank(1)+((t,x,y,l,datawidth)))
              pw.println(blank(2)+"BEGIN")
              if (row == 0 && track == 0 && side == NORTH){
                //pw.println(blank(2)+blank(4)+"PORT"+blank(1)+"f2io_"+datawidth+blank(1)+(x,0,datawidth))
              }else{
                pw.println(blank(2)+blank(4)+"GIB"+blank(1)+(t,unitX(l),unitY(l),opst(l),0,datawidth))
              }
              pw.println(blank(2)+"END")
            }
            //RMUX connection with PORT
            if (i == 0 && j == 0){
              if (t == 0){
                if (l != WEST) RMUXGen(j,t,l)
              }else {
                if (l != WEST && l != NORTH) RMUXGen(j,t,l)
              }
            }
            if (i == 0 && j == row){
              if ((l!=WEST) & (l!=SOUTH)) RMUXGen(j,t,l)
            }
            if (i == 0 && j > 0 && j < row){
              if (l!=WEST) RMUXGen(j,t,l)
            }
            if (i == column && j == 0){
              if (t == 0){
                if (l != EAST) RMUXGen(j,t,l)
              }else{
                if (l != EAST && l != NORTH) RMUXGen(j,t,l)
              }
            }
            if (i > 0 && i < column && j == 0){
              if (t == 0) RMUXGen(j,t,l)
              else {
                if (l != NORTH) RMUXGen(j,t,l)
              }
            }
            if (i == column && j > 0 && j < row){
              if (l != EAST) RMUXGen(j,t,l)
            }
            if (i == column && j == row){
              if (l != EAST && l != SOUTH) RMUXGen(j,t,l)
            }
            if (i > 0 && i < column && j == row){
              if (l != SOUTH) RMUXGen(j,t,l)
            }
            if (i > 0 && i < column && j > 0 && j < row) RMUXGen(j,t,l)
          }
        }
      }
    }
    //interconnection between PORT and unit
    for (i <- 0 until column){
      for (j <- 0 until row){
        val x = 2*i+1
        val y = 2*j+2
        val unitX: mutable.Map[Int, Int] = mutable.Map(
          WEST -> (x-2),
          EAST -> (x+2),
          SOUTH -> x,
          NORTH -> x,
          NORTHWEST -> (x-1),
          NORTHEAST -> (x+1),
          SOUTHEAST -> (x+1),
          SOUTHWEST -> (x-1)
        )
        val unitY: mutable.Map[Int, Int] = mutable.Map(
          WEST -> y,
          EAST -> y,
          SOUTH -> (y+2),
          NORTH -> (y-2),
          NORTHWEST -> (y-1),
          NORTHEAST -> (y-1),
          SOUTHEAST -> (y+1),
          SOUTHWEST -> (y+1)
        )
        pw.println("TILE"+blank(1)+(x,y,1,(conIfoIndexMap.values.max+1)))
        if ((i+1)%4 == 0){//mem
          for (num <-0 until omemsize){
            pw.println(blank(2)+"PORT"+blank(1)+"outMEM"+num+blank(1)+(x,y,datawidth))
            pw.println(blank(2)+"BEGIN")
            pw.println(blank(2)+blank(4)+"GIB"+blank(1)+(num,unitX(NORTHWEST),unitY(NORTHWEST),SOUTHEAST,0,datawidth))
            pw.println(blank(2)+blank(4)+"GIB"+blank(1)+(num,unitX(NORTHEAST),unitY(NORTHEAST),SOUTHWEST,0,datawidth))
            pw.println(blank(2)+blank(4)+"GIB"+blank(1)+(num,unitX(SOUTHEAST),unitY(SOUTHEAST),NORTHWEST,0,datawidth))
            pw.println(blank(2)+blank(4)+"GIB"+blank(1)+(num,unitX(SOUTHWEST),unitY(SOUTHWEST),NORTHEAST,0,datawidth))
            pw.println(blank(2)+"END")
          }
//          for (num <-0 until inmemsize){
//            pw.println(blank(2)+"PORT"+blank(1)+"inMEM"+num+blank(1)+(x,y,datawidth))
//            pw.println(blank(2)+"BEGIN")
//            pw.println(blank(2)+blank(4)+"GIB"+blank(1)+(num,unitX(NORTHWEST),unitY(NORTHWEST),SOUTHEAST,1,datawidth))
//            pw.println(blank(2)+blank(4)+"GIB"+blank(1)+(num,unitX(NORTHEAST),unitY(NORTHEAST),SOUTHWEST,1,datawidth))
//            pw.println(blank(2)+blank(4)+"GIB"+blank(1)+(num,unitX(SOUTHEAST),unitY(SOUTHEAST),NORTHWEST,1,datawidth))
//            pw.println(blank(2)+blank(4)+"GIB"+blank(1)+(num,unitX(SOUTHWEST),unitY(SOUTHWEST),NORTHEAST,1,datawidth))
//            pw.println(blank(2)+"END")
//          }
        }else{//pe
          for (num <-0 until opesize){
            pw.println(blank(2)+"PORT"+blank(1)+"outPE"+num+blank(1)+(x,y,datawidth))
            pw.println(blank(2)+"BEGIN")
            pw.println(blank(2)+blank(4)+"GIB"+blank(1)+(num,unitX(NORTHWEST),unitY(NORTHWEST),SOUTHEAST,0,datawidth))
            pw.println(blank(2)+blank(4)+"GIB"+blank(1)+(num,unitX(NORTHEAST),unitY(NORTHEAST),SOUTHWEST,0,datawidth))
            pw.println(blank(2)+blank(4)+"GIB"+blank(1)+(num,unitX(SOUTHEAST),unitY(SOUTHEAST),NORTHWEST,0,datawidth))
            pw.println(blank(2)+blank(4)+"GIB"+blank(1)+(num,unitX(SOUTHWEST),unitY(SOUTHWEST),NORTHEAST,0,datawidth))
            pw.println(blank(2)+"END")
          }
//          for (num <-0 until inpesize){
//            pw.println(blank(2)+"PORT"+blank(1)+"inPE"+num+blank(1)+(x,y,datawidth))
//            pw.println(blank(2)+"BEGIN")
//            pw.println(blank(2)+blank(4)+"GIB"+blank(1)+(num,unitX(NORTHWEST),unitY(NORTHWEST),SOUTHEAST,1,datawidth))
//            pw.println(blank(2)+blank(4)+"GIB"+blank(1)+(num,unitX(NORTHEAST),unitY(NORTHEAST),SOUTHWEST,1,datawidth))
//            pw.println(blank(2)+blank(4)+"GIB"+blank(1)+(num,unitX(SOUTHEAST),unitY(SOUTHEAST),NORTHWEST,1,datawidth))
//            pw.println(blank(2)+blank(4)+"GIB"+blank(1)+(num,unitX(SOUTHWEST),unitY(SOUTHWEST),NORTHEAST,1,datawidth))
//            pw.println(blank(2)+"END")
//          }
        }
      }
    }
    //interconnection between PORT and io2f
    for (i <- 0 until column){
      val x = 2*i
      pw.println("TILE"+blank(1)+(x+1,0,1,(conIfoIndexMap.values.max+1)))
      pw.println(blank(2)+"PORT"+blank(1)+"io2f_"+datawidth+blank(1)+(x+1,0,datawidth))
      pw.println(blank(2)+"BEGIN")
      pw.println(blank(2)+blank(4)+"GIB"+blank(1)+(0,x,1,NORTHEAST,0,datawidth))
      pw.println(blank(2)+"END")
    }
    pw.close

//    //generate bs ifo
//    val XYtoIndex = mutable.Map[Any, Int]()
//    GIBconIfo.keys.map{ key =>
//      XYtoIndex += ( key -> conIfoIndexMap(GIBconIfo(key)))
//    }
//    if(datawidth > 1) {
//      val pw1 = new PrintWriter(new File("src/main/resources/XYtoIndexCoarse.map"))
//      XYtoIndex.map(number => pw1.println(number))
//      pw1.close
//    }else {
//      val pw1 = new PrintWriter(new File("src/main/resources/XYtoIndexFine.map"))
//      XYtoIndex.map(number => pw1.println(number))
//      pw1.close
//    }

//    if(datawidth > 1) {
//      val pw2 = new PrintWriter(new File("src/main/resources/SWITCHCoarse.ifo"))
//      conIfoMap.keys.map{ key =>
//        pw2.println("SWITCH"+" "+datawidth+" "+conIfoIndexMap(key)+" "+numtrack)
//        pw2.println("BEGIN")
//        conIfoMap(key).map{ xx =>
//          pw2.write(blank(2))
//          xx.zipWithIndex.map{case (yy,k) =>
//            if (k == xx.size-1) pw2.println(yy)
//            else pw2.write(yy+" ")
//          }
//        }
//        pw2.println("END")
//      }
//      //uesd in tile that do not contain GIB
//      pw2.println("SWITCH"+" "+datawidth+" "+(conIfoIndexMap.values.max+1)+" "+numtrack)
//      pw2.println("BEGIN")
//      pw2.println("END")
//      pw2.close

//    }else {
//      val pw2 = new PrintWriter(new File("src/main/resources/SWITCHFine.ifo"))
//      conIfoMap.keys.map{ key =>
//        pw2.println("SWITCH"+" "+datawidth+" "+conIfoIndexMap(key)+" "+numtrack)
//        pw2.println("BEGIN")
//        conIfoMap(key).map{ xx =>
//          pw2.write(blank(2))
//          xx.zipWithIndex.map{case (yy,k) =>
//            if (k == xx.size-1) pw2.println(yy)
//            else pw2.write(yy+" ")
//          }
//        }
//        pw2.println("END")
//      }
//      //uesd in tile that do not contain GIB
//      pw2.println("SWITCH"+" "+datawidth+" "+(conIfoIndexMap.values.max+1)+" "+numtrack)
//      pw2.println("BEGIN")
//      pw2.println("END")
//      pw2.close
//
//    }


  }

  def layoutGen(column: Int,row: Int,filename:String)={
    val pw = new PrintWriter(new File(filename))
    //element coordinate in arch
    val x = 2*column
    val y = 2*row+1
    var cor = ListBuffer[Seq[Int]]()
    var corPE = ListBuffer[Seq[Int]]()
    var corMEM = ListBuffer[Seq[Int]]()
    var corGIB = ListBuffer[Seq[Int]]()
    var corIO = ListBuffer[Seq[Int]]()
    for (i <- 0 to column){
      val xIO = 2*i+1
      val yIO = 0
      if (i < column){
        corIO += Seq(xIO,yIO)
        cor += Seq(xIO,yIO)
      }
      for (j <- 0 to row){
        val xGIB = 2*i
        val yGIB = 2*j+1
        corGIB += Seq(xGIB,yGIB)
        cor += Seq(xGIB,yGIB)
        if (i < column && j < row){
          val xUnit = 2*i+1
          val yUnit = 2*j+2
          cor += Seq(xUnit,yUnit)
          if ((i+1)%4 != 0) corPE += Seq(xUnit,yUnit)
          else corMEM += Seq(xUnit,yUnit)
        }
      }
    }
    //reduce repeat work
    def partGen(cor:ListBuffer[Seq[Int]],corInter:ListBuffer[Seq[Int]])={
      pw.println("BEGIN")
      for(i<-0 to y) {
        for(j<-0 to x){
          if (cor.contains(mutable.Seq(j,i))){
            if (corInter.contains(mutable.Seq(j,i))) pw.print(1)
            else pw.print(0)
          }else{
            pw.print(0)
          }
        }
        pw.println(blank(1))
      }
      pw.println("END")
    }

    //arch ifo
    pw.println("LAYOUT"+blank(3)+0+blank(1)+20)
    partGen(cor,ListBuffer(Seq(1,0)))
    //pe
    pw.println("LAYOUT"+blank(1)+"p"+blank(1)+20+blank(1)+20)
    partGen(cor,corPE)
/*    pw.println("LAYOUT"+blank(1)+"M"+blank(1)+20+blank(1)+1)
    partGen(cor,corPE)*/
    //mem
    pw.println("LAYOUT"+blank(1)+"m"+blank(1)+19+blank(1)+20)
    partGen(cor,corMEM)
    //coarse IO
    pw.println("LAYOUT"+blank(1)+"I"+blank(1)+2+blank(1)+20)
    partGen(cor,corIO)
    //fine IO
    pw.println("LAYOUT"+blank(1)+"i"+blank(1)+1+blank(1)+20)
    partGen(cor,corIO)
    //reg
    pw.println("LAYOUT"+blank(1)+"r"+blank(1)+20+blank(1)+0)
    partGen(cor,corGIB)
//    partGen(cor,(corPE ++ corMEM))
    pw.close()
  }

  def GIB2cfgGen(conIfoIndexMap: mutable.Map[Any,Any],
                 conIfoIndexMap_fine: mutable.Map[Any, Any],
                 filename:String)={
    val pw = new PrintWriter(new File(filename))
    conIfoIndexMap.map(obj => pw.println(obj))
    conIfoIndexMap_fine.map(obj => pw.println(obj))
    pw.close()
  }

}



//object IRHandlerTest extends App {
//  val inFilename = "src/main/resources/cgra_spec.json"
//  val jsonMap = IRHandler.loadIR(inFilename)
//  println(jsonMap)
////  val outFilename = "src/main/resources/cgra_spec_w.json"
////  IRHandler.dumpIR(jsonMap, outFilename)
//}