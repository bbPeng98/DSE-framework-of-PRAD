package PRAD.memory

import PRAD.common.Muxn
import PRAD.ir._
import chisel3._

import scala.collection.mutable
import scala.collection.mutable.ArrayBuffer

class mem_top(attrs: mutable.Map[String, Any]) extends Module with IR {
  apply(attrs)
  val dataWidth = getAttrValue("data_width").asInstanceOf[Int]
  val config_addr_w_unit = getAttrValue("cfg_addr_width_Unit").asInstanceOf[Int]
  val config_data_w = getAttrValue("cfg_data_width").asInstanceOf[Int]
  val io = IO(new Bundle() {
    val stall = Input(Bool()) //p
    val in_coarse = Input(Vec(4 * 4, UInt(dataWidth.W)))
    val in_fine = Input(Vec(4 * 4, UInt(1.W))) 
    val out_coarse = Output(Vec(2, UInt(dataWidth.W))) 
    val out_fine = Output(Vec(4, Bool()))
    val config_config_data = Input(UInt(config_data_w.W)) //p
    val config_config_addr = Input(UInt(config_addr_w_unit.W)) //p
    val config_read = Input(Bool()) //p
    val config_write = Input(Bool()) //p
    val config_write_i = Input(Vec(2, Bool())) //p
    val config_en = Input(Vec(2, Bool())) //p
    /** output */
    val read_config_data = Output(Vec(3, UInt(config_data_w.W))) //p
  })

  val mem_black = Module(new mem_instance(attrs))
  //input mux
  val mux4_coarse = new ArrayBuffer[Muxn]()
  val mux4_fine = new ArrayBuffer[Muxn]()
  val mux_config_reg = RegInit(Vec(4 + 4, UInt(2.W)), VecInit(Seq.fill(4 + 4)(0.U(2.W))))
  //100->data0,101->data1,102->data2,103->data3,104->bit0,105->bit1,106->bit2,107->bit3
  mux_config_reg.zipWithIndex.map { case (sel, i) =>
    when(io.config_config_addr === (100 + i).U) {
      sel := io.config_config_data
    }.otherwise {
      sel := sel
    }
  }

  for (i <- 0 until 4) {
    mux4_coarse += Module(new Muxn(16, 4))
    mux4_fine += Module(new Muxn(1, 4))
  }
  mux4_coarse.zipWithIndex.map { case (mux, i) =>
    mux.io.in.zipWithIndex.map { case (ins, j) => ins := io.in_coarse(i * 4 + j) }
    mux.io.config := mux_config_reg(i)
  }
  mux4_fine.zipWithIndex.map { case (mux, i) =>
    mux.io.in.zipWithIndex.map { case (ins, j) => ins := io.in_fine(i * 4 + j) }
    mux.io.config := mux_config_reg(i + 4)
  }

  mem_black.io.clk := clock
  mem_black.io.reset := reset.asBool()
  mem_black.io.config_1_config_addr := io.config_config_addr
  mem_black.io.config_1_config_data := io.config_config_data
  mem_black.io.config_1_read := io.config_read
  mem_black.io.config_1_write := io.config_write_i(0)
  mem_black.io.config_2_config_addr := io.config_config_addr
  mem_black.io.config_2_config_data := io.config_config_data
  mem_black.io.config_2_read := io.config_read
  mem_black.io.config_2_write := io.config_write_i(1)
  mem_black.io.config_en_0 := io.config_en(0)
  mem_black.io.config_en_1 := io.config_en(1)
  mem_black.io.config_read := io.config_read
  mem_black.io.config_write := io.config_write
  mem_black.io.flush := mux4_fine(0).io.out
  mem_black.io.flush_core := mux4_fine(1).io.out
  mem_black.io.stall := io.stall
  mem_black.io.input_width_16_num_0 := mux4_coarse(0).io.out
  mem_black.io.input_width_16_num_1 := mux4_coarse(1).io.out
  mem_black.io.input_width_16_num_2 := mux4_coarse(2).io.out
  mem_black.io.input_width_16_num_3 := mux4_coarse(3).io.out
  mem_black.io.input_width_1_num_0 := mux4_fine(2).io.out
  mem_black.io.input_width_1_num_1 := mux4_fine(3).io.out
  io.out_coarse(0) := mem_black.io.output_width_16_num_0
  io.out_coarse(1) := mem_black.io.output_width_16_num_1
  io.out_fine(0) := mem_black.io.output_width_1_num_0
  io.out_fine(1) := mem_black.io.output_width_1_num_1
  io.out_fine(2) := mem_black.io.output_width_1_num_2
  io.out_fine(3) := mem_black.io.output_width_1_num_3
  io.read_config_data(0) := mem_black.io.read_config_data
  io.read_config_data(1) := mem_black.io.read_config_data_1
  io.read_config_data(2) := mem_black.io.read_config_data_2
}

