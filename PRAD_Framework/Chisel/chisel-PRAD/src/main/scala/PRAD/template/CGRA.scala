package PRAD.template

import PRAD.common.MacroVar._
import PRAD.common.Muxn
import PRAD.ir._
import PRAD.memory._
import PRAD.interconnect._
import PRAD.lassen._
import PRAD.io._
//import PRAD.memory.MemCore.MemCore
import chisel3._
import chisel3.util.log2Ceil

import scala.collection.mutable
import scala.collection.mutable.{ArrayBuffer, ListBuffer}



/** A template CGRA
 *
 * @param attrs     module attributes
 */
class CGRA(attrs: mutable.Map[String, Any], dumpIR: Boolean) extends Module with IR{
  apply(attrs)
  apply("top_module", "CGRA")
  val rows = getAttrValue("num_row").asInstanceOf[Int]     // unit number in a row
  val cols = getAttrValue("num_colum").asInstanceOf[Int]   // unit number in a colum
  val dataWidth = getAttrValue("data_width").asInstanceOf[Int] // data width in bit
  // cfgParams
  val cfgDataWidth = getAttrValue("cfg_data_width").asInstanceOf[Int]
  val cfgAddrWidth = getAttrValue("cfg_addr_width").asInstanceOf[Int]
  val cfgAddrWidthOfUnit = getAttrValue("cfg_addr_width_Unit").asInstanceOf[Int]
//  val cfgBlkOffset = getAttrValue("cfg_blk_offset").asInstanceOf[Int]   // configuration offset bit of blocks
  // ====== GPE-Specific attributes =======//
  val PEinputnum = getAttrValue("PEinputnum").asInstanceOf[List[Int]]//.asInstanceOf[ListBuffer[Int]]
//  val PEinputnumTuple = getAttrValue("PEinputnum").asInstanceOf[Tuple2[Int,Int]]//.asInstanceOf[ListBuffer[Int]]
//  val PEinputnum = ListBuffer(0,0)
//  PEinputnum(0) = PEinputnumTuple._1
//  PEinputnum(1) = PEinputnumTuple._2
//  val functionSelect = getAttrValue("functionSelect").asInstanceOf[Int]
  val operations = getAttrValue("operations").asInstanceOf[Map[String,Int]]
  val lut_n = getAttrValue("lut_n").asInstanceOf[Int]
  val has_3input = getAttrValue("has_3input").asInstanceOf[Int]

  // ====== MEM-Specific attributes =======//
  val interconnect_output_ports = getAttrValue("interconnect_output_ports").asInstanceOf[Int]
  val mem_width = getAttrValue("mem_width").asInstanceOf[Int]
  val mem_depth = getAttrValue("mem_depth").asInstanceOf[Int]
  val use_sram_stub = getAttrValue("use_sram_stub").asInstanceOf[Int]
  val target = getAttrValue("target").asInstanceOf[List[Int]]
  val iterator_support = getAttrValue("iterator_support").asInstanceOf[Int]
  val config_width = getAttrValue("config_width").asInstanceOf[Int]
  val interconnect_input_ports = getAttrValue("interconnect_input_ports").asInstanceOf[Int]
  val agg_addr_width = getAttrValue("agg_addr_width").asInstanceOf[Int]
  val agg_iter_support = getAttrValue("agg_iter_support").asInstanceOf[Int]
  val agg_range_width = getAttrValue("agg_range_width").asInstanceOf[Int]
  val tb_range_width = getAttrValue("tb_range_width").asInstanceOf[Int]
  val tb_addr_width = getAttrValue("tb_addr_width").asInstanceOf[Int]
  val banks = getAttrValue("banks").asInstanceOf[Int]
  val tb_height = getAttrValue("tb_height").asInstanceOf[Int]
  val agg_height = getAttrValue("agg_height").asInstanceOf[Int]
  val agg_rd_addr_gen_width = getAttrValue("agg_rd_addr_gen_width").asInstanceOf[Int]

  // ====== GIB-Specific attributes =======//
  val numTrackCoarse = getAttrValue("num_track_coarse").asInstanceOf[Int]
  val numTrackFine = getAttrValue("num_track_fine").asInstanceOf[Int]
  // trackRegedMode, 0: no reg; 1: half of GIBs reged; 2: all GIBs reged
  val trackRegedMode = getAttrValue("track_reged_mode").asInstanceOf[Int]
  // fcList
  //TODO:check fcMap for coarse and fine
  val fcMap_coarse = getAttrValue("connect_flexibility_coarse").asInstanceOf[mutable.Map[String, Int]]
  val fcMap_fine = getAttrValue("connect_flexibility_fine").asInstanceOf[mutable.Map[String, Int]]
  // if support diagonal connections between OPins and IPins
  val diagPinConect = getAttrValue("diag_iopin_connect").asInstanceOf[Boolean]


