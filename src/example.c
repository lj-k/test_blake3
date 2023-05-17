#include "blake3.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h> 
#include <io.h>
#include <process.h>

#define TEST_BLAKE3_INPUT_LEN 1
int main(void) {
  // Initialize the hasher.
  blake3_hasher hasher;
  blake3_hasher_init(&hasher);

  unsigned char buf[TEST_BLAKE3_INPUT_LEN+1];
  int j = 0;
  for (int i = 0; i < TEST_BLAKE3_INPUT_LEN+1; i++)
  {
      buf[i] = j++;
      if (j > 250)
      {
          j = 0;
      }
  }


    blake3_hasher_update(&hasher, buf, TEST_BLAKE3_INPUT_LEN);

  // Finalize the hash. BLAKE3_OUT_LEN is the default output length, 32 bytes.
  uint8_t output[BLAKE3_OUT_LEN];
  blake3_hasher_finalize(&hasher, output, BLAKE3_OUT_LEN);

  // Print the hash as hexadecimal.
  for (size_t i = 0; i < BLAKE3_OUT_LEN; i++) {
    printf("%02x", output[i]);
  }
  printf("\n");
  return 0;
}
