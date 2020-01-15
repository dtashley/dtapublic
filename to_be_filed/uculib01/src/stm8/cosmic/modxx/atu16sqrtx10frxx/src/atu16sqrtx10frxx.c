//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/atu16sqrtx10frxx/src/atu16sqrtx10frxx.c,v 1.5 2010/02/15 20:35:40 dashley Exp $
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

#include "uculib.h"


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


//-------------------------------------------------------------------------------
//End of $Id: atu16sqrtx10frxx.c,v 1.5 2010/02/15 20:35:40 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: atu16sqrtx10frxx.c,v $
//Revision 1.5  2010/02/15 20:35:40  dashley
//Spelling error corrected.
//
//Revision 1.4  2010/02/15 20:16:51  dashley
//Comments removed.
//
//Revision 1.3  2010/01/30 23:35:14  dashley
//Addition/renaming of square root functions.
//
//Revision 1.2  2010/01/22 02:35:07  dashley
//Extra line removed.
//
//Revision 1.1  2010/01/22 02:34:49  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

