/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_NetworkActivationTime_mex.cpp
 *
 * Code generation for function '_coder_NetworkActivationTime_mex'
 *
 */

/* Include files */
#include "NetworkActivationTime.h"
#include "_coder_NetworkActivationTime_mex.h"
#include "NetworkActivationTime_terminate.h"
#include "_coder_NetworkActivationTime_api.h"
#include "NetworkActivationTime_initialize.h"
#include "NetworkActivationTime_data.h"

/* Function Declarations */
static void c_NetworkActivationTime_mexFunc(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[7]);

/* Function Definitions */
static void c_NetworkActivationTime_mexFunc(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[7])
{
  int32_T n;
  const mxArray *inputs[7];
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        21, "NetworkActivationTime");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 21,
                        "NetworkActivationTime");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  NetworkActivationTime_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  NetworkActivationTime_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(NetworkActivationTime_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  NetworkActivationTime_initialize();

  /* Dispatch the entry-point. */
  c_NetworkActivationTime_mexFunc(nlhs, plhs, nrhs, prhs);
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_NetworkActivationTime_mex.cpp) */