  val io = IO(new Bundle{
    val glb2io_16 = Input(Vec(cols, UInt(16.W))) //without GIB
    val glb2io_1  = Input(Vec(cols, UInt(1.W)))  //without GIB
    val stall     = Input(UInt((cols).W))   //without GIB
    val config_addr = Input(Vec(2*cols+1, UInt(cfgAddrWidth.W)))  //each column
    val config_data = Input(Vec(2*cols+1, UInt(cfgDataWidth.W)))  //each column
    val config_read = Input(Vec(cols/4, Bool()))  //only mem
    val config_write = Input(Vec(2*cols+1, Bool()))  //each column
    val io2glb_16 = Output(Vec(cols, UInt(16.W)))  //without GIB
    val io2glb_1 = Output(Vec(cols, UInt(1.W)))  //without GIB
    val read_config_data_sel = Input(Vec(rows,UInt(log2Ceil(cols/4).W)))//only mem
    val read_config_data_sel_1 = Input(Vec(rows,UInt(log2Ceil(cols/4).W)))//only mem
    val read_config_data_sel_2 = Input(Vec(rows,UInt(log2Ceil(cols/4).W)))//only mem
    val read_config_data = Output(Vec(rows,UInt(cfgDataWidth.W)))//only mem
    val read_config_data_1 = Output(Vec(rows,UInt(cfgDataWidth.W)))//only mem
    val read_config_data_2 = Output(Vec(rows,UInt(cfgDataWidth.W)))//only mem
  })

  val pe_attrs: mutable.Map[String, Any] = mutable.Map(
    "data_width" -> dataWidth,
    "cfg_data_width" -> cfgDataWidth,
    "cfg_addr_width_Unit" -> cfgAddrWidthOfUnit,
    "input_coarse_num" -> PEinputnum(0),
    "input_fine_num" -> PEinputnum(1),
    "operations" -> operations,
    "lut_n" -> lut_n,
    "has_3input" -> has_3input
  )

  val mem_attrs: mutable.Map[String, Any] = mutable.Map(
    "data_width" -> dataWidth,
    "cfg_data_width" -> cfgDataWidth,
    "cfg_addr_width_Unit" -> cfgAddrWidthOfUnit,
  )

  val gib_attrs_coarse: mutable.Map[String, Any] = mutable.Map(
    "data_width" -> dataWidth,
    "cfg_data_width" -> cfgDataWidth,
    "cfg_addr_width" -> cfgAddrWidthOfUnit,
//    "cfg_blk_index" -> 0,
//    "cfg_blk_offset" -> cfgBlkOffset,
    "x" -> 0,
    "y" -> 0,
    "num_track" -> numTrackCoarse,
    "diag_iopin_connect" -> diagPinConect,
    "num_iopin_list" -> mutable.Map[String, Int](),
    "connect_flexibility" -> fcMap_coarse,
    "track_reged" -> false
  )

  val gib_attrs_fine: mutable.Map[String, Any] = mutable.Map(
    "data_width" -> 1,
    "cfg_data_width" -> cfgDataWidth,
    "cfg_addr_width" -> cfgAddrWidthOfUnit,
//    "cfg_blk_index" -> 0,
//    "cfg_blk_offset" -> cfgBlkOffset,
    "x" -> 0,
    "y" -> 0,
    "num_track" -> numTrackFine,
    "diag_iopin_connect" -> diagPinConect,
    "num_iopin_list" -> mutable.Map[String, Int](),
    "connect_flexibility" -> fcMap_fine,
    "track_reged" -> false
  )

  val io_attrs: mutable.Map[String, Any] = mutable.Map(
    "data_width" -> dataWidth,
  )

  val gib_coordinate: mutable.Map[(Int, Int), Int] = mutable.Map()
  val unit_coordinate: mutable.Map[(Int, Int), Int] = mutable.Map()

  val ios = new ArrayBuffer[Tile_io_core]()
  val pes = new ArrayBuffer[PE]()
  val mems = new ArrayBuffer[mem_top]()
  val gibs_coarse = new ArrayBuffer[GIB]()
  val gibs_fine = new ArrayBuffer[GIB]()
  val read_cfg_data_muxs = new ArrayBuffer[Muxn]()
  val read_cfg_data_muxs_1 = new ArrayBuffer[Muxn]()
  val read_cfg_data_muxs_2 = new ArrayBuffer[Muxn]()

  //read_cfg_data_mux
  for(i<-0 until rows){
    read_cfg_data_muxs += Module(new Muxn(cfgDataWidth,cols/4))
    read_cfg_data_muxs_1 += Module(new Muxn(cfgDataWidth,cols/4))
    read_cfg_data_muxs_2 += Module(new Muxn(cfgDataWidth,cols/4))
  }

  // top row, Tile_io
  for(i <- 0 until cols){
      ios += Module(new Tile_io_core(io_attrs))
  }

