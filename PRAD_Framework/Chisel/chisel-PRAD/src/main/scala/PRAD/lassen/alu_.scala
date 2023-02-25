package PRAD.lassen


import chisel3.util._
import chisel3._
import chisel3.util.MixedVec
import lassenvar._
import Chisel.Cat

import scala.collection.mutable
import scala.collection.mutable.ArrayBuffer
import scala.io.Codec.default

/** support 3inputs and 2inputs
 * param: is_2input */

class alu( operation:Map[String,Int] , w:Int,has_3input:Int=0) extends Module {

  val io = IO(new Bundle{
    val configuration = Input(UInt(log2Ceil(operation.size).W))
    val inputs = Input(Vec(2+has_3input,UInt(w.W)))
    val inputbit = Input(UInt(1.W))//a,b,d
    val signed = Input(UInt(1.W)) 
    val res = Output(UInt(w.W))
    // val s_res = Output(SInt(w.W))
    val res_p = Output(UInt(1.W))  //1bit
    val outputs = Output(MixedVec(Seq(UInt(1.W),UInt(1.W),UInt(1.W),UInt(1.W)))) //Z,N,C,V

  })
  val inputs = Wire(Vec(2+has_3input,UInt(w.W)))
  val inputbit = Wire(UInt(1.W))
  val S_inputs = Wire(Vec(2+has_3input,SInt(w.W)))

  for(i <- 0 until 2+has_3input){
    inputs(i) := io.inputs(i)
    S_inputs(i) := io.inputs(i).asSInt()
  }
  inputbit := io.inputbit
//  val inputs(0) = io.inputs(0)
//  val inputs(1) = io.inputs(1)
//  val inputbit = io.inputs(2) //cin


//  val S_inputs(0 = inputs(0).asSInt()
//  val S_inputs(1 = inputs(1).asSInt()
//  val S_inputd = inputbit.asSInt()


  io.res := 0.U
  io.res_p := 0.U
  //io.s_res := 0.S
  io.outputs(0) := 0.U
  io.outputs(1) := 0.U
  io.outputs(2) := 0.U
  io.outputs(3) := 0.U

  def CF_Unsigned(op:UInt,cin:UInt = 0.U) :UInt ={
    val sum = Wire(UInt((w+1).W))
    when(op === 1.U){
      sum := Cat(0.U,inputs(0)) - Cat(0.U,inputs(1)) + cin
    }.otherwise {
      sum := Cat(0.U,inputs(0)) + Cat(0.U,inputs(1)) + cin
    }
    val c = Wire(UInt(1.W))
    c := sum (w)
    c
  }

  def CF_Signed(op:UInt,cin:UInt = 0.U) :UInt = {
    val sum = Wire(SInt((w+1).W))
    val a = Wire(SInt((w+1).W))
    val b = Wire(SInt((w+1).W))
    when(S_inputs(0) >= 0.S){
      a := Cat(0.U,inputs(0)).asSInt()  //符号扩展
    }.otherwise{
      a := Cat(1.U,inputs(0)).asSInt()
    }
    when(S_inputs(1) >= 0.S){
      b := Cat(0.U,inputs(1)).asSInt()
    }.otherwise{
      b := Cat(1.U,inputs(1)).asSInt()
    }
    when(op === 1.U){
      when(cin === 0.U){
        sum := a - b
      }.otherwise{
        sum := a - b + 1.S
      }
    }.otherwise{
      when(cin === 0.U){
        sum := a + b
      }.otherwise{
        sum := a + b + 1.S
      }
    }
    val c = Wire(UInt(1.W))
    c := sum(w)
    c
  }


  def overflow(o_res:UInt,op:UInt) :UInt={ 
    val msb_a = Wire(UInt(1.W))
    val msb_b = Wire(UInt(1.W))
    val N = Wire(UInt(1.W))
    msb_a := inputs(0)(w-1)
    when(op === 1.U){
      msb_b := !(inputs(1)(w-1))
    }.otherwise{
      msb_b := inputs(1)(w-1)
    }
    N := o_res(w-1)
    val ov = Wire(UInt(1.W))
    ov := (msb_a & msb_b & !N)|(!msb_a & !msb_b & N)
    ov
  }


