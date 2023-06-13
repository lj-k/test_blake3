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


#define TEST_INPLACE 0
#define TEST_XOF     1

#define PRINTF_ON 0// printf input 
#define PRIOUT_ON 0//printf output

#define TEST_TIME
#define TIME_TEST_NUM 1000000000

/********************** configure above **************/
#ifdef TEST_TIME
    #include <time.h>
#endif // TEST_TIME

uint32_t cv[8] = { 0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A, 0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19};
uint8_t block_len = 64;
uint64_t counter = 0;

#if TEST_INPLACE==1
    uint8_t flags = 4;
    uint8_t block[BLAKE3_BLOCK_LEN] = {

    0x5c, 0x9e, 0x65, 0x44, 0x11, 0xe3, 0x93, 0xd1, 0xf4, 0xbe, 0xc7, 0x10, 0xcc, 0xd5, 0xbc, 0x56,
    0x69, 0xab, 0x17, 0x7d, 0x61, 0x0a, 0x0e, 0xb6, 0x91, 0xfc, 0xfe, 0xe9, 0x2f, 0xb4, 0xe8, 0xb1,
    0x5b, 0x1f, 0x23, 0xb8, 0x39, 0x03, 0x68, 0xa2, 0xc1, 0x50, 0x95, 0x91, 0x03, 0x89, 0xd1, 0xb7,
    0x16, 0xeb, 0x52, 0xa6, 0xdf, 0xd3, 0x4d, 0x0a, 0xa6, 0x6a, 0x22, 0xa2, 0x1b, 0x76, 0x1c, 0xa7,
    };
#elif TEST_XOF==1 
    uint8_t flags = 12;
    uint8_t xof_out[64];

    uint8_t block[BLAKE3_BLOCK_LEN] = {
        0x81, 0x1f, 0x7d, 0x4f, 0x17, 0x35, 0x25, 0x8e, 0x27, 0xc6, 0x8b, 0x92, 0x14, 0xff, 0x7c, 0x4a,
        0xac, 0x86, 0x6d, 0x47, 0xf7, 0x3d, 0xee, 0xf1, 0xfd, 0x89, 0x08, 0xb5, 0xe3, 0x8f, 0x80, 0x4f,
        0x1a, 0xd5, 0xf7, 0x80, 0xa5, 0xe3, 0x1e, 0x5a, 0xe4, 0x58, 0x4c, 0x8e, 0xa2, 0x3e, 0x6e, 0x25,
        0x6e, 0xda, 0x8d, 0x14, 0xd4, 0xab, 0xa6, 0x9c, 0x53, 0x50, 0xc4, 0xec, 0x54, 0xbe, 0x7f, 0x0a,
    };
#endif // TEST_INPLACE vs TEST_XOF

int main()
{
#if PRINTF_ON
    //printf("\n## blake3_compress_in_place: \n");
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
#endif //PRINTF_ON
#ifdef TEST_TIME
    clock_t  start, end;
    double timecost;
    start = clock();
    //printf("start %d;", start);
    for (int i = 0; i < TIME_TEST_NUM; i++)
    {
        

#endif //TEST_TIME

    #if TEST_INPLACE==1

            blake3_compress_in_place_portable(cv,block,block_len, counter,flags);
    #elif TEST_XOF==1 

            blake3_compress_xof_portable(cv,block,block_len,counter,flags, xof_out);
    #endif // TEST_INPLACE vs TEST_XOF

#ifdef TEST_TIME
    }
    end = clock();
    //printf("end %d;", end);
    
    timecost= (end - start);
        #if TEST_INPLACE==1
            printf("TEST_INPLACE: run %d times: cost %f total %f ns per;\n", TIME_TEST_NUM, timecost, timecost / TIME_TEST_NUM * 1000);
        #elif TEST_XOF==1 
            printf("TEST_XOF: run %d times: cost %f total %f ns per;\n", TIME_TEST_NUM, timecost,timecost/ TIME_TEST_NUM*1000);
        #endif // TEST_INPLACE vs TEST_XOF
#endif //TEST_TIME
#if PRIOUT_ON
    #if TEST_INPLACE==1
        printf("### output uint32_t cv: [0~7]\n");
        for (int i = 0; i < 8; i++) {
            printf(" % X,", cv[i]);
        }
        printf("\n");
        
    #elif TEST_XOF==1 

        printf("\n### uint8_t out: [0~63]\n");
        int j = 0;
        for (int i = 0; i < 64; i++) {
            printf(" % 02X,", xof_out[i]);
            j++;
            if (j == BLAKE3_OUT_LEN) {
                j = 0;
                printf("\n");

            }
        }
        printf("\n");
    #endif // TEST_INPLACE vs TEST_XOF
    
#endif //PRIOUT_ON
    return 0;
}

