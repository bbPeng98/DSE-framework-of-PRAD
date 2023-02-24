import scala.io.Source
import java.io._
import java.math.BigInteger
import scala.math.BigInt
import chisel3._
import chisel3.util._
import scala.collection.mutable
import scala.collection.mutable.{ArrayBuffer, ListBuffer}
import chisel3.iotesters.{PeekPokeTester, Driver, ChiselFlatSpec}
import PRAD.template._

class CGRATest(c: CGRA, cfgFilename: String, inputFilename: String, outputFilename: String) extends PeekPokeTester(c) {
  val pw = new PrintWriter(new File(outputFilename))
  c.io.config_write.map(cfg_write => poke(cfg_write, 1))
  c.io.config_read.map(cfg_read => poke(cfg_read, 1))
  poke(c.io.stall, 1)
  Source.fromFile(cfgFilename).getLines().foreach{
    line => {
      val items = line.split(" ")
      val addr = Integer.parseInt(items(0), 16);
      val data = BigInt(new BigInteger(items(1), 16));
      c.io.config_addr.map(cfg_addr => poke(cfg_addr, addr))
      c.io.config_data.map(cfg_data => poke(cfg_data, data))
//      poke(c.io.cfg_addr, addr)
//      poke(c.io.cfg_data, data)
      step(1)
    }
  }
  step(10)
  poke(c.io.stall, 0)
  Source.fromFile(inputFilename).getLines().foreach{
    line => {
      val input_line = Integer.parseInt(line, 2);
      poke(c.io.glb2io_16(3), input_line)
      step(1)
      pw.write(peek(c.io.io2glb_16(2)).toString())
      println("output0: " + peek(c.io.io2glb_16(0)).toString())
      println("output1: " + peek(c.io.io2glb_16(1)).toString())
      println("output2: " + peek(c.io.io2glb_16(2)).toString())
      println("output3: " + peek(c.io.io2glb_16(3)).toString())
      println("output4: " + peek(c.io.io2glb_16(4)).toString())
      println("output5: " + peek(c.io.io2glb_16(5)).toString())
      println("output6: " + peek(c.io.io2glb_16(6)).toString())
    }
  }
  (0 until 100).map { i =>
    step(1)
    println("output0: " + peek(c.io.io2glb_16(0)).toString())
    println("output1: " + peek(c.io.io2glb_16(1)).toString())
    println("output2: " + peek(c.io.io2glb_16(2)).toString())
    println("output3: " + peek(c.io.io2glb_16(3)).toString())
    println("output4: " + peek(c.io.io2glb_16(4)).toString())
    println("output5: " + peek(c.io.io2glb_16(5)).toString())
    println("output6: " + peek(c.io.io2glb_16(6)).toString())
    pw.write(peek(c.io.io2glb_16(2)).toString())
  }
  pw.close

  //  poke(c.io.glb2io_1(0), 1)
//  for( i <- 1 until 20){
//    poke(c.io.glb2io_16(0), 0)
//    //    poke(c.io.in(0), (2*i+1))
//    step(1)
////    println(peek(c.io.out(1)).toString())
//  }
//  println(peek(c.io.io2glb_16(0)).toString() + ", " + peek(c.io.io2glb_16(7)).toString())
}


object CGRATester extends App {
  val connect_flexibility = mutable.Map(
    "num_itrack_per_ipin" -> 4, // ipin number = 3
    "num_otrack_per_opin" -> 4, // opin number = 1
    "num_ipin_per_opin"   -> 6
  )
  val attrs: mutable.Map[String, Any] = mutable.Map(
    "num_row" -> 5,
    "num_colum" -> 16,
    "data_width" -> 16,
    "cfg_data_width" -> 32,
    "cfg_addr_width" -> 32,
    "cfg_addr_width_Unit" -> 8,
    "cfg_blk_offset" -> 3,
    "PEinputnum" -> (2,3),
    "functionSelect" -> 1,
    "interconnect_output_ports" -> 2,
    "mem_width" -> 64,
    "mem_depth" -> 512,
    "use_sram_stub" -> 0,
    "target" -> (0 until 100).toList,
    "iterator_support" -> 6,
    "config_width" -> 16,
    "interconnect_input_ports" -> 2,
    "agg_addr_width" -> 4,
    "agg_iter_support" -> 6,
    "agg_range_width" -> 16,
    "tb_range_width" -> 16,
    "tb_addr_width" -> 4,
    "banks" -> 1,
    "tb_height" -> 2,
    "agg_height" -> 4,
    "agg_rd_addr_gen_width" -> 8,
    "num_track" -> 5,
    "track_reged_mode" -> 2,
    "connect_flexibility" -> connect_flexibility,
    "diag_iopin_connect" -> true
  )
  // val dut = new CGRA(attrs)
  iotesters.Driver.execute(args, () => new CGRA(attrs, false)) {
    c => new CGRATest(c, "../benchmarks/test/counter/counter.bs", "../benchmarks/test/counter/regression_input_counter.txt", "../benchmarks/test/counter/CGRA_output.txt")
  }

}


