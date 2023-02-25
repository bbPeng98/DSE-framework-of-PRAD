package PRAD.lassen


import chisel3._

object lassenvar {
//alu
  val ALU_Add = 0.U(5.W)
  val ALU_Sub = 1.U(5.W)
  val ALU_Adc = 2.U(5.W)
  val ALU_Abs = 3.U(5.W)
  val ALU_GTE_Max = 4.U(5.W)
  val ALU_LTE_Min = 5.U(5.W)
  val ALU_Sbc = 6.U(5.W)
  val ALU_Sel = 8.U(5.W)
  val ALU_Multi0 = 11.U(5.W)
  val ALU_Multi1 = 12.U(5.W)
  val ALU_Multi2 = 13.U(5.W)
  val ALU_SHR = 15.U(5.W)
  val ALU_SHL = 17.U(5.W)
  val ALU_Or = 18.U(5.W)
  val ALU_And = 19.U(5.W)
  val ALU_XOr = 20.U(5.W)
  val ALU_FUN_NUM = 20

  val UNSIGNED = 0.U
  //UNSIGNED := 0.U
  val SIGNED = 1.U
  //SIGNED := 1.U
//mode
  val REG_CONST = 0.U
  //REG_CONST := 0.U
  val REG_DELAY = 2.U
  //REG_DELAY := 2.U
  val REG_BYPASS = 3.U
  //REG_BYPASS := 3.U
//common
  val DATAWIDTH_param = 16 //位宽
  val DATA_01_ADDR = 3 //config_addr为3的时候命中
  val BIT012_ADDR = 4
  val DATA0_START = 0
  val DATA0_WIDTH = DATAWIDTH_param
  val DATA1_START = 16
  val DATA1_WIDTH = DATAWIDTH_param
  val BIT0_START = 0
  val BIT1_START = 1
  val BIT2_START = 2
//cond
  val cond_Z = 0.U(4.W)         //EQ
  val cond_Z_n = 1.U(4.W)        //NE
  val cond_C = 2.U(4.W)          //UGE
  val cond_C_n = 3.U(4.W)        //ULT
  val cond_N = 4.U(4.W)         //<0
  val cond_N_n = 5.U(4.W)        //>0
  val cond_V = 6.U(4.W)         //overflow
  val cond_V_n = 7.U(4.W)       //no overflow
  val cond_EQ = 0.U(4.W)
  val cond_NE = 1.U(4.W)
  val cond_UGE = 2.U(4.W)       //>=
  val cond_ULT = 3.U(4.W)        //<
  //---------
  val cond_UGT = 8.U(4.W)        //>
  val cond_ULE = 9.U(4.W)        //<=
  val cond_SGE = 10.U(4.W)       //>=
  val cond_SLT = 11.U(4.W)       //<
  val cond_SGT = 12.U(4.W)       //>
  val cond_SLE = 13.U(4.W)      //<=
  val cond_LUT = 14.U(4.W)
  val cond_ALU = 15.U(4.W)


//_________________________________________________________________cond test

  def result_cond(cond_sel:Int,Z:Boolean,N:Boolean,C:Boolean,V:Boolean,alu_p:Boolean,lut_p:Boolean): Boolean={
    var output = false

    if(cond_sel == 0){ //
      output = Z
    }else if(cond_sel == 1){
      output = (!Z)
    }else if(cond_sel == 2){
      output = C
    }else if(cond_sel == 3){
      output = (!C)
    }else if(cond_sel == 4){
      output = N
    }else if(cond_sel == 5){
      output = (!N)
    }else if(cond_sel == 6){
      output = V
    }else if(cond_sel == 7){ //
      output = (!V)
    }else if(cond_sel == 8){ //
      output = (C&(!Z))
    }else if(cond_sel == 9){ //
      output = ((!C)|Z)
    }else if(cond_sel == 10){
      output = (N == V)
      //output = (if(N == V)1 else 0)
    }else if(cond_sel == 11){
      //output = (if(N == V) 0 else 1)
      output = (N!=V)
    }else if(cond_sel == 12){
      // val temp = (if(N==V)1 else 0)
      val temp = (N == V)
      output = ((!Z)&temp)
    }else if(cond_sel == 13){ //
      // val temp = (if(N!=V)1 else 0)
      val temp = (N != V)
      output = (Z|temp)
    }else if(cond_sel == 14){
      output = lut_p
    }else if(cond_sel == 15){
      output = alu_p
    }
    output
  }


//_________________________________________________________________lut test

