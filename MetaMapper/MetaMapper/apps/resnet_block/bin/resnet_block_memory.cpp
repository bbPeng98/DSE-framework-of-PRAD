#include "app.h"
#include "ubuffer.h"
#include "codegen.h"
#include "prog.h"

prog resnet_block() {
  prog prg;
  prg.compute_unit_file = "resnet_block_compute.h";
  prg.name = "resnet_block";

// Stencil<uint16_t, 3, 32, 32> &hw_input_stencil = arg_0;
  prg.add_input("hw_input_stencil");
  prg.buffer_port_widths["hw_input_stencil"] = 16;
// Stencil<uint16_t, 3, 3, 3, 3> &hw_kernel_stencil = arg_1;
  prg.add_input("hw_kernel_stencil");
  prg.buffer_port_widths["hw_kernel_stencil"] = 16;
// Stencil<uint16_t, 3, 3, 3, 3> &hw_kernel2_stencil = arg_2;
  prg.add_input("hw_kernel2_stencil");
  prg.buffer_port_widths["hw_kernel2_stencil"] = 16;
// Stencil<uint16_t, 28, 28, 3> &hw_output_stencil = arg_3;
  prg.add_output("hw_output_stencil");
  prg.buffer_port_widths["hw_output_stencil"] = 16;

////producing hw_kernel2_global_wrapper.stencil
  auto hw_kernel2_global_wrapper_s0_y = prg.add_loop("hw_kernel2_global_wrapper_s0_y", 0, 3);
  auto hw_kernel2_global_wrapper_s0_x = hw_kernel2_global_wrapper_s0_y->add_loop("hw_kernel2_global_wrapper_s0_x", 0, 3);
  auto hw_kernel2_global_wrapper_s0_w = hw_kernel2_global_wrapper_s0_x->add_loop("hw_kernel2_global_wrapper_s0_w", 0, 3);
  auto hw_kernel2_global_wrapper_s0_z = hw_kernel2_global_wrapper_s0_w->add_loop("hw_kernel2_global_wrapper_s0_z", 0, 3);

//store is: hw_kernel2_global_wrapper.stencil(hw_kernel2_global_wrapper_s0_z, hw_kernel2_global_wrapper_s0_w, hw_kernel2_global_wrapper_s0_x, hw_kernel2_global_wrapper_s0_y) = hw_kernel2.stencil(hw_kernel2_global_wrapper_s0_z, hw_kernel2_global_wrapper_s0_w, hw_kernel2_global_wrapper_s0_x, hw_kernel2_global_wrapper_s0_y)
  auto hcompute_hw_kernel2_global_wrapper_stencil = hw_kernel2_global_wrapper_s0_z->add_op("op_hcompute_hw_kernel2_global_wrapper_stencil");
  hcompute_hw_kernel2_global_wrapper_stencil->add_function("hcompute_hw_kernel2_global_wrapper_stencil");
  hcompute_hw_kernel2_global_wrapper_stencil->add_load("hw_kernel2_stencil", "hw_kernel2_global_wrapper_s0_y", "hw_kernel2_global_wrapper_s0_x", "hw_kernel2_global_wrapper_s0_w", "hw_kernel2_global_wrapper_s0_z");
  prg.buffer_port_widths["hw_kernel2_global_wrapper_stencil"] = 16;
  hcompute_hw_kernel2_global_wrapper_stencil->add_store("hw_kernel2_global_wrapper_stencil", "hw_kernel2_global_wrapper_s0_y", "hw_kernel2_global_wrapper_s0_x", "hw_kernel2_global_wrapper_s0_w", "hw_kernel2_global_wrapper_s0_z");

//consuming hw_kernel2_global_wrapper.stencil
////producing hw_input_global_wrapper.stencil
  auto hw_input_global_wrapper_s0_y = prg.add_loop("hw_input_global_wrapper_s0_y", 0, 32);
  auto hw_input_global_wrapper_s0_x = hw_input_global_wrapper_s0_y->add_loop("hw_input_global_wrapper_s0_x", 0, 32);
  auto hw_input_global_wrapper_s0_z = hw_input_global_wrapper_s0_x->add_loop("hw_input_global_wrapper_s0_z", 0, 3);

//store is: hw_input_global_wrapper.stencil(hw_input_global_wrapper_s0_z, hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y) = hw_input.stencil(hw_input_global_wrapper_s0_z, hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y)
  auto hcompute_hw_input_global_wrapper_stencil = hw_input_global_wrapper_s0_z->add_op("op_hcompute_hw_input_global_wrapper_stencil");
  hcompute_hw_input_global_wrapper_stencil->add_function("hcompute_hw_input_global_wrapper_stencil");
  hcompute_hw_input_global_wrapper_stencil->add_load("hw_input_stencil", "hw_input_global_wrapper_s0_y", "hw_input_global_wrapper_s0_x", "hw_input_global_wrapper_s0_z");
  prg.buffer_port_widths["hw_input_global_wrapper_stencil"] = 16;
  hcompute_hw_input_global_wrapper_stencil->add_store("hw_input_global_wrapper_stencil", "hw_input_global_wrapper_s0_y", "hw_input_global_wrapper_s0_x", "hw_input_global_wrapper_s0_z");

//consuming hw_input_global_wrapper.stencil
////producing hw_kernel_global_wrapper.stencil
  auto hw_kernel_global_wrapper_s0_y = prg.add_loop("hw_kernel_global_wrapper_s0_y", 0, 3);
  auto hw_kernel_global_wrapper_s0_x = hw_kernel_global_wrapper_s0_y->add_loop("hw_kernel_global_wrapper_s0_x", 0, 3);
  auto hw_kernel_global_wrapper_s0_w = hw_kernel_global_wrapper_s0_x->add_loop("hw_kernel_global_wrapper_s0_w", 0, 3);
  auto hw_kernel_global_wrapper_s0_z = hw_kernel_global_wrapper_s0_w->add_loop("hw_kernel_global_wrapper_s0_z", 0, 3);

//store is: hw_kernel_global_wrapper.stencil(hw_kernel_global_wrapper_s0_z, hw_kernel_global_wrapper_s0_w, hw_kernel_global_wrapper_s0_x, hw_kernel_global_wrapper_s0_y) = hw_kernel.stencil(hw_kernel_global_wrapper_s0_z, hw_kernel_global_wrapper_s0_w, hw_kernel_global_wrapper_s0_x, hw_kernel_global_wrapper_s0_y)
  auto hcompute_hw_kernel_global_wrapper_stencil = hw_kernel_global_wrapper_s0_z->add_op("op_hcompute_hw_kernel_global_wrapper_stencil");
  hcompute_hw_kernel_global_wrapper_stencil->add_function("hcompute_hw_kernel_global_wrapper_stencil");
  hcompute_hw_kernel_global_wrapper_stencil->add_load("hw_kernel_stencil", "hw_kernel_global_wrapper_s0_y", "hw_kernel_global_wrapper_s0_x", "hw_kernel_global_wrapper_s0_w", "hw_kernel_global_wrapper_s0_z");
  prg.buffer_port_widths["hw_kernel_global_wrapper_stencil"] = 16;
  hcompute_hw_kernel_global_wrapper_stencil->add_store("hw_kernel_global_wrapper_stencil", "hw_kernel_global_wrapper_s0_y", "hw_kernel_global_wrapper_s0_x", "hw_kernel_global_wrapper_s0_w", "hw_kernel_global_wrapper_s0_z");

//consuming hw_kernel_global_wrapper.stencil
////producing conv1.stencil
  auto conv1_s0_y = prg.add_loop("conv1_s0_y", 0, 30);
  auto conv1_s0_x = conv1_s0_y->add_loop("conv1_s0_x", 0, 30);
  auto conv1_s0_w = conv1_s0_x->add_loop("conv1_s0_w", 0, 3);

//store is: conv1.stencil(conv1_s0_x, conv1_s0_y, conv1_s0_w) = (uint16)0
  auto hcompute_conv1_stencil = conv1_s0_w->add_op("op_hcompute_conv1_stencil");
  hcompute_conv1_stencil->add_function("hcompute_conv1_stencil");
  prg.buffer_port_widths["conv1_stencil"] = 16;
  hcompute_conv1_stencil->add_store("conv1_stencil", "conv1_s0_w", "conv1_s0_y", "conv1_s0_x");
  auto conv1_s1_r_y = prg.add_loop("conv1_s1_r_y", 0, 3);
  auto conv1_s1_r_x = conv1_s1_r_y->add_loop("conv1_s1_r_x", 0, 3);
  auto conv1_s1_y = conv1_s1_r_x->add_loop("conv1_s1_y", 0, 30);
  auto conv1_s1_x = conv1_s1_y->add_loop("conv1_s1_x", 0, 30);

//store is: conv1.stencil(conv1_s1_x, conv1_s1_y, 0) = ((hw_kernel_global_wrapper.stencil(0, 0, conv1_s1_r_x, conv1_s1_r_y)*hw_input_global_wrapper.stencil(0, (conv1_s1_r_x + conv1_s1_x), (conv1_s1_r_y + conv1_s1_y))) + (conv1.stencil(conv1_s1_x, conv1_s1_y, 0) + ((hw_kernel_global_wrapper.stencil(2, 0, conv1_s1_r_x, conv1_s1_r_y)*hw_input_global_wrapper.stencil(2, (conv1_s1_r_x + conv1_s1_x), (conv1_s1_r_y + conv1_s1_y))) + (hw_kernel_global_wrapper.stencil(1, 0, conv1_s1_r_x, conv1_s1_r_y)*hw_input_global_wrapper.stencil(1, (conv1_s1_r_x + conv1_s1_x), (conv1_s1_r_y + conv1_s1_y))))))
  auto hcompute_conv1_stencil_1 = conv1_s1_x->add_op("op_hcompute_conv1_stencil_1");
  hcompute_conv1_stencil_1->add_function("hcompute_conv1_stencil_1");
  hcompute_conv1_stencil_1->add_load("conv1_stencil", "0", "conv1_s1_y", "conv1_s1_x");
  hcompute_conv1_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv1_s1_r_y + conv1_s1_y)", "(conv1_s1_r_x + conv1_s1_x)", "0");
  hcompute_conv1_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv1_s1_r_y + conv1_s1_y)", "(conv1_s1_r_x + conv1_s1_x)", "2");
  hcompute_conv1_stencil_1->add_load("hw_input_global_wrapper_stencil", "(conv1_s1_r_y + conv1_s1_y)", "(conv1_s1_r_x + conv1_s1_x)", "1");
  hcompute_conv1_stencil_1->add_load("hw_kernel_global_wrapper_stencil", "conv1_s1_r_y", "conv1_s1_r_x", "0", "0");
  hcompute_conv1_stencil_1->add_load("hw_kernel_global_wrapper_stencil", "conv1_s1_r_y", "conv1_s1_r_x", "0", "2");
  hcompute_conv1_stencil_1->add_load("hw_kernel_global_wrapper_stencil", "conv1_s1_r_y", "conv1_s1_r_x", "0", "1");
  hcompute_conv1_stencil_1->add_store("conv1_stencil", "0", "conv1_s1_y", "conv1_s1_x");

