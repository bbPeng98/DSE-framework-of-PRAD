package PRAD.lassen



import chisel3._
import chisel3.util.MuxLookup
import PRAD.lassen.lassenvar._

import scala.collection.mutable.ArrayBuffer


class cond extends Module {
  val io = IO(new Bundle{
    val cond_sel = Input(UInt(4.W))
    val alu_p = Input(UInt(1.W))
    val lut_p = Input(UInt(1.W))
    val Z = Input(UInt(1.W))
    val N = Input(UInt(1.W))
    val C = Input(UInt(1.W))
    val V = Input(UInt(1.W))
    val res_p = Output(UInt(1.W))
  })

  val output = Wire(UInt(1.W))
  output := 0.U

  val cond_res = new ArrayBuffer[(UInt,UInt)]
  for(i <- 0 until 16)
      i match {
        case 0 => cond_res.append(cond_Z ->  io.Z)
        case 1 => cond_res.append(cond_Z_n -> !io.Z)
        case 2 => cond_res.append(cond_C -> io.C)
        case 3 => cond_res.append(cond_C_n -> !io.C)
        case 4 => cond_res.append(cond_N -> io.N)
        case 5 => cond_res.append(cond_N_n -> !io.N)
        case 6 => cond_res.append(cond_V -> io.V)
        case 7 => cond_res.append(cond_V_n -> !io.V)
        case 8 => cond_res.append(cond_UGT -> (io.C & (!io.Z)))
        case 9 => cond_res.append(cond_ULE -> ((!io.C) | io.Z))
        case 10 => cond_res.append(cond_SGE -> (io.N === io.V).asUInt())
        case 11 => cond_res.append(cond_SLT -> (io.N === !io.V).asUInt())
        case 12 => cond_res.append(cond_SGT -> ((!io.Z) & (io.N === io.V)).asUInt())
        case 13 => cond_res.append(cond_SLE -> (io.Z | (io.N === !io.V)))
        case 14 => cond_res.append(cond_LUT -> io.lut_p)
        case 15 => cond_res.append(cond_ALU -> io.alu_p)
      }

  output := MuxLookup(io.cond_sel,0.U,cond_res)
  io.res_p := output

}



//object cond1 extends App {
//  new (chisel3.stage.ChiselStage).emitVerilog(new cond)
//
//}
//
//object condgen extends App {
//  chisel3.Driver.execute( args, () => new cond())
//}