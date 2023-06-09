#include "perfocunt.h"
#include <stdio.h>
#include <stdint.h>

void count_print()
{
	//printf("blake3_compress_in_place\t=\t%d\n", count_blake3_compress_in_place);
	//printf("count_blake3_compress_xof\t=\t%d\n", count_blake3_compress_xof);
	//printf("count_blake3_hash_many\t=\t%d\n", count_blake3_hash_many);

	//printf("\t%d;\t%d;\t%d;", count_blake3_compress_in_place,count_blake3_compress_xof,count_blake3_hash_many);
	int hashmany_situation_check=0;
	
	printf("%3d;%4d;", count_blake3_compress_in_place,count_blake3_hash_many);
	printf("\t");// hash many numbers
	//printf("%4d;\%4d;", count_blake3_hash_many_situation[1][1], count_blake3_hash_many_situation[1][16]);
	printf("%4d;%4d;", count_blake3_hash_many_situation[2][1], count_blake3_hash_many_situation[2][16]);
	printf("%4d;%4d;", count_blake3_hash_many_situation[4][1], count_blake3_hash_many_situation[4][16]);
	printf("%4d;%4d;", count_blake3_hash_many_situation[8][1], count_blake3_hash_many_situation[8][16]);
	printf("%4d;%4d;", count_blake3_hash_many_situation[16][1], count_blake3_hash_many_situation[16][16]);
	printf("\t");	//compress inplace numbers
	for (int i = 0; i < 7; i++)	{		
		printf("%2d;",count_blake3_compress_in_place_flags[i]);	}

	//CHECK HASH MANY NUMBER
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			hashmany_situation_check+=count_blake3_hash_many_situation[i][j] ;
		}
	}
	if (hashmany_situation_check != count_blake3_hash_many) { printf("ERROR! HASH MANY"); }
}

void count_clear()
{
	count_blake3_compress_in_place = 0;
	count_blake3_compress_xof = 0;
	count_blake3_hash_many = 0;

	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			count_blake3_hash_many_situation[i][j] = 0;
		}
	}
	for (int i = 0; i < 7; i++)
	{
		count_blake3_compress_in_place_flags[i] =0;
	}

}

void count_incer_blake3_compress_in_place(int block_len, uint8_t flags)
{
	//block_len=1~64

	count_blake3_compress_in_place++;

	for (int i = 0; i < 7; i++)
	{
		count_blake3_compress_in_place_flags[i] += (flags >> i) & 1;
	}


}

void count_incer_blake3_compress_xof()
{
	count_blake3_compress_xof++;
}

void count_incer_blake3_hash_many(int num_inputs, int blocks)
{
	count_blake3_hash_many++;
	count_blake3_hash_many_situation[num_inputs][blocks]++;
}

void caculate_print(int inputByteNum)
{
	int calculate_blake3_compress_in_place=0;
	int calculate_blake3_hash_many		  =0;

	//inputByteNum/1024


	printf("\t%d;\t%d;", calculate_blake3_compress_in_place, calculate_blake3_hash_many);

}