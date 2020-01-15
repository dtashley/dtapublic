//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/include/stm8/cosmic/c/uculib.h,v 1.60 2010/06/11 18:23:19 dashley Exp $
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
#ifndef UCULIB_H_INCLUDED
#define UCULIB_H_INCLUDED

//CPU core identifiers
#define UCU_CPUCORE_STM8             (1)
#define UCU_CPUCORE_CPU08            (2)

//CPU core variant identifiers.  At the present time, there are no variants.
#define UCU_CPUCOREVAR_STM8_BASE     (1)
#define UCU_CPUCOREVAR_CPU08_BASE    (1)

//Boolean constants.
#define UCU_FALSE (0)
#define UCU_TRUE  (1)

//Library version constants.  The version below is "0.1e".
#define UCU_LIBVER_MAJOR             (0)
#define UCU_LIBVER_MINOR             (1)
#define UCU_LIBVER_MICRO             (4)
#define UCU_LIBVER_CPUCORE           (UCU_CPUCORE_STM8)
#define UCU_LIBVER_CPUCOREVAR        (UCU_CPUCOREVAR_STM8_BASE)

//Data types.  Fortunately, the compiler does not seem to allow any switches on
//the command line to modify the types (such switches would add complexity).
typedef unsigned char UCU_UINT8;
typedef signed   char UCU_SINT8;
typedef unsigned int  UCU_UINT16;
typedef signed   int  UCU_SINT16;
typedef unsigned long UCU_UINT32;
typedef signed   long UCU_SINT32;
typedef unsigned char UCU_BOOLEAN;
typedef _Bool         UCU_BOOLEAN_C99;

typedef UCU_UINT8  UCU_CPU_CCR;      //It takes a byte to hold the CCR.
typedef UCU_UINT16 UCU_CPU_SPTR_PC;  //It takes 16 bits to hold the program counter stack pointer.

//Data types.
typedef union
{
  UCU_UINT16 ui;    //Largest all-encompassing value must come first so that union initialization
                    //works correctly (={0}, for example).
  UCU_UINT8  uc[2];
} UCU_UNION16;

typedef union
{
  UCU_UINT32   ul;  //Largest all-encompassing value must come first so that union initialization
                    //works correctly (={0}, for example). 
  UCU_UINT16   ui[2];
  UCU_UINT8    uc[4];
} UCU_UNION32;

typedef union 
   {
   struct {UCU_UINT8  uc[6];} uca;
      //Mnemonic:  unsigned character array.
   struct {UCU_UINT16 uw[3];} uwa;
      //Mnemonic:  unsigned word array.
   struct {UCU_UINT32 ul;  UCU_UINT16 uw;} uluwni;
      //Mnemonic:  unsigned long followed by unsigned word named individually.
   struct {UCU_UINT16 uw;  UCU_UINT32 ul;} uwulni;
      //Mnemonic:  unsigned word followed by unsigned long named individually.
   } UCU_UNION48;

typedef union 
   {
   struct {UCU_UINT8  uc[8];} uca;
      //Mnemonic:  unsigned character array.
   struct {UCU_UINT16 uw[4];} uwa;
      //Mnemonic:  unsigned word array.
   struct {UCU_UINT32 ul[2];} ula;
      //Mnemonic:  unsigned long array.
   } UCU_UNION64;


