package ppa

import chisel3._
import chisel3.util._
import PRAD.template.CGRA

import scala.collection.mutable
import scala.collection.mutable.{ArrayBuffer, ListBuffer, Map}
import java.io._

object area_cgra {
  def CGRA_area(attrs: mutable.Map[String, Any])  {
    // CGRA parameters
    val param = PRAD.template.CgraParam(attrs)
    import param._

    var area : Double = 0
    var total_area : Double = 0

  
    for (k <- 0 until 2) { // top and buttom row
      for (i <- 0 until cols) {
        area = area + ppa.ppa_iob.getiobarea
      }
    }
    total_area += area
    println("IB total area : (there is no IB now) " + area)

    area = 0
    for (k <- 0 until 2) { // top and buttom row
      for (i <- 0 until cols) {
        area = area + ppa.ppa_iob.getiobarea
      }
    }
    total_area += area
    println("OB total area : (there is no OB now) " + area)


    area = 0
    for (i <- 0 until rows) {
      for (j <- 0 until cols-cols/4) {

        area = area + ppa.ppa_pe.getpearea(operations, has_3input,lut_n,dataWidth)
      }
    }
    total_area += area
    //println(rows)
    //println(cols-cols/4)
    //println("PE total area : " + area)
    println("PE average area : " + area/(rows*(cols-cols/4)))


    var area_coarse : Double = 0
    var area_fine : Double = 0
    var area_mux_config_coarse :Double = 0
    var area_mux_config_fine :Double = 0
    for (i <- 0 to rows) {
      for (j <- 0 to cols) {

  
        //print("i="+i+"j="+j +"\n\n\n")
        val trackdirbuf : ListBuffer[Int] = ListBuffer()
        if(j == 0 ) trackdirbuf.append(0) else trackdirbuf.append(1) //west
        if(i == 0 ) trackdirbuf.append(0) else trackdirbuf.append(1) //north
        if(j == cols) trackdirbuf.append(0) else trackdirbuf.append(1) //east
        if(i == rows) trackdirbuf.append(0) else trackdirbuf.append(1) //south


        val num_iopin_list_coarse_par:mutable.Map[String,Int] = get_iopin_list_coarse(attrs,i,j)
        val num_iopin_list_fine_par:mutable.Map[String,Int] = get_iopin_list_fine(attrs,i,j)
        area_coarse = area_coarse + ppa.ppa_gib.getgibarea(dataWidth,numTrackCoarse, diagPinConect, num_iopin_list_coarse_par,get_track_reged(attrs,i,j) ,fcMap_coarse,trackdirbuf)._1
        area_mux_config_coarse = area_mux_config_coarse +ppa.ppa_gib.getgibarea(dataWidth,numTrackCoarse, diagPinConect, num_iopin_list_coarse_par,get_track_reged(attrs,i,j) ,fcMap_coarse,trackdirbuf)._2
        area_fine = area_fine + ppa.ppa_gib.getgibarea(1,numTrackFine, diagPinConect, num_iopin_list_fine_par,get_track_reged(attrs,i,j), fcMap_fine,trackdirbuf)._1
        area_mux_config_fine = area_mux_config_fine + ppa.ppa_gib.getgibarea(1,numTrackFine, diagPinConect, num_iopin_list_fine_par,get_track_reged(attrs,i,j), fcMap_fine,trackdirbuf)._2
        //        println("numTrack" + numTrack)
        //        println("gib_param.diag_iopin_connect" + gib_param.diag_iopin_connect)
        //        println("gib_param.num_iopin_list" + gib_param.num_iopin_list)
        //        println("gib_param.connect_flexibility" +  gib_param.connect_flexibility)
        //        println("gib_param.track_reged" +  gib_param.track_reged)
        //        println("gib_param.track_directions" +  gib_param.track_directions)
        //        println()
        //        println("area is :" + area)
      }
    }


   
    total_area += area_coarse
    total_area += area_fine
    println("GIB_coarse total area :" + area_coarse)
    println("GIB_fine total area :" + area_fine)
    //println("mux total area:" + area_mux_config_coarse)

    println("GIB_coarse average area :" + area_coarse/((rows+1)*(cols+1)))
    println("GIB_fine average area :" + area_fine/((rows+1)*(cols+1)))

    println("CGRA total area without mem :" + total_area)
    total_area

    val writer = new PrintWriter(new File("area.txt"))
    writer.write(total_area.toString)
    writer.close()
    val writer1 = new PrintWriter(new File("area_inter_c.txt"))
    writer1.write((area_coarse).toString)
    writer1.close()
    val writer2 = new PrintWriter(new File("area_inter_f.txt"))
    writer2.write((area_fine).toString)
    writer2.close()

  }