  def result_lut(config:Int,i:Int,j:Int,k:Int):Int={
    val shitf = 4*i+2*j+k
    val out = config >> shitf & 1
    out
  }

//_________________________________________________________________mode test

  def OutData(mode:Int,const:Int,data:Int,reg_data: Int):Int= {
  if (mode == 0) {
    const
  } else if (mode == 3) {
    data
  } else {
    reg_data
  }
}

  def OutReg(mode:Int,cfg_en:Int,clk_en:Int,data:Int,cfg_data:Int):(Int,Int) ={
    var reg_data = 0
    var reg_en = 0
    if(cfg_en == 1){
      reg_data = cfg_data
      reg_en = 1
    }else if (mode == 2){
      reg_data = data
      reg_en = clk_en
    }else{
      reg_data = data
      reg_en = 0
    }
    (reg_data,reg_en)
  }

  def result_mode(mode:Int,config_we:Int,config_data:Int,data:Int,clk_en:Int,out_data_reg:Int):Int = {
    var out = 0
    //    poke(c.io.data,data)
    //    poke(c.io.clk_en,clk_en)
    //    poke(c.io.const_,const)
    //    poke(c.io.configuration_we,config_we)
    //    poke(c.io.configuration_data,config_data)
    //    poke(c.io.mode,mode)
    if( OutReg(mode,config_we,clk_en,data,config_data)._2 == 1){
      out = OutReg(mode,config_we,clk_en,data,config_data)._1
    }else{
      out = out_data_reg
      //out_data_reg = OutReg(mode,config_we,clk_en,data,config_data)._1
    }
    out
  }

//_________________________________________________________________alu test


  def overflow(a:Int,b:Int,op:Int,res:Int,WIDTH:Int):Int ={
    val a_ = (a>>(WIDTH-1) & 1)
    var b_ = (b>>(WIDTH-1) & 1)
    val res_ = ((res>>(WIDTH-1)) & 1)
    if(op == 1){ 
      b_ = ~b_}else{b_ = b_}
    val v = (a_ & b_ & ~res_)|(~a_ & ~b_ & res_ )
    v
  }

  def overflow_alu(config:Int,a:Int,b:Int,res:Int,WIDTH:Int):Int = {
    var out = 0
    if (config == 0 | config == 2) {
      out = overflow(a, b, 0, res, WIDTH)
    } else if (config == 1 | config == 6) {
      out = overflow(a, b, 1, res, WIDTH)
    }
    out
  }


  def CF(a:Int,b:Int,op:Int,cin:Int = 0):Int ={
    var sum = 0
    if ( op == 1){
      sum = a - b + cin
    }else{
      sum = a + b + cin
    }
    val c = (sum >> 16) & 1
    c
  }

  def CF_alu(config:Int,a:Int,b:Int,d:Int): Int ={
    var out = 0
    if(config == 0){
      out = CF(a,b,0)
    }else if(config == 1){
      out = CF(a,b,1)
    }else if(config == 2){
      out = CF(a,b,0,d)
    }else if(config == 6){
      out = CF(a,b,1,d)
    }
    out
  }


  def Z(res:Int):Int ={
    if (res == 0){
      1
    }else{
      0
    }
  }


  def N(res:Int,WIDTH:Int):Int ={
    var n_ = 0
    n_ = (res >> (WIDTH-1)) & 1
    n_
  }

