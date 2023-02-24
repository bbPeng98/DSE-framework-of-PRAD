package PRAD.lassen

import chisel3._
import chisel3.util.{Cat, MixedVec, MuxLookup, log2Ceil}
import PRAD.ir._

import scala.collection.mutable
import scala.collection.mutable
import scala.collection.mutable.ArrayBuffer
import scala.math.{ceil, pow}



class PE(attrs: mutable.Map[String, Any]) extends Module with IR {
  apply(attrs)
  val dataWidth = getAttrValue("data_width").asInstanceOf[Int]
  //val config_addr_w = getAttrValue("cfg_addr_width").asInstanceOf[Int]
  val config_data_w = getAttrValue("cfg_data_width").asInstanceOf[Int]
  val config_addr_w_unit = getAttrValue("cfg_addr_width_Unit").asInstanceOf[Int]
  val inputCoarseNum = getAttrValue("input_coarse_num").asInstanceOf[Int]
  val inputFineNum = getAttrValue("input_fine_num").asInstanceOf[Int]
  val operations = getAttrValue("operations").asInstanceOf[Map[String,Int]]
  val has_3input = getAttrValue("has_3input").asInstanceOf[Int]  //0 or 1
  val lut_n = getAttrValue("lut_n").asInstanceOf[Int]

  //  val outputCoarseNum = getAttrValue("output_coarse_num").asInstanceOf[Int]
  //  val outputFineNum = getAttrValue("output_fine_num").asInstanceOf[Int]


  val io = IO(new Bundle{
    val in_coarse= Input(Vec(inputCoarseNum*4, UInt(dataWidth.W)))
    val in_fine = Input(Vec(inputFineNum*4, UInt(1.W)))
    val out_coarse = Output(Vec(1, UInt(dataWidth.W)))
    val out_fine = Output(Vec(1, UInt(1.W)))

    val config_data = Input(UInt(config_data_w.W))
    val config_addr = Input(UInt(config_addr_w_unit.W))   //划出0-7作为pe config addr，8-15作为mux的config addr  
//    val alu_res = Output(UInt(width.W))
//    val res_p = Output(UInt(1.W))
    //val read_config_data = Output(UInt(config_data_w.W))

//    val config_read = Input(Bool())
    val config_write = Input(Bool())
    val stall = Input(Bool())

  } )

  io.out_coarse.map(_ := 0.U)
  io.out_fine.map( _ := 0.U)
  //io.read_config_data := 0.U
  //val pe_config_addr = Wire(UInt(config_addr_w_unit.W)) //8bit
  //val mux_config_addr = Wire(UInt(config_addr_w_unit.W))  //8bit
  val pe_config_width :Int= log2Ceil(operations.size) + 1 + pow(2,lut_n).toInt + 4 +
    (2+has_3input)*(dataWidth+2) + lut_n * (1+2)
  val pe_config = Wire(UInt(pe_config_width.W))
  val mux_reg_num:Int = 2+has_3input+lut_n    
  //val mux_config = Wire(UInt((mux_reg_num*2).W))  
  pe_config := 0.U


  //pe_config_addr := io.config_addr(config_addr_w_unit-1,0)    //0-7
  //mux_config_addr := io.config_addr(2*config_addr_w_unit-1,config_addr_w_unit)   //8-15

  //mux
  val pe_mux_data :ArrayBuffer[mutable.Map[UInt,UInt]] = new ArrayBuffer[mutable.Map[UInt,UInt]] //(2+has_3input) 
  val pe_mux_bit :ArrayBuffer[mutable.Map[UInt,UInt]] = new ArrayBuffer[mutable.Map[UInt,UInt]] //(lut_n)


  for(i <- 0 until 2+has_3input){
    pe_mux_data.append( mutable.Map(
      0.U -> io.in_coarse(i*4),
      1.U -> io.in_coarse(i*4+1),
      2.U -> io.in_coarse(i*4+2),
      3.U -> io.in_coarse(i*4+3)  
    ))
  }
  for(i <- 0 until lut_n){
    pe_mux_bit.append(mutable.Map(
      0.U -> io.in_fine(i*4),
      1.U -> io.in_fine(i*4+1),
      2.U -> io.in_fine(i*4+2),
      3.U -> io.in_fine(i*4+3)
    ))
  }

  //println(mux_reg_num)
  val mux_config_reg = RegInit(Vec(mux_reg_num,UInt(2.W)),VecInit(Seq.fill(mux_reg_num)(0.U(2.W))))
  for(i <- 0 until mux_reg_num){
    when((io.config_addr === (10+i).U) & (io.config_write === 1.U)){
      mux_config_reg(i) := io.config_data(1,0)
    }.otherwise{
      mux_config_reg(i) := mux_config_reg(i)
    }
  }


