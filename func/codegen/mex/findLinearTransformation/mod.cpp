/*
 * mod.cpp
 *
 * Code generation for function 'mod'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "findLinearTransformation.h"
#include "mod.h"
#include "findLinearTransformation_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "scalexpAlloc.h"
#include "findLinearTransformation_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo dc_emlrtRSI = { 42, "mod",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elfun\\mod.m" };

static emlrtRSInfo ec_emlrtRSI = { 72, "mod",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elfun\\mod.m" };

static emlrtRSInfo fc_emlrtRSI = { 73, "applyScalarFunction",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"
};

static emlrtRSInfo gc_emlrtRSI = { 146, "applyScalarFunction",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 16, 9, "scalexpAlloc",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m"
};

static emlrtRTEInfo i_emlrtRTEI = { 1, 10, "scalexpAlloc",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m"
};

static emlrtRTEInfo v_emlrtRTEI = { 17, 19, "scalexpAlloc",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m"
};

/* Function Definitions */
void b_mod(const emlrtStack *sp, const emxArray_real_T *x, real_T y,
           emxArray_real_T *r)
{
  emxArray_real_T *z;
  int32_T k;
  boolean_T overflow;
  real_T b_r;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &z, 2, &i_emlrtRTEI, true);
  st.site = &dc_emlrtRSI;
  k = z->size[0] * z->size[1];
  z->size[0] = 1;
  z->size[1] = x->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)z, k, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  if (dimagree(z, x)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &v_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  emxFree_real_T(&z);
  st.site = &ec_emlrtRSI;
  b_st.site = &fc_emlrtRSI;
  k = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = x->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)r, k, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  if (dimagree(r, x)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &v_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  b_st.site = &gc_emlrtRSI;
  overflow = ((!(1 > x->size[1])) && (x->size[1] > 2147483646));
  if (overflow) {
    c_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k + 1 <= x->size[1]; k++) {
    if (y == 0.0) {
      b_r = x->data[k];
    } else if (y == muDoubleScalarFloor(y)) {
      b_r = x->data[k] - muDoubleScalarFloor(x->data[k] / y) * y;
    } else {
      b_r = x->data[k] / y;
      if (muDoubleScalarAbs(b_r - muDoubleScalarRound(b_r)) <=
          2.2204460492503131E-16 * muDoubleScalarAbs(b_r)) {
        b_r = 0.0;
      } else {
        b_r = (b_r - muDoubleScalarFloor(b_r)) * y;
      }
    }

    r->data[k] = b_r;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (mod.cpp) */