  def getResult_U :Seq[(UInt,UInt)] = {
    val Multi = Wire(UInt((2*w).W))
    Multi := inputs(0) * inputs(1)
    //val op2res = new ArrayBuffer[(UInt,UInt)]()
    val funSeq_res = operation.map(ins =>
      ins._1 match {
        case "Add" => ins._2.U -> (inputs(0) + inputs(1))
        case "Sub" => ins._2.U -> (inputs(0) - inputs(1))
        case "Adc" => ins._2.U -> (inputs(0) + inputs(1) + inputbit)
        case "Abs" => ins._2.U -> inputs(0)
        case "GTE_Max" => ins._2.U -> Mux(inputs(0) >= inputs(1), inputs(0), inputs(1))
        case "LTE_Min" => ins._2.U -> Mux(inputs(0) <= inputs(1), inputs(0), inputs(1))
        case "Sbc" => ins._2.U -> (inputs(0) - inputs(1) + inputbit)
        case "Sel" => ins._2.U -> Mux(inputbit === 1.U, inputs(0), inputs(1))
        case "Mult0" => ins._2.U -> Multi(w-1, 0)
        case "Mult1" => ins._2.U -> Multi((w-1)+w/2, w/2)
        case "Mult2" => ins._2.U -> Multi(2*w-1, w)
        case "SHR" => ins._2.U -> (inputs(0) >> inputs(1)(log2Ceil(w)-1,0)).asUInt()
        case "SHL" => ins._2.U -> (inputs(0) << inputs(1)(log2Ceil(w)-1,0)).asUInt()
        case "Or" => ins._2.U -> (inputs(0) | inputs(1))
        case "And" => ins._2.U -> (inputs(0) & inputs(1))
        case "XOr" => ins._2.U -> (inputs(0) ^ inputs(1))
        case "MULADD" => ins._2.U -> (Multi(w - 1, 0) + inputs(2))
        case "MULSUB" => ins._2.U -> (Multi(w - 1, 0) - inputs(2))
        case "TAA" => ins._2.U -> (inputs(0) + inputs(1) + inputs(2))
        case "TAS" => ins._2.U -> (inputs(0) + inputs(1) - inputs(2))
        case "TSA" => ins._2.U -> (inputs(0) - inputs(1) + inputs(2))
        case "TSS" => ins._2.U -> (inputs(0) - inputs(1) - inputs(2))
        case "CROP" => ins._2.U -> Mux(Mux(inputs(0) <= inputs(1), inputs(0), inputs(1)) >= inputs(2), Mux(inputs(0) <= inputs(1), inputs(0), inputs(1)), inputs(2))
        case "MULSHR" => ins._2.U -> (Multi(w - 1, 0)>> inputs(2)).asUInt()
        case  _ => ins._2.U -> 0.U
      }).toSeq
    //new ArrayBuffer[(UInt, UInt)]() 
    //   for (i <- 0 until (operation.size + 1)) {
    //     if ((functionSelect & (1 << i)) > 0) {
    //       i match {
    //         case 0 => funSeq_res.append(ALU_Add -> (inputs(0) + inputs(1)))
    //         case 1 => funSeq_res.append(ALU_Sub -> (inputs(0) - inputs(1)))
    //         case 2 => funSeq_res.append(ALU_Adc -> (inputs(0) + inputs(1) + inputbit))
    //         case 3 => funSeq_res.append(ALU_Abs -> inputs(0)
    //         case 4 => funSeq_res.append(ALU_GTE_Max -> Mux(inputs(0) >= inputs(1), inputs(0), inputs(1)))
    //         case 5 => funSeq_res.append(ALU_LTE_Min -> Mux(inputs(0) <= inputs(1), inputs(0), inputs(1)))
    //         case 6 => funSeq_res.append(ALU_Sbc -> (inputs(0) - inputs(1) + inputbit))
    //         case 8 => funSeq_res.append(ALU_Sel -> Mux(inputbit === 1.U, inputs(0), inputs(1)))
    //         case 11 => funSeq_res.append(ALU_Multi0 -> Multi(15, 0))
    //         case 12 => funSeq_res.append(ALU_Multi1 -> Multi(23, 8))
    //         case 13 => funSeq_res.append(ALU_Multi2 -> Multi(31, 16))
    //         case 15 => funSeq_res.append(ALU_SHR -> (inputs(0) >> inputs(1)(3,0)).asUInt())
    //         case 17 => funSeq_res.append(ALU_SHL -> (inputs(0) << inputs(1)(3,0)).asUInt())
    //         case 18 => funSeq_res.append(ALU_Or -> (inputs(0) | inputs(1)))
    //         case 19 => funSeq_res.append(ALU_And -> (inputs(0) & inputs(1)))
    //         case 20 => funSeq_res.append(ALU_XOr -> (inputs(0) ^ inputs(1)))
    //         case _ => funSeq_res.append(i.U -> 0.U)
    //       }
    //     }
    //   }
    funSeq_res
  }