//*******************************************************************************
//**** Arithmetic Functions *****************************************************
//*******************************************************************************
//UCU_UINT16 Comparison Functions
extern UCU_BOOLEAN UcuAtU16CmpDiffAbsGtRxx(UCU_UINT16 x1, UCU_UINT16 x2, UCU_UINT16 d);
//UCU_UINT16 Linear Scaling Functions, Zero Y-Offset
extern UCU_UINT16 UcuAtU16LscZyiFAxdAxrRxx(UCU_UINT16 arg, UCU_UINT16 arg_outof, UCU_UINT16 tgt_outof);
extern UCU_UINT16 UcuAtU16LscZyiRAxdAxrRxx(UCU_UINT16 arg, UCU_UINT16 arg_outof, UCU_UINT16 tgt_outof);
//UCU_UINT16 Ratiometric Adjustment Functions.
extern UCU_UINT16 UcuAtU16RatAdjRRxx(UCU_UINT16 arg, UCU_UINT16 arg_max, UCU_UINT16 adj_in, UCU_UINT16 adj_nom);
//UCU_UINT16 Vector Functions
extern UCU_UINT16 UcuAtU16v2CpDiva2FRxx(UCU_UINT16 in_a_vec_1, UCU_UINT16 in_a_vec_2, UCU_UINT16 in_g_vec_1, UCU_UINT16 in_g_vec_2);
//Square Root Extraction Functions
extern UCU_UINT8  UcuAtU8SqrtFRxx(UCU_UINT8 arg);
extern UCU_UINT8  UcuAtU16SqrtFRxx(UCU_UINT16 arg);
extern UCU_UINT16 UcuAtU16SqrtX10FRxx(UCU_UINT16 val);
//Trigonometric Functions
//UCU_UINT16 Trigonometric Functions
extern UCU_UINT8 UcuAtAtanIx100Odegx1RRxx(UCU_UINT16 arg);
//
//*******************************************************************************
//**** Bounded Arithmetic Functions *********************************************
//*******************************************************************************
//UCU_SINT8 Functions
extern UCU_SINT8 UcuBaS8AbsDiffBoundedRxx(UCU_SINT8 x1, UCU_SINT8 x2);
extern UCU_SINT8 UcuBaS8DiffBoundedRxx(UCU_SINT8 x1, UCU_SINT8 x2);
//UCU_SINT16 Functions
extern UCU_SINT16 UcuBaS16AbsDiffBoundedRxx(UCU_SINT16 x1, UCU_SINT16 x2);
extern UCU_SINT16 UcuBaS16DiffBoundedRxx(UCU_SINT16 x1, UCU_SINT16 x2);
//UCU_SINT32 Functions
extern UCU_SINT32 UcuBaS32AbsBoundedRxx(UCU_SINT32 x);
//
//*******************************************************************************
//**** Fixed-Point Arithmetic Functions *****************************************
//*******************************************************************************
//UCU_UINT16 [0,1024] [0,1] Bounded Functions
extern UCU_UINT16 UcuFpUm1024uProjIntoRU16aRxx(UCU_UINT16 arg, UCU_UINT16 arg_outof);
extern UCU_UINT16 UcuFpUm1024uMulRRxx(UCU_UINT16 arg1, UCU_UINT16 arg2);
//
//*******************************************************************************
//**** Large-Operand and Extended-Precision Arithmetic Functions ****************
//*******************************************************************************
//
//*******************************************************************************
//**** Block Memory Functions ***************************************************
//*******************************************************************************
//
//*******************************************************************************
//**** Bit-Mapped Set Functions *************************************************
//*******************************************************************************
//Bit set cardinality tables.
extern const UCU_UINT8 UcuBtU8ByteCardNibpLut[128];
extern const UCU_UINT32 UcuBtU32RmaskLut[33];
extern const UCU_UINT32 UcuBtU32BitByIndexLut[32];
//Bit set cardinality functions.
extern UCU_UINT8 UcuBtU8BitCardRxx(UCU_UINT8 arg);
extern UCU_UINT8 UcuBtU16BitCardRxx(UCU_UINT16 arg);
extern UCU_UINT8 UcuBtU32BitCardRxx(UCU_UINT32 arg);
extern UCU_UINT8 UcuBtU32BitCardRnRxx(UCU_UINT32 arg, UCU_UINT8 n);
//Rotation functions.
extern void UcuBtU32RotLeftNInPlaceRxn(UCU_UINT32 *tgt, UCU_UINT8 n);
//
//*******************************************************************************
//**** Search Functions *********************************************************
//*******************************************************************************
//
//*******************************************************************************
//**** Sort Functions ***********************************************************
//*******************************************************************************
//
//*******************************************************************************
//**** Array Manipulation Functions *********************************************
//*******************************************************************************
//Decrement But Not Below Zero Array Element Functions
extern void UcuAmU8aDnbzU16nRxn(UCU_UINT8 *in_arg, UCU_UINT16 in_nelem);
extern void UcuAmU16aDnbzU16nRxn(UCU_UINT16 *in_arg, UCU_UINT16 in_nelem);
extern void UcuAmU32aDnbzU16nRxn(UCU_UINT32 *in_arg, UCU_UINT16 in_nelem);
//Right shift functions.
extern void UcuAmU8aRs1U16nRxn(UCU_UINT8 *in_arr, UCU_UINT16 in_nelem, UCU_UINT8 in_pushval);
extern void UcuAmU16aRs1U16nRxn(UCU_UINT16 *in_arr, UCU_UINT16 in_nelem, UCU_UINT16 in_pushval);
//Average Functions
extern UCU_UINT16 UcuAmU16aAvgFU16nRxn(const UCU_UINT16 *in_array, UCU_UINT16 in_nelem);
extern UCU_UINT16 UcuAmU16aAvgFDmmU16nRxn(const UCU_UINT16 *in_array, UCU_UINT16 in_nelem);
extern void UcuAmU16aAvgFDmmRmmU16nRxn(const UCU_UINT16 *in_array, 
                                             UCU_UINT16  in_nelem, 
                                             UCU_UINT16 *out_avg, 
                                             UCU_UINT16 *out_el_min, 
                                             UCU_UINT16 *out_el_max);
