//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/amu16aavgfdmmu16nrxn/src/amu16aavgfdmmu16nrxn.c,v 1.5 2010/02/24 14:13:06 dashley Exp $
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


UCU_UINT16 UcuAmU16aAvgFDmmU16nRxn(const UCU_UINT16 *in_array, UCU_UINT16 in_nelem)
   {
   UCU_UINT32 sum;
   UCU_UINT16 min;
   UCU_UINT16 max;
   UCU_UINT16 i;

   sum = 0;
   min = 0xFFFF;
   max = 0;

   if (in_nelem == 0) 
      {
      //Illegal, but should give the caller some sane return value.
      return(0);
      }
   else if (in_nelem == 1)
      {
      //Sanest return value is just the single element.
      return(*in_array);
      }
   else if (in_nelem == 2)
      {
      //We can't discard the min and max in this case.  Sanest return value
      //is just the floored average.
      sum   = in_array[0];
      sum  += in_array[1];
      sum >>= 1;
      return(sum);
      }
   else
      {
      //At least 3 elements.
      //
      //Total up the elements, taking note of the min and max.
      //
      i = in_nelem;
      while (i) 
         {
         //Add to the total.
         sum += *in_array;

         //Form min and max.  Note that a given value may become both the
         //min and max.  This isn't harmful because there are at least 3
         //elements if at the end min and max are the same it means there
         //were 3 duplicates, and it is proper to remove 2.  The logic
         //below can _probably_ be changed to if-else, but would need to
         //think before I'm confident about this.
         if (*in_array > max)
            {
            max = *in_array;
            }
         if (*in_array < min) 
            {
            min = *in_array;
            }

         in_array++;
         i--;
         }

      //Discard min and max from the sum.
      sum -= min;
      sum -= max;

      //Return average of what is left, optimizing for popular buffer sizes.
      switch(in_nelem)
         {
         case  4:  //Were 4 elements originally, but with min and max removed
                   //treat it as 2 elements.
                   return(sum >> 1);
                   break;
         case  6:  //6 - 2 = 4
                   return(sum >> 2);
                   break;
         case  10: //10 - 2 = 8
                   return(sum >> 3);
                   break;
         case  18: //18 - 2 = 16
                   return(sum >> 4);
                   break;
         default:  return(sum/(in_nelem-2));  //General case:  division.  Slowest of all.
                   break;
         }
      }
   }

//-------------------------------------------------------------------------------
//End of $Id: amu16aavgfdmmu16nrxn.c,v 1.5 2010/02/24 14:13:06 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: amu16aavgfdmmu16nrxn.c,v $
//Revision 1.5  2010/02/24 14:13:06  dashley
//Minor array reference code change.  Should have no effect on generated
//code.
//
//Revision 1.4  2010/02/24 14:10:51  dashley
//Comments removed.
//
//Revision 1.3  2010/01/29 23:07:41  dashley
//Addition of two functions.
//
//Revision 1.2  2010/01/22 20:34:54  dashley
//Extra line removed.
//
//Revision 1.1  2010/01/22 20:34:26  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

