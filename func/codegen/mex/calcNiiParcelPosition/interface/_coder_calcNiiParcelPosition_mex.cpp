/*
 * _coder_calcNiiParcelPosition_mex.cpp
 *
 * Code generation for function '_coder_calcNiiParcelPosition_mex'
 *
 */

/* Include files */
#include "_coder_calcNiiParcelPosition_mex.h"
#include "_coder_calcNiiParcelPosition_api.h"
#include "calcNiiParcelPosition.h"
#include "calcNiiParcelPosition_data.h"
#include "calcNiiParcelPosition_initialize.h"
#include "calcNiiParcelPosition_terminate.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void c_calcNiiParcelPosition_mexFunc(int32_T nlhs, mxArray
  *plhs[1], int32_T nrhs, const mxArray *prhs[1]);

/* Function Definitions */
void c_calcNiiParcelPosition_mexFunc(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs, const mxArray *prhs[1])
{
  const mxArray *outputs[1];

  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 1, 4, 21, "calcNiiParcelPosition");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 21,
                        "calcNiiParcelPosition");
  }

  /* Call the function. */
  calcNiiParcelPosition_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(calcNiiParcelPosition_atexit);

  /* Module initialization. */
  calcNiiParcelPosition_initialize();

  /* Dispatch the entry-point. */
  c_calcNiiParcelPosition_mexFunc(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  calcNiiParcelPosition_terminate();
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_calcNiiParcelPosition_mex.cpp) */