  def getResult_S :Seq[(UInt,SInt)] = {
    val S_Multi = Wire(SInt((2*w).W))
    S_Multi := S_inputs(0) * S_inputs(1)
    val funSeq_res = operation.map(ins =>
      ins._1 match {
        case "Add" => ins._2.U -> (S_inputs(0) + S_inputs(1))
        case "Sub" => ins._2.U -> (S_inputs(0) - S_inputs(1))
        case "Adc" => ins._2.U -> (inputs(0) + inputs(1) + inputbit).asSInt()
        case "Abs" => ins._2.U -> Mux(S_inputs(0) >= 0.S, S_inputs(0), -S_inputs(0))
        case "GTE_Max" => ins._2.U -> Mux(S_inputs(0) >= S_inputs(1), S_inputs(0), S_inputs(1))
        case "LTE_Min" => ins._2.U -> Mux(S_inputs(0) <= S_inputs(1), S_inputs(0), S_inputs(1))
        case "Sbc" => ins._2.U -> (inputs(0) - inputs(1) + inputbit).asSInt()
        case "Sel" => ins._2.U -> Mux(inputbit === 1.U, S_inputs(0), S_inputs(1))
        case "Mult0" => ins._2.U -> S_Multi(w-1, 0).asSInt()
        case "Mult1" => ins._2.U -> S_Multi((w-1)+w/2, w/2).asSInt()
        case "Mult2" => ins._2.U -> S_Multi(2*w-1, w).asSInt()
        case "SHR" => ins._2.U -> (S_inputs(0) >> inputs(1)(log2Ceil(w)-1,0)).asSInt()
        case "SHL" => ins._2.U -> (S_inputs(0) << inputs(1)(log2Ceil(w)-1,0)).asSInt()
        case "Or" => ins._2.U -> (S_inputs(0) | S_inputs(1))
        case "And" => ins._2.U -> (S_inputs(0) & S_inputs(1))
        case "XOr" => ins._2.U -> (S_inputs(0) ^ S_inputs(1))
        case "MULADD" => ins._2.U -> (S_Multi(w - 1, 0) + inputs(2)).asSInt()
        case "MULSUB" => ins._2.U -> (S_Multi(w-1, 0) - inputs(2)).asSInt()
        case "TAA" => ins._2.U -> (S_inputs(0) + S_inputs(1) + S_inputs(2))
        case "TAS" => ins._2.U -> (S_inputs(0) + S_inputs(1) - S_inputs(2))
        case "TSA" => ins._2.U -> (S_inputs(0) - S_inputs(1) + S_inputs(2))
        case "TSS" => ins._2.U -> (S_inputs(0) - S_inputs(1) - S_inputs(2))
        case "CROP" => ins._2.U -> Mux(Mux(S_inputs(0) <= S_inputs(1), S_inputs(0), S_inputs(1)) >= S_inputs(2), Mux(S_inputs(0) <= S_inputs(1), S_inputs(0), S_inputs(1)), S_inputs(2))
        case "MULSHR" => ins._2.U -> (S_Multi(w - 1, 0) >> inputs(2)).asSInt()
        case _ => ins._2.U -> 0.S
      }
    ).toSeq
    //val funSeq_res = new ArrayBuffer[(UInt, SInt)]() 
    //    for (i <- 0 until (ALU_FUN_NUM +1) ) {
    //      if ((functionSelect & (1 << i)) > 0) {
    //        i match {
    //          case 0 => funSeq_res.append(ALU_Add -> (S_inputs(0 + S_inputs(1))
    //          case 1 => funSeq_res.append(ALU_Sub -> (S_inputs(0 - S_inputs(1))
    //          case 2 => funSeq_res.append(ALU_Adc -> (inputs(0) + inputs(1) + inputbit).asSInt())
    //          case 3 => funSeq_res.append(ALU_Abs -> Mux(S_inputs(0 >= 0.S, S_inputs(0, -S_inputs(0))
    //          case 4 => funSeq_res.append(ALU_GTE_Max -> Mux(S_inputs(0 >= S_inputs(1, S_inputs(0, S_inputs(1))
    //          case 5 => funSeq_res.append(ALU_LTE_Min -> Mux(S_inputs(0 <= S_inputs(1, S_inputs(0, S_inputs(1))
    //          case 6 => funSeq_res.append(ALU_Sbc -> (inputs(0) - inputs(1) + inputbit).asSInt())
    //          case 8 => funSeq_res.append(ALU_Sel -> Mux(inputbit === 1.U, S_inputs(0, S_inputs(1))
    //          case 11 => funSeq_res.append(ALU_Multi0 -> S_Multi(15, 0).asSInt())
    //          case 12 => funSeq_res.append(ALU_Multi1 -> S_Multi(23, 8).asSInt())
    //          case 13 => funSeq_res.append(ALU_Multi2 -> S_Multi(31, 16).asSInt())
    //          case 15 => funSeq_res.append(ALU_SHR -> (S_inputs(0 >> inputs(1)(3,0)).asSInt())
    //          case 17 => funSeq_res.append(ALU_SHL -> (S_inputs(0 << inputs(1)(3,0)).asSInt())
    //          case 18 => funSeq_res.append(ALU_Or -> (S_inputs(0 | S_inputs(1))
    //          case 19 => funSeq_res.append(ALU_And -> (S_inputs(0 & S_inputs(1))
    //          case 20 => funSeq_res.append(ALU_XOr -> (S_inputs(0 ^ S_inputs(1))
    //          case _ => funSeq_res.append(i.U -> 0.S)
    //        }
    //      }
    //    }
    funSeq_res
  }