  // PE and MEM row: 2*(1,2,...,rows)+1 row
  for(i <- 0 until rows){
    val y = 2*i+2
    for(j <- 0 until cols){
      val x = 2*j+1
      val coordinate = x*16*16+y
      if ((j + 1) % 4 == 0){
        mems += Module(new mem_top(mem_attrs))
      }else{
        pes += Module(new PE(pe_attrs))
      }
      unit_coordinate += ((i,j) -> coordinate)
    }
  }


  // GIB: 2*(1,...,rows+1) row
  val iopin_list_map = mutable.Map[mutable.Map[String, Int], Int]()
  for(i <- 0 to rows){
    for(j <- 0 to cols){
      //define GIB input/output nums in 4 directions(nw,nw,sw,se)
      val num_iopin_list_coarse = mutable.Map[String, Int]()
      val num_iopin_list_fine = mutable.Map[String, Int]()
      if ((j+1)%4 == 0){
        //for MEM left
        //coarse_grained
        num_iopin_list_coarse += "ipin_nw" -> {
          if(i > 0 && j > 0) PEinputnum(0) //asInstanceOf[List[Int]](0)
          else 0
        }
        num_iopin_list_coarse += "opin_nw" -> {   
          if(i > 0 && j > 0) 1
          else 0
        }
        num_iopin_list_coarse += "ipin_ne" -> {
          if(i == 0 && j < cols) 1
          else if(i > 0 && j < cols) 4
          else 0
        }
        num_iopin_list_coarse += "opin_ne" -> {
          if(i == 0 && j < cols) 1
          else if(i > 0 && j < cols) 2
          else 0
        }
        num_iopin_list_coarse += "ipin_se" -> {
          if(i < rows && j < cols) 4
          else 0
        }
        num_iopin_list_coarse += "opin_se" -> {
          if(i < rows && j < cols) 2
          else 0
        }
        num_iopin_list_coarse += "ipin_sw" -> {
          if(i < rows && j > 0) PEinputnum(0)//.asInstanceOf[List[Int]](0)
          else 0
        }
        num_iopin_list_coarse += "opin_sw" -> {
          if(i < rows && j > 0) 1
          else 0
        }
        //fine-grained
        num_iopin_list_fine += "ipin_nw" -> {
          if(i > 0 && j > 0) PEinputnum(1)//.asInstanceOf[List[Int]](1)
          else 0
        }
        num_iopin_list_fine += "opin_nw" -> {
          if(i > 0 && j > 0) 1
          else 0
        }
        num_iopin_list_fine += "ipin_ne" -> {
          if(i == 0 && j < cols) 1
          else if(i > 0 && j < cols) 4
          else 0
        }
        num_iopin_list_fine += "opin_ne" -> {
          if(i == 0 && j < cols) 1
          else if(i > 0 && j < cols) 4
          else 0
        }
        num_iopin_list_fine += "ipin_se" -> {
          if(i < rows && j < cols) 4
          else 0
        }
        num_iopin_list_fine += "opin_se" -> {
          if(i < rows && j < cols) 4
          else 0
        }
        num_iopin_list_fine += "ipin_sw" -> {
          if(i < rows && j > 0) PEinputnum(1)//.asInstanceOf[List[Int]](1)
          else 0
        }
        num_iopin_list_fine += "opin_sw" -> {
          if(i < rows && j > 0) 1
          else 0
        }
      }else if ((j%4)==0){
        //for MEM right
        //coarse_grained
        num_iopin_list_coarse += "ipin_nw" -> {
          if(i > 0 && j > 0) 4
          else 0
        }
        num_iopin_list_coarse += "opin_nw" -> {
          if(i > 0 && j > 0) 2
          else 0
        }
        num_iopin_list_coarse += "ipin_ne" -> {
          if(i == 0 && j < cols) 1
          else if(i > 0 && j < cols) PEinputnum(0)//.asInstanceOf[List[Int]](0)
          else 0
        }
        num_iopin_list_coarse += "opin_ne" -> {
          if(i == 0 && j < cols) 1
          else if(i > 0 && j < cols) 1
          else 0
        }
        num_iopin_list_coarse += "ipin_se" -> {
          if(i < rows && j < cols) PEinputnum(0)//.asInstanceOf[Tuple2](0) //PEinputnum.asInstanceOf[List[Int]](0)
          else 0
        }
        num_iopin_list_coarse += "opin_se" -> {
          if(i < rows && j < cols) 1
          else 0
        }
        num_iopin_list_coarse += "ipin_sw" -> {
          if(i < rows && j > 0) 4
          else 0
        }
        num_iopin_list_coarse += "opin_sw" -> {
          if(i < rows && j > 0) 2
          else 0
        }
        //fine-grained
        num_iopin_list_fine += "ipin_nw" -> {
          if(i > 0 && j > 0) 4
          else 0
        }
        num_iopin_list_fine += "opin_nw" -> {
          if(i > 0 && j > 0) 4
          else 0
        }
        num_iopin_list_fine += "ipin_ne" -> {
          if(i == 0 && j < cols) 1
          else if(i > 0 && j < cols) PEinputnum(1)//.asInstanceOf[List[Int]](1)
          else 0
        }
        num_iopin_list_fine += "opin_ne" -> {
          if(i == 0 && j < cols) 1
          else if(i > 0 && j < cols) 1
          else 0
        }
        num_iopin_list_fine += "ipin_se" -> {
          if(i < rows && j < cols) PEinputnum(1)//.asInstanceOf[List[Int]](1)
          else 0
        }
        num_iopin_list_fine += "opin_se" -> {
          if(i < rows && j < cols) 1
          else 0
        }
        num_iopin_list_fine += "ipin_sw" -> {
          if(i < rows && j > 0) 4
          else 0
        }
        num_iopin_list_fine += "opin_sw" -> {
          if(i < rows && j > 0) 4
          else 0
        }
      }
      else{
        //for PE
        //coarse_grained
        num_iopin_list_coarse += "ipin_nw" -> {
          if(i > 0 && j > 0) PEinputnum(0)//.asInstanceOf[List[Int]](0)
          else 0
        }
        num_iopin_list_coarse += "opin_nw" -> {
          if(i > 0 && j > 0) 1
          else 0
        }
        num_iopin_list_coarse += "ipin_ne" -> {
          if(i == 0 && j < cols) 1
          else if(i > 0 && j < cols) PEinputnum(0)//.asInstanceOf[List[Int]](0)
          else 0
        }
        num_iopin_list_coarse += "opin_ne" -> {
          if(i == 0 && j < cols) 1
          else if(i > 0 && j < cols) 1
          else 0
        }
        num_iopin_list_coarse += "ipin_se" -> {
          if(i < rows && j < cols) PEinputnum(0)//.asInstanceOf[List[Int]](0)
          else 0
        }
        num_iopin_list_coarse += "opin_se" -> {
          if(i < rows && j < cols) 1
          else 0
        }
        num_iopin_list_coarse += "ipin_sw" -> {
          if(i < rows && j > 0) PEinputnum(0)//.asInstanceOf[List[Int]](0)
          else 0
        }
        num_iopin_list_coarse += "opin_sw" -> {
          if(i < rows && j > 0) 1
          else 0
        }
        //fine-grained
        num_iopin_list_fine += "ipin_nw" -> {
          if(i > 0 && j > 0) PEinputnum(1)//.asInstanceOf[List[Int]](1)
          else 0
        }
        num_iopin_list_fine += "opin_nw" -> {
          if(i > 0 && j > 0) 1
          else 0
        }
        num_iopin_list_fine += "ipin_ne" -> {
          if(i == 0 && j < cols) 1
          else if(i > 0 && j < cols) PEinputnum(1)//.asInstanceOf[List[Int]](1)
          else 0
        }
        num_iopin_list_fine += "opin_ne" -> {
          if(i == 0 && j < cols) 1
          else if(i > 0 && j < cols) 1
          else 0
        }
        num_iopin_list_fine += "ipin_se" -> {
          if(i < rows && j < cols) PEinputnum(1)//.asInstanceOf[List[Int]](1)
          else 0
        }
        num_iopin_list_fine += "opin_se" -> {
          if(i < rows && j < cols) 1
          else 0
        }
        num_iopin_list_fine += "ipin_sw" -> {
          if(i < rows && j > 0) PEinputnum(1)//.asInstanceOf[List[Int]](1)
          else 0
        }
        num_iopin_list_fine += "opin_sw" -> {
          if(i < rows && j > 0) 1
          else 0
        }
      }
      val x = 2*j
      val y = 2*i+1
      val coordinate = x*16*16+y
      gib_coordinate += ((i,j) -> coordinate)
//      //TODO: use of index?
//      val index = x*(cols+1) + j + 1
      val reged = {
        if(trackRegedMode == 0) false
        else if(trackRegedMode == 2) true
        else (i%2 + j%2) == 1
      }
      //fine is same as coarse
      gib_attrs_coarse("num_iopin_list") = num_iopin_list_coarse
//      gib_attrs_coarse("cfg_blk_index") = index
      gib_attrs_coarse("x") = x
      gib_attrs_coarse("y") = y
      gib_attrs_coarse("track_reged") = reged
      gibs_coarse += Module(new GIB(gib_attrs_coarse))

      gib_attrs_fine("num_iopin_list") = num_iopin_list_fine
//      gib_attrs_fine("cfg_blk_index") = index
      gib_attrs_fine("x") = x
      gib_attrs_fine("y") = y
      gib_attrs_fine("track_reged") = reged
      gibs_fine += Module(new GIB(gib_attrs_fine))

    }
  }

