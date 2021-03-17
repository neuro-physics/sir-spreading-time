/*
 * getNiiParcelCoord_initialize.cpp
 *
 * Code generation for function 'getNiiParcelCoord_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "getNiiParcelCoord.h"
#include "getNiiParcelCoord_initialize.h"
#include "_coder_getNiiParcelCoord_mex.h"
#include "getNiiParcelCoord_data.h"

/* Function Definitions */
void getNiiParcelCoord_initialize()
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (getNiiParcelCoord_initialize.cpp) */
