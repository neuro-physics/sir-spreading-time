/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * PhaseTransition.h
 *
 * Code generation for function 'PhaseTransition'
 *
 */

#ifndef PHASETRANSITION_H
#define PHASETRANSITION_H

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
#include "PhaseTransition_types.h"

/* Function Declarations */
extern void PhaseTransition(const emlrtStack *sp, const emxArray_real_T *A,
  const emxArray_real_T *ThetaRange, real_T nSim, real_T tTotal, const
  emxArray_real_T *x0, const emxArray_char_T *icType, boolean_T
  useWeightSampling, emxArray_real_T *nAct, emxArray_real_T *nAct2,
  emxArray_real_T *stimIndex, emxArray_real_T *nActVec);

#endif

/* End of code generation (PhaseTransition.h) */
