//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/atu16sqrtfrxx/src/atu16sqrtfrxx.c,v 1.4 2010/02/15 16:48:11 dashley Exp $
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


UCU_UINT8 UcuAtU16SqrtFRxx(UCU_UINT16 arg)
   {
   UCU_UINT8 smask, i, rv;

   rv = 0;
   smask = 0x80;

   for (i=0; i<8; i++)
      {
      rv |= smask;
      if ((rv * rv) > arg)
         {
         //We overshot.  Need to back off.
         rv &= (~smask);
         }
      else
         {
         //We are fine.  Leave the masked bit in.
         }

      smask >>= 1;
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//End of $Id: atu16sqrtfrxx.c,v 1.4 2010/02/15 16:48:11 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: atu16sqrtfrxx.c,v $
//Revision 1.4  2010/02/15 16:48:11  dashley
//Comment removed.
//
//Revision 1.3  2010/01/30 23:35:14  dashley
//Addition/renaming of square root functions.
//
//Revision 1.2  2010/01/22 01:53:32  dashley
//Extra line removed.
//
//Revision 1.1  2010/01/22 01:53:14  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

