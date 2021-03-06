/*
 * rdivide.h
 *
 * Code generation for function 'rdivide'
 *
 */

#ifndef RDIVIDE_H
#define RDIVIDE_H

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
extern void rdivide(const emlrtStack *sp, const emxArray_real32_T *x, real32_T y,
                    emxArray_real32_T *z);

#endif

/* End of code generation (rdivide.h) */
