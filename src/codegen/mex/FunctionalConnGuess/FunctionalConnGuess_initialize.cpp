/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FunctionalConnGuess_initialize.cpp
 *
 * Code generation for function 'FunctionalConnGuess_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FunctionalConnGuess.h"
#include "FunctionalConnGuess_initialize.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "eml_rand_shr3cong_stateful.h"
#include "eml_rand_mcg16807_stateful.h"
#include "eml_rand.h"
#include "_coder_FunctionalConnGuess_mex.h"
#include "FunctionalConnGuess_data.h"

/* Function Declarations */
static void FunctionalConnGuess_once();

/* Function Definitions */
static void FunctionalConnGuess_once()
{
  c_state_not_empty_init();
  b_state_not_empty_init();
  state_not_empty_init();
  method_not_empty_init();
  eml_rand_init();
  eml_rand_mcg16807_stateful_init();
  eml_rand_shr3cong_stateful_init();
  c_eml_rand_mt19937ar_stateful_i();
}

void FunctionalConnGuess_initialize()
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    FunctionalConnGuess_once();
  }
}

/* End of code generation (FunctionalConnGuess_initialize.cpp) */
