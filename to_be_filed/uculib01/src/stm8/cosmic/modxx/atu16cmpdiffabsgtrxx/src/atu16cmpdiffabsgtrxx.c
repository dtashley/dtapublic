//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/atu16cmpdiffabsgtrxx/src/atu16cmpdiffabsgtrxx.c,v 1.4 2010/01/29 01:44:44 dashley Exp $
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


UCU_BOOLEAN UcuAtU16CmpDiffAbsGtRxx( UCU_UINT16 sig1, UCU_UINT16 sig2, UCU_UINT16 threshold )
   {
   UCU_UINT16  gt, ls;
   UCU_BOOLEAN result;
   
   result = UCU_FALSE;
   
   if( sig1 > sig2 )
      {
      gt = sig1;
      ls = sig2;
      }
   else
      {
      gt = sig2;
      ls = sig1;
      }
   
   if( (gt - ls) > threshold )
      {
      result = UCU_TRUE;
      }
   
   return( result );
   }

//-------------------------------------------------------------------------------
//End of $Id: atu16cmpdiffabsgtrxx.c,v 1.4 2010/01/29 01:44:44 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: atu16cmpdiffabsgtrxx.c,v $
//Revision 1.4  2010/01/29 01:44:44  dashley
//Addition of UcuAtU16CmpDiffAbsGtRxx() function.
//
//Revision 1.3  2010/01/21 23:19:16  dashley
//Symbolic oversight with FALSE and TRUE corrected.
//
//Revision 1.2  2010/01/21 21:36:03  dashley
//Minor whitespace correction.
//
//Revision 1.1  2010/01/21 21:35:24  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

