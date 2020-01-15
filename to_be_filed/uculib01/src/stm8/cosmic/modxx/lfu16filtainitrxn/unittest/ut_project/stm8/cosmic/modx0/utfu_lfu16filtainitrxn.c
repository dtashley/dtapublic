//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/lfu16filtainitrxn/unittest/ut_project/stm8/cosmic/modx0/utfu_lfu16filtainitrxn.c,v 1.3 2010/02/25 03:46:54 dashley Exp $
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
#define MODULE_UTFU_LFU16FILTAINITRXN

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_lfu16filtainitrxn.h"


UCU_UNION48 filter_state;


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuLfU16FiltAInitRxn(void)
   {
   UCU_BOOLEAN rv;

   //Set up the state before the call.
   filter_state.uca.uc[0] =  2;
   filter_state.uca.uc[1] =  3;
   filter_state.uca.uc[2] =  5;
   filter_state.uca.uc[3] =  7;
   filter_state.uca.uc[4] = 11;
   filter_state.uca.uc[5] = 13;

   //Make the call.  This should set the state a certain way.
   UcuLfU16FiltAInitRxn(&filter_state, 17*256 + 19);

   if (
         (filter_state.uca.uc[0] == 17)
         &&
         (filter_state.uca.uc[1] == 19)
         &&
         (filter_state.uca.uc[2] ==  0)
         &&
         (filter_state.uca.uc[3] ==  0)
         &&
         (filter_state.uca.uc[4] ==  0)
         &&
         (filter_state.uca.uc[5] ==  0)
      )
      {
      rv = UCU_TRUE;
      }
   else
      {
      rv = UCU_FALSE;
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_lfu16filtainitrxn.c,v $
//Revision 1.3  2010/02/25 03:46:54  dashley
//Unit test complte.
//
//Revision 1.2  2010/02/25 02:29:03  dashley
//Extra line removed.
//
//Revision 1.1  2010/02/25 02:28:21  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_lfu16filtainitrxn.c,v $
//-------------------------------------------------------------------------------

