#include "app.h"
#include "ubuffer.h"
#include "codegen.h"
#include "prog.h"

prog brighten_and_blur() {
  prog prg;
  prg.compute_unit_file = "brighten_and_blur_compute.h";
  prg.name = "brighten_and_blur";

// Stencil<uint16_t, 64, 64> &hw_input_stencil = arg_0;
  prg.add_input("hw_input_stencil");
  prg.buffer_port_widths["hw_input_stencil"] = 16;
// Stencil<uint16_t, 63, 63> &hw_output_stencil = arg_1;
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
////producing brighten.stencil
  auto brighten_s0_y = prg.add_loop("brighten_s0_y", 0, 64);
  auto brighten_s0_x = brighten_s0_y->add_loop("brighten_s0_x", 0, 64);

//store is: brighten.stencil(brighten_s0_x, brighten_s0_y) = (hw_input_global_wrapper.stencil(brighten_s0_x, brighten_s0_y)*(uint16)2)
  auto hcompute_brighten_stencil = brighten_s0_x->add_op("op_hcompute_brighten_stencil");
  hcompute_brighten_stencil->add_function("hcompute_brighten_stencil");
  hcompute_brighten_stencil->add_load("hw_input_global_wrapper_stencil", "brighten_s0_y", "brighten_s0_x");
  prg.buffer_port_widths["brighten_stencil"] = 16;
  hcompute_brighten_stencil->add_store("brighten_stencil", "brighten_s0_y", "brighten_s0_x");

//consuming brighten.stencil
////producing blur.stencil
  auto blur_s0_y = prg.add_loop("blur_s0_y", 0, 63);
  auto blur_s0_x = blur_s0_y->add_loop("blur_s0_x", 0, 63);

//store is: blur.stencil(blur_s0_x, blur_s0_y) = (uint16)0
  auto hcompute_blur_stencil = blur_s0_x->add_op("op_hcompute_blur_stencil");
  hcompute_blur_stencil->add_function("hcompute_blur_stencil");
  prg.buffer_port_widths["blur_stencil"] = 16;
  hcompute_blur_stencil->add_store("blur_stencil", "blur_s0_y", "blur_s0_x");
  auto blur_s1_y = prg.add_loop("blur_s1_y", 0, 63);
  auto blur_s1_x = blur_s1_y->add_loop("blur_s1_x", 0, 63);

//store is: blur.stencil(blur_s1_x, blur_s1_y) = (brighten.stencil(blur_s1_x, blur_s1_y) + (blur.stencil(blur_s1_x, blur_s1_y) + (brighten.stencil((blur_s1_x + 1), blur_s1_y) + (brighten.stencil((blur_s1_x + 1), (blur_s1_y + 1)) + brighten.stencil(blur_s1_x, (blur_s1_y + 1))))))
  auto hcompute_blur_stencil_1 = blur_s1_x->add_op("op_hcompute_blur_stencil_1");
  hcompute_blur_stencil_1->add_function("hcompute_blur_stencil_1");
  hcompute_blur_stencil_1->add_load("blur_stencil", "blur_s1_y", "blur_s1_x");
  hcompute_blur_stencil_1->add_load("brighten_stencil", "blur_s1_y", "blur_s1_x");
  hcompute_blur_stencil_1->add_load("brighten_stencil", "blur_s1_y", "(blur_s1_x + 1)");
  hcompute_blur_stencil_1->add_load("brighten_stencil", "(blur_s1_y + 1)", "(blur_s1_x + 1)");
  hcompute_blur_stencil_1->add_load("brighten_stencil", "(blur_s1_y + 1)", "blur_s1_x");
  hcompute_blur_stencil_1->add_store("blur_stencil", "blur_s1_y", "blur_s1_x");

//consuming blur.stencil
  auto hw_output_s0_y_yi = prg.add_loop("hw_output_s0_y_yi", 0, 63);
  auto hw_output_s0_x_xi = hw_output_s0_y_yi->add_loop("hw_output_s0_x_xi", 0, 63);

//store is: hw_output.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi) = (blur.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi)/(uint16)4)
  auto hcompute_hw_output_stencil = hw_output_s0_x_xi->add_op("op_hcompute_hw_output_stencil");
  hcompute_hw_output_stencil->add_function("hcompute_hw_output_stencil");
  hcompute_hw_output_stencil->add_load("blur_stencil", "hw_output_s0_y_yi", "hw_output_s0_x_xi");
  hcompute_hw_output_stencil->add_store("hw_output_stencil", "hw_output_s0_y_yi", "hw_output_s0_x_xi");

  return prg;
}


// empty
