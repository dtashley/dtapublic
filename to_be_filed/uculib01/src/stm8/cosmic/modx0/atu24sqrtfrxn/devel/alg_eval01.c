//--------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modx0/atu24sqrtfrxn/devel/alg_eval01.c,v 1.7 2010/03/02 16:47:42 dashley Exp $
//--------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------
//This program is to evaluate the bisection algorithm for calculating square
//roots before coding in assembly-language.  Things to be evaluated:
//  a)Correctness of the implementation (to be sure nothing was overlooked).
//  b)RAM requirements.
//This program can be compiled on a *nix system using something like:
//  gcc -lm -o alg_eval01 alg_eval01.c
//--------------------------------------------------------------------------------
#include <math.h>
#include <stdio.h>
//--------------------------------------------------------------------------------

unsigned int AtU24SqrtFRxn(unsigned int arg, int trace)
   {
   unsigned int two_2k_mask;
      //Mask allows rapid masking in of
      //2^2k without having to do the shift all at once.
      //
      //Space consumed is the same number of bits as the input argument.
      //That is 24 bits in this case.

   unsigned int trial_square;
      //The trial square we are evaluating.  This requires as many bits
      //as the input argument.  That is 24 bits in this case.

   unsigned int trial_square_prev;
      //The previous trial square, before trying another
      //bit.  This requires as many bits
      //as the input argument.  That is 24 bits in this case.

   unsigned int square_root_ls_ip1;
      //Square root shifted left by i+1.  Needs as many bits for this
      //as the input argument (24).

   if (trace)
      {
      printf("----------\n");
      printf("arg in: %u\n", arg);
      }

   //Our loop goes from 11 down to and including 0.  The initial
   //value of the 2k mask is 2^2k = 2^22.
   two_2k_mask = 0x0400000;
 
   //Trial square and trial square prev both get the value of 0.
   trial_square      = 0;
   trial_square_prev = 0;

   //The square root shifted starts off as 0.
   square_root_ls_ip1 = 0;

   while(1)
      {
      if (trace)
         printf("Two 2k mask %u\n", two_2k_mask);

      trial_square =    (trial_square_prev) 
	              + (square_root_ls_ip1)
	              + (two_2k_mask);

      if (trace)
         printf("Trial square: %u\n", trial_square);

      square_root_ls_ip1 >>= 1;  //This is now the square root shifted left
                                 //i, for the remainder of this iteration.

      if (arg >= trial_square)
	 {
	 square_root_ls_ip1 |= two_2k_mask;    //The square root now gets this bit set.
         trial_square_prev  =  trial_square;   //Update the trial square.
	 }

      if (two_2k_mask == 1)
         break;

      two_2k_mask  >>= 2;
      }
   
   return(square_root_ls_ip1);
   }


int main(void)
   {
   unsigned int i, result;

   printf("Execution begins.\n");

   for (i=0; i<(1<<24); i++)
      {
      result = AtU24SqrtFRxn(i, 0);

      printf("Arg: %u Result: %u.\n", i, result);
      }

   printf("Execution ends.\n");

   return(0);
   }


//--------------------------------------------------------------------------------
//$Log: alg_eval01.c,v $
//Revision 1.7  2010/03/02 16:47:42  dashley
//Enhanced algorithm working and believed correct.
//
//Revision 1.6  2010/03/02 16:35:31  dashley
//Edits.
//
//Revision 1.5  2010/03/02 16:30:35  dashley
//Enhanced algorithm working.
//
//Revision 1.4  2010/03/02 16:24:35  dashley
//Edits.
//
//Revision 1.3  2010/03/02 15:56:29  dashley
//Algorithm works.
//
//Revision 1.2  2010/03/02 15:34:17  dashley
//Edits.
//
//Revision 1.1  2010/03/02 14:59:26  dashley
//Initial checkin.
//--------------------------------------------------------------------------------
//End of $RCSfile: alg_eval01.c,v $.
//--------------------------------------------------------------------------------