//store is: conv1.stencil(conv1_s1_x, conv1_s1_y, 1) = ((hw_kernel_global_wrapper.stencil(0, 1, conv1_s1_r_x, conv1_s1_r_y)*hw_input_global_wrapper.stencil(0, (conv1_s1_r_x + conv1_s1_x), (conv1_s1_r_y + conv1_s1_y))) + (conv1.stencil(conv1_s1_x, conv1_s1_y, 1) + ((hw_kernel_global_wrapper.stencil(2, 1, conv1_s1_r_x, conv1_s1_r_y)*hw_input_global_wrapper.stencil(2, (conv1_s1_r_x + conv1_s1_x), (conv1_s1_r_y + conv1_s1_y))) + (hw_kernel_global_wrapper.stencil(1, 1, conv1_s1_r_x, conv1_s1_r_y)*hw_input_global_wrapper.stencil(1, (conv1_s1_r_x + conv1_s1_x), (conv1_s1_r_y + conv1_s1_y))))))
  auto hcompute_conv1_stencil_2 = conv1_s1_x->add_op("op_hcompute_conv1_stencil_2");
  hcompute_conv1_stencil_2->add_function("hcompute_conv1_stencil_2");
  hcompute_conv1_stencil_2->add_load("conv1_stencil", "1", "conv1_s1_y", "conv1_s1_x");
  hcompute_conv1_stencil_2->add_load("hw_input_global_wrapper_stencil", "(conv1_s1_r_y + conv1_s1_y)", "(conv1_s1_r_x + conv1_s1_x)", "0");
  hcompute_conv1_stencil_2->add_load("hw_input_global_wrapper_stencil", "(conv1_s1_r_y + conv1_s1_y)", "(conv1_s1_r_x + conv1_s1_x)", "2");
  hcompute_conv1_stencil_2->add_load("hw_input_global_wrapper_stencil", "(conv1_s1_r_y + conv1_s1_y)", "(conv1_s1_r_x + conv1_s1_x)", "1");
  hcompute_conv1_stencil_2->add_load("hw_kernel_global_wrapper_stencil", "conv1_s1_r_y", "conv1_s1_r_x", "1", "0");
  hcompute_conv1_stencil_2->add_load("hw_kernel_global_wrapper_stencil", "conv1_s1_r_y", "conv1_s1_r_x", "1", "2");
  hcompute_conv1_stencil_2->add_load("hw_kernel_global_wrapper_stencil", "conv1_s1_r_y", "conv1_s1_r_x", "1", "1");
  hcompute_conv1_stencil_2->add_store("conv1_stencil", "1", "conv1_s1_y", "conv1_s1_x");

