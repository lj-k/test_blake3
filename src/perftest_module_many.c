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
#include "test_module_many.h"

#ifdef TEST_TIME
    #include <time.h>
#endif // TEST_TIME


size_t num_inputs           = NUM_inputs;
size_t blocks               = NUM_blocks;
const uint32_t key[8]       = { 0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A, 0x510E527F, 0x9B05688C, 0x1F83D9AB,0x5BE0CD19};
uint64_t counter            =0  ;
#if NUM_blocks==1
bool increment_counter      =0  ;
uint8_t flags               = 4;
uint8_t flags_start         =0  ;
uint8_t flags_end           =0  ;
#elif NUM_blocks == 16
bool increment_counter = 1;
uint8_t flags =             0;
uint8_t flags_start        = 1;
uint8_t flags_end       = 2;
#endif

uint8_t out[NUM_inputs *32];



int main()
{
#if NUM_inputs==1
    const uint8_t* const* inputs[NUM_inputs] = { &data[0] };
#elif NUM_inputs==2
    const uint8_t* const* inputs[NUM_inputs] = { &data[0],&data[64 * NUM_blocks * 1] };
#elif NUM_inputs==4
    const uint8_t* const* inputs[NUM_inputs] = { &data[0],&data[64* NUM_blocks*1],&data[64 * NUM_blocks * 2],&data[64 * NUM_blocks * 3] };
#elif NUM_inputs==8
    const uint8_t* const* inputs[NUM_inputs] = { &data[0],&data[64 * NUM_blocks * 1],&data[64 * NUM_blocks * 2],&data[64 * NUM_blocks * 3] ,&data[64 * NUM_blocks * 4] ,&data[64 * NUM_blocks * 5] ,&data[64 * NUM_blocks * 6] ,&data[64 * NUM_blocks * 7] };
#elif NUM_inputs==16
    const uint8_t* const* inputs[NUM_inputs] = { &data[0],&data[64 * NUM_blocks * 1],&data[64 * NUM_blocks * 2],&data[64 * NUM_blocks * 3],&data[64 * NUM_blocks * 4],&data[64 * NUM_blocks * 5],&data[64 * NUM_blocks * 6],&data[64 * NUM_blocks * 7],&data[64 * NUM_blocks * 8],&data[64 * NUM_blocks * 9],&data[64 * NUM_blocks * 10],&data[64 * NUM_blocks * 11],&data[64 * NUM_blocks * 12],&data[64 * NUM_blocks * 13],&data[64 * NUM_blocks * 14],&data[64 * NUM_blocks * 15] };
#endif //NUM_inputs

#if PRINTF_ON
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
#endif //PRINTF_ON
#ifdef TEST_TIME
    clock_t  start, end;
    double timecost;
    start = clock();
    //printf("start %d;", start);
    for (int i = 0; i < TIME_TEST_NUM; i++)
    {
        

#endif //TEST_TIME

        #if TEST_USE_AVX512 ==1
                #if PRIOUT_ON
                        printf("\n blake3_hash_many_avx512\n");
                #endif //PRIOUT_ON

            blake3_hash_many_avx512(inputs, num_inputs, blocks, key, counter,
                increment_counter, flags, flags_start, flags_end,
                out);
        #elif TEST_USE_NEON==1
            #if PRIOUT_ON
                    printf("\n blake3_hash_many_portable\n");
                #endif //PRIOUT_ON

            blake3_hash_many_neon(inputs, num_inputs, blocks, key, counter,
                increment_counter, flags, flags_start, flags_end,
                out);
        #elif TEST_USE_RVV==1
        #else
                #if PRIOUT_ON
                    printf("\n blake3_hash_many_portable\n");
                #endif //PRIOUT_ON

            blake3_hash_many_portable(inputs, num_inputs, blocks, key, counter,
                increment_counter, flags, flags_start, flags_end,
                out);
        #endif

#ifdef TEST_TIME
    }
    end = clock();
    //printf("end %d;", end);
    
    timecost= (end - start);
    printf("M %d%d: run %d times: cost %f total(%d ~ %d) %f ns per;\n", NUM_inputs, NUM_blocks, TIME_TEST_NUM, timecost,start,end, timecost/ TIME_TEST_NUM*1000);
#endif //TEST_TIME
#if PRIOUT_ON
    printf("\n### output out: [0~%d]\n",NUM_inputs*32);
  for (int i = 0; i < NUM_inputs*32; i++)
  {
      printf("%02X,", out[i]);
      if ((i + 1) % 32 == 0) { printf("\n"); }
  }
#endif //PRIOUT_ON
    return 0;
}

