/*
 * GroupVerticesKMeans_terminate.cpp
 *
 * Code generation for function 'GroupVerticesKMeans_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "GroupVerticesKMeans.h"
#include "GroupVerticesKMeans_terminate.h"
#include "_coder_GroupVerticesKMeans_mex.h"
#include "GroupVerticesKMeans_data.h"

/* Function Definitions */
void GroupVerticesKMeans_atexit()
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void GroupVerticesKMeans_terminate()
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (GroupVerticesKMeans_terminate.cpp) */