  def result_alu(configuration:Int,signed:Int,a:Int,b:Int,d:Int,maxInt:Int):(Int,Int)= {
    var result = 0
    var result_p = 0
//    poke(c.io.configuration, configuration)
//    poke(c.io.inputs(0), a)
//    poke(c.io.inputs(1), b)
//    poke(c.io.inputs(2), d)
//    poke(c.io.signed, signed)

    if (signed == 1) {
      configuration match {
        case 0 => {
          result = (a + b) &(maxInt-1)
          result_p = CF(a, b, 0)}
        case 1 => {
          result = (a - b) &(maxInt-1)
          result_p = CF(a, b, 1)}
        case 2 => {
          result = (a + b + d) &(maxInt-1)
          result_p = CF(a, b, 0, d)}
        case 3 => {
          result = if (a >= 0) a else -a
          result_p = if (a >= 0) 1 else 0}
        //expect(c.io.res, result)}
        case 4 => {
          result = (if (a >= b) a else b) &(maxInt-1)
          result_p = if (a >= b) 1 else 0}
        //expect(c.io.s_res, result)}
        case 5 => {
          result = (if (a <= b) a else b) &(maxInt-1)
          result_p = if (a <= b) 1 else 0}
        // expect(c.io.s_res, result)}
        case 6 => {
          result = (a - b + d)&(maxInt-1)
          result_p = CF(a, b, 1, d)}
        case 8 => {
          result = (if (d == 1) a else b)&(maxInt-1)}
        //expect(c.io.s_res, result)}
        case 11 => {
          result = (a * b) & (maxInt - 1)}
        //expect(c.io.res, result)}
        case 12 => {
          result = (a * b >> 8) & (maxInt - 1)}
        // expect(c.io.res, result)}
        case 13 => {
          result = (a * b >> 16) & (maxInt - 1)}
        // expect(c.io.res, result)}
        case 15 => {
          result = (a >> (b & 15) & (maxInt - 1))}
        // expect(c.io.res, result)}
        case 17 => {
          result = (a << (b & 15) & (maxInt - 1))}
        // expect(c.io.res, result)}
        case 18 => {
          result = (a | b) &(maxInt - 1)}
        //expect(c.io.s_res, result)}
        case 19 => {
          result = (a & b) &(maxInt - 1)}
        // expect(c.io.s_res, result)}
        case 20 => {
          result = (a ^ b) &(maxInt - 1)}
        //expect(c.io.s_res, result)}
        case _ => {
          result = 0
          result_p = 0}
        //expect(c.io.res, result)}
      }
    } else {

      configuration match {
        case 0 => {
          result = (a + b) & (maxInt - 1)
          result_p = CF(a, b, 0)
          //expect(c.io.outputs(2), CF(a, b, 0))
        }
        case 1 => {
          result = (a - b) & (maxInt - 1)
          result_p = CF(a, b, 1)
          //expect(c.io.outputs(2), CF(a, b, 1))
        }
        case 2 => {
          result = (a + b + d) & (maxInt - 1)
          result_p = CF(a, b, 0, d)
          //expect(c.io.outputs(2), CF(a, b, 0, d))
        }
        case 3 => {
          result = a
          result_p = 1
        }
        case 4 => {
          result = if (a >= b) a else b
          result_p = if (a >= b) 1 else 0
        }
        case 5 => {
          result = if (a <= b) a else b
          result_p = if (a <= b) 1 else 0
        }
        case 6 => {
          result = (a - b + d) & (maxInt - 1)
          result_p = CF(a, b, 1, d)
          //expect(c.io.outputs(2), CF(a, b, 1, d))
        }
        case 8 => result = if (d == 1) a else b
        case 11 => result = (a * b) & (maxInt - 1)
        case 12 => result = (a * b >> 8) & (maxInt - 1)
        case 13 => result = (a * b >> 16) & (maxInt - 1)
        case 15 => result = (a >> (b & 15) & (maxInt - 1))
        case 17 => result = (a << (b & 15) & (maxInt - 1))
        case 18 => result = a | b
        case 19 => result = a & b
        case 20 => result = a ^ b
        case _ => {
          result = 0
          result_p = 0}
      }
    }
    (result,result_p)
  }


  def symbol(signed:Int,data:Int,maxInt:Int):Int={
    var out = data
    if(signed == 0){
      if(data >= 0){
        data
      }else{
        out = data & (maxInt-1)
        out
      }
    }else{
      if((((data >> 15 & 1) == 1) && (data >= 0)) ){
        out = 0 - ((~data + 1) & (maxInt-1))
        out
      }else{
        data
      }

    }
  }


//_____________________________________________________________

