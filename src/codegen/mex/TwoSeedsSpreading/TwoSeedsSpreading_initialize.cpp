/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * TwoSeedsSpreading_initialize.cpp
 *
 * Code generation for function 'TwoSeedsSpreading_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "TwoSeedsSpreading.h"
#include "TwoSeedsSpreading_initialize.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "eml_rand_shr3cong_stateful.h"
#include "eml_rand_mcg16807_stateful.h"
#include "eml_rand.h"
#include "_coder_TwoSeedsSpreading_mex.h"
#include "TwoSeedsSpreading_data.h"

/* Function Declarations */
static void TwoSeedsSpreading_once();

/* Function Definitions */
static void TwoSeedsSpreading_once()
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

void TwoSeedsSpreading_initialize()
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
    TwoSeedsSpreading_once();
  }
}

/* End of code generation (TwoSeedsSpreading_initialize.cpp) */
