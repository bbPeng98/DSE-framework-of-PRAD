package ppa

import chisel3.util.log2Ceil
import scala.math.pow
import ppa.area_par.op_group
import scala.collection.mutable.ListBuffer

object ppa_pe {

  def getpearea(operations :Map[String,Int], has_3input:Int = 0,lut_n:Int,datawidth:Int = 16) : Double = { //num pairs of IO ports in SharedDelayPipe

    val mux_area = (2 + has_3input ) * area_par.area_mux_width_map(datawidth)(4) + lut_n * area_par.area_mux_width_map(1)(4)// data012,bit012连接的4mux
    val mode_area = (2+has_3input) * area_par.area_mode_map(datawidth) + lut_n * area_par.area_mode_map(1)
    //println("mode area = " + mode_area)

    val op_Dif_Group : ListBuffer[String] = new ListBuffer()
    operations.map{ op => {
      var inGroup : Boolean = false
      op_group(2+has_3input).map{
        case(ks ,v) => {
          if(ks.contains(op._1)){
            inGroup = true
            if(!op_Dif_Group.contains(v)) op_Dif_Group.append(v)
          }
        }
      }
      if(!inGroup) op_Dif_Group.append(op._1)
    }}



    val op_Dif_Group_remove : ListBuffer[String] = new ListBuffer()
    //println(has_3input)
    if(has_3input == 1){
      //println("here")

      if( op_Dif_Group.contains("group11")){
        if(op_Dif_Group.contains("group6")){
          op_Dif_Group_remove += "group6"
        }
        if(op_Dif_Group.contains("group8-1")){
          op_Dif_Group_remove ++= List("group8-1","group11")
          op_Dif_Group.append("group13")
        }
        if(op_Dif_Group.contains("group8-2")){
          op_Dif_Group_remove ++= List("group8-2","group11")
          op_Dif_Group.append("group13")
        }
        if(op_Dif_Group.contains("group12")){
          op_Dif_Group_remove ++= List("group11","group12")
          op_Dif_Group.append("group13")
        }
      }

      if(op_Dif_Group.contains("group12")){
        if(op_Dif_Group.contains("group6")){
          op_Dif_Group_remove ++= List("group6","group12")
          op_Dif_Group.append("group13")
        }
        if(op_Dif_Group.contains("group8-1") ){
          op_Dif_Group_remove ++= List("group8-1")
        }
        if(op_Dif_Group.contains("group8-2")){
          op_Dif_Group_remove ++= List("group8-2")
        }
      }


      if(op_Dif_Group.contains("group6")){
        if(op_Dif_Group.contains("group1-0")){
          op_Dif_Group_remove ++= List("group1-0")
        }
      }

      if(op_Dif_Group.contains("group8-1")){
        if(op_Dif_Group.contains("group8-2")) {
          op_Dif_Group_remove ++= List("group8-2")
        }
      }

      if(op_Dif_Group.contains("MULSHR")){
        if(op_Dif_Group.contains("group12") && op_Dif_Group.contains("group9")){
          op_Dif_Group_remove ++= List("MULSHR")
        }
      }


     }
      //    else {
//      if(op_Dif_Group.contains("group1")) {
//        if (op_Dif_Group.contains("group0")) {
//          op_Dif_Group_remove ++= List("group0")
//        }
//      }
//      if(op_Dif_Group.contains("group3-1")) {
//          if (op_Dif_Group.contains("group3-2")) {
//            op_Dif_Group_remove ++= List("group3-2")
//          }
//        }
//      }


    val op_Dif_Group_remove_ = op_Dif_Group_remove.distinct
    op_Dif_Group --= op_Dif_Group_remove_
    val op_Dif_Group_ = op_Dif_Group.distinct
    //println(op_Dif_Group_)

    val alu_area = op_Dif_Group_.foldLeft(0.toDouble){(a,b)=> a + area_par.area_alu_width_map(2 + has_3input)(b)}


    val cond_area = area_par.area_cond_map(16)   
    val lut_area = area_par.area_lut_map(lut_n)
    val alumux_area = area_par.area_mux_width_map(datawidth)(operations.size)   

    val alu = alumux_area + alu_area
    //println("alu_area =" + alu)


    val constCfgWidth = datawidth*(2+has_3input) + 1*lut_n
    val aluCfgWidth = log2Ceil(operations.size) // ALU Config width
    val signedCfgWidth = 1
    val muxCfgWidth = (2+has_3input+lut_n) * log2Ceil(4)   
    val delayCfgWidth = (2+has_3input+lut_n) * log2Ceil(3)
    val condCfgWidth = log2Ceil(16)   
    val lutCfgWidth = pow(2,lut_n)
    val sumCfgWidth = constCfgWidth + aluCfgWidth + signedCfgWidth + muxCfgWidth + delayCfgWidth + condCfgWidth + lutCfgWidth
    val cfg_area = sumCfgWidth * area_par.area_cfgpre32

    val pes_instpe = mux_area + cfg_area
    //println("mux_area = pes-inst_PE" + pes_instpe)  //111
    val area = mux_area + mode_area +  alu_area  + cond_area + lut_area + cfg_area + alumux_area
    //println("gpe area :" + area)
    area

  }

}
