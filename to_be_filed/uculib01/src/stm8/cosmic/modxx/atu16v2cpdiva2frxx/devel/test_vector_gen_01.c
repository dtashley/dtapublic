//--------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/atu16v2cpdiva2frxx/devel/test_vector_gen_01.c,v 1.2 2010/02/19 18:59:38 dashley Exp $
//--------------------------------------------------------------------------------
//Dave Ashley, (C)Cequent Performance Products, 2009-2010
//--------------------------------------------------------------------------------
//This program generates test vectors for the vector cross product function
//of the Prodigy 2 trailer brake controller.  As part of the vectors,
//it also generates the expected value of the return value of the function.
//This data can be used by automated unit test code.
//
//The program is designed for a standard x86 *nix system, and can be compiled
//using "gcc test_vector_gen_01.c -o test_vector_gen_01 -lm".
//--------------------------------------------------------------------------------
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//--------------------------------------------------------------------------------
//Constants.
#define INDENT (3)
//--------------------------------------------------------------------------------
//The type that is a test vector.
typedef struct
   {
   unsigned a_x;
   unsigned a_y;
   unsigned g_x;
   unsigned g_y;
   char *desc;
   } TESTVECTOR;
//--------------------------------------------------------------------------------
//The array of reference test vectors.  These are prepended to the automatically-
//generated ones.
const TESTVECTOR static_tvs[] =
  {
     //**************************************************************
     {
           0,     0,     0,     0, "in_a_vec_1=0 excess-4096 mapping test."
     },
     {
           1,     0,     0,     0, "in_a_vec_1=1 excess-4096 mapping test."
     },
     {
          31,     0,     0,     0, "in_a_vec_1=31 excess-4096 mapping test."
     },
     {
          32,     0,     0,     0, "in_a_vec_1=32 excess-4096 mapping test."
     },
     {
          33,     0,     0,     0, "in_a_vec_1=33 excess-4096 mapping test."
     },
     {
         201,     0,     0,     0, "in_a_vec_1=201 excess-4096 mapping test."
     },
     {
        4095,     0,     0,     0, "in_a_vec_1=4095 excess-4096 mapping test."
     },
     {
        4096,     0,     0,     0, "in_a_vec_1=4096 excess-4096 mapping test."
     },
     {
        4097,     0,     0,     0, "in_a_vec_1=4097 excess-4096 mapping test."
     },
     {
        5023,     0,     0,     0, "in_a_vec_1=5023 excess-4096 mapping test."
     },
     {
        8159,     0,     0,     0, "in_a_vec_1=8159 excess-4096 mapping test."
     },
     {
        8160,     0,     0,     0, "in_a_vec_1=8160 excess-4096 mapping test."
     },
     {
        8161,     0,     0,     0, "in_a_vec_1=8161 excess-4096 mapping test."
     },

     //**************************************************************
     {
           0,     0,     0,     0, "in_a_vec_2=0 excess-4096 mapping test."
     },
     {
           0,     1,     0,     0, "in_a_vec_2=1 excess-4096 mapping test."
     },
     {
           0,    31,     0,     0, "in_a_vec_2=31 excess-4096 mapping test."
     },
     {
           0,    32,     0,     0, "in_a_vec_2=32 excess-4096 mapping test."
     },
     {
           0,    33,     0,     0, "in_a_vec_2=33 excess-4096 mapping test."
     },
     {
           0,   201,     0,     0, "in_a_vec_2=201 excess-4096 mapping test."
     },
     {
           0,  4095,     0,     0, "in_a_vec_2=4095 excess-4096 mapping test."
     },
     {
           0,  4096,     0,     0, "in_a_vec_2=4096 excess-4096 mapping test."
     },
     {
           0,  4097,     0,     0, "in_a_vec_2=4097 excess-4096 mapping test."
     },
     {
           0,  5023,     0,     0, "in_a_vec_2=5023 excess-4096 mapping test."
     },
     {
           0,  8159,     0,     0, "in_a_vec_2=8159 excess-4096 mapping test."
     },
     {
           0,  8160,     0,     0, "in_a_vec_2=8160 excess-4096 mapping test."
     },
     {
           0,  8161,     0,     0, "in_a_vec_2=8161 excess-4096 mapping test."
     },
     //**************************************************************
     {
           0,     0,     0,     0, "in_g_vec_1=0 excess-4096 mapping test."
     },
     {
           0,     0,     1,     0, "in_g_vec_1=1 excess-4096 mapping test."
     },
     {
           0,     0,    31,     0, "in_g_vec_1=31 excess-4096 mapping test."
     },
     {
           0,     0,    32,     0, "in_g_vec_1=32 excess-4096 mapping test."
     },
     {
           0,     0,    33,     0, "in_g_vec_1=33 excess-4096 mapping test."
     },
     {
           0,     0,   201,     0, "in_g_vec_1=201 excess-4096 mapping test."
     },
     {
           0,     0,  4095,     0, "in_g_vec_1=4095 excess-4096 mapping test."
     },
     {
           0,     0,  4096,     0, "in_g_vec_1=4096 excess-4096 mapping test."
     },
     {
           0,     0,  4097,     0, "in_g_vec_1=4097 excess-4096 mapping test."
     },
     {
           0,     0,  5023,     0, "in_g_vec_1=5023 excess-4096 mapping test."
     },
     {
           0,     0,  8159,     0, "in_g_vec_1=8159 excess-4096 mapping test."
     },
     {
           0,     0,  8160,     0, "in_g_vec_1=8160 excess-4096 mapping test."
     },
     {
           0,     0,  8161,     0, "in_g_vec_1=8161 excess-4096 mapping test."
     },
     //**************************************************************
     {
           0,     0,     0,     0, "in_g_vec_2=0 excess-4096 mapping test."
     },
     {
           0,     0,     0,     1, "in_g_vec_2=1 excess-4096 mapping test."
     },
     {
           0,     0,     0,    31, "in_g_vec_2=31 excess-4096 mapping test."
     },
     {
           0,     0,     0,    32, "in_g_vec_2=32 excess-4096 mapping test."
     },
     {
           0,     0,     0,    33, "in_g_vec_2=33 excess-4096 mapping test."
     },
     {
           0,     0,     0,   201, "in_g_vec_2=201 excess-4096 mapping test."
     },
     {
           0,     0,     0,  4095, "in_g_vec_2=4095 excess-4096 mapping test."
     },
     {
           0,     0,     0,  4096, "in_g_vec_2=4096 excess-4096 mapping test."
     },
     {
           0,     0,     0,  4097, "in_g_vec_2=4097 excess-4096 mapping test."
     },
     {
           0,     0,     0,  5023, "in_g_vec_2=5023 excess-4096 mapping test."
     },
     {
           0,     0,     0,  8159, "in_g_vec_2=8159 excess-4096 mapping test."
     },
     {
           0,     0,     0,  8160, "in_g_vec_2=8160 excess-4096 mapping test."
     },
     {
           0,     0,     0,  8161, "in_g_vec_2=8161 excess-4096 mapping test."
     },
     //**************************************************************
     {
           0+4096,     0+4096,     0+4096,     0+4096, "0-g vector trap test."
     },
     {
           0+4096,     0+4096,     1+4096,     0+4096, "One component of g (g_x) not zero."
     },
     {
           0+4096,     0+4096,     0+4096,     1+4096, "0ne component of g (g_y) not zero."
     },
     {
           0+4096,     0+4096,     1+4096,     1+4096, "Both components of g not zero."
     },
     //**************************************************************
     {
           0+4096,     0+4096,     0+4096,     1+4096, "Gravity normalization test."
     },
     {
           0+4096,     0+4096,     1+4096,     0+4096, "Gravity normalization test."
     },
     {
           0+4096,     0+4096,  1023+4096,     1+4096, "Gravity normalization test."
     },
     {
           0+4096,     0+4096,     1+4096,  1023+4096, "Gravity normalization test."
     },
     //**************************************************************
     {
        1255+4096,  -379+4096,   500+4096,     1+4096, "Identicality test."
     },
     {
        1255+4096,  -379+4096,  4000+4096,     0+4096, "Identicality test."
     },
     //**************************************************************
     {
           0+4096,     0+4096,  4064+4096,     0+4096, "Square root calculation overflow test."
     },
     {
           0+4096,     0+4096,     0+4096, -4064+4096, "Square root calculation overflow test."
     },
     {
           0+4096,     0+4096,  4064+4096,  4064+4096, "Square root calculation overflow test."
     },
     {
           0+4096,     0+4096, -4064+4096, -4064+4096, "Square root calculation overflow test."
     },
     //**************************************************************
     {
        1000+4096,  2500+4096,   900+4096,  3000+4096, "Sign permutation test (01/16)."
     },
     {
        1000+4096,  2500+4096,   900+4096, -3000+4096, "Sign permutation test (02/16)."
     },
     {
        1000+4096,  2500+4096,  -900+4096,  3000+4096, "Sign permutation test (03/16)."
     },
     {
        1000+4096,  2500+4096,  -900+4096, -3000+4096, "Sign permutation test (04/16)."
     },
     {
        1000+4096, -2500+4096,   900+4096,  3000+4096, "Sign permutation test (05/16)."
     },
     {
        1000+4096, -2500+4096,   900+4096, -3000+4096, "Sign permutation test (06/16)."
     },
     {
        1000+4096, -2500+4096,  -900+4096,  3000+4096, "Sign permutation test (07/16)."
     },
     {
        1000+4096, -2500+4096,  -900+4096, -3000+4096, "Sign permutation test (08/16)."
     },
     {
       -1000+4096,  2500+4096,   900+4096,  3000+4096, "Sign permutation test (09/16)."
     },
     {
       -1000+4096,  2500+4096,   900+4096, -3000+4096, "Sign permutation test (10/16)."
     },
     {
       -1000+4096,  2500+4096,  -900+4096,  3000+4096, "Sign permutation test (11/16)."
     },
     {
       -1000+4096,  2500+4096,  -900+4096, -3000+4096, "Sign permutation test (12/16)."
     },
     {
       -1000+4096, -2500+4096,   900+4096,  3000+4096, "Sign permutation test (13/16)."
     },
     {
       -1000+4096, -2500+4096,   900+4096, -3000+4096, "Sign permutation test (14/16)."
     },
     {
       -1000+4096, -2500+4096,  -900+4096,  3000+4096, "Sign permutation test (15/16)."
     },
     {
       -1000+4096, -2500+4096,  -900+4096, -3000+4096, "Sign permutation test (16/16)."
     },
  };
