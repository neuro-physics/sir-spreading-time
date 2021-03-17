/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nullAssignment.cpp
 *
 * Code generation for function 'nullAssignment'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "TwoSeedsSpreading.h"
#include "nullAssignment.h"
#include "TwoSeedsSpreading_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "TwoSeedsSpreading_data.h"

/* Variable Definitions */
static emlrtRSInfo db_emlrtRSI = { 21, /* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 25, /* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 273,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 281,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 283,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 286,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 257,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 130,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRTEInfo kc_emlrtRTEI = { 281,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = { 296,/* lineNo */
  5,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = { 25,/* lineNo */
  13,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = { 279,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo od_emlrtRTEI = { 295,/* lineNo */
  1,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo pd_emlrtRTEI = { 79,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

/* Function Definitions */
void nullAssignment(const emlrtStack *sp, emxArray_real_T *x, const
                    emxArray_int32_T *idx)
{
  boolean_T overflow;
  int32_T k;
  boolean_T exitg1;
  int32_T nrowx;
  emxArray_boolean_T *b;
  int32_T nrows;
  int32_T i;
  int32_T loop_ub;
  emxArray_real_T *b_x;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &db_emlrtRSI;
  overflow = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= idx->size[1] - 1)) {
    if ((idx->data[k] < 1) || (idx->data[k] > x->size[0])) {
      overflow = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2012b(&st, &pd_emlrtRTEI,
      "MATLAB:subsdeldimmismatch", 0);
  }

  st.site = &eb_emlrtRSI;
  nrowx = x->size[0];
  if (idx->size[1] == 1) {
    nrows = x->size[0] - 1;
    overflow = ((!(idx->data[0] > nrowx - 1)) && (nrowx - 1 > 2147483646));
    for (loop_ub = 0; loop_ub < 2; loop_ub++) {
      b_st.site = &fb_emlrtRSI;
      if (overflow) {
        c_st.site = &y_emlrtRSI;
        d_st.site = &y_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (i = idx->data[0]; i < nrowx; i++) {
        x->data[(i + x->size[0] * loop_ub) - 1] = x->data[i + x->size[0] *
          loop_ub];
      }
    }
  } else {
    emxInit_boolean_T(&st, &b, 2, &nc_emlrtRTEI, true);
    b_st.site = &gb_emlrtRSI;
    i = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = x->size[0];
    emxEnsureCapacity_boolean_T(&b_st, b, i, &kc_emlrtRTEI);
    loop_ub = x->size[0];
    for (i = 0; i < loop_ub; i++) {
      b->data[i] = false;
    }

    c_st.site = &jb_emlrtRSI;
    overflow = ((!(1 > idx->size[1])) && (idx->size[1] > 2147483646));
    if (overflow) {
      d_st.site = &y_emlrtRSI;
      e_st.site = &y_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 1; k <= idx->size[1]; k++) {
      b->data[idx->data[k - 1] - 1] = true;
    }

    b_st.site = &hb_emlrtRSI;
    nrows = 0;
    c_st.site = &kb_emlrtRSI;
    overflow = ((!(1 > b->size[1])) && (b->size[1] > 2147483646));
    if (overflow) {
      d_st.site = &y_emlrtRSI;
      e_st.site = &y_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 1; k <= b->size[1]; k++) {
      nrows += b->data[k - 1];
    }

    nrows = x->size[0] - nrows;
    i = 0;
    b_st.site = &ib_emlrtRSI;
    overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
    if (overflow) {
      c_st.site = &y_emlrtRSI;
      d_st.site = &y_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 1; k <= nrowx; k++) {
      if ((k > b->size[1]) || (!b->data[k - 1])) {
        for (loop_ub = 0; loop_ub < 2; loop_ub++) {
          x->data[i + x->size[0] * loop_ub] = x->data[(k + x->size[0] * loop_ub)
            - 1];
        }

        i++;
      }
    }

    emxFree_boolean_T(&b);
  }

  if (!(nrows <= nrowx)) {
    emlrtErrorWithMessageIdR2012b(&st, &od_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (1 > nrows) {
    loop_ub = 0;
  } else {
    loop_ub = nrows;
  }

  emxInit_real_T(&st, &b_x, 2, &lc_emlrtRTEI, true);
  i = b_x->size[0] * b_x->size[1];
  b_x->size[0] = loop_ub;
  b_x->size[1] = 2;
  emxEnsureCapacity_real_T(&st, b_x, i, &lc_emlrtRTEI);
  for (i = 0; i < 2; i++) {
    for (nrows = 0; nrows < loop_ub; nrows++) {
      b_x->data[nrows + b_x->size[0] * i] = x->data[nrows + x->size[0] * i];
    }
  }

  i = x->size[0] * x->size[1];
  x->size[0] = b_x->size[0];
  x->size[1] = 2;
  emxEnsureCapacity_real_T(&st, x, i, &mc_emlrtRTEI);
  for (i = 0; i < 2; i++) {
    loop_ub = b_x->size[0];
    for (nrows = 0; nrows < loop_ub; nrows++) {
      x->data[nrows + x->size[0] * i] = b_x->data[nrows + b_x->size[0] * i];
    }
  }

  emxFree_real_T(&b_x);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (nullAssignment.cpp) */
