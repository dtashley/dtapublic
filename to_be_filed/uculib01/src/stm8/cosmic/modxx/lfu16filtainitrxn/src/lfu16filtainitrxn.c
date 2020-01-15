//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/lfu16filtainitrxn/src/lfu16filtainitrxn.c,v 1.5 2010/02/24 18:57:44 dashley Exp $
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


void UcuLfU16FiltAInitRxn(UCU_UNION48 *in_fs, UCU_UINT16 in_x_k_initial)
   {
   in_fs->uwa.uw[0] = in_x_k_initial;
      //Set the part before the radix point to be the passed value.
   in_fs->uwa.uw[1] = 0;
   in_fs->uwa.uw[2] = 0;
      //Bits after the radix point are assigned zero.
   }

//-------------------------------------------------------------------------------
//End of $Id: lfu16filtainitrxn.c,v 1.5 2010/02/24 18:57:44 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: lfu16filtainitrxn.c,v $
//Revision 1.5  2010/02/24 18:57:44  dashley
//Comments removed.
//
//Revision 1.4  2010/01/28 03:19:12  dashley
//Linear Filter A function name change.
//
//Revision 1.3  2010/01/27 00:37:52  dashley
//Name change of Linear Filter A functions.
//
//Revision 1.2  2010/01/22 21:23:52  dashley
//Extra line removed.
//
//Revision 1.1  2010/01/22 21:23:37  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