  // ======= connections attribute ========//
//  apply("connection_format", ("src_id", "src_type", "src_out_idx", "dst_id", "dst_type", "dst_in_idx"))
//  // This:src_out_idx is the input index
//  // This:dst_in_idx is the output index
//  val connections = ListBuffer[(Int, String, Int, Int, String, Int)]()
//  val lastRowGibBaseIdx = rows*(cols+1)

  //IO connections
  ios.zipWithIndex.map{ case (iO, i) =>
    iO.io.tile_id := (i*16*16+0).U
    iO.io.glb2io_1 := io.glb2io_1(i)
    iO.io.glb2io_16 := io.glb2io_16(i)
    iO.io.f2io_1 := gibs_fine(i).io.ipinNE(0) 
    iO.io.f2io_16 := gibs_coarse(i).io.ipinNE(0)  
    io.io2glb_16(i) := iO.io.io2glb_16
    io.io2glb_1(i) := iO.io.io2glb_1
    gibs_coarse(i).io.opinNE.map { in => in := ios(i).io.io2f_16 }
    gibs_fine(i).io.opinNE.map { in => in := ios(i).io.io2f_1 }
  }


  val pePortCoarse: mutable.Map[Any, Int] = mutable.Map()
  val pePortFine: mutable.Map[Any, Int] = mutable.Map()