//store is: conv1.stencil(conv1_s1_x, conv1_s1_y, 2) = ((hw_kernel_global_wrapper.stencil(0, 2, conv1_s1_r_x, conv1_s1_r_y)*hw_input_global_wrapper.stencil(0, (conv1_s1_r_x + conv1_s1_x), (conv1_s1_r_y + conv1_s1_y))) + (conv1.stencil(conv1_s1_x, conv1_s1_y, 2) + ((hw_kernel_global_wrapper.stencil(2, 2, conv1_s1_r_x, conv1_s1_r_y)*hw_input_global_wrapper.stencil(2, (conv1_s1_r_x + conv1_s1_x), (conv1_s1_r_y + conv1_s1_y))) + (hw_kernel_global_wrapper.stencil(1, 2, conv1_s1_r_x, conv1_s1_r_y)*hw_input_global_wrapper.stencil(1, (conv1_s1_r_x + conv1_s1_x), (conv1_s1_r_y + conv1_s1_y))))))
  auto hcompute_conv1_stencil_3 = conv1_s1_x->add_op("op_hcompute_conv1_stencil_3");
  hcompute_conv1_stencil_3->add_function("hcompute_conv1_stencil_3");
  hcompute_conv1_stencil_3->add_load("conv1_stencil", "2", "conv1_s1_y", "conv1_s1_x");
  hcompute_conv1_stencil_3->add_load("hw_input_global_wrapper_stencil", "(conv1_s1_r_y + conv1_s1_y)", "(conv1_s1_r_x + conv1_s1_x)", "0");
  hcompute_conv1_stencil_3->add_load("hw_input_global_wrapper_stencil", "(conv1_s1_r_y + conv1_s1_y)", "(conv1_s1_r_x + conv1_s1_x)", "2");
  hcompute_conv1_stencil_3->add_load("hw_input_global_wrapper_stencil", "(conv1_s1_r_y + conv1_s1_y)", "(conv1_s1_r_x + conv1_s1_x)", "1");
  hcompute_conv1_stencil_3->add_load("hw_kernel_global_wrapper_stencil", "conv1_s1_r_y", "conv1_s1_r_x", "2", "0");
  hcompute_conv1_stencil_3->add_load("hw_kernel_global_wrapper_stencil", "conv1_s1_r_y", "conv1_s1_r_x", "2", "2");
  hcompute_conv1_stencil_3->add_load("hw_kernel_global_wrapper_stencil", "conv1_s1_r_y", "conv1_s1_r_x", "2", "1");
  hcompute_conv1_stencil_3->add_store("conv1_stencil", "2", "conv1_s1_y", "conv1_s1_x");

