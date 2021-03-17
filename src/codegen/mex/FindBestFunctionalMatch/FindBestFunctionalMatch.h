/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FindBestFunctionalMatch.h
 *
 * Code generation for function 'FindBestFunctionalMatch'
 *
 */

#ifndef FINDBESTFUNCTIONALMATCH_H
#define FINDBESTFUNCTIONALMATCH_H

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
#include "FindBestFunctionalMatch_types.h"

/* Function Declarations */
extern void FindBestFunctionalMatch(const emlrtStack *sp, const emxArray_real_T *
  As, const emxArray_real_T *Af, real_T Theta, const emxArray_real_T
  *nSeedsRange, real_T nSim, real_T tTotal, const emxArray_char_T
  *comparisonMethod, emxArray_real_T *F, emxArray_real_T *R, emxArray_real_T *P);

#endif

/* End of code generation (FindBestFunctionalMatch.h) */
