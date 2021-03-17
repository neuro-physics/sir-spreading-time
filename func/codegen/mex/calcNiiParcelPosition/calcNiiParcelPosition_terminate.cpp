/*
 * calcNiiParcelPosition_terminate.cpp
 *
 * Code generation for function 'calcNiiParcelPosition_terminate'
 *
 */

/* Include files */
#include "calcNiiParcelPosition_terminate.h"
#include "_coder_calcNiiParcelPosition_mex.h"
#include "calcNiiParcelPosition.h"
#include "calcNiiParcelPosition_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void calcNiiParcelPosition_atexit()
{
  mexFunctionCreateRootTLS();
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void calcNiiParcelPosition_terminate()
{
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (calcNiiParcelPosition_terminate.cpp) */
