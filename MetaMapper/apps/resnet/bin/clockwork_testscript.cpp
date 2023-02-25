#include "clockwork_testscript.h"
#include "unoptimized_resnet.h"
#include "hw_classes.h"
#include <fstream>
#include <vector>

void run_clockwork_program(RDAI_MemObject **mem_object_list) {
	// input and output memory objects
	uint16_t *hw_input_stencil = (uint16_t*) mem_object_list[0]->host_ptr;
	uint16_t *hw_kernel_stencil = (uint16_t*) mem_object_list[1]->host_ptr;
	uint16_t *hw_output_stencil = (uint16_t*) mem_object_list[2]->host_ptr;

	// input and output stream declarations
	HWStream< hw_uint<16> > hw_input_stencil_stream;
	HWStream< hw_uint<16> > hw_kernel_stencil_stream;
	HWStream< hw_uint<16> > hw_output_stencil_stream;
	int idx = 0;

	// provision input stream hw_input_stencil_stream
	std::vector<uint16_t> hw_input_stencil_stream_tile(4*30*30);   idx=0;
	for (int l2 = 0; l2 < 30; l2++) {
	for (int l1 = 0; l1 < 30; l1++) {
	for (int l0 = 0; l0 < 4; l0++) {
		hw_uint<16> in_val;
		set_at<0, 16, 16>(in_val, hw_uint<16>(hw_input_stencil[((l2*120) + ((l1*4) + l0))]));
		hw_input_stencil_stream.write(in_val);
		hw_input_stencil_stream_tile[idx] = hw_input_stencil[((l2*120) + ((l1*4) + l0))];  idx += 1;
	} } } 
	ofstream hw_input_stencil_file("bin/hw_input_stencil.leraw", ios::binary);
	hw_input_stencil_file.write(reinterpret_cast<const char *>(hw_input_stencil_stream_tile.data()),
		sizeof(hw_input_stencil_stream_tile[0]) * 4 * 30 * 30);
	hw_input_stencil_file.close();

	// provision input stream hw_kernel_stencil_stream
	std::vector<uint16_t> hw_kernel_stencil_stream_tile(4*3*3*3);   idx=0;
	for (int l3 = 0; l3 < 3; l3++) {
	for (int l2 = 0; l2 < 3; l2++) {
	for (int l1 = 0; l1 < 3; l1++) {
	for (int l0 = 0; l0 < 4; l0++) {
		hw_uint<16> in_val;
		set_at<0, 16, 16>(in_val, hw_uint<16>(hw_kernel_stencil[((l3*36) + ((l2*12) + ((l1*4) + l0)))]));
		hw_kernel_stencil_stream.write(in_val);
		hw_kernel_stencil_stream_tile[idx] = hw_kernel_stencil[((l3*36) + ((l2*12) + ((l1*4) + l0)))];  idx += 1;
	} } } } 
	ofstream hw_kernel_stencil_file("bin/hw_kernel_stencil.leraw", ios::binary);
	hw_kernel_stencil_file.write(reinterpret_cast<const char *>(hw_kernel_stencil_stream_tile.data()),
		sizeof(hw_kernel_stencil_stream_tile[0]) * 4 * 3 * 3 * 3);
	hw_kernel_stencil_file.close();


	// invoke clockwork program
	unoptimized_resnet(
		hw_input_stencil_stream,
		hw_kernel_stencil_stream,
		hw_output_stencil_stream
	);

	// provision output buffer
	std::vector<uint16_t> hw_output_stencil_stream_tile(28*28*3);   idx=0;
	for (int l2 = 0; l2 < 3; l2++) {
	for (int l1 = 0; l1 < 28; l1++) {
	for (int l0 = 0; l0 < 28; l0++) {
		hw_uint<16> actual = hw_output_stencil_stream.read();
		int actual_lane = actual.extract<0, 15>();
		hw_output_stencil[((l2*784) + ((l1*28) + l0))] = (uint16_t)(actual_lane);
		hw_output_stencil_stream_tile[idx] = hw_output_stencil[((l2*784) + ((l1*28) + l0))];  idx += 1;
	} } } 
	ofstream hw_output_file("bin/hw_output.leraw", ios::binary);
	hw_output_file.write(reinterpret_cast<const char *>(hw_output_stencil_stream_tile.data()),
		sizeof(hw_output_stencil_stream_tile[0]) * 28 * 28 * 3);
	hw_output_file.close();
	ofstream hw_output_header_file("bin/hw_output_header.txt", ios::binary);
	hw_output_header_file << "P5" << std::endl;
	hw_output_header_file << "28 28 3" << std::endl;
	hw_output_header_file << "65535" << std::endl;
	hw_output_header_file.close();
}