//consuming conv1.stencil
////producing conv2.stencil
  auto conv2_s0_y = prg.add_loop("conv2_s0_y", 0, 28);
  auto conv2_s0_x = conv2_s0_y->add_loop("conv2_s0_x", 0, 28);
  auto conv2_s0_w = conv2_s0_x->add_loop("conv2_s0_w", 0, 3);

//store is: conv2.stencil(conv2_s0_x, conv2_s0_y, conv2_s0_w) = (uint16)0
  auto hcompute_conv2_stencil = conv2_s0_w->add_op("op_hcompute_conv2_stencil");
  hcompute_conv2_stencil->add_function("hcompute_conv2_stencil");
  prg.buffer_port_widths["conv2_stencil"] = 16;
  hcompute_conv2_stencil->add_store("conv2_stencil", "conv2_s0_w", "conv2_s0_y", "conv2_s0_x");
  auto conv2_s1_r2_0_y = prg.add_loop("conv2_s1_r2_0_y", 0, 3);
  auto conv2_s1_r2_0_x = conv2_s1_r2_0_y->add_loop("conv2_s1_r2_0_x", 0, 3);
  auto conv2_s1_y = conv2_s1_r2_0_x->add_loop("conv2_s1_y", 0, 28);
  auto conv2_s1_x = conv2_s1_y->add_loop("conv2_s1_x", 0, 28);