  val memPortCoarse: mutable.Map[Any, Int] = mutable.Map()
  val memPortFine: mutable.Map[Any, Int] = mutable.Map()
  // PE and MEM to GIB connections
  //ipin is GIB2PE, opin is PE2GIB
  var memNum = 0
  for(i <- 0 until rows){
    for(j <- 0 until cols){
      if ((j + 1) % 4 == 0){
//        mems(memNum).io.config_write := io.config_write(j)
        mems(memNum).io.in_coarse.zipWithIndex.map{ case (in, k) =>
          if(k%4 == 0){ // northwest - southeast
            in := gibs_coarse(i*(cols+1)+j).io.ipinSE(k/4)
            memPortCoarse += ((SOUTHEAST,k/4) -> k)
          } else if(k%4 == 1) { // northeast - southwest
            in := gibs_coarse(i*(cols+1)+j+1).io.ipinSW(k/4)
            memPortCoarse += ((SOUTHWEST,k/4) -> k)
          } else if(k%4 == 2) { // southwest - northeast
            in := gibs_coarse((i+1)*(cols+1)+j).io.ipinNE(k/4)
            memPortCoarse += ((NORTHEAST,k/4) -> k)
          } else { // southeast - northwest
            in := gibs_coarse((i+1)*(cols+1)+j+1).io.ipinNW(k/4)
            memPortCoarse += ((NORTHWEST,k/4) -> k)
          }
        }
        mems(memNum).io.in_fine.zipWithIndex.map{ case (in, k) =>
          if(k%4 == 0){ // northwest - southeast
            in := gibs_fine(i*(cols+1)+j).io.ipinSE(k/4)
            memPortFine += ((SOUTHEAST,k/4) -> k)
          } else if(k%4 == 1) { // northeast - southwest
            in := gibs_fine(i*(cols+1)+j+1).io.ipinSW(k/4)
            memPortFine += ((SOUTHWEST,k/4) -> k)
          } else if(k%4 == 2) { // southwest - northeast
            in := gibs_fine((i+1)*(cols+1)+j).io.ipinNE(k/4)
            memPortFine += ((NORTHEAST,k/4) -> k)
          } else { // southeast - northwest
            in := gibs_fine((i+1)*(cols+1)+j+1).io.ipinNW(k/4)
            memPortFine += ((NORTHWEST,k/4) -> k)
          }
        }
//        println("i: "+i+"j: "+j+"index: "+(i*(cols+1)+j))
//        println(memNum)
        mems(memNum).io.out_coarse.zipWithIndex.map{ case (out, k) =>
          gibs_coarse(i*(cols+1)+j).io.opinSE(k) := out
          gibs_coarse(i*(cols+1)+j+1).io.opinSW(k) := out
          gibs_coarse((i+1)*(cols+1)+j).io.opinNE(k) := out
          gibs_coarse((i+1)*(cols+1)+j+1).io.opinNW(k) := out
        }
        mems(memNum).io.out_fine.zipWithIndex.map{ case (out, k) =>
          gibs_fine(i*(cols+1)+j).io.opinSE(k) := out
          gibs_fine(i*(cols+1)+j+1).io.opinSW(k) := out
          gibs_fine((i+1)*(cols+1)+j).io.opinNE(k) := out
          gibs_fine((i+1)*(cols+1)+j+1).io.opinNW(k) := out
        }
        memNum += 1
      }else{
//        pes(i*cols+j-memNum).io.io_config_write := io.config_write(j)
        pes(i*cols+j-memNum).io.in_coarse.zipWithIndex.map{ case (in, k) =>
          if(k%4 == 0){ // northwest - southeast
            in := gibs_coarse(i*(cols+1)+j).io.ipinSE(k/4)
            pePortCoarse += ((SOUTHEAST,k/4) -> k)
          } else if(k%4 == 1) { // northeast - southwest
            in := gibs_coarse(i*(cols+1)+j+1).io.ipinSW(k/4)
            pePortCoarse += ((SOUTHWEST,k/4) -> k)
          } else if(k%4 == 2) { // southwest - northeast
            in := gibs_coarse((i+1)*(cols+1)+j).io.ipinNE(k/4)
            pePortCoarse += ((NORTHEAST,k/4) -> k)
          } else { // southeast - northwest
            in := gibs_coarse((i+1)*(cols+1)+j+1).io.ipinNW(k/4)
            pePortCoarse += ((NORTHWEST,k/4) -> k)
          }
        }
        pes(i*cols+j-memNum).io.in_fine.zipWithIndex.map{ case (in, k) =>
          if(k%4 == 0){ // northwest - southeast
            in := gibs_fine(i*(cols+1)+j).io.ipinSE(k/4)
            pePortFine += ((SOUTHEAST,k/4) -> k)
          } else if(k%4 == 1) { // northeast - southwest
            in := gibs_fine(i*(cols+1)+j+1).io.ipinSW(k/4)
            pePortFine += ((SOUTHWEST,k/4) -> k)
          } else if(k%4 == 2) { // southwest - northeast
            in := gibs_fine((i+1)*(cols+1)+j).io.ipinNE(k/4)
            pePortFine += ((NORTHEAST,k/4) -> k)
          } else { // southeast - northwest
            in := gibs_fine((i+1)*(cols+1)+j+1).io.ipinNW(k/4)
            pePortFine += ((NORTHWEST,k/4) -> k)
          }
        }
        pes(i*cols+j-memNum).io.out_coarse.zipWithIndex.map{ case (out, k) =>
          gibs_coarse(i*(cols+1)+j).io.opinSE(k) := out
          gibs_coarse(i*(cols+1)+j+1).io.opinSW(k) := out
          gibs_coarse((i+1)*(cols+1)+j).io.opinNE(k) := out
          gibs_coarse((i+1)*(cols+1)+j+1).io.opinNW(k) := out
        }
        pes(i*cols+j-memNum).io.out_fine.zipWithIndex.map{ case (out, k) =>
          gibs_fine(i*(cols+1)+j).io.opinSE(k) := out
          gibs_fine(i*(cols+1)+j+1).io.opinSW(k) := out
          gibs_fine((i+1)*(cols+1)+j).io.opinNE(k) := out
          gibs_fine((i+1)*(cols+1)+j+1).io.opinNW(k) := out
        }
      }
    }
  }
//  println(pePortCoarse.apply(6))
//  memPortCoarse.apply(1)



