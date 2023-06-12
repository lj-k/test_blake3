#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "blake3_impl.h"

#include <string.h>
#include <stdio.h>

#include "perfocunt.h"

#if defined(IS_X86)
#if defined(_MSC_VER)
#include <intrin.h>
#elif defined(__GNUC__)
#include <immintrin.h>
#else
#undef IS_X86 /* Unimplemented! */
#endif
#endif

#define MAYBE_UNUSED(x) (void)((x))

void blake3_compress_in_place(uint32_t cv[8],
                              const uint8_t block[BLAKE3_BLOCK_LEN],
                              uint8_t block_len, uint64_t counter,
                              uint8_t flags) {
     count_incer_blake3_compress_in_place( block_len,  flags);

    printf("\n## blake3_compress_in_place %d: \n", count_blake3_compress_in_place);
    printf("\tuint8_t block_len=%u, \n\tuint64_t counter=%llu,\n\tuint8_t flags=%u \n", block_len, counter, flags);

    printf("### input uint32_t cv: [0~7]\n");
    for (int i = 0; i < 8; i++) {
        printf(" % X,", cv[i]);
    }
    printf("\n");


    printf("\n### input uint8_t block: [0~%d]\n", BLAKE3_BLOCK_LEN - 1);
    int newlinecount = 0;
    for (int i = 0; i < BLAKE3_BLOCK_LEN; i++)
    {
        printf("%02x,", block[i]);
        newlinecount++;
        if (newlinecount == 16) {
            newlinecount = 0;
            printf("\n");
        }
    }
    printf("\n");

  blake3_compress_in_place_portable(cv, block, block_len, counter, flags);

  printf("### output uint32_t cv: [0~7]\n");
  for (int i = 0; i < 8; i++) {
      printf(" % X,", cv[i]);
  }
  printf("\n");

  printf("\n");
}

void blake3_compress_xof(const uint32_t cv[8],
                         const uint8_t block[BLAKE3_BLOCK_LEN],
                         uint8_t block_len, uint64_t counter, uint8_t flags,
                         uint8_t out[64]) {

    printf("\n## blake3_compress_xof: \n");
    printf("\tuint8_t block_len=%u, \n\tuint64_t counter=%llu,\n\tuint8_t flags=%u \n", block_len, counter, flags);
    
    printf("### input uint32_t cv: [0~7]\n");
    for (int i = 0; i < 8; i++) {
        printf(" % X,", cv[i]);
    }
    printf("\n");


    printf("\n### input uint8_t block: [0~%d]\n", BLAKE3_BLOCK_LEN - 1);
    int newlinecount = 0;
    for (int i = 0; i < BLAKE3_BLOCK_LEN; i++)
    {
        printf("%02x,", block[i]);
        newlinecount++;
        if (newlinecount == 16) {
            newlinecount = 0;
            printf("\n");
        }
    }
    printf("\n");


    


  blake3_compress_xof_portable(cv, block, block_len, counter, flags, out);

  printf("\n### uint8_t out: [0~63]\n");
  int j = 0;
  for (int i = 0; i < 64; i++) {
      printf(" % 02X,", out[i]);
      j++;
      if (j == BLAKE3_OUT_LEN) {
          j = 0;
          printf("\n");

      }
  }
  printf("\n");

}

void blake3_hash_many(const uint8_t *const *inputs, size_t num_inputs,
                      size_t blocks, const uint32_t key[8], uint64_t counter,
                      bool increment_counter, uint8_t flags,
                      uint8_t flags_start, uint8_t flags_end, uint8_t *out) {

    uint8_t* message = inputs[0];
     count_incer_blake3_hash_many((int)num_inputs, (int)blocks);

    printf("\n## blake3_hash_many %d (M%d%d):\n", (int)count_blake3_hash_many, (int)num_inputs, (int)blocks);

    printf("\tsize_t num_inputs=%llu, \n\tsize_t blocks=%llu,\n\tuint64_t counter=%llu \n", num_inputs, blocks, counter);
    printf("\tbool increment_counter=%d, \n\tuint8_t flags=%x,\n\tuint8_t flags_start=%x,\n\tuint8_t flags_end=%x \n", increment_counter, flags, flags_start, flags_end);


    printf("\n### input message: [0~%d]\n", 64*(int)blocks * (int)num_inputs - 1);
    int j=0;
    int chunknum = 1;
    int newlinecount = 0;
    printf("\n####  Parallel %d\n", chunknum);

    //for (int i = 0; i < BLAKE3_CHUNK_LEN * num_inputs; i++)
    for (int i = 0; i < blocks * num_inputs*64; i++)
    {
        printf("%02x,", message[i]);
        j++;
        if (j == 64* blocks) {
            j = 0;
            chunknum++;
            if (i < blocks * num_inputs * 64-1) {
                printf("\n\n#### Parallel %d", chunknum);
            }

        }
        newlinecount++;
        if (newlinecount == 16) {
            newlinecount = 0;
            printf("\n");
        }

    }

    printf("\n### input key: [0~7]\n");
    for (int i = 0; i < 8; i++) {
        printf(" % 02X,", key[i]);
    }
    printf("\n");

  blake3_hash_many_portable(inputs, num_inputs, blocks, key, counter,
                            increment_counter, flags, flags_start, flags_end,
                            out);


  printf("\n### out: [0~%d]\n",BLAKE3_OUT_LEN *(int) num_inputs-1);
  j = 0;
  for (int i = 0; i < BLAKE3_OUT_LEN* num_inputs; i++) {
      printf(" % 02X,", out[i]);
      j++;
      if (j == BLAKE3_OUT_LEN) {
          j = 0;
          printf("\n");

      }
  }
  printf("\n\n\n");
  
}

size_t blake3_simd_degree(void) {
    return 16;
}

