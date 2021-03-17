/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * NetworkActivationTime.h
 *
 * Code generation for function 'NetworkActivationTime'
 *
 */

#ifndef NETWORKACTIVATIONTIME_H
#define NETWORKACTIVATIONTIME_H

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
#include "NetworkActivationTime_types.h"

/* Function Declarations */
extern void NetworkActivationTime(const emlrtStack *sp, const emxArray_real_T *A,
  real_T Theta, real_T tTotal, real_T nSeeds, real_T isCompetitive, const
  emxArray_char_T *seedType, const emxArray_real_T *seedInd, emxArray_real_T *T,
  emxArray_real_T *S);

#endif

/* End of code generation (NetworkActivationTime.h) */
