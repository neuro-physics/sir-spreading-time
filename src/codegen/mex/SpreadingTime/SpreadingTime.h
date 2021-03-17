/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SpreadingTime.h
 *
 * Code generation for function 'SpreadingTime'
 *
 */

#ifndef SPREADINGTIME_H
#define SPREADINGTIME_H

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
#include "SpreadingTime_types.h"

/* Function Declarations */
extern void SpreadingTime(const emlrtStack *sp, const emxArray_real_T *A, real_T
  Theta, real_T nSim, real_T tTotal, emxArray_real_T *T, emxArray_real_T *V,
  emxArray_real_T *S);

#endif

/* End of code generation (SpreadingTime.h) */
