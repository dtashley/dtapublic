//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/btu8bytecardnibplut/devel/u8_bit_card_table_gen.c,v 1.2 2010/02/09 19:32:50 dashley Exp $
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
//This program generates a bytewise lookup table used for functions that
//evaluate bit cardinality (the number of bits set in a data type).  The format
//chosen was a table of 128 bytes, with each byte containing two nibbles.  The
//lower nibble of byte [i] contains the cardinality of i, and the upper nibble
//of byte [i] contains the cardinality of 128+i.  This format was chosen to
//avoid shifting before indexing into the array.
//
//This program was designed to be compiled and run on a *nix system using
//a command like this:
//
//   gcc -o u8_bit_card_table_gen u8_bit_card_table_gen.c
//
//The program could be easily adapted to run on a Windows system.
//-------------------------------------------------------------------------------
#include <stdio.h>

unsigned table[128];


int char_cardinality(unsigned arg)
   {
   int i;
   int rv;

   rv = 0;

   for (i=0; i<8; i++)
      {
      if (arg & 1)
         rv++;
 
      arg >>= 1;
      }

   return(rv);
   }


void char_binary_emit(unsigned arg)
   {
   unsigned i;
   unsigned mask;

   mask = 0x80;

   for (i=0; i<8; i++)
      {
      if (arg & mask)
 	 printf("1");
      else
	 printf("0");

      mask >>= 1;
      }
   }


int main(void)
   {
   unsigned i;

   //Do lower nibbles.
   for (i=0; i<128; i++)
     table[i] = char_cardinality(i);

   //Do upper nibbles.
   for (i=128; i<256; i++)
     table[i-128] += (char_cardinality(i) << 4);

   //Emit the data.
   for (i=0; i<128; i++)
      {
      printf("   ");
      printf("0x%02x, ", table[i]);
      printf("//Idx [%3d]: ", i);
      printf("Upr nib %3d, \%", i+128);
      char_binary_emit(i+128);
      printf(", card %1d: ", table[i] >> 4);
      printf("Lwr nib %3d, \%", i);
      char_binary_emit(i);
      printf(", card %1d", table[i] & 0xF);
      printf("\n");
      }
   }

//-------------------------------------------------------------------------------
//$Log: u8_bit_card_table_gen.c,v $
//Revision 1.2  2010/02/09 19:32:50  dashley
//Cosmetic edits.
//
//Revision 1.1  2010/02/09 19:25:17  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: u8_bit_card_table_gen.c,v $.
//-------------------------------------------------------------------------------
