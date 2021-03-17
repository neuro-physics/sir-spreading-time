/*
 * findLinearTransformation_initialize.cpp
 *
 * Code generation for function 'findLinearTransformation_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "findLinearTransformation.h"
#include "findLinearTransformation_initialize.h"
#include "_coder_findLinearTransformation_mex.h"
#include "findLinearTransformation_data.h"
#include "blas.h"
#include "lapacke.h"

/* Function Definitions */
void findLinearTransformation_initialize()
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (findLinearTransformation_initialize.cpp) */
