/*
 * _coder_getNiiParcelCoord_mex.cpp
 *
 * Code generation for function '_coder_getNiiParcelCoord_mex'
 *
 */

/* Include files */
#include "getNiiParcelCoord.h"
#include "_coder_getNiiParcelCoord_mex.h"
#include "getNiiParcelCoord_terminate.h"
#include "_coder_getNiiParcelCoord_api.h"
#include "getNiiParcelCoord_initialize.h"
#include "getNiiParcelCoord_data.h"

/* Function Declarations */
static void getNiiParcelCoord_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[2]);

/* Function Definitions */
static void getNiiParcelCoord_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[2])
{
  int32_T n;
  const mxArray *inputs[2];
  const mxArray *outputs[1];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        17, "getNiiParcelCoord");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "getNiiParcelCoord");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  getNiiParcelCoord_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  getNiiParcelCoord_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(getNiiParcelCoord_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  getNiiParcelCoord_initialize();

  /* Dispatch the entry-point. */
  getNiiParcelCoord_mexFunction(nlhs, plhs, nrhs, prhs);
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_getNiiParcelCoord_mex.cpp) */
