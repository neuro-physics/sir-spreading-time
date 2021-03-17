/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvolveSINetworkAndCountActive_emxutil.h
 *
 * Code generation for function 'EvolveSINetworkAndCountActive_emxutil'
 *
 */

#ifndef EVOLVESINETWORKANDCOUNTACTIVE_EMXUTIL_H
#define EVOLVESINETWORKANDCOUNTACTIVE_EMXUTIL_H

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
#include "EvolveSINetworkAndCountActive_types.h"

/* Function Declarations */
extern void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
extern void emxEnsureCapacity_struct0_T(const emlrtStack *sp, emxArray_struct0_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
extern void emxFree_struct0_T(emxArray_struct0_T **pEmxArray);
extern void emxInit_struct0_T(const emlrtStack *sp, emxArray_struct0_T
  **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
  doPush);

#endif

/* End of code generation (EvolveSINetworkAndCountActive_emxutil.h) */
