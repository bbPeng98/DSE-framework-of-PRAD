package PRAD.lassen

import chisel3._
import chisel3.util.{MuxLookup, log2Ceil}
import PRAD.lassen.lassenvar._

import scala.collection.mutable
import scala.collection.mutable.ArrayBuffer



class muxlookup (mux_n:Int,width:Int)extends Module{

    val io = IO(new Bundle{
      val cond_sel = Input(UInt(log2Ceil(mux_n).W))
      val input = Input(Vec(mux_n,UInt(width.W)))
//      val lut_p = Input(UInt(1.W))
//      val Z = Input(UInt(1.W))
//      val N = Input(UInt(1.W))
//      val C = Input(UInt(1.W))
//      val V = Input(UInt(1.W))
      val output = Output(UInt(width.W))
    })

    val output = Wire(UInt(width.W))
    output := 0.U

    val inputmap :mutable.Map[UInt,UInt]= mutable.Map()
//    val cond_res = new ArrayBuffer[(UInt,UInt)]
    for(i <- 0 until mux_n){
      inputmap += (i.U ->io.input(i))
    }



    output := MuxLookup(io.cond_sel,0.U,inputmap.toSeq)
    io.output := output

}

class muxlookupmult (num:Int,mux_n:Int,width:Int) extends Module {

  val io = IO(new Bundle{
    val cond_sel = Input(Vec(num,UInt(log2Ceil(mux_n).W)))
    val input = Input(Vec(num,Vec(mux_n,UInt(width.W))))
    //      val lut_p = Input(UInt(1.W))
    //      val Z = Input(UInt(1.W))
    //      val N = Input(UInt(1.W))
    //      val C = Input(UInt(1.W))
    //      val V = Input(UInt(1.W))
    val output = Output(Vec(num,UInt(width.W)))
  })

  val muxlist = new ArrayBuffer[muxlookup]
  for(i <- 0 until num){
    muxlist.append(Module(new muxlookup(mux_n,width)))
    muxlist(i).io.input := io.input(i)
    muxlist(i).io.cond_sel := io.cond_sel(i)
    io.output(i) := muxlist(i).io.output
  }

}


//
//object muxlookup extends App {
//  new (chisel3.stage.ChiselStage).emitVerilog(new muxlookup(14,16))
//
//}

//object muxlookupmult extends App {
//  new (chisel3.stage.ChiselStage).emitVerilog(new muxlookupmult(10,30,1))
//
//}

//object condgen extends App {
//  chisel3.Driver.execute(args, () => new cond())
//}