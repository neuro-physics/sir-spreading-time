/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rand.cpp
 *
 * Code generation for function 'rand'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "PhaseTransition.h"
#include "rand.h"
#include "PhaseTransition_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo ib_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "rand",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\rand.m"/* pName */
};

static emlrtDCInfo h_emlrtDCI = { 100, /* lineNo */
  34,                                  /* colNo */
  "rand",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\rand.m",/* pName */
  4                                    /* checkKind */
};

/* Function Definitions */
real_T b_rand()
{
  real_T r;
  emlrtRandu(&r, 1);
  return r;
}

void c_rand(const emlrtStack *sp, real_T varargin_1, real_T varargin_2,
            emxArray_real_T *r)
{
  int32_T i8;
  i8 = r->size[0] * r->size[1];
  r->size[0] = (int32_T)varargin_1;
  if (!(varargin_2 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_2, (emlrtDCInfo *)&h_emlrtDCI, sp);
  }

  r->size[1] = (int32_T)varargin_2;
  emxEnsureCapacity_real_T(sp, r, i8, &ib_emlrtRTEI);
  if (!((r->size[0] == 0) || (r->size[1] == 0))) {
    emlrtRandu(&r->data[0], r->size[0] * r->size[1]);
  }
}

/* End of code generation (rand.cpp) */
