/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sort1.cpp
 *
 * Code generation for function 'sort1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "TwoSeedsSpreading.h"
#include "sort1.h"
#include "TwoSeedsSpreading_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sortIdx.h"
#include "TwoSeedsSpreading_data.h"

/* Variable Definitions */
static emlrtRSInfo jc_emlrtRSI = { 19, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 50, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 71, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 74, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 76, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 79, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 82, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo qc_emlrtRSI = { 84, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo rc_emlrtRSI = { 49, /* lineNo */
  "prodsize",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\prodsize.m"/* pathName */
};

static emlrtRTEInfo ec_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = { 52,/* lineNo */
  1,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

/* Function Declarations */
static void c_sort(const emlrtStack *sp, emxArray_real_T *x, int32_T dim,
                   emxArray_int32_T *idx);

/* Function Definitions */
static void c_sort(const emlrtStack *sp, emxArray_real_T *x, int32_T dim,
                   emxArray_int32_T *idx)
{
  int32_T i25;
  emxArray_real_T *vwork;
  int32_T vstride;
  int32_T x_idx_0;
  int32_T j;
  emxArray_int32_T *iidx;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &kc_emlrtRSI;
  if (dim <= 1) {
    i25 = x->size[0];
  } else {
    i25 = 1;
  }

  emxInit_real_T1(sp, &vwork, 1, &oc_emlrtRTEI, true);
  vstride = vwork->size[0];
  vwork->size[0] = i25;
  emxEnsureCapacity_real_T1(sp, vwork, vstride, &ec_emlrtRTEI);
  x_idx_0 = x->size[0];
  vstride = idx->size[0];
  idx->size[0] = x_idx_0;
  emxEnsureCapacity_int32_T1(sp, idx, vstride, &ec_emlrtRTEI);
  st.site = &lc_emlrtRSI;
  vstride = 1;
  b_st.site = &rc_emlrtRSI;
  if ((!(1 > dim - 1)) && (dim - 1 > 2147483646)) {
    c_st.site = &y_emlrtRSI;
    d_st.site = &y_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  x_idx_0 = 1;
  while (x_idx_0 <= dim - 1) {
    vstride *= x->size[0];
    x_idx_0 = 2;
  }

  st.site = &mc_emlrtRSI;
  st.site = &nc_emlrtRSI;
  if ((!(1 > vstride)) && (vstride > 2147483646)) {
    b_st.site = &y_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  j = 0;
  emxInit_int32_T(sp, &iidx, 1, &ec_emlrtRTEI, true);
  while (j + 1 <= vstride) {
    st.site = &oc_emlrtRSI;
    if ((!(1 > i25)) && (i25 > 2147483646)) {
      b_st.site = &y_emlrtRSI;
      c_st.site = &y_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (x_idx_0 = 0; x_idx_0 + 1 <= i25; x_idx_0++) {
      vwork->data[x_idx_0] = x->data[j + x_idx_0 * vstride];
    }

    st.site = &pc_emlrtRSI;
    sortIdx(&st, vwork, iidx);
    st.site = &qc_emlrtRSI;
    for (x_idx_0 = 0; x_idx_0 + 1 <= i25; x_idx_0++) {
      x->data[j + x_idx_0 * vstride] = vwork->data[x_idx_0];
      idx->data[j + x_idx_0 * vstride] = iidx->data[x_idx_0];
    }

    j++;
  }

  emxFree_int32_T(&iidx);
  emxFree_real_T(&vwork);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void b_sort(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  int32_T i24;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  i24 = 2;
  if (x->size[0] != 1) {
    i24 = 1;
  }

  st.site = &jc_emlrtRSI;
  c_sort(&st, x, i24, idx);
}

void sort(real_T x[2])
{
  boolean_T p;
  real_T tmp;
  if ((x[0] <= x[1]) || muDoubleScalarIsNaN(x[1])) {
    p = true;
  } else {
    p = false;
  }

  if (!p) {
    tmp = x[0];
    x[0] = x[1];
    x[1] = tmp;
  }
}

/* End of code generation (sort1.cpp) */
