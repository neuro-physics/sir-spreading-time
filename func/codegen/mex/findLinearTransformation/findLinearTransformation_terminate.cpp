/*
 * findLinearTransformation_terminate.cpp
 *
 * Code generation for function 'findLinearTransformation_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "findLinearTransformation.h"
#include "findLinearTransformation_terminate.h"
#include "_coder_findLinearTransformation_mex.h"
#include "findLinearTransformation_data.h"
#include "blas.h"
#include "lapacke.h"

/* Function Definitions */
void findLinearTransformation_atexit()
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void findLinearTransformation_terminate()
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (findLinearTransformation_terminate.cpp) */