  val Inst_PE = Module(new sim(operations,dataWidth,lut_n,has_3input,config_data_w,config_addr_w_unit))


  for(i <- 0 until 2+has_3input){
    Inst_PE.io.input_data(i) := MuxLookup(mux_config_reg(i),0.U,pe_mux_data(i).toSeq)
  }
  for(i <- 0 until lut_n){
    Inst_PE.io.input_bit(i) := MuxLookup(mux_config_reg(i+2+has_3input),0.U,pe_mux_bit(i).toSeq)
  }



  Inst_PE.io.clk_en := !io.stall
//  Inst_PE.io.config_address := io.config_addr   
//  Inst_PE.io.config_data := io.config_data 
//  Inst_PE.io.config_en := io.config_write 




  val pe_reg_num = ceil(pe_config_width.toDouble / config_data_w.toDouble).toInt   
  //val config_reg = Vec(reg_num,RegInit(0.U(config_data_w.W)))
  val pe_config_reg = RegInit(Vec(pe_reg_num,UInt(config_data_w.W)),VecInit(Seq.fill(pe_reg_num)(0.U(config_data_w.W))))

//
//  val config_part0 = RegInit(0.U(config_data_w.W))
//  val config_part1 = RegInit(0.U(config_data_w.W))
//  val config_part2 = RegInit(0.U(3.W))

//  when((io.config_addr === 0.U) & (io.config_write === 1.U)){
//    config_part0 := io.config_data
//  }.elsewhen((io.config_addr === 1.U) & (io.config_write === 1.U)){
//    config_part1 := io.config_data
//  }.elsewhen((io.config_addr === 2.U) & (io.config_write === 1.U)){
//    config_part2 := io.config_data(2,0)
//  }.otherwise{
//    config_part0 := config_part0
//    config_part1 := config_part1
//    config_part2 := config_part2
//  }

  for(i <- 0 until pe_reg_num){
    when((io.config_addr === i.U ) &(io.config_write === 1.U)){
      pe_config_reg(i) := io.config_data
    }.otherwise{
      pe_config_reg(i) := pe_config_reg(i)
    }
  }
  pe_config := pe_config_reg.asUInt()


  Inst_PE.io.inst(0) := pe_config(log2Ceil(operations.size)-1,0)
  Inst_PE.io.inst(1) := pe_config(log2Ceil(operations.size))
  Inst_PE.io.inst(2) := pe_config(log2Ceil(operations.size)+pow(2,lut_n).toInt,log2Ceil(operations.size)+1)
  Inst_PE.io.inst(3) := pe_config(log2Ceil(operations.size)+4+pow(2,lut_n).toInt,log2Ceil(operations.size)+1+pow(2,lut_n).toInt)
  Inst_PE.io.inst(4) := pe_config(log2Ceil(operations.size)+4+pow(2,lut_n).toInt+(2+has_3input)*(dataWidth+2),log2Ceil(operations.size)+5+pow(2,lut_n).toInt)
  Inst_PE.io.inst(5) := pe_config(log2Ceil(operations.size)+4+pow(2,lut_n).toInt+(2+has_3input)*(dataWidth+2)+lut_n*(1+2),log2Ceil(operations.size)+5+pow(2,lut_n).toInt+(2+has_3input)*(dataWidth+2))




  io.out_coarse(0) := Inst_PE.io.alu_res
  io.out_fine(0) := Inst_PE.io.res_p
 // io.read_config_data := Inst_PE.io.read_config_data
}



object PE extends App {
   val attrs = mutable.Map(
     "data_width" -> 16,
     "cfg_addr_width" -> 32,
     "cfg_data_width" -> 32,
     "cfg_addr_width_Unit" -> 8,
     "input_coarse_num" -> 2,
     "input_fine_num" -> 3,
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
       //"TAA"->13,
       // "TAS"->10,
        //"TSA"->11,
       // "TSS"->12,
              "Sel" -> 11,
              "GTE_Max" -> 12 ,
              "LTE_Min" ->13,
              "SHR" -> 14,
              "Abs" -> 15,
       //       "MULSHR" -> 21,
       //       "CROP" -> 22,
     ),
     "has_3input" -> 0,
     "lut_n" -> 3
   )
  new (chisel3.stage.ChiselStage).emitVerilog(new PE(attrs))

}
