//----------------------------------------------------------------------------------------------------
//emts_heap_alloc_test
//----------------------------------------------------------------------------------------------------
//Quick program to determine whether fully buffering file contents in RAM
//is generally viable for text tools on PCs.  The target for testing is 2
//gigabytes of allocated heap.
//----------------------------------------------------------------------------------------------------
//Copyright 2020 David T. Ashley
//
//Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
//associated documentation files (the "Software"), to deal in the Software without restriction,
//including without limitation the rights to use, copy, modify, merge, publish, distribute,
//sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//   -The above copyright notice and this permission notice shall be included in all copies or
//    substantial portions of the Software.
//   -THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//    BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//    NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//    DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//----------------------------------------------------------------------------------------------------
#define EMTS_HEAP_ALLOC_BLKSIZE    (1000)
   //Believed to be fairly representative of a chunk of memory that might be
   //allocated.
#define EMTS_HEAP_ALLOC_NBLKS   (2000000)
   //This many blocks, each of 1000 bytes, is about 2 gigabytes.

#define EMTS_BLK_TRAVERSER         (1783)
   //This is a prime number.  Using this to add to the index within a block
   //should generate a reasonable pseudo-random access sequence.
#define EMTS_BLK_NUM_TRAVERSER  (3802949)
   //This is a prime number.  Same idea for block number.

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *(ptrblk[2000000]);

//Advance the block traverser in a psuedo-random fashion.
static void advance_block_traverser(unsigned *arg)
{
   *arg = *arg + EMTS_BLK_TRAVERSER;
   *arg = *arg % EMTS_HEAP_ALLOC_BLKSIZE;
}

//Advance the block number traverser in a psuedo-random fashion.
static void advance_block_number_traverser(unsigned* arg)
{
   *arg = *arg + EMTS_BLK_NUM_TRAVERSER;
   *arg = *arg % EMTS_HEAP_ALLOC_NBLKS;
}

int main()
{
   unsigned uidx;
   unsigned repctr;
   unsigned blkidx;
   unsigned charidx;

   printf("Execution begins.\n");
   printf("Allocating blocks.\n");
   for (uidx = 0; uidx < EMTS_HEAP_ALLOC_NBLKS; uidx++)
   {
      ptrblk[uidx] = (char *)malloc(EMTS_HEAP_ALLOC_BLKSIZE);
      if (!ptrblk[uidx])
      {
         printf("Allocating failed.\n");
         exit(0);
      }

      if ((uidx % 100000) == 0)
         printf("   Allocated block %u.\n", uidx);
   }
   printf("Block allocation complete.\n");

   printf("Allocating block of pointers ... ");

   printf("Block zeroing all blocks.\n");
   for (uidx = 0; uidx < EMTS_HEAP_ALLOC_NBLKS; uidx++)
   {
      memset(ptrblk[uidx], 0, EMTS_HEAP_ALLOC_BLKSIZE);
      if ((uidx % 100000) == 0)
         printf("   Block zeroed block %u.\n", uidx);
   }
   printf("Block zeroing complete.\n");

   blkidx = 0;
   charidx = 0;
   printf("Beginning linear assignment test.\n");
   for (repctr = 0; repctr < 2; repctr++)
   {
      printf("   Iteration %u\n", repctr);
      for (uidx = 0; uidx < (EMTS_HEAP_ALLOC_NBLKS * EMTS_HEAP_ALLOC_BLKSIZE); uidx++)
      {
         blkidx = uidx % EMTS_HEAP_ALLOC_NBLKS;
         charidx = charidx % EMTS_HEAP_ALLOC_BLKSIZE;
         ptrblk[blkidx][charidx] = (blkidx + charidx) & 0xff;
      }
   }
   printf("Linear assignment test complete.\n");

   blkidx = 0;
   charidx = 0;
   printf("Beginning pseudo-random assignment test.\n");
   for (repctr = 0; repctr < 2; repctr++)
   {
      printf("   Iteration %u\n", repctr);
      for (uidx = 0; uidx < (EMTS_HEAP_ALLOC_NBLKS * EMTS_HEAP_ALLOC_BLKSIZE); uidx++)
      {
         advance_block_number_traverser(&blkidx);
         advance_block_traverser(&charidx);
         //printf("      Block index: %u  Char index: %u.\n", blkidx, charidx);
         ptrblk[blkidx][charidx] = (~(blkidx + charidx)) & 0xff;
      }
   }
   printf("Pseudo-random assignment test complete.\n");

   return 0;
}