  // GIB to GIB connections.for coarse
  if(numTrackCoarse > 0) {
    for (i <- 0 to rows) {
      for (j <- 0 to cols) {
        if (i == 0) {
    
          gibs_coarse(j).io.itrackN.map(in => in := 0.U)
          gibs_coarse(j).io.itrackS.zipWithIndex.map { case (in, k) =>
            in := gibs_coarse(cols + 1 + j).io.otrackN(k)
          }
        } else if (i == rows) {
          gibs_coarse(i * (cols + 1) + j).io.itrackS.map { in => in := 0.U }
          gibs_coarse(i * (cols + 1) + j).io.itrackN.zipWithIndex.map { case (in, k) =>
            in := gibs_coarse((i - 1) * (cols + 1) + j).io.otrackS(k)
          }
        } else {
          gibs_coarse(i * (cols + 1) + j).io.itrackN.zipWithIndex.map { case (in, k) =>
            in := gibs_coarse((i - 1) * (cols + 1) + j).io.otrackS(k)
          }
          gibs_coarse(i * (cols + 1) + j).io.itrackS.zipWithIndex.map { case (in, k) =>
            in := gibs_coarse((i + 1) * (cols + 1) + j).io.otrackN(k)
          }
        }
        if (j == 0) {
          gibs_coarse(i * (cols + 1) + j).io.itrackW.map { in => in := 0.U }
          gibs_coarse(i * (cols + 1) + j).io.itrackE.zipWithIndex.map { case (in, k) =>
            in := gibs_coarse(i * (cols + 1) + j + 1).io.otrackW(k)
          }
        } else if (j == cols) {
          gibs_coarse(i * (cols + 1) + j).io.itrackE.map { in => in := 0.U }
          gibs_coarse(i * (cols + 1) + j).io.itrackW.zipWithIndex.map { case (in, k) =>
            in := gibs_coarse(i * (cols + 1) + j - 1).io.otrackE(k)
          }
        } else {
          gibs_coarse(i * (cols + 1) + j).io.itrackW.zipWithIndex.map { case (in, k) =>
            in := gibs_coarse(i * (cols + 1) + j - 1).io.otrackE(k)
          }
          gibs_coarse(i * (cols + 1) + j).io.itrackE.zipWithIndex.map { case (in, k) =>
            in := gibs_coarse(i * (cols + 1) + j + 1).io.otrackW(k)
          }
        }
      }
    }
  }

