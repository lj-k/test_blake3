#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "blake3_impl.h"

#include <string.h>
#include <io.h>

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
    //printf("BLEN:%d;", block_len);
    count_incer_blake3_compress_in_place(block_len, flags);
  //blake3_compress_in_place_portable(cv, block, block_len, counter, flags);
}

void blake3_compress_xof(const uint32_t cv[8],
                         const uint8_t block[BLAKE3_BLOCK_LEN],
                         uint8_t block_len, uint64_t counter, uint8_t flags,
                         uint8_t out[64]) {
    count_incer_blake3_compress_xof();
  //blake3_compress_xof_portable(cv, block, block_len, counter, flags, out);
}

void blake3_hash_many(const uint8_t *const *inputs, size_t num_inputs,
                      size_t blocks, const uint32_t key[8], uint64_t counter,
                      bool increment_counter, uint8_t flags,
                      uint8_t flags_start, uint8_t flags_end, uint8_t *out) {

    count_incer_blake3_hash_many(num_inputs, blocks);
   //printf("MANY%d;%llu;%llu;", count_blake3_hash_many, num_inputs, blocks);
  //blake3_hash_many_portable(inputs, num_inputs, blocks, key, counter,
  //                          increment_counter, flags, flags_start, flags_end,
  //                          out);
}

size_t blake3_simd_degree(void) {
    return 1;
}

