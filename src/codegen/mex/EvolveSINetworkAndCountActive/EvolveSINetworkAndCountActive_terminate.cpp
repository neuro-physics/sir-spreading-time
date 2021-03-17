/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvolveSINetworkAndCountActive_terminate.cpp
 *
 * Code generation for function 'EvolveSINetworkAndCountActive_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EvolveSINetworkAndCountActive.h"
#include "EvolveSINetworkAndCountActive_terminate.h"
#include "_coder_EvolveSINetworkAndCountActive_mex.h"
#include "EvolveSINetworkAndCountActive_data.h"

/* Function Definitions */
void EvolveSINetworkAndCountActive_atexit()
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

void EvolveSINetworkAndCountActive_terminate()
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (EvolveSINetworkAndCountActive_terminate.cpp) */
