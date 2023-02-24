package PRAD.lassen


import chisel3._
import chisel3.stage.ChiselStage
import chisel3.util.Cat

import scala.math.pow
/** default:3-LUT */

class lut(lut_n:Int = 3) extends Module {
  val io = IO(new Bundle {
    val configuration = Input(UInt(pow(2,lut_n).toInt.W))
    val LUT_in = Input(Vec(lut_n, UInt(1.W)))
    val LUT_out = Output(UInt(1.W))
  })
//  val lut_in_temp = Cat(io.LUT_in(2),io.LUT_in(1))
//  val lut_in = Cat(lut_in_temp,io.LUT_in(0))
//  val config_reg = RegInit(0.U(8.W))
//  config_reg := io.configuration
  val lut_in = io.LUT_in.asUInt()
  io.LUT_out := 0.U
  io.LUT_out := (io.configuration >> lut_in)(0)

}
//object LUTT extends App {
// Driver.emitVerilog(new lut)

//}
//object LUT1 extends App {
//  new (chisel3.stage.ChiselStage).emitVerilog(new lut(8))
//
//}