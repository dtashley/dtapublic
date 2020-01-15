//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/btu8bytecardnibplut/src/btu8bytecardnibplut.c,v 1.3 2010/01/31 02:46:48 dashley Exp $
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


const UCU_UINT8 UcuBtU8ByteCardNibpLut[128]
   =
   {
   //Lookup table entry [i] provides the cardinality of i+128 in the upper nibble
   //and the cardinality of i in the lower nibble.  This table was automatically generated.
   //
   0x10, //Idx [  0]: Upr nib 128, 10000000, card 1: Lwr nib   0, 00000000, card 0
   0x21, //Idx [  1]: Upr nib 129, 10000001, card 2: Lwr nib   1, 00000001, card 1
   0x21, //Idx [  2]: Upr nib 130, 10000010, card 2: Lwr nib   2, 00000010, card 1
   0x32, //Idx [  3]: Upr nib 131, 10000011, card 3: Lwr nib   3, 00000011, card 2
   0x21, //Idx [  4]: Upr nib 132, 10000100, card 2: Lwr nib   4, 00000100, card 1
   0x32, //Idx [  5]: Upr nib 133, 10000101, card 3: Lwr nib   5, 00000101, card 2
   0x32, //Idx [  6]: Upr nib 134, 10000110, card 3: Lwr nib   6, 00000110, card 2
   0x43, //Idx [  7]: Upr nib 135, 10000111, card 4: Lwr nib   7, 00000111, card 3
   0x21, //Idx [  8]: Upr nib 136, 10001000, card 2: Lwr nib   8, 00001000, card 1
   0x32, //Idx [  9]: Upr nib 137, 10001001, card 3: Lwr nib   9, 00001001, card 2
   0x32, //Idx [ 10]: Upr nib 138, 10001010, card 3: Lwr nib  10, 00001010, card 2
   0x43, //Idx [ 11]: Upr nib 139, 10001011, card 4: Lwr nib  11, 00001011, card 3
   0x32, //Idx [ 12]: Upr nib 140, 10001100, card 3: Lwr nib  12, 00001100, card 2
   0x43, //Idx [ 13]: Upr nib 141, 10001101, card 4: Lwr nib  13, 00001101, card 3
   0x43, //Idx [ 14]: Upr nib 142, 10001110, card 4: Lwr nib  14, 00001110, card 3
   0x54, //Idx [ 15]: Upr nib 143, 10001111, card 5: Lwr nib  15, 00001111, card 4
   0x21, //Idx [ 16]: Upr nib 144, 10010000, card 2: Lwr nib  16, 00010000, card 1
   0x32, //Idx [ 17]: Upr nib 145, 10010001, card 3: Lwr nib  17, 00010001, card 2
   0x32, //Idx [ 18]: Upr nib 146, 10010010, card 3: Lwr nib  18, 00010010, card 2
   0x43, //Idx [ 19]: Upr nib 147, 10010011, card 4: Lwr nib  19, 00010011, card 3
   0x32, //Idx [ 20]: Upr nib 148, 10010100, card 3: Lwr nib  20, 00010100, card 2
   0x43, //Idx [ 21]: Upr nib 149, 10010101, card 4: Lwr nib  21, 00010101, card 3
   0x43, //Idx [ 22]: Upr nib 150, 10010110, card 4: Lwr nib  22, 00010110, card 3
   0x54, //Idx [ 23]: Upr nib 151, 10010111, card 5: Lwr nib  23, 00010111, card 4
   0x32, //Idx [ 24]: Upr nib 152, 10011000, card 3: Lwr nib  24, 00011000, card 2
   0x43, //Idx [ 25]: Upr nib 153, 10011001, card 4: Lwr nib  25, 00011001, card 3
   0x43, //Idx [ 26]: Upr nib 154, 10011010, card 4: Lwr nib  26, 00011010, card 3
   0x54, //Idx [ 27]: Upr nib 155, 10011011, card 5: Lwr nib  27, 00011011, card 4
   0x43, //Idx [ 28]: Upr nib 156, 10011100, card 4: Lwr nib  28, 00011100, card 3
   0x54, //Idx [ 29]: Upr nib 157, 10011101, card 5: Lwr nib  29, 00011101, card 4
   0x54, //Idx [ 30]: Upr nib 158, 10011110, card 5: Lwr nib  30, 00011110, card 4
   0x65, //Idx [ 31]: Upr nib 159, 10011111, card 6: Lwr nib  31, 00011111, card 5
   0x21, //Idx [ 32]: Upr nib 160, 10100000, card 2: Lwr nib  32, 00100000, card 1
   0x32, //Idx [ 33]: Upr nib 161, 10100001, card 3: Lwr nib  33, 00100001, card 2
   0x32, //Idx [ 34]: Upr nib 162, 10100010, card 3: Lwr nib  34, 00100010, card 2
   0x43, //Idx [ 35]: Upr nib 163, 10100011, card 4: Lwr nib  35, 00100011, card 3
   0x32, //Idx [ 36]: Upr nib 164, 10100100, card 3: Lwr nib  36, 00100100, card 2
   0x43, //Idx [ 37]: Upr nib 165, 10100101, card 4: Lwr nib  37, 00100101, card 3
   0x43, //Idx [ 38]: Upr nib 166, 10100110, card 4: Lwr nib  38, 00100110, card 3
   0x54, //Idx [ 39]: Upr nib 167, 10100111, card 5: Lwr nib  39, 00100111, card 4
   0x32, //Idx [ 40]: Upr nib 168, 10101000, card 3: Lwr nib  40, 00101000, card 2
   0x43, //Idx [ 41]: Upr nib 169, 10101001, card 4: Lwr nib  41, 00101001, card 3
   0x43, //Idx [ 42]: Upr nib 170, 10101010, card 4: Lwr nib  42, 00101010, card 3
   0x54, //Idx [ 43]: Upr nib 171, 10101011, card 5: Lwr nib  43, 00101011, card 4
   0x43, //Idx [ 44]: Upr nib 172, 10101100, card 4: Lwr nib  44, 00101100, card 3
   0x54, //Idx [ 45]: Upr nib 173, 10101101, card 5: Lwr nib  45, 00101101, card 4
   0x54, //Idx [ 46]: Upr nib 174, 10101110, card 5: Lwr nib  46, 00101110, card 4
   0x65, //Idx [ 47]: Upr nib 175, 10101111, card 6: Lwr nib  47, 00101111, card 5
   0x32, //Idx [ 48]: Upr nib 176, 10110000, card 3: Lwr nib  48, 00110000, card 2
   0x43, //Idx [ 49]: Upr nib 177, 10110001, card 4: Lwr nib  49, 00110001, card 3
   0x43, //Idx [ 50]: Upr nib 178, 10110010, card 4: Lwr nib  50, 00110010, card 3
   0x54, //Idx [ 51]: Upr nib 179, 10110011, card 5: Lwr nib  51, 00110011, card 4
   0x43, //Idx [ 52]: Upr nib 180, 10110100, card 4: Lwr nib  52, 00110100, card 3
   0x54, //Idx [ 53]: Upr nib 181, 10110101, card 5: Lwr nib  53, 00110101, card 4
   0x54, //Idx [ 54]: Upr nib 182, 10110110, card 5: Lwr nib  54, 00110110, card 4
   0x65, //Idx [ 55]: Upr nib 183, 10110111, card 6: Lwr nib  55, 00110111, card 5
   0x43, //Idx [ 56]: Upr nib 184, 10111000, card 4: Lwr nib  56, 00111000, card 3
   0x54, //Idx [ 57]: Upr nib 185, 10111001, card 5: Lwr nib  57, 00111001, card 4
   0x54, //Idx [ 58]: Upr nib 186, 10111010, card 5: Lwr nib  58, 00111010, card 4
   0x65, //Idx [ 59]: Upr nib 187, 10111011, card 6: Lwr nib  59, 00111011, card 5
   0x54, //Idx [ 60]: Upr nib 188, 10111100, card 5: Lwr nib  60, 00111100, card 4
   0x65, //Idx [ 61]: Upr nib 189, 10111101, card 6: Lwr nib  61, 00111101, card 5
   0x65, //Idx [ 62]: Upr nib 190, 10111110, card 6: Lwr nib  62, 00111110, card 5
   0x76, //Idx [ 63]: Upr nib 191, 10111111, card 7: Lwr nib  63, 00111111, card 6
   0x21, //Idx [ 64]: Upr nib 192, 11000000, card 2: Lwr nib  64, 01000000, card 1
   0x32, //Idx [ 65]: Upr nib 193, 11000001, card 3: Lwr nib  65, 01000001, card 2
   0x32, //Idx [ 66]: Upr nib 194, 11000010, card 3: Lwr nib  66, 01000010, card 2
   0x43, //Idx [ 67]: Upr nib 195, 11000011, card 4: Lwr nib  67, 01000011, card 3
   0x32, //Idx [ 68]: Upr nib 196, 11000100, card 3: Lwr nib  68, 01000100, card 2
   0x43, //Idx [ 69]: Upr nib 197, 11000101, card 4: Lwr nib  69, 01000101, card 3
   0x43, //Idx [ 70]: Upr nib 198, 11000110, card 4: Lwr nib  70, 01000110, card 3
   0x54, //Idx [ 71]: Upr nib 199, 11000111, card 5: Lwr nib  71, 01000111, card 4
   0x32, //Idx [ 72]: Upr nib 200, 11001000, card 3: Lwr nib  72, 01001000, card 2
   0x43, //Idx [ 73]: Upr nib 201, 11001001, card 4: Lwr nib  73, 01001001, card 3
   0x43, //Idx [ 74]: Upr nib 202, 11001010, card 4: Lwr nib  74, 01001010, card 3
   0x54, //Idx [ 75]: Upr nib 203, 11001011, card 5: Lwr nib  75, 01001011, card 4
   0x43, //Idx [ 76]: Upr nib 204, 11001100, card 4: Lwr nib  76, 01001100, card 3
   0x54, //Idx [ 77]: Upr nib 205, 11001101, card 5: Lwr nib  77, 01001101, card 4
   0x54, //Idx [ 78]: Upr nib 206, 11001110, card 5: Lwr nib  78, 01001110, card 4
   0x65, //Idx [ 79]: Upr nib 207, 11001111, card 6: Lwr nib  79, 01001111, card 5
   0x32, //Idx [ 80]: Upr nib 208, 11010000, card 3: Lwr nib  80, 01010000, card 2
   0x43, //Idx [ 81]: Upr nib 209, 11010001, card 4: Lwr nib  81, 01010001, card 3
   0x43, //Idx [ 82]: Upr nib 210, 11010010, card 4: Lwr nib  82, 01010010, card 3
   0x54, //Idx [ 83]: Upr nib 211, 11010011, card 5: Lwr nib  83, 01010011, card 4
   0x43, //Idx [ 84]: Upr nib 212, 11010100, card 4: Lwr nib  84, 01010100, card 3
   0x54, //Idx [ 85]: Upr nib 213, 11010101, card 5: Lwr nib  85, 01010101, card 4
   0x54, //Idx [ 86]: Upr nib 214, 11010110, card 5: Lwr nib  86, 01010110, card 4
   0x65, //Idx [ 87]: Upr nib 215, 11010111, card 6: Lwr nib  87, 01010111, card 5
   0x43, //Idx [ 88]: Upr nib 216, 11011000, card 4: Lwr nib  88, 01011000, card 3
   0x54, //Idx [ 89]: Upr nib 217, 11011001, card 5: Lwr nib  89, 01011001, card 4
   0x54, //Idx [ 90]: Upr nib 218, 11011010, card 5: Lwr nib  90, 01011010, card 4
   0x65, //Idx [ 91]: Upr nib 219, 11011011, card 6: Lwr nib  91, 01011011, card 5
   0x54, //Idx [ 92]: Upr nib 220, 11011100, card 5: Lwr nib  92, 01011100, card 4
   0x65, //Idx [ 93]: Upr nib 221, 11011101, card 6: Lwr nib  93, 01011101, card 5
   0x65, //Idx [ 94]: Upr nib 222, 11011110, card 6: Lwr nib  94, 01011110, card 5
   0x76, //Idx [ 95]: Upr nib 223, 11011111, card 7: Lwr nib  95, 01011111, card 6
   0x32, //Idx [ 96]: Upr nib 224, 11100000, card 3: Lwr nib  96, 01100000, card 2
   0x43, //Idx [ 97]: Upr nib 225, 11100001, card 4: Lwr nib  97, 01100001, card 3
   0x43, //Idx [ 98]: Upr nib 226, 11100010, card 4: Lwr nib  98, 01100010, card 3
   0x54, //Idx [ 99]: Upr nib 227, 11100011, card 5: Lwr nib  99, 01100011, card 4
   0x43, //Idx [100]: Upr nib 228, 11100100, card 4: Lwr nib 100, 01100100, card 3
   0x54, //Idx [101]: Upr nib 229, 11100101, card 5: Lwr nib 101, 01100101, card 4
   0x54, //Idx [102]: Upr nib 230, 11100110, card 5: Lwr nib 102, 01100110, card 4
   0x65, //Idx [103]: Upr nib 231, 11100111, card 6: Lwr nib 103, 01100111, card 5
   0x43, //Idx [104]: Upr nib 232, 11101000, card 4: Lwr nib 104, 01101000, card 3
   0x54, //Idx [105]: Upr nib 233, 11101001, card 5: Lwr nib 105, 01101001, card 4
   0x54, //Idx [106]: Upr nib 234, 11101010, card 5: Lwr nib 106, 01101010, card 4
   0x65, //Idx [107]: Upr nib 235, 11101011, card 6: Lwr nib 107, 01101011, card 5
   0x54, //Idx [108]: Upr nib 236, 11101100, card 5: Lwr nib 108, 01101100, card 4
   0x65, //Idx [109]: Upr nib 237, 11101101, card 6: Lwr nib 109, 01101101, card 5
   0x65, //Idx [110]: Upr nib 238, 11101110, card 6: Lwr nib 110, 01101110, card 5
   0x76, //Idx [111]: Upr nib 239, 11101111, card 7: Lwr nib 111, 01101111, card 6
   0x43, //Idx [112]: Upr nib 240, 11110000, card 4: Lwr nib 112, 01110000, card 3
   0x54, //Idx [113]: Upr nib 241, 11110001, card 5: Lwr nib 113, 01110001, card 4
   0x54, //Idx [114]: Upr nib 242, 11110010, card 5: Lwr nib 114, 01110010, card 4
   0x65, //Idx [115]: Upr nib 243, 11110011, card 6: Lwr nib 115, 01110011, card 5
   0x54, //Idx [116]: Upr nib 244, 11110100, card 5: Lwr nib 116, 01110100, card 4
   0x65, //Idx [117]: Upr nib 245, 11110101, card 6: Lwr nib 117, 01110101, card 5
   0x65, //Idx [118]: Upr nib 246, 11110110, card 6: Lwr nib 118, 01110110, card 5
   0x76, //Idx [119]: Upr nib 247, 11110111, card 7: Lwr nib 119, 01110111, card 6
   0x54, //Idx [120]: Upr nib 248, 11111000, card 5: Lwr nib 120, 01111000, card 4
   0x65, //Idx [121]: Upr nib 249, 11111001, card 6: Lwr nib 121, 01111001, card 5
   0x65, //Idx [122]: Upr nib 250, 11111010, card 6: Lwr nib 122, 01111010, card 5
   0x76, //Idx [123]: Upr nib 251, 11111011, card 7: Lwr nib 123, 01111011, card 6
   0x65, //Idx [124]: Upr nib 252, 11111100, card 6: Lwr nib 124, 01111100, card 5
   0x76, //Idx [125]: Upr nib 253, 11111101, card 7: Lwr nib 125, 01111101, card 6
   0x76, //Idx [126]: Upr nib 254, 11111110, card 7: Lwr nib 126, 01111110, card 6
   0x87  //Idx [127]: Upr nib 255, 11111111, card 8: Lwr nib 127, 01111111, card 7
   };


//-------------------------------------------------------------------------------
//End of $Id: btu8bytecardnibplut.c,v 1.3 2010/01/31 02:46:48 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: btu8bytecardnibplut.c,v $
//Revision 1.3  2010/01/31 02:46:48  dashley
//Bit cardinality functions added.
//
//Revision 1.2  2010/01/22 03:42:59  dashley
//Extra line removed.
//
//Revision 1.1  2010/01/22 03:42:28  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

