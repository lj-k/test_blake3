//#include "arrayprint.h"
#ifndef ARRAYPRINT_H
#define ARRAYPRINT_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define ENABLE_0x   0


void print_vector_uint32_HEX(uint32_t* data, int number,int indent) {
    for (int i =   0; i < indent; i++)
    {
        printf("\t");

    }
    for (int i = 0; i < number; i++)
    {
#if ENABLE_0x
        printf("0x");
#endif // ENABLE_0x

        printf("%08X,", data[i]);
    }
}

void print_matrix_uint8_HEX(uint8_t* data, int number, int indent) {
    int newline = 32;

    for (int i = 0; i < number; i++)
    {
        if ((i ) % newline == 0) {
            for (int j = 0; j < indent; j++)
            {
                printf("\t");

            }
        }
#if ENABLE_0x
        printf("0x");
#endif // ENABLE_0x
        printf("%02X,", data[i]);
        if ((i+1) % newline == 0) { printf("\n"); }
    }
}

void print_matrix_uint32_HEX(uint32_t* data, int number, int indent) {
    int newline = 8;

    for (int i = 0; i < number; i++)
    {
        if ((i) % newline == 0) {
            for (int j = 0; j < indent; j++)
            {
                printf("\t");

            }
        }
#if ENABLE_0x
        printf("0x");
#endif // ENABLE_0x
        printf("%08X,", data[i]);
        if ((i + 1) % newline == 0) { printf("\n"); }
    }
}

///////// print specifically 
//print_xor_state2cv(state, cv);
void print_xor_state2cv(uint32_t state[16], uint32_t cv[8]) {
    printf("#### xor in blake3_compress_in_place_portable:\n");
    printf("\t    state[0~ 7]\t"); print_vector_uint32_HEX(state, 8, 0);   printf("\n");
    printf("\txor state[8~15]\t"); print_vector_uint32_HEX(state+8, 8, 0);   printf("\n");
    printf("\t  =    cv[0~ 7]\t"); print_vector_uint32_HEX(cv, 8, 0);   printf("\n");




}
//print_compress_pre_inputs(cv,block,block_len,counter,flags,block_words,state);
void print_compress_pre_inputs( uint32_t cv[8],
                                const uint8_t block[64],
                                uint8_t block_len, uint64_t counter,
                                uint8_t flags, uint32_t block_words[16], uint32_t state[16]) {
    int indent = 1;
    printf("### inputs in compress_pre:\n");
    printf("\tblock_len: %d,counter:%d,:flags%d\n", block_len, counter, flags);
    printf("#### block[0~63]:\n");  print_matrix_uint8_HEX(block, 64, indent);  printf("\n");
    printf("#### block_words[0~15]:\n");  print_matrix_uint32_HEX(block_words, 16, indent);  printf("\n");
    printf("#### cv[0~7]:\n");      print_vector_uint32_HEX(cv, 8, indent);     printf("\n");
    printf("#### state[0~15]:\n");  print_matrix_uint32_HEX(state, 16, indent);  printf("\n");


}

//print_state16(state, round);
//
// print_state16(state, 0);
// print_state16(state, 1);
// print_state16(state, 2);
// print_state16(state, 3);
// print_state16(state, 4);
// print_state16(state, 5);
// print_state16(state, 6);
void print_state16(uint32_t* state,int round) {
    int indent = 1;

    printf("#### state[0~15] after round%d:\n",round);  print_matrix_uint32_HEX(state, 16, indent);  printf("\n");

}



//;print_compress_inplace(cv,block,block_len,counter,flags);
void print_compress_inplace_inputs(uint32_t cv[8],
    const uint8_t block[64],
    uint8_t block_len, uint64_t counter,
    uint8_t flags) {
    int indent = 1;
    printf("### inputs in compress_inplace:\n");
    printf("\tblock_len: %d,counter:%d,:flags%d\n", block_len, counter, flags);
    printf("#### cv[0~7]:\n");      print_vector_uint32_HEX(cv, 8, indent);     printf("\n");
    printf("#### block[0~63]:\n");  print_matrix_uint8_HEX(block, 64, indent);  printf("\n");

}

void print_compress_inplace_outputs(uint32_t cv[8],
    const uint8_t block[64],
    uint8_t block_len, uint64_t counter,
    uint8_t flags) {
    int indent = 1;
    printf("### outputs in compress_inplace:\n");
    //printf("\tblock_len: %d,counter:%d,:flags%d\n", block_len, counter, flags);
    printf("#### cv[0~7]:\n");      print_vector_uint32_HEX(cv, 8, indent);     printf("\n");
   // printf("#### block[0~63]:\n");  print_matrix_uint8_HEX(block, 64, indent);  printf("\n");

}
#endif //ARRAYPRINT_H