//--------------------------------------------------------------------------------
//A custom kludge assert()-like function.
//
static void custom_assert(int condition, int line_no)
   {
   if (! condition)
      {
      printf("Assertion failed, line: %d.\n", line_no); 
      exit(1);
      }
   }
//--------------------------------------------------------------------------------
//Returns the square root x10 that the integer square root x10 function in the
//microcontroller software is expected to return.
//
static unsigned sqrt_x10(unsigned arg)
   {
   long double in_arg, out_arg;
   unsigned rv;

   custom_assert(arg < 65536, __LINE__);

   in_arg = arg;
   in_arg *= 100;
   out_arg = sqrtl(in_arg);
   rv = out_arg;

   return(rv);
   }
//--------------------------------------------------------------------------------
//Returns the vector cross product over g as it is expected it would be returned by
//the function in the microcontroller code.  The arguments here are biased
//excess-4096.
//
static void vector_cp(unsigned in_ax, 
                      unsigned in_ay, 
                      unsigned in_gx, 
                      unsigned in_gy,
                      unsigned *out_u_tp_10,
                      double   *out_d_gmag,
                      unsigned *out_u_cp,
                      double   *out_d_cp)
   {
   int ax, ay, gx, gy, gsumofsquares;
   int upper_product_x10;
   int lower_gmag_x10;

   custom_assert(in_ax <= 8192,       __LINE__);
   custom_assert(in_ay <= 8192,       __LINE__);
   custom_assert(in_gx <= 8192,       __LINE__);
   custom_assert(in_gy <= 8192,       __LINE__);
   custom_assert(out_u_tp_10 != NULL, __LINE__);
   custom_assert(out_d_gmag  != NULL, __LINE__);
   custom_assert(out_u_cp    != NULL, __LINE__);
   custom_assert(out_d_cp    != NULL, __LINE__);

   //Assign the outputs just to be cautious.
   *out_u_tp_10 = 0;
   *out_d_gmag  = 0.0;
   *out_u_cp    = 0;
   *out_d_cp    = 0.0;

   //Convert the arguments to signed.
   ax = (int)in_ax - 4096;
   ay = (int)in_ay - 4096;
   gx = (int)in_gx - 4096;
   gy = (int)in_gy - 4096;

   //Calculate the upper product.
   upper_product_x10 = ax * gy - gx * ay;

   //Take its absolute value.
   if (upper_product_x10 < 0)
      upper_product_x10 = -upper_product_x10;

   //Multiply by 10 to match the square root that will be calculated.
   upper_product_x10 *= 10;

   //Assign the top product for the caller.
   *out_u_tp_10 = upper_product_x10;

   //Calculate the sum of squares for the gravity.
   gsumofsquares = gx * gx + gy * gy;

   //If the gravitational magnitude is 0, must return.
   if (gsumofsquares == 0)
      {
      *out_d_gmag = 0.0;
      *out_u_cp   = 0;
      *out_d_cp   = 0.0;

      return;
      }

   //printf("Before double math.\n");

   //Assign as a double what the gravitational magnitude and
   //the cross-product should be.  This will probably be used 
   //as a comment only.
      {
      double tp;
      double lower_sqrt;
      
      tp = upper_product_x10 / 10;
      *out_d_gmag = lower_sqrt = sqrt((double)gsumofsquares);

      *out_d_cp = tp/lower_sqrt;
      }

   //printf("After double math.\n");

   //Calculate the cross-product in the same way the microcontroller software
   //should calculate it.

   //printf("Entering sqrt_x10.\n");
   
   lower_gmag_x10 = sqrt_x10(gsumofsquares >> 10) << 5;

   //printf("Out of sqrt_x10.\n");

   //printf("Before statement.\n");

   //printf("Lower_gmag_x10: %d\n", lower_gmag_x10);
   
   if (lower_gmag_x10 != 0)
      *out_u_cp = upper_product_x10 / lower_gmag_x10;
   else
      *out_u_cp = 0;

   //printf("After statement.\n");
   }