//store is: conv2.stencil(conv2_s1_x, conv2_s1_y, 0) = ((hw_kernel2_global_wrapper.stencil(0, 0, conv2_s1_r2_0_x, conv2_s1_r2_0_y)*conv1.stencil((conv2_s1_r2_0_x + conv2_s1_x), (conv2_s1_r2_0_y + conv2_s1_y), 0)) + (conv2.stencil(conv2_s1_x, conv2_s1_y, 0) + ((hw_kernel2_global_wrapper.stencil(2, 0, conv2_s1_r2_0_x, conv2_s1_r2_0_y)*conv1.stencil((conv2_s1_r2_0_x + conv2_s1_x), (conv2_s1_r2_0_y + conv2_s1_y), 2)) + (hw_kernel2_global_wrapper.stencil(1, 0, conv2_s1_r2_0_x, conv2_s1_r2_0_y)*conv1.stencil((conv2_s1_r2_0_x + conv2_s1_x), (conv2_s1_r2_0_y + conv2_s1_y), 1)))))
  auto hcompute_conv2_stencil_1 = conv2_s1_x->add_op("op_hcompute_conv2_stencil_1");
  hcompute_conv2_stencil_1->add_function("hcompute_conv2_stencil_1");
  hcompute_conv2_stencil_1->add_load("conv1_stencil", "0", "(conv2_s1_r2_0_y + conv2_s1_y)", "(conv2_s1_r2_0_x + conv2_s1_x)");
  hcompute_conv2_stencil_1->add_load("conv1_stencil", "2", "(conv2_s1_r2_0_y + conv2_s1_y)", "(conv2_s1_r2_0_x + conv2_s1_x)");
  hcompute_conv2_stencil_1->add_load("conv1_stencil", "1", "(conv2_s1_r2_0_y + conv2_s1_y)", "(conv2_s1_r2_0_x + conv2_s1_x)");
  hcompute_conv2_stencil_1->add_load("conv2_stencil", "0", "conv2_s1_y", "conv2_s1_x");
  hcompute_conv2_stencil_1->add_load("hw_kernel2_global_wrapper_stencil", "conv2_s1_r2_0_y", "conv2_s1_r2_0_x", "0", "0");
  hcompute_conv2_stencil_1->add_load("hw_kernel2_global_wrapper_stencil", "conv2_s1_r2_0_y", "conv2_s1_r2_0_x", "0", "2");
  hcompute_conv2_stencil_1->add_load("hw_kernel2_global_wrapper_stencil", "conv2_s1_r2_0_y", "conv2_s1_r2_0_x", "0", "1");
  hcompute_conv2_stencil_1->add_store("conv2_stencil", "0", "conv2_s1_y", "conv2_s1_x");

