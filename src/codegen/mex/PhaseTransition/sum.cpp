/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.cpp
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "PhaseTransition.h"
#include "sum.h"
#include "PhaseTransition_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "PhaseTransition_data.h"

/* Variable Definitions */
static emlrtRSInfo wc_emlrtRSI = { 145,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 106,/* lineNo */
  13,                                  /* colNo */
  "combineVectorElements",             /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 9,/* lineNo */
  1,                                   /* colNo */
  "sum",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = { 48,/* lineNo */
  9,                                   /* colNo */
  "sumprod",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pName */
};

/* Function Definitions */
void sum(const emlrtStack *sp, const emxArray_boolean_T *x, emxArray_real_T *y)
{
  boolean_T overflow;
  boolean_T p;
  int32_T vlen;
  int32_T xpageoffset;
  uint32_T sz[2];
  int32_T i;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  if (((x->size[0] == 1) && (x->size[1] == 1)) || (x->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2012b(&st, &ic_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  overflow = false;
  p = false;
  if ((x->size[0] != 0) || (x->size[1] != 0)) {
  } else {
    p = true;
  }

  if (p) {
    overflow = true;
  }

  if (overflow) {
    emlrtErrorWithMessageIdR2012b(&st, &nc_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  b_st.site = &sc_emlrtRSI;
  vlen = x->size[0];
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    for (xpageoffset = 0; xpageoffset < 2; xpageoffset++) {
      sz[xpageoffset] = (uint32_T)x->size[xpageoffset];
    }

    xpageoffset = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int32_T)sz[1];
    emxEnsureCapacity_real_T(&b_st, y, xpageoffset, &hb_emlrtRTEI);
    i = (int32_T)sz[1];
    for (xpageoffset = 0; xpageoffset < i; xpageoffset++) {
      y->data[xpageoffset] = 0.0;
    }
  } else {
    c_st.site = &tc_emlrtRSI;
    xpageoffset = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = x->size[1];
    emxEnsureCapacity_real_T(&c_st, y, xpageoffset, &gb_emlrtRTEI);
    d_st.site = &wc_emlrtRSI;
    overflow = (x->size[1] > 2147483646);
    if (overflow) {
      e_st.site = &gb_emlrtRSI;
      f_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }

    for (i = 0; i + 1 <= x->size[1]; i++) {
      xpageoffset = i * x->size[0];
      y->data[i] = x->data[xpageoffset];
      d_st.site = &uc_emlrtRSI;
      if ((!(2 > vlen)) && (vlen > 2147483646)) {
        e_st.site = &gb_emlrtRSI;
        f_st.site = &gb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (k = 2; k <= vlen; k++) {
        y->data[i] += (real_T)x->data[(xpageoffset + k) - 1];
      }
    }
  }
}

/* End of code generation (sum.cpp) */
