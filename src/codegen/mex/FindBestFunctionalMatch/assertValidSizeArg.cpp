/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * assertValidSizeArg.cpp
 *
 * Code generation for function 'assertValidSizeArg'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindBestFunctionalMatch.h"
#include "assertValidSizeArg.h"

/* Variable Definitions */
static emlrtRTEInfo fd_emlrtRTEI = { 53,/* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtRTEInfo gd_emlrtRTEI = { 59,/* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

/* Function Definitions */
void assertValidSizeArg(const emlrtStack *sp, real_T varargin_2)
{
  boolean_T p;
  real_T b_varargin_2;
  if ((varargin_2 != varargin_2) || muDoubleScalarIsInf(varargin_2)) {
    p = false;
  } else {
    p = true;
  }

  if (p && (!(2.147483647E+9 < varargin_2))) {
    p = true;
  } else {
    p = false;
  }

  if (!p) {
    emlrtErrorWithMessageIdR2012b(sp, &fd_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }

  if (varargin_2 <= 0.0) {
    b_varargin_2 = 0.0;
  } else {
    b_varargin_2 = varargin_2;
  }

  if (!(2.147483647E+9 >= b_varargin_2)) {
    emlrtErrorWithMessageIdR2012b(sp, &gd_emlrtRTEI, "Coder:MATLAB:pmaxsize", 0);
  }
}

/* End of code generation (assertValidSizeArg.cpp) */