//store is: conv2.stencil(conv2_s1_x, conv2_s1_y, 1) = ((hw_kernel2_global_wrapper.stencil(0, 1, conv2_s1_r2_0_x, conv2_s1_r2_0_y)*conv1.stencil((conv2_s1_r2_0_x + conv2_s1_x), (conv2_s1_r2_0_y + conv2_s1_y), 0)) + (conv2.stencil(conv2_s1_x, conv2_s1_y, 1) + ((hw_kernel2_global_wrapper.stencil(2, 1, conv2_s1_r2_0_x, conv2_s1_r2_0_y)*conv1.stencil((conv2_s1_r2_0_x + conv2_s1_x), (conv2_s1_r2_0_y + conv2_s1_y), 2)) + (hw_kernel2_global_wrapper.stencil(1, 1, conv2_s1_r2_0_x, conv2_s1_r2_0_y)*conv1.stencil((conv2_s1_r2_0_x + conv2_s1_x), (conv2_s1_r2_0_y + conv2_s1_y), 1)))))
  auto hcompute_conv2_stencil_2 = conv2_s1_x->add_op("op_hcompute_conv2_stencil_2");
  hcompute_conv2_stencil_2->add_function("hcompute_conv2_stencil_2");
  hcompute_conv2_stencil_2->add_load("conv1_stencil", "0", "(conv2_s1_r2_0_y + conv2_s1_y)", "(conv2_s1_r2_0_x + conv2_s1_x)");
  hcompute_conv2_stencil_2->add_load("conv1_stencil", "2", "(conv2_s1_r2_0_y + conv2_s1_y)", "(conv2_s1_r2_0_x + conv2_s1_x)");
  hcompute_conv2_stencil_2->add_load("conv1_stencil", "1", "(conv2_s1_r2_0_y + conv2_s1_y)", "(conv2_s1_r2_0_x + conv2_s1_x)");
  hcompute_conv2_stencil_2->add_load("conv2_stencil", "1", "conv2_s1_y", "conv2_s1_x");
  hcompute_conv2_stencil_2->add_load("hw_kernel2_global_wrapper_stencil", "conv2_s1_r2_0_y", "conv2_s1_r2_0_x", "1", "0");
  hcompute_conv2_stencil_2->add_load("hw_kernel2_global_wrapper_stencil", "conv2_s1_r2_0_y", "conv2_s1_r2_0_x", "1", "2");
  hcompute_conv2_stencil_2->add_load("hw_kernel2_global_wrapper_stencil", "conv2_s1_r2_0_y", "conv2_s1_r2_0_x", "1", "1");
  hcompute_conv2_stencil_2->add_store("conv2_stencil", "1", "conv2_s1_y", "conv2_s1_x");

