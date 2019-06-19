
// =====================================================================
//
//	Exported by Cearn's excellut v1.0
//	(comments, kudos, flames to daytshen@hotmail.com)
//
// =====================================================================
#include <stdint.h>
#include <stdio.h>

#ifndef TRIG_LUT_H
#define TRIG_LUT_H

#define FIX_14_SHIFT 14
#define FIX_14_MULT(a,b) ((a * b) >> FIX_14_SHIFT)
#define FIX_14_DIV(a,b)  ((a << FIX_14_SHIFT) / b)

// === LUT SIZES ===
#define SIN_SIZE 512
#define DEGREES 360

// === LUT DECLARATIONS ===
extern const signed short SIN[SIN_SIZE];

typedef struct vector_t {
    int32_t x, y;
} vector_t;

// === LUT FUNCTIONS ===
int32_t sin_lut(int32_t i);
int32_t cos_lut(int32_t i);
void initVector(vector_t* v, int32_t x, int32_t y);
void rotateVector(vector_t* v, int32_t i);

#endif	// SIN_LUT_H
