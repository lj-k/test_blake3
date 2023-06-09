#include "blake3.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h> 
#include <io.h>
#include <process.h>
#include <time.h>

#define TEST_BLAKE3_INPUT_LEN 102401
#define TEST_BLAKE3_OOOUT_LEN 32


void blak3_onetime(blake3_hasher hasher, unsigned char buf[TEST_BLAKE3_INPUT_LEN + 1],uint8_t output[TEST_BLAKE3_OOOUT_LEN])
{
blake3_hasher_init(&hasher);
blake3_hasher_update(&hasher, buf, TEST_BLAKE3_INPUT_LEN);
blake3_hasher_finalize(&hasher, output, TEST_BLAKE3_OOOUT_LEN);
}


int main(void) {
  // Initialize the hasher.
  blake3_hasher hasher;
  unsigned char buf[TEST_BLAKE3_INPUT_LEN+1];
  uint8_t output[TEST_BLAKE3_OOOUT_LEN];


  // time veriables
  clock_t  start, end;
  int t1;
  int t1_times=1000000;

#define  t2_casenum   45
  int t2_times_basic = 1000000;
  float t2[t2_casenum];
  int t2_inputlen[t2_casenum] = {   0,1,2,3,4,    5,6,7,8,63,
                                    64,65,127,128,129,  255,256,257,512,513,
                                    1023,1024,1025,2048,2049 ,
                                    3072,3073,4096,4097,5120,  5121,6144,6145,7168,7169,
                                    8192,8193,16384,16385,31744,  31745,65536,65537,102400,102401 };

  blake3_hasher_init(&hasher);
  //input message
      int j = 0;
      for (int i = 0; i < TEST_BLAKE3_INPUT_LEN+1; i++)
      {
          buf[i] = j++;
          if (j > 250)
          {
              j = 0;
          }
      }

  // prepare for avoid cache effect
      blake3_hasher_init(&hasher);
      blake3_hasher_update(&hasher, buf, TEST_BLAKE3_INPUT_LEN);
      blake3_hasher_finalize(&hasher, output, TEST_BLAKE3_OOOUT_LEN);
  // blake3 performance test
      for (int j = 0; j < t2_casenum; j++)
      {
          start = clock();
          for (int i = 0; i < t1_times; i++)          {
              blake3_hasher_init(&hasher);
              blake3_hasher_update(&hasher, buf, t2_inputlen[j]);
              blake3_hasher_finalize(&hasher, output, TEST_BLAKE3_OOOUT_LEN);
          }

          end = clock();
          t2[j] = (double)(end-start) / CLK_TCK;    // convert to seconds

          printf_s("time\t%05d\t%f\n", t2_inputlen[j], t2[j]);
      }



  // Print the hash as hexadecimal.
      for (size_t i = 0; i < TEST_BLAKE3_OOOUT_LEN; i++) {
        printf("%02x", output[i]);
      }
      printf("\n");
      return 0;
}
