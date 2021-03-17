/*
 * _coder_GroupVerticesKMeans_mex.cpp
 *
 * Code generation for function '_coder_GroupVerticesKMeans_mex'
 *
 */

/* Include files */
#include "GroupVerticesKMeans.h"
#include "_coder_GroupVerticesKMeans_mex.h"
#include "GroupVerticesKMeans_terminate.h"
#include "_coder_GroupVerticesKMeans_api.h"
#include "GroupVerticesKMeans_initialize.h"
#include "GroupVerticesKMeans_data.h"

/* Function Declarations */
static void GroupVerticesKMeans_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[2]);

/* Function Definitions */
static void GroupVerticesKMeans_mexFunction(int32_T nlhs, mxArray *plhs[1],
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
                        19, "GroupVerticesKMeans");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 19,
                        "GroupVerticesKMeans");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  GroupVerticesKMeans_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  GroupVerticesKMeans_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(GroupVerticesKMeans_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  GroupVerticesKMeans_initialize();

  /* Dispatch the entry-point. */
  GroupVerticesKMeans_mexFunction(nlhs, plhs, nrhs, prhs);
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_GroupVerticesKMeans_mex.cpp) */
