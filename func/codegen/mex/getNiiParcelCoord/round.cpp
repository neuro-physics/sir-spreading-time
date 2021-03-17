/*
 * round.cpp
 *
 * Code generation for function 'round'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "getNiiParcelCoord.h"
#include "round.h"
#include "eml_int_forloop_overflow_check.h"
#include "getNiiParcelCoord_data.h"

/* Variable Definitions */
static emlrtRSInfo y_emlrtRSI = { 10, "round",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elfun\\round.m"
};

static emlrtRSInfo ab_emlrtRSI = { 24, "applyScalarFunctionInPlace",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"
};

/* Function Definitions */
void b_round(const emlrtStack *sp, emxArray_real32_T *x)
{
  int32_T nx;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &y_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x->size[0] * x->size[1] * x->size[2];
  b_st.site = &ab_emlrtRSI;
  if ((!(1 > nx)) && (nx > 2147483646)) {
    c_st.site = &s_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k + 1 <= nx; k++) {
    x->data[k] = muSingleScalarRound(x->data[k]);
  }
}

void c_round(real32_T x[2])
{
  int32_T k;
  for (k = 0; k < 2; k++) {
    x[k] = muSingleScalarRound(x[k]);
  }
}

/* End of code generation (round.cpp) */
