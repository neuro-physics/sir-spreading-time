/*
 * getNiiParcelCoord_terminate.cpp
 *
 * Code generation for function 'getNiiParcelCoord_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "getNiiParcelCoord.h"
#include "getNiiParcelCoord_terminate.h"
#include "_coder_getNiiParcelCoord_mex.h"
#include "getNiiParcelCoord_data.h"

/* Function Definitions */
void getNiiParcelCoord_atexit()
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void getNiiParcelCoord_terminate()
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (getNiiParcelCoord_terminate.cpp) */