  def get_iopin_list_coarse(attrs: mutable.Map[String, Any],i:Int,j:Int): mutable.Map[String,Int] ={

    val param = PRAD.template.CgraParam(attrs)
    import param._

        //define GIB input/output nums in 4 directions(nw,nw,sw,se)
    val num_iopin_list_coarse = mutable.Map[String, Int]()
        if ((j + 1) % 4 == 0) {
          //for MEM left
          //coarse_grained
          num_iopin_list_coarse += "ipin_nw" -> {
            if (i > 0 && j > 0) PEinputnum(0) //asInstanceOf[List[Int]](0)
            else 0
          }
          num_iopin_list_coarse += "opin_nw" -> { //只有res一个coarse的输出
            if (i > 0 && j > 0) 1
            else 0
          }
          num_iopin_list_coarse += "ipin_ne" -> {
            if (i == 0 && j < cols) 1
            else if (i > 0 && j < cols) interconnect_output_ports * 3
            else 0
          }
          num_iopin_list_coarse += "opin_ne" -> {
            if (i == 0 && j < cols) 1
            else if (i > 0 && j < cols) interconnect_output_ports
            else 0
          }
          num_iopin_list_coarse += "ipin_se" -> {
            if (i < rows && j < cols) interconnect_output_ports * 3
            else 0
          }
          num_iopin_list_coarse += "opin_se" -> {
            if (i < rows && j < cols) interconnect_output_ports
            else 0
          }
          num_iopin_list_coarse += "ipin_sw" -> {
            if (i < rows && j > 0) PEinputnum(0) //.asInstanceOf[List[Int]](0)
            else 0
          }
          num_iopin_list_coarse += "opin_sw" -> {
            if (i < rows && j > 0) 1
            else 0
          }
        } else if ((j % 4) == 0) {
          //for MEM right
          //coarse_grained
          num_iopin_list_coarse += "ipin_nw" -> {
            if (i > 0 && j > 0) interconnect_output_ports * 3
            else 0
          }
          num_iopin_list_coarse += "opin_nw" -> {
            if (i > 0 && j > 0) interconnect_output_ports
            else 0
          }
          num_iopin_list_coarse += "ipin_ne" -> {
            if (i == 0 && j < cols) 1
            else if (i > 0 && j < cols) PEinputnum(0) //.asInstanceOf[List[Int]](0)
            else 0
          }
          num_iopin_list_coarse += "opin_ne" -> {
            if (i == 0 && j < cols) 1
            else if (i > 0 && j < cols) 1
            else 0
          }
          num_iopin_list_coarse += "ipin_se" -> {
            if (i < rows && j < cols) PEinputnum(0) //.asInstanceOf[Tuple2](0) //PEinputnum.asInstanceOf[List[Int]](0)
            else 0
          }
          num_iopin_list_coarse += "opin_se" -> {
            if (i < rows && j < cols) 1
            else 0
          }
          num_iopin_list_coarse += "ipin_sw" -> {
            if (i < rows && j > 0) interconnect_output_ports * 3
            else 0
          }
          num_iopin_list_coarse += "opin_sw" -> {
            if (i < rows && j > 0) interconnect_output_ports
            else 0
          }
        }
        else {
          //for PE
          //coarse_grained
          num_iopin_list_coarse += "ipin_nw" -> {
            if (i > 0 && j > 0) PEinputnum(0) //.asInstanceOf[List[Int]](0)
            else 0
          }
          num_iopin_list_coarse += "opin_nw" -> {
            if (i > 0 && j > 0) 1
            else 0
          }
          num_iopin_list_coarse += "ipin_ne" -> {
            if (i == 0 && j < cols) 1
            else if (i > 0 && j < cols) PEinputnum(0) //.asInstanceOf[List[Int]](0)
            else 0
          }
          num_iopin_list_coarse += "opin_ne" -> {
            if (i == 0 && j < cols) 1
            else if (i > 0 && j < cols) 1
            else 0
          }
          num_iopin_list_coarse += "ipin_se" -> {
            if (i < rows && j < cols) PEinputnum(0) //.asInstanceOf[List[Int]](0)
            else 0
          }
          num_iopin_list_coarse += "opin_se" -> {
            if (i < rows && j < cols) 1
            else 0
          }
          num_iopin_list_coarse += "ipin_sw" -> {
            if (i < rows && j > 0) PEinputnum(0) //.asInstanceOf[List[Int]](0)
            else 0
          }
          num_iopin_list_coarse += "opin_sw" -> {
            if (i < rows && j > 0) 1
            else 0
          }
        }

    num_iopin_list_coarse
  }

