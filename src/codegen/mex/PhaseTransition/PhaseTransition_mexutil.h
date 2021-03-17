/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * PhaseTransition_mexutil.h
 *
 * Code generation for function 'PhaseTransition_mexutil'
 *
 */

#ifndef PHASETRANSITION_MEXUTIL_H
#define PHASETRANSITION_MEXUTIL_H

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
extern real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
extern real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *mu, const
  char_T *identifier);
extern void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);
extern real_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

#endif

/* End of code generation (PhaseTransition_mexutil.h) */
