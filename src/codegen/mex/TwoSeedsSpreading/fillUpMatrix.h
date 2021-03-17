/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fillUpMatrix.h
 *
 * Code generation for function 'fillUpMatrix'
 *
 */

#ifndef FILLUPMATRIX_H
#define FILLUPMATRIX_H

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
#include "TwoSeedsSpreading_types.h"

/* Function Declarations */
extern void fillUpMatrix(const emlrtStack *sp, const emxArray_real_T *A, real_T
  m, real_T N, emxArray_real_T *M);

#endif

/* End of code generation (fillUpMatrix.h) */
