/*
 * colon.cpp
 *
 * Code generation for function 'colon'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "findLinearTransformation.h"
#include "colon.h"
#include "eml_int_forloop_overflow_check.h"
#include "findLinearTransformation_emxutil.h"
#include "findLinearTransformation_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo eb_emlrtRSI = { 151, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo fb_emlrtRSI = { 156, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRTEInfo e_emlrtRTEI = { 146, 14, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

/* Function Definitions */
void eml_signed_integer_colon(const emlrtStack *sp, int32_T b, emxArray_int32_T *
  y)
{
  int32_T n;
  int32_T yk;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &eb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (b < 1) {
    n = 0;
  } else {
    n = b;
  }

  yk = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity(sp, (emxArray__common *)y, yk, (int32_T)sizeof(int32_T),
                    &e_emlrtRTEI);
  if (n > 0) {
    y->data[0] = 1;
    yk = 1;
    st.site = &fb_emlrtRSI;
    if ((!(2 > n)) && (n > 2147483646)) {
      b_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (k = 2; k <= n; k++) {
      yk++;
      y->data[k - 1] = yk;
    }
  }
}

/* End of code generation (colon.cpp) */
