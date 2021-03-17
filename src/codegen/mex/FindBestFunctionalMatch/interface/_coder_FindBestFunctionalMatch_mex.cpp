/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_FindBestFunctionalMatch_mex.cpp
 *
 * Code generation for function '_coder_FindBestFunctionalMatch_mex'
 *
 */

/* Include files */
#include "FindBestFunctionalMatch.h"
#include "_coder_FindBestFunctionalMatch_mex.h"
#include "FindBestFunctionalMatch_terminate.h"
#include "_coder_FindBestFunctionalMatch_api.h"
#include "FindBestFunctionalMatch_initialize.h"
#include "FindBestFunctionalMatch_data.h"

/* Function Declarations */
static void c_FindBestFunctionalMatch_mexFu(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[7]);

/* Function Definitions */
static void c_FindBestFunctionalMatch_mexFu(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[7])
{
  int32_T n;
  const mxArray *inputs[7];
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        23, "FindBestFunctionalMatch");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 23,
                        "FindBestFunctionalMatch");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  FindBestFunctionalMatch_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  FindBestFunctionalMatch_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(FindBestFunctionalMatch_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  FindBestFunctionalMatch_initialize();

  /* Dispatch the entry-point. */
  c_FindBestFunctionalMatch_mexFu(nlhs, plhs, nrhs, prhs);
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_FindBestFunctionalMatch_mex.cpp) */