  def getres_p_U : Seq[(UInt,UInt)] = {

    val funSeq_res_p = operation.map(ins =>
      ins._1 match {
        case "Add" => ins._2.U -> CF_Unsigned(0.U)
        case "Sub" => ins._2.U -> CF_Unsigned(1.U)
        case "Adc" => ins._2.U -> CF_Unsigned(0.U,inputbit)
        case "Sbc" => ins._2.U -> CF_Unsigned(1.U,inputbit)
        case "GTE_Max" => ins._2.U -> (inputs(0) >= inputs(1))
        case "LTE_Min" => ins._2.U -> (inputs(0) <= inputs(1))
        case "Abs" => ins._2.U -> inputs(0)(w-1)
        case _ => ins._2.U -> 0.U
      }
    ).toSeq
    //val funSeq_res_p = new ArrayBuffer[(UInt, UInt)]() //存放res_p(1bit)
    //    for (i <- 0 until (ALU_FUN_NUM + 1)) {
    //      if ((functionSelect & (1 << i)) > 0) {
    //        i match {
    //          case 0 => funSeq_res_p.append(ALU_Add -> CF_Unsigned(0.U))
    //          case 1 => funSeq_res_p.append(ALU_Sub -> CF_Unsigned(1.U))
    //          case 2 => funSeq_res_p.append(ALU_Adc -> CF_Unsigned(0.U,inputbit))
    //          case 6 => funSeq_res_p.append(ALU_Sbc -> CF_Unsigned(1.U,inputbit))
    //          case 4 => funSeq_res_p.append(ALU_GTE_Max -> (inputs(0) >= inputs(1)))
    //          case 5 => funSeq_res_p.append(ALU_LTE_Min -> (inputs(0) <= inputs(1)))
    //          case 3 => funSeq_res_p.append(ALU_Abs -> inputs(0)(w-1))
    ////          case 8 => funSeq_res_p.append(ALU_Sel -> 0.U)
    ////          case 11 => funSeq_res_p.append(ALU_Multi0 -> 0.U)
    ////          case 12 => funSeq_res_p.append(ALU_Multi1 -> 0.U)
    ////          case 13 => funSeq_res_p.append(ALU_Multi2 -> 0.U)
    ////          case 15 => funSeq_res_p.append(ALU_SHR -> 0.U)
    ////          case 17 => funSeq_res_p.append(ALU_SHL -> 0.U)
    ////          case 18 => funSeq_res_p.append(ALU_Or -> 0.U)
    ////          case 19 => funSeq_res_p.append(ALU_And -> 0.U)
    ////          case 20 => funSeq_res_p.append(ALU_XOr -> 0.U)
    //          case _ => funSeq_res_p.append(i.U -> 0.U)
    //        }
    //      }
    //    }
    funSeq_res_p
  }

  def getres_p_S : Seq[(UInt,UInt)] = {
    //val funSeq_res_p = new ArrayBuffer[(UInt,UInt)]() //存放res_p(1bit)
    val funSeq_res_p = operation.map(ins =>
      ins._1 match {
        case "Add" => ins._2.U -> CF_Signed(0.U)
        case "Sub" => ins._2.U -> CF_Signed(1.U)
        case "Adc" => ins._2.U -> CF_Signed(0.U,inputbit)
        case "Sbc" => ins._2.U -> CF_Signed(1.U,inputbit)
        case "GTE_Max" => ins._2.U -> (S_inputs(0) >= S_inputs(1)).asUInt()
        case "LTE_Min" => ins._2.U -> (S_inputs(0) <= S_inputs(1)).asUInt()
        case "Abs" => ins._2.U -> inputs(0)(w-1)
        case _ => ins._2.U -> 0.U
      }
    ).toSeq
    //    for (i <- 0 until ALU_FUN_NUM) {
    //      if ((functionSelect & (1 << i)) > 0) {
    //        i match {
    //          case 0 => funSeq_res_p.append(ALU_Add -> CF_Signed(0.U))
    //          case 1 => funSeq_res_p.append(ALU_Sub -> CF_Signed(1.U))
    //          case 2 => funSeq_res_p.append(ALU_Adc -> CF_Signed(0.U,inputbit))
    //          case 6 => funSeq_res_p.append(ALU_Sbc -> CF_Signed(1.U,inputbit))
    //          case 4 => funSeq_res_p.append(ALU_GTE_Max -> (S_inputs(0 >= S_inputs(1).asUInt())
    //          case 5 => funSeq_res_p.append(ALU_LTE_Min -> (S_inputs(0 <= S_inputs(1).asUInt())
    //          case 3 => funSeq_res_p.append(ALU_Abs -> (S_inputs(0 >= 0.S).asUInt())
    ////          case 8 => funSeq_res_p.append(ALU_Sel -> 0.U)
    ////          case 11 => funSeq_res_p.append(ALU_Multi0 -> 0.U)
    ////          case 12 => funSeq_res_p.append(ALU_Multi1 -> 0.U)
    ////          case 13 => funSeq_res_p.append(ALU_Multi2 -> 0.U)
    ////          case 15 => funSeq_res_p.append(ALU_SHR -> 0.U)
    ////          case 17 => funSeq_res_p.append(ALU_SHL -> 0.U)
    ////          case 18 => funSeq_res_p.append(ALU_Or -> 0.U)
    ////          case 19 => funSeq_res_p.append(ALU_And -> 0.U)
    ////          case 20 => funSeq_res_p.append(ALU_XOr -> 0.U)
    //          case _ => funSeq_res_p.append(i.U -> 0.U)
    //        }
    //      }
    //    }
    funSeq_res_p
  }
  //
  //  def getC(signed : Int) : Seq[(UInt,UInt)] ={
  //    val C_U = operation.map( ins =>
  //      ins._1 match {
  //        case "Add" => ins._2.U -> CF_Unsigned(0.U)
  //        case "Sub" => ins._2.U -> CF_Unsigned(1.U)
  //        case "Adc" => ins._2.U -> CF_Unsigned(0.U, inputbit)
  //        case "Sbc" => ins._2.U -> CF_Unsigned(1.U,inputbit)
  //        case _ => ins._2.U -> 0.U
  //      }
  //    ).toSeq
  //    val C_S = operation.map( ins =>
  //      ins._1 match {
  //        case "Add" => ins._2.U -> CF_Signed(0.U)
  //        case "Sub" => ins._2.U -> CF_Signed(1.U)
  //        case "Adc" => ins._2.U -> CF_Signed(0.U, inputbit)
  //        case "Sbc" => ins._2.U -> CF_Signed(1.U, inputbit)
  //        case _ => ins._2.U -> 0.U
  //      }
  //    ).toSeq
  //    if(signed == 1){
  //      C_S
  //    }else{
  //      C_U
  //    }
  //  }
  val C_U = operation.map( ins =>
    ins._1 match {
      case "Add" => ins._2.U -> CF_Unsigned(0.U)
      case "Sub" => ins._2.U -> CF_Unsigned(1.U)
      case "Adc" => ins._2.U -> CF_Unsigned(0.U, inputbit)
      case "Sbc" => ins._2.U -> CF_Unsigned(1.U,inputbit)
      case _ => ins._2.U -> 0.U
    }
  ).toSeq
  val C_S = operation.map( ins =>
    ins._1 match {
      case "Add" => ins._2.U -> CF_Signed(0.U)
      case "Sub" => ins._2.U -> CF_Signed(1.U)
      case "Adc" => ins._2.U -> CF_Signed(0.U, inputbit)
      case "Sbc" => ins._2.U -> CF_Signed(1.U, inputbit)
      case _ => ins._2.U -> 0.U
    }
  ).toSeq