  // GIB to GIB connections, for fine
  if(numTrackFine > 0) {
    for (i <- 0 to rows) {
      for (j <- 0 to cols) {
        if (i == 0) {
        
          gibs_fine(j).io.itrackN.map(in => in := 0.U)
          gibs_fine(j).io.itrackS.zipWithIndex.map { case (in, k) =>
            in := gibs_fine(cols + 1 + j).io.otrackN(k)
          }
        } else if (i == rows) {
          gibs_fine(i * (cols + 1) + j).io.itrackS.map { in => in := 0.U }
          gibs_fine(i * (cols + 1) + j).io.itrackN.zipWithIndex.map { case (in, k) =>
            in := gibs_fine((i - 1) * (cols + 1) + j).io.otrackS(k)
          }
        } else {
          gibs_fine(i * (cols + 1) + j).io.itrackN.zipWithIndex.map { case (in, k) =>
            in := gibs_fine((i - 1) * (cols + 1) + j).io.otrackS(k)
          }
          gibs_fine(i * (cols + 1) + j).io.itrackS.zipWithIndex.map { case (in, k) =>
            in := gibs_fine((i + 1) * (cols + 1) + j).io.otrackN(k)
          }
        }
        if (j == 0) {
          gibs_fine(i * (cols + 1) + j).io.itrackW.map { in => in := 0.U }
          gibs_fine(i * (cols + 1) + j).io.itrackE.zipWithIndex.map { case (in, k) =>
            in := gibs_fine(i * (cols + 1) + j + 1).io.otrackW(k)
          }
        } else if (j == cols) {
          gibs_fine(i * (cols + 1) + j).io.itrackE.map { in => in := 0.U }
          gibs_fine(i * (cols + 1) + j).io.itrackW.zipWithIndex.map { case (in, k) =>
            in := gibs_fine(i * (cols + 1) + j - 1).io.otrackE(k)
          }
        } else {
          gibs_fine(i * (cols + 1) + j).io.itrackW.zipWithIndex.map { case (in, k) =>
            in := gibs_fine(i * (cols + 1) + j - 1).io.otrackE(k)
          }
          gibs_fine(i * (cols + 1) + j).io.itrackE.zipWithIndex.map { case (in, k) =>
            in := gibs_fine(i * (cols + 1) + j + 1).io.otrackW(k)
          }
        }
      }
    }
  }


  // Configurations, each column share one config bus
  var memNum2 = 0
  for(i <- 0 to rows){
    for(j <- 0 to cols){
      gibs_coarse(i*(cols+1)+j).io.cfg_en := (io.config_addr(2*j)(23,16) === 0.U) && io.config_write(2*j) && (gib_coordinate((i,j)).asUInt() === io.config_addr(2*j)(15,0))
      gibs_coarse(i*(cols+1)+j).io.cfg_addr := io.config_addr(2*j)(31,24)
      gibs_coarse(i*(cols+1)+j).io.cfg_data := io.config_data(2*j)

      gibs_fine(i*(cols+1)+j).io.cfg_en := (io.config_addr(2*j)(23,16) === 1.U) && io.config_write(2*j) && (gib_coordinate((i,j)).asUInt() === io.config_addr(2*j)(15,0))
      gibs_fine(i*(cols+1)+j).io.cfg_addr := io.config_addr(2*j)(31,24)
      gibs_fine(i*(cols+1)+j).io.cfg_data := io.config_data(2*j)
      if((i < rows) && (j < cols)){
        if ((j + 1) % 4 == 0){
          mems(memNum2).io.stall := io.stall(j)
          mems(memNum2).io.config_config_addr := io.config_addr(2*j+1)(31,24)
          mems(memNum2).io.config_config_data := io.config_data(2*j+1)
          mems(memNum2).io.config_read := io.config_read(j/4)
          mems(memNum2).io.config_write := (io.config_addr(2*j+1)(23,16) === 0.U) && (unit_coordinate((i,j)).asUInt() === io.config_addr(2*j+1)(15,0) && io.config_write(2*j+1))
//          mems(memNum2).config_config_addr_i.map{obj => obj := io.config_addr(2*j+1)(31,24)}
//          mems(memNum2).config_config_data_i.map{obj => obj := io.config_data(2*j+1)}
//          mems(memNum2).config_read_i.map{obj => obj := io.config_read(j)}
          mems(memNum2).io.config_write_i.zipWithIndex.map{ case (obj, index) =>
            obj := (io.config_addr(2*j+1)(23,16) === (index+1).U) && (unit_coordinate((i,j)).asUInt() === io.config_addr(2*j+1)(15,0) && io.config_write(2*j+1))
          }
//         2 config_en, attach to 1 and 2
          mems(memNum2).io.config_en.zipWithIndex.map{ case (en,k) => en := (io.config_addr(2*j+1)(23,16) === (k+1).U)}
          memNum2 += 1
        }else{
          pes(i*cols+j-memNum2).io.config_write := (io.config_write(2*j+1) && (unit_coordinate((i,j)).asUInt() === io.config_addr(2*j+1)(15,0)) && (io.config_addr(2*j+1)(23,16) === 0.U))
          pes(i*cols+j-memNum2).io.config_addr := io.config_addr(2*j+1)(31,24)
          pes(i*cols+j-memNum2).io.config_data := io.config_data(2*j+1)
//          pes(i*cols+j-memNum2).io.config_read := io.config_read(j)
          pes(i*cols+j-memNum2).io.stall := io.stall(j)
        }
      }
    }
  }

