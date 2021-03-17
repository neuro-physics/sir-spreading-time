/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_setop.cpp
 *
 * Code generation for function 'eml_setop'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "TwoSeedsSpreading.h"
#include "eml_setop.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo tb_emlrtRSI = { 228,/* lineNo */
  "eml_setop",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pathName */
};

/* Function Definitions */
void do_vectors(const emlrtStack *sp, const real_T b[2], int32_T c_size[2],
                int32_T ia_size[1], int32_T ib_size[1])
{
  boolean_T y;
  boolean_T p;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_size[0] = 1;
  c_size[1] = 0;
  ia_size[0] = 0;
  ib_size[0] = 0;
  y = true;
  if ((b[0] <= b[1]) || muDoubleScalarIsNaN(b[1])) {
    p = true;
  } else {
    p = false;
  }

  if (!p) {
    y = false;
  }

  if (!y) {
    st.site = &tb_emlrtRSI;
    b_st.site = &tb_emlrtRSI;
    error(&b_st);
  }
}

/* End of code generation (eml_setop.cpp) */
