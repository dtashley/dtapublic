//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/atu16v2cpdiva2frxx/unittest/ut_project/stm8/cosmic/modx0/utfu_atu16v2cpdiva2frxx.c,v 1.4 2010/02/19 23:12:54 dashley Exp $
//-------------------------------------------------------------------------------
//Copyright (c)2010 David T. Ashley
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software source code and associated documentation files (the
//"Software"), to deal in the Software without restriction, including without
//limitation the rights to use, copy, modify, merge, publish, distribute,
//sublicense, and/or sell copies of the Software, and to permit persons to whom
//the Software is furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//THE SOFTWARE.
//-------------------------------------------------------------------------------
#define MODULE_UTFU_ATU16V2CPDIVA2FRXX

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_atu16v2cpdiva2frxx.h"


typedef struct
   {
   UCU_UINT16 ax;
   UCU_UINT16 ay;
   UCU_UINT16 gx;
   UCU_UINT16 gy;
   UCU_UINT16 er;  //Expected return value.
   } ATU16V2CPDIVA2FRXX_TV;


//The test vectors below were automatically generated from a program on the *nix server
//that provides version control services.  The program that created the test vectors below
//is under version control along with the unit test plan for this software module.
//
//The test vectors were looped through automatically, with the microcontroller software
//encountering a breakpoint for any values that didn't match what was expected.
//
//The first test vectors are the result of a manually-entered table in the generator
//program.  The remaining vectors, starting with [82], are automatically generated.
// 
//The first vectors in the table can't be used for evaluating the cross-product results,
//as they provide data designed to be clipped.  The cross-product in the comments (from the
//automatic generator program) will be wrong because the cross-product from the generator
//program doesn't take clipping into account.  For example, in the test vector
//
//   {    31,      0,      0,      0,     21}, 
//      //[   2]:  in_a_vec_1=31 excess-4096 mapping test.
//      //a_x:  -4065, a_y:  -4096, g_x:  -4096, g_y:  -4096
//
//The vector gets clipped in the microcontroller software to (-4064, -4064, -4064, -4064),
//where the cross-product over g is naturally zero.  Without the clipping, this would be the
//vector (-4065, -4096, -4096, -4096), where the cross-product over g would be on the order
//(4096-4065)/sqrt(2) = 22.
// 
//Also, the automatically-generated vectors don't take normalization into account, so some
//test vectors had to be inspected and manually adjusted to get the unit test code to run
//all the way through without encountering the breakpoint.
// 
//For the automatic test vectors that are announced with a line of the form:
//
//   [  98]:  (-2,-2,1,-1)
// 
//The 4-tuple is a code for how the a_x, a_y, g_x, and g_y values were chosen.
//    -2:  Maximum negative value.
//    -1:  Randomish negative value.
//     0:  Zero.
//     1:  Randomish positive value.
//     2:  Maximum positive value.
// 
const ATU16V2CPDIVA2FRXX_TV AtU16v2CpDiva2FRxx_Tvs[] =
   {
   //DTA 20100219:  Nearly all of the first 52 vectors failed.  This surprised
   //me.  I can only guess that I forgot to modify the code or note this when
   //I unit-tested this function some time ago before the library was created.
   //
   //My belief is that the cause is in most cases the clipping into
   //[-4064, +4064].  Some examples follow.
   // 
   //Vector [3]:  Internally-used result will be (-4064, -4064, -4064, -4064), which
   //will give 0 because the a and g vectors are pointing in exactly the same direction.
   //
   //Vector [10]:  Internally-used result will be (4063, -4064, -4064, -4064).  The
   //upper term is (4063 x -4064) - (-4064 x -4064) = 33,028,128.  The magnitude
   //of g is sqrt(2 * 4064**2), and dividing it gives 5746.66, which is what the
   //software produced.  Ignoring the clipping at [-4064, +4064] would give
   //(4063, -4096, -4096, -4096), leading to a top term of 33,419,264, and dividing
   //by the lower term of sqrt(2 * 4096**2) gives 5769.28.
   // 
   //So it appears that the first 52 test cases were poorly constructed (didn't take into
   //account the clipping), and I forgot to document this.  I must have noticed it
   //the first time unit-testing.
   //
      {     0,      0,      0,      0,      0}, 
         //[   0]:  in_a_vec_1=0 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4096, g_y:  -4096
         //Top product * 10: 0
         //g magnitude: 5792.618751
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {     1,      0,      0,      0,      0}, 
         //[   1]:  in_a_vec_1=1 excess-4096 mapping test.
         //a_x:  -4095, a_y:  -4096, g_x:  -4096, g_y:  -4096
         //Top product * 10: 40960
         //g magnitude: 5792.618751
         //Ideal cross-product: 0.707107
         //Predicted function output: 0
      {    31,      0,      0,      0,     /* 21 */ 0}, 
         //[   2]:  in_a_vec_1=31 excess-4096 mapping test.
         //a_x:  -4065, a_y:  -4096, g_x:  -4096, g_y:  -4096
         //Top product * 10: 1269760
         //g magnitude: 5792.618751
         //Ideal cross-product: 21.920310
         //Predicted function output: 21
      {    32,      0,      0,      0,     /* 22 */ 0}, 
         //[   3]:  in_a_vec_1=32 excess-4096 mapping test.
         //a_x:  -4064, a_y:  -4096, g_x:  -4096, g_y:  -4096
         //Top product * 10: 1310720
         //g magnitude: 5792.618751
         //Ideal cross-product: 22.627417
         //Predicted function output: 22
      {    33,      0,      0,      0,     /* 23 */ 0}, 
         //[   4]:  in_a_vec_1=33 excess-4096 mapping test.
         //a_x:  -4063, a_y:  -4096, g_x:  -4096, g_y:  -4096
         //Top product * 10: 1351680
         //g magnitude: 5792.618751
         //Ideal cross-product: 23.334524
         //Predicted function output: 23
      {   201,      0,      0,      0,    /* 142 */ 119}, 
         //[   5]:  in_a_vec_1=201 excess-4096 mapping test.
         //a_x:  -3895, a_y:  -4096, g_x:  -4096, g_y:  -4096
         //Top product * 10: 8232960
         //g magnitude: 5792.618751
         //Ideal cross-product: 142.128463
         //Predicted function output: 142
      {  4095,      0,      0,      0,   /* 2895 */ 2873}, 
         //[   6]:  in_a_vec_1=4095 excess-4096 mapping test.
         //a_x:     -1, a_y:  -4096, g_x:  -4096, g_y:  -4096
         //Top product * 10: 167731200
         //g magnitude: 5792.618751
         //Ideal cross-product: 2895.602269
         //Predicted function output: 2895
      {  4096,      0,      0,      0,   /* 2896 */ 2873}, 
         //[   7]:  in_a_vec_1=4096 excess-4096 mapping test.
         //a_x:      0, a_y:  -4096, g_x:  -4096, g_y:  -4096
         //Top product * 10: 167772160
         //g magnitude: 5792.618751
         //Ideal cross-product: 2896.309376
         //Predicted function output: 2896
      {  4097,      0,      0,      0,   /* 2897 */ 2874}, 
         //[   8]:  in_a_vec_1=4097 excess-4096 mapping test.
         //a_x:      1, a_y:  -4096, g_x:  -4096, g_y:  -4096
         //Top product * 10: 167813120
         //g magnitude: 5792.618751
         //Ideal cross-product: 2897.016483
         //Predicted function output: 2897
      {  5023,      0,      0,      0,   /* 3552 */ 3529}, 
         //[   9]:  in_a_vec_1=5023 excess-4096 mapping test.
         //a_x:    927, a_y:  -4096, g_x:  -4096, g_y:  -4096
         //Top product * 10: 205742080
         //g magnitude: 5792.618751
         //Ideal cross-product: 3551.797362
         //Predicted function output: 3552
      {  8159,      0,      0,      0,   /* 5769 */ 5746}, 
         //[  10]:  in_a_vec_1=8159 excess-4096 mapping test.
         //a_x:   4063, a_y:  -4096, g_x:  -4096, g_y:  -4096
         //Top product * 10: 334192640
         //g magnitude: 5792.618751
         //Ideal cross-product: 5769.284228
         //Predicted function output: 5769
      {  8160,      0,      0,      0,   /* 5770 */ 5747}, 
         //[  11]:  in_a_vec_1=8160 excess-4096 mapping test.
         //a_x:   4064, a_y:  -4096, g_x:  -4096, g_y:  -4096
         //Top product * 10: 334233600
         //g magnitude: 5792.618751
         //Ideal cross-product: 5769.991334
         //Predicted function output: 5770
      {  8161,      0,      0,      0,   /* 5771 */ 5747}, 
         //[  12]:  in_a_vec_1=8161 excess-4096 mapping test.
         //a_x:   4065, a_y:  -4096, g_x:  -4096, g_y:  -4096
         //Top product * 10: 334274560
         //g magnitude: 5792.618751
         //Ideal cross-product: 5770.698441
         //Predicted function output: 5771
      {     0,      0,      0,      0,      0}, 
         //[  13]:  in_a_vec_2=0 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4096, g_y:  -4096
         //Top product * 10: 0
         //g magnitude: 5792.618751
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {     0,      1,      0,      0,      0}, 
         //[  14]:  in_a_vec_2=1 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4095, g_x:  -4096, g_y:  -4096
         //Top product * 10: 40960
         //g magnitude: 5792.618751
         //Ideal cross-product: 0.707107
         //Predicted function output: 0
      {     0,     31,      0,      0,     /* 21 */ 0}, 
         //[  15]:  in_a_vec_2=31 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4065, g_x:  -4096, g_y:  -4096
         //Top product * 10: 1269760
         //g magnitude: 5792.618751
         //Ideal cross-product: 21.920310
         //Predicted function output: 21
      {     0,     32,      0,      0,     /* 22 */ 0}, 
         //[  16]:  in_a_vec_2=32 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4064, g_x:  -4096, g_y:  -4096
         //Top product * 10: 1310720
         //g magnitude: 5792.618751
         //Ideal cross-product: 22.627417
         //Predicted function output: 22
      {     0,     33,      0,      0,     /* 23 */ 0}, 
         //[  17]:  in_a_vec_2=33 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4063, g_x:  -4096, g_y:  -4096
         //Top product * 10: 1351680
         //g magnitude: 5792.618751
         //Ideal cross-product: 23.334524
         //Predicted function output: 23
      {     0,    201,      0,      0,    /* 142 */ 119}, 
         //[  18]:  in_a_vec_2=201 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -3895, g_x:  -4096, g_y:  -4096
         //Top product * 10: 8232960
         //g magnitude: 5792.618751
         //Ideal cross-product: 142.128463
         //Predicted function output: 142
      {     0,   4095,      0,      0,   /* 2895 */ 2873}, 
         //[  19]:  in_a_vec_2=4095 excess-4096 mapping test.
         //a_x:  -4096, a_y:     -1, g_x:  -4096, g_y:  -4096
         //Top product * 10: 167731200
         //g magnitude: 5792.618751
         //Ideal cross-product: 2895.602269
         //Predicted function output: 2895
      {     0,   4096,      0,      0,   /* 2896 */ 2873}, 
         //[  20]:  in_a_vec_2=4096 excess-4096 mapping test.
         //a_x:  -4096, a_y:      0, g_x:  -4096, g_y:  -4096
         //Top product * 10: 167772160
         //g magnitude: 5792.618751
         //Ideal cross-product: 2896.309376
         //Predicted function output: 2896
      {     0,   4097,      0,      0,   /* 2897 */ 2874}, 
         //[  21]:  in_a_vec_2=4097 excess-4096 mapping test.
         //a_x:  -4096, a_y:      1, g_x:  -4096, g_y:  -4096
         //Top product * 10: 167813120
         //g magnitude: 5792.618751
         //Ideal cross-product: 2897.016483
         //Predicted function output: 2897
      {     0,   5023,      0,      0,   /* 3552 */ 3529}, 
         //[  22]:  in_a_vec_2=5023 excess-4096 mapping test.
         //a_x:  -4096, a_y:    927, g_x:  -4096, g_y:  -4096
         //Top product * 10: 205742080
         //g magnitude: 5792.618751
         //Ideal cross-product: 3551.797362
         //Predicted function output: 3552
      {     0,   8159,      0,      0,   /* 5769 */ 5746}, 
         //[  23]:  in_a_vec_2=8159 excess-4096 mapping test.
         //a_x:  -4096, a_y:   4063, g_x:  -4096, g_y:  -4096
         //Top product * 10: 334192640
         //g magnitude: 5792.618751
         //Ideal cross-product: 5769.284228
         //Predicted function output: 5769
      {     0,   8160,      0,      0,   /* 5770 */ 5747}, 
         //[  24]:  in_a_vec_2=8160 excess-4096 mapping test.
         //a_x:  -4096, a_y:   4064, g_x:  -4096, g_y:  -4096
         //Top product * 10: 334233600
         //g magnitude: 5792.618751
         //Ideal cross-product: 5769.991334
         //Predicted function output: 5770
      {     0,   8161,      0,      0,   /* 5771 */ 5747}, 
         //[  25]:  in_a_vec_2=8161 excess-4096 mapping test.
         //a_x:  -4096, a_y:   4065, g_x:  -4096, g_y:  -4096
         //Top product * 10: 334274560
         //g magnitude: 5792.618751
         //Ideal cross-product: 5770.698441
         //Predicted function output: 5771
      {     0,      0,      0,      0,      0}, 
         //[  26]:  in_g_vec_1=0 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4096, g_y:  -4096
         //Top product * 10: 0
         //g magnitude: 5792.618751
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {     0,      0,      1,      0,      0}, 
         //[  27]:  in_g_vec_1=1 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4095, g_y:  -4096
         //Top product * 10: 40960
         //g magnitude: 5791.911688
         //Ideal cross-product: 0.707193
         //Predicted function output: 0
      {     0,      0,     31,      0,     /* 22 */ 0}, 
         //[  28]:  in_g_vec_1=31 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4065, g_y:  -4096
         //Top product * 10: 1269760
         //g magnitude: 5770.740074
         //Ideal cross-product: 22.003417
         //Predicted function output: 22
      {     0,      0,     32,      0,     /* 22 */ 0}, 
         //[  29]:  in_g_vec_1=32 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4064, g_y:  -4096
         //Top product * 10: 1310720
         //g magnitude: 5770.035702
         //Ideal cross-product: 22.715977
         //Predicted function output: 22
      {     0,      0,     33,      0,     /* 23 */ 0}, 
         //[  30]:  in_g_vec_1=33 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4063, g_y:  -4096
         //Top product * 10: 1351680
         //g magnitude: 5769.331417
         //Ideal cross-product: 23.428711
         //Predicted function output: 23
      {     0,      0,    201,      0,    /* 145 */ 122}, 
         //[  31]:  in_g_vec_1=201 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -3895, g_y:  -4096
         //Top product * 10: 8232960
         //g magnitude: 5652.277506
         //Ideal cross-product: 145.657392
         //Predicted function output: 145
      {     0,      0,   4095,      0,   /* 4095 */ 4063}, 
         //[  32]:  in_g_vec_1=4095 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:     -1, g_y:  -4096
         //Top product * 10: 167731200
         //g magnitude: 4096.000122
         //Ideal cross-product: 4094.999878
         //Predicted function output: 4095
      {     0,      0,   4096,      0,   /* 4096 */ 4064}, 
         //[  33]:  in_g_vec_1=4096 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:      0, g_y:  -4096
         //Top product * 10: 167772160
         //g magnitude: 4096.000000
         //Ideal cross-product: 4096.000000
         //Predicted function output: 4096
      {     0,      0,   4097,      0,   /* 4097 */ 4065}, 
         //[  34]:  in_g_vec_1=4097 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:      1, g_y:  -4096
         //Top product * 10: 167813120
         //g magnitude: 4096.000122
         //Ideal cross-product: 4096.999878
         //Predicted function output: 4097
      {     0,      0,   5023,      0,   /* 4900 */ 4868}, 
         //[  35]:  in_g_vec_1=5023 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:    927, g_y:  -4096
         //Top product * 10: 205742080
         //g magnitude: 4199.588670
         //Ideal cross-product: 4899.100749
         //Predicted function output: 4900
      {     0,      0,   8159,      0,   /* 5795 */ 5750}, 
         //[  36]:  in_g_vec_1=8159 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:   4063, g_y:  -4096
         //Top product * 10: 334192640
         //g magnitude: 5769.331417
         //Ideal cross-product: 5792.571372
         //Predicted function output: 5795
      {     0,      0,   8160,      0,   /* 5793 */ 5747}, 
         //[  37]:  in_g_vec_1=8160 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:   4064, g_y:  -4096
         //Top product * 10: 334233600
         //g magnitude: 5770.035702
         //Ideal cross-product: 5792.574211
         //Predicted function output: 5793
      {     0,      0,   8161,      0,   /* 5793 */ 5747}, 
         //[  38]:  in_g_vec_1=8161 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:   4065, g_y:  -4096
         //Top product * 10: 334274560
         //g magnitude: 5770.740074
         //Ideal cross-product: 5792.576961
         //Predicted function output: 5793
      {     0,      0,      0,      0,      0}, 
         //[  39]:  in_g_vec_2=0 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4096, g_y:  -4096
         //Top product * 10: 0
         //g magnitude: 5792.618751
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {     0,      0,      0,      1,      0}, 
         //[  40]:  in_g_vec_2=1 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4096, g_y:  -4095
         //Top product * 10: 40960
         //g magnitude: 5791.911688
         //Ideal cross-product: 0.707193
         //Predicted function output: 0
      {     0,      0,      0,     31,     /* 22 */ 0}, 
         //[  41]:  in_g_vec_2=31 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4096, g_y:  -4065
         //Top product * 10: 1269760
         //g magnitude: 5770.740074
         //Ideal cross-product: 22.003417
         //Predicted function output: 22
      {     0,      0,      0,     32,     /* 22 */ 0}, 
         //[  42]:  in_g_vec_2=32 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4096, g_y:  -4064
         //Top product * 10: 1310720
         //g magnitude: 5770.035702
         //Ideal cross-product: 22.715977
         //Predicted function output: 22
      {     0,      0,      0,     33,     /* 23 */ 0}, 
         //[  43]:  in_g_vec_2=33 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4096, g_y:  -4063
         //Top product * 10: 1351680
         //g magnitude: 5769.331417
         //Ideal cross-product: 23.428711
         //Predicted function output: 23
      {     0,      0,      0,    201,    /* 145 */ 122}, 
         //[  44]:  in_g_vec_2=201 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4096, g_y:  -3895
         //Top product * 10: 8232960
         //g magnitude: 5652.277506
         //Ideal cross-product: 145.657392
         //Predicted function output: 145
      {     0,      0,      0,   4095,   /* 4095 */ 4063}, 
         //[  45]:  in_g_vec_2=4095 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4096, g_y:     -1
         //Top product * 10: 167731200
         //g magnitude: 4096.000122
         //Ideal cross-product: 4094.999878
         //Predicted function output: 4095
      {     0,      0,      0,   4096,   /* 4096 */ 4064}, 
         //[  46]:  in_g_vec_2=4096 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4096, g_y:      0
         //Top product * 10: 167772160
         //g magnitude: 4096.000000
         //Ideal cross-product: 4096.000000
         //Predicted function output: 4096
      {     0,      0,      0,   4097,   /* 4097 */ 4065}, 
         //[  47]:  in_g_vec_2=4097 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4096, g_y:      1
         //Top product * 10: 167813120
         //g magnitude: 4096.000122
         //Ideal cross-product: 4096.999878
         //Predicted function output: 4097
      {     0,      0,      0,   5023,   /* 4900 */ 4868}, 
         //[  48]:  in_g_vec_2=5023 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4096, g_y:    927
         //Top product * 10: 205742080
         //g magnitude: 4199.588670
         //Ideal cross-product: 4899.100749
         //Predicted function output: 4900
      {     0,      0,      0,   8159,   /* 5795 */ 5750}, 
         //[  49]:  in_g_vec_2=8159 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4096, g_y:   4063
         //Top product * 10: 334192640
         //g magnitude: 5769.331417
         //Ideal cross-product: 5792.571372
         //Predicted function output: 5795
      {     0,      0,      0,   8160,   /* 5793 */ 5747}, 
         //[  50]:  in_g_vec_2=8160 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4096, g_y:   4064
         //Top product * 10: 334233600
         //g magnitude: 5770.035702
         //Ideal cross-product: 5792.574211
         //Predicted function output: 5793
      {     0,      0,      0,   8161,   /* 5793 */ 5747}, 
         //[  51]:  in_g_vec_2=8161 excess-4096 mapping test.
         //a_x:  -4096, a_y:  -4096, g_x:  -4096, g_y:   4065
         //Top product * 10: 334274560
         //g magnitude: 5770.740074
         //Ideal cross-product: 5792.576961
         //Predicted function output: 5793
      //******************************************************
      //******************************************************
      //******************************************************
      {  4096,   4096,   4096,   4096,      0}, 
         //[  52]:  0-g vector trap test.
         //a_x:      0, a_y:      0, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   4097,   4096,      0}, 
         //[  53]:  One component of g (g_x) not zero.
         //a_x:      0, a_y:      0, g_x:      1, g_y:      0
         //Top product * 10: 0
         //g magnitude: 1.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   4096,   4097,      0}, 
         //[  54]:  0ne component of g (g_y) not zero.
         //a_x:      0, a_y:      0, g_x:      0, g_y:      1
         //Top product * 10: 0
         //g magnitude: 1.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   4097,   4097,      0}, 
         //[  55]:  Both components of g not zero.
         //a_x:      0, a_y:      0, g_x:      1, g_y:      1
         //Top product * 10: 0
         //g magnitude: 1.414214
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   4096,   4097,      0}, 
         //[  56]:  Gravity normalization test.
         //a_x:      0, a_y:      0, g_x:      0, g_y:      1
         //Top product * 10: 0
         //g magnitude: 1.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   4097,   4096,      0}, 
         //[  57]:  Gravity normalization test.
         //a_x:      0, a_y:      0, g_x:      1, g_y:      0
         //Top product * 10: 0
         //g magnitude: 1.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   5119,   4097,      0}, 
         //[  58]:  Gravity normalization test.
         //a_x:      0, a_y:      0, g_x:   1023, g_y:      1
         //Top product * 10: 0
         //g magnitude: 1023.000489
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   4097,   5119,      0}, 
         //[  59]:  Gravity normalization test.
         //a_x:      0, a_y:      0, g_x:      1, g_y:   1023
         //Top product * 10: 0
         //g magnitude: 1023.000489
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  5351,   3717,   4596,   4097,    382}, 
         //[  60]:  Identicality test.
         //a_x:   1255, a_y:   -379, g_x:    500, g_y:      1
         //Top product * 10: 1907550
         //g magnitude: 500.001000
         //Ideal cross-product: 381.509237
         //Predicted function output: 382
      {  5351,   3717,   8096,   4096,    379}, 
         //[  61]:  Identicality test.
         //a_x:   1255, a_y:   -379, g_x:   4000, g_y:      0
         //Top product * 10: 15160000
         //g magnitude: 4000.000000
         //Ideal cross-product: 379.000000
         //Predicted function output: 379
      {  4096,   4096,   8160,   4096,      0}, 
         //[  62]:  Square root calculation overflow test.
         //a_x:      0, a_y:      0, g_x:   4064, g_y:      0
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   4096,     32,      0}, 
         //[  63]:  Square root calculation overflow test.
         //a_x:      0, a_y:      0, g_x:      0, g_y:  -4064
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   8160,   8160,      0}, 
         //[  64]:  Square root calculation overflow test.
         //a_x:      0, a_y:      0, g_x:   4064, g_y:   4064
         //Top product * 10: 0
         //g magnitude: 5747.363917
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,     32,     32,      0}, 
         //[  65]:  Square root calculation overflow test.
         //a_x:      0, a_y:      0, g_x:  -4064, g_y:  -4064
         //Top product * 10: 0
         //g magnitude: 5747.363917
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  5096,   6596,   4996,   7096,    239}, 
         //[  66]:  Sign permutation test (01/16).
         //a_x:   1000, a_y:   2500, g_x:    900, g_y:   3000
         //Top product * 10: 7500000
         //g magnitude: 3132.091953
         //Ideal cross-product: 239.456571
         //Predicted function output: 239
      {  5096,   6596,   4996,   1096,   1677}, 
         //[  67]:  Sign permutation test (02/16).
         //a_x:   1000, a_y:   2500, g_x:    900, g_y:  -3000
         //Top product * 10: 52500000
         //g magnitude: 3132.091953
         //Ideal cross-product: 1676.195999
         //Predicted function output: 1677
      {  5096,   6596,   3196,   7096,   1677}, 
         //[  68]:  Sign permutation test (03/16).
         //a_x:   1000, a_y:   2500, g_x:   -900, g_y:   3000
         //Top product * 10: 52500000
         //g magnitude: 3132.091953
         //Ideal cross-product: 1676.195999
         //Predicted function output: 1677
      {  5096,   6596,   3196,   1096,    239}, 
         //[  69]:  Sign permutation test (04/16).
         //a_x:   1000, a_y:   2500, g_x:   -900, g_y:  -3000
         //Top product * 10: 7500000
         //g magnitude: 3132.091953
         //Ideal cross-product: 239.456571
         //Predicted function output: 239
      {  5096,   1596,   4996,   7096,   1677}, 
         //[  70]:  Sign permutation test (05/16).
         //a_x:   1000, a_y:  -2500, g_x:    900, g_y:   3000
         //Top product * 10: 52500000
         //g magnitude: 3132.091953
         //Ideal cross-product: 1676.195999
         //Predicted function output: 1677
      {  5096,   1596,   4996,   1096,    239}, 
         //[  71]:  Sign permutation test (06/16).
         //a_x:   1000, a_y:  -2500, g_x:    900, g_y:  -3000
         //Top product * 10: 7500000
         //g magnitude: 3132.091953
         //Ideal cross-product: 239.456571
         //Predicted function output: 239
      {  5096,   1596,   3196,   7096,    239}, 
         //[  72]:  Sign permutation test (07/16).
         //a_x:   1000, a_y:  -2500, g_x:   -900, g_y:   3000
         //Top product * 10: 7500000
         //g magnitude: 3132.091953
         //Ideal cross-product: 239.456571
         //Predicted function output: 239
      {  5096,   1596,   3196,   1096,   1677}, 
         //[  73]:  Sign permutation test (08/16).
         //a_x:   1000, a_y:  -2500, g_x:   -900, g_y:  -3000
         //Top product * 10: 52500000
         //g magnitude: 3132.091953
         //Ideal cross-product: 1676.195999
         //Predicted function output: 1677
      {  3096,   6596,   4996,   7096,   1677}, 
         //[  74]:  Sign permutation test (09/16).
         //a_x:  -1000, a_y:   2500, g_x:    900, g_y:   3000
         //Top product * 10: 52500000
         //g magnitude: 3132.091953
         //Ideal cross-product: 1676.195999
         //Predicted function output: 1677
      {  3096,   6596,   4996,   1096,    239}, 
         //[  75]:  Sign permutation test (10/16).
         //a_x:  -1000, a_y:   2500, g_x:    900, g_y:  -3000
         //Top product * 10: 7500000
         //g magnitude: 3132.091953
         //Ideal cross-product: 239.456571
         //Predicted function output: 239
      {  3096,   6596,   3196,   7096,    239}, 
         //[  76]:  Sign permutation test (11/16).
         //a_x:  -1000, a_y:   2500, g_x:   -900, g_y:   3000
         //Top product * 10: 7500000
         //g magnitude: 3132.091953
         //Ideal cross-product: 239.456571
         //Predicted function output: 239
      {  3096,   6596,   3196,   1096,   1677}, 
         //[  77]:  Sign permutation test (12/16).
         //a_x:  -1000, a_y:   2500, g_x:   -900, g_y:  -3000
         //Top product * 10: 52500000
         //g magnitude: 3132.091953
         //Ideal cross-product: 1676.195999
         //Predicted function output: 1677
      {  3096,   1596,   4996,   7096,    239}, 
         //[  78]:  Sign permutation test (13/16).
         //a_x:  -1000, a_y:  -2500, g_x:    900, g_y:   3000
         //Top product * 10: 7500000
         //g magnitude: 3132.091953
         //Ideal cross-product: 239.456571
         //Predicted function output: 239
      {  3096,   1596,   4996,   1096,   1677}, 
         //[  79]:  Sign permutation test (14/16).
         //a_x:  -1000, a_y:  -2500, g_x:    900, g_y:  -3000
         //Top product * 10: 52500000
         //g magnitude: 3132.091953
         //Ideal cross-product: 1676.195999
         //Predicted function output: 1677
      {  3096,   1596,   3196,   7096,   1677}, 
         //[  80]:  Sign permutation test (15/16).
         //a_x:  -1000, a_y:  -2500, g_x:   -900, g_y:   3000
         //Top product * 10: 52500000
         //g magnitude: 3132.091953
         //Ideal cross-product: 1676.195999
         //Predicted function output: 1677
      {  3096,   1596,   3196,   1096,    239}, 
         //[  81]:  Sign permutation test (16/16).
         //a_x:  -1000, a_y:  -2500, g_x:   -900, g_y:  -3000
         //Top product * 10: 7500000
         //g magnitude: 3132.091953
         //Ideal cross-product: 239.456571
         //Predicted function output: 239
      //******************************************************
      //******************************************************
      //******************************************************
      {    32,     32,     32,     32,      0}, 
         //[  82]:  (-2,-2,-2,-2)
         //a_x:  -4064, a_y:  -4064, g_x:  -4064, g_y:  -4064
         //Top product * 10: 0
         //g magnitude: 5747.363917
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {    32,     32,     32,    374,    252}, 
         //[  83]:  (-2,-2,-2,-1)
         //a_x:  -4064, a_y:  -4064, g_x:  -4064, g_y:  -3722
         //Top product * 10: 13898880
         //g magnitude: 5510.842041
         //Ideal cross-product: 252.209733
         //Predicted function output: 252
      {    32,     32,     32,   4096,   4064}, 
         //[  84]:  (-2,-2,-2,0)
         //a_x:  -4064, a_y:  -4064, g_x:  -4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {    32,     32,     32,   5306,   5055}, 
         //[  85]:  (-2,-2,-2,1)
         //a_x:  -4064, a_y:  -4064, g_x:  -4064, g_y:   1210
         //Top product * 10: 214335360
         //g magnitude: 4240.306121
         //Ideal cross-product: 5054.714303
         //Predicted function output: 5055
      {    32,     32,     32,   8160,   5747}, 
         //[  86]:  (-2,-2,-2,2)
         //a_x:  -4064, a_y:  -4064, g_x:  -4064, g_y:   4064
         //Top product * 10: 330321920
         //g magnitude: 5747.363917
         //Ideal cross-product: 5747.363917
         //Predicted function output: 5747
      {    32,     32,   1544,     32,   1281}, 
         //[  87]:  (-2,-2,-1,-2)
         //a_x:  -4064, a_y:  -4064, g_x:  -2552, g_y:  -4064
         //Top product * 10: 61447680
         //g magnitude: 4798.833192
         //Ideal cross-product: 1280.471263
         //Predicted function output: 1281
      {    32,     32,   1970,   3216,   2200}, 
         //[  88]:  (-2,-2,-1,-1)
         //a_x:  -4064, a_y:  -4064, g_x:  -2126, g_y:   -880
         //Top product * 10: 50637440
         //g magnitude: 2300.929377
         //Ideal cross-product: 2200.738558
         //Predicted function output: 2200
      {    32,     32,   1763,   4096,   4064}, 
         //[  89]:  (-2,-2,-1,0)
         //a_x:  -4064, a_y:  -4064, g_x:  -2333, g_y:      0
         //Top product * 10: 94813120
         //g magnitude: 2333.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {    32,     32,   3482,   4954,   5673}, 
         //[  90]:  (-2,-2,-1,1)
         //a_x:  -4064, a_y:  -4064, g_x:   -614, g_y:    858
         //Top product * 10: 59822080
         //g magnitude: 1055.063979
         //Ideal cross-product: 5669.995487
         //Predicted function output: 5682
         //DTA 20091212:  Expected value adjusted to
         //5673.  Presumed cause of disagreement is g-vector
         //normalization due to sub-1024 values of components.
         //G-vector normalization seems to lead to closer
         //value to ideal.
      {    32,     32,   1588,   8160,   5594}, 
         //[  91]:  (-2,-2,-1,2)
         //a_x:  -4064, a_y:  -4064, g_x:  -2508, g_y:   4064
         //Top product * 10: 267086080
         //g magnitude: 4775.579546
         //Ideal cross-product: 5592.746963
         //Predicted function output: 5594
      {    32,     32,   4096,     32,   4064}, 
         //[  92]:  (-2,-2,0,-2)
         //a_x:  -4064, a_y:  -4064, g_x:      0, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {    32,     32,   4096,   4059,   4064}, 
         //[  93]:  (-2,-2,0,-1)
         //a_x:  -4064, a_y:  -4064, g_x:      0, g_y:    -37
         //Top product * 10: 1503680
         //g magnitude: 37.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4699
         //DTA 20091212:  Expected value adjusted to
         //4064.  Presumed cause of disagreement is g-vector
         //normalization due to sub-1024 values of components.
         //G-vector normalization seems to lead to closer
         //value to ideal.
      {    32,     32,   4096,   4096,      0}, 
         //[  94]:  (-2,-2,0,0)
         //a_x:  -4064, a_y:  -4064, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {    32,     32,   4096,   6268,   4068}, 
         //[  95]:  (-2,-2,0,1)
         //a_x:  -4064, a_y:  -4064, g_x:      0, g_y:   2172
         //Top product * 10: 88270080
         //g magnitude: 2172.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4068
      {    32,     32,   4096,   8160,   4064}, 
         //[  96]:  (-2,-2,0,2)
         //a_x:  -4064, a_y:  -4064, g_x:      0, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {    32,     32,   6314,     32,   5517}, 
         //[  97]:  (-2,-2,1,-2)
         //a_x:  -4064, a_y:  -4064, g_x:   2218, g_y:  -4064
         //Top product * 10: 255300480
         //g magnitude: 4629.861769
         //Ideal cross-product: 5514.213874
         //Predicted function output: 5517
      {    32,     32,   7649,   2667,   5290}, 
         //[  98]:  (-2,-2,1,-1)
         //a_x:  -4064, a_y:  -4064, g_x:   3553, g_y:  -1429
         //Top product * 10: 202468480
         //g magnitude: 3829.601807
         //Ideal cross-product: 5286.932956
         //Predicted function output: 5290
      {    32,     32,   4191,   4096,   4072}, 
         //[  99]:  (-2,-2,1,0)
         //a_x:  -4064, a_y:  -4064, g_x:     95, g_y:      0
         //Top product * 10: 3860800
         //g magnitude: 95.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4308
         //DTA 20091212:  Expected value adjusted to
         //4072.  Presumed cause of disagreement is g-vector
         //normalization due to sub-1024 values of components.
         //G-vector normalization seems to lead to closer
         //value to ideal.
      {    32,     32,   6734,   7231,    493}, 
         //[ 100]:  (-2,-2,1,1)
         //a_x:  -4064, a_y:  -4064, g_x:   2638, g_y:   3135
         //Top product * 10: 20198080
         //g magnitude: 4097.226989
         //Ideal cross-product: 492.969515
         //Predicted function output: 493
      {    32,     32,   6331,   8160,   1603}, 
         //[ 101]:  (-2,-2,1,2)
         //a_x:  -4064, a_y:  -4064, g_x:   2235, g_y:   4064
         //Top product * 10: 74330560
         //g magnitude: 4638.029862
         //Ideal cross-product: 1602.632200
         //Predicted function output: 1603
      {    32,     32,   8160,     32,   5747}, 
         //[ 102]:  (-2,-2,2,-2)
         //a_x:  -4064, a_y:  -4064, g_x:   4064, g_y:  -4064
         //Top product * 10: 330321920
         //g magnitude: 5747.363917
         //Ideal cross-product: 5747.363917
         //Predicted function output: 5747
      {    32,     32,   8160,    961,   5703}, 
         //[ 103]:  (-2,-2,2,-1)
         //a_x:  -4064, a_y:  -4064, g_x:   4064, g_y:  -3135
         //Top product * 10: 292567360
         //g magnitude: 5132.671916
         //Ideal cross-product: 5700.098599
         //Predicted function output: 5703
      {    32,     32,   8160,   4096,   4064}, 
         //[ 104]:  (-2,-2,2,0)
         //a_x:  -4064, a_y:  -4064, g_x:   4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {    32,     32,   8160,   4544,   3596}, 
         //[ 105]:  (-2,-2,2,1)
         //a_x:  -4064, a_y:  -4064, g_x:   4064, g_y:    448
         //Top product * 10: 146954240
         //g magnitude: 4088.618349
         //Ideal cross-product: 3594.227376
         //Predicted function output: 3596
      {    32,     32,   8160,   8160,      0}, 
         //[ 106]:  (-2,-2,2,2)
         //a_x:  -4064, a_y:  -4064, g_x:   4064, g_y:   4064
         //Top product * 10: 0
         //g magnitude: 5747.363917
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {    32,   1925,     32,     32,   1338}, 
         //[ 107]:  (-2,-1,-2,-2)
         //a_x:  -4064, a_y:  -2171, g_x:  -4064, g_y:  -4064
         //Top product * 10: 76931520
         //g magnitude: 5747.363917
         //Ideal cross-product: 1338.553137
         //Predicted function output: 1338
      {    32,   2654,     32,   2300,    323}, 
         //[ 108]:  (-2,-1,-2,-1)
         //a_x:  -4064, a_y:  -1442, g_x:  -4064, g_y:  -1796
         //Top product * 10: 14386560
         //g magnitude: 4443.164638
         //Ideal cross-product: 323.790838
         //Predicted function output: 323
      {    32,   1153,     32,   4096,   2943}, 
         //[ 109]:  (-2,-1,-2,0)
         //a_x:  -4064, a_y:  -2943, g_x:  -4064, g_y:      0
         //Top product * 10: 119603520
         //g magnitude: 4064.000000
         //Ideal cross-product: 2943.000000
         //Predicted function output: 2943
      {    32,   3367,     32,   7113,   3009}, 
         //[ 110]:  (-2,-1,-2,1)
         //a_x:  -4064, a_y:   -729, g_x:  -4064, g_y:   3017
         //Top product * 10: 152237440
         //g magnitude: 5061.460758
         //Ideal cross-product: 3007.776752
         //Predicted function output: 3009
      {    32,   3187,     32,   8160,   3516}, 
         //[ 111]:  (-2,-1,-2,2)
         //a_x:  -4064, a_y:   -909, g_x:  -4064, g_y:   4064
         //Top product * 10: 202102720
         //g magnitude: 5747.363917
         //Ideal cross-product: 3516.442023
         //Predicted function output: 3516
      {    32,   3288,    837,     32,   2666}, 
         //[ 112]:  (-2,-1,-1,-2)
         //a_x:  -4064, a_y:   -808, g_x:  -3259, g_y:  -4064
         //Top product * 10: 138828240
         //g magnitude: 5209.335562
         //Ideal cross-product: 2664.989390
         //Predicted function output: 2666
      {    32,   3054,   1357,   1470,   2061}, 
         //[ 113]:  (-2,-1,-1,-1)
         //a_x:  -4064, a_y:  -1042, g_x:  -2739, g_y:  -2626
         //Top product * 10: 78180260
         //g magnitude: 3794.469265
         //Ideal cross-product: 2060.374048
         //Predicted function output: 2061
      {    32,   1737,    996,   4096,   2360}, 
         //[ 114]:  (-2,-1,-1,0)
         //a_x:  -4064, a_y:  -2359, g_x:  -3100, g_y:      0
         //Top product * 10: 73129000
         //g magnitude: 3100.000000
         //Ideal cross-product: 2359.000000
         //Predicted function output: 2360
      {    32,   3287,   3606,   6670,   4147}, 
         //[ 115]:  (-2,-1,-1,1)
         //a_x:  -4064, a_y:   -809, g_x:   -490, g_y:   2574
         //Top product * 10: 108571460
         //g magnitude: 2620.224418
         //Ideal cross-product: 4143.593933
         //Predicted function output: 4147
      {    32,   2284,   2502,   8160,   4445}, 
         //[ 116]:  (-2,-1,-1,2)
         //a_x:  -4064, a_y:  -1812, g_x:  -1594, g_y:   4064
         //Top product * 10: 194044240
         //g magnitude: 4365.424607
         //Ideal cross-product: 4445.025569
         //Predicted function output: 4445
      {    32,   3083,   4096,     32,   4064}, 
         //[ 117]:  (-2,-1,0,-2)
         //a_x:  -4064, a_y:  -1013, g_x:      0, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {    32,   3419,   4096,   2365,   4071}, 
         //[ 118]:  (-2,-1,0,-1)
         //a_x:  -4064, a_y:   -677, g_x:      0, g_y:  -1731
         //Top product * 10: 70347840
         //g magnitude: 1731.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4071
      {    32,   2070,   4096,   4096,      0}, 
         //[ 119]:  (-2,-1,0,0)
         //a_x:  -4064, a_y:  -2026, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {    32,   3644,   4096,   5473,   4066}, 
         //[ 120]:  (-2,-1,0,1)
         //a_x:  -4064, a_y:   -452, g_x:      0, g_y:   1377
         //Top product * 10: 55961280
         //g magnitude: 1377.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4066
      {    32,   3389,   4096,   8160,   4064}, 
         //[ 121]:  (-2,-1,0,2)
         //a_x:  -4064, a_y:   -707, g_x:      0, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {    32,   2486,   4411,     32,   4178}, 
         //[ 122]:  (-2,-1,1,-2)
         //a_x:  -4064, a_y:  -1610, g_x:    315, g_y:  -4064
         //Top product * 10: 170232460
         //g magnitude: 4076.189520
         //Ideal cross-product: 4176.264602
         //Predicted function output: 4178
      {    32,   1543,   6334,   3439,   3598}, 
         //[ 123]:  (-2,-1,1,-1)
         //a_x:  -4064, a_y:  -2553, g_x:   2238, g_y:   -657
         //Top product * 10: 83836620
         //g magnitude: 2332.443568
         //Ideal cross-product: 3594.368633
         //Predicted function output: 3598
      {    32,   2827,   6504,   4096,   1269}, 
         //[ 124]:  (-2,-1,1,0)
         //a_x:  -4064, a_y:  -1269, g_x:   2408, g_y:      0
         //Top product * 10: 30557520
         //g magnitude: 2408.000000
         //Ideal cross-product: 1269.000000
         //Predicted function output: 1269
      {    32,   3439,   4912,   7578,   3808}, 
         //[ 125]:  (-2,-1,1,1)
         //a_x:  -4064, a_y:   -657, g_x:    816, g_y:   3482
         //Top product * 10: 136147360
         //g magnitude: 3576.336114
         //Ideal cross-product: 3806.894980
         //Predicted function output: 3808
      {    32,   2671,   6565,   8160,   2733}, 
         //[ 126]:  (-2,-1,1,2)
         //a_x:  -4064, a_y:  -1425, g_x:   2469, g_y:   4064
         //Top product * 10: 129977710
         //g magnitude: 4755.213665
         //Ideal cross-product: 2733.372655
         //Predicted function output: 2733
      {    32,    957,   8160,     32,   5093}, 
         //[ 127]:  (-2,-1,2,-2)
         //a_x:  -4064, a_y:  -3139, g_x:   4064, g_y:  -4064
         //Top product * 10: 292729920
         //g magnitude: 5747.363917
         //Ideal cross-product: 5093.290145
         //Predicted function output: 5093
      {    32,   2017,   8160,   2088,   3665}, 
         //[ 128]:  (-2,-1,2,-1)
         //a_x:  -4064, a_y:  -2079, g_x:   4064, g_y:  -2008
         //Top product * 10: 166095680
         //g magnitude: 4533.007831
         //Ideal cross-product: 3664.138386
         //Predicted function output: 3665
      {    32,    413,   8160,   4096,   3683}, 
         //[ 129]:  (-2,-1,2,0)
         //a_x:  -4064, a_y:  -3683, g_x:   4064, g_y:      0
         //Top product * 10: 149677120
         //g magnitude: 4064.000000
         //Ideal cross-product: 3683.000000
         //Predicted function output: 3683
      {    32,   3094,   8160,   7248,   1699}, 
         //[ 130]:  (-2,-1,2,1)
         //a_x:  -4064, a_y:  -1002, g_x:   4064, g_y:   3152
         //Top product * 10: 87376000
         //g magnitude: 5143.073011
         //Ideal cross-product: 1698.906467
         //Predicted function output: 1699
      {    32,   2160,   8160,   8160,   1504}, 
         //[ 131]:  (-2,-1,2,2)
         //a_x:  -4064, a_y:  -1936, g_x:   4064, g_y:   4064
         //Top product * 10: 86481920
         //g magnitude: 5747.363917
         //Ideal cross-product: 1504.723230
         //Predicted function output: 1504
      {    32,   4096,     32,     32,   2873}, 
         //[ 132]:  (-2,0,-2,-2)
         //a_x:  -4064, a_y:      0, g_x:  -4064, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 5747.363917
         //Ideal cross-product: 2873.681959
         //Predicted function output: 2873
      {    32,   4096,     32,   1177,   2371}, 
         //[ 133]:  (-2,0,-2,-1)
         //a_x:  -4064, a_y:      0, g_x:  -4064, g_y:  -2919
         //Top product * 10: 118628160
         //g magnitude: 5003.664357
         //Ideal cross-product: 2370.825690
         //Predicted function output: 2371
      {    32,   4096,     32,   4096,      0}, 
         //[ 134]:  (-2,0,-2,0)
         //a_x:  -4064, a_y:      0, g_x:  -4064, g_y:      0
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {    32,   4096,     32,   5210,   1075}, 
         //[ 135]:  (-2,0,-2,1)
         //a_x:  -4064, a_y:      0, g_x:  -4064, g_y:   1114
         //Top product * 10: 45272960
         //g magnitude: 4213.916468
         //Ideal cross-product: 1074.367761
         //Predicted function output: 1075
      {    32,   4096,     32,   8160,   2873}, 
         //[ 136]:  (-2,0,-2,2)
         //a_x:  -4064, a_y:      0, g_x:  -4064, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 5747.363917
         //Ideal cross-product: 2873.681959
         //Predicted function output: 2873
      {    32,   4096,   2251,     32,   3702}, 
         //[ 137]:  (-2,0,-1,-2)
         //a_x:  -4064, a_y:      0, g_x:  -1845, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 4463.196276
         //Ideal cross-product: 3700.508554
         //Predicted function output: 3702
      {    32,   4096,   2307,   3107,   1968}, 
         //[ 138]:  (-2,0,-1,-1)
         //a_x:  -4064, a_y:      0, g_x:  -1789, g_y:   -989
         //Top product * 10: 40192960
         //g magnitude: 2044.172693
         //Ideal cross-product: 1966.221354
         //Predicted function output: 1968
      {    32,   4096,   1799,   4096,      0}, 
         //[ 139]:  (-2,0,-1,0)
         //a_x:  -4064, a_y:      0, g_x:  -2297, g_y:      0
         //Top product * 10: 0
         //g magnitude: 2297.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {    32,   4096,   1087,   5492,   1711}, 
         //[ 140]:  (-2,0,-1,1)
         //a_x:  -4064, a_y:      0, g_x:  -3009, g_y:   1396
         //Top product * 10: 56733440
         //g magnitude: 3317.061501
         //Ideal cross-product: 1710.352370
         //Predicted function output: 1711
      {    32,   4096,   3245,   8160,   3979}, 
         //[ 141]:  (-2,0,-1,2)
         //a_x:  -4064, a_y:      0, g_x:   -851, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 4152.143663
         //Ideal cross-product: 3977.727492
         //Predicted function output: 3979
      {    32,   4096,   4096,     32,   4064}, 
         //[ 142]:  (-2,0,0,-2)
         //a_x:  -4064, a_y:      0, g_x:      0, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {    32,   4096,   4096,   3640,   4064}, 
         //[ 143]:  (-2,0,0,-1)
         //a_x:  -4064, a_y:      0, g_x:      0, g_y:   -456
         //Top product * 10: 18531840
         //g magnitude: 456.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4078
         //DTA 20091212:  Expected value adjusted to
         //4064.  Presumed cause of disagreement is g-vector
         //normalization due to sub-1024 values of components.
         //G-vector normalization seems to lead to closer
         //value to ideal.
      {    32,   4096,   4096,   4096,      0}, 
         //[ 144]:  (-2,0,0,0)
         //a_x:  -4064, a_y:      0, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {    32,   4096,   4096,   6501,   4067}, 
         //[ 145]:  (-2,0,0,1)
         //a_x:  -4064, a_y:      0, g_x:      0, g_y:   2405
         //Top product * 10: 97739200
         //g magnitude: 2405.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4067
      {    32,   4096,   4096,   8160,   4064}, 
         //[ 146]:  (-2,0,0,2)
         //a_x:  -4064, a_y:      0, g_x:      0, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {    32,   4096,   7643,     32,   3063}, 
         //[ 147]:  (-2,0,1,-2)
         //a_x:  -4064, a_y:      0, g_x:   3547, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 5394.191784
         //Ideal cross-product: 3061.829587
         //Predicted function output: 3063
      {    32,   4096,   6202,   2330,   2614}, 
         //[ 148]:  (-2,0,1,-1)
         //a_x:  -4064, a_y:      0, g_x:   2106, g_y:  -1766
         //Top product * 10: 71770240
         //g magnitude: 2748.452656
         //Ideal cross-product: 2611.296209
         //Predicted function output: 2614
      {    32,   4096,   4977,   4096,      0}, 
         //[ 149]:  (-2,0,1,0)
         //a_x:  -4064, a_y:      0, g_x:    881, g_y:      0
         //Top product * 10: 0
         //g magnitude: 881.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {    32,   4096,   7226,   7654,   3053}, 
         //[ 150]:  (-2,0,1,1)
         //a_x:  -4064, a_y:      0, g_x:   3130, g_y:   3558
         //Top product * 10: 144597120
         //g magnitude: 4738.804069
         //Ideal cross-product: 3051.342024
         //Predicted function output: 3053
      {    32,   4096,   7648,   8160,   3061}, 
         //[ 151]:  (-2,0,1,2)
         //a_x:  -4064, a_y:      0, g_x:   3552, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 5397.480894
         //Ideal cross-product: 3059.963773
         //Predicted function output: 3061
      {    32,   4096,   8160,     32,   2873}, 
         //[ 152]:  (-2,0,2,-2)
         //a_x:  -4064, a_y:      0, g_x:   4064, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 5747.363917
         //Ideal cross-product: 2873.681959
         //Predicted function output: 2873
      {    32,   4096,   8160,   1009,   2459}, 
         //[ 153]:  (-2,0,2,-1)
         //a_x:  -4064, a_y:      0, g_x:   4064, g_y:  -3087
         //Top product * 10: 125455680
         //g magnitude: 5103.495371
         //Ideal cross-product: 2458.230504
         //Predicted function output: 2459
      {    32,   4096,   8160,   4096,      0}, 
         //[ 154]:  (-2,0,2,0)
         //a_x:  -4064, a_y:      0, g_x:   4064, g_y:      0
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {    32,   4096,   8160,   4323,    226}, 
         //[ 155]:  (-2,0,2,1)
         //a_x:  -4064, a_y:      0, g_x:   4064, g_y:    227
         //Top product * 10: 9225280
         //g magnitude: 4070.334753
         //Ideal cross-product: 226.646715
         //Predicted function output: 226
      {    32,   4096,   8160,   8160,   2873}, 
         //[ 156]:  (-2,0,2,2)
         //a_x:  -4064, a_y:      0, g_x:   4064, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 5747.363917
         //Ideal cross-product: 2873.681959
         //Predicted function output: 2873
      {    32,   5746,     32,     32,   4040}, 
         //[ 157]:  (-2,1,-2,-2)
         //a_x:  -4064, a_y:   1650, g_x:  -4064, g_y:  -4064
         //Top product * 10: 232216960
         //g magnitude: 5747.363917
         //Ideal cross-product: 4040.408148
         //Predicted function output: 4040
      {    32,   7093,     32,    700,   4905}, 
         //[ 158]:  (-2,1,-2,-1)
         //a_x:  -4064, a_y:   2997, g_x:  -4064, g_y:  -3396
         //Top product * 10: 259811520
         //g magnitude: 5296.122355
         //Ideal cross-product: 4905.693309
         //Predicted function output: 4905
      {    32,   6078,     32,   4096,   1982}, 
         //[ 159]:  (-2,1,-2,0)
         //a_x:  -4064, a_y:   1982, g_x:  -4064, g_y:      0
         //Top product * 10: 80548480
         //g magnitude: 4064.000000
         //Ideal cross-product: 1982.000000
         //Predicted function output: 1982
      {    32,   7700,     32,   4743,   2922}, 
         //[ 160]:  (-2,1,-2,1)
         //a_x:  -4064, a_y:   3604, g_x:  -4064, g_y:    647
         //Top product * 10: 120172480
         //g magnitude: 4115.179826
         //Ideal cross-product: 2920.224269
         //Predicted function output: 2922
      {    32,   6703,     32,   8160,   1030}, 
         //[ 161]:  (-2,1,-2,2)
         //a_x:  -4064, a_y:   2607, g_x:  -4064, g_y:   4064
         //Top product * 10: 59212480
         //g magnitude: 5747.363917
         //Ideal cross-product: 1030.254580
         //Predicted function output: 1030
      {    32,   5389,   1319,     32,   4085}, 
         //[ 162]:  (-2,1,-1,-2)
         //a_x:  -4064, a_y:   1293, g_x:  -2777, g_y:  -4064
         //Top product * 10: 201067570
         //g magnitude: 4922.176856
         //Ideal cross-product: 4084.931848
         //Predicted function output: 4085
      {    32,   4668,   1609,   2510,   2669}, 
         //[ 163]:  (-2,1,-1,-1)
         //a_x:  -4064, a_y:    572, g_x:  -2487, g_y:  -1586
         //Top product * 10: 78680680
         //g magnitude: 2949.672016
         //Ideal cross-product: 2667.438264
         //Predicted function output: 2669
      {    32,   7731,   2142,   4096,   3638}, 
         //[ 164]:  (-2,1,-1,0)
         //a_x:  -4064, a_y:   3635, g_x:  -1954, g_y:      0
         //Top product * 10: 71027900
         //g magnitude: 1954.000000
         //Ideal cross-product: 3635.000000
         //Predicted function output: 3638
      {    32,   5192,   1318,   7942,   2653}, 
         //[ 165]:  (-2,1,-1,1)
         //a_x:  -4064, a_y:   1096, g_x:  -2778, g_y:   3846
         //Top product * 10: 125854560
         //g magnitude: 4744.365079
         //Ideal cross-product: 2652.716600
         //Predicted function output: 2653
      {    32,   4498,   3119,   8160,   3857}, 
         //[ 166]:  (-2,1,-1,2)
         //a_x:  -4064, a_y:    402, g_x:   -977, g_y:   4064
         //Top product * 10: 161233420
         //g magnitude: 4179.787674
         //Ideal cross-product: 3857.454794
         //Predicted function output: 3857
      {    32,   7312,   4096,     32,   4064}, 
         //[ 167]:  (-2,1,0,-2)
         //a_x:  -4064, a_y:   3216, g_x:      0, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {    32,   4466,   4096,   1901,   4069}, 
         //[ 168]:  (-2,1,0,-1)
         //a_x:  -4064, a_y:    370, g_x:      0, g_y:  -2195
         //Top product * 10: 89204800
         //g magnitude: 2195.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4069
      {    32,   6047,   4096,   4096,      0}, 
         //[ 169]:  (-2,1,0,0)
         //a_x:  -4064, a_y:   1951, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {    32,   5225,   4096,   7463,   4064}, 
         //[ 170]:  (-2,1,0,1)
         //a_x:  -4064, a_y:   1129, g_x:      0, g_y:   3367
         //Top product * 10: 136834880
         //g magnitude: 3367.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {    32,   5311,   4096,   8160,   4064}, 
         //[ 171]:  (-2,1,0,2)
         //a_x:  -4064, a_y:   1215, g_x:      0, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {    32,   7755,   5295,     32,   2862}, 
         //[ 172]:  (-2,1,1,-2)
         //a_x:  -4064, a_y:   3659, g_x:   1199, g_y:  -4064
         //Top product * 10: 121289550
         //g magnitude: 4237.180312
         //Ideal cross-product: 2862.506220
         //Predicted function output: 2862
      {    32,   4624,   6125,   2163,   2423}, 
         //[ 173]:  (-2,1,1,-1)
         //a_x:  -4064, a_y:    528, g_x:   2029, g_y:  -1933
         //Top product * 10: 67844000
         //g magnitude: 2802.379346
         //Ideal cross-product: 2420.942764
         //Predicted function output: 2423
      {    32,   5570,   7114,   4096,   1474}, 
         //[ 174]:  (-2,1,1,0)
         //a_x:  -4064, a_y:   1474, g_x:   3018, g_y:      0
         //Top product * 10: 44485320
         //g magnitude: 3018.000000
         //Ideal cross-product: 1474.000000
         //Predicted function output: 1474
      {    32,   7442,   4147,   4863,   4280}, 
         //[ 175]:  (-2,1,1,1)
         //a_x:  -4064, a_y:   3346, g_x:     51, g_y:    767
         //Top product * 10: 32877340
         //g magnitude: 768.693697
         //Ideal cross-product: 4277.040403
         //Predicted function output: 4280
      {    32,   6738,   7387,   8160,   4821}, 
         //[ 176]:  (-2,1,1,2)
         //a_x:  -4064, a_y:   2642, g_x:   3291, g_y:   4064
         //Top product * 10: 252109180
         //g magnitude: 5229.414594
         //Ideal cross-product: 4820.982836
         //Predicted function output: 4821
      {    32,   7451,   8160,     32,    501}, 
         //[ 177]:  (-2,1,2,-2)
         //a_x:  -4064, a_y:   3355, g_x:   4064, g_y:  -4064
         //Top product * 10: 28813760
         //g magnitude: 5747.363917
         //Ideal cross-product: 501.338708
         //Predicted function output: 501
      {    32,   6602,   8160,   2978,   1338}, 
         //[ 178]:  (-2,1,2,-1)
         //a_x:  -4064, a_y:   2506, g_x:   4064, g_y:  -1118
         //Top product * 10: 56408320
         //g magnitude: 4214.975682
         //Ideal cross-product: 1338.283403
         //Predicted function output: 1338
      {    32,   7802,   8160,   4096,   3706}, 
         //[ 179]:  (-2,1,2,0)
         //a_x:  -4064, a_y:   3706, g_x:   4064, g_y:      0
         //Top product * 10: 150611840
         //g magnitude: 4064.000000
         //Ideal cross-product: 3706.000000
         //Predicted function output: 3706
      {    32,   4463,   8160,   4320,    590}, 
         //[ 180]:  (-2,1,2,1)
         //a_x:  -4064, a_y:    367, g_x:   4064, g_y:    224
         //Top product * 10: 24018240
         //g magnitude: 4070.168547
         //Ideal cross-product: 590.104310
         //Predicted function output: 590
      {    32,   7280,   8160,   8160,   5125}, 
         //[ 181]:  (-2,1,2,2)
         //a_x:  -4064, a_y:   3184, g_x:   4064, g_y:   4064
         //Top product * 10: 294558720
         //g magnitude: 5747.363917
         //Ideal cross-product: 5125.109950
         //Predicted function output: 5125
      {    32,   8160,     32,     32,   5747}, 
         //[ 182]:  (-2,2,-2,-2)
         //a_x:  -4064, a_y:   4064, g_x:  -4064, g_y:  -4064
         //Top product * 10: 330321920
         //g magnitude: 5747.363917
         //Ideal cross-product: 5747.363917
         //Predicted function output: 5747
      {    32,   8160,     32,   1190,   5670}, 
         //[ 183]:  (-2,2,-2,-1)
         //a_x:  -4064, a_y:   4064, g_x:  -4064, g_y:  -2906
         //Top product * 10: 283260800
         //g magnitude: 4996.091672
         //Ideal cross-product: 5669.647768
         //Predicted function output: 5670
      {    32,   8160,     32,   4096,   4064}, 
         //[ 184]:  (-2,2,-2,0)
         //a_x:  -4064, a_y:   4064, g_x:  -4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {    32,   8160,     32,   7163,    795}, 
         //[ 185]:  (-2,2,-2,1)
         //a_x:  -4064, a_y:   4064, g_x:  -4064, g_y:   3067
         //Top product * 10: 40518080
         //g magnitude: 5091.422689
         //Ideal cross-product: 795.810571
         //Predicted function output: 795
      {    32,   8160,     32,   8160,      0}, 
         //[ 186]:  (-2,2,-2,2)
         //a_x:  -4064, a_y:   4064, g_x:  -4064, g_y:   4064
         //Top product * 10: 0
         //g magnitude: 5747.363917
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {    32,   8160,   1446,     32,   5624}, 
         //[ 187]:  (-2,2,-1,-2)
         //a_x:  -4064, a_y:   4064, g_x:  -2650, g_y:  -4064
         //Top product * 10: 272856960
         //g magnitude: 4851.659098
         //Ideal cross-product: 5623.992834
         //Predicted function output: 5624
      {    32,   8160,   1352,   4001,   4207}, 
         //[ 188]:  (-2,2,-1,-1)
         //a_x:  -4064, a_y:   4064, g_x:  -2744, g_y:    -95
         //Top product * 10: 115376960
         //g magnitude: 2745.644005
         //Ideal cross-product: 4202.182068
         //Predicted function output: 4207
      {    32,   8160,    831,   4096,   4065}, 
         //[ 189]:  (-2,2,-1,0)
         //a_x:  -4064, a_y:   4064, g_x:  -3265, g_y:      0
         //Top product * 10: 132689600
         //g magnitude: 3265.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4065
      {    32,   8160,   2320,   7539,   1749}, 
         //[ 190]:  (-2,2,-1,1)
         //a_x:  -4064, a_y:   4064, g_x:  -1776, g_y:   3443
         //Top product * 10: 67746880
         //g magnitude: 3874.070856
         //Ideal cross-product: 1748.725888
         //Predicted function output: 1749
      {    32,   8160,   3915,   8160,   3879}, 
         //[ 191]:  (-2,2,-1,2)
         //a_x:  -4064, a_y:   4064, g_x:   -181, g_y:   4064
         //Top product * 10: 157805120
         //g magnitude: 4068.028638
         //Ideal cross-product: 3879.154599
         //Predicted function output: 3879
      {    32,   8160,   4096,     32,   4064}, 
         //[ 192]:  (-2,2,0,-2)
         //a_x:  -4064, a_y:   4064, g_x:      0, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {    32,   8160,   4096,   1761,   4067}, 
         //[ 193]:  (-2,2,0,-1)
         //a_x:  -4064, a_y:   4064, g_x:      0, g_y:  -2335
         //Top product * 10: 94894400
         //g magnitude: 2335.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4067
      {    32,   8160,   4096,   4096,      0}, 
         //[ 194]:  (-2,2,0,0)
         //a_x:  -4064, a_y:   4064, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {    32,   8160,   4096,   5194,   4065}, 
         //[ 195]:  (-2,2,0,1)
         //a_x:  -4064, a_y:   4064, g_x:      0, g_y:   1098
         //Top product * 10: 44622720
         //g magnitude: 1098.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4065
      {    32,   8160,   4096,   8160,   4064}, 
         //[ 196]:  (-2,2,0,2)
         //a_x:  -4064, a_y:   4064, g_x:      0, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {    32,   8160,   5323,     32,   2717}, 
         //[ 197]:  (-2,2,1,-2)
         //a_x:  -4064, a_y:   4064, g_x:   1227, g_y:  -4064
         //Top product * 10: 115295680
         //g magnitude: 4245.188453
         //Ideal cross-product: 2715.914294
         //Predicted function output: 2717
      {    32,   8160,   7678,   2782,   2416}, 
         //[ 198]:  (-2,2,1,-1)
         //a_x:  -4064, a_y:   4064, g_x:   3582, g_y:  -1314
         //Top product * 10: 92171520
         //g magnitude: 3815.405614
         //Ideal cross-product: 2415.772511
         //Predicted function output: 2416
      {    32,   8160,   6085,   4096,   4067}, 
         //[ 199]:  (-2,2,1,0)
         //a_x:  -4064, a_y:   4064, g_x:   1989, g_y:      0
         //Top product * 10: 80832960
         //g magnitude: 1989.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4067
      {    32,   8160,   6348,   4479,   4693}, 
         //[ 200]:  (-2,2,1,1)
         //a_x:  -4064, a_y:   4064, g_x:   2252, g_y:    383
         //Top product * 10: 107086400
         //g magnitude: 2284.336446
         //Ideal cross-product: 4687.855862
         //Predicted function output: 4693
      {    32,   8160,   4793,   8160,   4694}, 
         //[ 201]:  (-2,2,1,2)
         //a_x:  -4064, a_y:   4064, g_x:    697, g_y:   4064
         //Top product * 10: 193487040
         //g magnitude: 4123.336634
         //Ideal cross-product: 4692.487108
         //Predicted function output: 4694
      {    32,   8160,   8160,     32,      0}, 
         //[ 202]:  (-2,2,2,-2)
         //a_x:  -4064, a_y:   4064, g_x:   4064, g_y:  -4064
         //Top product * 10: 0
         //g magnitude: 5747.363917
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {    32,   8160,   8160,   2168,   1930}, 
         //[ 203]:  (-2,2,2,-1)
         //a_x:  -4064, a_y:   4064, g_x:   4064, g_y:  -1928
         //Top product * 10: 86807040
         //g magnitude: 4498.141839
         //Ideal cross-product: 1929.842213
         //Predicted function output: 1930
      {    32,   8160,   8160,   4096,   4064}, 
         //[ 204]:  (-2,2,2,0)
         //a_x:  -4064, a_y:   4064, g_x:   4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {    32,   8160,   8160,   6486,   5564}, 
         //[ 205]:  (-2,2,2,1)
         //a_x:  -4064, a_y:   4064, g_x:   4064, g_y:   2390
         //Top product * 10: 262290560
         //g magnitude: 4714.678780
         //Ideal cross-product: 5563.275299
         //Predicted function output: 5564
      {    32,   8160,   8160,   8160,   5747}, 
         //[ 206]:  (-2,2,2,2)
         //a_x:  -4064, a_y:   4064, g_x:   4064, g_y:   4064
         //Top product * 10: 330321920
         //g magnitude: 5747.363917
         //Ideal cross-product: 5747.363917
         //Predicted function output: 5747
      {  3297,     32,     32,     32,   2308}, 
         //[ 207]:  (-1,-2,-2,-2)
         //a_x:   -799, a_y:  -4064, g_x:  -4064, g_y:  -4064
         //Top product * 10: 132689600
         //g magnitude: 5747.363917
         //Ideal cross-product: 2308.703641
         //Predicted function output: 2308
      {  1165,     32,     32,   4089,   4058}, 
         //[ 208]:  (-1,-2,-2,-1)
         //a_x:  -2931, a_y:  -4064, g_x:  -4064, g_y:     -7
         //Top product * 10: 164955790
         //g magnitude: 4064.006029
         //Ideal cross-product: 4058.945505
         //Predicted function output: 4058
      {  1449,     32,     32,   4096,   4064}, 
         //[ 209]:  (-1,-2,-2,0)
         //a_x:  -2647, a_y:  -4064, g_x:  -4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  2254,     32,     32,   5021,   4373}, 
         //[ 210]:  (-1,-2,-2,1)
         //a_x:  -1842, a_y:  -4064, g_x:  -4064, g_y:    925
         //Top product * 10: 182199460
         //g magnitude: 4167.939659
         //Ideal cross-product: 4371.451482
         //Predicted function output: 4373
      {   207,     32,     32,   8160,   5623}, 
         //[ 211]:  (-1,-2,-2,2)
         //a_x:  -3889, a_y:  -4064, g_x:  -4064, g_y:   4064
         //Top product * 10: 323209920
         //g magnitude: 5747.363917
         //Ideal cross-product: 5623.620231
         //Predicted function output: 5623
      {  1680,     32,   2037,     32,    318}, 
         //[ 212]:  (-1,-2,-1,-2)
         //a_x:  -2416, a_y:  -4064, g_x:  -2059, g_y:  -4064
         //Top product * 10: 14508480
         //g magnitude: 4555.828904
         //Ideal cross-product: 318.459721
         //Predicted function output: 318
      {  1488,     32,    709,   3091,   3154}, 
         //[ 213]:  (-1,-2,-1,-1)
         //a_x:  -2608, a_y:  -4064, g_x:  -3387, g_y:  -1005
         //Top product * 10: 111437280
         //g magnitude: 3532.958251
         //Ideal cross-product: 3154.220121
         //Predicted function output: 3154
      {  1466,     32,   2120,   4096,   4067}, 
         //[ 214]:  (-1,-2,-1,0)
         //a_x:  -2630, a_y:  -4064, g_x:  -1976, g_y:      0
         //Top product * 10: 80304640
         //g magnitude: 1976.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4067
      {   302,     32,   2408,   6596,   5422}, 
         //[ 215]:  (-1,-2,-1,1)
         //a_x:  -3794, a_y:  -4064, g_x:  -1688, g_y:   2500
         //Top product * 10: 163450320
         //g magnitude: 3016.511893
         //Ideal cross-product: 5418.520656
         //Predicted function output: 5422
      {  3184,     32,   3462,   8160,   1527}, 
         //[ 216]:  (-1,-2,-1,2)
         //a_x:   -912, a_y:  -4064, g_x:   -634, g_y:   4064
         //Top product * 10: 62829440
         //g magnitude: 4113.155966
         //Ideal cross-product: 1527.523890
         //Predicted function output: 1527
      {  3115,     32,   4096,     32,    981}, 
         //[ 217]:  (-1,-2,0,-2)
         //a_x:   -981, a_y:  -4064, g_x:      0, g_y:  -4064
         //Top product * 10: 39867840
         //g magnitude: 4064.000000
         //Ideal cross-product: 981.000000
         //Predicted function output: 981
      {  2745,     32,   4096,   1681,   1352}, 
         //[ 218]:  (-1,-2,0,-1)
         //a_x:  -1351, a_y:  -4064, g_x:      0, g_y:  -2415
         //Top product * 10: 32626650
         //g magnitude: 2415.000000
         //Ideal cross-product: 1351.000000
         //Predicted function output: 1352
      {  1702,     32,   4096,   4096,      0}, 
         //[ 219]:  (-1,-2,0,0)
         //a_x:  -2394, a_y:  -4064, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  2450,     32,   4096,   6970,   1646}, 
         //[ 220]:  (-1,-2,0,1)
         //a_x:  -1646, a_y:  -4064, g_x:      0, g_y:   2874
         //Top product * 10: 47306040
         //g magnitude: 2874.000000
         //Ideal cross-product: 1646.000000
         //Predicted function output: 1646
      {  3224,     32,   4096,   8160,    872}, 
         //[ 221]:  (-1,-2,0,2)
         //a_x:   -872, a_y:  -4064, g_x:      0, g_y:   4064
         //Top product * 10: 35438080
         //g magnitude: 4064.000000
         //Ideal cross-product: 872.000000
         //Predicted function output: 872
      {  1146,     32,   6398,     32,   4571}, 
         //[ 222]:  (-1,-2,1,-2)
         //a_x:  -2950, a_y:  -4064, g_x:   2302, g_y:  -4064
         //Top product * 10: 213441280
         //g magnitude: 4670.685175
         //Ideal cross-product: 4569.806613
         //Predicted function output: 4571
      {  1214,     32,   5444,   1951,   4606}, 
         //[ 223]:  (-1,-2,1,-1)
         //a_x:  -2882, a_y:  -4064, g_x:   1348, g_y:  -2145
         //Top product * 10: 116601620
         //g magnitude: 2533.402653
         //Ideal cross-product: 4602.569587
         //Predicted function output: 4606
      {   439,     32,   7048,   4096,   4066}, 
         //[ 224]:  (-1,-2,1,0)
         //a_x:  -3657, a_y:  -4064, g_x:   2952, g_y:      0
         //Top product * 10: 119969280
         //g magnitude: 2952.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4066
      {  3318,     32,   6789,   5373,   3340}, 
         //[ 225]:  (-1,-2,1,1)
         //a_x:   -778, a_y:  -4064, g_x:   2693, g_y:   1277
         //Top product * 10: 99508460
         //g magnitude: 2980.432519
         //Ideal cross-product: 3338.725483
         //Predicted function output: 3340
      {  1804,     32,   7409,   8160,    791}, 
         //[ 226]:  (-1,-2,1,2)
         //a_x:  -2292, a_y:  -4064, g_x:   3313, g_y:   4064
         //Top product * 10: 41493440
         //g magnitude: 5243.287614
         //Ideal cross-product: 791.363035
         //Predicted function output: 791
      {  2601,     32,   8160,     32,   3930}, 
         //[ 227]:  (-1,-2,2,-2)
         //a_x:  -1495, a_y:  -4064, g_x:   4064, g_y:  -4064
         //Top product * 10: 225917760
         //g magnitude: 5747.363917
         //Ideal cross-product: 3930.806597
         //Predicted function output: 3930
      {  3328,     32,   8160,   3665,   4122}, 
         //[ 228]:  (-1,-2,2,-1)
         //a_x:   -768, a_y:  -4064, g_x:   4064, g_y:   -431
         //Top product * 10: 168471040
         //g magnitude: 4086.790550
         //Ideal cross-product: 4122.331153
         //Predicted function output: 4122
      {  1645,     32,   8160,   4096,   4064}, 
         //[ 229]:  (-1,-2,2,0)
         //a_x:  -2451, a_y:  -4064, g_x:   4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  1704,     32,   8160,   5881,   2759}, 
         //[ 230]:  (-1,-2,2,1)
         //a_x:  -2392, a_y:  -4064, g_x:   4064, g_y:   1785
         //Top product * 10: 122463760
         //g magnitude: 4438.729661
         //Ideal cross-product: 2758.982172
         //Predicted function output: 2759
      {  1720,     32,   8160,   8160,   1193}, 
         //[ 231]:  (-1,-2,2,2)
         //a_x:  -2376, a_y:  -4064, g_x:   4064, g_y:   4064
         //Top product * 10: 68600320
         //g magnitude: 5747.363917
         //Ideal cross-product: 1193.596247
         //Predicted function output: 1193
      {  1108,   3116,     32,     32,   1419}, 
         //[ 232]:  (-1,-1,-2,-2)
         //a_x:  -2988, a_y:   -980, g_x:  -4064, g_y:  -4064
         //Top product * 10: 81605120
         //g magnitude: 5747.363917
         //Ideal cross-product: 1419.870417
         //Predicted function output: 1419
      {  2894,   3239,     32,   1955,    198}, 
         //[ 233]:  (-1,-1,-2,-1)
         //a_x:  -1202, a_y:   -857, g_x:  -4064, g_y:  -2141
         //Top product * 10: 9093660
         //g magnitude: 4593.471128
         //Ideal cross-product: 197.969243
         //Predicted function output: 198
      {  1675,   4004,     32,   4096,     92}, 
         //[ 234]:  (-1,-1,-2,0)
         //a_x:  -2421, a_y:    -92, g_x:  -4064, g_y:      0
         //Top product * 10: 3738880
         //g magnitude: 4064.000000
         //Ideal cross-product: 92.000000
         //Predicted function output: 92
      {  3182,    162,     32,   6891,   3760}, 
         //[ 235]:  (-1,-1,-2,1)
         //a_x:   -914, a_y:  -3934, g_x:  -4064, g_y:   2795
         //Top product * 10: 185424060
         //g magnitude: 4932.354509
         //Ideal cross-product: 3759.341703
         //Predicted function output: 3760
      {  2622,   2791,     32,   8160,   1965}, 
         //[ 236]:  (-1,-1,-2,2)
         //a_x:  -1474, a_y:  -1305, g_x:  -4064, g_y:   4064
         //Top product * 10: 112938560
         //g magnitude: 5747.363917
         //Ideal cross-product: 1965.049745
         //Predicted function output: 1965
      {  3904,   1419,   2333,     32,    889}, 
         //[ 237]:  (-1,-1,-1,-2)
         //a_x:   -192, a_y:  -2677, g_x:  -1763, g_y:  -4064
         //Top product * 10: 39392630
         //g magnitude: 4429.928329
         //Ideal cross-product: 889.238540
         //Predicted function output: 889
      {   720,    792,   1517,   2177,    635}, 
         //[ 238]:  (-1,-1,-1,-1)
         //a_x:  -3376, a_y:  -3304, g_x:  -2579, g_y:  -1919
         //Top product * 10: 20424720
         //g magnitude: 3214.623151
         //Ideal cross-product: 635.369032
         //Predicted function output: 635
      {  3624,   3409,    638,   4096,    687}, 
         //[ 239]:  (-1,-1,-1,0)
         //a_x:   -472, a_y:   -687, g_x:  -3458, g_y:      0
         //Top product * 10: 23756460
         //g magnitude: 3458.000000
         //Ideal cross-product: 687.000000
         //Predicted function output: 687
      {  3389,   2279,    562,   6624,   1890}, 
         //[ 240]:  (-1,-1,-1,1)
         //a_x:   -707, a_y:  -1817, g_x:  -3534, g_y:   2528
         //Top product * 10: 82085740
         //g magnitude: 4345.105292
         //Ideal cross-product: 1889.154220
         //Predicted function output: 1890
      {  1749,   3298,   3796,   8160,   2400}, 
         //[ 241]:  (-1,-1,-1,2)
         //a_x:  -2347, a_y:   -798, g_x:   -300, g_y:   4064
         //Top product * 10: 97776080
         //g magnitude: 4075.057791
         //Ideal cross-product: 2399.378979
         //Predicted function output: 2400
      {  1300,    645,   4096,     32,   2796}, 
         //[ 242]:  (-1,-1,0,-2)
         //a_x:  -2796, a_y:  -3451, g_x:      0, g_y:  -4064
         //Top product * 10: 113629440
         //g magnitude: 4064.000000
         //Ideal cross-product: 2796.000000
         //Predicted function output: 2796
      {  2021,   1911,   4096,    359,   2076}, 
         //[ 243]:  (-1,-1,0,-1)
         //a_x:  -2075, a_y:  -2185, g_x:      0, g_y:  -3737
         //Top product * 10: 77542750
         //g magnitude: 3737.000000
         //Ideal cross-product: 2075.000000
         //Predicted function output: 2076
      {  2897,    826,   4096,   4096,      0}, 
         //[ 244]:  (-1,-1,0,0)
         //a_x:  -1199, a_y:  -3270, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  2790,   2221,   4096,   5591,   1306}, 
         //[ 245]:  (-1,-1,0,1)
         //a_x:  -1306, a_y:  -1875, g_x:      0, g_y:   1495
         //Top product * 10: 19524700
         //g magnitude: 1495.000000
         //Ideal cross-product: 1306.000000
         //Predicted function output: 1306
      {  2855,    979,   4096,   8160,   1241}, 
         //[ 246]:  (-1,-1,0,2)
         //a_x:  -1241, a_y:  -3117, g_x:      0, g_y:   4064
         //Top product * 10: 50434240
         //g magnitude: 4064.000000
         //Ideal cross-product: 1241.000000
         //Predicted function output: 1241
      {  1071,   1940,   6965,     32,   3716}, 
         //[ 247]:  (-1,-1,1,-2)
         //a_x:  -3025, a_y:  -2156, g_x:   2869, g_y:  -4064
         //Top product * 10: 184791640
         //g magnitude: 4974.661496
         //Ideal cross-product: 3714.657573
         //Predicted function output: 3716
      {  3887,   3607,   6914,   3481,    522}, 
         //[ 248]:  (-1,-1,1,-1)
         //a_x:   -209, a_y:   -489, g_x:   2818, g_y:   -615
         //Top product * 10: 15065370
         //g magnitude: 2884.328171
         //Ideal cross-product: 522.318166
         //Predicted function output: 522
      {  1265,   1159,   5820,   4096,   2941}, 
         //[ 249]:  (-1,-1,1,0)
         //a_x:  -2831, a_y:  -2937, g_x:   1724, g_y:      0
         //Top product * 10: 50633880
         //g magnitude: 1724.000000
         //Ideal cross-product: 2937.000000
         //Predicted function output: 2941
      {  3880,   2662,   6185,   4709,   1315}, 
         //[ 250]:  (-1,-1,1,1)
         //a_x:   -216, a_y:  -1434, g_x:   2089, g_y:    613
         //Top product * 10: 28632180
         //g magnitude: 2177.082911
         //Ideal cross-product: 1315.162590
         //Predicted function output: 1315
      {  1278,   2951,   4200,   8160,   2788}, 
         //[ 251]:  (-1,-1,1,2)
         //a_x:  -2818, a_y:  -1145, g_x:    104, g_y:   4064
         //Top product * 10: 113332720
         //g magnitude: 4065.330491
         //Ideal cross-product: 2787.786141
         //Predicted function output: 2788
      {  3110,   3527,   8160,     32,   1099}, 
         //[ 252]:  (-1,-1,2,-2)
         //a_x:   -986, a_y:   -569, g_x:   4064, g_y:  -4064
         //Top product * 10: 63195200
         //g magnitude: 5747.363917
         //Ideal cross-product: 1099.551045
         //Predicted function output: 1099
      {   939,   2412,   8160,    639,   3328}, 
         //[ 253]:  (-1,-1,2,-1)
         //a_x:  -3157, a_y:  -1684, g_x:   4064, g_y:  -3457
         //Top product * 10: 177575250
         //g magnitude: 5335.442343
         //Ideal cross-product: 3328.219828
         //Predicted function output: 3328
      {  3665,    601,   8160,   4096,   3495}, 
         //[ 254]:  (-1,-1,2,0)
         //a_x:   -431, a_y:  -3495, g_x:   4064, g_y:      0
         //Top product * 10: 142036800
         //g magnitude: 4064.000000
         //Ideal cross-product: 3495.000000
         //Predicted function output: 3495
      {  3887,   2582,   8160,   6079,   1269}, 
         //[ 255]:  (-1,-1,2,1)
         //a_x:   -209, a_y:  -1514, g_x:   4064, g_y:   1983
         //Top product * 10: 57384490
         //g magnitude: 4521.989054
         //Ideal cross-product: 1269.009927
         //Predicted function output: 1269
      {  1986,   3309,   8160,   8160,    935}, 
         //[ 256]:  (-1,-1,2,2)
         //a_x:  -2110, a_y:   -787, g_x:   4064, g_y:   4064
         //Top product * 10: 53766720
         //g magnitude: 5747.363917
         //Ideal cross-product: 935.502272
         //Predicted function output: 935
      {  1069,   4096,     32,     32,   2140}, 
         //[ 257]:  (-1,0,-2,-2)
         //a_x:  -3027, a_y:      0, g_x:  -4064, g_y:  -4064
         //Top product * 10: 123017280
         //g magnitude: 5747.363917
         //Ideal cross-product: 2140.412227
         //Predicted function output: 2140
      {  1375,   4096,     32,   2758,    850}, 
         //[ 258]:  (-1,0,-2,-1)
         //a_x:  -2721, a_y:      0, g_x:  -4064, g_y:  -1338
         //Top product * 10: 36406980
         //g magnitude: 4278.590890
         //Ideal cross-product: 850.910520
         //Predicted function output: 850
      {  3385,   4096,     32,   4096,      0}, 
         //[ 259]:  (-1,0,-2,0)
         //a_x:   -711, a_y:      0, g_x:  -4064, g_y:      0
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4084,   4096,     32,   5889,      4}, 
         //[ 260]:  (-1,0,-2,1)
         //a_x:    -12, a_y:      0, g_x:  -4064, g_y:   1793
         //Top product * 10: 215160
         //g magnitude: 4441.952836
         //Ideal cross-product: 4.843816
         //Predicted function output: 4
      {   914,   4096,     32,   8160,   2250}, 
         //[ 261]:  (-1,0,-2,2)
         //a_x:  -3182, a_y:      0, g_x:  -4064, g_y:   4064
         //Top product * 10: 129316480
         //g magnitude: 5747.363917
         //Ideal cross-product: 2250.013778
         //Predicted function output: 2250
      {  3951,   4096,   3201,     32,    141}, 
         //[ 262]:  (-1,0,-1,-2)
         //a_x:   -145, a_y:      0, g_x:   -895, g_y:  -4064
         //Top product * 10: 5892800
         //g magnitude: 4161.384505
         //Ideal cross-product: 141.606717
         //Predicted function output: 141
      {  1075,   4096,   2076,   2397,   1946}, 
         //[ 263]:  (-1,0,-1,-1)
         //a_x:  -3021, a_y:      0, g_x:  -2020, g_y:  -1699
         //Top product * 10: 51326790
         //g magnitude: 2639.507719
         //Ideal cross-product: 1944.559193
         //Predicted function output: 1946
      {  2115,   4096,   1278,   4096,      0}, 
         //[ 264]:  (-1,0,-1,0)
         //a_x:  -1981, a_y:      0, g_x:  -2818, g_y:      0
         //Top product * 10: 0
         //g magnitude: 2818.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {   412,   4096,    631,   4646,    577}, 
         //[ 265]:  (-1,0,-1,1)
         //a_x:  -3684, a_y:      0, g_x:  -3465, g_y:    550
         //Top product * 10: 20262000
         //g magnitude: 3508.379255
         //Ideal cross-product: 577.531633
         //Predicted function output: 577
      {  2159,   4096,   3161,   8160,   1887}, 
         //[ 266]:  (-1,0,-1,2)
         //a_x:  -1937, a_y:      0, g_x:   -935, g_y:   4064
         //Top product * 10: 78719680
         //g magnitude: 4170.170380
         //Ideal cross-product: 1887.684982
         //Predicted function output: 1887
      {  1466,   4096,   4096,     32,   2630}, 
         //[ 267]:  (-1,0,0,-2)
         //a_x:  -2630, a_y:      0, g_x:      0, g_y:  -4064
         //Top product * 10: 106883200
         //g magnitude: 4064.000000
         //Ideal cross-product: 2630.000000
         //Predicted function output: 2630
      {   727,   4096,   4096,   1329,   3371}, 
         //[ 268]:  (-1,0,0,-1)
         //a_x:  -3369, a_y:      0, g_x:      0, g_y:  -2767
         //Top product * 10: 93220230
         //g magnitude: 2767.000000
         //Ideal cross-product: 3369.000000
         //Predicted function output: 3371
      {  1611,   4096,   4096,   4096,      0}, 
         //[ 269]:  (-1,0,0,0)
         //a_x:  -2485, a_y:      0, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  3916,   4096,   4096,   4686,    180}, 
         //[ 270]:  (-1,0,0,1)
         //a_x:   -180, a_y:      0, g_x:      0, g_y:    590
         //Top product * 10: 1062000
         //g magnitude: 590.000000
         //Ideal cross-product: 180.000000
         //Predicted function output: 180
      {  2648,   4096,   4096,   8160,   1448}, 
         //[ 271]:  (-1,0,0,2)
         //a_x:  -1448, a_y:      0, g_x:      0, g_y:   4064
         //Top product * 10: 58846720
         //g magnitude: 4064.000000
         //Ideal cross-product: 1448.000000
         //Predicted function output: 1448
      {  2621,   4096,   6815,     32,   1225}, 
         //[ 272]:  (-1,0,1,-2)
         //a_x:  -1475, a_y:      0, g_x:   2719, g_y:  -4064
         //Top product * 10: 59944000
         //g magnitude: 4889.688845
         //Ideal cross-product: 1225.926678
         //Predicted function output: 1225
      {  3526,   4096,   6891,   1969,    345}, 
         //[ 273]:  (-1,0,1,-1)
         //a_x:   -570, a_y:      0, g_x:   2795, g_y:  -2127
         //Top product * 10: 12123900
         //g magnitude: 3512.286150
         //Ideal cross-product: 345.185429
         //Predicted function output: 345
      {  2544,   4096,   5076,   4096,      0}, 
         //[ 274]:  (-1,0,1,0)
         //a_x:  -1552, a_y:      0, g_x:    980, g_y:      0
         //Top product * 10: 0
         //g magnitude: 980.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {   390,   4096,   5231,   7795,   3543}, 
         //[ 275]:  (-1,0,1,1)
         //a_x:  -3706, a_y:      0, g_x:   1135, g_y:   3699
         //Top product * 10: 137084940
         //g magnitude: 3869.215166
         //Ideal cross-product: 3542.965023
         //Predicted function output: 3543
      {   683,   4096,   4604,   8160,   3388}, 
         //[ 276]:  (-1,0,1,2)
         //a_x:  -3413, a_y:      0, g_x:    508, g_y:   4064
         //Top product * 10: 138704320
         //g magnitude: 4095.626936
         //Ideal cross-product: 3386.644393
         //Predicted function output: 3388
      {  3240,   4096,   8160,     32,    605}, 
         //[ 277]:  (-1,0,2,-2)
         //a_x:   -856, a_y:      0, g_x:   4064, g_y:  -4064
         //Top product * 10: 34787840
         //g magnitude: 5747.363917
         //Ideal cross-product: 605.283405
         //Predicted function output: 605
      {   813,   4096,   8160,   1728,   1653}, 
         //[ 278]:  (-1,0,2,-1)
         //a_x:  -3283, a_y:      0, g_x:   4064, g_y:  -2368
         //Top product * 10: 77741440
         //g magnitude: 4703.564606
         //Ideal cross-product: 1652.819649
         //Predicted function output: 1653
      {  3095,   4096,   8160,   4096,      0}, 
         //[ 279]:  (-1,0,2,0)
         //a_x:  -1001, a_y:      0, g_x:   4064, g_y:      0
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  3550,   4096,   8160,   6894,    309}, 
         //[ 280]:  (-1,0,2,1)
         //a_x:   -546, a_y:      0, g_x:   4064, g_y:   2798
         //Top product * 10: 15277080
         //g magnitude: 4934.055127
         //Ideal cross-product: 309.625239
         //Predicted function output: 309
      {  2006,   4096,   8160,   8160,   1477}, 
         //[ 281]:  (-1,0,2,2)
         //a_x:  -2090, a_y:      0, g_x:   4064, g_y:   4064
         //Top product * 10: 84937600
         //g magnitude: 5747.363917
         //Ideal cross-product: 1477.853173
         //Predicted function output: 1477
      {   371,   7983,     32,     32,   5382}, 
         //[ 282]:  (-1,1,-2,-2)
         //a_x:  -3725, a_y:   3887, g_x:  -4064, g_y:  -4064
         //Top product * 10: 309351680
         //g magnitude: 5747.363917
         //Ideal cross-product: 5382.496818
         //Predicted function output: 5382
      {  2280,   7946,     32,   2222,   4258}, 
         //[ 283]:  (-1,1,-2,-1)
         //a_x:  -1816, a_y:   3850, g_x:  -4064, g_y:  -1874
         //Top product * 10: 190495840
         //g magnitude: 4475.262227
         //Ideal cross-product: 4256.640848
         //Predicted function output: 4258
      {  2635,   5421,     32,   4096,   1325}, 
         //[ 284]:  (-1,1,-2,0)
         //a_x:  -1461, a_y:   1325, g_x:  -4064, g_y:      0
         //Top product * 10: 53848000
         //g magnitude: 4064.000000
         //Ideal cross-product: 1325.000000
         //Predicted function output: 1325
      {  3045,   5387,     32,   7387,    341}, 
         //[ 285]:  (-1,1,-2,1)
         //a_x:  -1051, a_y:   1291, g_x:  -4064, g_y:   3291
         //Top product * 10: 17877830
         //g magnitude: 5229.414594
         //Ideal cross-product: 341.870580
         //Predicted function output: 341
      {  2693,   4236,     32,   8160,    893}, 
         //[ 286]:  (-1,1,-2,2)
         //a_x:  -1403, a_y:    140, g_x:  -4064, g_y:   4064
         //Top product * 10: 51328320
         //g magnitude: 5747.363917
         //Ideal cross-product: 893.075865
         //Predicted function output: 893
      {  3198,   4936,   3009,     32,   1085}, 
         //[ 287]:  (-1,1,-1,-2)
         //a_x:   -898, a_y:    840, g_x:  -1087, g_y:  -4064
         //Top product * 10: 45625520
         //g magnitude: 4206.859280
         //Ideal cross-product: 1084.550658
         //Predicted function output: 1085
      {   657,   7694,   1068,   2044,   4908}, 
         //[ 288]:  (-1,1,-1,-1)
         //a_x:  -3439, a_y:   3598, g_x:  -3028, g_y:  -2052
         //Top product * 10: 179515720
         //g magnitude: 3657.798245
         //Ideal cross-product: 4907.753462
         //Predicted function output: 4908
      {  3780,   6541,   2073,   4096,   2445}, 
         //[ 289]:  (-1,1,-1,0)
         //a_x:   -316, a_y:   2445, g_x:  -2023, g_y:      0
         //Top product * 10: 49462350
         //g magnitude: 2023.000000
         //Ideal cross-product: 2445.000000
         //Predicted function output: 2445
      {  2711,   4603,   1866,   6604,    698}, 
         //[ 290]:  (-1,1,-1,1)
         //a_x:  -1385, a_y:    507, g_x:  -2230, g_y:   2508
         //Top product * 10: 23429700
         //g magnitude: 3356.033969
         //Ideal cross-product: 698.136557
         //Predicted function output: 698
      {  3438,   6734,   3857,   8160,    502}, 
         //[ 291]:  (-1,1,-1,2)
         //a_x:   -658, a_y:   2638, g_x:   -239, g_y:   4064
         //Top product * 10: 20436300
         //g magnitude: 4071.021616
         //Ideal cross-product: 501.994387
         //Predicted function output: 502
      {  3351,   7378,   4096,     32,    745}, 
         //[ 292]:  (-1,1,0,-2)
         //a_x:   -745, a_y:   3282, g_x:      0, g_y:  -4064
         //Top product * 10: 30276800
         //g magnitude: 4064.000000
         //Ideal cross-product: 745.000000
         //Predicted function output: 745
      {  3911,   5440,   4096,   1420,    185}, 
         //[ 293]:  (-1,1,0,-1)
         //a_x:   -185, a_y:   1344, g_x:      0, g_y:  -2676
         //Top product * 10: 4950600
         //g magnitude: 2676.000000
         //Ideal cross-product: 185.000000
         //Predicted function output: 185
      {  3552,   6112,   4096,   4096,      0}, 
         //[ 294]:  (-1,1,0,0)
         //a_x:   -544, a_y:   2016, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {   913,   5437,   4096,   4273,   3186}, 
         //[ 295]:  (-1,1,0,1)
         //a_x:  -3183, a_y:   1341, g_x:      0, g_y:    177
         //Top product * 10: 5633910
         //g magnitude: 177.000000
         //Ideal cross-product: 3183.000000
         //Predicted function output: 3260
         //DTA 20091212:  Expected value adjusted to
         //3186.  Presumed cause of disagreement is g-vector
         //normalization due to sub-1024 values of components.
         //G-vector normalization seems to lead to closer
         //value to ideal.
      {  2276,   6188,   4096,   8160,   1820}, 
         //[ 296]:  (-1,1,0,2)
         //a_x:  -1820, a_y:   2092, g_x:      0, g_y:   4064
         //Top product * 10: 73964800
         //g magnitude: 4064.000000
         //Ideal cross-product: 1820.000000
         //Predicted function output: 1820
      {  3996,   6246,   7642,     32,   1338}, 
         //[ 297]:  (-1,1,1,-2)
         //a_x:   -100, a_y:   2150, g_x:   3546, g_y:  -4064
         //Top product * 10: 72175000
         //g magnitude: 5393.534277
         //Ideal cross-product: 1338.176348
         //Predicted function output: 1338
      {  3246,   5391,   4940,   1440,    418}, 
         //[ 298]:  (-1,1,1,-1)
         //a_x:   -850, a_y:   1295, g_x:    844, g_y:  -2656
         //Top product * 10: 11646200
         //g magnitude: 2786.874952
         //Ideal cross-product: 417.894602
         //Predicted function output: 418
      {  3743,   7763,   4427,   4096,   3673}, 
         //[ 299]:  (-1,1,1,0)
         //a_x:   -353, a_y:   3667, g_x:    331, g_y:      0
         //Top product * 10: 12137770
         //g magnitude: 331.000000
         //Ideal cross-product: 3667.000000
         //Predicted function output: 3718
         //DTA 20091212:  Expected value adjusted to
         //3673.  Presumed cause of disagreement is g-vector
         //normalization due to sub-1024 values of components.
         //G-vector normalization seems to lead to closer
         //value to ideal.
      {  1527,   6545,   4443,   6826,   2860}, 
         //[ 300]:  (-1,1,1,1)
         //a_x:  -2569, a_y:   2449, g_x:    347, g_y:   2730
         //Top product * 10: 78631730
         //g magnitude: 2751.964571
         //Ideal cross-product: 2857.294415
         //Predicted function output: 2860
      {  2062,   5615,   5082,   8160,   2336}, 
         //[ 301]:  (-1,1,1,2)
         //a_x:  -2034, a_y:   1519, g_x:    986, g_y:   4064
         //Top product * 10: 97639100
         //g magnitude: 4181.900525
         //Ideal cross-product: 2334.802070
         //Predicted function output: 2336
      {  1157,   5497,   8160,     32,   1087}, 
         //[ 302]:  (-1,1,2,-2)
         //a_x:  -2939, a_y:   1401, g_x:   4064, g_y:  -4064
         //Top product * 10: 62504320
         //g magnitude: 5747.363917
         //Ideal cross-product: 1087.530229
         //Predicted function output: 1087
      {   778,   5397,   8160,   3114,    485}, 
         //[ 303]:  (-1,1,2,-1)
         //a_x:  -3318, a_y:   1301, g_x:   4064, g_y:   -982
         //Top product * 10: 20289880
         //g magnitude: 4180.959220
         //Ideal cross-product: 485.292464
         //Predicted function output: 485
      {  2239,   4451,   8160,   4096,    355}, 
         //[ 304]:  (-1,1,2,0)
         //a_x:  -1857, a_y:    355, g_x:   4064, g_y:      0
         //Top product * 10: 14427200
         //g magnitude: 4064.000000
         //Ideal cross-product: 355.000000
         //Predicted function output: 355
      {  3873,   7118,   8160,   6885,   2618}, 
         //[ 305]:  (-1,1,2,1)
         //a_x:   -223, a_y:   3022, g_x:   4064, g_y:   2789
         //Top product * 10: 129033550
         //g magnitude: 4928.956989
         //Ideal cross-product: 2617.867234
         //Predicted function output: 2618
      {  1306,   7027,   8160,   8160,   4045}, 
         //[ 306]:  (-1,1,2,2)
         //a_x:  -2790, a_y:   2931, g_x:   4064, g_y:   4064
         //Top product * 10: 232501440
         //g magnitude: 5747.363917
         //Ideal cross-product: 4045.357895
         //Predicted function output: 4045
      {  1820,   8160,     32,     32,   4483}, 
         //[ 307]:  (-1,2,-2,-2)
         //a_x:  -2276, a_y:   4064, g_x:  -4064, g_y:  -4064
         //Top product * 10: 257657600
         //g magnitude: 5747.363917
         //Ideal cross-product: 4483.056993
         //Predicted function output: 4483
      {  1614,   8160,     32,   3677,   4299}, 
         //[ 308]:  (-1,2,-2,-1)
         //a_x:  -2482, a_y:   4064, g_x:  -4064, g_y:   -419
         //Top product * 10: 175560540
         //g magnitude: 4085.542436
         //Ideal cross-product: 4297.117035
         //Predicted function output: 4299
      {  3186,   8160,     32,   4096,   4064}, 
         //[ 309]:  (-1,2,-2,0)
         //a_x:   -910, a_y:   4064, g_x:  -4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  2486,   8160,     32,   4227,   4012}, 
         //[ 310]:  (-1,2,-2,1)
         //a_x:  -1610, a_y:   4064, g_x:  -4064, g_y:    131
         //Top product * 10: 163051860
         //g magnitude: 4066.110795
         //Ideal cross-product: 4010.020096
         //Predicted function output: 4012
      {  3290,   8160,     32,   8160,   2303}, 
         //[ 311]:  (-1,2,-2,2)
         //a_x:   -806, a_y:   4064, g_x:  -4064, g_y:   4064
         //Top product * 10: 132405120
         //g magnitude: 5747.363917
         //Ideal cross-product: 2303.753893
         //Predicted function output: 2303
      {   723,   8160,   2575,     32,   4583}, 
         //[ 312]:  (-1,2,-1,-2)
         //a_x:  -3373, a_y:   4064, g_x:  -1521, g_y:  -4064
         //Top product * 10: 198892160
         //g magnitude: 4339.301441
         //Ideal cross-product: 4583.506416
         //Predicted function output: 4583
      {  1060,   8160,    334,   1915,   5041}, 
         //[ 313]:  (-1,2,-1,-1)
         //a_x:  -3036, a_y:   4064, g_x:  -3762, g_y:  -2181
         //Top product * 10: 219102840
         //g magnitude: 4348.494567
         //Ideal cross-product: 5038.590635
         //Predicted function output: 5041
      {  1126,   8160,    620,   4096,   4064}, 
         //[ 314]:  (-1,2,-1,0)
         //a_x:  -2970, a_y:   4064, g_x:  -3476, g_y:      0
         //Top product * 10: 141264640
         //g magnitude: 3476.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  2248,   8160,   1562,   5716,   2430}, 
         //[ 315]:  (-1,2,-1,1)
         //a_x:  -1848, a_y:   4064, g_x:  -2534, g_y:   1620
         //Top product * 10: 73044160
         //g magnitude: 3007.583083
         //Ideal cross-product: 2428.666407
         //Predicted function output: 2430
      {   669,   8160,    921,   8160,    198}, 
         //[ 316]:  (-1,2,-1,2)
         //a_x:  -3427, a_y:   4064, g_x:  -3175, g_y:   4064
         //Top product * 10: 10241280
         //g magnitude: 5157.200888
         //Ideal cross-product: 198.582142
         //Predicted function output: 198
      {  3626,   8160,   4096,     32,    470}, 
         //[ 317]:  (-1,2,0,-2)
         //a_x:   -470, a_y:   4064, g_x:      0, g_y:  -4064
         //Top product * 10: 19100800
         //g magnitude: 4064.000000
         //Ideal cross-product: 470.000000
         //Predicted function output: 470
      {  2415,   8160,   4096,   2080,   1681}, 
         //[ 318]:  (-1,2,0,-1)
         //a_x:  -1681, a_y:   4064, g_x:      0, g_y:  -2016
         //Top product * 10: 33888960
         //g magnitude: 2016.000000
         //Ideal cross-product: 1681.000000
         //Predicted function output: 1681
      {  1566,   8160,   4096,   4096,      0}, 
         //[ 319]:  (-1,2,0,0)
         //a_x:  -2530, a_y:   4064, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  2593,   8160,   4096,   7420,   1504}, 
         //[ 320]:  (-1,2,0,1)
         //a_x:  -1503, a_y:   4064, g_x:      0, g_y:   3324
         //Top product * 10: 49959720
         //g magnitude: 3324.000000
         //Ideal cross-product: 1503.000000
         //Predicted function output: 1504
      {  3042,   8160,   4096,   8160,   1054}, 
         //[ 321]:  (-1,2,0,2)
         //a_x:  -1054, a_y:   4064, g_x:      0, g_y:   4064
         //Top product * 10: 42834560
         //g magnitude: 4064.000000
         //Ideal cross-product: 1054.000000
         //Predicted function output: 1054
      {   234,   8160,   6924,     32,    848}, 
         //[ 322]:  (-1,2,1,-2)
         //a_x:  -3862, a_y:   4064, g_x:   2828, g_y:  -4064
         //Top product * 10: 42021760
         //g magnitude: 4951.129164
         //Ideal cross-product: 848.730837
         //Predicted function output: 848
      {  1293,   8160,   7639,    999,   1215}, 
         //[ 323]:  (-1,2,1,-1)
         //a_x:  -2803, a_y:   4064, g_x:   3543, g_y:  -3097
         //Top product * 10: 57178610
         //g magnitude: 4705.768588
         //Ideal cross-product: 1215.074837
         //Predicted function output: 1215
      {  2246,   8160,   6015,   4096,   4068}, 
         //[ 324]:  (-1,2,1,0)
         //a_x:  -1850, a_y:   4064, g_x:   1919, g_y:      0
         //Top product * 10: 77988160
         //g magnitude: 1919.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4068
      {  2921,   8160,   4300,   4783,   2287}, 
         //[ 325]:  (-1,2,1,1)
         //a_x:  -1175, a_y:   4064, g_x:    204, g_y:    687
         //Top product * 10: 16362810
         //g magnitude: 716.648449
         //Ideal cross-product: 2283.240829
         //Predicted function output: 2292
         //DTA 20091212:  Expected value adjusted to
         //2287.  Presumed cause of disagreement is g-vector
         //normalization due to sub-1024 values of components.
         //G-vector normalization seems to lead to closer
         //value to ideal.
      {  1745,   8160,   7160,   8160,   4325}, 
         //[ 326]:  (-1,2,1,2)
         //a_x:  -2351, a_y:   4064, g_x:   3064, g_y:   4064
         //Top product * 10: 220065600
         //g magnitude: 5089.616096
         //Ideal cross-product: 4323.815311
         //Predicted function output: 4325
      {  2343,   8160,   8160,     32,   1634}, 
         //[ 327]:  (-1,2,2,-2)
         //a_x:  -1753, a_y:   4064, g_x:   4064, g_y:  -4064
         //Top product * 10: 93919040
         //g magnitude: 5747.363917
         //Ideal cross-product: 1634.123771
         //Predicted function output: 1634
      {  1088,   8160,   8160,   1513,   1817}, 
         //[ 328]:  (-1,2,2,-1)
         //a_x:  -3008, a_y:   4064, g_x:   4064, g_y:  -2583
         //Top product * 10: 87464320
         //g magnitude: 4815.390431
         //Ideal cross-product: 1816.349500
         //Predicted function output: 1817
      {  3743,   8160,   8160,   4096,   4064}, 
         //[ 329]:  (-1,2,2,0)
         //a_x:   -353, a_y:   4064, g_x:   4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  1998,   8160,   8160,   5237,   4480}, 
         //[ 330]:  (-1,2,2,1)
         //a_x:  -2098, a_y:   4064, g_x:   4064, g_y:   1141
         //Top product * 10: 189099140
         //g magnitude: 4221.134563
         //Ideal cross-product: 4479.817859
         //Predicted function output: 4480
      {   358,   8160,   8160,   8160,   5517}, 
         //[ 331]:  (-1,2,2,2)
         //a_x:  -3738, a_y:   4064, g_x:   4064, g_y:   4064
         //Top product * 10: 317073280
         //g magnitude: 5747.363917
         //Ideal cross-product: 5516.847107
         //Predicted function output: 5517
      {  4096,     32,     32,     32,   2873}, 
         //[ 332]:  (0,-2,-2,-2)
         //a_x:      0, a_y:  -4064, g_x:  -4064, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 5747.363917
         //Ideal cross-product: 2873.681959
         //Predicted function output: 2873
      {  4096,     32,     32,    236,   2947}, 
         //[ 333]:  (0,-2,-2,-1)
         //a_x:      0, a_y:  -4064, g_x:  -4064, g_y:  -3860
         //Top product * 10: 165160960
         //g magnitude: 5604.970651
         //Ideal cross-product: 2946.687330
         //Predicted function output: 2947
      {  4096,     32,     32,   4096,   4064}, 
         //[ 334]:  (0,-2,-2,0)
         //a_x:      0, a_y:  -4064, g_x:  -4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  4096,     32,     32,   6373,   3547}, 
         //[ 335]:  (0,-2,-2,1)
         //a_x:      0, a_y:  -4064, g_x:  -4064, g_y:   2277
         //Top product * 10: 165160960
         //g magnitude: 4658.414430
         //Ideal cross-product: 3545.432947
         //Predicted function output: 3547
      {  4096,     32,     32,   8160,   2873}, 
         //[ 336]:  (0,-2,-2,2)
         //a_x:      0, a_y:  -4064, g_x:  -4064, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 5747.363917
         //Ideal cross-product: 2873.681959
         //Predicted function output: 2873
      {  4096,     32,   2059,     32,   1821}, 
         //[ 337]:  (0,-2,-1,-2)
         //a_x:      0, a_y:  -4064, g_x:  -2037, g_y:  -4064
         //Top product * 10: 82783680
         //g magnitude: 4545.928398
         //Ideal cross-product: 1821.051120
         //Predicted function output: 1821
      {  4096,     32,   2504,   1668,   2229}, 
         //[ 338]:  (0,-2,-1,-1)
         //a_x:      0, a_y:  -4064, g_x:  -1592, g_y:  -2428
         //Top product * 10: 64698880
         //g magnitude: 2903.385610
         //Ideal cross-product: 2228.394319
         //Predicted function output: 2229
      {  4096,     32,   2918,   4096,   4065}, 
         //[ 339]:  (0,-2,-1,0)
         //a_x:      0, a_y:  -4064, g_x:  -1178, g_y:      0
         //Top product * 10: 47873920
         //g magnitude: 1178.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4065
      {  4096,     32,   4087,   6816,     13}, 
         //[ 340]:  (0,-2,-1,1)
         //a_x:      0, a_y:  -4064, g_x:     -9, g_y:   2720
         //Top product * 10: 365760
         //g magnitude: 2720.014890
         //Ideal cross-product: 13.446985
         //Predicted function output: 13
      {  4096,     32,   2307,   8160,   1638}, 
         //[ 341]:  (0,-2,-1,2)
         //a_x:      0, a_y:  -4064, g_x:  -1789, g_y:   4064
         //Top product * 10: 72704960
         //g magnitude: 4440.339739
         //Ideal cross-product: 1637.373811
         //Predicted function output: 1638
      {  4096,     32,   4096,     32,      0}, 
         //[ 342]:  (0,-2,0,-2)
         //a_x:      0, a_y:  -4064, g_x:      0, g_y:  -4064
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,     32,   4096,   1418,      0}, 
         //[ 343]:  (0,-2,0,-1)
         //a_x:      0, a_y:  -4064, g_x:      0, g_y:  -2678
         //Top product * 10: 0
         //g magnitude: 2678.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,     32,   4096,   4096,      0}, 
         //[ 344]:  (0,-2,0,0)
         //a_x:      0, a_y:  -4064, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,     32,   4096,   7942,      0}, 
         //[ 345]:  (0,-2,0,1)
         //a_x:      0, a_y:  -4064, g_x:      0, g_y:   3846
         //Top product * 10: 0
         //g magnitude: 3846.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,     32,   4096,   8160,      0}, 
         //[ 346]:  (0,-2,0,2)
         //a_x:      0, a_y:  -4064, g_x:      0, g_y:   4064
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,     32,   6633,     32,   2152}, 
         //[ 347]:  (0,-2,1,-2)
         //a_x:      0, a_y:  -4064, g_x:   2537, g_y:  -4064
         //Top product * 10: 103103680
         //g magnitude: 4790.873094
         //Ideal cross-product: 2152.085392
         //Predicted function output: 2152
      {  4096,     32,   7588,   1335,   3188}, 
         //[ 348]:  (0,-2,1,-1)
         //a_x:      0, a_y:  -4064, g_x:   3492, g_y:  -2761
         //Top product * 10: 141914880
         //g magnitude: 4451.649694
         //Ideal cross-product: 3187.916610
         //Predicted function output: 3188
      {  4096,     32,   6285,   4096,   4064}, 
         //[ 349]:  (0,-2,1,0)
         //a_x:      0, a_y:  -4064, g_x:   2189, g_y:      0
         //Top product * 10: 88960960
         //g magnitude: 2189.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  4096,     32,   6527,   4972,   3825}, 
         //[ 350]:  (0,-2,1,1)
         //a_x:      0, a_y:  -4064, g_x:   2431, g_y:    876
         //Top product * 10: 98795840
         //g magnitude: 2584.015673
         //Ideal cross-product: 3823.345230
         //Predicted function output: 3825
      {  4096,     32,   7935,   8160,   2790}, 
         //[ 351]:  (0,-2,1,2)
         //a_x:      0, a_y:  -4064, g_x:   3839, g_y:   4064
         //Top product * 10: 156016960
         //g magnitude: 5590.529224
         //Ideal cross-product: 2790.736865
         //Predicted function output: 2790
      {  4096,     32,   8160,     32,   2873}, 
         //[ 352]:  (0,-2,2,-2)
         //a_x:      0, a_y:  -4064, g_x:   4064, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 5747.363917
         //Ideal cross-product: 2873.681959
         //Predicted function output: 2873
      {  4096,     32,   8160,    890,   3191}, 
         //[ 353]:  (0,-2,2,-1)
         //a_x:      0, a_y:  -4064, g_x:   4064, g_y:  -3206
         //Top product * 10: 165160960
         //g magnitude: 5176.343497
         //Ideal cross-product: 3190.687791
         //Predicted function output: 3191
      {  4096,     32,   8160,   4096,   4064}, 
         //[ 354]:  (0,-2,2,0)
         //a_x:      0, a_y:  -4064, g_x:   4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  4096,     32,   8160,   4472,   4048}, 
         //[ 355]:  (0,-2,2,1)
         //a_x:      0, a_y:  -4064, g_x:   4064, g_y:    376
         //Top product * 10: 165160960
         //g magnitude: 4081.356637
         //Ideal cross-product: 4046.717175
         //Predicted function output: 4048
      {  4096,     32,   8160,   8160,   2873}, 
         //[ 356]:  (0,-2,2,2)
         //a_x:      0, a_y:  -4064, g_x:   4064, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 5747.363917
         //Ideal cross-product: 2873.681959
         //Predicted function output: 2873
      {  4096,   2157,     32,     32,   1371}, 
         //[ 357]:  (0,-1,-2,-2)
         //a_x:      0, a_y:  -1939, g_x:  -4064, g_y:  -4064
         //Top product * 10: 78800960
         //g magnitude: 5747.363917
         //Ideal cross-product: 1371.080049
         //Predicted function output: 1371
      {  4096,   3286,     32,   1579,    689}, 
         //[ 358]:  (0,-1,-2,-1)
         //a_x:      0, a_y:   -810, g_x:  -4064, g_y:  -2517
         //Top product * 10: 32918400
         //g magnitude: 4780.312228
         //Ideal cross-product: 688.624475
         //Predicted function output: 689
      {  4096,   2482,     32,   4096,   1614}, 
         //[ 359]:  (0,-1,-2,0)
         //a_x:      0, a_y:  -1614, g_x:  -4064, g_y:      0
         //Top product * 10: 65592960
         //g magnitude: 4064.000000
         //Ideal cross-product: 1614.000000
         //Predicted function output: 1614
      {  4096,   1900,     32,   7188,   1748}, 
         //[ 360]:  (0,-1,-2,1)
         //a_x:      0, a_y:  -2196, g_x:  -4064, g_y:   3092
         //Top product * 10: 89245440
         //g magnitude: 5106.521321
         //Ideal cross-product: 1747.675852
         //Predicted function output: 1748
      {  4096,   1253,     32,   8160,   2010}, 
         //[ 361]:  (0,-1,-2,2)
         //a_x:      0, a_y:  -2843, g_x:  -4064, g_y:   4064
         //Top product * 10: 115539520
         //g magnitude: 5747.363917
         //Ideal cross-product: 2010.304579
         //Predicted function output: 2010
      {  4096,   3617,   1411,     32,    264}, 
         //[ 362]:  (0,-1,-1,-2)
         //a_x:      0, a_y:   -479, g_x:  -2685, g_y:  -4064
         //Top product * 10: 12861150
         //g magnitude: 4870.864502
         //Ideal cross-product: 264.042451
         //Predicted function output: 264
      {  4096,   3455,   3672,   3846,    552}, 
         //[ 363]:  (0,-1,-1,-1)
         //a_x:      0, a_y:   -641, g_x:   -424, g_y:   -250
         //Top product * 10: 2717840
         //g magnitude: 492.215400
         //Ideal cross-product: 552.164764
         //Predicted function output: 555
         //DTA 20091212:  Expected value adjusted to
         //552.  Presumed cause of disagreement is g-vector
         //normalization due to sub-1024 values of components.
         //G-vector normalization seems to lead to closer
         //value to ideal.
      {  4096,   1070,   3916,   4096,   3026}, 
         //[ 364]:  (0,-1,-1,0)
         //a_x:      0, a_y:  -3026, g_x:   -180, g_y:      0
         //Top product * 10: 5446800
         //g magnitude: 180.000000
         //Ideal cross-product: 3026.000000
         //Predicted function output: 3094
         //DTA 20091212:  Expected value adjusted to
         //3026.  Presumed cause of disagreement is g-vector
         //normalization due to sub-1024 values of components.
         //G-vector normalization seems to lead to closer
         //value to ideal.
      {  4096,   1451,   3934,   5929,    233}, 
         //[ 365]:  (0,-1,-1,1)
         //a_x:      0, a_y:  -2645, g_x:   -162, g_y:   1833
         //Top product * 10: 4284900
         //g magnitude: 1840.144831
         //Ideal cross-product: 232.856671
         //Predicted function output: 233
      {  4096,    671,   1557,   8160,   1815}, 
         //[ 366]:  (0,-1,-1,2)
         //a_x:      0, a_y:  -3425, g_x:  -2539, g_y:   4064
         //Top product * 10: 86960750
         //g magnitude: 4791.932491
         //Ideal cross-product: 1814.732369
         //Predicted function output: 1815
      {  4096,   1128,   4096,     32,      0}, 
         //[ 367]:  (0,-1,0,-2)
         //a_x:      0, a_y:  -2968, g_x:      0, g_y:  -4064
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   3899,   4096,    996,      0}, 
         //[ 368]:  (0,-1,0,-1)
         //a_x:      0, a_y:   -197, g_x:      0, g_y:  -3100
         //Top product * 10: 0
         //g magnitude: 3100.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   2802,   4096,   4096,      0}, 
         //[ 369]:  (0,-1,0,0)
         //a_x:      0, a_y:  -1294, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,    545,   4096,   6130,      0}, 
         //[ 370]:  (0,-1,0,1)
         //a_x:      0, a_y:  -3551, g_x:      0, g_y:   2034
         //Top product * 10: 0
         //g magnitude: 2034.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   3867,   4096,   8160,      0}, 
         //[ 371]:  (0,-1,0,2)
         //a_x:      0, a_y:   -229, g_x:      0, g_y:   4064
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   2652,   4269,     32,     61}, 
         //[ 372]:  (0,-1,1,-2)
         //a_x:      0, a_y:  -1444, g_x:    173, g_y:  -4064
         //Top product * 10: 2498120
         //g magnitude: 4067.680543
         //Ideal cross-product: 61.413869
         //Predicted function output: 61
      {  4096,   1913,   6550,    602,   1254}, 
         //[ 373]:  (0,-1,1,-1)
         //a_x:      0, a_y:  -2183, g_x:   2454, g_y:  -3494
         //Top product * 10: 53570820
         //g magnitude: 4269.678208
         //Ideal cross-product: 1254.680503
         //Predicted function output: 1254
      {  4096,   2506,   7291,   4096,   1590}, 
         //[ 374]:  (0,-1,1,0)
         //a_x:      0, a_y:  -1590, g_x:   3195, g_y:      0
         //Top product * 10: 50800500
         //g magnitude: 3195.000000
         //Ideal cross-product: 1590.000000
         //Predicted function output: 1590
      {  4096,   1657,   4829,   5496,   1133}, 
         //[ 375]:  (0,-1,1,1)
         //a_x:      0, a_y:  -2439, g_x:    733, g_y:   1400
         //Top product * 10: 17877870
         //g magnitude: 1580.281304
         //Ideal cross-product: 1131.309341
         //Predicted function output: 1133
      {  4096,   2989,   7846,   8160,    750}, 
         //[ 376]:  (0,-1,1,2)
         //a_x:      0, a_y:  -1107, g_x:   3750, g_y:   4064
         //Top product * 10: 41512500
         //g magnitude: 5529.791678
         //Ideal cross-product: 750.706399
         //Predicted function output: 750
      {  4096,   2488,   8160,     32,   1137}, 
         //[ 377]:  (0,-1,2,-2)
         //a_x:      0, a_y:  -1608, g_x:   4064, g_y:  -4064
         //Top product * 10: 65349120
         //g magnitude: 5747.363917
         //Ideal cross-product: 1137.027704
         //Predicted function output: 1137
      {  4096,   4046,   8160,    726,     38}, 
         //[ 378]:  (0,-1,2,-1)
         //a_x:      0, a_y:    -50, g_x:   4064, g_y:  -3370
         //Top product * 10: 2032000
         //g magnitude: 5279.488233
         //Ideal cross-product: 38.488579
         //Predicted function output: 38
      {  4096,   1050,   8160,   4096,   3046}, 
         //[ 379]:  (0,-1,2,0)
         //a_x:      0, a_y:  -3046, g_x:   4064, g_y:      0
         //Top product * 10: 123789440
         //g magnitude: 4064.000000
         //Ideal cross-product: 3046.000000
         //Predicted function output: 3046
      {  4096,   1891,   8160,   4669,   2184}, 
         //[ 380]:  (0,-1,2,1)
         //a_x:      0, a_y:  -2205, g_x:   4064, g_y:    573
         //Top product * 10: 89611200
         //g magnitude: 4104.196024
         //Ideal cross-product: 2183.404484
         //Predicted function output: 2184
      {  4096,    753,   8160,   8160,   2363}, 
         //[ 381]:  (0,-1,2,2)
         //a_x:      0, a_y:  -3343, g_x:   4064, g_y:   4064
         //Top product * 10: 135859520
         //g magnitude: 5747.363917
         //Ideal cross-product: 2363.857970
         //Predicted function output: 2363
      {  4096,   4096,     32,     32,      0}, 
         //[ 382]:  (0,0,-2,-2)
         //a_x:      0, a_y:      0, g_x:  -4064, g_y:  -4064
         //Top product * 10: 0
         //g magnitude: 5747.363917
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,     32,    348,      0}, 
         //[ 383]:  (0,0,-2,-1)
         //a_x:      0, a_y:      0, g_x:  -4064, g_y:  -3748
         //Top product * 10: 0
         //g magnitude: 5528.435583
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,     32,   4096,      0}, 
         //[ 384]:  (0,0,-2,0)
         //a_x:      0, a_y:      0, g_x:  -4064, g_y:      0
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,     32,   5959,      0}, 
         //[ 385]:  (0,0,-2,1)
         //a_x:      0, a_y:      0, g_x:  -4064, g_y:   1863
         //Top product * 10: 0
         //g magnitude: 4470.667176
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,     32,   8160,      0}, 
         //[ 386]:  (0,0,-2,2)
         //a_x:      0, a_y:      0, g_x:  -4064, g_y:   4064
         //Top product * 10: 0
         //g magnitude: 5747.363917
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,    959,     32,      0}, 
         //[ 387]:  (0,0,-1,-2)
         //a_x:      0, a_y:      0, g_x:  -3137, g_y:  -4064
         //Top product * 10: 0
         //g magnitude: 5133.893746
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   1527,   4070,      0}, 
         //[ 388]:  (0,0,-1,-1)
         //a_x:      0, a_y:      0, g_x:  -2569, g_y:    -26
         //Top product * 10: 0
         //g magnitude: 2569.131565
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   2703,   4096,      0}, 
         //[ 389]:  (0,0,-1,0)
         //a_x:      0, a_y:      0, g_x:  -1393, g_y:      0
         //Top product * 10: 0
         //g magnitude: 1393.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   3796,   6127,      0}, 
         //[ 390]:  (0,0,-1,1)
         //a_x:      0, a_y:      0, g_x:   -300, g_y:   2031
         //Top product * 10: 0
         //g magnitude: 2053.037019
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   1060,   8160,      0}, 
         //[ 391]:  (0,0,-1,2)
         //a_x:      0, a_y:      0, g_x:  -3036, g_y:   4064
         //Top product * 10: 0
         //g magnitude: 5072.809084
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   4096,     32,      0}, 
         //[ 392]:  (0,0,0,-2)
         //a_x:      0, a_y:      0, g_x:      0, g_y:  -4064
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   4096,    253,      0}, 
         //[ 393]:  (0,0,0,-1)
         //a_x:      0, a_y:      0, g_x:      0, g_y:  -3843
         //Top product * 10: 0
         //g magnitude: 3843.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   4096,   4096,      0}, 
         //[ 394]:  (0,0,0,0)
         //a_x:      0, a_y:      0, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   4096,   7244,      0}, 
         //[ 395]:  (0,0,0,1)
         //a_x:      0, a_y:      0, g_x:      0, g_y:   3148
         //Top product * 10: 0
         //g magnitude: 3148.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   4096,   8160,      0}, 
         //[ 396]:  (0,0,0,2)
         //a_x:      0, a_y:      0, g_x:      0, g_y:   4064
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   6119,     32,      0}, 
         //[ 397]:  (0,0,1,-2)
         //a_x:      0, a_y:      0, g_x:   2023, g_y:  -4064
         //Top product * 10: 0
         //g magnitude: 4539.672345
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   4983,    895,      0}, 
         //[ 398]:  (0,0,1,-1)
         //a_x:      0, a_y:      0, g_x:    887, g_y:  -3201
         //Top product * 10: 0
         //g magnitude: 3321.621592
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   5546,   4096,      0}, 
         //[ 399]:  (0,0,1,0)
         //a_x:      0, a_y:      0, g_x:   1450, g_y:      0
         //Top product * 10: 0
         //g magnitude: 1450.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   7820,   5159,      0}, 
         //[ 400]:  (0,0,1,1)
         //a_x:      0, a_y:      0, g_x:   3724, g_y:   1063
         //Top product * 10: 0
         //g magnitude: 3872.743859
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   7371,   8160,      0}, 
         //[ 401]:  (0,0,1,2)
         //a_x:      0, a_y:      0, g_x:   3275, g_y:   4064
         //Top product * 10: 0
         //g magnitude: 5219.360210
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   8160,     32,      0}, 
         //[ 402]:  (0,0,2,-2)
         //a_x:      0, a_y:      0, g_x:   4064, g_y:  -4064
         //Top product * 10: 0
         //g magnitude: 5747.363917
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   8160,   1289,      0}, 
         //[ 403]:  (0,0,2,-1)
         //a_x:      0, a_y:      0, g_x:   4064, g_y:  -2807
         //Top product * 10: 0
         //g magnitude: 4939.164403
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   8160,   4096,      0}, 
         //[ 404]:  (0,0,2,0)
         //a_x:      0, a_y:      0, g_x:   4064, g_y:      0
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   8160,   6090,      0}, 
         //[ 405]:  (0,0,2,1)
         //a_x:      0, a_y:      0, g_x:   4064, g_y:   1994
         //Top product * 10: 0
         //g magnitude: 4526.823610
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4096,   8160,   8160,      0}, 
         //[ 406]:  (0,0,2,2)
         //a_x:      0, a_y:      0, g_x:   4064, g_y:   4064
         //Top product * 10: 0
         //g magnitude: 5747.363917
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   5697,     32,     32,   1132}, 
         //[ 407]:  (0,1,-2,-2)
         //a_x:      0, a_y:   1601, g_x:  -4064, g_y:  -4064
         //Top product * 10: 65064640
         //g magnitude: 5747.363917
         //Ideal cross-product: 1132.077957
         //Predicted function output: 1132
      {  4096,   5949,     32,   2521,   1727}, 
         //[ 408]:  (0,1,-2,-1)
         //a_x:      0, a_y:   1853, g_x:  -4064, g_y:  -1575
         //Top product * 10: 75305920
         //g magnitude: 4358.522800
         //Ideal cross-product: 1727.785386
         //Predicted function output: 1727
      {  4096,   4920,     32,   4096,    824}, 
         //[ 409]:  (0,1,-2,0)
         //a_x:      0, a_y:    824, g_x:  -4064, g_y:      0
         //Top product * 10: 33487360
         //g magnitude: 4064.000000
         //Ideal cross-product: 824.000000
         //Predicted function output: 824
      {  4096,   5253,     32,   5603,   1085}, 
         //[ 410]:  (0,1,-2,1)
         //a_x:      0, a_y:   1157, g_x:  -4064, g_y:   1507
         //Top product * 10: 47020480
         //g magnitude: 4334.414032
         //Ideal cross-product: 1084.817455
         //Predicted function output: 1085
      {  4096,   6711,     32,   8160,   1849}, 
         //[ 411]:  (0,1,-2,2)
         //a_x:      0, a_y:   2615, g_x:  -4064, g_y:   4064
         //Top product * 10: 106273600
         //g magnitude: 5747.363917
         //Ideal cross-product: 1849.084233
         //Predicted function output: 1849
      {  4096,   7338,   3670,     32,    338}, 
         //[ 412]:  (0,1,-1,-2)
         //a_x:      0, a_y:   3242, g_x:   -426, g_y:  -4064
         //Top product * 10: 13810920
         //g magnitude: 4086.266266
         //Ideal cross-product: 337.983849
         //Predicted function output: 338
      {  4096,   5974,   1745,   3674,   1849}, 
         //[ 413]:  (0,1,-1,-1)
         //a_x:      0, a_y:   1878, g_x:  -2351, g_y:   -422
         //Top product * 10: 44151780
         //g magnitude: 2388.573842
         //Ideal cross-product: 1848.457821
         //Predicted function output: 1849
      {  4096,   4818,    917,   4096,    722}, 
         //[ 414]:  (0,1,-1,0)
         //a_x:      0, a_y:    722, g_x:  -3179, g_y:      0
         //Top product * 10: 22952380
         //g magnitude: 3179.000000
         //Ideal cross-product: 722.000000
         //Predicted function output: 722
      {  4096,   5009,   2223,   6231,    602}, 
         //[ 415]:  (0,1,-1,1)
         //a_x:      0, a_y:    913, g_x:  -1873, g_y:   2135
         //Top product * 10: 17100490
         //g magnitude: 2840.132743
         //Ideal cross-product: 602.101787
         //Predicted function output: 602
      {  4096,   6736,   1627,   8160,   1370}, 
         //[ 416]:  (0,1,-1,2)
         //a_x:      0, a_y:   2640, g_x:  -2469, g_y:   4064
         //Top product * 10: 65181600
         //g magnitude: 4755.213665
         //Ideal cross-product: 1370.739668
         //Predicted function output: 1370
      {  4096,   7545,   4096,     32,      0}, 
         //[ 417]:  (0,1,0,-2)
         //a_x:      0, a_y:   3449, g_x:      0, g_y:  -4064
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   5651,   4096,   1341,      0}, 
         //[ 418]:  (0,1,0,-1)
         //a_x:      0, a_y:   1555, g_x:      0, g_y:  -2755
         //Top product * 10: 0
         //g magnitude: 2755.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   6471,   4096,   4096,      0}, 
         //[ 419]:  (0,1,0,0)
         //a_x:      0, a_y:   2375, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   4134,   4096,   7628,      0}, 
         //[ 420]:  (0,1,0,1)
         //a_x:      0, a_y:     38, g_x:      0, g_y:   3532
         //Top product * 10: 0
         //g magnitude: 3532.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   5021,   4096,   8160,      0}, 
         //[ 421]:  (0,1,0,2)
         //a_x:      0, a_y:    925, g_x:      0, g_y:   4064
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   5573,   5838,     32,    582}, 
         //[ 422]:  (0,1,1,-2)
         //a_x:      0, a_y:   1477, g_x:   1742, g_y:  -4064
         //Top product * 10: 25729340
         //g magnitude: 4421.612828
         //Ideal cross-product: 581.899434
         //Predicted function output: 582
      {  4096,   6760,   5116,    948,    821}, 
         //[ 423]:  (0,1,1,-1)
         //a_x:      0, a_y:   2664, g_x:   1020, g_y:  -3148
         //Top product * 10: 27172800
         //g magnitude: 3309.124355
         //Ideal cross-product: 821.147744
         //Predicted function output: 821
      {  4096,   5696,   7456,   4096,   1600}, 
         //[ 424]:  (0,1,1,0)
         //a_x:      0, a_y:   1600, g_x:   3360, g_y:      0
         //Top product * 10: 53760000
         //g magnitude: 3360.000000
         //Ideal cross-product: 1600.000000
         //Predicted function output: 1600
      {  4096,   4539,   7375,   4490,    439}, 
         //[ 425]:  (0,1,1,1)
         //a_x:      0, a_y:    443, g_x:   3279, g_y:    394
         //Top product * 10: 14525970
         //g magnitude: 3302.586411
         //Ideal cross-product: 439.836183
         //Predicted function output: 439
      {  4096,   6480,   4992,   8160,    513}, 
         //[ 426]:  (0,1,1,2)
         //a_x:      0, a_y:   2384, g_x:    896, g_y:   4064
         //Top product * 10: 21360640
         //g magnitude: 4161.599692
         //Ideal cross-product: 513.279546
         //Predicted function output: 513
      {  4096,   6622,   8160,     32,   1786}, 
         //[ 427]:  (0,1,2,-2)
         //a_x:      0, a_y:   2526, g_x:   4064, g_y:  -4064
         //Top product * 10: 102656640
         //g magnitude: 5747.363917
         //Ideal cross-product: 1786.151729
         //Predicted function output: 1786
      {  4096,   6272,   8160,   1743,   1883}, 
         //[ 428]:  (0,1,2,-1)
         //a_x:      0, a_y:   2176, g_x:   4064, g_y:  -2353
         //Top product * 10: 88432640
         //g magnitude: 4696.030771
         //Ideal cross-product: 1883.135872
         //Predicted function output: 1883
      {  4096,   7916,   8160,   4096,   3820}, 
         //[ 429]:  (0,1,2,0)
         //a_x:      0, a_y:   3820, g_x:   4064, g_y:      0
         //Top product * 10: 155244800
         //g magnitude: 4064.000000
         //Ideal cross-product: 3820.000000
         //Predicted function output: 3820
      {  4096,   6163,   8160,   7964,   1497}, 
         //[ 430]:  (0,1,2,1)
         //a_x:      0, a_y:   2067, g_x:   4064, g_y:   3868
         //Top product * 10: 84002880
         //g magnitude: 5610.483045
         //Ideal cross-product: 1497.248621
         //Predicted function output: 1497
      {  4096,   6607,   8160,   8160,   1775}, 
         //[ 431]:  (0,1,2,2)
         //a_x:      0, a_y:   2511, g_x:   4064, g_y:   4064
         //Top product * 10: 102047040
         //g magnitude: 5747.363917
         //Ideal cross-product: 1775.545128
         //Predicted function output: 1775
      {  4096,   8160,     32,     32,   2873}, 
         //[ 432]:  (0,2,-2,-2)
         //a_x:      0, a_y:   4064, g_x:  -4064, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 5747.363917
         //Ideal cross-product: 2873.681959
         //Predicted function output: 2873
      {  4096,   8160,     32,    314,   2976}, 
         //[ 433]:  (0,2,-2,-1)
         //a_x:      0, a_y:   4064, g_x:  -4064, g_y:  -3782
         //Top product * 10: 165160960
         //g magnitude: 5551.542128
         //Ideal cross-product: 2975.046504
         //Predicted function output: 2976
      {  4096,   8160,     32,   4096,   4064}, 
         //[ 434]:  (0,2,-2,0)
         //a_x:      0, a_y:   4064, g_x:  -4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  4096,   8160,     32,   6319,   3566}, 
         //[ 435]:  (0,2,-2,1)
         //a_x:      0, a_y:   4064, g_x:  -4064, g_y:   2223
         //Top product * 10: 165160960
         //g magnitude: 4632.259168
         //Ideal cross-product: 3565.451630
         //Predicted function output: 3566
      {  4096,   8160,     32,   8160,   2873}, 
         //[ 436]:  (0,2,-2,2)
         //a_x:      0, a_y:   4064, g_x:  -4064, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 5747.363917
         //Ideal cross-product: 2873.681959
         //Predicted function output: 2873
      {  4096,   8160,   4019,     32,     77}, 
         //[ 437]:  (0,2,-1,-2)
         //a_x:      0, a_y:   4064, g_x:    -77, g_y:  -4064
         //Top product * 10: 3129280
         //g magnitude: 4064.729388
         //Ideal cross-product: 76.986183
         //Predicted function output: 77
      {  4096,   8160,    181,   3667,   4042}, 
         //[ 438]:  (0,2,-1,-1)
         //a_x:      0, a_y:   4064, g_x:  -3915, g_y:   -429
         //Top product * 10: 159105600
         //g magnitude: 3938.434461
         //Ideal cross-product: 4039.818400
         //Predicted function output: 4042
      {  4096,   8160,   2903,   4096,   4072}, 
         //[ 439]:  (0,2,-1,0)
         //a_x:      0, a_y:   4064, g_x:  -1193, g_y:      0
         //Top product * 10: 48483520
         //g magnitude: 1193.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4072
      {  4096,   8160,   2908,   6469,   1819}, 
         //[ 440]:  (0,2,-1,1)
         //a_x:      0, a_y:   4064, g_x:  -1188, g_y:   2373
         //Top product * 10: 48280320
         //g magnitude: 2653.765815
         //Ideal cross-product: 1819.313510
         //Predicted function output: 1819
      {  4096,   8160,   2644,   8160,   1367}, 
         //[ 441]:  (0,2,-1,2)
         //a_x:      0, a_y:   4064, g_x:  -1452, g_y:   4064
         //Top product * 10: 59009280
         //g magnitude: 4315.599611
         //Ideal cross-product: 1367.348348
         //Predicted function output: 1367
      {  4096,   8160,   4096,     32,      0}, 
         //[ 442]:  (0,2,0,-2)
         //a_x:      0, a_y:   4064, g_x:      0, g_y:  -4064
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   8160,   4096,   1872,      0}, 
         //[ 443]:  (0,2,0,-1)
         //a_x:      0, a_y:   4064, g_x:      0, g_y:  -2224
         //Top product * 10: 0
         //g magnitude: 2224.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   8160,   4096,   4096,      0}, 
         //[ 444]:  (0,2,0,0)
         //a_x:      0, a_y:   4064, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   8160,   4096,   6968,      0}, 
         //[ 445]:  (0,2,0,1)
         //a_x:      0, a_y:   4064, g_x:      0, g_y:   2872
         //Top product * 10: 0
         //g magnitude: 2872.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   8160,   4096,   8160,      0}, 
         //[ 446]:  (0,2,0,2)
         //a_x:      0, a_y:   4064, g_x:      0, g_y:   4064
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4096,   8160,   6394,     32,   2001}, 
         //[ 447]:  (0,2,1,-2)
         //a_x:      0, a_y:   4064, g_x:   2298, g_y:  -4064
         //Top product * 10: 93390720
         //g magnitude: 4668.715027
         //Ideal cross-product: 2000.351691
         //Predicted function output: 2001
      {  4096,   8160,   7244,   3208,   3911}, 
         //[ 448]:  (0,2,1,-1)
         //a_x:      0, a_y:   4064, g_x:   3148, g_y:   -888
         //Top product * 10: 127934720
         //g magnitude: 3270.848208
         //Ideal cross-product: 3911.362187
         //Predicted function output: 3911
      {  4096,   8160,   7497,   4096,   4067}, 
         //[ 449]:  (0,2,1,0)
         //a_x:      0, a_y:   4064, g_x:   3401, g_y:      0
         //Top product * 10: 138216640
         //g magnitude: 3401.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4067
      {  4096,   8160,   5914,   4742,   3835}, 
         //[ 450]:  (0,2,1,1)
         //a_x:      0, a_y:   4064, g_x:   1818, g_y:    646
         //Top product * 10: 73883520
         //g magnitude: 1929.362589
         //Ideal cross-product: 3829.426383
         //Predicted function output: 3835
      {  4096,   8160,   5645,   8160,   1447}, 
         //[ 451]:  (0,2,1,2)
         //a_x:      0, a_y:   4064, g_x:   1549, g_y:   4064
         //Top product * 10: 62951360
         //g magnitude: 4349.194983
         //Ideal cross-product: 1447.425564
         //Predicted function output: 1447
      {  4096,   8160,   8160,     32,   2873}, 
         //[ 452]:  (0,2,2,-2)
         //a_x:      0, a_y:   4064, g_x:   4064, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 5747.363917
         //Ideal cross-product: 2873.681959
         //Predicted function output: 2873
      {  4096,   8160,   8160,   3156,   3961}, 
         //[ 453]:  (0,2,2,-1)
         //a_x:      0, a_y:   4064, g_x:   4064, g_y:   -940
         //Top product * 10: 165160960
         //g magnitude: 4171.294284
         //Ideal cross-product: 3959.465546
         //Predicted function output: 3961
      {  4096,   8160,   8160,   4096,   4064}, 
         //[ 454]:  (0,2,2,0)
         //a_x:      0, a_y:   4064, g_x:   4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  4096,   8160,   8160,   6653,   3440}, 
         //[ 455]:  (0,2,2,1)
         //a_x:      0, a_y:   4064, g_x:   4064, g_y:   2557
         //Top product * 10: 165160960
         //g magnitude: 4801.494038
         //Ideal cross-product: 3439.782674
         //Predicted function output: 3440
      {  4096,   8160,   8160,   8160,   2873}, 
         //[ 456]:  (0,2,2,2)
         //a_x:      0, a_y:   4064, g_x:   4064, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 5747.363917
         //Ideal cross-product: 2873.681959
         //Predicted function output: 2873
      {  7746,     32,     32,     32,   5454}, 
         //[ 457]:  (1,-2,-2,-2)
         //a_x:   3650, a_y:  -4064, g_x:  -4064, g_y:  -4064
         //Top product * 10: 313496960
         //g magnitude: 5747.363917
         //Ideal cross-product: 5454.621710
         //Predicted function output: 5454
      {  5126,     32,     32,   1052,   3872}, 
         //[ 458]:  (1,-2,-2,-1)
         //a_x:   1030, a_y:  -4064, g_x:  -4064, g_y:  -3044
         //Top product * 10: 196514160
         //g magnitude: 5077.601008
         //Ideal cross-product: 3870.216657
         //Predicted function output: 3872
      {  4370,     32,     32,   4096,   4064}, 
         //[ 459]:  (1,-2,-2,0)
         //a_x:    274, a_y:  -4064, g_x:  -4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  4362,     32,     32,   7365,   3001}, 
         //[ 460]:  (1,-2,-2,1)
         //a_x:    266, a_y:  -4064, g_x:  -4064, g_y:   3269
         //Top product * 10: 156465420
         //g magnitude: 5215.597473
         //Ideal cross-product: 2999.951987
         //Predicted function output: 3001
      {  4582,     32,     32,   8160,   2530}, 
         //[ 461]:  (1,-2,-2,2)
         //a_x:    486, a_y:  -4064, g_x:  -4064, g_y:   4064
         //Top product * 10: 145409920
         //g magnitude: 5747.363917
         //Ideal cross-product: 2530.028063
         //Predicted function output: 2530
      {  6603,     32,   3767,     32,   2827}, 
         //[ 462]:  (1,-2,-1,-2)
         //a_x:   2507, a_y:  -4064, g_x:   -329, g_y:  -4064
         //Top product * 10: 115255040
         //g magnitude: 4077.295304
         //Ideal cross-product: 2826.752329
         //Predicted function output: 2827
      {  6813,     32,   3451,   3515,   4843}, 
         //[ 463]:  (1,-2,-1,-1)
         //a_x:   2717, a_y:  -4064, g_x:   -645, g_y:   -581
         //Top product * 10: 41998570
         //g magnitude: 868.093313
         //Ideal cross-product: 4838.024827
         //Predicted function output: 4843
      {  4722,     32,    678,   4096,   4064}, 
         //[ 464]:  (1,-2,-1,0)
         //a_x:    626, a_y:  -4064, g_x:  -3418, g_y:      0
         //Top product * 10: 138907520
         //g magnitude: 3418.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  7831,     32,   1192,   4984,   2797}, 
         //[ 465]:  (1,-2,-1,1)
         //a_x:   3735, a_y:  -4064, g_x:  -2904, g_y:    888
         //Top product * 10: 84851760
         //g magnitude: 3036.735089
         //Ideal cross-product: 2794.177217
         //Predicted function output: 2797
      {  6516,     32,   1979,   8160,    268}, 
         //[ 466]:  (1,-2,-1,2)
         //a_x:   2420, a_y:  -4064, g_x:  -2117, g_y:   4064
         //Top product * 10: 12313920
         //g magnitude: 4582.334012
         //Ideal cross-product: 268.725937
         //Predicted function output: 268
      {  6423,     32,   4096,     32,   2327}, 
         //[ 467]:  (1,-2,0,-2)
         //a_x:   2327, a_y:  -4064, g_x:      0, g_y:  -4064
         //Top product * 10: 94569280
         //g magnitude: 4064.000000
         //Ideal cross-product: 2327.000000
         //Predicted function output: 2327
      {  7357,     32,   4096,   3042,   3264}, 
         //[ 468]:  (1,-2,0,-1)
         //a_x:   3261, a_y:  -4064, g_x:      0, g_y:  -1054
         //Top product * 10: 34370940
         //g magnitude: 1054.000000
         //Ideal cross-product: 3261.000000
         //Predicted function output: 3264
      {  7698,     32,   4096,   4096,      0}, 
         //[ 469]:  (1,-2,0,0)
         //a_x:   3602, a_y:  -4064, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  7798,     32,   4096,   6116,   3703}, 
         //[ 470]:  (1,-2,0,1)
         //a_x:   3702, a_y:  -4064, g_x:      0, g_y:   2020
         //Top product * 10: 74780400
         //g magnitude: 2020.000000
         //Ideal cross-product: 3702.000000
         //Predicted function output: 3703
      {  4100,     32,   4096,   8160,      4}, 
         //[ 471]:  (1,-2,0,2)
         //a_x:      4, a_y:  -4064, g_x:      0, g_y:   4064
         //Top product * 10: 162560
         //g magnitude: 4064.000000
         //Ideal cross-product: 4.000000
         //Predicted function output: 4
      {  5471,     32,   7466,     32,   1536}, 
         //[ 472]:  (1,-2,1,-2)
         //a_x:   1375, a_y:  -4064, g_x:   3370, g_y:  -4064
         //Top product * 10: 81076800
         //g magnitude: 5279.488233
         //Ideal cross-product: 1535.694303
         //Predicted function output: 1536
      {  7806,     32,   7879,   2495,   2297}, 
         //[ 473]:  (1,-2,1,-1)
         //a_x:   3710, a_y:  -4064, g_x:   3783, g_y:  -1601
         //Top product * 10: 94344020
         //g magnitude: 4107.832762
         //Ideal cross-product: 2296.686001
         //Predicted function output: 2297
      {  7448,     32,   7411,   4096,   4067}, 
         //[ 474]:  (1,-2,1,0)
         //a_x:   3352, a_y:  -4064, g_x:   3315, g_y:      0
         //Top product * 10: 134721600
         //g magnitude: 3315.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4067
      {  7782,     32,   4303,   7039,   3966}, 
         //[ 475]:  (1,-2,1,1)
         //a_x:   3686, a_y:  -4064, g_x:    207, g_y:   2943
         //Top product * 10: 116891460
         //g magnitude: 2950.270835
         //Ideal cross-product: 3962.058622
         //Predicted function output: 3966
      {  7619,     32,   4691,   8160,   4076}, 
         //[ 476]:  (1,-2,1,2)
         //a_x:   3523, a_y:  -4064, g_x:    595, g_y:   4064
         //Top product * 10: 167355520
         //g magnitude: 4107.325285
         //Ideal cross-product: 4074.562115
         //Predicted function output: 4076
      {  4163,     32,   8160,     32,   2826}, 
         //[ 477]:  (1,-2,2,-2)
         //a_x:     67, a_y:  -4064, g_x:   4064, g_y:  -4064
         //Top product * 10: 162438080
         //g magnitude: 5747.363917
         //Ideal cross-product: 2826.305804
         //Predicted function output: 2826
      {  6736,     32,   8160,    570,   1339}, 
         //[ 478]:  (1,-2,2,-1)
         //a_x:   2640, a_y:  -4064, g_x:   4064, g_y:  -3526
         //Top product * 10: 72074560
         //g magnitude: 5380.406304
         //Ideal cross-product: 1339.574670
         //Predicted function output: 1339
      {  4874,     32,   8160,   4096,   4064}, 
         //[ 479]:  (1,-2,2,0)
         //a_x:    778, a_y:  -4064, g_x:   4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  5396,     32,   8160,   4598,   4194}, 
         //[ 480]:  (1,-2,2,1)
         //a_x:   1300, a_y:  -4064, g_x:   4064, g_y:    502
         //Top product * 10: 171686960
         //g magnitude: 4094.887056
         //Ideal cross-product: 4192.715395
         //Predicted function output: 4194
      {  7970,     32,   8160,   8160,   5613}, 
         //[ 481]:  (1,-2,2,2)
         //a_x:   3874, a_y:  -4064, g_x:   4064, g_y:   4064
         //Top product * 10: 322600320
         //g magnitude: 5747.363917
         //Ideal cross-product: 5613.013629
         //Predicted function output: 5613
      {  4979,    577,     32,     32,   3112}, 
         //[ 482]:  (1,-1,-2,-2)
         //a_x:    883, a_y:  -3519, g_x:  -4064, g_y:  -4064
         //Top product * 10: 178897280
         //g magnitude: 5747.363917
         //Ideal cross-product: 3112.684051
         //Predicted function output: 3112
      {  7868,    570,     32,   1929,   4886}, 
         //[ 483]:  (1,-1,-2,-1)
         //a_x:   3772, a_y:  -3526, g_x:  -4064, g_y:  -2167
         //Top product * 10: 225035880
         //g magnitude: 4605.647077
         //Ideal cross-product: 4886.086064
         //Predicted function output: 4886
      {  7282,   1824,     32,   4096,   2272}, 
         //[ 484]:  (1,-1,-2,0)
         //a_x:   3186, a_y:  -2272, g_x:  -4064, g_y:      0
         //Top product * 10: 92334080
         //g magnitude: 4064.000000
         //Ideal cross-product: 2272.000000
         //Predicted function output: 2272
      {  4965,   1020,     32,   5089,   2782}, 
         //[ 485]:  (1,-1,-2,1)
         //a_x:    869, a_y:  -3076, g_x:  -4064, g_y:    993
         //Top product * 10: 116379470
         //g magnitude: 4183.556501
         //Ideal cross-product: 2781.830960
         //Predicted function output: 2782
      {  7648,   3924,     32,   8160,   2390}, 
         //[ 486]:  (1,-1,-2,2)
         //a_x:   3552, a_y:   -172, g_x:  -4064, g_y:   4064
         //Top product * 10: 137363200
         //g magnitude: 5747.363917
         //Ideal cross-product: 2390.020920
         //Predicted function output: 2390
      {  6816,   2785,   1687,     32,   3009}, 
         //[ 487]:  (1,-1,-1,-2)
         //a_x:   2720, a_y:  -1311, g_x:  -2409, g_y:  -4064
         //Top product * 10: 142122790
         //g magnitude: 4724.338790
         //Ideal cross-product: 3008.310714
         //Predicted function output: 3009
      {  4669,   3956,   3188,    553,    590}, 
         //[ 488]:  (1,-1,-1,-1)
         //a_x:    573, a_y:   -140, g_x:   -908, g_y:  -3543
         //Top product * 10: 21572590
         //g magnitude: 3657.500923
         //Ideal cross-product: 589.817760
         //Predicted function output: 590
      {  4728,   4087,   1871,   4096,      9}, 
         //[ 489]:  (1,-1,-1,0)
         //a_x:    632, a_y:     -9, g_x:  -2225, g_y:      0
         //Top product * 10: 200250
         //g magnitude: 2225.000000
         //Ideal cross-product: 9.000000
         //Predicted function output: 9
      {  6495,    214,   1542,   7847,    201}, 
         //[ 490]:  (1,-1,-1,1)
         //a_x:   2399, a_y:  -3882, g_x:  -2554, g_y:   3751
         //Top product * 10: 9159790
         //g magnitude: 4537.941934
         //Ideal cross-product: 201.848991
         //Predicted function output: 201
      {  8011,   3391,   2797,   8160,   3515}, 
         //[ 491]:  (1,-1,-1,2)
         //a_x:   3915, a_y:   -705, g_x:  -1299, g_y:   4064
         //Top product * 10: 149947650
         //g magnitude: 4266.555637
         //Ideal cross-product: 3514.489503
         //Predicted function output: 3515
      {  6624,   1896,   4096,     32,   2528}, 
         //[ 492]:  (1,-1,0,-2)
         //a_x:   2528, a_y:  -2200, g_x:      0, g_y:  -4064
         //Top product * 10: 102737920
         //g magnitude: 4064.000000
         //Ideal cross-product: 2528.000000
         //Predicted function output: 2528
      {  7228,   2542,   4096,   3459,   3132}, 
         //[ 493]:  (1,-1,0,-1)
         //a_x:   3132, a_y:  -1554, g_x:      0, g_y:   -637
         //Top product * 10: 19950840
         //g magnitude: 637.000000
         //Ideal cross-product: 3132.000000
         //Predicted function output: 3148
         //DTA 20091212:  Expected value adjusted to
         //3132.  Presumed cause of disagreement is g-vector
         //normalization due to sub-1024 values of components.
         //G-vector normalization seems to lead to closer
         //value to ideal.
      {  7876,    599,   4096,   4096,      0}, 
         //[ 494]:  (1,-1,0,0)
         //a_x:   3780, a_y:  -3497, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  7784,    961,   4096,   7771,   3689}, 
         //[ 495]:  (1,-1,0,1)
         //a_x:   3688, a_y:  -3135, g_x:      0, g_y:   3675
         //Top product * 10: 135534000
         //g magnitude: 3675.000000
         //Ideal cross-product: 3688.000000
         //Predicted function output: 3689
      {  7930,   2436,   4096,   8160,   3834}, 
         //[ 496]:  (1,-1,0,2)
         //a_x:   3834, a_y:  -1660, g_x:      0, g_y:   4064
         //Top product * 10: 155813760
         //g magnitude: 4064.000000
         //Ideal cross-product: 3834.000000
         //Predicted function output: 3834
      {  5085,   3128,   4926,     32,    775}, 
         //[ 497]:  (1,-1,1,-2)
         //a_x:    989, a_y:   -968, g_x:    830, g_y:  -4064
         //Top product * 10: 32158560
         //g magnitude: 4147.890548
         //Ideal cross-product: 775.299146
         //Predicted function output: 775
      {  6623,   2582,   7863,   2251,    248}, 
         //[ 498]:  (1,-1,1,-1)
         //a_x:   2527, a_y:  -1514, g_x:   3767, g_y:  -1845
         //Top product * 10: 10409230
         //g magnitude: 4194.557664
         //Ideal cross-product: 248.160374
         //Predicted function output: 248
      {  4884,   1652,   5656,   4096,   2446}, 
         //[ 499]:  (1,-1,1,0)
         //a_x:    788, a_y:  -2444, g_x:   1560, g_y:      0
         //Top product * 10: 38126400
         //g magnitude: 1560.000000
         //Ideal cross-product: 2444.000000
         //Predicted function output: 2446
      {  7653,   3666,   5237,   8004,   3535}, 
         //[ 500]:  (1,-1,1,1)
         //a_x:   3557, a_y:   -430, g_x:   1141, g_y:   3908
         //Top product * 10: 143913860
         //g magnitude: 4071.160154
         //Ideal cross-product: 3534.959435
         //Predicted function output: 3535
      {  4160,   1282,   5521,   8160,    992}, 
         //[ 501]:  (1,-1,1,2)
         //a_x:     64, a_y:  -2814, g_x:   1425, g_y:   4064
         //Top product * 10: 42700460
         //g magnitude: 4306.590415
         //Ideal cross-product: 991.514305
         //Predicted function output: 992
      {  5428,   3480,   8160,     32,    506}, 
         //[ 502]:  (1,-1,2,-2)
         //a_x:   1332, a_y:   -616, g_x:   4064, g_y:  -4064
         //Top product * 10: 29098240
         //g magnitude: 5747.363917
         //Ideal cross-product: 506.288455
         //Predicted function output: 506
      {  4268,   2322,   8160,    185,   1159}, 
         //[ 503]:  (1,-1,2,-1)
         //a_x:    172, a_y:  -1774, g_x:   4064, g_y:  -3911
         //Top product * 10: 65368440
         //g magnitude: 5640.214269
         //Ideal cross-product: 1158.970863
         //Predicted function output: 1159
      {  6870,   1319,   8160,   4096,   2777}, 
         //[ 504]:  (1,-1,2,0)
         //a_x:   2774, a_y:  -2777, g_x:   4064, g_y:      0
         //Top product * 10: 112857280
         //g magnitude: 4064.000000
         //Ideal cross-product: 2777.000000
         //Predicted function output: 2777
      {  4233,   1910,   8160,   7774,   1713}, 
         //[ 505]:  (1,-1,2,1)
         //a_x:    137, a_y:  -2186, g_x:   4064, g_y:   3678
         //Top product * 10: 93877900
         //g magnitude: 5481.220667
         //Ideal cross-product: 1712.718858
         //Predicted function output: 1713
      {  6006,   1375,   8160,   8160,   3274}, 
         //[ 506]:  (1,-1,2,2)
         //a_x:   1910, a_y:  -2721, g_x:   4064, g_y:   4064
         //Top product * 10: 188203840
         //g magnitude: 5747.363917
         //Ideal cross-product: 3274.611504
         //Predicted function output: 3274
      {  7780,   4096,     32,     32,   2605}, 
         //[ 507]:  (1,0,-2,-2)
         //a_x:   3684, a_y:      0, g_x:  -4064, g_y:  -4064
         //Top product * 10: 149717760
         //g magnitude: 5747.363917
         //Ideal cross-product: 2604.981382
         //Predicted function output: 2605
      {  7242,   4096,     32,    816,   1975}, 
         //[ 508]:  (1,0,-2,-1)
         //a_x:   3146, a_y:      0, g_x:  -4064, g_y:  -3280
         //Top product * 10: 103188800
         //g magnitude: 5222.499019
         //Ideal cross-product: 1975.851018
         //Predicted function output: 1975
      {  5383,   4096,     32,   4096,      0}, 
         //[ 509]:  (1,0,-2,0)
         //a_x:   1287, a_y:      0, g_x:  -4064, g_y:      0
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  6460,   4096,     32,   4982,    503}, 
         //[ 510]:  (1,0,-2,1)
         //a_x:   2364, a_y:      0, g_x:  -4064, g_y:    886
         //Top product * 10: 20945040
         //g magnitude: 4159.458138
         //Ideal cross-product: 503.552129
         //Predicted function output: 503
      {  4394,   4096,     32,   8160,    210}, 
         //[ 511]:  (1,0,-2,2)
         //a_x:    298, a_y:      0, g_x:  -4064, g_y:   4064
         //Top product * 10: 12110720
         //g magnitude: 5747.363917
         //Ideal cross-product: 210.717821
         //Predicted function output: 210
      {  7123,   4096,   1422,     32,   2529}, 
         //[ 512]:  (1,0,-1,-2)
         //a_x:   3027, a_y:      0, g_x:  -2674, g_y:  -4064
         //Top product * 10: 123017280
         //g magnitude: 4864.809554
         //Ideal cross-product: 2528.717283
         //Predicted function output: 2529
      {  5181,   4096,   1535,    327,    898}, 
         //[ 513]:  (1,0,-1,-1)
         //a_x:   1085, a_y:      0, g_x:  -2561, g_y:  -3769
         //Top product * 10: 40893650
         //g magnitude: 4556.762228
         //Ideal cross-product: 897.427778
         //Predicted function output: 898
      {  5703,   4096,   3169,   4096,      0}, 
         //[ 514]:  (1,0,-1,0)
         //a_x:   1607, a_y:      0, g_x:   -927, g_y:      0
         //Top product * 10: 0
         //g magnitude: 927.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  7910,   4096,   1579,   4811,   1043}, 
         //[ 515]:  (1,0,-1,1)
         //a_x:   3814, a_y:      0, g_x:  -2517, g_y:    715
         //Top product * 10: 27270100
         //g magnitude: 2616.584415
         //Ideal cross-product: 1042.202187
         //Predicted function output: 1043
      {  5774,   4096,   1570,   8160,   1425}, 
         //[ 516]:  (1,0,-1,2)
         //a_x:   1678, a_y:      0, g_x:  -2526, g_y:   4064
         //Top product * 10: 68193920
         //g magnitude: 4785.057157
         //Ideal cross-product: 1425.143269
         //Predicted function output: 1425
      {  4898,   4096,   4096,     32,    802}, 
         //[ 517]:  (1,0,0,-2)
         //a_x:    802, a_y:      0, g_x:      0, g_y:  -4064
         //Top product * 10: 32593280
         //g magnitude: 4064.000000
         //Ideal cross-product: 802.000000
         //Predicted function output: 802
      {  6137,   4096,   4096,   1934,   2042}, 
         //[ 518]:  (1,0,0,-1)
         //a_x:   2041, a_y:      0, g_x:      0, g_y:  -2162
         //Top product * 10: 44126420
         //g magnitude: 2162.000000
         //Ideal cross-product: 2041.000000
         //Predicted function output: 2042
      {  7043,   4096,   4096,   4096,      0}, 
         //[ 519]:  (1,0,0,0)
         //a_x:   2947, a_y:      0, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  7312,   4096,   4096,   7370,   3216}, 
         //[ 520]:  (1,0,0,1)
         //a_x:   3216, a_y:      0, g_x:      0, g_y:   3274
         //Top product * 10: 105291840
         //g magnitude: 3274.000000
         //Ideal cross-product: 3216.000000
         //Predicted function output: 3216
      {  7637,   4096,   4096,   8160,   3541}, 
         //[ 521]:  (1,0,0,2)
         //a_x:   3541, a_y:      0, g_x:      0, g_y:   4064
         //Top product * 10: 143906240
         //g magnitude: 4064.000000
         //Ideal cross-product: 3541.000000
         //Predicted function output: 3541
      {  4830,   4096,   7137,     32,    587}, 
         //[ 522]:  (1,0,1,-2)
         //a_x:    734, a_y:      0, g_x:   3041, g_y:  -4064
         //Top product * 10: 29829760
         //g magnitude: 5075.803089
         //Ideal cross-product: 587.685524
         //Predicted function output: 587
      {  7522,   4096,   5052,   2222,   3053}, 
         //[ 523]:  (1,0,1,-1)
         //a_x:   3426, a_y:      0, g_x:    956, g_y:  -1874
         //Top product * 10: 64203240
         //g magnitude: 2103.761393
         //Ideal cross-product: 3051.830887
         //Predicted function output: 3053
      {  5157,   4096,   7659,   4096,      0}, 
         //[ 524]:  (1,0,1,0)
         //a_x:   1061, a_y:      0, g_x:   3563, g_y:      0
         //Top product * 10: 0
         //g magnitude: 3563.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4966,   4096,   5699,   4770,    337}, 
         //[ 525]:  (1,0,1,1)
         //a_x:    870, a_y:      0, g_x:   1603, g_y:    674
         //Top product * 10: 5863800
         //g magnitude: 1738.932144
         //Ideal cross-product: 337.206947
         //Predicted function output: 337
      {  4761,   4096,   7975,   8160,    481}, 
         //[ 526]:  (1,0,1,2)
         //a_x:    665, a_y:      0, g_x:   3879, g_y:   4064
         //Top product * 10: 27025600
         //g magnitude: 5618.072356
         //Ideal cross-product: 481.047560
         //Predicted function output: 481
      {  5876,   4096,   8160,     32,   1258}, 
         //[ 527]:  (1,0,2,-2)
         //a_x:   1780, a_y:      0, g_x:   4064, g_y:  -4064
         //Top product * 10: 72339200
         //g magnitude: 5747.363917
         //Ideal cross-product: 1258.650071
         //Predicted function output: 1258
      {  4778,   4096,   8160,   3699,     66}, 
         //[ 528]:  (1,0,2,-1)
         //a_x:    682, a_y:      0, g_x:   4064, g_y:   -397
         //Top product * 10: 2707540
         //g magnitude: 4083.344830
         //Ideal cross-product: 66.306915
         //Predicted function output: 66
      {  7187,   4096,   8160,   4096,      0}, 
         //[ 529]:  (1,0,2,0)
         //a_x:   3091, a_y:      0, g_x:   4064, g_y:      0
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  6750,   4096,   8160,   6541,   1368}, 
         //[ 530]:  (1,0,2,1)
         //a_x:   2654, a_y:      0, g_x:   4064, g_y:   2445
         //Top product * 10: 64890300
         //g magnitude: 4742.796749
         //Ideal cross-product: 1368.186398
         //Predicted function output: 1368
      {  4487,   4096,   8160,   8160,    276}, 
         //[ 531]:  (1,0,2,2)
         //a_x:    391, a_y:      0, g_x:   4064, g_y:   4064
         //Top product * 10: 15890240
         //g magnitude: 5747.363917
         //Ideal cross-product: 276.478751
         //Predicted function output: 276
      {  5143,   5985,     32,     32,    595}, 
         //[ 532]:  (1,1,-2,-2)
         //a_x:   1047, a_y:   1889, g_x:  -4064, g_y:  -4064
         //Top product * 10: 34218880
         //g magnitude: 5747.363917
         //Ideal cross-product: 595.383910
         //Predicted function output: 595
      {  4311,   6907,     32,   1848,   2356}, 
         //[ 533]:  (1,1,-2,-1)
         //a_x:    215, a_y:   2811, g_x:  -4064, g_y:  -2248
         //Top product * 10: 109405840
         //g magnitude: 4644.308345
         //Ideal cross-product: 2355.697165
         //Predicted function output: 2356
      {  7098,   6587,     32,   4096,   2491}, 
         //[ 534]:  (1,1,-2,0)
         //a_x:   3002, a_y:   2491, g_x:  -4064, g_y:      0
         //Top product * 10: 101234240
         //g magnitude: 4064.000000
         //Ideal cross-product: 2491.000000
         //Predicted function output: 2491
      {  5839,   5438,     32,   5899,   1934}, 
         //[ 535]:  (1,1,-2,1)
         //a_x:   1743, a_y:   1342, g_x:  -4064, g_y:   1803
         //Top product * 10: 85965170
         //g magnitude: 4445.998763
         //Ideal cross-product: 1933.540124
         //Predicted function output: 1934
      {  6406,   4610,     32,   8160,   1996}, 
         //[ 536]:  (1,1,-2,2)
         //a_x:   2310, a_y:    514, g_x:  -4064, g_y:   4064
         //Top product * 10: 114767360
         //g magnitude: 5747.363917
         //Ideal cross-product: 1996.869550
         //Predicted function output: 1996
      {  4436,   5747,    637,     32,    811}, 
         //[ 537]:  (1,1,-1,-2)
         //a_x:    340, a_y:   1651, g_x:  -3459, g_y:  -4064
         //Top product * 10: 43290490
         //g magnitude: 5336.738423
         //Ideal cross-product: 811.178787
         //Predicted function output: 811
      {  6417,   7050,   2378,   1187,    496}, 
         //[ 538]:  (1,1,-1,-1)
         //a_x:   2321, a_y:   2954, g_x:  -1718, g_y:  -2909
         //Top product * 10: 16768170
         //g magnitude: 3378.432329
         //Ideal cross-product: 496.329906
         //Predicted function output: 496
      {  7503,   5501,   1697,   4096,   1406}, 
         //[ 539]:  (1,1,-1,0)
         //a_x:   3407, a_y:   1405, g_x:  -2399, g_y:      0
         //Top product * 10: 33705950
         //g magnitude: 2399.000000
         //Ideal cross-product: 1405.000000
         //Predicted function output: 1406
      {  6809,   6969,   2585,   4605,   3590}, 
         //[ 540]:  (1,1,-1,1)
         //a_x:   2713, a_y:   2873, g_x:  -1511, g_y:    509
         //Top product * 10: 57220200
         //g magnitude: 1594.428424
         //Ideal cross-product: 3588.759403
         //Predicted function output: 3590
      {  6984,   5813,   2459,   8160,   3320}, 
         //[ 541]:  (1,1,-1,2)
         //a_x:   2888, a_y:   1717, g_x:  -1637, g_y:   4064
         //Top product * 10: 145475610
         //g magnitude: 4381.308594
         //Ideal cross-product: 3320.368946
         //Predicted function output: 3320
      {  7808,   7155,   4096,     32,   3712}, 
         //[ 542]:  (1,1,0,-2)
         //a_x:   3712, a_y:   3059, g_x:      0, g_y:  -4064
         //Top product * 10: 150855680
         //g magnitude: 4064.000000
         //Ideal cross-product: 3712.000000
         //Predicted function output: 3712
      {  5411,   5243,   4096,   2889,   1315}, 
         //[ 543]:  (1,1,0,-1)
         //a_x:   1315, a_y:   1147, g_x:      0, g_y:  -1207
         //Top product * 10: 15872050
         //g magnitude: 1207.000000
         //Ideal cross-product: 1315.000000
         //Predicted function output: 1315
      {  7824,   4163,   4096,   4096,      0}, 
         //[ 544]:  (1,1,0,0)
         //a_x:   3728, a_y:     67, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  4335,   6391,   4096,   5947,    239}, 
         //[ 545]:  (1,1,0,1)
         //a_x:    239, a_y:   2295, g_x:      0, g_y:   1851
         //Top product * 10: 4423890
         //g magnitude: 1851.000000
         //Ideal cross-product: 239.000000
         //Predicted function output: 239
      {  4373,   5398,   4096,   8160,    277}, 
         //[ 546]:  (1,1,0,2)
         //a_x:    277, a_y:   1302, g_x:      0, g_y:   4064
         //Top product * 10: 11257280
         //g magnitude: 4064.000000
         //Ideal cross-product: 277.000000
         //Predicted function output: 277
      {  7002,   6703,   6197,     32,   3780}, 
         //[ 547]:  (1,1,1,-2)
         //a_x:   2906, a_y:   2607, g_x:   2101, g_y:  -4064
         //Top product * 10: 172872910
         //g magnitude: 4574.964153
         //Ideal cross-product: 3778.672449
         //Predicted function output: 3780
      {  6150,   6284,   7664,   1955,   2933}, 
         //[ 548]:  (1,1,1,-1)
         //a_x:   2054, a_y:   2188, g_x:   3568, g_y:  -2141
         //Top product * 10: 122043980
         //g magnitude: 4161.070175
         //Ideal cross-product: 2932.994996
         //Predicted function output: 2933
      {  6784,   4651,   7196,   4096,    555}, 
         //[ 549]:  (1,1,1,0)
         //a_x:   2688, a_y:    555, g_x:   3100, g_y:      0
         //Top product * 10: 17205000
         //g magnitude: 3100.000000
         //Ideal cross-product: 555.000000
         //Predicted function output: 555
      {  7728,   7848,   5958,   6848,    905}, 
         //[ 550]:  (1,1,1,1)
         //a_x:   3632, a_y:   3752, g_x:   1862, g_y:   2752
         //Top product * 10: 30090400
         //g magnitude: 3322.732008
         //Ideal cross-product: 905.592143
         //Predicted function output: 905
      {  4889,   5459,   6928,   8160,    128}, 
         //[ 551]:  (1,1,1,2)
         //a_x:    793, a_y:   1363, g_x:   2832, g_y:   4064
         //Top product * 10: 6372640
         //g magnitude: 4953.414984
         //Ideal cross-product: 128.651446
         //Predicted function output: 128
      {  4278,   6110,   8160,     32,   1552}, 
         //[ 552]:  (1,1,2,-2)
         //a_x:    182, a_y:   2014, g_x:   4064, g_y:  -4064
         //Top product * 10: 89245440
         //g magnitude: 5747.363917
         //Ideal cross-product: 1552.806491
         //Predicted function output: 1552
      {  4929,   4578,   8160,   1722,    836}, 
         //[ 553]:  (1,1,2,-1)
         //a_x:    833, a_y:    482, g_x:   4064, g_y:  -2374
         //Top product * 10: 39363900
         //g magnitude: 4706.588149
         //Ideal cross-product: 836.357437
         //Predicted function output: 836
      {  5853,   6522,   8160,   4096,   2426}, 
         //[ 554]:  (1,1,2,0)
         //a_x:   1757, a_y:   2426, g_x:   4064, g_y:      0
         //Top product * 10: 98592640
         //g magnitude: 4064.000000
         //Ideal cross-product: 2426.000000
         //Predicted function output: 2426
      {  4149,   5618,   8160,   7166,   1182}, 
         //[ 555]:  (1,1,2,1)
         //a_x:     53, a_y:   1522, g_x:   4064, g_y:   3070
         //Top product * 10: 60226980
         //g magnitude: 5093.230409
         //Ideal cross-product: 1182.490780
         //Predicted function output: 1182
      {  4849,   5560,   8160,   8160,    502}, 
         //[ 556]:  (1,1,2,2)
         //a_x:    753, a_y:   1464, g_x:   4064, g_y:   4064
         //Top product * 10: 28895040
         //g magnitude: 5747.363917
         //Ideal cross-product: 502.752921
         //Predicted function output: 502
      {  6187,   8160,     32,     32,   1395}, 
         //[ 557]:  (1,2,-2,-2)
         //a_x:   2091, a_y:   4064, g_x:  -4064, g_y:  -4064
         //Top product * 10: 80182720
         //g magnitude: 5747.363917
         //Ideal cross-product: 1395.121679
         //Predicted function output: 1395
      {  5607,   8160,     32,   1490,   2606}, 
         //[ 558]:  (1,2,-2,-1)
         //a_x:   1511, a_y:   4064, g_x:  -4064, g_y:  -2606
         //Top product * 10: 125784300
         //g magnitude: 4827.766772
         //Ideal cross-product: 2605.434478
         //Predicted function output: 2606
      {  7171,   8160,     32,   4096,   4064}, 
         //[ 559]:  (1,2,-2,0)
         //a_x:   3075, a_y:   4064, g_x:  -4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  7029,   8160,     32,   6545,   4997}, 
         //[ 560]:  (1,2,-2,1)
         //a_x:   2933, a_y:   4064, g_x:  -4064, g_y:   2449
         //Top product * 10: 236990130
         //g magnitude: 4744.860061
         //Ideal cross-product: 4994.670590
         //Predicted function output: 4997
      {  7470,   8160,     32,   8160,   5259}, 
         //[ 561]:  (1,2,-2,2)
         //a_x:   3374, a_y:   4064, g_x:  -4064, g_y:   4064
         //Top product * 10: 302280320
         //g magnitude: 5747.363917
         //Ideal cross-product: 5259.460238
         //Predicted function output: 5259
      {  4739,   8160,   1364,     32,   1734}, 
         //[ 562]:  (1,2,-1,-2)
         //a_x:    643, a_y:   4064, g_x:  -2732, g_y:  -4064
         //Top product * 10: 84896960
         //g magnitude: 4896.929650
         //Ideal cross-product: 1733.677346
         //Predicted function output: 1734
      {  6559,   8160,   3809,    471,   2135}, 
         //[ 563]:  (1,2,-1,-1)
         //a_x:   2463, a_y:   4064, g_x:   -287, g_y:  -3625
         //Top product * 10: 77620070
         //g magnitude: 3636.343493
         //Ideal cross-product: 2134.563749
         //Predicted function output: 2135
      {  8033,   8160,   3551,   4096,   4071}, 
         //[ 564]:  (1,2,-1,0)
         //a_x:   3937, a_y:   4064, g_x:   -545, g_y:      0
         //Top product * 10: 22148800
         //g magnitude: 545.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4071
      {  4640,   8160,   1006,   7182,   3261}, 
         //[ 565]:  (1,2,-1,1)
         //a_x:    544, a_y:   4064, g_x:  -3090, g_y:   3086
         //Top product * 10: 142365440
         //g magnitude: 4367.092397
         //Ideal cross-product: 3259.959421
         //Predicted function output: 3261
      {  5608,   8160,   2157,   8160,   3114}, 
         //[ 566]:  (1,2,-1,2)
         //a_x:   1512, a_y:   4064, g_x:  -1939, g_y:   4064
         //Top product * 10: 140248640
         //g magnitude: 4502.867642
         //Ideal cross-product: 3114.651621
         //Predicted function output: 3114
      {  5966,   8160,   4096,     32,   1870}, 
         //[ 567]:  (1,2,0,-2)
         //a_x:   1870, a_y:   4064, g_x:      0, g_y:  -4064
         //Top product * 10: 75996800
         //g magnitude: 4064.000000
         //Ideal cross-product: 1870.000000
         //Predicted function output: 1870
      {  6459,   8160,   4096,   3702,   2365}, 
         //[ 568]:  (1,2,0,-1)
         //a_x:   2363, a_y:   4064, g_x:      0, g_y:   -394
         //Top product * 10: 9310220
         //g magnitude: 394.000000
         //Ideal cross-product: 2363.000000
         //Predicted function output: 2384
         //DTA 20091212:  Expected value adjusted to
         //2365.  Presumed cause of disagreement is g-vector
         //normalization due to sub-1024 values of components.
         //G-vector normalization seems to lead to closer
         //value to ideal.
      {  6068,   8160,   4096,   4096,      0}, 
         //[ 569]:  (1,2,0,0)
         //a_x:   1972, a_y:   4064, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  8000,   8160,   4096,   7902,   3905}, 
         //[ 570]:  (1,2,0,1)
         //a_x:   3904, a_y:   4064, g_x:      0, g_y:   3806
         //Top product * 10: 148586240
         //g magnitude: 3806.000000
         //Ideal cross-product: 3904.000000
         //Predicted function output: 3905
      {  4493,   8160,   4096,   8160,    397}, 
         //[ 571]:  (1,2,0,2)
         //a_x:    397, a_y:   4064, g_x:      0, g_y:   4064
         //Top product * 10: 16134080
         //g magnitude: 4064.000000
         //Ideal cross-product: 397.000000
         //Predicted function output: 397
      {  6363,   8160,   6284,     32,   3923}, 
         //[ 572]:  (1,2,1,-2)
         //a_x:   2267, a_y:   4064, g_x:   2188, g_y:  -4064
         //Top product * 10: 181051200
         //g magnitude: 4615.564971
         //Ideal cross-product: 3922.622716
         //Predicted function output: 3923
      {  7942,   8160,   5456,    704,   5082}, 
         //[ 573]:  (1,2,1,-1)
         //a_x:   3846, a_y:   4064, g_x:   1360, g_y:  -3392
         //Top product * 10: 185726720
         //g magnitude: 3654.485463
         //Ideal cross-product: 5082.157854
         //Predicted function output: 5082
      {  5575,   8160,   6715,   4096,   4066}, 
         //[ 574]:  (1,2,1,0)
         //a_x:   1479, a_y:   4064, g_x:   2619, g_y:      0
         //Top product * 10: 106436160
         //g magnitude: 2619.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4066
      {  6341,   8160,   7507,   4793,   3535}, 
         //[ 575]:  (1,2,1,1)
         //a_x:   2245, a_y:   4064, g_x:   3411, g_y:    697
         //Top product * 10: 122975390
         //g magnitude: 3481.483879
         //Ideal cross-product: 3532.269408
         //Predicted function output: 3535
      {  7635,   8160,   5067,   8160,   2499}, 
         //[ 576]:  (1,2,1,2)
         //a_x:   3539, a_y:   4064, g_x:    971, g_y:   4064
         //Top product * 10: 104363520
         //g magnitude: 4178.389283
         //Ideal cross-product: 2497.697388
         //Predicted function output: 2499
      {  7429,   8160,   8160,     32,   5230}, 
         //[ 577]:  (1,2,2,-2)
         //a_x:   3333, a_y:   4064, g_x:   4064, g_y:  -4064
         //Top product * 10: 300614080
         //g magnitude: 5747.363917
         //Ideal cross-product: 5230.468860
         //Predicted function output: 5230
      {  4550,   8160,   8160,    740,   3422}, 
         //[ 578]:  (1,2,2,-1)
         //a_x:    454, a_y:   4064, g_x:   4064, g_y:  -3356
         //Top product * 10: 180397200
         //g magnitude: 5270.562778
         //Ideal cross-product: 3422.731264
         //Predicted function output: 3422
      {  8021,   8160,   8160,   4096,   4064}, 
         //[ 579]:  (1,2,2,0)
         //a_x:   3925, a_y:   4064, g_x:   4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  4250,   8160,   8160,   7497,   3017}, 
         //[ 580]:  (1,2,2,1)
         //a_x:    154, a_y:   4064, g_x:   4064, g_y:   3401
         //Top product * 10: 159923420
         //g magnitude: 5299.329863
         //Ideal cross-product: 3017.804593
         //Predicted function output: 3017
      {  7664,   8160,   8160,   8160,    350}, 
         //[ 581]:  (1,2,2,2)
         //a_x:   3568, a_y:   4064, g_x:   4064, g_y:   4064
         //Top product * 10: 20157440
         //g magnitude: 5747.363917
         //Ideal cross-product: 350.724963
         //Predicted function output: 350
      {  8160,     32,     32,     32,   5747}, 
         //[ 582]:  (2,-2,-2,-2)
         //a_x:   4064, a_y:  -4064, g_x:  -4064, g_y:  -4064
         //Top product * 10: 330321920
         //g magnitude: 5747.363917
         //Ideal cross-product: 5747.363917
         //Predicted function output: 5747
      {  8160,     32,     32,   3823,   4330}, 
         //[ 583]:  (2,-2,-2,-1)
         //a_x:   4064, a_y:  -4064, g_x:  -4064, g_y:   -273
         //Top product * 10: 176255680
         //g magnitude: 4073.159093
         //Ideal cross-product: 4327.247622
         //Predicted function output: 4330
      {  8160,     32,     32,   4096,   4064}, 
         //[ 584]:  (2,-2,-2,0)
         //a_x:   4064, a_y:  -4064, g_x:  -4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  8160,     32,     32,   7928,    168}, 
         //[ 585]:  (2,-2,-2,1)
         //a_x:   4064, a_y:  -4064, g_x:  -4064, g_y:   3832
         //Top product * 10: 9428480
         //g magnitude: 5585.724662
         //Ideal cross-product: 168.796004
         //Predicted function output: 168
      {  8160,     32,     32,   8160,      0}, 
         //[ 586]:  (2,-2,-2,2)
         //a_x:   4064, a_y:  -4064, g_x:  -4064, g_y:   4064
         //Top product * 10: 0
         //g magnitude: 5747.363917
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  8160,     32,    508,     32,   5736}, 
         //[ 587]:  (2,-2,-1,-2)
         //a_x:   4064, a_y:  -4064, g_x:  -3588, g_y:  -4064
         //Top product * 10: 310977280
         //g magnitude: 5421.239711
         //Ideal cross-product: 5736.276140
         //Predicted function output: 5736
      {  8160,     32,    276,   2521,   5307}, 
         //[ 588]:  (2,-2,-1,-1)
         //a_x:   4064, a_y:  -4064, g_x:  -3820, g_y:  -1575
         //Top product * 10: 219252800
         //g magnitude: 4131.951718
         //Ideal cross-product: 5306.276911
         //Predicted function output: 5307
      {  8160,     32,    910,   4096,   4066}, 
         //[ 589]:  (2,-2,-1,0)
         //a_x:   4064, a_y:  -4064, g_x:  -3186, g_y:      0
         //Top product * 10: 129479040
         //g magnitude: 3186.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4066
      {  8160,     32,   3344,   4982,    468}, 
         //[ 590]:  (2,-2,-1,1)
         //a_x:   4064, a_y:  -4064, g_x:   -752, g_y:    886
         //Top product * 10: 5445760
         //g magnitude: 1162.110150
         //Ideal cross-product: 468.609624
         //Predicted function output: 468
      {  8160,     32,   2904,   8160,   2756}, 
         //[ 591]:  (2,-2,-1,2)
         //a_x:   4064, a_y:  -4064, g_x:  -1192, g_y:   4064
         //Top product * 10: 116718080
         //g magnitude: 4235.204836
         //Ideal cross-product: 2755.901651
         //Predicted function output: 2756
      {  8160,     32,   4096,     32,   4064}, 
         //[ 592]:  (2,-2,0,-2)
         //a_x:   4064, a_y:  -4064, g_x:      0, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  8160,     32,   4096,    147,   4064}, 
         //[ 593]:  (2,-2,0,-1)
         //a_x:   4064, a_y:  -4064, g_x:      0, g_y:  -3949
         //Top product * 10: 160487360
         //g magnitude: 3949.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  8160,     32,   4096,   4096,      0}, 
         //[ 594]:  (2,-2,0,0)
         //a_x:   4064, a_y:  -4064, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  8160,     32,   4096,   7487,   4066}, 
         //[ 595]:  (2,-2,0,1)
         //a_x:   4064, a_y:  -4064, g_x:      0, g_y:   3391
         //Top product * 10: 137810240
         //g magnitude: 3391.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4066
      {  8160,     32,   4096,   8160,   4064}, 
         //[ 596]:  (2,-2,0,2)
         //a_x:   4064, a_y:  -4064, g_x:      0, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  8160,     32,   5950,     32,   2011}, 
         //[ 597]:  (2,-2,1,-2)
         //a_x:   4064, a_y:  -4064, g_x:   1854, g_y:  -4064
         //Top product * 10: 89814400
         //g magnitude: 4466.924221
         //Ideal cross-product: 2010.654212
         //Predicted function output: 2011
      {  8160,     32,   7400,   1656,    855}, 
         //[ 598]:  (2,-2,1,-1)
         //a_x:   4064, a_y:  -4064, g_x:   3304, g_y:  -2440
         //Top product * 10: 35112960
         //g magnitude: 4107.312503
         //Ideal cross-product: 854.888932
         //Predicted function output: 855
      {  8160,     32,   7036,   4096,   4067}, 
         //[ 599]:  (2,-2,1,0)
         //a_x:   4064, a_y:  -4064, g_x:   2940, g_y:      0
         //Top product * 10: 119481600
         //g magnitude: 2940.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4067
      {  8160,     32,   7063,   4129,   4110}, 
         //[ 600]:  (2,-2,1,1)
         //a_x:   4064, a_y:  -4064, g_x:   2967, g_y:     33
         //Top product * 10: 121920000
         //g magnitude: 2967.183513
         //Ideal cross-product: 4108.947069
         //Predicted function output: 4110
      {  8160,     32,   6833,   8160,   5641}, 
         //[ 601]:  (2,-2,1,2)
         //a_x:   4064, a_y:  -4064, g_x:   2737, g_y:   4064
         //Top product * 10: 276392640
         //g magnitude: 4899.720910
         //Ideal cross-product: 5640.987416
         //Predicted function output: 5641
      {  8160,     32,   8160,     32,      0}, 
         //[ 602]:  (2,-2,2,-2)
         //a_x:   4064, a_y:  -4064, g_x:   4064, g_y:  -4064
         //Top product * 10: 0
         //g magnitude: 5747.363917
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  8160,     32,   8160,   3101,   2982}, 
         //[ 603]:  (2,-2,2,-1)
         //a_x:   4064, a_y:  -4064, g_x:   4064, g_y:   -995
         //Top product * 10: 124724160
         //g magnitude: 4184.031668
         //Ideal cross-product: 2980.956405
         //Predicted function output: 2982
      {  8160,     32,   8160,   4096,   4064}, 
         //[ 604]:  (2,-2,2,0)
         //a_x:   4064, a_y:  -4064, g_x:   4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  8160,     32,   8160,   6589,   5592}, 
         //[ 605]:  (2,-2,2,1)
         //a_x:   4064, a_y:  -4064, g_x:   4064, g_y:   2493
         //Top product * 10: 266476480
         //g magnitude: 4767.719056
         //Ideal cross-product: 5589.181679
         //Predicted function output: 5592
      {  8160,     32,   8160,   8160,   5747}, 
         //[ 606]:  (2,-2,2,2)
         //a_x:   4064, a_y:  -4064, g_x:   4064, g_y:   4064
         //Top product * 10: 330321920
         //g magnitude: 5747.363917
         //Ideal cross-product: 5747.363917
         //Predicted function output: 5747
      {  8160,   2359,     32,     32,   4102}, 
         //[ 607]:  (2,-1,-2,-2)
         //a_x:   4064, a_y:  -1737, g_x:  -4064, g_y:  -4064
         //Top product * 10: 235752640
         //g magnitude: 5747.363917
         //Ideal cross-product: 4101.926438
         //Predicted function output: 4102
      {  8160,   1872,     32,   2734,   3401}, 
         //[ 608]:  (2,-1,-2,-1)
         //a_x:   4064, a_y:  -2224, g_x:  -4064, g_y:  -1362
         //Top product * 10: 145735040
         //g magnitude: 4286.156787
         //Ideal cross-product: 3400.133202
         //Predicted function output: 3401
      {  8160,   2754,     32,   4096,   1342}, 
         //[ 609]:  (2,-1,-2,0)
         //a_x:   4064, a_y:  -1342, g_x:  -4064, g_y:      0
         //Top product * 10: 54538880
         //g magnitude: 4064.000000
         //Ideal cross-product: 1342.000000
         //Predicted function output: 1342
      {  8160,   1967,     32,   7281,    831}, 
         //[ 610]:  (2,-1,-2,1)
         //a_x:   4064, a_y:  -2129, g_x:  -4064, g_y:   3185
         //Top product * 10: 42915840
         //g magnitude: 5163.363342
         //Ideal cross-product: 831.160566
         //Predicted function output: 831
      {  8160,   2706,     32,   8160,   1890}, 
         //[ 611]:  (2,-1,-2,2)
         //a_x:   4064, a_y:  -1390, g_x:  -4064, g_y:   4064
         //Top product * 10: 108671360
         //g magnitude: 5747.363917
         //Ideal cross-product: 1890.803533
         //Predicted function output: 1890
      {  8160,   2014,    329,     32,   4397}, 
         //[ 612]:  (2,-1,-1,-2)
         //a_x:   4064, a_y:  -2082, g_x:  -3767, g_y:  -4064
         //Top product * 10: 243589900
         //g magnitude: 5541.334226
         //Ideal cross-product: 4395.870924
         //Predicted function output: 4397
      {  8160,   2568,   2510,   1565,   4256}, 
         //[ 613]:  (2,-1,-1,-1)
         //a_x:   4064, a_y:  -1528, g_x:  -1586, g_y:  -2531
         //Top product * 10: 127093920
         //g magnitude: 2986.864075
         //Ideal cross-product: 4255.095539
         //Predicted function output: 4256
      {  8160,   3451,   1466,   4096,    645}, 
         //[ 614]:  (2,-1,-1,0)
         //a_x:   4064, a_y:   -645, g_x:  -2630, g_y:      0
         //Top product * 10: 16963500
         //g magnitude: 2630.000000
         //Ideal cross-product: 645.000000
         //Predicted function output: 645
      {  8160,   2581,    561,   4548,    987}, 
         //[ 615]:  (2,-1,-1,1)
         //a_x:   4064, a_y:  -1515, g_x:  -3535, g_y:    452
         //Top product * 10: 35185970
         //g magnitude: 3563.780156
         //Ideal cross-product: 987.321565
         //Predicted function output: 987
      {  8160,   1916,   2663,   8160,   3109}, 
         //[ 616]:  (2,-1,-1,2)
         //a_x:   4064, a_y:  -2180, g_x:  -1433, g_y:   4064
         //Top product * 10: 133921560
         //g magnitude: 4309.244133
         //Ideal cross-product: 3107.773796
         //Predicted function output: 3109
      {  8160,   3183,   4096,     32,   4064}, 
         //[ 617]:  (2,-1,0,-2)
         //a_x:   4064, a_y:   -913, g_x:      0, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  8160,    971,   4096,    845,   4067}, 
         //[ 618]:  (2,-1,0,-1)
         //a_x:   4064, a_y:  -3125, g_x:      0, g_y:  -3251
         //Top product * 10: 132120640
         //g magnitude: 3251.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4067
      {  8160,   3885,   4096,   4096,      0}, 
         //[ 619]:  (2,-1,0,0)
         //a_x:   4064, a_y:   -211, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  8160,   3887,   4096,   7119,   4066}, 
         //[ 620]:  (2,-1,0,1)
         //a_x:   4064, a_y:   -209, g_x:      0, g_y:   3023
         //Top product * 10: 122854720
         //g magnitude: 3023.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4066
      {  8160,    534,   4096,   8160,   4064}, 
         //[ 621]:  (2,-1,0,2)
         //a_x:   4064, a_y:  -3562, g_x:      0, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  8160,   1594,   5077,     32,   3364}, 
         //[ 622]:  (2,-1,1,-2)
         //a_x:   4064, a_y:  -2502, g_x:    981, g_y:  -4064
         //Top product * 10: 140616340
         //g magnitude: 4180.724459
         //Ideal cross-product: 3363.444336
         //Predicted function output: 3364
      {  8160,   2523,   6366,   3869,   1162}, 
         //[ 623]:  (2,-1,1,-1)
         //a_x:   4064, a_y:  -1573, g_x:   2270, g_y:   -227
         //Top product * 10: 26481820
         //g magnitude: 2281.321766
         //Ideal cross-product: 1160.810386
         //Predicted function output: 1162
      {  8160,   1086,   6874,   4096,   3010}, 
         //[ 624]:  (2,-1,1,0)
         //a_x:   4064, a_y:  -3010, g_x:   2778, g_y:      0
         //Top product * 10: 83617800
         //g magnitude: 2778.000000
         //Ideal cross-product: 3010.000000
         //Predicted function output: 3010
      {  8160,   3761,   7651,   7909,   3201}, 
         //[ 625]:  (2,-1,1,1)
         //a_x:   4064, a_y:   -335, g_x:   3555, g_y:   3813
         //Top product * 10: 166869570
         //g magnitude: 5213.155858
         //Ideal cross-product: 3200.931922
         //Predicted function output: 3201
      {  8160,   1074,   4718,   8160,   4477}, 
         //[ 626]:  (2,-1,1,2)
         //a_x:   4064, a_y:  -3022, g_x:    622, g_y:   4064
         //Top product * 10: 183957800
         //g magnitude: 4111.323388
         //Ideal cross-product: 4474.418153
         //Predicted function output: 4477
      {  8160,   1779,   8160,     32,   1235}, 
         //[ 627]:  (2,-1,2,-2)
         //a_x:   4064, a_y:  -2317, g_x:   4064, g_y:  -4064
         //Top product * 10: 70998080
         //g magnitude: 5747.363917
         //Ideal cross-product: 1235.315547
         //Predicted function output: 1235
      {  8160,   3435,   8160,   3901,    465}, 
         //[ 628]:  (2,-1,2,-1)
         //a_x:   4064, a_y:   -661, g_x:   4064, g_y:   -195
         //Top product * 10: 18938240
         //g magnitude: 4068.675583
         //Ideal cross-product: 465.464489
         //Predicted function output: 465
      {  8160,   2445,   8160,   4096,   1651}, 
         //[ 629]:  (2,-1,2,0)
         //a_x:   4064, a_y:  -1651, g_x:   4064, g_y:      0
         //Top product * 10: 67096640
         //g magnitude: 4064.000000
         //Ideal cross-product: 1651.000000
         //Predicted function output: 1651
      {  8160,   2676,   8160,   7989,   3838}, 
         //[ 630]:  (2,-1,2,1)
         //a_x:   4064, a_y:  -1420, g_x:   4064, g_y:   3893
         //Top product * 10: 215920320
         //g magnitude: 5627.747773
         //Ideal cross-product: 3836.709261
         //Predicted function output: 3838
      {  8160,   1988,   8160,   8160,   4364}, 
         //[ 631]:  (2,-1,2,2)
         //a_x:   4064, a_y:  -2108, g_x:   4064, g_y:   4064
         //Top product * 10: 250830080
         //g magnitude: 5747.363917
         //Ideal cross-product: 4364.263053
         //Predicted function output: 4364
      {  8160,   4096,     32,     32,   2873}, 
         //[ 632]:  (2,0,-2,-2)
         //a_x:   4064, a_y:      0, g_x:  -4064, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 5747.363917
         //Ideal cross-product: 2873.681959
         //Predicted function output: 2873
      {  8160,   4096,     32,   1985,   1873}, 
         //[ 633]:  (2,0,-2,-1)
         //a_x:   4064, a_y:      0, g_x:  -4064, g_y:  -2111
         //Top product * 10: 85791040
         //g magnitude: 4579.565154
         //Ideal cross-product: 1873.344676
         //Predicted function output: 1873
      {  8160,   4096,     32,   4096,      0}, 
         //[ 634]:  (2,0,-2,0)
         //a_x:   4064, a_y:      0, g_x:  -4064, g_y:      0
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  8160,   4096,     32,   6993,   2359}, 
         //[ 635]:  (2,0,-2,1)
         //a_x:   4064, a_y:      0, g_x:  -4064, g_y:   2897
         //Top product * 10: 117734080
         //g magnitude: 4990.862150
         //Ideal cross-product: 2358.992825
         //Predicted function output: 2359
      {  8160,   4096,     32,   8160,   2873}, 
         //[ 636]:  (2,0,-2,2)
         //a_x:   4064, a_y:      0, g_x:  -4064, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 5747.363917
         //Ideal cross-product: 2873.681959
         //Predicted function output: 2873
      {  8160,   4096,   3641,     32,   4041}, 
         //[ 637]:  (2,0,-1,-2)
         //a_x:   4064, a_y:      0, g_x:   -455, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 4089.391275
         //Ideal cross-product: 4038.766381
         //Predicted function output: 4041
      {  8160,   4096,   1180,    152,   3269}, 
         //[ 638]:  (2,0,-1,-1)
         //a_x:   4064, a_y:      0, g_x:  -2916, g_y:  -3944
         //Top product * 10: 160284160
         //g magnitude: 4904.915086
         //Ideal cross-product: 3267.827418
         //Predicted function output: 3269
      {  8160,   4096,    701,   4096,      0}, 
         //[ 639]:  (2,0,-1,0)
         //a_x:   4064, a_y:      0, g_x:  -3395, g_y:      0
         //Top product * 10: 0
         //g magnitude: 3395.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  8160,   4096,   1001,   4963,   1096}, 
         //[ 640]:  (2,0,-1,1)
         //a_x:   4064, a_y:      0, g_x:  -3095, g_y:    867
         //Top product * 10: 35234880
         //g magnitude: 3214.142810
         //Ideal cross-product: 1096.245005
         //Predicted function output: 1096
      {  8160,   4096,   3730,   8160,   4048}, 
         //[ 641]:  (2,0,-1,2)
         //a_x:   4064, a_y:      0, g_x:   -366, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 4080.447524
         //Ideal cross-product: 4047.618772
         //Predicted function output: 4048
      {  8160,   4096,   4096,     32,   4064}, 
         //[ 642]:  (2,0,0,-2)
         //a_x:   4064, a_y:      0, g_x:      0, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  8160,   4096,   4096,   1052,   4065}, 
         //[ 643]:  (2,0,0,-1)
         //a_x:   4064, a_y:      0, g_x:      0, g_y:  -3044
         //Top product * 10: 123708160
         //g magnitude: 3044.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4065
      {  8160,   4096,   4096,   4096,      0}, 
         //[ 644]:  (2,0,0,0)
         //a_x:   4064, a_y:      0, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  8160,   4096,   4096,   7785,   4066}, 
         //[ 645]:  (2,0,0,1)
         //a_x:   4064, a_y:      0, g_x:      0, g_y:   3689
         //Top product * 10: 149920960
         //g magnitude: 3689.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4066
      {  8160,   4096,   4096,   8160,   4064}, 
         //[ 646]:  (2,0,0,2)
         //a_x:   4064, a_y:      0, g_x:      0, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  8160,   4096,   4939,     32,   3982}, 
         //[ 647]:  (2,0,1,-2)
         //a_x:   4064, a_y:      0, g_x:    843, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 4150.511414
         //Ideal cross-product: 3979.291791
         //Predicted function output: 3982
      {  8160,   4096,   5404,   4075,     65}, 
         //[ 648]:  (2,0,1,-1)
         //a_x:   4064, a_y:      0, g_x:   1308, g_y:    -21
         //Top product * 10: 853440
         //g magnitude: 1308.168567
         //Ideal cross-product: 65.239299
         //Predicted function output: 65
      {  8160,   4096,   4927,   4096,      0}, 
         //[ 649]:  (2,0,1,0)
         //a_x:   4064, a_y:      0, g_x:    831, g_y:      0
         //Top product * 10: 0
         //g magnitude: 831.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  8160,   4096,   7517,   5512,   1554}, 
         //[ 650]:  (2,0,1,1)
         //a_x:   4064, a_y:      0, g_x:   3421, g_y:   1416
         //Top product * 10: 57546240
         //g magnitude: 3702.471742
         //Ideal cross-product: 1554.265475
         //Predicted function output: 1554
      {  8160,   4096,   4319,   8160,   4060}, 
         //[ 651]:  (2,0,1,2)
         //a_x:   4064, a_y:      0, g_x:    223, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 4070.113635
         //Ideal cross-product: 4057.895548
         //Predicted function output: 4060
      {  8160,   4096,   8160,     32,   2873}, 
         //[ 652]:  (2,0,2,-2)
         //a_x:   4064, a_y:      0, g_x:   4064, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 5747.363917
         //Ideal cross-product: 2873.681959
         //Predicted function output: 2873
      {  8160,   4096,   8160,   1564,   2149}, 
         //[ 653]:  (2,0,2,-1)
         //a_x:   4064, a_y:      0, g_x:   4064, g_y:  -2532
         //Top product * 10: 102900480
         //g magnitude: 4788.227229
         //Ideal cross-product: 2149.030843
         //Predicted function output: 2149
      {  8160,   4096,   8160,   4096,      0}, 
         //[ 654]:  (2,0,2,0)
         //a_x:   4064, a_y:      0, g_x:   4064, g_y:      0
         //Top product * 10: 0
         //g magnitude: 4064.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  8160,   4096,   8160,   5597,   1408}, 
         //[ 655]:  (2,0,2,1)
         //a_x:   4064, a_y:      0, g_x:   4064, g_y:   1501
         //Top product * 10: 61000640
         //g magnitude: 4332.331589
         //Ideal cross-product: 1408.032574
         //Predicted function output: 1408
      {  8160,   4096,   8160,   8160,   2873}, 
         //[ 656]:  (2,0,2,2)
         //a_x:   4064, a_y:      0, g_x:   4064, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 5747.363917
         //Ideal cross-product: 2873.681959
         //Predicted function output: 2873
      {  8160,   5455,     32,     32,   1912}, 
         //[ 657]:  (2,1,-2,-2)
         //a_x:   4064, a_y:   1359, g_x:  -4064, g_y:  -4064
         //Top product * 10: 109931200
         //g magnitude: 5747.363917
         //Ideal cross-product: 1912.723843
         //Predicted function output: 1912
      {  8160,   5195,     32,   3526,    524}, 
         //[ 658]:  (2,1,-2,-1)
         //a_x:   4064, a_y:   1099, g_x:  -4064, g_y:   -570
         //Top product * 10: 21498560
         //g magnitude: 4103.778259
         //Ideal cross-product: 523.872360
         //Predicted function output: 524
      {  8160,   7994,     32,   4096,   3898}, 
         //[ 659]:  (2,1,-2,0)
         //a_x:   4064, a_y:   3898, g_x:  -4064, g_y:      0
         //Top product * 10: 158414720
         //g magnitude: 4064.000000
         //Ideal cross-product: 3898.000000
         //Predicted function output: 3898
      {  8160,   4240,     32,   5543,   1498}, 
         //[ 660]:  (2,1,-2,1)
         //a_x:   4064, a_y:    144, g_x:  -4064, g_y:   1447
         //Top product * 10: 64658240
         //g magnitude: 4313.919911
         //Ideal cross-product: 1498.828011
         //Predicted function output: 1498
      {  8160,   6789,     32,   8160,   4778}, 
         //[ 661]:  (2,1,-2,2)
         //a_x:   4064, a_y:   2693, g_x:  -4064, g_y:   4064
         //Top product * 10: 274604480
         //g magnitude: 5747.363917
         //Ideal cross-product: 4777.920520
         //Predicted function output: 4778
      {  8160,   6481,    171,     32,   1266}, 
         //[ 662]:  (2,1,-1,-2)
         //a_x:   4064, a_y:   2385, g_x:  -3925, g_y:  -4064
         //Top product * 10: 71549710
         //g magnitude: 5649.931062
         //Ideal cross-product: 1266.382000
         //Predicted function output: 1266
      {  8160,   5199,    392,   1669,   1305}, 
         //[ 663]:  (2,1,-1,-1)
         //a_x:   4064, a_y:   1103, g_x:  -3704, g_y:  -2427
         //Top product * 10: 57778160
         //g magnitude: 4428.311755
         //Ideal cross-product: 1304.744634
         //Predicted function output: 1305
      {  8160,   5212,   4080,   4096,   1116}, 
         //[ 664]:  (2,1,-1,0)
         //a_x:   4064, a_y:   1116, g_x:    -16, g_y:      0
         //Top product * 10: 178560
         //g magnitude: 16.000000
         //Ideal cross-product: 1116.000000
         //Predicted function output: 0
         //DTA 20091212:  Expected value adjusted to
         //1116.  Presumed cause of disagreement is g-vector
         //normalization due to sub-1024 values of components.
         //G-vector normalization seems to lead to closer
         //value to ideal.
      {  8160,   7653,    974,   5076,   4613}, 
         //[ 665]:  (2,1,-1,1)
         //a_x:   4064, a_y:   3557, g_x:  -3122, g_y:    980
         //Top product * 10: 150876740
         //g magnitude: 3272.198649
         //Ideal cross-product: 4610.867376
         //Predicted function output: 4613
      {  8160,   4233,   2311,   8160,   3776}, 
         //[ 666]:  (2,1,-1,2)
         //a_x:   4064, a_y:    137, g_x:  -1785, g_y:   4064
         //Top product * 10: 167606410
         //g magnitude: 4438.729661
         //Ideal cross-product: 3775.999505
         //Predicted function output: 3776
      {  8160,   7805,   4096,     32,   4064}, 
         //[ 667]:  (2,1,0,-2)
         //a_x:   4064, a_y:   3709, g_x:      0, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  8160,   6632,   4096,   1598,   4067}, 
         //[ 668]:  (2,1,0,-1)
         //a_x:   4064, a_y:   2536, g_x:      0, g_y:  -2498
         //Top product * 10: 101518720
         //g magnitude: 2498.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4067
      {  8160,   6988,   4096,   4096,      0}, 
         //[ 669]:  (2,1,0,0)
         //a_x:   4064, a_y:   2892, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  8160,   7893,   4096,   5798,   4070}, 
         //[ 670]:  (2,1,0,1)
         //a_x:   4064, a_y:   3797, g_x:      0, g_y:   1702
         //Top product * 10: 69169280
         //g magnitude: 1702.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4070
      {  8160,   5296,   4096,   8160,   4064}, 
         //[ 671]:  (2,1,0,2)
         //a_x:   4064, a_y:   1200, g_x:      0, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  8160,   5777,   4833,     32,   4301}, 
         //[ 672]:  (2,1,1,-2)
         //a_x:   4064, a_y:   1681, g_x:    737, g_y:  -4064
         //Top product * 10: 177549930
         //g magnitude: 4130.286310
         //Ideal cross-product: 4298.731775
         //Predicted function output: 4301
      {  8160,   4797,   4919,   1226,   4099}, 
         //[ 673]:  (2,1,1,-1)
         //a_x:   4064, a_y:    701, g_x:    823, g_y:  -2870
         //Top product * 10: 122406030
         //g magnitude: 2985.670611
         //Ideal cross-product: 4099.783463
         //Predicted function output: 4099
      {  8160,   4367,   6984,   4096,    271}, 
         //[ 674]:  (2,1,1,0)
         //a_x:   4064, a_y:    271, g_x:   2888, g_y:      0
         //Top product * 10: 7826480
         //g magnitude: 2888.000000
         //Ideal cross-product: 271.000000
         //Predicted function output: 271
      {  8160,   7771,   4992,   6433,   2479}, 
         //[ 675]:  (2,1,1,1)
         //a_x:   4064, a_y:   3675, g_x:    896, g_y:   2337
         //Top product * 10: 62047680
         //g magnitude: 2502.875346
         //Ideal cross-product: 2479.055942
         //Predicted function output: 2479
      {  8160,   7617,   6449,   8160,   1753}, 
         //[ 676]:  (2,1,1,2)
         //a_x:   4064, a_y:   3521, g_x:   2353, g_y:   4064
         //Top product * 10: 82311830
         //g magnitude: 4696.030771
         //Ideal cross-product: 1752.795798
         //Predicted function output: 1753
      {  8160,   6982,   8160,     32,   4914}, 
         //[ 677]:  (2,1,2,-2)
         //a_x:   4064, a_y:   2886, g_x:   4064, g_y:  -4064
         //Top product * 10: 282448000
         //g magnitude: 5747.363917
         //Ideal cross-product: 4914.392129
         //Predicted function output: 4914
      {  8160,   5070,   8160,   2664,   2270}, 
         //[ 678]:  (2,1,2,-1)
         //a_x:   4064, a_y:    974, g_x:   4064, g_y:  -1432
         //Top product * 10: 97779840
         //g magnitude: 4308.911696
         //Ideal cross-product: 2269.246782
         //Predicted function output: 2270
      {  8160,   6894,   8160,   4096,   2798}, 
         //[ 679]:  (2,1,2,0)
         //a_x:   4064, a_y:   2798, g_x:   4064, g_y:      0
         //Top product * 10: 113710720
         //g magnitude: 4064.000000
         //Ideal cross-product: 2798.000000
         //Predicted function output: 2798
      {  8160,   8028,   8160,   7654,    281}, 
         //[ 680]:  (2,1,2,1)
         //a_x:   4064, a_y:   3932, g_x:   4064, g_y:   3558
         //Top product * 10: 15199360
         //g magnitude: 5401.431292
         //Ideal cross-product: 281.395045
         //Predicted function output: 281
      {  8160,   7994,   8160,   8160,    117}, 
         //[ 681]:  (2,1,2,2)
         //a_x:   4064, a_y:   3898, g_x:   4064, g_y:   4064
         //Top product * 10: 6746240
         //g magnitude: 5747.363917
         //Ideal cross-product: 117.379726
         //Predicted function output: 117
      {  8160,   8160,     32,     32,      0}, 
         //[ 682]:  (2,2,-2,-2)
         //a_x:   4064, a_y:   4064, g_x:  -4064, g_y:  -4064
         //Top product * 10: 0
         //g magnitude: 5747.363917
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  8160,   8160,     32,   1100,    860}, 
         //[ 683]:  (2,2,-2,-1)
         //a_x:   4064, a_y:   4064, g_x:  -4064, g_y:  -2996
         //Top product * 10: 43403520
         //g magnitude: 5048.971380
         //Ideal cross-product: 859.650743
         //Predicted function output: 860
      {  8160,   8160,     32,   4096,   4064}, 
         //[ 684]:  (2,2,-2,0)
         //a_x:   4064, a_y:   4064, g_x:  -4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  8160,   8160,     32,   5249,   5019}, 
         //[ 685]:  (2,2,-2,1)
         //a_x:   4064, a_y:   4064, g_x:  -4064, g_y:   1153
         //Top product * 10: 212018880
         //g magnitude: 4224.394039
         //Ideal cross-product: 5018.918170
         //Predicted function output: 5019
      {  8160,   8160,     32,   8160,   5747}, 
         //[ 686]:  (2,2,-2,2)
         //a_x:   4064, a_y:   4064, g_x:  -4064, g_y:   4064
         //Top product * 10: 330321920
         //g magnitude: 5747.363917
         //Ideal cross-product: 5747.363917
         //Predicted function output: 5747
      {  8160,   8160,   2443,     32,   2233}, 
         //[ 687]:  (2,2,-1,-2)
         //a_x:   4064, a_y:   4064, g_x:  -1653, g_y:  -4064
         //Top product * 10: 97983040
         //g magnitude: 4387.311819
         //Ideal cross-product: 2233.327469
         //Predicted function output: 2233
      {  8160,   8160,   3658,   1884,   3200}, 
         //[ 688]:  (2,2,-1,-1)
         //a_x:   4064, a_y:   4064, g_x:   -438, g_y:  -2212
         //Top product * 10: 72095360
         //g magnitude: 2254.947449
         //Ideal cross-product: 3197.207989
         //Predicted function output: 3200
      {  8160,   8160,   1539,   4096,   4064}, 
         //[ 689]:  (2,2,-1,0)
         //a_x:   4064, a_y:   4064, g_x:  -2557, g_y:      0
         //Top product * 10: 103916480
         //g magnitude: 2557.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  8160,   8160,   3551,   4863,   5667}, 
         //[ 690]:  (2,2,-1,1)
         //a_x:   4064, a_y:   4064, g_x:   -545, g_y:    767
         //Top product * 10: 53319680
         //g magnitude: 940.911260
         //Ideal cross-product: 5666.812827
         //Predicted function output: 5686
         //DTA 20091212:  Expected value adjusted to
         //5667.  Presumed cause of disagreement is g-vector
         //normalization due to sub-1024 values of components.
         //G-vector normalization seems to lead to closer
         //value to ideal.
      {  8160,   8160,   1982,   8160,   5482}, 
         //[ 691]:  (2,2,-1,2)
         //a_x:   4064, a_y:   4064, g_x:  -2114, g_y:   4064
         //Top product * 10: 251073920
         //g magnitude: 4580.948810
         //Ideal cross-product: 5480.827890
         //Predicted function output: 5482
      {  8160,   8160,   4096,     32,   4064}, 
         //[ 692]:  (2,2,0,-2)
         //a_x:   4064, a_y:   4064, g_x:      0, g_y:  -4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  8160,   8160,   4096,   1365,   4066}, 
         //[ 693]:  (2,2,0,-1)
         //a_x:   4064, a_y:   4064, g_x:      0, g_y:  -2731
         //Top product * 10: 110987840
         //g magnitude: 2731.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4066
      {  8160,   8160,   4096,   4096,      0}, 
         //[ 694]:  (2,2,0,0)
         //a_x:   4064, a_y:   4064, g_x:      0, g_y:      0
         //Top product * 10: 0
         //g magnitude: 0.000000
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
      {  8160,   8160,   4096,   5703,   4065}, 
         //[ 695]:  (2,2,0,1)
         //a_x:   4064, a_y:   4064, g_x:      0, g_y:   1607
         //Top product * 10: 65308480
         //g magnitude: 1607.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4065
      {  8160,   8160,   4096,   8160,   4064}, 
         //[ 696]:  (2,2,0,2)
         //a_x:   4064, a_y:   4064, g_x:      0, g_y:   4064
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  8160,   8160,   6204,     32,   5481}, 
         //[ 697]:  (2,2,1,-2)
         //a_x:   4064, a_y:   4064, g_x:   2108, g_y:  -4064
         //Top product * 10: 250830080
         //g magnitude: 4578.183046
         //Ideal cross-product: 5478.812828
         //Predicted function output: 5481
      {  8160,   8160,   7171,   2313,   5558}, 
         //[ 698]:  (2,2,1,-1)
         //a_x:   4064, a_y:   4064, g_x:   3075, g_y:  -1783
         //Top product * 10: 197429120
         //g magnitude: 3554.534287
         //Ideal cross-product: 5554.289368
         //Predicted function output: 5558
      {  8160,   8160,   6585,   4096,   4068}, 
         //[ 699]:  (2,2,1,0)
         //a_x:   4064, a_y:   4064, g_x:   2489, g_y:      0
         //Top product * 10: 101152960
         //g magnitude: 2489.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4068
      {  8160,   8160,   7949,   7698,    193}, 
         //[ 700]:  (2,2,1,1)
         //a_x:   4064, a_y:   4064, g_x:   3853, g_y:   3602
         //Top product * 10: 10200640
         //g magnitude: 5274.468030
         //Ideal cross-product: 193.396565
         //Predicted function output: 193
      {  8160,   8160,   7826,   8160,    246}, 
         //[ 701]:  (2,2,1,2)
         //a_x:   4064, a_y:   4064, g_x:   3730, g_y:   4064
         //Top product * 10: 13573760
         //g magnitude: 5516.248363
         //Ideal cross-product: 246.068688
         //Predicted function output: 246
      {  8160,   8160,   8160,     32,   5747}, 
         //[ 702]:  (2,2,2,-2)
         //a_x:   4064, a_y:   4064, g_x:   4064, g_y:  -4064
         //Top product * 10: 330321920
         //g magnitude: 5747.363917
         //Ideal cross-product: 5747.363917
         //Predicted function output: 5747
      {  8160,   8160,   8160,   1861,   5520}, 
         //[ 703]:  (2,2,2,-1)
         //a_x:   4064, a_y:   4064, g_x:   4064, g_y:  -2235
         //Top product * 10: 255991360
         //g magnitude: 4638.029862
         //Ideal cross-product: 5519.398702
         //Predicted function output: 5520
      {  8160,   8160,   8160,   4096,   4064}, 
         //[ 704]:  (2,2,2,0)
         //a_x:   4064, a_y:   4064, g_x:   4064, g_y:      0
         //Top product * 10: 165160960
         //g magnitude: 4064.000000
         //Ideal cross-product: 4064.000000
         //Predicted function output: 4064
      {  8160,   8160,   8160,   8021,    100}, 
         //[ 705]:  (2,2,2,1)
         //a_x:   4064, a_y:   4064, g_x:   4064, g_y:   3925
         //Top product * 10: 5648960
         //g magnitude: 5649.931062
         //Ideal cross-product: 99.982813
         //Predicted function output: 100
      {  8160,   8160,   8160,   8160,      0}, 
         //[ 706]:  (2,2,2,2)
         //a_x:   4064, a_y:   4064, g_x:   4064, g_y:   4064
         //Top product * 10: 0
         //g magnitude: 5747.363917
         //Ideal cross-product: 0.000000
         //Predicted function output: 0
   };


