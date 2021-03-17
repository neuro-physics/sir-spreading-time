/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * TwoSeedsSpreading.h
 *
 * Code generation for function 'TwoSeedsSpreading'
 *
 */

#ifndef TWOSEEDSSPREADING_H
#define TWOSEEDSSPREADING_H

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
extern void TwoSeedsSpreading(const emlrtStack *sp, const emxArray_real_T *A,
  real_T Theta, real_T tTotal, real_T isCompetitive, emxArray_real_T *Cp1,
  emxArray_real_T *Cp2, emxArray_real_T *H, emxArray_real_T *Cf, emxArray_real_T
  *T, emxArray_real_T *Tn, emxArray_real_T *S, emxArray_real_T *Sn);

#endif

/* End of code generation (TwoSeedsSpreading.h) */
