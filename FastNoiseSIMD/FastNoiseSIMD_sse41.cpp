#include "FastNoiseSIMD.h"

#if defined(__clang__) && defined(FN_COMPILE_SSE41)

#ifndef __SSE4_1__
#error To compile SSE4.1 add "-msse4.1" to FastNoiseSIMD_sse41 build parameters
#endif

#define SIMD_LEVEL FN_SSE41
#define SIMD_LEVEL_H FN_SSE41
#include <smmintrin.h>
#include "FastNoiseSIMD_internal.h"
#include "FastNoiseSIMD_internal.cpp"
#endif