//--------------------------------------------------------------------------------
//Returns a random number in the range of 50 through 4000, inclusive.
//
unsigned rand_50_4000_inc(void)
   {
   int val;

   //50 through 4000 is a range of 3951, or an offset of [0, 3950].
   //
   //Keep whacking on rand() until a suitable value pops up.
   while ((val = rand()) > 3950)
      ;

   //Return the value.
   return(val);
   }
//--------------------------------------------------------------------------------
//Dumps a number of spaces to the standard output.
//
static void nspaces(unsigned indent)
  {
  while(indent--)
     printf(" ");
  }
//--------------------------------------------------------------------------------
//Makes the mapping from the range code to the actual value that
//will be used.
//
unsigned range_code_map(unsigned arg)
   {
   unsigned rv;

   if (arg == 0)
      {
      return(4096-4064);
      }
   else if (arg == 1)
      {
      return(4096-rand_50_4000_inc());
      }
   else if (arg == 2)
      {
      return(4096);
      }
   else if (arg == 3)
      {
      return(4096+rand_50_4000_inc());
      }
   else
      {
      return(4096+4064);
      }
   }
//--------------------------------------------------------------------------------
//Processes and individual test vector and emits the output.
//
static void process_test_vector(const TESTVECTOR *tv, unsigned vn, unsigned indent)
   {
   unsigned out_u_tp_10;
   double out_d_gmag;
   unsigned out_u_cp;
   double out_d_cp;

   //printf("Entering vector_cp()\n");

   //Obtain the results of the test vector.  These will appear in the reference
   //structure and in the comments.
   vector_cp(tv->a_x, 
             tv->a_y, 
             tv->g_x, 
             tv->g_y,
             &out_u_tp_10,
             &out_d_gmag,
             &out_u_cp,
             &out_d_cp);
   //printf("Out of vector_cp()\n");

   nspaces(indent * 3);
   printf("{%6u, %6u, %6u, %6u, %6u}, \n",
	  tv->a_x, tv->a_y, tv->g_x, tv->g_y, out_u_cp);

   nspaces(indent * 4);
   printf("//[%4u]:  %s\n", 
          vn, tv->desc);

   nspaces(indent * 4);
   printf("//a_x: %6d, a_y: %6d, g_x: %6d, g_y: %6d\n", 
          (int)tv->a_x - 4096,
          (int)tv->a_y - 4096,
          (int)tv->g_x - 4096,
          (int)tv->g_y - 4096);

   nspaces(indent * 4);
   printf("//Top product * 10: %u\n", 
          out_u_tp_10);

   nspaces(indent * 4);
   printf("//g magnitude: %f\n", 
          out_d_gmag);

   nspaces(indent * 4);
   printf("//Ideal cross-product: %f\n", 
          out_d_cp);

   nspaces(indent * 4);
   printf("//Predicted function output: %u\n", 
   out_u_cp);
   }
