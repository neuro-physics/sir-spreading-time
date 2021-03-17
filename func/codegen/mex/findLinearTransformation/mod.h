/*
 * mod.h
 *
 * Code generation for function 'mod'
 *
 */

#ifndef MOD_H
#define MOD_H

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
#include "findLinearTransformation_types.h"

/* Function Declarations */
extern void b_mod(const emlrtStack *sp, const emxArray_real_T *x, real_T y,
                  emxArray_real_T *r);

#endif

/* End of code generation (mod.h) */
