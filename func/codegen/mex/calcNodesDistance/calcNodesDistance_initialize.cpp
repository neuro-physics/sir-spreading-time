/*
 * calcNodesDistance_initialize.cpp
 *
 * Code generation for function 'calcNodesDistance_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calcNodesDistance.h"
#include "calcNodesDistance_initialize.h"
#include "_coder_calcNodesDistance_mex.h"
#include "calcNodesDistance_data.h"
#include "blas.h"

/* Function Definitions */
void calcNodesDistance_initialize()
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (calcNodesDistance_initialize.cpp) */
