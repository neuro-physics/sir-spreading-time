/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvolveSINetwork_terminate.cpp
 *
 * Code generation for function 'EvolveSINetwork_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EvolveSINetwork.h"
#include "EvolveSINetwork_terminate.h"
#include "_coder_EvolveSINetwork_mex.h"
#include "EvolveSINetwork_data.h"

/* Function Definitions */
void EvolveSINetwork_atexit()
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

void EvolveSINetwork_terminate()
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (EvolveSINetwork_terminate.cpp) */
