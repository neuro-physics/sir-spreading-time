/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * GetSimulationParam.h
 *
 * Code generation for function 'GetSimulationParam'
 *
 */

#ifndef GETSIMULATIONPARAM_H
#define GETSIMULATIONPARAM_H

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
extern void GetSimulationParam(const emlrtStack *sp, const emxArray_real_T *A,
  real_T nSeeds, real_T isCompetitive, const emxArray_char_T *seedType, const
  emxArray_real_T *seedInd, real_T nSim, real_T *p_N, real_T *p_nSeeds, real_T
  *p_isCompetitive, emxArray_real_T *p_seeds, real_T *p_nSim, emxArray_char_T
  *p_seedType, real_T *p_seedTrial, emxArray_real_T *p_x0);

#endif

/* End of code generation (GetSimulationParam.h) */
