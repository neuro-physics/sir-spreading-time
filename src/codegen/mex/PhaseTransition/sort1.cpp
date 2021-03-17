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
#include "PhaseTransition.h"
#include "sort1.h"
#include "PhaseTransition_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sortIdx.h"
#include "PhaseTransition_data.h"

/* Variable Definitions */
static emlrtRSInfo mb_emlrtRSI = { 19, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 50, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 71, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 74, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 76, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 79, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 82, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 84, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 49, /* lineNo */
  "prodsize",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\prodsize.m"/* pathName */
};

static emlrtRSInfo qd_emlrtRSI = { 23, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 52,/* lineNo */
  1,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

/* Function Declarations */
static void b_sort(const emlrtStack *sp, emxArray_real_T *x, int32_T dim,
                   emxArray_int32_T *idx);
static void d_sort(const emlrtStack *sp, emxArray_real_T *x, int32_T dim);
static void f_sort(const emlrtStack *sp, emxArray_real_T *x, int32_T dim,
                   emxArray_int32_T *idx);

/* Function Definitions */
static void b_sort(const emlrtStack *sp, emxArray_real_T *x, int32_T dim,
                   emxArray_int32_T *idx)
{
  int32_T i13;
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
  st.site = &nb_emlrtRSI;
  if (dim <= 1) {
    i13 = x->size[0];
  } else {
    i13 = 1;
  }

  emxInit_real_T(sp, &vwork, 1, &mb_emlrtRTEI, true);
  vstride = vwork->size[0];
  vwork->size[0] = i13;
  emxEnsureCapacity_real_T1(sp, vwork, vstride, &eb_emlrtRTEI);
  x_idx_0 = x->size[0];
  vstride = idx->size[0];
  idx->size[0] = x_idx_0;
  emxEnsureCapacity_int32_T(sp, idx, vstride, &eb_emlrtRTEI);
  st.site = &ob_emlrtRSI;
  vstride = 1;
  b_st.site = &ub_emlrtRSI;
  if ((!(1 > dim - 1)) && (dim - 1 > 2147483646)) {
    c_st.site = &gb_emlrtRSI;
    d_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  x_idx_0 = 1;
  while (x_idx_0 <= dim - 1) {
    vstride *= x->size[0];
    x_idx_0 = 2;
  }

  st.site = &pb_emlrtRSI;
  st.site = &qb_emlrtRSI;
  if ((!(1 > vstride)) && (vstride > 2147483646)) {
    b_st.site = &gb_emlrtRSI;
    c_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  j = 0;
  emxInit_int32_T(sp, &iidx, 1, &eb_emlrtRTEI, true);
  while (j + 1 <= vstride) {
    st.site = &rb_emlrtRSI;
    if ((!(1 > i13)) && (i13 > 2147483646)) {
      b_st.site = &gb_emlrtRSI;
      c_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (x_idx_0 = 0; x_idx_0 + 1 <= i13; x_idx_0++) {
      vwork->data[x_idx_0] = x->data[j + x_idx_0 * vstride];
    }

    st.site = &sb_emlrtRSI;
    sortIdx(&st, vwork, iidx);
    st.site = &tb_emlrtRSI;
    for (x_idx_0 = 0; x_idx_0 + 1 <= i13; x_idx_0++) {
      x->data[j + x_idx_0 * vstride] = vwork->data[x_idx_0];
      idx->data[j + x_idx_0 * vstride] = iidx->data[x_idx_0];
    }

    j++;
  }

  emxFree_int32_T(&iidx);
  emxFree_real_T(&vwork);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void d_sort(const emlrtStack *sp, emxArray_real_T *x, int32_T dim)
{
  emxArray_real_T *vwork;
  int32_T i16;
  int32_T vstride;
  int32_T k;
  int32_T j;
  emxArray_int32_T *xd_emlrtRSI;
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
  emxInit_real_T(sp, &vwork, 1, &mb_emlrtRTEI, true);
  st.site = &nb_emlrtRSI;
  i16 = x->size[dim - 1];
  vstride = x->size[dim - 1];
  k = vwork->size[0];
  vwork->size[0] = vstride;
  emxEnsureCapacity_real_T1(sp, vwork, k, &eb_emlrtRTEI);
  st.site = &ob_emlrtRSI;
  vstride = 1;
  b_st.site = &ub_emlrtRSI;
  if ((!(1 > dim - 1)) && (dim - 1 > 2147483646)) {
    c_st.site = &gb_emlrtRSI;
    d_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  k = 1;
  while (k <= dim - 1) {
    vstride *= x->size[0];
    k = 2;
  }

  st.site = &pb_emlrtRSI;
  st.site = &qb_emlrtRSI;
  if ((!(1 > vstride)) && (vstride > 2147483646)) {
    b_st.site = &gb_emlrtRSI;
    c_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  j = 0;
  emxInit_int32_T(sp, &xd_emlrtRSI, 1, &eb_emlrtRTEI, true);
  while (j + 1 <= vstride) {
    st.site = &rb_emlrtRSI;
    if ((!(1 > i16)) && (i16 > 2147483646)) {
      b_st.site = &gb_emlrtRSI;
      c_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (k = 0; k + 1 <= i16; k++) {
      vwork->data[k] = x->data[j + k * vstride];
    }

    st.site = &sb_emlrtRSI;
    b_sortIdx(&st, vwork, xd_emlrtRSI);
    st.site = &tb_emlrtRSI;
    for (k = 0; k + 1 <= i16; k++) {
      x->data[j + k * vstride] = vwork->data[k];
    }

    j++;
  }

  emxFree_int32_T(&xd_emlrtRSI);
  emxFree_real_T(&vwork);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void f_sort(const emlrtStack *sp, emxArray_real_T *x, int32_T dim,
                   emxArray_int32_T *idx)
{
  int32_T i18;
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
  st.site = &nb_emlrtRSI;
  if (dim <= 1) {
    i18 = x->size[0];
  } else {
    i18 = 1;
  }

  emxInit_real_T(sp, &vwork, 1, &mb_emlrtRTEI, true);
  vstride = vwork->size[0];
  vwork->size[0] = i18;
  emxEnsureCapacity_real_T1(sp, vwork, vstride, &eb_emlrtRTEI);
  x_idx_0 = x->size[0];
  vstride = idx->size[0];
  idx->size[0] = x_idx_0;
  emxEnsureCapacity_int32_T(sp, idx, vstride, &eb_emlrtRTEI);
  st.site = &ob_emlrtRSI;
  vstride = 1;
  b_st.site = &ub_emlrtRSI;
  if ((!(1 > dim - 1)) && (dim - 1 > 2147483646)) {
    c_st.site = &gb_emlrtRSI;
    d_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  x_idx_0 = 1;
  while (x_idx_0 <= dim - 1) {
    vstride *= x->size[0];
    x_idx_0 = 2;
  }

  st.site = &pb_emlrtRSI;
  st.site = &qb_emlrtRSI;
  if ((!(1 > vstride)) && (vstride > 2147483646)) {
    b_st.site = &gb_emlrtRSI;
    c_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  j = 0;
  emxInit_int32_T(sp, &iidx, 1, &eb_emlrtRTEI, true);
  while (j + 1 <= vstride) {
    st.site = &rb_emlrtRSI;
    if ((!(1 > i18)) && (i18 > 2147483646)) {
      b_st.site = &gb_emlrtRSI;
      c_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (x_idx_0 = 0; x_idx_0 + 1 <= i18; x_idx_0++) {
      vwork->data[x_idx_0] = x->data[j + x_idx_0 * vstride];
    }

    st.site = &sb_emlrtRSI;
    b_sortIdx(&st, vwork, iidx);
    st.site = &tb_emlrtRSI;
    for (x_idx_0 = 0; x_idx_0 + 1 <= i18; x_idx_0++) {
      x->data[j + x_idx_0 * vstride] = vwork->data[x_idx_0];
      idx->data[j + x_idx_0 * vstride] = iidx->data[x_idx_0];
    }

    j++;
  }

  emxFree_int32_T(&iidx);
  emxFree_real_T(&vwork);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void c_sort(const emlrtStack *sp, emxArray_real_T *x)
{
  int32_T i15;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  i15 = 2;
  if (x->size[0] != 1) {
    i15 = 1;
  }

  st.site = &qd_emlrtRSI;
  d_sort(&st, x, i15);
}

void e_sort(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  int32_T i17;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  i17 = 2;
  if (x->size[0] != 1) {
    i17 = 1;
  }

  st.site = &mb_emlrtRSI;
  f_sort(&st, x, i17, idx);
}

void sort(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  int32_T i12;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  i12 = 2;
  if (x->size[0] != 1) {
    i12 = 1;
  }

  st.site = &mb_emlrtRSI;
  b_sort(&st, x, i12, idx);
}

/* End of code generation (sort1.cpp) */
