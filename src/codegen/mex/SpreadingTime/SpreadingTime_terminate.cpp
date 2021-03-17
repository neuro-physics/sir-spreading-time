/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SpreadingTime_terminate.cpp
 *
 * Code generation for function 'SpreadingTime_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "SpreadingTime.h"
#include "SpreadingTime_terminate.h"
#include "_coder_SpreadingTime_mex.h"
#include "SpreadingTime_data.h"

/* Function Definitions */
void SpreadingTime_atexit()
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void SpreadingTime_terminate()
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (SpreadingTime_terminate.cpp) */
