//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/atu16lsczyifaxdaxrrxx/src/atu16lsczyifaxdaxrrxx.c,v 1.5 2010/02/03 15:01:28 dashley Exp $
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

UCU_UINT16 UcuAtU16LscZyiFAxdAxrRxx(UCU_UINT16 arg, UCU_UINT16 arg_outof, UCU_UINT16 tgt_outof)
   {
   UCU_UINT32 rv;

   if ((tgt_outof == 0) || (arg_outof == 0))
      {
      return(0);
      }
   else if (arg >= arg_outof)  //==coverage not required, but is equivalent and quicker
      {
      return(tgt_outof);
      }
   else
      {
      rv = (UCU_UINT32)arg * (UCU_UINT32)tgt_outof;
      rv /= arg_outof;
      return(rv);
      }
   }


//-------------------------------------------------------------------------------
//End of $Id: atu16lsczyifaxdaxrrxx.c,v 1.5 2010/02/03 15:01:28 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: atu16lsczyifaxdaxrrxx.c,v $
//Revision 1.5  2010/02/03 15:01:28  dashley
//Optimization comment added.
//
//Revision 1.4  2010/02/03 02:04:05  dashley
//Documentation removed from function (function behavior is documented
//separately).
//
//Revision 1.3  2010/01/30 04:53:55  dashley
//Addition of two functions.
//
//Revision 1.2  2010/01/22 15:57:23  dashley
//Extra line removed.
//
//Revision 1.1  2010/01/22 15:57:01  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

