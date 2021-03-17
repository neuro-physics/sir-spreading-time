/*
 * calcNodesDistance_terminate.cpp
 *
 * Code generation for function 'calcNodesDistance_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calcNodesDistance.h"
#include "calcNodesDistance_terminate.h"
#include "_coder_calcNodesDistance_mex.h"
#include "calcNodesDistance_data.h"
#include "blas.h"

/* Function Definitions */
void calcNodesDistance_atexit()
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void calcNodesDistance_terminate()
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (calcNodesDistance_terminate.cpp) */
