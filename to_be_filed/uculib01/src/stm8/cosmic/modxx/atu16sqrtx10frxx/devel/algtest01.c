//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/atu16sqrtx10frxx/devel/algtest01.c,v 1.3 2010/02/16 20:45:24 dashley Exp $
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
//Tests the algorithm for exception cases
//-------------------------------------------------------------------------------
#include <math.h>
#include <stdio.h>

typedef unsigned char  UCU_BOOLEAN;
typedef unsigned char  UCU_UINT8;
typedef unsigned short UCU_UINT16;
typedef unsigned int   UCU_UINT32;
#define UCU_FALSE (0)
#define UCU_TRUE  (1)


UCU_UINT16 UcuAtU16SqrtX10FRxx( UCU_UINT16 val )
   {
   UCU_UINT8 i;
   UCU_BOOLEAN done;
   UCU_UINT32  w;
   UCU_UINT16  x, xlast; 

   x = 0x00ff;  
   xlast = 0;         

   w = val;
   w *= (UCU_UINT8) 100;  // times 100 gives results in fixed point math X 10
                          // since sqrt of 100 is 10.
   if(val == 0) 
      {
      done = UCU_TRUE;      // square root of 0 is 0
      x = 0;
      } 
   else
      {
      done = UCU_FALSE;         
      }

   for ( i = 0; (! done) && (i<6) ; i++ ) // iterative estimation algorithm
      {
      x = ( x + (UCU_UINT16)( w / (UCU_UINT32) x ) ) / 2;        

      if(xlast == x) 
         {
         done = UCU_TRUE;       
         }

      xlast = x;
      }
     
   return( x );
   }


int main(void)
   {
   int i;
   int sqrt_result;
   int function_result;
   int geq_point05;
   int p;

   printf("Sizeof UCU_BOOLEAN/UCU_UINT8/UCU_UINT16/UCU_UINT32 for testing: %u/%u/%u/%u.\n",
          sizeof(UCU_BOOLEAN),
          sizeof(UCU_UINT8), 
          sizeof(UCU_UINT16), 
          sizeof(UCU_UINT32));

   for (i=0; i<65536; i++)
      {
      sqrt_result = floor(sqrt(i) * 10.0);
      function_result = UcuAtU16SqrtX10FRxx(i);

      p = (int)(round(sqrt(i)*10.0));

      if (/*sqrt_result*/ p != function_result)
	 {
	 printf("%10d %10d %10d %20.6f\n", i, p, function_result, sqrt(i));
	 }
      }

   return(0);
   }

//-------------------------------------------------------------------------------
//End of $Id: algtest01.c,v 1.3 2010/02/16 20:45:24 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: algtest01.c,v $
//Revision 1.3  2010/02/16 20:45:24  dashley
//Program changed to evaluate whether function rounds or not.  It does not.
//The function being evaluated with return either floor(sqrt(x) * 10) or
//floor(sqrt(x) * 10) + 1, with no special rule as to which is returned.
//
//Revision 1.2  2010/02/16 20:35:28  dashley
//Edits.
//
//Revision 1.1  2010/02/16 20:21:28  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

