package PRAD.lassen


import Chisel.RegEnable
import chisel3._
import lassenvar._

/** default: width = 16bit/1bit */
class mode (width:Int )extends Module {
  val io = IO(new Bundle {
    //val configuration_we = Input(UInt(1.W)) //1bit
    //val configuration_data = Input(UInt(width.W)) //1bit or 16bit
    val mode = Input(UInt(2.W)) 
    val data = Input(UInt(width.W)) //1bit or 16bit
    val clk_en = Input(UInt(1.W)) //1bit 
    val const_ = Input(UInt(width.W)) //1bir or 16bit
    val out_data_reg = Output(UInt(width.W)) //1bit or 16bit
    val out_data = Output(UInt(width.W)) //1bit or 16bit
  })

  val reg_data = Wire(UInt(width.W))
  val reg_en = Wire(UInt(1.W))


  io.out_data_reg := 0.U
  io.out_data := 0.U


  //when (io.configuration_we === 1.U) {
  //  reg_data := io.configuration_data
  //  reg_en := 1.U
  when(io.mode === REG_DELAY) {
    reg_data := io.data
    reg_en := io.clk_en
  } .otherwise{
    reg_data := io.data
    reg_en := 0.U
  }


  val reg_instance = RegInit(0.U(width.W))
  when(reg_en === 1.U){
    reg_instance := reg_data
    //io.out_data_reg := reg_data
  }.otherwise{

    reg_instance := reg_instance

  }
  io.out_data_reg := reg_instance


//  val reg_instance1 = RegEnable(reg_data,reg_en===1.U)


  when (io.mode === REG_CONST) {
    io.out_data := io.const_
  } .elsewhen (io.mode === REG_BYPASS) {
    io.out_data := io.data
  } .otherwise{
    io.out_data := reg_instance
  }




}

//object mode1 extends App {
//  new (chisel3.stage.ChiselStage).emitVerilog(new mode(DATAWIDTH_param)) //ra rb
//
//}
//
//object mode2 extends App {
//  new (chisel3.stage.ChiselStage).emitVerilog(new mode(1))  //rd re rf
//
//}