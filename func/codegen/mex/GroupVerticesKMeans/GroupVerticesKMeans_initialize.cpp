/*
 * GroupVerticesKMeans_initialize.cpp
 *
 * Code generation for function 'GroupVerticesKMeans_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "GroupVerticesKMeans.h"
#include "GroupVerticesKMeans_initialize.h"
#include "_coder_GroupVerticesKMeans_mex.h"
#include "GroupVerticesKMeans_data.h"

/* Function Definitions */
void GroupVerticesKMeans_initialize()
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, "Statistics_Toolbox", 2);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (GroupVerticesKMeans_initialize.cpp) */
