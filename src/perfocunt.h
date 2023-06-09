#ifndef PERFCOUNT
#define PERFCOUNT
#include <stdint.h>
#include <math.h>


int count_blake3_compress_in_place		;
int count_blake3_compress_in_place_blocklen[17];
int count_blake3_compress_in_place_flags[7];


int count_blake3_compress_xof			;
int count_blake3_hash_many				;
int count_blake3_hash_many_situation[17][17]	;	// input4, block1




void count_print();
void count_clear();

void count_incer_blake3_compress_in_place(int block_len, uint8_t flags);
void count_incer_blake3_compress_xof	();
void count_incer_blake3_hash_many		(int num_inputs, int blocks);



void caculate_print(int inputByteNum);
#endif /* PERFCOUNT */
