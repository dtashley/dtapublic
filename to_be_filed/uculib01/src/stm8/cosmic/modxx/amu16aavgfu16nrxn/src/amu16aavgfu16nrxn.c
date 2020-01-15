//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/amu16aavgfu16nrxn/src/amu16aavgfu16nrxn.c,v 1.5 2010/02/23 18:40:20 dashley Exp $
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


UCU_UINT16 UcuAmU16aAvgFU16nRxn(const UCU_UINT16 *in_array, UCU_UINT16 in_nelem)
   {
   UCU_UINT32 sum;
   UCU_UINT16 i;
   
   if (in_nelem == 0)
      {
      return(0);  //Done this way because must skip the division by in_nelem below.
      }
   else
      {
      sum = 0;
      i   = in_nelem;

      //Total up the elements.
      while (i)
         {
         sum += (UCU_UINT32)(*in_array);  //LDW confirmed used to fetch the array element.
                                          //Instruction appears to be LDW x,(x).
                                          //
                                          //"sum" cannot overflow.  65535*65535 < (2^32-1).
         in_array++;
         i--;
         }

      //Divide to get the average.  Shifting is better
      //when helpful.
      switch(in_nelem)
         {
         case  2:  return(sum >> 1);
                   break;
         case  4:  return(sum >> 2);
                   break;
         case  8:  return(sum >> 3);
                   break;
         case 16:  return(sum >> 4);
                   break;
         default:  return(sum/in_nelem);  //General case:  division.  Slowest of all.
                   break;
         }
      }
   }

//-------------------------------------------------------------------------------
//End of $Id: amu16aavgfu16nrxn.c,v 1.5 2010/02/23 18:40:20 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: amu16aavgfu16nrxn.c,v $
//Revision 1.5  2010/02/23 18:40:20  dashley
//Comments removed.
//
//Revision 1.4  2010/01/29 23:07:42  dashley
//Addition of two functions.
//
//Revision 1.3  2010/01/29 06:59:20  dashley
//Addition of UcuAmU16aAvgFU16nRxn() function.
//
//Revision 1.2  2010/01/22 20:26:46  dashley
//Extra line removed.
//
//Revision 1.1  2010/01/22 20:26:27  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

