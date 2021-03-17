/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FindBestFunctionalMatch_mexutil.h
 *
 * Code generation for function 'FindBestFunctionalMatch_mexutil'
 *
 */

#ifndef FINDBESTFUNCTIONALMATCH_MEXUTIL_H
#define FINDBESTFUNCTIONALMATCH_MEXUTIL_H

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
extern void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);
extern real_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

#endif

/* End of code generation (FindBestFunctionalMatch_mexutil.h) */
