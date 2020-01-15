//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/atu16ratadjrrxx/src/atu16ratadjrrxx.c,v 1.4 2010/02/09 01:42:32 dashley Exp $
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


UCU_UINT16 UcuAtU16RatAdjRRxx(UCU_UINT16 arg, UCU_UINT16 arg_max, UCU_UINT16 adj_in, UCU_UINT16 adj_nom)
   {
   UCU_UINT32 rv;

   if (adj_in == 0)
      {
      if (arg == 0)
         {
         return(0);
         }
      else
         {
         return(arg_max);
         }
      }
   else if (adj_nom == 0)
      {
      return(0);
      }
   else
      {
      rv = (UCU_UINT32)arg * (UCU_UINT32)adj_nom;
      rv += ((adj_in - 1) >> 1);
         //adj_in can't be 0 because of the test above and so can't roll over
         //less than zero.
         //
         //The addition step above can't overflow.  Let W be the number of bit
         //patterns for an unsigned (16 bits), so that the unsigned value itself will be
         //in the range [0..W-1].  For a variable twice as long (32 bits), the number of
         //bit patterns is W**2, so that the variable itself is [0..W**2-1].
         //In a worst case, we are squaring the maximum 16-bit integer and adding the
         //maximum 16-bit integer, i.e.
         //  (W-1)**2 + W - 1
         //and we want to know if we can exceed
         //  W**2 - 1.
         //Doing the algebra:
         //    (W-1)**2 + W - 1
         //  = W**2 - 2W + 1 + W - 1
         //  = W**2 - W.
         //Clearly (W**2 - W) < (W**2 - 1), so this is OK.

      rv /= adj_in;

      if (rv > arg_max)
         {
         rv = arg_max;
         }

      return(rv);
      }
   }


//-------------------------------------------------------------------------------
//End of $Id: atu16ratadjrrxx.c,v 1.4 2010/02/09 01:42:32 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: atu16ratadjrrxx.c,v $
//Revision 1.4  2010/02/09 01:42:32  dashley
//Rounding logic simplified.
//
//Revision 1.3  2010/01/30 20:27:58  dashley
//Addition of U16 ratiometric adjustment function.
//
//Revision 1.2  2010/01/22 17:51:48  dashley
//Extra line removed.
//
//Revision 1.1  2010/01/22 17:51:30  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

