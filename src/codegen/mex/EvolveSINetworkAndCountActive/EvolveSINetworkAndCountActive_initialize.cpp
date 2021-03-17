/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvolveSINetworkAndCountActive_initialize.cpp
 *
 * Code generation for function 'EvolveSINetworkAndCountActive_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EvolveSINetworkAndCountActive.h"
#include "EvolveSINetworkAndCountActive_initialize.h"
#include "_coder_EvolveSINetworkAndCountActive_mex.h"
#include "EvolveSINetworkAndCountActive_data.h"

/* Function Definitions */
void EvolveSINetworkAndCountActive_initialize()
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (EvolveSINetworkAndCountActive_initialize.cpp) */