//store is: conv2.stencil(conv2_s1_x, conv2_s1_y, 2) = ((hw_kernel2_global_wrapper.stencil(0, 2, conv2_s1_r2_0_x, conv2_s1_r2_0_y)*conv1.stencil((conv2_s1_r2_0_x + conv2_s1_x), (conv2_s1_r2_0_y + conv2_s1_y), 0)) + (conv2.stencil(conv2_s1_x, conv2_s1_y, 2) + ((hw_kernel2_global_wrapper.stencil(2, 2, conv2_s1_r2_0_x, conv2_s1_r2_0_y)*conv1.stencil((conv2_s1_r2_0_x + conv2_s1_x), (conv2_s1_r2_0_y + conv2_s1_y), 2)) + (hw_kernel2_global_wrapper.stencil(1, 2, conv2_s1_r2_0_x, conv2_s1_r2_0_y)*conv1.stencil((conv2_s1_r2_0_x + conv2_s1_x), (conv2_s1_r2_0_y + conv2_s1_y), 1)))))
  auto hcompute_conv2_stencil_3 = conv2_s1_x->add_op("op_hcompute_conv2_stencil_3");
  hcompute_conv2_stencil_3->add_function("hcompute_conv2_stencil_3");
  hcompute_conv2_stencil_3->add_load("conv1_stencil", "0", "(conv2_s1_r2_0_y + conv2_s1_y)", "(conv2_s1_r2_0_x + conv2_s1_x)");
  hcompute_conv2_stencil_3->add_load("conv1_stencil", "2", "(conv2_s1_r2_0_y + conv2_s1_y)", "(conv2_s1_r2_0_x + conv2_s1_x)");
  hcompute_conv2_stencil_3->add_load("conv1_stencil", "1", "(conv2_s1_r2_0_y + conv2_s1_y)", "(conv2_s1_r2_0_x + conv2_s1_x)");
  hcompute_conv2_stencil_3->add_load("conv2_stencil", "2", "conv2_s1_y", "conv2_s1_x");
  hcompute_conv2_stencil_3->add_load("hw_kernel2_global_wrapper_stencil", "conv2_s1_r2_0_y", "conv2_s1_r2_0_x", "2", "0");
  hcompute_conv2_stencil_3->add_load("hw_kernel2_global_wrapper_stencil", "conv2_s1_r2_0_y", "conv2_s1_r2_0_x", "2", "2");
  hcompute_conv2_stencil_3->add_load("hw_kernel2_global_wrapper_stencil", "conv2_s1_r2_0_y", "conv2_s1_r2_0_x", "2", "1");
  hcompute_conv2_stencil_3->add_store("conv2_stencil", "2", "conv2_s1_y", "conv2_s1_x");

//consuming conv2.stencil
  auto hw_output_s0_w = prg.add_loop("hw_output_s0_w", 0, 3);
  auto hw_output_s0_y_yi = hw_output_s0_w->add_loop("hw_output_s0_y_yi", 0, 28);
  auto hw_output_s0_x_xi = hw_output_s0_y_yi->add_loop("hw_output_s0_x_xi", 0, 28);

//store is: hw_output.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi, hw_output_s0_w) = conv2.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi, hw_output_s0_w)
  auto hcompute_hw_output_stencil = hw_output_s0_x_xi->add_op("op_hcompute_hw_output_stencil");
  hcompute_hw_output_stencil->add_function("hcompute_hw_output_stencil");
  hcompute_hw_output_stencil->add_load("conv2_stencil", "hw_output_s0_w", "hw_output_s0_y_yi", "hw_output_s0_x_xi");
  hcompute_hw_output_stencil->add_store("hw_output_stencil", "hw_output_s0_w", "hw_output_s0_y_yi", "hw_output_s0_x_xi");

  return prg;
}


// empty
