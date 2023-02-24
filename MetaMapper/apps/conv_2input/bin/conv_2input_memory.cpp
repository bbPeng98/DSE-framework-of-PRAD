#include "app.h"
#include "ubuffer.h"
#include "codegen.h"
#include "prog.h"

prog conv_2input() {
  prog prg;
  prg.compute_unit_file = "conv_2input_compute.h";
  prg.name = "conv_2input";

// Stencil<uint16_t, 64, 64> &hw_input_stencil = arg_0;
  prg.add_input("hw_input_stencil");
  prg.buffer_port_widths["hw_input_stencil"] = 16;
// Stencil<uint16_t, 3, 3> &hw_weight_stencil = arg_1;
  prg.add_input("hw_weight_stencil");
  prg.buffer_port_widths["hw_weight_stencil"] = 16;
// Stencil<uint16_t, 62, 62> &hw_output_stencil = arg_2;
  prg.add_output("hw_output_stencil");
  prg.buffer_port_widths["hw_output_stencil"] = 16;

////producing hw_input_global_wrapper.stencil
  auto hw_input_global_wrapper_s0_y = prg.add_loop("hw_input_global_wrapper_s0_y", 0, 64);
  auto hw_input_global_wrapper_s0_x = hw_input_global_wrapper_s0_y->add_loop("hw_input_global_wrapper_s0_x", 0, 64);

//store is: hw_input_global_wrapper.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y) = hw_input.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y)
  auto hcompute_hw_input_global_wrapper_stencil = hw_input_global_wrapper_s0_x->add_op("op_hcompute_hw_input_global_wrapper_stencil");
  hcompute_hw_input_global_wrapper_stencil->add_function("hcompute_hw_input_global_wrapper_stencil");
  hcompute_hw_input_global_wrapper_stencil->add_load("hw_input_stencil", "hw_input_global_wrapper_s0_y", "hw_input_global_wrapper_s0_x");
  prg.buffer_port_widths["hw_input_global_wrapper_stencil"] = 16;
  hcompute_hw_input_global_wrapper_stencil->add_store("hw_input_global_wrapper_stencil", "hw_input_global_wrapper_s0_y", "hw_input_global_wrapper_s0_x");

//consuming hw_input_global_wrapper.stencil
////producing hw_weight_global_wrapper.stencil
  auto hw_weight_global_wrapper_s0_y = prg.add_loop("hw_weight_global_wrapper_s0_y", 0, 3);
  auto hw_weight_global_wrapper_s0_x = hw_weight_global_wrapper_s0_y->add_loop("hw_weight_global_wrapper_s0_x", 0, 3);

//store is: hw_weight_global_wrapper.stencil(hw_weight_global_wrapper_s0_x, hw_weight_global_wrapper_s0_y) = hw_weight.stencil(hw_weight_global_wrapper_s0_x, hw_weight_global_wrapper_s0_y)
  auto hcompute_hw_weight_global_wrapper_stencil = hw_weight_global_wrapper_s0_x->add_op("op_hcompute_hw_weight_global_wrapper_stencil");
  hcompute_hw_weight_global_wrapper_stencil->add_function("hcompute_hw_weight_global_wrapper_stencil");
  hcompute_hw_weight_global_wrapper_stencil->add_load("hw_weight_stencil", "hw_weight_global_wrapper_s0_y", "hw_weight_global_wrapper_s0_x");
  prg.buffer_port_widths["hw_weight_global_wrapper_stencil"] = 16;
  hcompute_hw_weight_global_wrapper_stencil->add_store("hw_weight_global_wrapper_stencil", "hw_weight_global_wrapper_s0_y", "hw_weight_global_wrapper_s0_x");

//consuming hw_weight_global_wrapper.stencil
////producing conv.stencil
  auto conv_s0_y = prg.add_loop("conv_s0_y", 0, 62);
  auto conv_s0_x = conv_s0_y->add_loop("conv_s0_x", 0, 62);

//store is: conv.stencil(conv_s0_x, conv_s0_y) = (uint16)0
  auto hcompute_conv_stencil = conv_s0_x->add_op("op_hcompute_conv_stencil");
  hcompute_conv_stencil->add_function("hcompute_conv_stencil");
  prg.buffer_port_widths["conv_stencil"] = 16;
  hcompute_conv_stencil->add_store("conv_stencil", "conv_s0_y", "conv_s0_x");
  auto conv_s1_y = prg.add_loop("conv_s1_y", 0, 62);
  auto conv_s1_x = conv_s1_y->add_loop("conv_s1_x", 0, 62);

//store is: conv.stencil(conv_s1_x, conv_s1_y) = ((hw_weight_global_wrapper.stencil(0, 0)*hw_input_global_wrapper.stencil(conv_s1_x, conv_s1_y)) + (conv.stencil(conv_s1_x, conv_s1_y) + ((hw_weight_global_wrapper.stencil(1, 0)*hw_input_global_wrapper.stencil((conv_s1_x + 1), conv_s1_y)) + ((hw_weight_global_wrapper.stencil(2, 0)*hw_input_global_wrapper.stencil((conv_s1_x + 2), conv_s1_y)) + ((hw_weight_global_wrapper.stencil(0, 1)*hw_input_global_wrapper.stencil(conv_s1_x, (conv_s1_y + 1))) + ((hw_weight_global_wrapper.stencil(1, 1)*hw_input_global_wrapper.stencil((conv_s1_x + 1), (conv_s1_y + 1))) + ((hw_weight_global_wrapper.stencil(2, 1)*hw_input_global_wrapper.stencil((conv_s1_x + 2), (conv_s1_y + 1))) + ((hw_weight_global_wrapper.stencil(0, 2)*hw_input_global_wrapper.stencil(conv_s1_x, (conv_s1_y + 2))) + ((hw_weight_global_wrapper.stencil(2, 2)*hw_input_global_wrapper.stencil((conv_s1_x + 2), (conv_s1_y + 2))) + (hw_weight_global_wrapper.stencil(1, 2)*hw_input_global_wrapper.stencil((conv_s1_x + 1), (conv_s1_y + 2))))))))))))
  auto hcompute_conv_stencil_1 = conv_s1_x->add_op("op_hcompute_conv_stencil_1");
  hcompute_conv_stencil_1->add_function("hcompute_conv_stencil_1");
  hcompute_conv_stencil_1->add_load("conv_stencil", "conv_s1_y", "conv_s1_x");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "conv_s1_y", "conv_s1_x");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "conv_s1_y", "(conv_s1_x + 1)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "conv_s1_y", "(conv_s1_x + 2)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 1)", "conv_s1_x");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 1)", "(conv_s1_x + 1)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 1)", "(conv_s1_x + 2)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 2)", "conv_s1_x");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 2)", "(conv_s1_x + 2)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 2)", "(conv_s1_x + 1)");
  hcompute_conv_stencil_1->add_load("hw_weight_global_wrapper_stencil", "0", "0");
  hcompute_conv_stencil_1->add_load("hw_weight_global_wrapper_stencil", "0", "1");
  hcompute_conv_stencil_1->add_load("hw_weight_global_wrapper_stencil", "0", "2");
  hcompute_conv_stencil_1->add_load("hw_weight_global_wrapper_stencil", "1", "0");
  hcompute_conv_stencil_1->add_load("hw_weight_global_wrapper_stencil", "1", "1");
  hcompute_conv_stencil_1->add_load("hw_weight_global_wrapper_stencil", "1", "2");
  hcompute_conv_stencil_1->add_load("hw_weight_global_wrapper_stencil", "2", "0");
  hcompute_conv_stencil_1->add_load("hw_weight_global_wrapper_stencil", "2", "2");
  hcompute_conv_stencil_1->add_load("hw_weight_global_wrapper_stencil", "2", "1");
  hcompute_conv_stencil_1->add_store("conv_stencil", "conv_s1_y", "conv_s1_x");

//consuming conv.stencil
  auto hw_output_s0_y_yi = prg.add_loop("hw_output_s0_y_yi", 0, 62);
  auto hw_output_s0_x_xi = hw_output_s0_y_yi->add_loop("hw_output_s0_x_xi", 0, 62);

//store is: hw_output.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi) = conv.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi)
  auto hcompute_hw_output_stencil = hw_output_s0_x_xi->add_op("op_hcompute_hw_output_stencil");
  hcompute_hw_output_stencil->add_function("hcompute_hw_output_stencil");
  hcompute_hw_output_stencil->add_load("conv_stencil", "hw_output_s0_y_yi", "hw_output_s0_x_xi");
  hcompute_hw_output_stencil->add_store("hw_output_stencil", "hw_output_s0_y_yi", "hw_output_s0_x_xi");

  return prg;
}


// empty
