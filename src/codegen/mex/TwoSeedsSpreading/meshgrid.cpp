/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * meshgrid.cpp
 *
 * Code generation for function 'meshgrid'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "TwoSeedsSpreading.h"
#include "meshgrid.h"
#include "TwoSeedsSpreading_emxutil.h"
#include "GetNodes.h"
#include "eml_int_forloop_overflow_check.h"
#include "assertValidSizeArg.h"
#include "TwoSeedsSpreading_mexutil.h"
#include "TwoSeedsSpreading_data.h"

/* Variable Definitions */
static emlrtRSInfo s_emlrtRSI = { 17,  /* lineNo */
  "meshgrid",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\meshgrid.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 18,  /* lineNo */
  "meshgrid",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\meshgrid.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 112, /* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 114, /* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 14,/* lineNo */
  9,                                   /* colNo */
  "meshgrid",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\meshgrid.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 15,/* lineNo */
  9,                                   /* colNo */
  "meshgrid",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\meshgrid.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 17,/* lineNo */
  21,                                  /* colNo */
  "meshgrid",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\meshgrid.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 17,/* lineNo */
  14,                                  /* colNo */
  "meshgrid",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\meshgrid.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 18,/* lineNo */
  14,                                  /* colNo */
  "meshgrid",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\meshgrid.m"/* pName */
};

/* Function Definitions */
void meshgrid(const emlrtStack *sp, const emxArray_real_T *x, const
              emxArray_real_T *y, emxArray_real_T *xx, emxArray_real_T *yy)
{
  emxArray_real_T *a;
  int32_T ntilerows;
  int32_T outsize_idx_1;
  real_T varargin_1[2];
  const mxArray *b_y;
  const mxArray *m0;
  static const int32_T iv1[2] = { 1, 15 };

  static const int32_T iv2[2] = { 1, 15 };

  int32_T ibtile;
  int32_T ibmat;
  int32_T itilerow;
  static const int32_T iv3[2] = { 1, 15 };

  static const int32_T iv4[2] = { 1, 15 };

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
  emxInit_real_T(sp, &a, 2, &kb_emlrtRTEI, true);
  if ((x->size[1] == 0) || (y->size[1] == 0)) {
    ntilerows = xx->size[0] * xx->size[1];
    xx->size[0] = 0;
    xx->size[1] = 0;
    emxEnsureCapacity_real_T(sp, xx, ntilerows, &ib_emlrtRTEI);
    ntilerows = yy->size[0] * yy->size[1];
    yy->size[0] = 0;
    yy->size[1] = 0;
    emxEnsureCapacity_real_T(sp, yy, ntilerows, &jb_emlrtRTEI);
  } else {
    st.site = &s_emlrtRSI;
    outsize_idx_1 = x->size[1];
    ntilerows = a->size[0] * a->size[1];
    a->size[0] = 1;
    a->size[1] = outsize_idx_1;
    emxEnsureCapacity_real_T(&st, a, ntilerows, &kb_emlrtRTEI);
    for (ntilerows = 0; ntilerows < outsize_idx_1; ntilerows++) {
      a->data[a->size[0] * ntilerows] = x->data[ntilerows];
    }

    varargin_1[0] = y->size[1];
    varargin_1[1] = 1.0;
    b_st.site = &u_emlrtRSI;
    assertValidSizeArg(&b_st, varargin_1);
    if (!(varargin_1[0] == varargin_1[0])) {
      b_y = NULL;
      m0 = emlrtCreateCharArray(2, iv1);
      emlrtInitCharArrayR2013a(&st, 15, m0, &cv0[0]);
      emlrtAssign(&b_y, m0);
      b_st.site = &me_emlrtRSI;
      d_error(&b_st, b_y, (emlrtMCInfo *)&emlrtMCI);
    }

    outsize_idx_1 = a->size[1];
    if (outsize_idx_1 != a->size[1]) {
      b_y = NULL;
      m0 = emlrtCreateCharArray(2, iv2);
      emlrtInitCharArrayR2013a(&st, 15, m0, &cv0[0]);
      emlrtAssign(&b_y, m0);
      b_st.site = &me_emlrtRSI;
      d_error(&b_st, b_y, (emlrtMCInfo *)&emlrtMCI);
    }

    ntilerows = xx->size[0] * xx->size[1];
    xx->size[0] = (int32_T)varargin_1[0];
    xx->size[1] = outsize_idx_1;
    emxEnsureCapacity_real_T(&st, xx, ntilerows, &lb_emlrtRTEI);
    outsize_idx_1 = a->size[1];
    ntilerows = (int32_T)varargin_1[0];
    b_st.site = &v_emlrtRSI;
    b_st.site = &w_emlrtRSI;
    if (outsize_idx_1 > 2147483646) {
      c_st.site = &y_emlrtRSI;
      d_st.site = &y_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (ibtile = 0; ibtile + 1 <= outsize_idx_1; ibtile++) {
      ibmat = ibtile * ntilerows;
      b_st.site = &x_emlrtRSI;
      if (ntilerows > 2147483646) {
        c_st.site = &y_emlrtRSI;
        d_st.site = &y_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (itilerow = 1; itilerow <= ntilerows; itilerow++) {
        xx->data[(ibmat + itilerow) - 1] = a->data[ibtile];
      }
    }

    st.site = &t_emlrtRSI;
    varargin_1[0] = 1.0;
    varargin_1[1] = x->size[1];
    b_st.site = &u_emlrtRSI;
    assertValidSizeArg(&b_st, varargin_1);
    outsize_idx_1 = y->size[1];
    if (outsize_idx_1 != y->size[1]) {
      b_y = NULL;
      m0 = emlrtCreateCharArray(2, iv3);
      emlrtInitCharArrayR2013a(&st, 15, m0, &cv0[0]);
      emlrtAssign(&b_y, m0);
      b_st.site = &me_emlrtRSI;
      d_error(&b_st, b_y, (emlrtMCInfo *)&emlrtMCI);
    }

    if (!(varargin_1[1] == varargin_1[1])) {
      b_y = NULL;
      m0 = emlrtCreateCharArray(2, iv4);
      emlrtInitCharArrayR2013a(&st, 15, m0, &cv0[0]);
      emlrtAssign(&b_y, m0);
      b_st.site = &me_emlrtRSI;
      d_error(&b_st, b_y, (emlrtMCInfo *)&emlrtMCI);
    }

    ntilerows = yy->size[0] * yy->size[1];
    yy->size[0] = outsize_idx_1;
    yy->size[1] = (int32_T)varargin_1[1];
    emxEnsureCapacity_real_T(&st, yy, ntilerows, &mb_emlrtRTEI);
    outsize_idx_1 = y->size[1];
    b_st.site = &v_emlrtRSI;
    if (varargin_1[1] > 2.147483646E+9) {
      c_st.site = &y_emlrtRSI;
      d_st.site = &y_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (ntilerows = 1; ntilerows <= (int32_T)varargin_1[1]; ntilerows++) {
      ibtile = (ntilerows - 1) * outsize_idx_1;
      b_st.site = &x_emlrtRSI;
      b_st.site = &ab_emlrtRSI;
      if (outsize_idx_1 > 2147483646) {
        c_st.site = &y_emlrtRSI;
        d_st.site = &y_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (ibmat = 1; ibmat <= outsize_idx_1; ibmat++) {
        yy->data[(ibtile + ibmat) - 1] = y->data[ibmat - 1];
      }
    }
  }

  emxFree_real_T(&a);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (meshgrid.cpp) */
