#include "app.h"
#include "ubuffer.h"
#include "codegen.h"
#include "prog.h"

prog conv_5_5() {
  prog prg;
  prg.compute_unit_file = "conv_5_5_compute.h";
  prg.name = "conv_5_5";

// Stencil<uint16_t, 64, 64> &hw_input_stencil = arg_0;
  prg.add_input("hw_input_stencil");
  prg.buffer_port_widths["hw_input_stencil"] = 16;
// Stencil<uint16_t, 60, 60> &hw_output_stencil = arg_1;
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
////producing conv.stencil
  auto conv_s0_y = prg.add_loop("conv_s0_y", 0, 60);
  auto conv_s0_x = conv_s0_y->add_loop("conv_s0_x", 0, 60);

//store is: conv.stencil(conv_s0_x, conv_s0_y) = (uint16)0
  auto hcompute_conv_stencil = conv_s0_x->add_op("op_hcompute_conv_stencil");
  hcompute_conv_stencil->add_function("hcompute_conv_stencil");
  prg.buffer_port_widths["conv_stencil"] = 16;
  hcompute_conv_stencil->add_store("conv_stencil", "conv_s0_y", "conv_s0_x");
  auto conv_s1_y = prg.add_loop("conv_s1_y", 0, 60);
  auto conv_s1_x = conv_s1_y->add_loop("conv_s1_x", 0, 60);

//store is: conv.stencil(conv_s1_x, conv_s1_y) = ((hw_input_global_wrapper.stencil(conv_s1_x, conv_s1_y)*(uint16)11) + (conv.stencil(conv_s1_x, conv_s1_y) + ((hw_input_global_wrapper.stencil((conv_s1_x + 1), conv_s1_y)*(uint16)14) + ((hw_input_global_wrapper.stencil((conv_s1_x + 2), conv_s1_y)*(uint16)17) + ((hw_input_global_wrapper.stencil((conv_s1_x + 3), conv_s1_y)*(uint16)20) + ((hw_input_global_wrapper.stencil((conv_s1_x + 4), conv_s1_y)*(uint16)30) + ((hw_input_global_wrapper.stencil(conv_s1_x, (conv_s1_y + 1))*(uint16)12) + ((hw_input_global_wrapper.stencil((conv_s1_x + 2), (conv_s1_y + 1))*(uint16)18) + ((hw_input_global_wrapper.stencil((conv_s1_x + 3), (conv_s1_y + 1))*(uint16)29) + ((hw_input_global_wrapper.stencil((conv_s1_x + 4), (conv_s1_y + 1))*(uint16)39) + ((hw_input_global_wrapper.stencil(conv_s1_x, (conv_s1_y + 2))*(uint16)13) + ((hw_input_global_wrapper.stencil((conv_s1_x + 1), (conv_s1_y + 2))*(uint16)16) + ((hw_input_global_wrapper.stencil((conv_s1_x + 2), (conv_s1_y + 2))*(uint16)19) + ((hw_input_global_wrapper.stencil((conv_s1_x + 3), (conv_s1_y + 2))*(uint16)22) + ((hw_input_global_wrapper.stencil((conv_s1_x + 4), (conv_s1_y + 2))*(uint16)32) + ((hw_input_global_wrapper.stencil(conv_s1_x, (conv_s1_y + 3))*(uint16)23) + ((hw_input_global_wrapper.stencil((conv_s1_x + 1), (conv_s1_y + 3))*(uint16)21) + ((hw_input_global_wrapper.stencil((conv_s1_x + 2), (conv_s1_y + 3))*(uint16)26) + ((hw_input_global_wrapper.stencil((conv_s1_x + 3), (conv_s1_y + 3))*(uint16)24) + ((hw_input_global_wrapper.stencil((conv_s1_x + 4), (conv_s1_y + 3))*(uint16)34) + ((hw_input_global_wrapper.stencil(conv_s1_x, (conv_s1_y + 4))*(uint16)33) + ((hw_input_global_wrapper.stencil((conv_s1_x + 1), (conv_s1_y + 4))*(uint16)31) + ((hw_input_global_wrapper.stencil((conv_s1_x + 2), (conv_s1_y + 4))*(uint16)32) + ((hw_input_global_wrapper.stencil((conv_s1_x + 4), (conv_s1_y + 4))*(uint16)37) + (hw_input_global_wrapper.stencil((conv_s1_x + 3), (conv_s1_y + 4))*(uint16)34)))))))))))))))))))))))))
  auto hcompute_conv_stencil_1 = conv_s1_x->add_op("op_hcompute_conv_stencil_1");
  hcompute_conv_stencil_1->add_function("hcompute_conv_stencil_1");
  hcompute_conv_stencil_1->add_load("conv_stencil", "conv_s1_y", "conv_s1_x");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "conv_s1_y", "conv_s1_x");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 2)", "conv_s1_x");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 2)", "(conv_s1_x + 1)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 2)", "(conv_s1_x + 2)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 2)", "(conv_s1_x + 3)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 2)", "(conv_s1_x + 4)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 3)", "conv_s1_x");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 3)", "(conv_s1_x + 1)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 3)", "(conv_s1_x + 2)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 3)", "(conv_s1_x + 3)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 3)", "(conv_s1_x + 4)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "conv_s1_y", "(conv_s1_x + 1)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 4)", "conv_s1_x");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 4)", "(conv_s1_x + 1)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 4)", "(conv_s1_x + 2)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 4)", "(conv_s1_x + 4)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 4)", "(conv_s1_x + 3)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "conv_s1_y", "(conv_s1_x + 2)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "conv_s1_y", "(conv_s1_x + 3)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "conv_s1_y", "(conv_s1_x + 4)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 1)", "conv_s1_x");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 1)", "(conv_s1_x + 2)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 1)", "(conv_s1_x + 3)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv_s1_y + 1)", "(conv_s1_x + 4)");
  hcompute_conv_stencil_1->add_store("conv_stencil", "conv_s1_y", "conv_s1_x");

//consuming conv.stencil
  auto hw_output_s0_y_yi = prg.add_loop("hw_output_s0_y_yi", 0, 60);
  auto hw_output_s0_x_xi = hw_output_s0_y_yi->add_loop("hw_output_s0_x_xi", 0, 60);

//store is: hw_output.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi) = conv.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi)
  auto hcompute_hw_output_stencil = hw_output_s0_x_xi->add_op("op_hcompute_hw_output_stencil");
  hcompute_hw_output_stencil->add_function("hcompute_hw_output_stencil");
  hcompute_hw_output_stencil->add_load("conv_stencil", "hw_output_s0_y_yi", "hw_output_s0_x_xi");
  hcompute_hw_output_stencil->add_store("hw_output_stencil", "hw_output_s0_y_yi", "hw_output_s0_x_xi");

  return prg;
}


// empty
