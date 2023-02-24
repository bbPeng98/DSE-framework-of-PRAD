package PRAD.lassen

import Chisel.Cat
import chisel3._
import chisel3.util._
import lassenvar._

import scala.collection.mutable.ArrayBuffer
import scala.math.{ceil, pow}

/** support 2 inputs and 3 inputs,use has_3input to define
 * default lut is 3LUTs  , 1 bit inputs === lut_n*/
class sim (operation:Map[String,Int] , width:Int,lut_n:Int,has_3input:Int = 0,cfg_data_width:Int,cfg_addr_width_unit:Int)extends Module {
  val io = IO(new Bundle {
    //val inst = Input(UInt(64.W))
    val inst = Input(MixedVec(Seq(UInt(log2Ceil(operation.size).W),
                                          UInt(1.W),UInt(pow(2,lut_n).toInt.W),UInt(4.W),UInt(((2+has_3input)*(width+2)).W),UInt((lut_n*(1+2)).W))))//ALU ,SIGNED ,LUT ,COND ,REGA+DATA0+REGB+DATA1(+REGC+DATA2) ,REGDEF+BIT012
    //val inst1 = Input(UInt(3.W)) 
    //val input_data = Input(MixedVec(Seq(UInt(width.W), UInt(width.W), UInt(1.W), UInt(1.W), UInt(1.W))))
    val input_data = Input(Vec(2 + has_3input,UInt(width.W)))//a,b/ a,b,c
    val input_bit = Input(Vec(lut_n,UInt(1.W)))
    val clk_en = Input(UInt(1.W))
    //val config_address = Input(UInt(cfg_addr_width_unit.W))
    //val config_data = Input(UInt(cfg_data_width.W))
    //val config_en = Input(UInt(1.W))
    val alu_res = Output(UInt(width.W))
    val res_p = Output(UInt(1.W))
    //val read_config_data = Output(UInt((cfg_data_width).W))
  })


  val regdata = Wire(Vec(2+has_3input,UInt(width.W)))
  val reg1bit = Wire(Vec(lut_n,UInt(1.W)))
  val reg_rdata = Wire(MixedVec(Vec(2+has_3input,UInt(width.W)),Vec(lut_n,UInt(1.W))))
    //Seq(UInt(width.W), UInt(width.W), UInt(1.W), UInt(1.W), UInt(1.W))))//ra,rb,rd,re,rf_rdata

  for(i <- 0 until 2+has_3input){
    reg_rdata(0)(i) := 0.U
    regdata(i) := 0.U
  }
  for(i <- 0 until lut_n) {
    reg_rdata(1)(i) := 0.U
    reg1bit(i) := 0.U
  }


  val Inst_reg_data = new ArrayBuffer[mode]
  val Inst_reg_bit = new ArrayBuffer[mode]
  for(i <- 0 until 2+has_3input){
    Inst_reg_data.append(Module(new mode(width)))    //ra rb rc……
    Inst_reg_data(i).io.mode := io.inst(4)(i*(2+width)+1,i*(2+width))
    Inst_reg_data(i).io.const_ := io.inst(4)(i*(2+width)+(1+width),i*(2+width)+2)
    Inst_reg_data(i).io.clk_en := io.clk_en
    Inst_reg_data(i).io.data := io.input_data(i)
    regdata(i) := Inst_reg_data(i).io.out_data
    reg_rdata(0)(i) := Inst_reg_data(i).io.out_data_reg
  }
  for(i <- 0 until lut_n){
    Inst_reg_bit.append(Module(new mode(1)))  //rd re rf……
    Inst_reg_bit(i).io.mode := io.inst(5)(i*(2+1)+1,i*(2+1))
    Inst_reg_bit(i).io.const_ := io.inst(5)(i*(2+1)+2)
    Inst_reg_bit(i).io.clk_en := io.clk_en
    Inst_reg_bit(i).io.data := io.input_bit(i)
    reg1bit(i) := Inst_reg_bit(i).io.out_data
    reg_rdata(1)(i) := Inst_reg_bit(i).io.out_data_reg
  }



  val Inst_lut = Module(new lut(lut_n))

  Inst_lut.io.configuration := io.inst(2)((pow(2,lut_n).toInt)-1,0)
  for(index <- 0 until lut_n){
    Inst_lut.io.LUT_in(index) := reg1bit(index)  //d e f
  }



  val Inst_alu = Module(new alu(operation,width,has_3input))

  Inst_alu.io.configuration := io.inst(0)(log2Ceil(operation.size)-1,0)
  for(i <- 0 until 2+has_3input){
    Inst_alu.io.inputs(i) := regdata(i)
  }
  Inst_alu.io.inputbit := reg1bit(0)
  Inst_alu.io.signed := io.inst(1)
  io.alu_res := Inst_alu.io.res


  val Inst_cond = Module(new cond)

  Inst_cond.io.cond_sel := io.inst(3)(3,0)
  Inst_cond.io.alu_p := Inst_alu.io.res_p
  Inst_cond.io.lut_p := Inst_lut.io.LUT_out
  Inst_cond.io.Z := Inst_alu.io.outputs(0) //Z
  Inst_cond.io.N := Inst_alu.io.outputs(1) //N
  Inst_cond.io.C := Inst_alu.io.outputs(2) //C
  Inst_cond.io.V := Inst_alu.io.outputs(3) //V
  io.res_p := Inst_cond.io.res_p

//val num = ceil(85.toDouble/3.toDouble).toInt
//  println(num)
//
}


//object sim1 extends App {
//  val operation :Map[String, Int] = Map(
//    "Add" -> 0,
//    "Sub" -> 1
//  )
//  new (chisel3.stage.ChiselStage).emitVerilog(new sim(operation,16,3,0,32,8))
//
//}