  def get_iopin_list_fine(attrs:mutable.Map[String, Any],i:Int,j:Int): mutable.Map[String,Int] = {

    val param = PRAD.template.CgraParam(attrs)
    import param._

    //define GIB input/output nums in 4 directions(nw,nw,sw,se)

    val num_iopin_list_fine = mutable.Map[String, Int]()
    if ((j + 1) % 4 == 0) {
      //for MEM left
      //coarse_grained

      //fine-grained
      num_iopin_list_fine += "ipin_nw" -> {
        if (i > 0 && j > 0) PEinputnum(1) //.asInstanceOf[List[Int]](1)
        else 0
      }
      num_iopin_list_fine += "opin_nw" -> {
        if (i > 0 && j > 0) 1
        else 0
      }
      num_iopin_list_fine += "ipin_ne" -> {
        if (i == 0 && j < cols) 1
        else if (i > 0 && j < cols) interconnect_output_ports * 2 + 1
        else 0
      }
      num_iopin_list_fine += "opin_ne" -> {
        if (i == 0 && j < cols) 1
        else if (i > 0 && j < cols) 4 + interconnect_output_ports
        else 0
      }
      num_iopin_list_fine += "ipin_se" -> {
        if (i < rows && j < cols) interconnect_output_ports * 2 + 1
        else 0
      }
      num_iopin_list_fine += "opin_se" -> {
        if (i < rows && j < cols) 4 + interconnect_output_ports
        else 0
      }
      num_iopin_list_fine += "ipin_sw" -> {
        if (i < rows && j > 0) PEinputnum(1) //.asInstanceOf[List[Int]](1)
        else 0
      }
      num_iopin_list_fine += "opin_sw" -> {
        if (i < rows && j > 0) 1
        else 0
      }
    } else if ((j % 4) == 0) {
      //for MEM right
      //coarse_grained

      //fine-grained
      num_iopin_list_fine += "ipin_nw" -> {
        if (i > 0 && j > 0) interconnect_output_ports * 2 + 1
        else 0
      }
      num_iopin_list_fine += "opin_nw" -> {
        if (i > 0 && j > 0) 4 + interconnect_output_ports
        else 0
      }
      num_iopin_list_fine += "ipin_ne" -> {
        if (i == 0 && j < cols) 1
        else if (i > 0 && j < cols) PEinputnum(1) //.asInstanceOf[List[Int]](1)
        else 0
      }
      num_iopin_list_fine += "opin_ne" -> {
        if (i == 0 && j < cols) 1
        else if (i > 0 && j < cols) 1
        else 0
      }
      num_iopin_list_fine += "ipin_se" -> {
        if (i < rows && j < cols) PEinputnum(1) //.asInstanceOf[List[Int]](1)
        else 0
      }
      num_iopin_list_fine += "opin_se" -> {
        if (i < rows && j < cols) 1
        else 0
      }
      num_iopin_list_fine += "ipin_sw" -> {
        if (i < rows && j > 0) interconnect_output_ports * 2 + 1
        else 0
      }
      num_iopin_list_fine += "opin_sw" -> {
        if (i < rows && j > 0) 4 + interconnect_output_ports
        else 0
      }
    }
    else {
      //for PE
      //coarse_grained

      //fine-grained
      num_iopin_list_fine += "ipin_nw" -> {
        if (i > 0 && j > 0) PEinputnum(1) //.asInstanceOf[List[Int]](1)
        else 0
      }
      num_iopin_list_fine += "opin_nw" -> {
        if (i > 0 && j > 0) 1
        else 0
      }
      num_iopin_list_fine += "ipin_ne" -> {
        if (i == 0 && j < cols) 1
        else if (i > 0 && j < cols) PEinputnum(1) //.asInstanceOf[List[Int]](1)
        else 0
      }
      num_iopin_list_fine += "opin_ne" -> {
        if (i == 0 && j < cols) 1
        else if (i > 0 && j < cols) 1
        else 0
      }
      num_iopin_list_fine += "ipin_se" -> {
        if (i < rows && j < cols) PEinputnum(1) //.asInstanceOf[List[Int]](1)
        else 0
      }
      num_iopin_list_fine += "opin_se" -> {
        if (i < rows && j < cols) 1
        else 0
      }
      num_iopin_list_fine += "ipin_sw" -> {
        if (i < rows && j > 0) PEinputnum(1) //.asInstanceOf[List[Int]](1)
        else 0
      }
      num_iopin_list_fine += "opin_sw" -> {
        if (i < rows && j > 0) 1
        else 0
      }
    }
    num_iopin_list_fine
  }

  def get_track_reged(attrs: mutable.Map[String, Any],i:Int,j:Int):Boolean ={
    val param = PRAD.template.CgraParam(attrs)
    import param._

    val reged = {
      if(trackRegedMode == 0) false
      else if(trackRegedMode == 2) true
      else (i%2 + j%2) == 1
    }
    reged
  }
}