  //  def getV(signed :Int) : Seq[(UInt,UInt)] ={
  //    val V_U = operation.map( ins =>
  //      ins._1 match {
  //        case "Add" => ins._2.U -> overflow(MuxLookup(io.configuration, 0.U, getResult_U), 0.U)
  //        case "Adc" => ins._2.U -> overflow(MuxLookup(io.configuration, 0.U, getResult_U), 0.U)
  //        case "Sub" => ins._2.U -> overflow(MuxLookup(io.configuration,0.U,getResult_U),1.U)
  //        case "Sbc" => ins._2.U -> overflow(MuxLookup(io.configuration,0.U,getResult_U),1.U)
  //        case _ => ins._2.U -> 0.U
  //      }).toSeq
  //    val V_S = operation.map( ins =>
  //      ins._1 match {
  //        case "Add" => ins._2.U -> overflow(MuxLookup(io.configuration, 0.S, getResult_S).asUInt(), 0.U)
  //        case "Adc" => ins._2.U -> overflow(MuxLookup(io.configuration, 0.S, getResult_S).asUInt(), 0.U)
  //        case "Sub" => ins._2.U -> overflow(MuxLookup(io.configuration, 0.S, getResult_S).asUInt(), 1.U)
  //        case "Sbc" => ins._2.U -> overflow(MuxLookup(io.configuration, 0.S, getResult_S).asUInt(), 1.U)
  //        case _ => ins._2.U -> 0.U
  //      }).toSeq
  //    if(signed == 1){
  //      V_U
  //    }else{
  //      V_S
  //    }
  //  }
  val V_U = operation.map( ins =>
    ins._1 match {
      case "Add" => ins._2.U -> overflow(MuxLookup(io.configuration, 0.U, getResult_U), 0.U)
      case "Adc" => ins._2.U -> overflow(MuxLookup(io.configuration, 0.U, getResult_U), 0.U)
      case "Sub" => ins._2.U -> overflow(MuxLookup(io.configuration,0.U,getResult_U),1.U)
      case "Sbc" => ins._2.U -> overflow(MuxLookup(io.configuration,0.U,getResult_U),1.U)
      case _ => ins._2.U -> 0.U
    }).toSeq
  val V_S = operation.map( ins =>
    ins._1 match {
      case "Add" => ins._2.U -> overflow(MuxLookup(io.configuration, 0.S, getResult_S).asUInt(), 0.U)
      case "Adc" => ins._2.U -> overflow(MuxLookup(io.configuration, 0.S, getResult_S).asUInt(), 0.U)
      case "Sub" => ins._2.U -> overflow(MuxLookup(io.configuration, 0.S, getResult_S).asUInt(), 1.U)
      case "Sbc" => ins._2.U -> overflow(MuxLookup(io.configuration, 0.S, getResult_S).asUInt(), 1.U)
      case _ => ins._2.U -> 0.U
    }).toSeq

  when(io.signed === UNSIGNED) {  
    io.res := MuxLookup(io.configuration,0.U,getResult_U)
    io.res_p := MuxLookup(io.configuration,0.U,getres_p_U)
    io.outputs(2) := MuxLookup(io.configuration,0.U,C_U)
    io.outputs(3) := MuxLookup(io.configuration,0.U,V_U)
  }.otherwise {
    io.res := MuxLookup(io.configuration, 0.S, getResult_S).asUInt()
    io.res_p := MuxLookup(io.configuration, 0.U, getres_p_S)
    io.outputs(2) := MuxLookup(io.configuration,0.U,C_S)
    io.outputs(3) := MuxLookup(io.configuration,0.U,V_S)
  }

