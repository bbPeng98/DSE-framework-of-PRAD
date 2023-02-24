)
{
#pragma HLS DATAFLOW
#pragma HLS INLINE region
#pragma HLS INTERFACE s_axilite port=return bundle=config
#pragma HLS INTERFACE s_axilite port=arg_0 bundle=config
#pragma HLS ARRAY_PARTITION variable=arg_0.value complete dim=0
#pragma HLS INTERFACE s_axilite port=arg_1 bundle=config
#pragma HLS ARRAY_PARTITION variable=arg_1.value complete dim=0

 // alias the arguments
 Stencil<uint16_t, 75, 75> &hw_input_stencil = arg_0;
 Stencil<uint16_t, 64, 64> &hw_output_stencil = arg_1;
[, ], [, ] // produce hw_input_global_wrapper.stencil
 for (int hw_input_global_wrapper_s0_y = -7; hw_input_global_wrapper_s0_y < 68; hw_input_global_wrapper_s0_y++)
 {
  for (int hw_input_global_wrapper_s0_x = -7; hw_input_global_wrapper_s0_x < 68; hw_input_global_wrapper_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _404 = _hw_input_global_wrapper_s0_x + 7;
   int32_t _405 = _hw_input_global_wrapper_s0_y + 7;
   uint16_t _406 = _hw_input_stencil(_hw_input_global_wrapper_s0_x, _hw_input_global_wrapper_s0_y);
   _hw_input_global_wrapper_stencil(_404, _405) = _406;
  } // for hw_input_global_wrapper_s0_x
 } // for hw_input_global_wrapper_s0_y
 // consume hw_input_global_wrapper.stencil
[, ], [, ] // produce blur_unnormalized.stencil
 for (int blur_unnormalized_s0_y = -7; blur_unnormalized_s0_y < 66; blur_unnormalized_s0_y++)
 {
  for (int blur_unnormalized_s0_x = -7; blur_unnormalized_s0_x < 66; blur_unnormalized_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _409 = _blur_unnormalized_s0_x + 7;
   int32_t _410 = _blur_unnormalized_s0_y + 7;
   uint16_t _411 = (uint16_t)(0);
   _blur_unnormalized_stencil(_409, _410) = _411;
  } // for blur_unnormalized_s0_x
 } // for blur_unnormalized_s0_y
 for (int blur_unnormalized_s1_y = -7; blur_unnormalized_s1_y < 66; blur_unnormalized_s1_y++)
 {
  for (int blur_unnormalized_s1_x = -7; blur_unnormalized_s1_x < 66; blur_unnormalized_s1_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _454 = _blur_unnormalized_s1_x + 7;
   int32_t _455 = _blur_unnormalized_s1_y + 7;
   uint16_t _456 = _hw_input_global_wrapper_stencil(_454, _455);
   uint16_t _457 = (uint16_t)(3);
   uint16_t _458 = _456 * _457;
   uint16_t _459 = _blur_unnormalized_stencil(_454, _455);
   int32_t _460 = _blur_unnormalized_s1_x + 8;
   uint16_t _461 = _hw_input_global_wrapper_stencil(_460, _455);
   uint16_t _462 = (uint16_t)(21);
   uint16_t _463 = _461 * _462;
   int32_t _464 = _blur_unnormalized_s1_x + 9;
   uint16_t _465 = _hw_input_global_wrapper_stencil(_464, _455);
   uint16_t _466 = _465 * _457;
   int32_t _467 = _blur_unnormalized_s1_y + 8;
   uint16_t _468 = _hw_input_global_wrapper_stencil(_454, _467);
   uint16_t _469 = _468 * _462;
   uint16_t _470 = _hw_input_global_wrapper_stencil(_464, _467);
   uint16_t _471 = (uint16_t)(7);
   uint16_t _472 = _470 * _471;
   int32_t _473 = _blur_unnormalized_s1_y + 9;
   uint16_t _474 = _hw_input_global_wrapper_stencil(_454, _473);
   uint16_t _475 = _hw_input_global_wrapper_stencil(_464, _473);
   uint16_t _476 = _hw_input_global_wrapper_stencil(_460, _473);
   uint16_t _477 = _476 * _471;
   uint16_t _478 = _475 + _477;
   uint16_t _479 = _474 + _478;
   uint16_t _480 = _472 + _479;
   uint16_t _481 = _480 * _457;
   uint16_t _482 = _hw_input_global_wrapper_stencil(_460, _467);
   uint16_t _483 = (uint16_t)(158);
   uint16_t _484 = _482 * _483;
   uint16_t _485 = _481 + _484;
   uint16_t _486 = _469 + _485;
   uint16_t _487 = _466 + _486;
   uint16_t _488 = _463 + _487;
   uint16_t _489 = _459 + _488;
   uint16_t _490 = _458 + _489;
   _blur_unnormalized_stencil(_454, _455) = _490;
  } // for blur_unnormalized_s1_x
 } // for blur_unnormalized_s1_y
 // consume blur_unnormalized.stencil
[, ], [, ] // produce l0$0.stencil
 for (int l0_0_s0_y = -6; l0_0_s0_y < 67; l0_0_s0_y++)
 {
  for (int l0_0_s0_x = -6; l0_0_s0_x < 67; l0_0_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _495 = _l0_0_s0_x + 6;
   int32_t _496 = _l0_0_s0_y + 6;
   uint16_t _497 = _blur_unnormalized_stencil(_495, _496);
   uint16_t _498 = (uint16_t)(8);
   uint16_t _499 = _497 >> _498;
   _l0_0_stencil(_495, _496) = _499;
  } // for l0_0_s0_x
 } // for l0_0_s0_y
 // consume l0$0.stencil
[, ], [, ] // produce h0$0.stencil
 for (int h0_0_s0_y = 0; h0_0_s0_y < 64; h0_0_s0_y++)
 {
  for (int h0_0_s0_x = 0; h0_0_s0_x < 64; h0_0_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _502 = _h0_0_s0_x + 7;
   int32_t _503 = _h0_0_s0_y + 7;
   uint16_t _504 = _hw_input_global_wrapper_stencil(_502, _503);
   int32_t _505 = _h0_0_s0_x + 6;
   int32_t _506 = _h0_0_s0_y + 6;
   uint16_t _507 = _l0_0_stencil(_505, _506);
   uint16_t _508 = _504 - _507;
   _h0_0_stencil(_h0_0_s0_x, _h0_0_s0_y) = _508;
  } // for h0_0_s0_x
 } // for h0_0_s0_y
 // consume h0$0.stencil
[, ], [, ] // produce f1$0.stencil
 for (int f1_0_s0_y = -3; f1_0_s0_y < 34; f1_0_s0_y++)
 {
  for (int f1_0_s0_x = -3; f1_0_s0_x < 34; f1_0_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _509 = _f1_0_s0_x + 3;
   int32_t _510 = _f1_0_s0_y + 3;
   int32_t _511 = _f1_0_s0_x * 2;
   int32_t _512 = _511 + 6;
   int32_t _513 = _f1_0_s0_y * 2;
   int32_t _514 = _513 + 6;
   uint16_t _515 = _l0_0_stencil(_512, _514);
   _f1_0_stencil(_509, _510) = _515;
  } // for f1_0_s0_x
 } // for f1_0_s0_y
 // consume f1$0.stencil
[, ], [, ] // produce f1_blur_unnormalized.stencil
 for (int f1_blur_unnormalized_s0_y = -3; f1_blur_unnormalized_s0_y < 32; f1_blur_unnormalized_s0_y++)
 {
  for (int f1_blur_unnormalized_s0_x = -3; f1_blur_unnormalized_s0_x < 32; f1_blur_unnormalized_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _518 = _f1_blur_unnormalized_s0_x + 3;
   int32_t _519 = _f1_blur_unnormalized_s0_y + 3;
   uint16_t _520 = (uint16_t)(0);
   _f1_blur_unnormalized_stencil(_518, _519) = _520;
  } // for f1_blur_unnormalized_s0_x
 } // for f1_blur_unnormalized_s0_y
 for (int f1_blur_unnormalized_s1_y = -3; f1_blur_unnormalized_s1_y < 32; f1_blur_unnormalized_s1_y++)
 {
  for (int f1_blur_unnormalized_s1_x = -3; f1_blur_unnormalized_s1_x < 32; f1_blur_unnormalized_s1_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _563 = _f1_blur_unnormalized_s1_x + 3;
   int32_t _564 = _f1_blur_unnormalized_s1_y + 3;
   uint16_t _565 = _f1_0_stencil(_563, _564);
   uint16_t _566 = (uint16_t)(3);
   uint16_t _567 = _565 * _566;
   uint16_t _568 = _f1_blur_unnormalized_stencil(_563, _564);
   int32_t _569 = _f1_blur_unnormalized_s1_x + 4;
   uint16_t _570 = _f1_0_stencil(_569, _564);
   uint16_t _571 = (uint16_t)(21);
   uint16_t _572 = _570 * _571;
   int32_t _573 = _f1_blur_unnormalized_s1_x + 5;
   uint16_t _574 = _f1_0_stencil(_573, _564);
   uint16_t _575 = _574 * _566;
   int32_t _576 = _f1_blur_unnormalized_s1_y + 4;
   uint16_t _577 = _f1_0_stencil(_563, _576);
   uint16_t _578 = _577 * _571;
   uint16_t _579 = _f1_0_stencil(_573, _576);
   uint16_t _580 = (uint16_t)(7);
   uint16_t _581 = _579 * _580;
   int32_t _582 = _f1_blur_unnormalized_s1_y + 5;
   uint16_t _583 = _f1_0_stencil(_563, _582);
   uint16_t _584 = _f1_0_stencil(_573, _582);
   uint16_t _585 = _f1_0_stencil(_569, _582);
   uint16_t _586 = _585 * _580;
   uint16_t _587 = _584 + _586;
   uint16_t _588 = _583 + _587;
   uint16_t _589 = _581 + _588;
   uint16_t _590 = _589 * _566;
   uint16_t _591 = _f1_0_stencil(_569, _576);
   uint16_t _592 = (uint16_t)(158);
   uint16_t _593 = _591 * _592;
   uint16_t _594 = _590 + _593;
   uint16_t _595 = _578 + _594;
   uint16_t _596 = _575 + _595;
   uint16_t _597 = _572 + _596;
   uint16_t _598 = _568 + _597;
   uint16_t _599 = _567 + _598;
   _f1_blur_unnormalized_stencil(_563, _564) = _599;
  } // for f1_blur_unnormalized_s1_x
 } // for f1_blur_unnormalized_s1_y
 // consume f1_blur_unnormalized.stencil
[, ], [, ] // produce l1$0.stencil
 for (int l1_0_s0_y = -2; l1_0_s0_y < 33; l1_0_s0_y++)
 {
  for (int l1_0_s0_x = -2; l1_0_s0_x < 33; l1_0_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _604 = _l1_0_s0_x + 2;
   int32_t _605 = _l1_0_s0_y + 2;
   uint16_t _606 = _f1_blur_unnormalized_stencil(_604, _605);
   uint16_t _607 = (uint16_t)(8);
   uint16_t _608 = _606 >> _607;
   _l1_0_stencil(_604, _605) = _608;
  } // for l1_0_s0_x
 } // for l1_0_s0_y
 // consume l1$0.stencil
[, ], [, ] // produce h1$0.stencil
 for (int h1_0_s0_y = -1; h1_0_s0_y < 33; h1_0_s0_y++)
 {
  for (int h1_0_s0_x = -1; h1_0_s0_x < 33; h1_0_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _611 = _h1_0_s0_x + 1;
   int32_t _612 = _h1_0_s0_y + 1;
   int32_t _613 = _h1_0_s0_x + 3;
   int32_t _614 = _h1_0_s0_y + 3;
   uint16_t _615 = _f1_0_stencil(_613, _614);
   int32_t _616 = _h1_0_s0_x + 2;
   int32_t _617 = _h1_0_s0_y + 2;
   uint16_t _618 = _l1_0_stencil(_616, _617);
   uint16_t _619 = _615 - _618;
   _h1_0_stencil(_611, _612) = _619;
  } // for h1_0_s0_x
 } // for h1_0_s0_y
 // consume h1$0.stencil
[, ], [, ] // produce f2$0.stencil
 for (int f2_0_s0_y = -1; f2_0_s0_y < 17; f2_0_s0_y++)
 {
  for (int f2_0_s0_x = -1; f2_0_s0_x < 17; f2_0_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _620 = _f2_0_s0_x + 1;
   int32_t _621 = _f2_0_s0_y + 1;
   int32_t _622 = _f2_0_s0_x * 2;
   int32_t _623 = _622 + 2;
   int32_t _624 = _f2_0_s0_y * 2;
   int32_t _625 = _624 + 2;
   uint16_t _626 = _l1_0_stencil(_623, _625);
   _f2_0_stencil(_620, _621) = _626;
  } // for f2_0_s0_x
 } // for f2_0_s0_y
 // consume f2$0.stencil
[, ], [, ] // produce f2_temp.stencil
 for (int f2_temp_s0_y = -2; f2_temp_s0_y < 34; f2_temp_s0_y++)
 {
  for (int f2_temp_s0_x = -2; f2_temp_s0_x < 34; f2_temp_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _627 = _f2_temp_s0_x + 2;
   int32_t _628 = _f2_temp_s0_y + 2;
   int32_t _629 = _f2_temp_s0_x >> 1;
   int32_t _630 = _629 + 1;
   int32_t _631 = _f2_temp_s0_y >> 1;
   int32_t _632 = _631 + 1;
   uint16_t _633 = _f2_0_stencil(_630, _632);
   _f2_temp_stencil(_627, _628) = _633;
  } // for f2_temp_s0_x
 } // for f2_temp_s0_y
 // consume f2_temp.stencil
[, ], [, ] // produce f2_temp_blur_unnormalized.stencil
 for (int f2_temp_blur_unnormalized_s0_y = -2; f2_temp_blur_unnormalized_s0_y < 32; f2_temp_blur_unnormalized_s0_y++)
 {
  for (int f2_temp_blur_unnormalized_s0_x = -2; f2_temp_blur_unnormalized_s0_x < 32; f2_temp_blur_unnormalized_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _636 = _f2_temp_blur_unnormalized_s0_x + 2;
   int32_t _637 = _f2_temp_blur_unnormalized_s0_y + 2;
   uint16_t _638 = (uint16_t)(0);
   _f2_temp_blur_unnormalized_stencil(_636, _637) = _638;
  } // for f2_temp_blur_unnormalized_s0_x
 } // for f2_temp_blur_unnormalized_s0_y
 for (int f2_temp_blur_unnormalized_s1_y = -2; f2_temp_blur_unnormalized_s1_y < 32; f2_temp_blur_unnormalized_s1_y++)
 {
  for (int f2_temp_blur_unnormalized_s1_x = -2; f2_temp_blur_unnormalized_s1_x < 32; f2_temp_blur_unnormalized_s1_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _681 = _f2_temp_blur_unnormalized_s1_x + 2;
   int32_t _682 = _f2_temp_blur_unnormalized_s1_y + 2;
   uint16_t _683 = _f2_temp_stencil(_681, _682);
   uint16_t _684 = (uint16_t)(3);
   uint16_t _685 = _683 * _684;
   uint16_t _686 = _f2_temp_blur_unnormalized_stencil(_681, _682);
   int32_t _687 = _f2_temp_blur_unnormalized_s1_x + 3;
   uint16_t _688 = _f2_temp_stencil(_687, _682);
   uint16_t _689 = (uint16_t)(21);
   uint16_t _690 = _688 * _689;
   int32_t _691 = _f2_temp_blur_unnormalized_s1_x + 4;
   uint16_t _692 = _f2_temp_stencil(_691, _682);
   uint16_t _693 = _692 * _684;
   int32_t _694 = _f2_temp_blur_unnormalized_s1_y + 3;
   uint16_t _695 = _f2_temp_stencil(_681, _694);
   uint16_t _696 = _695 * _689;
   uint16_t _697 = _f2_temp_stencil(_691, _694);
   uint16_t _698 = (uint16_t)(7);
   uint16_t _699 = _697 * _698;
   int32_t _700 = _f2_temp_blur_unnormalized_s1_y + 4;
   uint16_t _701 = _f2_temp_stencil(_681, _700);
   uint16_t _702 = _f2_temp_stencil(_691, _700);
   uint16_t _703 = _f2_temp_stencil(_687, _700);
   uint16_t _704 = _703 * _698;
   uint16_t _705 = _702 + _704;
   uint16_t _706 = _701 + _705;
   uint16_t _707 = _699 + _706;
   uint16_t _708 = _707 * _684;
   uint16_t _709 = _f2_temp_stencil(_687, _694);
   uint16_t _710 = (uint16_t)(158);
   uint16_t _711 = _709 * _710;
   uint16_t _712 = _708 + _711;
   uint16_t _713 = _696 + _712;
   uint16_t _714 = _693 + _713;
   uint16_t _715 = _690 + _714;
   uint16_t _716 = _686 + _715;
   uint16_t _717 = _685 + _716;
   _f2_temp_blur_unnormalized_stencil(_681, _682) = _717;
  } // for f2_temp_blur_unnormalized_s1_x
 } // for f2_temp_blur_unnormalized_s1_y
 // consume f2_temp_blur_unnormalized.stencil
[, ], [, ] // produce l1_up.stencil
 for (int l1_up_s0_y = -1; l1_up_s0_y < 33; l1_up_s0_y++)
 {
  for (int l1_up_s0_x = -1; l1_up_s0_x < 33; l1_up_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _722 = _l1_up_s0_x + 1;
   int32_t _723 = _l1_up_s0_y + 1;
   uint16_t _724 = _f2_temp_blur_unnormalized_stencil(_722, _723);
   uint16_t _725 = (uint16_t)(8);
   uint16_t _726 = _724 >> _725;
   _l1_up_stencil(_722, _723) = _726;
  } // for l1_up_s0_x
 } // for l1_up_s0_y
 // consume l1_up.stencil
[, ], [, ] // produce f1_up.stencil
 for (int f1_up_s0_y = -1; f1_up_s0_y < 33; f1_up_s0_y++)
 {
  for (int f1_up_s0_x = -1; f1_up_s0_x < 33; f1_up_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _729 = _f1_up_s0_x + 1;
   int32_t _730 = _f1_up_s0_y + 1;
   uint16_t _731 = _l1_up_stencil(_729, _730);
   uint16_t _732 = _h1_0_stencil(_729, _730);
   uint16_t _733 = _731 + _732;
   _f1_up_stencil(_729, _730) = _733;
  } // for f1_up_s0_x
 } // for f1_up_s0_y
 // consume f1_up.stencil
[, ], [, ] // produce f1_temp.stencil
 for (int f1_temp_s0_y = -1; f1_temp_s0_y < 65; f1_temp_s0_y++)
 {
  for (int f1_temp_s0_x = -1; f1_temp_s0_x < 65; f1_temp_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _734 = _f1_temp_s0_x + 1;
   int32_t _735 = _f1_temp_s0_y + 1;
   int32_t _736 = _f1_temp_s0_x >> 1;
   int32_t _737 = _736 + 1;
   int32_t _738 = _f1_temp_s0_y >> 1;
   int32_t _739 = _738 + 1;
   uint16_t _740 = _f1_up_stencil(_737, _739);
   _f1_temp_stencil(_734, _735) = _740;
  } // for f1_temp_s0_x
 } // for f1_temp_s0_y
 // consume f1_temp.stencil
[, ], [, ] // produce f1_temp_blur_unnormalized.stencil
 for (int f1_temp_blur_unnormalized_s0_y = -1; f1_temp_blur_unnormalized_s0_y < 63; f1_temp_blur_unnormalized_s0_y++)
 {
  for (int f1_temp_blur_unnormalized_s0_x = -1; f1_temp_blur_unnormalized_s0_x < 63; f1_temp_blur_unnormalized_s0_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _743 = _f1_temp_blur_unnormalized_s0_x + 1;
   int32_t _744 = _f1_temp_blur_unnormalized_s0_y + 1;
   uint16_t _745 = (uint16_t)(0);
   _f1_temp_blur_unnormalized_stencil(_743, _744) = _745;
  } // for f1_temp_blur_unnormalized_s0_x
 } // for f1_temp_blur_unnormalized_s0_y
 for (int f1_temp_blur_unnormalized_s1_y = -1; f1_temp_blur_unnormalized_s1_y < 63; f1_temp_blur_unnormalized_s1_y++)
 {
  for (int f1_temp_blur_unnormalized_s1_x = -1; f1_temp_blur_unnormalized_s1_x < 63; f1_temp_blur_unnormalized_s1_x++)
  {
#pragma HLS PIPELINE II=1
   int32_t _788 = _f1_temp_blur_unnormalized_s1_x + 1;
   int32_t _789 = _f1_temp_blur_unnormalized_s1_y + 1;
   uint16_t _790 = _f1_temp_stencil(_788, _789);
   uint16_t _791 = (uint16_t)(3);
   uint16_t _792 = _790 * _791;
   uint16_t _793 = _f1_temp_blur_unnormalized_stencil(_788, _789);
   int32_t _794 = _f1_temp_blur_unnormalized_s1_x + 2;
   uint16_t _795 = _f1_temp_stencil(_794, _789);
   uint16_t _796 = (uint16_t)(21);
   uint16_t _797 = _795 * _796;
   int32_t _798 = _f1_temp_blur_unnormalized_s1_x + 3;
   uint16_t _799 = _f1_temp_stencil(_798, _789);
   uint16_t _800 = _799 * _791;
   int32_t _801 = _f1_temp_blur_unnormalized_s1_y + 2;
   uint16_t _802 = _f1_temp_stencil(_788, _801);
   uint16_t _803 = _802 * _796;
   uint16_t _804 = _f1_temp_stencil(_798, _801);
   uint16_t _805 = (uint16_t)(7);
   uint16_t _806 = _804 * _805;
   int32_t _807 = _f1_temp_blur_unnormalized_s1_y + 3;
   uint16_t _808 = _f1_temp_stencil(_788, _807);
   uint16_t _809 = _f1_temp_stencil(_798, _807);
   uint16_t _810 = _f1_temp_stencil(_794, _807);
   uint16_t _811 = _810 * _805;
   uint16_t _812 = _809 + _811;
   uint16_t _813 = _808 + _812;
   uint16_t _814 = _806 + _813;
   uint16_t _815 = _814 * _791;
   uint16_t _816 = _f1_temp_stencil(_794, _801);
   uint16_t _817 = (uint16_t)(158);
   uint16_t _818 = _816 * _817;
   uint16_t _819 = _815 + _818;
   uint16_t _820 = _803 + _819;
   uint16_t _821 = _800 + _820;
   uint16_t _822 = _797 + _821;
   uint16_t _823 = _793 + _822;
   uint16_t _824 = _792 + _823;
   _f1_temp_blur_unnormalized_stencil(_788, _789) = _824;
  } // for f1_temp_blur_unnormalized_s1_x
 } // for f1_temp_blur_unnormalized_s1_y
 // consume f1_temp_blur_unnormalized.stencil
[, ], [, ] // produce l0_up.stencil
 for (int l0_up_s0_y = 0; l0_up_s0_y < 64; l0_up_s0_y++)
 {
  for (int l0_up_s0_x = 0; l0_up_s0_x < 64; l0_up_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _829 = _f1_temp_blur_unnormalized_stencil(_l0_up_s0_x, _l0_up_s0_y);
   uint16_t _830 = (uint16_t)(8);
   uint16_t _831 = _829 >> _830;
   _l0_up_stencil(_l0_up_s0_x, _l0_up_s0_y) = _831;
  } // for l0_up_s0_x
 } // for l0_up_s0_y
 // consume l0_up.stencil
[, ], [, ] // produce f0_up.stencil
 for (int f0_up_s0_y = 0; f0_up_s0_y < 64; f0_up_s0_y++)
 {
  for (int f0_up_s0_x = 0; f0_up_s0_x < 64; f0_up_s0_x++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _834 = _l0_up_stencil(_f0_up_s0_x, _f0_up_s0_y);
   uint16_t _835 = _h0_0_stencil(_f0_up_s0_x, _f0_up_s0_y);
   uint16_t _836 = _834 + _835;
   _f0_up_stencil(_f0_up_s0_x, _f0_up_s0_y) = _836;
  } // for f0_up_s0_x
 } // for f0_up_s0_y
 // consume f0_up.stencil
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 64; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 64; hw_output_s0_x_xi++)
  {
#pragma HLS PIPELINE II=1
   uint16_t _837 = _f0_up_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi);
   _hw_output_stencil(_hw_output_s0_x_xi, _hw_output_s0_y_yi) = _837;
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
} // kernel hls_targetlaplacian_pyramid

