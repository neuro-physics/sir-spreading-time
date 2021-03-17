/*
 * calcNiiParcelPosition_initialize.cpp
 *
 * Code generation for function 'calcNiiParcelPosition_initialize'
 *
 */

/* Include files */
#include "calcNiiParcelPosition_initialize.h"
#include "_coder_calcNiiParcelPosition_mex.h"
#include "calcNiiParcelPosition.h"
#include "calcNiiParcelPosition_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void calcNiiParcelPosition_initialize()
{
  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, false, 0U, 0);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (calcNiiParcelPosition_initialize.cpp) */
