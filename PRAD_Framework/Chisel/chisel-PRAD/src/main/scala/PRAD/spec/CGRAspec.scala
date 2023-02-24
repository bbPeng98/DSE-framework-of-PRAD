package PRAD.spec
// Architecture Specification

import scala.collection.mutable
import scala.collection.mutable.ListBuffer
import PRAD.ir._


/** import cgra spec.json */



// CGRA Specification
object CGRASpec{
  val connect_flexibility_coarse = mutable.Map(
    "num_itrack_per_ipin" -> 4, // ipin number = 3
    "num_otrack_per_opin" -> 4, // opin number = 1
    "num_ipin_per_opin"   -> 6
  )
  val connect_flexibility_fine = mutable.Map(
    "num_itrack_per_ipin" -> 4, // ipin number = 3
    "num_otrack_per_opin" -> 4, // opin number = 1
    "num_ipin_per_opin"   -> 6
  )
  val attrs: mutable.Map[String, Any] = mutable.Map(
    "num_row" -> 4,
    "num_colum" -> 4,
    "data_width" -> 16,
    "cfg_data_width" -> 32,
    "cfg_addr_width" -> 32,
    "cfg_addr_width_Unit" -> 8,
    "cfg_blk_offset" -> 2,
    "PEinputnum" -> (2,3),   
    "operations" -> Map(
      "Add" ->0,
      "Sub"->1,
      "Adc"->2,
      "Sbc"->3,
      "Mult0"->4,
      "Mult1"->5,
      "Mult2"->6,
      "XOr" ->7,
      "And" -> 8,
      "SHL" -> 9,
      "Or" -> 10,
      //"MULADD" ->11,
      //"MULSUB"->12,
      //"TAA"->12,
      // "TAS"->10,
      //"TSA"->9,
      // "TSS"->12,
      "Sel" -> 11,
             "GTE_Max" -> 12 ,
             "LTE_Min" ->13,
             "SHR" -> 14,
            "Abs" -> 15,
      //       "MULSHR" -> 21,
      //       "CROP" -> 22,
             ),
    "lut_n" -> 3,
    "has_3input" -> 0,
    "interconnect_output_ports" -> 2,
    "mem_width" -> 64,
    "mem_depth" -> 512,
    "use_sram_stub" -> 0,
    "target" -> (0 until 100).toList,
    "iterator_support" -> 6,
    "config_width" -> 16,
    "interconnect_input_ports" -> 2,
    "agg_addr_width" -> 4,
    "agg_iter_support" -> 6,
    "agg_range_width" -> 16,
    "tb_range_width" -> 16,
    "tb_addr_width" -> 4,
    "banks" -> 1,
    "tb_height" -> 2,
    "agg_height" -> 4,
    "agg_rd_addr_gen_width" -> 8,
    "num_track_coarse" -> 3,
    "num_track_fine" -> 3,
    "track_reged_mode" -> 2,
    "connect_flexibility_coarse" -> connect_flexibility_coarse,
    "connect_flexibility_fine" -> connect_flexibility_fine,
    "diag_iopin_connect" -> true
  )

  def loadSpec(jsonFile : String): Unit ={
    val jsonMap = IRHandler.loadIR(jsonFile)
    for(kv <- jsonMap){
      if(attrs.contains(kv._1)){
        if(kv._1 == "operations") {
          attrs(kv._1) = kv._2.asInstanceOf[Map[String,Int]]
        }else if(kv._1 == "connect_flexibility_coarse" || kv._1 == "connect_flexibility_fine"){
          attrs(kv._1) = mutable.Map() ++ kv._2.asInstanceOf[Map[String, Int]]
        }else{
          attrs(kv._1) = kv._2
        }
      }
    }
  }

  def dumpSpec(jsonFile : String): Unit={
    IRHandler.dumpIR(attrs, jsonFile)
  }

}


