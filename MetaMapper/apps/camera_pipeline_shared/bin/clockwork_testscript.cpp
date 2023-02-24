#include "clockwork_testscript.h"
#include "unoptimized_camera_pipeline_shared.h"
#include "hw_classes.h"
#include <fstream>
#include <vector>

void run_clockwork_program(RDAI_MemObject **mem_object_list) {
	// input and output memory objects
	int32_t _320 = ((int32_t*) mem_object_list[0]->host_ptr)[0];
	int32_t _321 = ((int32_t*) mem_object_list[1]->host_ptr)[0];
	uint16_t *hw_input_stencil = (uint16_t*) mem_object_list[2]->host_ptr;
	int32_t hw_output_global_wrapper_s0_x_xo = ((int32_t*) mem_object_list[3]->host_ptr)[0];
	uint16_t *hw_output_global_wrapper_stencil = (uint16_t*) mem_object_list[4]->host_ptr;

	// input and output stream declarations
	HWStream< hw_uint<16> > hw_input_stencil_stream;
	HWStream< hw_uint<16> > hw_output_global_wrapper_stencil_stream;
	int idx = 0;

	// provision input stream hw_input_stencil_stream
	std::vector<uint16_t> hw_input_stencil_stream_tile(256*192);   idx=0;
	for (int l1 = _321; l1 < (_321 + 192); l1++) {
	for (int l0 = (hw_output_global_wrapper_s0_x_xo*248); l0 < ((hw_output_global_wrapper_s0_x_xo*248) + 256); l0++) {
		hw_uint<16> in_val;
		set_at<0, 16, 16>(in_val, hw_uint<16>(hw_input_stencil[((l1*4720) + l0)]));
		hw_input_stencil_stream.write(in_val);
		hw_input_stencil_stream_tile[idx] = hw_input_stencil[((l1*4720) + l0)];  idx += 1;
	} } 
	ofstream hw_input_stencil_file("bin/hw_input_stencil.leraw", ios::binary);
	hw_input_stencil_file.write(reinterpret_cast<const char *>(hw_input_stencil_stream_tile.data()),
		sizeof(hw_input_stencil_stream_tile[0]) * 256 * 192);
	hw_input_stencil_file.close();


	// invoke clockwork program
	unoptimized_camera_pipeline_shared(
		hw_input_stencil_stream,
		hw_output_global_wrapper_stencil_stream
	);

	// provision output buffer
	std::vector<uint16_t> hw_output_global_wrapper_stencil_stream_tile(3*248*184);   idx=0;
	for (int l2 = _321; l2 < (_321 + 184); l2++) {
	for (int l1 = (hw_output_global_wrapper_s0_x_xo*248); l1 < ((hw_output_global_wrapper_s0_x_xo*248) + 248); l1++) {
	for (int l0 = 0; l0 < 3; l0++) {
		hw_uint<16> actual = hw_output_global_wrapper_stencil_stream.read();
		int actual_lane = actual.extract<0, 15>();
		hw_output_global_wrapper_stencil[((l2*7440) + ((l1*3) + l0))] = (uint16_t)(actual_lane);
		hw_output_global_wrapper_stencil_stream_tile[idx] = hw_output_global_wrapper_stencil[((l2*7440) + ((l1*3) + l0))];  idx += 1;
	} } } 
	ofstream hw_output_file("bin/hw_output.leraw", ios::binary);
	hw_output_file.write(reinterpret_cast<const char *>(hw_output_global_wrapper_stencil_stream_tile.data()),
		sizeof(hw_output_global_wrapper_stencil_stream_tile[0]) * 3 * 248 * 184);
	hw_output_file.close();
	ofstream hw_output_header_file("bin/hw_output_header.txt", ios::binary);
	hw_output_header_file << "P5" << std::endl;
	hw_output_header_file << "3 248 184" << std::endl;
	hw_output_header_file << "65535" << std::endl;
	hw_output_header_file.close();
}

