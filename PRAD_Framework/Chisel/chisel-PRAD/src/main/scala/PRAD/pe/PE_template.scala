package PRAD.pe

import chisel3._
import scala.collection.mutable
import PRAD.ir._

class PE_template(attrs: mutable.Map[String, Any]) extends BlackBox with IR {
  apply(attrs)
  val dataWidth = getAttrValue("data_width").asInstanceOf[Int]
  val config_addr_w = getAttrValue("cfg_addr_width").asInstanceOf[Int]
  val config_data_w = getAttrValue("cfg_data_width").asInstanceOf[Int]
  val inputCoarseNum = getAttrValue("input_coarse_num").asInstanceOf[Int]
  val inputFineNum = getAttrValue("input_fine_num").asInstanceOf[Int]

//  val outputCoarseNum = getAttrValue("output_coarse_num").asInstanceOf[Int]
//  val outputFineNum = getAttrValue("output_fine_num").asInstanceOf[Int]


  val io = IO(new Bundle{
    val clock = Input(Clock())
    val reset = Input(Bool())
//    val io_bit0 = Input(UInt(1.W))
//    val io_bit1 = Input(UInt(1.W))
//    val io_bit2 = Input(UInt(1.W))
//    val io_data0 = Input(UInt(dataWidth.W))
//    val io_data1 = Input(UInt(dataWidth.W))

    val io_config_addr = Input(UInt(config_addr_w.W))
    val io_config_data = Input(UInt(config_data_w.W))
    val io_config_read = Input(Bool())
    val io_config_write = Input(Bool())
    val io_stall = Input(Bool())

    val io_read_config_data = Output(UInt(config_data_w.W))
//    val io_res_p = Output(UInt(1.W))
//    val io_alu_res = Output(UInt(dataWidth.W))

    val io_in_coarse= Input(Vec(inputCoarseNum, UInt(dataWidth.W)))
    val io_in_fine = Input(Vec(inputFineNum, UInt(1.W)))
    val io_out_coarse = Output(Vec(1, UInt(dataWidth.W)))
    val io_out_fine = Output(Vec(1, UInt(1.W)))


  })
  override def desiredName = "PE_unq1"

//  io.read_config_data := 0.U
//  io.res_p := 1.U
//  io.alu_res := 55.U



}
//
//object PEgen extends App {
//  chisel3.Driver.execute( args, () => new PE(1,16,8,32,32))
//}
