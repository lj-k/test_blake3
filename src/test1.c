#include "blake3.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h> 
#include <io.h>
#include <process.h>
#include <time.h>

#define TEST_BLAKE3_INPUT_LEN 2048
#define TEST_BLAKE3_OOOUT_LEN 32



int main(void) {
  // Initialize the hasher.
  blake3_hasher hasher;
  unsigned char buf[TEST_BLAKE3_INPUT_LEN+1];
  uint8_t output[TEST_BLAKE3_OOOUT_LEN];

  //input message
  int j = 0;
  for (int i = 0; i < TEST_BLAKE3_INPUT_LEN + 1; i++)
  {
      buf[i] = j++;
      if (j > 250)
      {
          j = 0;
      }
  }

  printf("Data print! \nsimd = % u, \nTEST_BLAKE3_INPUT_LEN = % d \n", blake3_simd_degree(), TEST_BLAKE3_INPUT_LEN);

      blake3_hasher_init(&hasher);
      blake3_hasher_update(&hasher, buf, TEST_BLAKE3_INPUT_LEN);
      blake3_hasher_finalize(&hasher, output, TEST_BLAKE3_OOOUT_LEN);



  // Print the hash as hexadecimal.
      for (size_t i = 0; i < TEST_BLAKE3_OOOUT_LEN; i++) {
        printf("%02x", output[i]);
      }
      printf("\n");
      return 0;
}
