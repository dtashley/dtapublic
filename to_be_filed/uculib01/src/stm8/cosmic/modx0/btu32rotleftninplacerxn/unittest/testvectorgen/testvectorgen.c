//--------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modx0/btu32rotleftninplacerxn/unittest/testvectorgen/testvectorgen.c,v 1.8 2010/05/17 20:47:10 dashley Exp $
//--------------------------------------------------------------------------------
//Generates test vectors for the UcuBtU32RotLeftNInPlaceRxn() function.  The test
//vectors are a mixture of structured and random.  The vectors are designed to
//be pasted into the program that links with the library to test the function.
//
//The random test vectors output from this program are not repeatable, because
//the /dev/random device is used to create these.
//
//This program is designed to be compiled on a *nix box, although it could easily
//be ported to Windows.
//
//This program probably will not run correctly on a platform where the size of
//an integer is anything other then 32 bits.
//--------------------------------------------------------------------------------
#define NUM_RANDOM_VECTORS (3000)
#define ARRAY_OFFSET       (33)

#include <stdio.h>
#include <stdlib.h>

//Obtains a random unsigned integer.  If can't, exits.
//
unsigned random_unsigned_integer(void)
   {
   FILE *s;
   unsigned rv;
   size_t nread;

   rv = 0;

   s = fopen("/dev/random", "r");

   if (!s)
      {
      printf("Unable to open random source /dev/rand.\n");
      exit(1);
      }

   //Get the integer.
   nread = fread(&rv, sizeof(rv), 1, s);

   if (nread != 1)   
      {
      printf("Failure obtaining random integer via fread() on /dev/rand.\n");
      exit(1);
      }

   if (fclose(s))
      {
      printf("Error closing /dev/rand.\n");
      exit(1);
      }

   return(rv);
   }


//Obtains a random byte.
//
unsigned int random_byte(void)
   {
   static unsigned int ri;
   static unsigned int n_left;
   unsigned int rv;

   if (! n_left)
      {
      ri = random_unsigned_integer();
      n_left = 4;
      }

   rv   = ri & 0xFF;
   ri >>= 8;
   n_left--;

   return(rv);
   }


//Outputs a test vector to stdout.  The comment may optionally
//be a NULL pointer.
//
void vector_output(unsigned start, unsigned n, unsigned end, const char *comment)
   {
   static unsigned elno = ARRAY_OFFSET;
     
   printf("      {  0x%08XUL,  %3u,  0x%08XUL  },  // [%5u]", start, n, end, elno);
   if ((comment) && (*comment))
      printf(" %s", comment);
   printf("\n");

   elno++;
   }


unsigned left_roll(unsigned arg, unsigned n)
  {
  while (n--)
     {
     if (arg & 0x80000000U)
        {
	arg <<= 1;
	arg |= 1;
	}
     else
	{
	arg <<= 1;
	}
     }

  return(arg);
  }


void push_zero_test_vectors(void)
   {
   unsigned i, j;

   for (i=0; i<33; i++)
      {
      vector_output(0, i, left_roll(0,i), "Zero left roll test.");
      }

   for (i=0; i<25; i++)
      {
      j = random_byte();
      vector_output(0, j, left_roll(0,j), "Zero left roll test.");
      }
   }


void push_one_test_vectors(void)
   {
   unsigned i, j;

   for (i=0; i<33; i++)
      {
      vector_output(0xFFFFFFFFU, i, left_roll(0xFFFFFFFFU,i), "One left roll test.");
      }

   for (i=0; i<25; i++)
      {
      j = random_byte();
      vector_output(0xFFFFFFFFU, j, left_roll(0xFFFFFFFFU,j), "One left roll test.");
      }
   }


void push_random_test_vectors(void)
   {
   unsigned i, j, k;
   char x[200];

   for (i=0; i<NUM_RANDOM_VECTORS; i++)
      {
      j = random_unsigned_integer();
      k = random_byte();
      sprintf(x, "Random left roll test (%5u/%5u).", i+1, NUM_RANDOM_VECTORS);
      vector_output(j, k, left_roll(j,k), x);
      }
   }


int main(void)
   {
   push_zero_test_vectors();
   push_one_test_vectors();
   push_random_test_vectors();

   return(0);
   }


//--------------------------------------------------------------------------------
//$Log: testvectorgen.c,v $
//Revision 1.8  2010/05/17 20:47:10  dashley
//Number of test vectors increased.
//
//Revision 1.7  2010/05/17 20:43:26  dashley
//Error corrected.
//
//Revision 1.6  2010/05/17 19:30:30  dashley
//Comment enhanced.
//
//Revision 1.5  2010/05/17 18:47:56  dashley
//Edits.
//
//Revision 1.4  2010/05/17 16:59:44  dashley
//Edits.
//
//Revision 1.3  2010/05/15 04:50:19  dashley
//Edits.
//
//Revision 1.2  2010/05/14 20:42:31  dashley
//Extra line removed.
//
//Revision 1.1  2010/05/14 20:41:59  dashley
//Initial checkin.
//--------------------------------------------------------------------------------
