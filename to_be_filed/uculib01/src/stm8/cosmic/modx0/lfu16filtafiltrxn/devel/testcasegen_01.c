//================================================================================
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modx0/lfu16filtafiltrxn/devel/testcasegen_01.c,v 1.2 2010/02/25 15:32:06 dashley Exp $
//================================================================================
//This program assists in generating test vectors for the assembly-language
//filter "A".  The GMP is used because of the large integer operations.
//================================================================================
#include <gmp.h>
#include <stdio.h>


typedef struct
   {
   unsigned char uc[6];
   } BIGNUM_48;

typedef struct
   {
   unsigned char uc[8];
   } BIGNUM_64;

typedef struct
   {
   unsigned char uc[2];
   } BIGNUM_16;

typedef struct
   {
   BIGNUM_16 n16;
   BIGNUM_48 n48;
   } TEST_VEC_64_16_48;

//These are the test vectors.
//
const TEST_VEC_64_16_48 tvs[] =
   {
      {
	 {   0,   0},
	 {   0,   0,   0,   0,   0,   0}
      },
      {
	 {  17,  19},
	 {   2,   3,   5,   7,  11,  13}
      },
      {
	 { 223, 211},
	 { 251, 241, 239, 233, 229, 227}
      },
      {
	 { 255, 255},
	 {   0,   0,   0,   0,   0,   0}
      },
      {
	 {   0,   0},
	 { 255, 255, 255, 255, 255, 255}
      },
      {
	 { 255, 255},
	 {   0,   0,   0,   0,   0,   1}
      },
      {
	 {   0,   1},
	 { 255, 255, 255, 255, 255, 255}
      },
      {
	 { 255, 255},
	 {   1,   0,   0,   0,   0,   0}
      },
      {
	 {   1,   0},
	 { 255, 255, 255, 255, 255, 255}
      },
      {
	 { 255, 255},
	 { 255, 255, 255, 255, 255, 255}
      },
   };


static void hline(void)
   {
   printf("--------------------------------------------------------------------------------\n");
   }


static void my_mpz_emit(mpz_t arg, unsigned nbytes)
   {
   unsigned i;
   unsigned val;
   mpz_t temp, divisor, andmask, k256;

   //Initialize the temporary mpz's.
   mpz_init(temp);
   mpz_init(divisor);
   mpz_init(andmask);
   mpz_init(k256);

   //The AND-mask is always 255.
   mpz_set_ui(andmask, 255);

   //The constant 256 is always 256.
   mpz_set_ui(k256, 256);

   //In order to get to the i'th byte, we need to divide
   //by 256^(i-1).  So we start by setting the divisor to 
   //that value.
   mpz_set_ui(divisor, 1);
   for (i=1; i<nbytes; i++)
     {
     mpz_mul_ui(divisor, divisor, 256);
     }
 
   for (i=0; i<nbytes; i++)
      {
      //Copy the argument to the temporary variable.
      mpz_set(temp, arg);

      //Divide the temp by the divisor.
      mpz_fdiv_q(temp, temp, divisor);

      //And the value with 255 to get only the byte.
      mpz_and(temp, temp, andmask);

      //Assign the value to an unsigned integer for presentation.
      val = mpz_get_ui(temp);

      //Output the number in hex.
      printf("$%02X", val);

      //If we're not on our least iteration, output a space.
      if (i != (nbytes - 1))
         printf(" ");

      //Reduce the divisor for the next iteration.
      mpz_fdiv_q(divisor, divisor, k256);
      }

   //Deallocate the temporary mpz's.
   mpz_clear(temp);
   mpz_clear(divisor);
   mpz_clear(andmask);
   mpz_clear(k256);
   }


static void do_64_16_48_testcase(void)
   {
   unsigned i;
   mpz_t u16, u48, u64;

   //Initialize the three integers.  This must be done to allocate memory and so on.
   mpz_init(u16);
   mpz_init(u48);
   mpz_init(u64);

   for (i=0; i<(sizeof(tvs)/sizeof(tvs[0])); i++)
       {
       //Announcements.
       hline();
       printf("64=16x48 Vector: %u\n", i);

       //Be sure the integers are zero.
       mpz_set_ui(u16, 0);
       mpz_set_ui(u48, 0);
       mpz_set_ui(u64, 0);

       //Assign the 16-bit integer.
       mpz_add_ui(u16, u16, tvs[i].n16.uc[0]);
       mpz_mul_ui(u16, u16, 256);
       mpz_add_ui(u16, u16, tvs[i].n16.uc[1]);

       //Assign the 48-bit integer.
       mpz_add_ui(u48, u48, tvs[i].n48.uc[0]);
       mpz_mul_ui(u48, u48, 256);
       mpz_add_ui(u48, u48, tvs[i].n48.uc[1]);
       mpz_mul_ui(u48, u48, 256);
       mpz_add_ui(u48, u48, tvs[i].n48.uc[2]);
       mpz_mul_ui(u48, u48, 256);
       mpz_add_ui(u48, u48, tvs[i].n48.uc[3]);
       mpz_mul_ui(u48, u48, 256);
       mpz_add_ui(u48, u48, tvs[i].n48.uc[4]);
       mpz_mul_ui(u48, u48, 256);
       mpz_add_ui(u48, u48, tvs[i].n48.uc[5]);

       //Calculate the 64-bit value.
       mpz_mul(u64, u16, u48);

       //Emit the 16-bit operand.
       printf("16-bit operand: ");
       my_mpz_emit(u16, 2);
       printf("\n");

       //Emit the 48-bit operand.
       printf("48-bit operand: ");
       my_mpz_emit(u48, 6);
       printf("\n");

       //Emit the 64-bit operand.
       printf("64-bit result : ");
       my_mpz_emit(u64, 8);
       printf("\n");
       }

   //Deallocate the three integers.  This must be done to deallocate memory and so on.
   mpz_clear(u16);
   mpz_clear(u48);
   mpz_clear(u64);
   }


int main(void)
   {
   do_64_16_48_testcase();
   hline();
   return(0);
   }

//================================================================================
//$Log: testcasegen_01.c,v $
//Revision 1.2  2010/02/25 15:32:06  dashley
//Extra line removed.
//
//Revision 1.1  2010/02/25 15:31:43  dashley
//Initial checkin.
//================================================================================
//End of $RCSfile: testcasegen_01.c,v $.
//================================================================================
