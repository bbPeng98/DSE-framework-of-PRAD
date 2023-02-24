package PRAD.memory

import PRAD.ir._
import chisel3._

import scala.collection.mutable

class mem_instance(attrs: mutable.Map[String, Any]) extends BlackBox with IR {
  apply(attrs)
  val dataWidth = getAttrValue("data_width").asInstanceOf[Int]
  val config_addr_w_unit = getAttrValue("cfg_addr_width_Unit").asInstanceOf[Int]
  val config_data_w = getAttrValue("cfg_data_width").asInstanceOf[Int]

  val io = IO(new Bundle() {
    val clk = Input(Clock())
    val reset = Input(Bool())
    val config_1_config_addr = Input(UInt(config_addr_w_unit.W)) //p
    val config_1_config_data = Input(UInt(config_data_w.W)) //p
    val config_1_read = Input(Bool()) //p
    val config_1_write = Input(Bool()) //p

    val config_2_config_addr = Input(UInt(config_addr_w_unit.W)) //p
    val config_2_config_data = Input(UInt(config_data_w.W)) //p
    val config_2_read = Input(Bool()) //p
    val config_2_write = Input(Bool()) //p

    val config_en_0 = Input(Bool())
    val config_en_1 = Input(Bool())
    val config_read = Input(Bool()) //p
    val config_write = Input(Bool()) //p
    val flush = Input(Bool()) //p
    val flush_core = Input(Bool()) //p
    val stall = Input(Bool())

    val input_width_16_num_0 = Input(UInt(dataWidth.W))
    val input_width_16_num_1 = Input(UInt(dataWidth.W))
    val input_width_16_num_2 = Input(UInt(dataWidth.W))
    val input_width_16_num_3 = Input(UInt(dataWidth.W))

    val input_width_1_num_0 = Input(UInt(1.W))
    val input_width_1_num_1 = Input(UInt(1.W))

    val output_width_16_num_0 = Output(UInt(dataWidth.W))
    val output_width_16_num_1 = Output(UInt(dataWidth.W))

    val output_width_1_num_0 = Output(UInt(1.W))
    val output_width_1_num_1 = Output(UInt(1.W))
    val output_width_1_num_2 = Output(UInt(1.W))
    val output_width_1_num_3 = Output(UInt(1.W))

    val read_config_data = Output(UInt(config_data_w.W)) //p
    val read_config_data_1 = Output(UInt(config_data_w.W)) //p
    val read_config_data_2 = Output(UInt(config_data_w.W)) //p

  })

  override def desiredName = "MemCore"
}

