#include "app.h"
#include "ubuffer.h"
#include "codegen.h"
#include "prog.h"

prog camera_pipeline() {
  prog prg;
  prg.compute_unit_file = "camera_pipeline_compute.h";
  prg.name = "camera_pipeline";

// Stencil<uint16_t, 64, 64> &hw_input_stencil = arg_0;
  prg.add_input("hw_input_stencil");
  prg.buffer_port_widths["hw_input_stencil"] = 16;
// Stencil<uint16_t, 3, 56, 56> &hw_output_stencil = arg_1;
  prg.add_output("hw_output_stencil");
  prg.buffer_port_widths["hw_output_stencil"] = 16;

////producing hw_input_global_wrapper.stencil
  auto hw_input_global_wrapper_s0_y = prg.add_loop("hw_input_global_wrapper_s0_y", -4, 60);
  auto hw_input_global_wrapper_s0_x = hw_input_global_wrapper_s0_y->add_loop("hw_input_global_wrapper_s0_x", -4, 60);

//store is: hw_input_global_wrapper.stencil((hw_input_global_wrapper_s0_x + 4), (hw_input_global_wrapper_s0_y + 4)) = hw_input.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y)
  auto hcompute_hw_input_global_wrapper_stencil = hw_input_global_wrapper_s0_x->add_op("op_hcompute_hw_input_global_wrapper_stencil");
  hcompute_hw_input_global_wrapper_stencil->add_function("hcompute_hw_input_global_wrapper_stencil");
  hcompute_hw_input_global_wrapper_stencil->add_load("hw_input_stencil", "hw_input_global_wrapper_s0_y", "hw_input_global_wrapper_s0_x");
  prg.buffer_port_widths["hw_input_global_wrapper_stencil"] = 16;
  hcompute_hw_input_global_wrapper_stencil->add_store("hw_input_global_wrapper_stencil", "(hw_input_global_wrapper_s0_y + 4)", "(hw_input_global_wrapper_s0_x + 4)");

//consuming hw_input_global_wrapper.stencil
////producing denoised$1.stencil
  auto denoised_1_s0_y = prg.add_loop("denoised_1_s0_y", -2, 58);
  auto denoised_1_s0_x = denoised_1_s0_y->add_loop("denoised_1_s0_x", -2, 58);

//store is: denoised$1.stencil((denoised_1_s0_x + 2), (denoised_1_s0_y + 2)) = min(hw_input_global_wrapper.stencil((denoised_1_s0_x + 4), (denoised_1_s0_y + 4)), max(hw_input_global_wrapper.stencil((denoised_1_s0_x + 4), (denoised_1_s0_y + 6)), max(hw_input_global_wrapper.stencil((denoised_1_s0_x + 4), (denoised_1_s0_y + 2)), max(hw_input_global_wrapper.stencil((denoised_1_s0_x + 2), (denoised_1_s0_y + 4)), hw_input_global_wrapper.stencil((denoised_1_s0_x + 6), (denoised_1_s0_y + 4))))))
  auto hcompute_denoised_1_stencil = denoised_1_s0_x->add_op("op_hcompute_denoised_1_stencil");
  hcompute_denoised_1_stencil->add_function("hcompute_denoised_1_stencil");
  hcompute_denoised_1_stencil->add_load("hw_input_global_wrapper_stencil", "(denoised_1_s0_y + 4)", "(denoised_1_s0_x + 4)");
  hcompute_denoised_1_stencil->add_load("hw_input_global_wrapper_stencil", "(denoised_1_s0_y + 6)", "(denoised_1_s0_x + 4)");
  hcompute_denoised_1_stencil->add_load("hw_input_global_wrapper_stencil", "(denoised_1_s0_y + 2)", "(denoised_1_s0_x + 4)");
  hcompute_denoised_1_stencil->add_load("hw_input_global_wrapper_stencil", "(denoised_1_s0_y + 4)", "(denoised_1_s0_x + 2)");
  hcompute_denoised_1_stencil->add_load("hw_input_global_wrapper_stencil", "(denoised_1_s0_y + 4)", "(denoised_1_s0_x + 6)");
  prg.buffer_port_widths["denoised_1_stencil"] = 16;
  hcompute_denoised_1_stencil->add_store("denoised_1_stencil", "(denoised_1_s0_y + 2)", "(denoised_1_s0_x + 2)");

//consuming denoised$1.stencil
////producing b_b.stencil
  auto b_b_s0_y = prg.add_loop("b_b_s0_y", -1, 28);
  auto b_b_s0_x = b_b_s0_y->add_loop("b_b_s0_x", 0, 29);

//store is: b_b.stencil(b_b_s0_x, (b_b_s0_y + 1)) = denoised$1.stencil(((b_b_s0_x*2) + 2), ((b_b_s0_y*2) + 3))
  auto hcompute_b_b_stencil = b_b_s0_x->add_op("op_hcompute_b_b_stencil");
  hcompute_b_b_stencil->add_function("hcompute_b_b_stencil");
  hcompute_b_b_stencil->add_load("denoised_1_stencil", "((b_b_s0_y*2) + 3)", "((b_b_s0_x*2) + 2)");
  prg.buffer_port_widths["b_b_stencil"] = 16;
  hcompute_b_b_stencil->add_store("b_b_stencil", "(b_b_s0_y + 1)", "b_b_s0_x");

//consuming b_b.stencil
////producing g_gb.stencil
  auto g_gb_s0_y = prg.add_loop("g_gb_s0_y", -1, 29);
  auto g_gb_s0_x = g_gb_s0_y->add_loop("g_gb_s0_x", -1, 29);

//store is: g_gb.stencil((g_gb_s0_x + 1), (g_gb_s0_y + 1)) = denoised$1.stencil(((g_gb_s0_x*2) + 3), ((g_gb_s0_y*2) + 3))
  auto hcompute_g_gb_stencil = g_gb_s0_x->add_op("op_hcompute_g_gb_stencil");
  hcompute_g_gb_stencil->add_function("hcompute_g_gb_stencil");
  hcompute_g_gb_stencil->add_load("denoised_1_stencil", "((g_gb_s0_y*2) + 3)", "((g_gb_s0_x*2) + 3)");
  prg.buffer_port_widths["g_gb_stencil"] = 16;
  hcompute_g_gb_stencil->add_store("g_gb_stencil", "(g_gb_s0_y + 1)", "(g_gb_s0_x + 1)");

//consuming g_gb.stencil
////producing g_gr.stencil
  auto g_gr_s0_y = prg.add_loop("g_gr_s0_y", -1, 29);
  auto g_gr_s0_x = g_gr_s0_y->add_loop("g_gr_s0_x", -1, 29);

//store is: g_gr.stencil((g_gr_s0_x + 1), (g_gr_s0_y + 1)) = denoised$1.stencil(((g_gr_s0_x*2) + 2), ((g_gr_s0_y*2) + 2))
  auto hcompute_g_gr_stencil = g_gr_s0_x->add_op("op_hcompute_g_gr_stencil");
  hcompute_g_gr_stencil->add_function("hcompute_g_gr_stencil");
  hcompute_g_gr_stencil->add_load("denoised_1_stencil", "((g_gr_s0_y*2) + 2)", "((g_gr_s0_x*2) + 2)");
  prg.buffer_port_widths["g_gr_stencil"] = 16;
  hcompute_g_gr_stencil->add_store("g_gr_stencil", "(g_gr_s0_y + 1)", "(g_gr_s0_x + 1)");

//consuming g_gr.stencil
////producing r_r.stencil
  auto r_r_s0_y = prg.add_loop("r_r_s0_y", 0, 29);
  auto r_r_s0_x = r_r_s0_y->add_loop("r_r_s0_x", -1, 28);

//store is: r_r.stencil((r_r_s0_x + 1), r_r_s0_y) = denoised$1.stencil(((r_r_s0_x*2) + 3), ((r_r_s0_y*2) + 2))
  auto hcompute_r_r_stencil = r_r_s0_x->add_op("op_hcompute_r_r_stencil");
  hcompute_r_r_stencil->add_function("hcompute_r_r_stencil");
  hcompute_r_r_stencil->add_load("denoised_1_stencil", "((r_r_s0_y*2) + 2)", "((r_r_s0_x*2) + 3)");
  prg.buffer_port_widths["r_r_stencil"] = 16;
  hcompute_r_r_stencil->add_store("r_r_stencil", "r_r_s0_y", "(r_r_s0_x + 1)");

//consuming r_r.stencil
////producing demosaicked$1.stencil
  auto demosaicked_1_s0_y = prg.add_loop("demosaicked_1_s0_y", 0, 56);
  auto demosaicked_1_s0_x = demosaicked_1_s0_y->add_loop("demosaicked_1_s0_x", 0, 56);

//store is: demosaicked$1.stencil(demosaicked_1_s0_x, demosaicked_1_s0_y, 0) = select(((demosaicked_1_s0_y % 2) == 0), select(((demosaicked_1_s0_x % 2) == 0), ((g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)) + ((r_r.stencil(((demosaicked_1_s0_x/2) + 1), (demosaicked_1_s0_y/2)) + r_r.stencil((demosaicked_1_s0_x/2), (demosaicked_1_s0_y/2)))/(uint16)2)) - ((select((absd(g_gr.stencil(((demosaicked_1_s0_x/2) + 2), ((demosaicked_1_s0_y/2) + 1)), g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1))) < absd(g_gb.stencil(((demosaicked_1_s0_x/2) + 1), (demosaicked_1_s0_y/2)), g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)))), ((g_gr.stencil(((demosaicked_1_s0_x/2) + 2), ((demosaicked_1_s0_y/2) + 1)) + g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)))/(uint16)2), ((g_gb.stencil(((demosaicked_1_s0_x/2) + 1), (demosaicked_1_s0_y/2)) + g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)))/(uint16)2)) + select((absd(g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)), g_gr.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 1))) < absd(g_gb.stencil((demosaicked_1_s0_x/2), (demosaicked_1_s0_y/2)), g_gb.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 1)))), ((g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)) + g_gr.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 1)))/(uint16)2), ((g_gb.stencil((demosaicked_1_s0_x/2), (demosaicked_1_s0_y/2)) + g_gb.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 1)))/(uint16)2)))/(uint16)2)), r_r.stencil(((demosaicked_1_s0_x/2) + 1), (demosaicked_1_s0_y/2))), select(((demosaicked_1_s0_x % 2) == 0), select((absd(r_r.stencil(((demosaicked_1_s0_x/2) + 1), (demosaicked_1_s0_y/2)), r_r.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 1))) < absd(r_r.stencil((demosaicked_1_s0_x/2), (demosaicked_1_s0_y/2)), r_r.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)))), ((select((absd(g_gb.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 1)), g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1))) < absd(g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 2)), g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)))), ((g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)) + g_gb.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 1)))/(uint16)2), ((g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)) + g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 2)))/(uint16)2)) + ((r_r.stencil(((demosaicked_1_s0_x/2) + 1), (demosaicked_1_s0_y/2)) + r_r.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 1)))/(uint16)2)) - ((select((absd(g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 2)), g_gr.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 2))) < absd(g_gb.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 1)), g_gb.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 2)))), ((g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 2)) + g_gr.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 2)))/(uint16)2), ((g_gb.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 1)) + g_gb.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 2)))/(uint16)2)) + select((absd(g_gr.stencil(((demosaicked_1_s0_x/2) + 2), ((demosaicked_1_s0_y/2) + 1)), g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1))) < absd(g_gb.stencil(((demosaicked_1_s0_x/2) + 1), (demosaicked_1_s0_y/2)), g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)))), ((g_gr.stencil(((demosaicked_1_s0_x/2) + 2), ((demosaicked_1_s0_y/2) + 1)) + g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)))/(uint16)2), ((g_gb.stencil(((demosaicked_1_s0_x/2) + 1), (demosaicked_1_s0_y/2)) + g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)))/(uint16)2)))/(uint16)2)), ((select((absd(g_gb.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 1)), g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1))) < absd(g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 2)), g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)))), ((g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)) + g_gb.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 1)))/(uint16)2), ((g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)) + g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 2)))/(uint16)2)) + ((r_r.stencil((demosaicked_1_s0_x/2), (demosaicked_1_s0_y/2)) + r_r.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)))/(uint16)2)) - ((select((absd(g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)), g_gr.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 1))) < absd(g_gb.stencil((demosaicked_1_s0_x/2), (demosaicked_1_s0_y/2)), g_gb.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 1)))), ((g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)) + g_gr.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 1)))/(uint16)2), ((g_gb.stencil((demosaicked_1_s0_x/2), (demosaicked_1_s0_y/2)) + g_gb.stencil((demosaicked_1_s0_x/2), ((demosaicked_1_s0_y/2) + 1)))/(uint16)2)) + select((absd(g_gr.stencil(((demosaicked_1_s0_x/2) + 2), ((demosaicked_1_s0_y/2) + 2)), g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 2))) < absd(g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)), g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 2)))), ((g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 2)) + g_gr.stencil(((demosaicked_1_s0_x/2) + 2), ((demosaicked_1_s0_y/2) + 2)))/(uint16)2), ((g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)) + g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 2)))/(uint16)2)))/(uint16)2))), ((g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)) + ((r_r.stencil(((demosaicked_1_s0_x/2) + 1), (demosaicked_1_s0_y/2)) + r_r.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)))/(uint16)2)) - ((select((absd(g_gr.stencil(((demosaicked_1_s0_x/2) + 2), ((demosaicked_1_s0_y/2) + 1)), g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1))) < absd(g_gb.stencil(((demosaicked_1_s0_x/2) + 1), (demosaicked_1_s0_y/2)), g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)))), ((g_gr.stencil(((demosaicked_1_s0_x/2) + 2), ((demosaicked_1_s0_y/2) + 1)) + g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)))/(uint16)2), ((g_gb.stencil(((demosaicked_1_s0_x/2) + 1), (demosaicked_1_s0_y/2)) + g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)))/(uint16)2)) + select((absd(g_gr.stencil(((demosaicked_1_s0_x/2) + 2), ((demosaicked_1_s0_y/2) + 2)), g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 2))) < absd(g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)), g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 2)))), ((g_gr.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 2)) + g_gr.stencil(((demosaicked_1_s0_x/2) + 2), ((demosaicked_1_s0_y/2) + 2)))/(uint16)2), ((g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 1)) + g_gb.stencil(((demosaicked_1_s0_x/2) + 1), ((demosaicked_1_s0_y/2) + 2)))/(uint16)2)))/(uint16)2))))
  auto hcompute_demosaicked_1_stencil = demosaicked_1_s0_x->add_op("op_hcompute_demosaicked_1_stencil");
  hcompute_demosaicked_1_stencil->add_function("hcompute_demosaicked_1_stencil");
  hcompute_demosaicked_1_stencil->add_load("g_gb_stencil", "floor((demosaicked_1_s0_y/2))", "(floor((demosaicked_1_s0_x/2)) + 1)");
  hcompute_demosaicked_1_stencil->add_load("g_gb_stencil", "(floor((demosaicked_1_s0_y/2)) + 1)", "(floor((demosaicked_1_s0_x/2)) + 1)");
  hcompute_demosaicked_1_stencil->add_load("g_gb_stencil", "floor((demosaicked_1_s0_y/2))", "floor((demosaicked_1_s0_x/2))");
  hcompute_demosaicked_1_stencil->add_load("g_gb_stencil", "(floor((demosaicked_1_s0_y/2)) + 1)", "floor((demosaicked_1_s0_x/2))");
  hcompute_demosaicked_1_stencil->add_load("g_gb_stencil", "(floor((demosaicked_1_s0_y/2)) + 2)", "floor((demosaicked_1_s0_x/2))");
  hcompute_demosaicked_1_stencil->add_load("g_gb_stencil", "(floor((demosaicked_1_s0_y/2)) + 2)", "(floor((demosaicked_1_s0_x/2)) + 1)");
  hcompute_demosaicked_1_stencil->add_load("g_gr_stencil", "(floor((demosaicked_1_s0_y/2)) + 1)", "(floor((demosaicked_1_s0_x/2)) + 1)");
  hcompute_demosaicked_1_stencil->add_load("g_gr_stencil", "(floor((demosaicked_1_s0_y/2)) + 1)", "(floor((demosaicked_1_s0_x/2)) + 2)");
  hcompute_demosaicked_1_stencil->add_load("g_gr_stencil", "(floor((demosaicked_1_s0_y/2)) + 1)", "floor((demosaicked_1_s0_x/2))");
  hcompute_demosaicked_1_stencil->add_load("g_gr_stencil", "(floor((demosaicked_1_s0_y/2)) + 2)", "(floor((demosaicked_1_s0_x/2)) + 1)");
  hcompute_demosaicked_1_stencil->add_load("g_gr_stencil", "(floor((demosaicked_1_s0_y/2)) + 2)", "floor((demosaicked_1_s0_x/2))");
  hcompute_demosaicked_1_stencil->add_load("g_gr_stencil", "(floor((demosaicked_1_s0_y/2)) + 2)", "(floor((demosaicked_1_s0_x/2)) + 2)");
  hcompute_demosaicked_1_stencil->add_load("r_r_stencil", "floor((demosaicked_1_s0_y/2))", "(floor((demosaicked_1_s0_x/2)) + 1)");
  hcompute_demosaicked_1_stencil->add_load("r_r_stencil", "floor((demosaicked_1_s0_y/2))", "floor((demosaicked_1_s0_x/2))");
  hcompute_demosaicked_1_stencil->add_load("r_r_stencil", "(floor((demosaicked_1_s0_y/2)) + 1)", "floor((demosaicked_1_s0_x/2))");
  hcompute_demosaicked_1_stencil->add_load("r_r_stencil", "(floor((demosaicked_1_s0_y/2)) + 1)", "(floor((demosaicked_1_s0_x/2)) + 1)");
  prg.buffer_port_widths["demosaicked_1_stencil"] = 16;
  hcompute_demosaicked_1_stencil->add_store("demosaicked_1_stencil", "0", "demosaicked_1_s0_y", "demosaicked_1_s0_x");
  hcompute_demosaicked_1_stencil->compute_unit_needs_index_variable("demosaicked_1_s0_x");
  hcompute_demosaicked_1_stencil->compute_unit_needs_index_variable("demosaicked_1_s0_y");
  auto demosaicked_1_s0_y_1 = prg.add_loop("demosaicked_1_s0_y_1", 0, 56);
  auto demosaicked_1_s0_x_1 = demosaicked_1_s0_y_1->add_loop("demosaicked_1_s0_x_1", 0, 56);

//store is: demosaicked$1.stencil(demosaicked_1_s0_x_1, demosaicked_1_s0_y_1, 1) = select(((demosaicked_1_s0_y_1 % 2) == 0), select(((demosaicked_1_s0_x_1 % 2) == 0), g_gr.stencil(((demosaicked_1_s0_x_1/2) + 1), ((demosaicked_1_s0_y_1/2) + 1)), select((absd(g_gr.stencil(((demosaicked_1_s0_x_1/2) + 2), ((demosaicked_1_s0_y_1/2) + 1)), g_gr.stencil(((demosaicked_1_s0_x_1/2) + 1), ((demosaicked_1_s0_y_1/2) + 1))) < absd(g_gb.stencil(((demosaicked_1_s0_x_1/2) + 1), (demosaicked_1_s0_y_1/2)), g_gb.stencil(((demosaicked_1_s0_x_1/2) + 1), ((demosaicked_1_s0_y_1/2) + 1)))), ((g_gr.stencil(((demosaicked_1_s0_x_1/2) + 2), ((demosaicked_1_s0_y_1/2) + 1)) + g_gr.stencil(((demosaicked_1_s0_x_1/2) + 1), ((demosaicked_1_s0_y_1/2) + 1)))/(uint16)2), ((g_gb.stencil(((demosaicked_1_s0_x_1/2) + 1), (demosaicked_1_s0_y_1/2)) + g_gb.stencil(((demosaicked_1_s0_x_1/2) + 1), ((demosaicked_1_s0_y_1/2) + 1)))/(uint16)2))), select(((demosaicked_1_s0_x_1 % 2) == 0), select((absd(g_gb.stencil((demosaicked_1_s0_x_1/2), ((demosaicked_1_s0_y_1/2) + 1)), g_gb.stencil(((demosaicked_1_s0_x_1/2) + 1), ((demosaicked_1_s0_y_1/2) + 1))) < absd(g_gr.stencil(((demosaicked_1_s0_x_1/2) + 1), ((demosaicked_1_s0_y_1/2) + 2)), g_gr.stencil(((demosaicked_1_s0_x_1/2) + 1), ((demosaicked_1_s0_y_1/2) + 1)))), ((g_gb.stencil(((demosaicked_1_s0_x_1/2) + 1), ((demosaicked_1_s0_y_1/2) + 1)) + g_gb.stencil((demosaicked_1_s0_x_1/2), ((demosaicked_1_s0_y_1/2) + 1)))/(uint16)2), ((g_gr.stencil(((demosaicked_1_s0_x_1/2) + 1), ((demosaicked_1_s0_y_1/2) + 1)) + g_gr.stencil(((demosaicked_1_s0_x_1/2) + 1), ((demosaicked_1_s0_y_1/2) + 2)))/(uint16)2)), g_gb.stencil(((demosaicked_1_s0_x_1/2) + 1), ((demosaicked_1_s0_y_1/2) + 1))))
  auto hcompute_demosaicked_1_stencil_1 = demosaicked_1_s0_x_1->add_op("op_hcompute_demosaicked_1_stencil_1");
  hcompute_demosaicked_1_stencil_1->add_function("hcompute_demosaicked_1_stencil_1");
  hcompute_demosaicked_1_stencil_1->add_load("g_gb_stencil", "floor((demosaicked_1_s0_y_1/2))", "(floor((demosaicked_1_s0_x_1/2)) + 1)");
  hcompute_demosaicked_1_stencil_1->add_load("g_gb_stencil", "(floor((demosaicked_1_s0_y_1/2)) + 1)", "(floor((demosaicked_1_s0_x_1/2)) + 1)");
  hcompute_demosaicked_1_stencil_1->add_load("g_gb_stencil", "(floor((demosaicked_1_s0_y_1/2)) + 1)", "floor((demosaicked_1_s0_x_1/2))");
  hcompute_demosaicked_1_stencil_1->add_load("g_gr_stencil", "(floor((demosaicked_1_s0_y_1/2)) + 1)", "(floor((demosaicked_1_s0_x_1/2)) + 1)");
  hcompute_demosaicked_1_stencil_1->add_load("g_gr_stencil", "(floor((demosaicked_1_s0_y_1/2)) + 1)", "(floor((demosaicked_1_s0_x_1/2)) + 2)");
  hcompute_demosaicked_1_stencil_1->add_load("g_gr_stencil", "(floor((demosaicked_1_s0_y_1/2)) + 2)", "(floor((demosaicked_1_s0_x_1/2)) + 1)");
  hcompute_demosaicked_1_stencil_1->add_store("demosaicked_1_stencil", "1", "demosaicked_1_s0_y_1", "demosaicked_1_s0_x_1");
  hcompute_demosaicked_1_stencil_1->compute_unit_needs_index_variable("demosaicked_1_s0_x_1");
  hcompute_demosaicked_1_stencil_1->compute_unit_needs_index_variable("demosaicked_1_s0_y_1");
  auto demosaicked_1_s0_y_2 = prg.add_loop("demosaicked_1_s0_y_2", 0, 56);
  auto demosaicked_1_s0_x_2 = demosaicked_1_s0_y_2->add_loop("demosaicked_1_s0_x_2", 0, 56);

//store is: demosaicked$1.stencil(demosaicked_1_s0_x_2, demosaicked_1_s0_y_2, 2) = select(((demosaicked_1_s0_y_2 % 2) == 0), select(((demosaicked_1_s0_x_2 % 2) == 0), ((g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)) + ((b_b.stencil((demosaicked_1_s0_x_2/2), ((demosaicked_1_s0_y_2/2) + 1)) + b_b.stencil((demosaicked_1_s0_x_2/2), (demosaicked_1_s0_y_2/2)))/(uint16)2)) - ((select((absd(g_gb.stencil((demosaicked_1_s0_x_2/2), ((demosaicked_1_s0_y_2/2) + 1)), g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1))) < absd(g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 2)), g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)))), ((g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)) + g_gb.stencil((demosaicked_1_s0_x_2/2), ((demosaicked_1_s0_y_2/2) + 1)))/(uint16)2), ((g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)) + g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 2)))/(uint16)2)) + select((absd(g_gb.stencil((demosaicked_1_s0_x_2/2), (demosaicked_1_s0_y_2/2)), g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), (demosaicked_1_s0_y_2/2))) < absd(g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)), g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), (demosaicked_1_s0_y_2/2)))), ((g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), (demosaicked_1_s0_y_2/2)) + g_gb.stencil((demosaicked_1_s0_x_2/2), (demosaicked_1_s0_y_2/2)))/(uint16)2), ((g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)) + g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), (demosaicked_1_s0_y_2/2)))/(uint16)2)))/(uint16)2)), select((absd(b_b.stencil((demosaicked_1_s0_x_2/2), ((demosaicked_1_s0_y_2/2) + 1)), b_b.stencil(((demosaicked_1_s0_x_2/2) + 1), (demosaicked_1_s0_y_2/2))) < absd(b_b.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)), b_b.stencil((demosaicked_1_s0_x_2/2), (demosaicked_1_s0_y_2/2)))), ((select((absd(g_gr.stencil(((demosaicked_1_s0_x_2/2) + 2), ((demosaicked_1_s0_y_2/2) + 1)), g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1))) < absd(g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), (demosaicked_1_s0_y_2/2)), g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)))), ((g_gr.stencil(((demosaicked_1_s0_x_2/2) + 2), ((demosaicked_1_s0_y_2/2) + 1)) + g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)))/(uint16)2), ((g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), (demosaicked_1_s0_y_2/2)) + g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)))/(uint16)2)) + ((b_b.stencil((demosaicked_1_s0_x_2/2), ((demosaicked_1_s0_y_2/2) + 1)) + b_b.stencil(((demosaicked_1_s0_x_2/2) + 1), (demosaicked_1_s0_y_2/2)))/(uint16)2)) - ((select((absd(g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), (demosaicked_1_s0_y_2/2)), g_gb.stencil(((demosaicked_1_s0_x_2/2) + 2), (demosaicked_1_s0_y_2/2))) < absd(g_gr.stencil(((demosaicked_1_s0_x_2/2) + 2), ((demosaicked_1_s0_y_2/2) + 1)), g_gr.stencil(((demosaicked_1_s0_x_2/2) + 2), (demosaicked_1_s0_y_2/2)))), ((g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), (demosaicked_1_s0_y_2/2)) + g_gb.stencil(((demosaicked_1_s0_x_2/2) + 2), (demosaicked_1_s0_y_2/2)))/(uint16)2), ((g_gr.stencil(((demosaicked_1_s0_x_2/2) + 2), ((demosaicked_1_s0_y_2/2) + 1)) + g_gr.stencil(((demosaicked_1_s0_x_2/2) + 2), (demosaicked_1_s0_y_2/2)))/(uint16)2)) + select((absd(g_gb.stencil((demosaicked_1_s0_x_2/2), ((demosaicked_1_s0_y_2/2) + 1)), g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1))) < absd(g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 2)), g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)))), ((g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)) + g_gb.stencil((demosaicked_1_s0_x_2/2), ((demosaicked_1_s0_y_2/2) + 1)))/(uint16)2), ((g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)) + g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 2)))/(uint16)2)))/(uint16)2)), ((select((absd(g_gr.stencil(((demosaicked_1_s0_x_2/2) + 2), ((demosaicked_1_s0_y_2/2) + 1)), g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1))) < absd(g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), (demosaicked_1_s0_y_2/2)), g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)))), ((g_gr.stencil(((demosaicked_1_s0_x_2/2) + 2), ((demosaicked_1_s0_y_2/2) + 1)) + g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)))/(uint16)2), ((g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), (demosaicked_1_s0_y_2/2)) + g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)))/(uint16)2)) + ((b_b.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)) + b_b.stencil((demosaicked_1_s0_x_2/2), (demosaicked_1_s0_y_2/2)))/(uint16)2)) - ((select((absd(g_gb.stencil((demosaicked_1_s0_x_2/2), (demosaicked_1_s0_y_2/2)), g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), (demosaicked_1_s0_y_2/2))) < absd(g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)), g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), (demosaicked_1_s0_y_2/2)))), ((g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), (demosaicked_1_s0_y_2/2)) + g_gb.stencil((demosaicked_1_s0_x_2/2), (demosaicked_1_s0_y_2/2)))/(uint16)2), ((g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)) + g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), (demosaicked_1_s0_y_2/2)))/(uint16)2)) + select((absd(g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)), g_gb.stencil(((demosaicked_1_s0_x_2/2) + 2), ((demosaicked_1_s0_y_2/2) + 1))) < absd(g_gr.stencil(((demosaicked_1_s0_x_2/2) + 2), ((demosaicked_1_s0_y_2/2) + 2)), g_gr.stencil(((demosaicked_1_s0_x_2/2) + 2), ((demosaicked_1_s0_y_2/2) + 1)))), ((g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)) + g_gb.stencil(((demosaicked_1_s0_x_2/2) + 2), ((demosaicked_1_s0_y_2/2) + 1)))/(uint16)2), ((g_gr.stencil(((demosaicked_1_s0_x_2/2) + 2), ((demosaicked_1_s0_y_2/2) + 1)) + g_gr.stencil(((demosaicked_1_s0_x_2/2) + 2), ((demosaicked_1_s0_y_2/2) + 2)))/(uint16)2)))/(uint16)2)))), select(((demosaicked_1_s0_x_2 % 2) == 0), b_b.stencil((demosaicked_1_s0_x_2/2), ((demosaicked_1_s0_y_2/2) + 1)), ((g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)) + ((b_b.stencil((demosaicked_1_s0_x_2/2), ((demosaicked_1_s0_y_2/2) + 1)) + b_b.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)))/(uint16)2)) - ((select((absd(g_gb.stencil((demosaicked_1_s0_x_2/2), ((demosaicked_1_s0_y_2/2) + 1)), g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1))) < absd(g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 2)), g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)))), ((g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)) + g_gb.stencil((demosaicked_1_s0_x_2/2), ((demosaicked_1_s0_y_2/2) + 1)))/(uint16)2), ((g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)) + g_gr.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 2)))/(uint16)2)) + select((absd(g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)), g_gb.stencil(((demosaicked_1_s0_x_2/2) + 2), ((demosaicked_1_s0_y_2/2) + 1))) < absd(g_gr.stencil(((demosaicked_1_s0_x_2/2) + 2), ((demosaicked_1_s0_y_2/2) + 2)), g_gr.stencil(((demosaicked_1_s0_x_2/2) + 2), ((demosaicked_1_s0_y_2/2) + 1)))), ((g_gb.stencil(((demosaicked_1_s0_x_2/2) + 1), ((demosaicked_1_s0_y_2/2) + 1)) + g_gb.stencil(((demosaicked_1_s0_x_2/2) + 2), ((demosaicked_1_s0_y_2/2) + 1)))/(uint16)2), ((g_gr.stencil(((demosaicked_1_s0_x_2/2) + 2), ((demosaicked_1_s0_y_2/2) + 1)) + g_gr.stencil(((demosaicked_1_s0_x_2/2) + 2), ((demosaicked_1_s0_y_2/2) + 2)))/(uint16)2)))/(uint16)2))))
  auto hcompute_demosaicked_1_stencil_2 = demosaicked_1_s0_x_2->add_op("op_hcompute_demosaicked_1_stencil_2");
  hcompute_demosaicked_1_stencil_2->add_function("hcompute_demosaicked_1_stencil_2");
  hcompute_demosaicked_1_stencil_2->add_load("b_b_stencil", "(floor((demosaicked_1_s0_y_2/2)) + 1)", "floor((demosaicked_1_s0_x_2/2))");
  hcompute_demosaicked_1_stencil_2->add_load("b_b_stencil", "floor((demosaicked_1_s0_y_2/2))", "floor((demosaicked_1_s0_x_2/2))");
  hcompute_demosaicked_1_stencil_2->add_load("b_b_stencil", "floor((demosaicked_1_s0_y_2/2))", "(floor((demosaicked_1_s0_x_2/2)) + 1)");
  hcompute_demosaicked_1_stencil_2->add_load("b_b_stencil", "(floor((demosaicked_1_s0_y_2/2)) + 1)", "(floor((demosaicked_1_s0_x_2/2)) + 1)");
  hcompute_demosaicked_1_stencil_2->add_load("g_gb_stencil", "(floor((demosaicked_1_s0_y_2/2)) + 1)", "floor((demosaicked_1_s0_x_2/2))");
  hcompute_demosaicked_1_stencil_2->add_load("g_gb_stencil", "(floor((demosaicked_1_s0_y_2/2)) + 1)", "(floor((demosaicked_1_s0_x_2/2)) + 1)");
  hcompute_demosaicked_1_stencil_2->add_load("g_gb_stencil", "floor((demosaicked_1_s0_y_2/2))", "floor((demosaicked_1_s0_x_2/2))");
  hcompute_demosaicked_1_stencil_2->add_load("g_gb_stencil", "floor((demosaicked_1_s0_y_2/2))", "(floor((demosaicked_1_s0_x_2/2)) + 1)");
  hcompute_demosaicked_1_stencil_2->add_load("g_gb_stencil", "floor((demosaicked_1_s0_y_2/2))", "(floor((demosaicked_1_s0_x_2/2)) + 2)");
  hcompute_demosaicked_1_stencil_2->add_load("g_gb_stencil", "(floor((demosaicked_1_s0_y_2/2)) + 1)", "(floor((demosaicked_1_s0_x_2/2)) + 2)");
  hcompute_demosaicked_1_stencil_2->add_load("g_gr_stencil", "(floor((demosaicked_1_s0_y_2/2)) + 1)", "(floor((demosaicked_1_s0_x_2/2)) + 1)");
  hcompute_demosaicked_1_stencil_2->add_load("g_gr_stencil", "(floor((demosaicked_1_s0_y_2/2)) + 2)", "(floor((demosaicked_1_s0_x_2/2)) + 1)");
  hcompute_demosaicked_1_stencil_2->add_load("g_gr_stencil", "floor((demosaicked_1_s0_y_2/2))", "(floor((demosaicked_1_s0_x_2/2)) + 1)");
  hcompute_demosaicked_1_stencil_2->add_load("g_gr_stencil", "(floor((demosaicked_1_s0_y_2/2)) + 1)", "(floor((demosaicked_1_s0_x_2/2)) + 2)");
  hcompute_demosaicked_1_stencil_2->add_load("g_gr_stencil", "floor((demosaicked_1_s0_y_2/2))", "(floor((demosaicked_1_s0_x_2/2)) + 2)");
  hcompute_demosaicked_1_stencil_2->add_load("g_gr_stencil", "(floor((demosaicked_1_s0_y_2/2)) + 2)", "(floor((demosaicked_1_s0_x_2/2)) + 2)");
  hcompute_demosaicked_1_stencil_2->add_store("demosaicked_1_stencil", "2", "demosaicked_1_s0_y_2", "demosaicked_1_s0_x_2");
  hcompute_demosaicked_1_stencil_2->compute_unit_needs_index_variable("demosaicked_1_s0_x_2");
  hcompute_demosaicked_1_stencil_2->compute_unit_needs_index_variable("demosaicked_1_s0_y_2");

//consuming demosaicked$1.stencil
////producing corrected.stencil
  auto corrected_s0_y = prg.add_loop("corrected_s0_y", 0, 56);
  auto corrected_s0_x = corrected_s0_y->add_loop("corrected_s0_x", 0, 56);

//store is: corrected.stencil(corrected_s0_x, corrected_s0_y, 0) = (((int16(((int32(min(demosaicked$1.stencil(corrected_s0_x, corrected_s0_y, 0), (uint16)10000))*549)/256)) + int16(((int32(min(demosaicked$1.stencil(corrected_s0_x, corrected_s0_y, 1), (uint16)10000))*-103)/256))) + int16(((int32(min(demosaicked$1.stencil(corrected_s0_x, corrected_s0_y, 2), (uint16)10000))*7)/256))) + (int16)-40)
  auto hcompute_corrected_stencil = corrected_s0_x->add_op("op_hcompute_corrected_stencil");
  hcompute_corrected_stencil->add_function("hcompute_corrected_stencil");
  hcompute_corrected_stencil->add_load("demosaicked_1_stencil", "0", "corrected_s0_y", "corrected_s0_x");
  hcompute_corrected_stencil->add_load("demosaicked_1_stencil", "1", "corrected_s0_y", "corrected_s0_x");
  hcompute_corrected_stencil->add_load("demosaicked_1_stencil", "2", "corrected_s0_y", "corrected_s0_x");
  prg.buffer_port_widths["corrected_stencil"] = 16;
  hcompute_corrected_stencil->add_store("corrected_stencil", "0", "corrected_s0_y", "corrected_s0_x");
  auto corrected_s0_y_1 = prg.add_loop("corrected_s0_y_1", 0, 56);
  auto corrected_s0_x_1 = corrected_s0_y_1->add_loop("corrected_s0_x_1", 0, 56);

//store is: corrected.stencil(corrected_s0_x_1, corrected_s0_y_1, 1) = (((int16(((int32(min(demosaicked$1.stencil(corrected_s0_x_1, corrected_s0_y_1, 0), (uint16)10000))*-96)/256)) + int16(((int32(min(demosaicked$1.stencil(corrected_s0_x_1, corrected_s0_y_1, 1), (uint16)10000))*373)/256))) + int16(((int32(min(demosaicked$1.stencil(corrected_s0_x_1, corrected_s0_y_1, 2), (uint16)10000))*62)/256))) + (int16)-29)
  auto hcompute_corrected_stencil_1 = corrected_s0_x_1->add_op("op_hcompute_corrected_stencil_1");
  hcompute_corrected_stencil_1->add_function("hcompute_corrected_stencil_1");
  hcompute_corrected_stencil_1->add_load("demosaicked_1_stencil", "0", "corrected_s0_y_1", "corrected_s0_x_1");
  hcompute_corrected_stencil_1->add_load("demosaicked_1_stencil", "1", "corrected_s0_y_1", "corrected_s0_x_1");
  hcompute_corrected_stencil_1->add_load("demosaicked_1_stencil", "2", "corrected_s0_y_1", "corrected_s0_x_1");
  hcompute_corrected_stencil_1->add_store("corrected_stencil", "1", "corrected_s0_y_1", "corrected_s0_x_1");
  auto corrected_s0_y_2 = prg.add_loop("corrected_s0_y_2", 0, 56);
  auto corrected_s0_x_2 = corrected_s0_y_2->add_loop("corrected_s0_x_2", 0, 56);

//store is: corrected.stencil(corrected_s0_x_2, corrected_s0_y_2, 2) = (((int16(((int32(min(demosaicked$1.stencil(corrected_s0_x_2, corrected_s0_y_2, 0), (uint16)10000))*-31)/256)) + int16(((int32(min(demosaicked$1.stencil(corrected_s0_x_2, corrected_s0_y_2, 1), (uint16)10000))*-261)/256))) + int16(((int32(min(demosaicked$1.stencil(corrected_s0_x_2, corrected_s0_y_2, 2), (uint16)10000))*883)/256))) + (int16)-22)
  auto hcompute_corrected_stencil_2 = corrected_s0_x_2->add_op("op_hcompute_corrected_stencil_2");
  hcompute_corrected_stencil_2->add_function("hcompute_corrected_stencil_2");
  hcompute_corrected_stencil_2->add_load("demosaicked_1_stencil", "0", "corrected_s0_y_2", "corrected_s0_x_2");
  hcompute_corrected_stencil_2->add_load("demosaicked_1_stencil", "1", "corrected_s0_y_2", "corrected_s0_x_2");
  hcompute_corrected_stencil_2->add_load("demosaicked_1_stencil", "2", "corrected_s0_y_2", "corrected_s0_x_2");
  hcompute_corrected_stencil_2->add_store("corrected_stencil", "2", "corrected_s0_y_2", "corrected_s0_x_2");

//consuming corrected.stencil
////producing curvea0

//consuming curvea0
////producing curved.stencil
  auto curved_s0_y = prg.add_loop("curved_s0_y", 0, 56);
  auto curved_s0_x = curved_s0_y->add_loop("curved_s0_x", 0, 56);

//store is: curved.stencil(curved_s0_x, curved_s0_y, 0) = curvea0[int32(uint16(max(min(corrected.stencil(curved_s0_x, curved_s0_y, 0), (int16)1023), (int16)0)))]
  auto hcompute_curved_stencil = curved_s0_x->add_op("op_hcompute_curved_stencil");
  hcompute_curved_stencil->add_function("hcompute_curved_stencil");
  hcompute_curved_stencil->add_load("corrected_stencil", "0", "curved_s0_y", "curved_s0_x");
  prg.buffer_port_widths["curved_stencil"] = 16;
  hcompute_curved_stencil->add_store("curved_stencil", "0", "curved_s0_y", "curved_s0_x");
  //hcompute_curved_stencil->index_variable_prefetch_cycle(1);
  hcompute_curved_stencil->add_latency(1);
  auto curved_s0_y_1 = prg.add_loop("curved_s0_y_1", 0, 56);
  auto curved_s0_x_1 = curved_s0_y_1->add_loop("curved_s0_x_1", 0, 56);

//store is: curved.stencil(curved_s0_x_1, curved_s0_y_1, 1) = curvea0[int32(uint16(max(min(corrected.stencil(curved_s0_x_1, curved_s0_y_1, 1), (int16)1023), (int16)0)))]
  auto hcompute_curved_stencil_1 = curved_s0_x_1->add_op("op_hcompute_curved_stencil_1");
  hcompute_curved_stencil_1->add_function("hcompute_curved_stencil_1");
  hcompute_curved_stencil_1->add_load("corrected_stencil", "1", "curved_s0_y_1", "curved_s0_x_1");
  hcompute_curved_stencil_1->add_store("curved_stencil", "1", "curved_s0_y_1", "curved_s0_x_1");
  //hcompute_curved_stencil_1->index_variable_prefetch_cycle(1);
  hcompute_curved_stencil_1->add_latency(1);
  auto curved_s0_y_2 = prg.add_loop("curved_s0_y_2", 0, 56);
  auto curved_s0_x_2 = curved_s0_y_2->add_loop("curved_s0_x_2", 0, 56);

//store is: curved.stencil(curved_s0_x_2, curved_s0_y_2, 2) = curvea0[int32(uint16(max(min(corrected.stencil(curved_s0_x_2, curved_s0_y_2, 2), (int16)1023), (int16)0)))]
  auto hcompute_curved_stencil_2 = curved_s0_x_2->add_op("op_hcompute_curved_stencil_2");
  hcompute_curved_stencil_2->add_function("hcompute_curved_stencil_2");
  hcompute_curved_stencil_2->add_load("corrected_stencil", "2", "curved_s0_y_2", "curved_s0_x_2");
  hcompute_curved_stencil_2->add_store("curved_stencil", "2", "curved_s0_y_2", "curved_s0_x_2");
  //hcompute_curved_stencil_2->index_variable_prefetch_cycle(1);
  hcompute_curved_stencil_2->add_latency(1);

//consuming curved.stencil
  auto hw_output_s0_y_yi = prg.add_loop("hw_output_s0_y_yi", 0, 56);
  auto hw_output_s0_x_xi = hw_output_s0_y_yi->add_loop("hw_output_s0_x_xi", 0, 56);

//store is: hw_output.stencil(0, hw_output_s0_x_xi, hw_output_s0_y_yi) = curved.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi, 0)
  auto hcompute_hw_output_stencil = hw_output_s0_x_xi->add_op("op_hcompute_hw_output_stencil");
  hcompute_hw_output_stencil->add_function("hcompute_hw_output_stencil");
  hcompute_hw_output_stencil->add_load("curved_stencil", "0", "hw_output_s0_y_yi", "hw_output_s0_x_xi");
  hcompute_hw_output_stencil->add_store("hw_output_stencil", "hw_output_s0_y_yi", "hw_output_s0_x_xi", "0");

//store is: hw_output.stencil(1, hw_output_s0_x_xi, hw_output_s0_y_yi) = curved.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi, 1)
  auto hcompute_hw_output_stencil_1 = hw_output_s0_x_xi->add_op("op_hcompute_hw_output_stencil_1");
  hcompute_hw_output_stencil_1->add_function("hcompute_hw_output_stencil_1");
  hcompute_hw_output_stencil_1->add_load("curved_stencil", "1", "hw_output_s0_y_yi", "hw_output_s0_x_xi");
  hcompute_hw_output_stencil_1->add_store("hw_output_stencil", "hw_output_s0_y_yi", "hw_output_s0_x_xi", "1");

//store is: hw_output.stencil(2, hw_output_s0_x_xi, hw_output_s0_y_yi) = curved.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi, 2)
  auto hcompute_hw_output_stencil_2 = hw_output_s0_x_xi->add_op("op_hcompute_hw_output_stencil_2");
  hcompute_hw_output_stencil_2->add_function("hcompute_hw_output_stencil_2");
  hcompute_hw_output_stencil_2->add_load("curved_stencil", "2", "hw_output_s0_y_yi", "hw_output_s0_x_xi");
  hcompute_hw_output_stencil_2->add_store("hw_output_stencil", "hw_output_s0_y_yi", "hw_output_s0_x_xi", "2");

  return prg;
}


// empty
