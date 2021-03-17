/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * GetSimulationParam.cpp
 *
 * Code generation for function 'GetSimulationParam'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "TwoSeedsSpreading.h"
#include "GetSimulationParam.h"
#include "error.h"
#include "fillUpMatrix.h"
#include "TwoSeedsSpreading_data.h"

/* Variable Definitions */
static emlrtRSInfo lb_emlrtRSI = { 52, /* lineNo */
  "GetSimulationParam",                /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 61, /* lineNo */
  "GetSimulationParam",                /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pathName */
};

/* Function Definitions */
void GetSimulationParam(const emlrtStack *sp, const emxArray_real_T *A, real_T
  isCompetitive, const emxArray_real_T *seedInd, real_T nSim, real_T *p_N,
  real_T *p_nSeeds, real_T *p_isCompetitive, emxArray_real_T *p_seeds, real_T
  *p_nSim, char_T p_seedType[5], real_T *p_seedTrial, real_T p_x0[2])
{
  int32_T b_p_N;
  int32_T i2;
  static const char_T seedType[5] = { 'f', 'i', 'x', 'e', 'd' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;

  /*  A -> adj matrix */
  /*  nSeeds -> amount of initial seeds for activity (must be equal to the GetNodes nSeeds */
  /*  isCompetitive -> determines whether the seeds are competitive (diff states) or cooperative (eq states) */
  /*  seedType -> 'random': randomly select seeds */
  /*              'fixed': select fixed seedInd for every trial + a quantity of (nSeeds-numel(seedInd)) seeds in 1:size(A,1); */
  /*              'mostconn': selects the nSeeds most connected nodes as seeds */
  /*  seedInd -> double(1:nSim,1:nSeeds) index of 'fixed' seeds */
  /*             if there is less rows than nSim, the remaining rows are a periodic repetition of seedInd(:,:) */
  /*             if there is less columns than nSeeds, the remaining cols are going to be filled up with random seeds */
  /*  nSim -> number seed trials */
  /*  */
  /*  return: */
  /*  p struct with fields: */
  /*  .N -> network total number of elements */
  /*  .nSeeds -> same as input */
  /*  .isCompetitive -> same as input */
  /*  .seeds -> double(1:nSim,1:nSeeds); each line is a seed trial */
  /*  .seedTrial -> a counter for sim functions to determine which seed trial (out of .seeds) to take */
  /*  .nSim -> number of seed trials */
  /*  .seedType -> same as input */
  /*  .x0 -> double(1,1:nSeeds); initial condition for each of the seed nodes */
  /*  */
  b_p_N = A->size[0];
  for (i2 = 0; i2 < 5; i2++) {
    p_seedType[i2] = seedType[i2];
  }

  st.site = &lb_emlrtRSI;
  fillUpMatrix(&st, seedInd, nSim, (real_T)A->size[0], p_seeds);
  st.site = &mb_emlrtRSI;
  if (muDoubleScalarIsNaN(isCompetitive)) {
    b_st.site = &ub_emlrtRSI;
    c_st.site = &ub_emlrtRSI;
    b_error(&c_st);
  }

  if (isCompetitive != 0.0) {
    for (i2 = 0; i2 < 2; i2++) {
      p_x0[i2] = 1.0 + (real_T)i2;
    }
  } else {
    for (i2 = 0; i2 < 2; i2++) {
      p_x0[i2] = 1.0;
    }
  }

  *p_N = b_p_N;
  *p_nSeeds = 2.0;
  *p_isCompetitive = isCompetitive;
  *p_nSim = nSim;
  *p_seedTrial = 1.0;
}

/* End of code generation (GetSimulationParam.cpp) */
