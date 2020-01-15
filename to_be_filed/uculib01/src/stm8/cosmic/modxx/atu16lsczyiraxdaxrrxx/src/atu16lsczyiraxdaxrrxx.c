//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/atu16lsczyiraxdaxrrxx/src/atu16lsczyiraxdaxrrxx.c,v 1.6 2010/02/08 19:47:05 dashley Exp $
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

//Optimization note, DTA 20100203:  The 32=32x32 multiplication
//below can be reduced to a 32=16x16 multiplication.  Probably should add an
//assembly-language 32=16x16 function function to do this and use that instead
//of what is in the code now.

UCU_UINT16 UcuAtU16LscZyiRAxdAxrRxx(UCU_UINT16 arg, UCU_UINT16 arg_outof, UCU_UINT16 tgt_outof)
   {
   UCU_UINT32 rv;

   if ((tgt_outof == 0) || (arg_outof == 0))
      {
      return(0);
      }
   else if (arg >= arg_outof)
      {
      return(tgt_outof);
      }

   else
      {
      rv  = (UCU_UINT32)arg * (UCU_UINT32)tgt_outof;

      rv += ((arg_outof-1) >> 1);
         //arg_outof is guaranteed non-zero because of the earlier test, so the 
         //subtraction above can't roll below zero.
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
      rv /= arg_outof;
      return(rv);
      }
   }


//-------------------------------------------------------------------------------
//End of $Id: atu16lsczyiraxdaxrrxx.c,v 1.6 2010/02/08 19:47:05 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: atu16lsczyiraxdaxrrxx.c,v $
//Revision 1.6  2010/02/08 19:47:05  dashley
//Defect corrected.
//
//Revision 1.5  2010/02/03 15:01:29  dashley
//Optimization comment added.
//
//Revision 1.4  2010/02/03 02:17:02  dashley
//a)Documentation removed (function is documented separately).
//b)Function simplified and modified.
//
//Revision 1.3  2010/01/30 04:53:55  dashley
//Addition of two functions.
//
//Revision 1.2  2010/01/22 16:50:29  dashley
//Extra line removed.
//
//Revision 1.1  2010/01/22 16:50:04  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