  def result_sim(config_address:Int,config_data:Int,value1:Double,inst:Long,inst1:Int,config_en:Int,a:Int,
                b:Int,d:Int,e:Int,f:Int,clk_en:Int,maxInt:Int,WIDTH:Int,
                 out_data_reg1:Int,out_data_reg2:Int,out_data_reg3:Int,out_data_reg4:Int,out_data_reg5:Int):
  (Int,Int,Int,Int,Int,Int,Int,Int) = {
    var out_data_reg1_ = out_data_reg1
    var out_data_reg2_ = out_data_reg2
    var out_data_reg3_ = out_data_reg3
    var out_data_reg4_ = out_data_reg4
    var out_data_reg5_ = out_data_reg5
    //mode
    val configuration_we1 = if ((config_address & 15) == DATA_01_ADDR) 1 else 0
    val configuration_we2 = if ((config_address & 15) == BIT012_ADDR) 1 else 0
    val configuration_data1 = (config_data >> DATA0_START) & (value1.toInt - 1)
    val configuration_data2 = (config_data >> DATA1_START) & (value1.toInt - 1)
    val configuration_data3 = (config_data >> BIT0_START) & 1
    val configuration_data4 = (config_data >> BIT1_START) & 1
    val configuration_data5 = (config_data >> BIT2_START) & 1
    val const_1 = (inst >> 24) & (value1.toInt - 1)
    val const_2 = (inst >> 42) & (value1.toInt - 1)
    val const_3 = (inst >> 60) & 1
    val const_4 = (inst >> 63) & 1
    val const_5 = (inst1 >> 2) & 1
    val mode1 = (inst >> 22) & 3
    val mode2 = (inst >> 40) & 3
    val mode3 = (inst >> 58) & 3
    val mode4 = (inst >> 61) & 3
    val mode5 = inst1 & 3
    val temp1 = out_data_reg1
    val temp2 = out_data_reg2
    val temp3 = out_data_reg3
    val temp4 = out_data_reg4
    val temp5 = out_data_reg5

    out_data_reg1_ = result_mode(mode1.toInt, (configuration_we1 & config_en), configuration_data1, a, clk_en, out_data_reg1)
    out_data_reg2_ = result_mode(mode2.toInt, (configuration_we1 & config_en), configuration_data2, b, clk_en, out_data_reg2)
    out_data_reg3_ = result_mode(mode3.toInt, (configuration_we2 & config_en), configuration_data3, d, clk_en, out_data_reg3)
    out_data_reg4_ = result_mode(mode4.toInt, (configuration_we2 & config_en), configuration_data4, e, clk_en, out_data_reg4)
    out_data_reg5_ = result_mode(mode5, (configuration_we2 & config_en), configuration_data5, f, clk_en, out_data_reg5)
    val out_data1 = OutData(mode1.toInt, const_1.toInt, a, temp1)
    val out_data2 = OutData(mode2.toInt, const_2.toInt, b, temp2)
    val out_data3 = OutData(mode3.toInt, const_3.toInt, d, temp3)
    val out_data4 = OutData(mode4.toInt, const_4.toInt, e, temp4)
    val out_data5 = OutData(mode5, const_5, f, temp5)

    //lut
    val lut_config = (inst >> 9) & 255 //8bit
    val lut_in0 = out_data3
    val lut_in1 = out_data4
    val lut_in2 = out_data5
    val lut_out = result_lut(lut_config.toInt, lut_in2, lut_in1, lut_in0)

    //alu
    val alu_signed = (inst >> 8) & 1
    val alu_config = inst & 31 //inst(4,0)
    val alu_in0 = symbol(((inst >> 8) & 1).toInt, out_data1, maxInt)
    val alu_in1 = symbol(((inst >> 8) & 1).toInt, out_data2, maxInt)
    val alu_in2 = out_data3
    val alu_res_p = result_alu(alu_config.toInt, alu_signed.toInt, alu_in0, alu_in1, alu_in2, maxInt)._2
    val alu_res = (result_alu(alu_config.toInt, alu_signed.toInt, alu_in0, alu_in1, alu_in2, maxInt)._1 & (maxInt - 1))


    //cond
    val cond_config = (inst >> 17) & 15
    val cond_alu_p = if (alu_res_p == 1) true else false
    val cond_lut_p = if (lut_out == 1) true else false
    val cond_Z = if (Z(alu_res) == 1) true else false
    val cond_N = if (N(alu_res, WIDTH) == 1) true else false
    val cond_C = if (CF_alu(alu_config.toInt, alu_in0, alu_in1, alu_in2) == 1) true else false
    val cond_V = if (overflow_alu(alu_config.toInt, alu_in0, alu_in1, alu_res, WIDTH) == 1) true else false
    val cond_out = if(result_cond(cond_config.toInt, cond_Z, cond_N, cond_C, cond_V, cond_alu_p, cond_lut_p)) 1 else 0

    //calculate read_config_data
    var read_config_data: Long = 0
    if (configuration_we2 == 1) {
      read_config_data = (out_data_reg3_ << 31) | (out_data_reg4_ << 30) | (out_data_reg5_ << 29)
    } else {
      read_config_data = (out_data_reg1_ << 16) | (out_data_reg2_ & (maxInt - 1))
    }
    (alu_res,cond_out,read_config_data.toInt,out_data_reg1_,out_data_reg2_,out_data_reg3_,out_data_reg4_,out_data_reg5_)
  }



}