//
//*******************************************************************************
//**** Linear Filter Functions **************************************************
//*******************************************************************************
//Linear Filter A
extern void UcuLfU16FiltAInitRxn(UCU_UNION48 *in_fs, UCU_UINT16 in_x_k_initial);
extern UCU_UINT16 UcuLfU16FiltAFiltRxn(UCU_UNION48 *in_fs, UCU_UINT16 in_x_k, UCU_UINT16 in_h);
//
//*******************************************************************************
//**** Non-Linear Filter Functions **********************************************
//*******************************************************************************
//
//*******************************************************************************
//**** Vertical Counter Functions ***********************************************
//*******************************************************************************
//
//*******************************************************************************
//**** Control System Component Functions ***************************************
//*******************************************************************************
//
//*******************************************************************************
//**** CRC, Checksum, and Non-Cryptographic Hash Functions **********************
//*******************************************************************************
//
//*******************************************************************************
//**** Cryptographic Hash Functions *********************************************
//*******************************************************************************
//
//*******************************************************************************
//**** Cipher Functions *********************************************************
//*******************************************************************************
//
//*******************************************************************************
//**** Miscellaneous Functions **************************************************
//*******************************************************************************
//Library version functions.
extern UCU_UINT16 UcuMfLibVerMajRxx(void);
extern UCU_UINT16 UcuMfLibVerMinMicRxx(void);
extern UCU_UINT16 UcuMfLibVerCpuRxx(void);
extern UCU_BOOLEAN UcuMfLibVerCmpRxx(UCU_UINT16 in_majorversion,
                                     UCU_UINT8  in_minorversion,
                                     UCU_UINT8  in_microversion,
                                     UCU_UINT8  in_cpucore,
                                     UCU_UINT8  in_cpucorevariant);
//CPU register manipulation functions.
extern UCU_CPU_CCR UcuMfCpuCcrGetRxx(void);
extern void UcuMfCpuCcrSetRxx(UCU_CPU_CCR in_ccr);
extern UCU_CPU_SPTR_PC UcuMfCpuSptrPcGetRxx(void);
//
//*******************************************************************************
//**** Utility Functions ********************************************************
//*******************************************************************************
//
//*******************************************************************************
//*******************************************************************************
//*******************************************************************************

#endif

//-------------------------------------------------------------------------------
//End of $Id: uculib.h,v 1.60 2010/06/11 18:23:19 dashley Exp $
//-------------------------------------------------------------------------------