//Returns the number of test vectors that may be used for a speed test.
//
UCU_UINT32 UtsnAtU16v2CpDiva2FRxx(void)
   {
   return(sizeof(AtU16v2CpDiva2FRxx_Tvs)/sizeof(AtU16v2CpDiva2FRxx_Tvs[0]));
   }


//Runs a selected test vector.  This is used for automated speed testing.
//
void UtspAtU16v2CpDiva2FRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void))
   {
   UCU_UINT16 ax, ay, gx, gy, rv;

   if (test_no > (sizeof(AtU16v2CpDiva2FRxx_Tvs)/sizeof(AtU16v2CpDiva2FRxx_Tvs[0])))
      {
      while (1);  //Sieze up if bad input vector specifier.
      }

   ax = AtU16v2CpDiva2FRxx_Tvs[test_no].ax;
   ay = AtU16v2CpDiva2FRxx_Tvs[test_no].ay;
   gx = AtU16v2CpDiva2FRxx_Tvs[test_no].gx;
   gy = AtU16v2CpDiva2FRxx_Tvs[test_no].gy;

   //We are ready to make the call.  Start the caller's timer.
   (*start_pointer)();

   //Call the function.
   rv = UcuAtU16v2CpDiva2FRxx(ax, ay, gx, gy);

   //The call is finished.  Stop the caller's timer.
   (*end_pointer)();
   }


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuAtU16v2CpDiva2FRxx(void)
   {
   UCU_BOOLEAN rv;
   UCU_UINT16  i;
   UCU_UINT16  ax, ay, gx, gy, er, result;

   rv = UCU_TRUE;

   for (i=0; i<(sizeof(AtU16v2CpDiva2FRxx_Tvs)/sizeof(AtU16v2CpDiva2FRxx_Tvs[0])); i++)
      {
      ax = AtU16v2CpDiva2FRxx_Tvs[i].ax;
      ay = AtU16v2CpDiva2FRxx_Tvs[i].ay;
      gx = AtU16v2CpDiva2FRxx_Tvs[i].gx;
      gy = AtU16v2CpDiva2FRxx_Tvs[i].gy;
			er = AtU16v2CpDiva2FRxx_Tvs[i].er;

      result = UcuAtU16v2CpDiva2FRxx(ax, ay, gx, gy);

      if (result != er)
         {
         rv = UCU_FALSE;
         }
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_atu16v2cpdiva2frxx.c,v $
//Revision 1.4  2010/02/19 23:12:54  dashley
//Some test vector entries had to be modified.  Unit test passed.
//
//Revision 1.3  2010/02/19 21:02:51  dashley
//Edits.
//
//Revision 1.2  2010/02/19 20:33:55  dashley
//Extra line removed.
//
//Revision 1.1  2010/02/19 20:33:13  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_atu16v2cpdiva2frxx.c,v $
//-------------------------------------------------------------------------------