  io.outputs(0) := (io.res === 0.U).asUInt() //Z
  io.outputs(1) := io.res(w-1) //N

}


//class alu3(operation:Map[String,Int],w:Int) extends Module {
//
//  val io = IO(new Bundle {
//    val configuration = Input(UInt(log2Ceil(operation.size).W))
//    val inputs = Input(MixedVec(Seq(UInt(w.W), UInt(w.W), UInt(w.W), UInt(1.W)))) // a,b,c,d
//    val signed = Input(UInt(1.W)) 
//    val res = Output(UInt(w.W))
//    // val s_res = Output(SInt(w.W))
//    val res_p = Output(UInt(1.W)) //1bit
//    val outputs = Output(MixedVec(Seq(UInt(1.W), UInt(1.W), UInt(1.W), UInt(1.W)))) //Z,N,C,V
//  })
//
// 
//  val inputs = io.inputs(0)
//  val inputs(1) = io.inputs(1)
//  val inputs(2) = io.inputs(2)
//  val inputbit = io.inputs(3) //cin
//
//
//  val S_inputs(0) = inputs(0).asSInt()
//  val S_inputs(1) = inputs(1).asSInt()
//  val S_inputs(2) = inputs(2).asSInt()
//  val S_inputd = inputbit.asSInt()
//
//  io.res := 0.U
//  io.res_p := 0.U
//  io.outputs(0) := 0.U
//  io.outputs(1) := 0.U
//  io.outputs(2) := 0.U
//  io.outputs(3) := 0.U
//
//  def CF_Unsigned_3(op:UInt,cin:UInt = 0.U) :UInt ={
//    val sum = Wire(UInt((w+1).W))
//    when(op === 1.U){
//      sum := Cat(0.U,inputs(0)) - Cat(0.U,inputs(1)) + cin
//    }.otherwise {
//      sum := Cat(0.U,inputs(0)) + Cat(0.U,inputs(1)) + cin
//    }
//    val c = Wire(UInt(1.W))
//    c := sum (w)
//    c
//  }
//
//  def CF_Signed_3(op:UInt,cin:UInt = 0.U) :UInt = {
//    val sum = Wire(SInt((w+1).W))
//    val a = Wire(SInt((w+1).W))
//    val b = Wire(SInt((w+1).W))
//    when(S_inputs(0) >= 0.S){
//      a := Cat(0.U,inputs(0).asSInt()  //符号扩展
//    }.otherwise{
//      a := Cat(1.U,inputs(0).asSInt()
//    }
//    when(S_inputs(1) >= 0.S){
//      b := Cat(0.U,inputs(1)).asSInt()
//    }.otherwise{
//      b := Cat(1.U,inputs(1)).asSInt()
//    }
//    when(op === 1.U){
//      when(cin === 0.U){
//        sum := a - b
//      }.otherwise{
//        sum := a - b + 1.S
//      }
//    }.otherwise{
//      when(cin === 0.U){
//        sum := a + b
//      }.otherwise{
//        sum := a + b + 1.S
//      }
//    }
//    val c = Wire(UInt(1.W))
//    c := sum(w)
//    c
//  }
//
//  def overflow_3(o_res:UInt,op:UInt) :UInt={ 
//    val msb_a = Wire(UInt(1.W))
//    val msb_b = Wire(UInt(1.W))
//    val N = Wire(UInt(1.W))
//    msb_a := inputs(0)(w-1)
//    when(op === 1.U){
//      msb_b := !inputs(1)(w-1)
//    }.otherwise{
//      msb_b := inputs(1)(w-1)
//    }
//    N := o_res(w-1)
//    val ov = Wire(UInt(1.W))
//    ov := (msb_a & msb_b & !N)|(!msb_a & !msb_b & N)
//    ov
//  }
//
//
//  def getResult_U_3: Seq[(UInt, UInt)] = {
//    val Multi = Wire(UInt((2 * w).W))
//    Multi := inputs(0) * inputs(1)
//    //val op2res = new ArrayBuffer[(UInt,UInt)]()
//    val funSeq_res = operation.map(ins =>
//      ins._1 match {
//        case "Add" => ins._2.U -> (inputs(0) + inputs(1))
//        case "Sub" => ins._2.U -> (inputs(0) - inputs(1))
//        case "Adc" => ins._2.U -> (inputs(0) + inputs(1) + inputbit)
//        case "Abs" => ins._2.U -> inputs(0)
//        case "GTE_Max" => ins._2.U -> Mux(inputs(0) >= inputs(1), inputs(0), inputs(1))
//        case "LTE_Min" => ins._2.U -> Mux(inputs(0) <= inputs(1), inputs(0), inputs(1))
//        case "Sbc" => ins._2.U -> (inputs(0) - inputs(1) + inputbit)
//        case "Sel" => ins._2.U -> Mux(inputbit === 1.U, inputs(0), inputs(1))
//        case "Mult0" => ins._2.U -> Multi(w - 1, 0)
//        case "Mult1" => ins._2.U -> Multi((w - 1) + w / 2, w / 2)
//        case "Mult2" => ins._2.U -> Multi(2 * w - 1, w)
//        case "SHR" => ins._2.U -> (inputs(0) >> inputs(1)(log2Ceil(w) - 1, 0)).asUInt()
//        case "SHL" => ins._2.U -> (inputs(0) << inputs(1)(log2Ceil(w) - 1, 0)).asUInt()
//        case "Or" => ins._2.U -> (inputs(0) | inputs(1))
//        case "And" => ins._2.U -> (inputs(0) & inputs(1))
//        case "XOr" => ins._2.U -> (inputs(0) ^ inputs(1))
//        case "MULADD" => ins._2.U -> (Multi(w - 1, 0) + inputs(2))
//        case "MULSUB" => ins._2.U -> (Multi(w - 1, 0) - inputs(2))
//        case "TAA" => ins._2.U -> (inputs(0) + inputs(1) + inputs(2))
//        case "TAS" => ins._2.U -> (inputs(0) + inputs(1) - inputs(2))
//        case "TSA" => ins._2.U -> (inputs(0) - inputs(1) + inputs(2))
//        case "TSS" => ins._2.U -> (inputs(0) - inputs(1) - inputs(2))
//        case "CROP" => ins._2.U -> Mux(Mux(inputs(0) <= inputs(1), inputs(0), inputs(1)) >= inputs(2), Mux(inputs(0) <= inputs(1), inputs(0), inputs(1)), inputs(2))
//        case "MULSHR" => ins._2.U -> (Multi(w - 1, 0)>> inputs(2)).asUInt()
//        case _ => ins._2.U -> 0.U
//      }).toSeq
//
//    funSeq_res
//  }
//
//
//  def getResult_S_3: Seq[(UInt, SInt)] = {
//    val S_Multi = Wire(UInt((2 * w).W))
//    S_Multi := S_inputs(0) * S_inputs(1)
//    //val op2res = new ArrayBuffer[(UInt,UInt)]()
//    val funSeq_res = operation.map(ins =>
//      ins._1 match {
//        case "Add" => ins._2.U -> (S_inputs(0) + S_inputs(1))
//        case "Sub" => ins._2.U -> (S_inputs(0) - S_inputs(1))
//        case "Adc" => ins._2.U -> (inputs(0) + inputs(1) + inputbit).asSInt()
//        case "Abs" => ins._2.U -> Mux(S_inputs(0) >= 0.S, S_inputs(0), -S_inputs(0))
//        case "GTE_Max" => ins._2.U -> Mux(S_inputs(0) >= S_inputs(1), S_inputs(0), S_inputs(1))
//        case "LTE_Min" => ins._2.U -> Mux(S_inputs(0) <= S_inputs(1), S_inputs(0), S_inputs(1))
//        case "Sbc" => ins._2.U -> (inputs(0) - inputs(1) + inputbit).asSInt()
//        case "Sel" => ins._2.U -> Mux(inputbit === 1.U, S_inputs(0), S_inputs(1))
//        case "Mult0" => ins._2.U -> S_Multi(w - 1, 0).asSInt()
//        case "Mult1" => ins._2.U -> S_Multi((w - 1) + w / 2, w / 2).asSInt()
//        case "Mult2" => ins._2.U -> S_Multi(2 * w - 1, w).asSInt()
//        case "SHR" => ins._2.U -> (S_inputs(0) >> inputs(1)(log2Ceil(w) - 1, 0)).asSInt()
//        case "SHL" => ins._2.U -> (S_inputs(0) << inputs(1)(log2Ceil(w) - 1, 0)).asSInt()
//        case "Or" => ins._2.U -> (S_inputs(0) | S_inputs(1))
//        case "And" => ins._2.U -> (S_inputs(0) & S_inputs(1))
//        case "XOr" => ins._2.U -> (S_inputs(0) ^ S_inputs(1))
//        case "MULADD" => ins._2.U -> (S_Multi(w - 1, 0) + inputs(2)).asSInt()
//        case "MULSUB" => ins._2.U -> (S_Multi(w-1, 0) - inputs(2)).asSInt()
//        case "TAA" => ins._2.U -> (S_inputs(0) + S_inputs(1) + S_inputs(2))
//        case "TAS" => ins._2.U -> (S_inputs(0) + S_inputs(1) - S_inputs(2))
//        case "TSA" => ins._2.U -> (S_inputs(0) - S_inputs(1) + S_inputs(2))
//        case "TSS" => ins._2.U -> (S_inputs(0) - S_inputs(1) - S_inputs(2))
//        case "CROP" => ins._2.U -> Mux(Mux(S_inputs(0) <= S_inputs(1), S_inputs(0), S_inputs(1)) >= S_inputs(2), Mux(S_inputs(0) <= S_inputs(1), S_inputs(0), S_inputs(1)), S_inputs(2))
//        case "MULSHR" => ins._2.U -> (S_Multi(w - 1, 0) >> inputs(2)).asSInt()
//        case _ => ins._2.U -> 0.S
//      }).toSeq
//    funSeq_res
//  }
//  def getres_p_U_3 : Seq[(UInt,UInt)] = {
//
//    val funSeq_res_p = operation.map(ins =>
//      ins._1 match {
//        case "Add" => ins._2.U -> CF_Unsigned_3(0.U)
//        case "Sub" => ins._2.U -> CF_Unsigned_3(1.U)
//        case "Adc" => ins._2.U -> CF_Unsigned_3(0.U,inputbit)
//        case "Sbc" => ins._2.U -> CF_Unsigned_3(1.U,inputbit)
//        case "GTE_Max" => ins._2.U -> (inputs(0) >= inputs(1))
//        case "LTE_Min" => ins._2.U -> (inputs(0) <= inputs(1))
//        case "Abs" => ins._2.U -> inputs(0)(w-1)
//        case _ => ins._2.U -> 0.U
//      }
//    ).toSeq
//    funSeq_res_p
//  }
//  def getres_p_S_3 : Seq[(UInt,UInt)] = {
//    //val funSeq_res_p = new ArrayBuffer[(UInt,UInt)]() //存放res_p(1bit)
//    val funSeq_res_p = operation.map(ins =>
//      ins._1 match {
//        case "Add" => ins._2.U -> CF_Signed_3(0.U)
//        case "Sub" => ins._2.U -> CF_Signed_3(1.U)
//        case "Adc" => ins._2.U -> CF_Signed_3(0.U,inputbit)
//        case "Sbc" => ins._2.U -> CF_Signed_3(1.U,inputbit)
//        case "GTE_Max" => ins._2.U -> (S_inputs(0) >= S_inputs(1)).asUInt()
//        case "LTE_Min" => ins._2.U -> (S_inputs(0) <= S_inputs(1)).asUInt()
//        case "Abs" => ins._2.U -> inputs(0)(w-1)
//        case _ => ins._2.U -> 0.U
//      }
//    ).toSeq
//    funSeq_res_p
//  }
//
//  val C_U_3 = operation.map( ins =>
//    ins._1 match {
//      case "Add" => ins._2.U -> CF_Unsigned_3(0.U)
//      case "Sub" => ins._2.U -> CF_Unsigned_3(1.U)
//      case "Adc" => ins._2.U -> CF_Unsigned_3(0.U, inputbit)
//      case "Sbc" => ins._2.U -> CF_Unsigned_3(1.U,inputbit)
//      case _ => ins._2.U -> 0.U
//    }
//  ).toSeq
//  val C_S_3 = operation.map( ins =>
//    ins._1 match {
//      case "Add" => ins._2.U -> CF_Signed_3(0.U)
//      case "Sub" => ins._2.U -> CF_Signed_3(1.U)
//      case "Adc" => ins._2.U -> CF_Signed_3(0.U, inputbit)
//      case "Sbc" => ins._2.U -> CF_Signed_3(1.U, inputbit)
//      case _ => ins._2.U -> 0.U
//    }
//  ).toSeq
//  val V_U_3 = operation.map( ins =>
//    ins._1 match {
//      case "Add" => ins._2.U -> overflow_3(MuxLookup(io.configuration, 0.U, getResult_U_3), 0.U)
//      case "Adc" => ins._2.U -> overflow_3(MuxLookup(io.configuration, 0.U, getResult_U_3), 0.U)
//      case "Sub" => ins._2.U -> overflow_3(MuxLookup(io.configuration,0.U,getResult_U_3),1.U)
//      case "Sbc" => ins._2.U -> overflow_3(MuxLookup(io.configuration,0.U,getResult_U_3),1.U)
//      case _ => ins._2.U -> 0.U
//    }).toSeq
//  val V_S_3 = operation.map( ins =>
//    ins._1 match {
//      case "Add" => ins._2.U -> overflow_3(MuxLookup(io.configuration, 0.S, getResult_S_3).asUInt(), 0.U)
//      case "Adc" => ins._2.U -> overflow_3(MuxLookup(io.configuration, 0.S, getResult_S_3).asUInt(), 0.U)
//      case "Sub" => ins._2.U -> overflow_3(MuxLookup(io.configuration, 0.S, getResult_S_3).asUInt(), 1.U)
//      case "Sbc" => ins._2.U -> overflow_3(MuxLookup(io.configuration, 0.S, getResult_S_3).asUInt(), 1.U)
//      case _ => ins._2.U -> 0.U
//    }).toSeq
//
//  when(io.signed === UNSIGNED) {
//    io.res := MuxLookup(io.configuration,0.U,getResult_U_3)
//    io.res_p := MuxLookup(io.configuration,0.U,getres_p_U_3)
//    io.outputs(2) := MuxLookup(io.configuration,0.U,C_U_3)
//    io.outputs(3) := MuxLookup(io.configuration,0.U,V_U_3)
//  }.otherwise{
//    io.res := MuxLookup(io.configuration, 0.S, getResult_S_3).asUInt()
//    io.res_p := MuxLookup(io.configuration, 0.U, getres_p_S_3)
//    io.outputs(2) := MuxLookup(io.configuration,0.U,C_S_3)
//    io.outputs(3) := MuxLookup(io.configuration,0.U,V_S_3)
//  }
//
//  io.outputs(0) := (io.res === 0.U).asUInt()
//  io.outputs(1) := io.res(w-1)
//
//}
//











object ALU1 extends App {
  val operation :Map[String, Int] = Map(
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



  )
  new (chisel3.stage.ChiselStage).emitVerilog(new alu(operation,16,1))
}
