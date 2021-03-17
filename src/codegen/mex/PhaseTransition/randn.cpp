/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * randn.cpp
 *
 * Code generation for function 'randn'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "PhaseTransition.h"
#include "randn.h"
#include "PhaseTransition_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo kb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "randn",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randn.m"/* pName */
};

/* Function Definitions */
void randn(const emlrtStack *sp, const real_T varargin_1[2], emxArray_real_T *r)
{
  int32_T i9;
  i9 = r->size[0] * r->size[1];
  r->size[0] = (int32_T)varargin_1[0];
  r->size[1] = 1;
  emxEnsureCapacity_real_T(sp, r, i9, &kb_emlrtRTEI);
  if (!(r->size[0] == 0)) {
    emlrtRandn(&r->data[0], r->size[0]);
  }
}

/* End of code generation (randn.cpp) */
