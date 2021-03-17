/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * NetworkActivationTime_mexutil.cpp
 *
 * Code generation for function 'NetworkActivationTime_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "NetworkActivationTime.h"
#include "NetworkActivationTime_mexutil.h"

/* Function Definitions */
void d_error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

/* End of code generation (NetworkActivationTime_mexutil.cpp) */
