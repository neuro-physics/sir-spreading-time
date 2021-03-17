/*
 * qrsolve.h
 *
 * Code generation for function 'qrsolve'
 *
 */

#ifndef QRSOLVE_H
#define QRSOLVE_H

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
extern void LSQFromQR(const emlrtStack *sp, const emxArray_real_T *A, const
                      emxArray_real_T *tau, const emxArray_int32_T *jpvt,
                      emxArray_real_T *B, int32_T rankA, emxArray_real_T *Y);
extern int32_T rankFromQR(const emlrtStack *sp, const emxArray_real_T *A);

#endif

/* End of code generation (qrsolve.h) */
