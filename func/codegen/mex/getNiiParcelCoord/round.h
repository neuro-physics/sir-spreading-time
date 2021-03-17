/*
 * round.h
 *
 * Code generation for function 'round'
 *
 */

#ifndef ROUND_H
#define ROUND_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "getNiiParcelCoord_types.h"

/* Function Declarations */
extern void b_round(const emlrtStack *sp, emxArray_real32_T *x);
extern void c_round(real32_T x[2]);

#endif

/* End of code generation (round.h) */