//--------------------------------------------------------------------------------
int main(void)
   {
   unsigned rec_no = 0;
   unsigned i;
   unsigned i1, i2, i3, i4;
   TESTVECTOR tv;
   char buf[1000];

   //Emit the preamble.
   nspaces(INDENT);
   printf("static const struct\n");

   nspaces(INDENT*2);
   printf("{\n");

   nspaces(INDENT*2);
   printf("UINT16 ax;\n");
   
   nspaces(INDENT*2);
   printf("UINT16 ay;\n");

   nspaces(INDENT*2);
   printf("UINT16 gx;\n");

   nspaces(INDENT*2);
   printf("UINT16 gy;\n");

   nspaces(INDENT*2);
   printf("UINT16 er;\n");

   nspaces(INDENT*2);
   printf("} cp2_test_vectors[]\n");

   nspaces(INDENT*2);
   printf("=\n");

   nspaces(INDENT*2);
   printf("{\n");

   //Process the static test vectors.
   for (i=0; i<(sizeof(static_tvs)/sizeof(static_tvs[0])); i++)
     {
     process_test_vector(static_tvs + i, rec_no, INDENT);
     rec_no++;
     }

   //Process the dynamic test vectors.
   for (i1=0; i1<5; i1++)
      {
      for (i2=0; i2<5; i2++)
         {
	 for (i3=0; i3<5; i3++)
	    {
	    for (i4=0; i4<5; i4++)
	       {
	       tv.a_x = range_code_map(i1);
	       tv.a_y = range_code_map(i2);
	       tv.g_x = range_code_map(i3);
	       tv.g_y = range_code_map(i4);

               sprintf(buf, "(%d,%d,%d,%d)", i1-2, i2-2, i3-2, i4-2);
 
               tv.desc = buf;

               //printf("In ptv.\n");

               process_test_vector(&tv, rec_no, INDENT);

               //printf("Out of ptv.\n");

               rec_no++;
	       }
	    }
	 }
      }

   //Emit the postamble.
   nspaces(INDENT*2);
   printf("};\n");

   //No error if we've made it this far ...
   return(0);
   }
//--------------------------------------------------------------------------------
//$Log: test_vector_gen_01.c,v $
//Revision 1.2  2010/02/19 18:59:38  dashley
//Extra line removed.
//
//Revision 1.1  2010/02/19 18:59:06  dashley
//Initial checkin.
//--------------------------------------------------------------------------------
//End of $RCSfile: test_vector_gen_01.c,v $
//--------------------------------------------------------------------------------

