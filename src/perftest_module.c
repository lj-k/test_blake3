/*
 * @Author: Kong Lingjun 
 * @Date: 2023-06-12 14:43:32 
 * @Last Modified by: Kong Lingjun
 * @Last Modified time: 2023-06-12 14:49:38
 */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "blake3_impl.h"

#define NUM_inputs 4
#define NUM_blocks 1
#define INPU_FLAGS 4


uint8_t data[256] = {
0x98,0xe1,0x5c,0xf4,0xa7,0x6e,0x5c,0xa6,0x7c,0x48,0x20,0x5d,0xc5,0xdc,0xea,0xb0,
0x9d,0xe9,0x8e,0x4b,0x5d,0x63,0xe8,0xdc,0x9e,0x31,0xde,0xb9,0xbe,0x21,0xbe,0x6c,
0xa7,0x5e,0x6e,0x3f,0x8a,0xce,0xf6,0x3f,0x9f,0x35,0xf8,0x5a,0x1c,0x99,0x41,0x88,
0xaa,0xbe,0x3d,0x87,0x80,0x57,0x26,0x4f,0xeb,0xc5,0xa5,0x14,0x3b,0xda,0x35,0xdb,
0xb0,0x7d,0x1a,0x86,0x92,0x36,0xbb,0x38,0x22,0x1b,0xf2,0x96,0x03,0x0f,0x66,0x76,
0x86,0xa8,0xf5,0xdd,0x64,0xe0,0x44,0x61,0x36,0x95,0x2f,0xf7,0xf9,0x32,0x2b,0x18,
0x04,0xa9,0x8b,0xfe,0x12,0x47,0x52,0x31,0x67,0xa0,0x73,0xb4,0x46,0x9c,0xd3,0xdd,
0x33,0xf9,0x27,0x31,0x2d,0x90,0x5a,0xaa,0x2d,0xfd,0xcf,0xd9,0x76,0xb8,0x18,0x7e,
0x1e,0x92,0xb6,0x7e,0xa8,0x35,0x5a,0xf2,0xe3,0x6d,0xdd,0x12,0x83,0xa8,0x6d,0x11,
0xd0,0x61,0x34,0x5b,0xd1,0x4d,0x23,0x75,0x03,0x45,0xa0,0xa9,0x89,0x26,0xde,0xfb,
0x79,0x04,0x89,0x08,0x10,0x26,0xa7,0x2c,0x02,0x4d,0x2e,0x87,0xbf,0x89,0x35,0x6f,
0x70,0xfd,0x32,0x84,0x24,0x50,0x0f,0x31,0x8e,0x8d,0x67,0x18,0x25,0x9b,0x6b,0x1f,
0x16,0x6b,0x8c,0xd4,0x70,0x0d,0x0c,0xac,0x2f,0xd1,0x17,0x34,0xec,0x98,0xfc,0x1d,
0xd0,0x7b,0x1c,0xf7,0x46,0x71,0x5b,0x16,0x38,0x42,0x10,0xa1,0x99,0xa5,0x37,0x04,
0x97,0xed,0x22,0x04,0x6a,0xd8,0x85,0x29,0x41,0xc2,0xc9,0xc8,0xdf,0xb0,0xef,0xe4,
0x20,0xdf,0x64,0xaa,0x9c,0x8e,0xe1,0x35,0x01,0x0d,0x91,0xcf,0x46,0x3a,0xb8,0xb8,

};


size_t num_inputs           = NUM_inputs;
size_t blocks               = NUM_blocks;
const uint32_t key[8]       = { 0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A, 0x510E527F, 0x9B05688C, 0x1F83D9AB,0x5BE0CD19};
uint64_t counter            =0  ;
bool increment_counter      =0  ;
uint8_t flags               = INPU_FLAGS;
uint8_t flags_start         =0  ;
uint8_t flags_end           =0  ;
uint8_t out[128];



int main()
{
    const uint8_t* const* inputs[4] = { &data[0],&data[64],&data[128],&data[192] };

    

    uint8_t* message = inputs[0];

    printf("\n## blake3_hash_many  (M%d%d):\n", (int)num_inputs, (int)blocks);

    printf("\tsize_t num_inputs=%llu, \n\tsize_t blocks=%llu,\n\tuint64_t counter=%llu \n", num_inputs, blocks, counter);
    printf("\tbool increment_counter=%d, \n\tuint8_t flags=%x,\n\tuint8_t flags_start=%x,\n\tuint8_t flags_end=%x \n", increment_counter, flags, flags_start, flags_end);


    printf("\n### input message: [0~%d]\n", 64 * (int)blocks * (int)num_inputs - 1);
    int j = 0;
    int chunknum = 1;
    int newlinecount = 0;
    printf("\n####  Parallel %d\n", chunknum);

    //for (int i = 0; i < BLAKE3_CHUNK_LEN * num_inputs; i++)
    for (int i = 0; i < blocks * num_inputs * 64; i++)
    {
        printf("%02x,", message[i]);
        j++;
        if (j == 64 * blocks) {
            j = 0;
            chunknum++;
            if (i < blocks * num_inputs * 64 - 1) {
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
    for (int i = 0; i < 7; i++) {
        printf(" % 02X,", key[i]);
    }
    printf("\n");
    
  blake3_hash_many_portable(inputs, num_inputs, blocks, key, counter,
                           increment_counter, flags, flags_start, flags_end,
                           out);
  
  for (int i = 0; i < NUM_inputs*32; i++)
  {
      printf("%02X,", out[i]);
      if ((i + 1) % 32 == 0) { printf("\n"); }
  }

    return 0;
}

