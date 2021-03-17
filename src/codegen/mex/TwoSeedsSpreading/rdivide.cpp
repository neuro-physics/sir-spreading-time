/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rdivide.cpp
 *
 * Code generation for function 'rdivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "TwoSeedsSpreading.h"
#include "rdivide.h"
#include "TwoSeedsSpreading_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo ic_emlrtRTEI = { 26,/* lineNo */
  1,                                   /* colNo */
  "rdivide",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m"/* pName */
};

/* Function Definitions */
void rdivide(const emlrtStack *sp, const emxArray_real_T *x, real_T y,
             emxArray_real_T *z)
{
  int32_T i22;
  int32_T loop_ub;
  i22 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity_real_T1(sp, z, i22, &ic_emlrtRTEI);
  loop_ub = x->size[0];
  for (i22 = 0; i22 < loop_ub; i22++) {
    z->data[i22] = x->data[i22] / y;
  }
}

/* End of code generation (rdivide.cpp) */
