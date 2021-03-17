/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_TwoSeedsSpreading_mex.cpp
 *
 * Code generation for function '_coder_TwoSeedsSpreading_mex'
 *
 */

/* Include files */
#include "TwoSeedsSpreading.h"
#include "_coder_TwoSeedsSpreading_mex.h"
#include "TwoSeedsSpreading_terminate.h"
#include "_coder_TwoSeedsSpreading_api.h"
#include "TwoSeedsSpreading_initialize.h"
#include "TwoSeedsSpreading_data.h"

/* Function Declarations */
static void TwoSeedsSpreading_mexFunction(int32_T nlhs, mxArray *plhs[8],
  int32_T nrhs, const mxArray *prhs[4]);

/* Function Definitions */
static void TwoSeedsSpreading_mexFunction(int32_T nlhs, mxArray *plhs[8],
  int32_T nrhs, const mxArray *prhs[4])
{
  int32_T n;
  const mxArray *inputs[4];
  const mxArray *outputs[8];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        17, "TwoSeedsSpreading");
  }

  if (nlhs > 8) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "TwoSeedsSpreading");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  TwoSeedsSpreading_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  TwoSeedsSpreading_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(TwoSeedsSpreading_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  TwoSeedsSpreading_initialize();

  /* Dispatch the entry-point. */
  TwoSeedsSpreading_mexFunction(nlhs, plhs, nrhs, prhs);
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_TwoSeedsSpreading_mex.cpp) */
