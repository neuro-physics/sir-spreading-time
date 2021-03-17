/*
 * _coder_findLinearTransformation_mex.cpp
 *
 * Code generation for function '_coder_findLinearTransformation_mex'
 *
 */

/* Include files */
#include "findLinearTransformation.h"
#include "_coder_findLinearTransformation_mex.h"
#include "findLinearTransformation_terminate.h"
#include "_coder_findLinearTransformation_api.h"
#include "findLinearTransformation_initialize.h"
#include "findLinearTransformation_data.h"
#include "blas.h"
#include "lapacke.h"

/* Function Declarations */
static void c_findLinearTransformation_mexF(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[2]);

/* Function Definitions */
static void c_findLinearTransformation_mexF(int32_T nlhs, mxArray *plhs[1],
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
                        24, "findLinearTransformation");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 24,
                        "findLinearTransformation");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  findLinearTransformation_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  findLinearTransformation_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(findLinearTransformation_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  findLinearTransformation_initialize();

  /* Dispatch the entry-point. */
  c_findLinearTransformation_mexF(nlhs, plhs, nrhs, prhs);
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_findLinearTransformation_mex.cpp) */