  //read_cfg_data connection
  read_cfg_data_muxs.zipWithIndex.map{case(mux,i) =>
    mux.io.in.zipWithIndex.map{case (ins,j) => ins := mems(i*(cols/4)+j).io.read_config_data(0)}
    mux.io.config := io.read_config_data_sel(i)
  }
  io.read_config_data.zipWithIndex.map{case (io_readcfg,i) => io_readcfg := read_cfg_data_muxs(i).io.out}
  read_cfg_data_muxs_1.zipWithIndex.map{case(mux,i) =>
    mux.io.in.zipWithIndex.map{case (ins,j) => ins := mems(i*(cols/4)+j).io.read_config_data(1)}
    mux.io.config := io.read_config_data_sel_1(i)
  }
  io.read_config_data_1.zipWithIndex.map{case (io_readcfg,i) => io_readcfg := read_cfg_data_muxs_1(i).io.out}
  read_cfg_data_muxs_2.zipWithIndex.map{case(mux,i) =>
    mux.io.in.zipWithIndex.map{case (ins,j) => ins := mems(i*(cols/4)+j).io.read_config_data(2)}
    mux.io.config := io.read_config_data_sel_2(i)
  }
  io.read_config_data_2.zipWithIndex.map{case (io_readcfg,i) => io_readcfg := read_cfg_data_muxs_2(i).io.out}

  if(dumpIR){

    val conIfoMap = mutable.Map[Any, ListBuffer[Seq[Int]]]()
    val conIfoIndexMap = mutable.Map[Any,Int]()
    val GIBconIfo = mutable.Map[Any,Any]()
    val GIBmuxWithcfg = mutable.Map[String,Any]()

    gibs_coarse.zipWithIndex.map{ case (gib,i) =>
      conIfoMap += (gib.numIOPinMap -> gib.connect_ifo)
      GIBconIfo += ((i%(cols+1)*2,i/(cols+1)*2+1)-> gib.numIOPinMap)
      GIBmuxWithcfg += ((gib.x,gib.y,dataWidth).toString() -> gib.GIBconnectIfo)
    }
    conIfoMap.keys.zipWithIndex.map{case (key,i) =>
      conIfoIndexMap += (key -> i)
    }
    //  println(conIfoMap)
    //  println(conIfoIndexMap)
    //  println(GIBconIfo)

    val conIfoMap_fine = mutable.Map[Any, ListBuffer[Seq[Int]]]()
    val conIfoIndexMap_fine = mutable.Map[Any,Int]()
    val GIBconIfo_fine = mutable.Map[Any,Any]()
    val GIBmuxWithcfg_fine = mutable.Map[String,Any]()

    gibs_fine.zipWithIndex.map{ case (gib,i) =>
      conIfoMap_fine += (gib.numIOPinMap -> gib.connect_ifo)
      GIBconIfo_fine += ((i%(cols+1)*2,i/(cols+1)*2+1)-> gib.numIOPinMap)
      GIBmuxWithcfg_fine += ((gib.x,gib.y,1).toString() -> gib.GIBconnectIfo)
    }
    conIfoMap_fine.keys.zipWithIndex.map{case (key,i) =>
      conIfoIndexMap_fine += (key -> i)
    }
    //  println(GIBmuxWithcfg_fine)

    //    val outFilename = "src/main/resources/cgra_adg.json"
//    printIR(outFilename)
    val outgraph16 = "src/main/resources/16bit.graph"
    IRHandler.dumpGraph(conIfoMap,conIfoIndexMap,GIBconIfo, dataWidth,numTrackCoarse,numTrackFine,outgraph16,rows,cols,pePortCoarse,memPortCoarse,pes(0).io.out_coarse.size,mems(0).io.out_coarse.size,pes(0).io.in_coarse.size/4, mems(0).io.in_coarse.size/4)
    val outgraph1 = "src/main/resources/1bit.graph"
    IRHandler.dumpGraph(conIfoMap_fine,conIfoIndexMap_fine,GIBconIfo_fine, 1,numTrackCoarse,numTrackFine,outgraph1,rows,cols,pePortFine,memPortFine,pes(0).io.out_fine.size,mems(0).io.out_fine.size,pes(0).io.in_fine.size/4,mems(0).io.in_fine.size/4)
    val layout = "src/main/resources/design.layout"
    IRHandler.layoutGen(cols,rows,layout)

    //generate cfg ifo
    IRHandler.dumpIR(GIBmuxWithcfg,"src/main/resources/GIB16.json")
    IRHandler.dumpIR(GIBmuxWithcfg_fine,"src/main/resources/GIB1.json")
  }
}
