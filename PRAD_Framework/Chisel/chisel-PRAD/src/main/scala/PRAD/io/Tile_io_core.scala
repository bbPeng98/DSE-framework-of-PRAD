package PRAD.io

import chisel3._

import scala.collection.mutable
import PRAD.ir._

class Tile_io_core (attrs: mutable.Map[String, Any]) extends Module with IR{
  apply(attrs)
  val dataWidth = getAttrValue("data_width").asInstanceOf[Int]

  val io = IO(new Bundle() {
    val tile_id = Input(UInt(dataWidth.W))
    val glb2io_1 = Input(UInt(1.W))
    val f2io_1 = Input(UInt(1.W))
    val glb2io_16 = Input(UInt(dataWidth.W))
    val f2io_16 = Input(UInt(dataWidth.W))

    val io2glb_1 = Output(UInt(1.W))
    val io2f_1 = Output(UInt(1.W))
    val io2glb_16 = Output(UInt(dataWidth.W))
    val io2f_16 = Output(UInt(dataWidth.W))

  })
  io.io2glb_1 := 0.U
  io.io2f_1 := 0.U
  io.io2glb_16 := 0.U
  io.io2f_16 := 0.U

  //connect
  io.io2f_16 := io.glb2io_16
  io.io2f_1 := io.glb2io_1
  io.io2glb_1 := io.f2io_1
  io.io2glb_16 := io.f2io_16
}

//
//object Tile_io_coregen extends App {
//  chisel3.Driver.execute( args, () => new Tile_io_core(16,1))
//}
