#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#include <stdint.h>

#define F (1 << 14)

// 정수 => 고정 소수점(FP)
#define INT_TO_FP(n) ((n) * (F))

// 고정 소수점 => 정수(버림: Round toward zero)
#define FP_TO_INT_RZ(x) ((x) / (F))

// 고정 소수점 => 정수(반올림: Round to nearest)
#define FP_TO_INT_RN(x) ((x) >= 0 ? ((x) + (F) / 2) / (F) : ((x) - (F) / 2) / (F))

#define ADD_FP(x, y) ((x) + (y))
#define SUB_FP(x, y) ((x) - (y))
#define ADD_FP_INT(x, n) ((x) + (n) * (F))
#define SUB_FP_INT(x, n) ((x) - (n) * (F))

#define MUL_FP(x, y) ((int) (((int64_t) (x)) * (y) / (F)))
#define MUL_FP_INT(x, n) ((x) * (n))
#define DIV_FP(x, y) ((int) (((int64_t) (x)) * (F) / (y)))
#define DIV_FP_INT(x, n) ((x) / (n))

#endif 