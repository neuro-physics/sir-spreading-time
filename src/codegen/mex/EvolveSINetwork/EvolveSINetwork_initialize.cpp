/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvolveSINetwork_initialize.cpp
 *
 * Code generation for function 'EvolveSINetwork_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EvolveSINetwork.h"
#include "EvolveSINetwork_initialize.h"
#include "_coder_EvolveSINetwork_mex.h"
#include "EvolveSINetwork_data.h"

/* Function Definitions */
void EvolveSINetwork_initialize()
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

/* End of code generation (EvolveSINetwork_initialize.cpp) */
