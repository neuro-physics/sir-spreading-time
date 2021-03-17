/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repeatToComplete.cpp
 *
 * Code generation for function 'repeatToComplete'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindBestFunctionalMatch.h"
#include "repeatToComplete.h"
#include "FindBestFunctionalMatch_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "assertValidSizeArg.h"
#include "FindBestFunctionalMatch_mexutil.h"
#include "FindBestFunctionalMatch_data.h"

/* Variable Definitions */
static emlrtRSInfo mb_emlrtRSI = { 112,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 114,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRTEInfo dc_emlrtRTEI = { 3,/* lineNo */
  5,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = { 4,/* lineNo */
  9,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = { 4,/* lineNo */
  5,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = { 8,/* lineNo */
  9,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = { 11,/* lineNo */
  18,                                  /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  11,                                  /* lineNo */
  5,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

static emlrtDCInfo h_emlrtDCI = { 21,  /* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 12,  /* lineNo */
  8,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 11,  /* lineNo */
  10,                                  /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  25,                                  /* colNo */
  "x",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 12,  /* lineNo */
  25,                                  /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  22,                                  /* colNo */
  "x",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  17,                                  /* colNo */
  "x",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  15,                                  /* colNo */
  "x",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void repeatToComplete(const emlrtStack *sp, emxArray_real_T *x, real_T N,
                      emxArray_real_T *y)
{
  int32_T ibtile;
  int32_T outsize_idx_1;
  emxArray_real_T *b_x;
  real_T m;
  real_T d1;
  int32_T i9;
  const mxArray *b_y;
  const mxArray *m4;
  static const int32_T iv7[2] = { 1, 15 };

  int32_T jtilecol;
  int32_T jcol;
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

  /*  y = [ x(:)', x(:)', ..., x(:)' ]; such that y is [1,N] vector */
  ibtile = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)N;
  emxEnsureCapacity_real_T(sp, y, ibtile, &dc_emlrtRTEI);
  outsize_idx_1 = (int32_T)N;
  for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
    y->data[ibtile] = 0.0;
  }

  emxInit_real_T(sp, &b_x, 2, &ec_emlrtRTEI, true);
  outsize_idx_1 = x->size[1];
  ibtile = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = outsize_idx_1;
  emxEnsureCapacity_real_T(sp, b_x, ibtile, &ec_emlrtRTEI);
  for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
    b_x->data[b_x->size[0] * ibtile] = x->data[ibtile];
  }

  ibtile = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = b_x->size[1];
  emxEnsureCapacity_real_T(sp, x, ibtile, &fc_emlrtRTEI);
  outsize_idx_1 = b_x->size[1];
  for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
    x->data[x->size[0] * ibtile] = b_x->data[b_x->size[0] * ibtile];
  }

  m = muDoubleScalarFloor(N / (real_T)x->size[1]);
  if (m <= 1.0) {
    if (1.0 > N) {
      outsize_idx_1 = 0;
    } else {
      ibtile = x->size[1];
      if (!(1 <= ibtile)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, ibtile, (emlrtBCInfo *)&tc_emlrtBCI,
          sp);
      }

      ibtile = x->size[1];
      outsize_idx_1 = (int32_T)N;
      if (!((outsize_idx_1 >= 1) && (outsize_idx_1 <= ibtile))) {
        emlrtDynamicBoundsCheckR2012b(outsize_idx_1, 1, ibtile, (emlrtBCInfo *)
          &sc_emlrtBCI, sp);
      }
    }

    ibtile = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = outsize_idx_1;
    emxEnsureCapacity_real_T(sp, y, ibtile, &gc_emlrtRTEI);
    for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
      y->data[y->size[0] * ibtile] = x->data[ibtile];
    }
  } else {
    d1 = m * (real_T)x->size[1];
    if (1.0 > d1) {
      i9 = 0;
    } else {
      ibtile = (int32_T)N;
      if (!(1 <= ibtile)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, ibtile, (emlrtBCInfo *)&ec_emlrtBCI,
          sp);
      }

      ibtile = (int32_T)N;
      if (d1 != (int32_T)d1) {
        emlrtIntegerCheckR2012b(d1, (emlrtDCInfo *)&j_emlrtDCI, sp);
      }

      i9 = (int32_T)d1;
      if (!((i9 >= 1) && (i9 <= ibtile))) {
        emlrtDynamicBoundsCheckR2012b(i9, 1, ibtile, (emlrtBCInfo *)&dc_emlrtBCI,
          sp);
      }
    }

    st.site = &kb_emlrtRSI;
    b_st.site = &lb_emlrtRSI;
    assertValidSizeArg(&b_st, m);
    if (!(m >= 0.0)) {
      emlrtNonNegativeCheckR2012b(rtNaN, (emlrtDCInfo *)&h_emlrtDCI, &st);
    }

    outsize_idx_1 = x->size[1] * (int32_T)m;
    if (!(outsize_idx_1 == (real_T)x->size[1] * (real_T)(int32_T)m)) {
      b_y = NULL;
      m4 = emlrtCreateCharArray(2, iv7);
      emlrtInitCharArrayR2013a(&st, 15, m4, &cv0[0]);
      emlrtAssign(&b_y, m4);
      b_st.site = &md_emlrtRSI;
      error(&b_st, b_y, (emlrtMCInfo *)&b_emlrtMCI);
    }

    ibtile = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = outsize_idx_1;
    emxEnsureCapacity_real_T(&st, b_x, ibtile, &hc_emlrtRTEI);
    if ((!(x->size[1] == 0)) && (!(outsize_idx_1 == 0))) {
      outsize_idx_1 = x->size[1];
      b_st.site = &mb_emlrtRSI;
      if ((!(1 > (int32_T)m)) && ((int32_T)m > 2147483646)) {
        c_st.site = &k_emlrtRSI;
        d_st.site = &k_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (jtilecol = 1; jtilecol <= (int32_T)m; jtilecol++) {
        ibtile = (jtilecol - 1) * outsize_idx_1;
        b_st.site = &nb_emlrtRSI;
        if (outsize_idx_1 > 2147483646) {
          c_st.site = &k_emlrtRSI;
          d_st.site = &k_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (jcol = 1; jcol <= outsize_idx_1; jcol++) {
          b_x->data[(ibtile + jcol) - 1] = 0.0;
        }
      }
    }

    ibtile = b_x->size[1];
    if (i9 != ibtile) {
      emlrtSubAssignSizeCheck1dR2017a(i9, ibtile, (emlrtECInfo *)&c_emlrtECI, sp);
    }

    outsize_idx_1 = b_x->size[1];
    for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
      y->data[ibtile] = b_x->data[b_x->size[0] * ibtile];
    }

    d1 = N - m * (real_T)x->size[1];
    if (1.0 > d1) {
      outsize_idx_1 = 0;
    } else {
      ibtile = x->size[1];
      if (!(1 <= ibtile)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, ibtile, (emlrtBCInfo *)&rc_emlrtBCI,
          sp);
      }

      ibtile = x->size[1];
      if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
        emlrtIntegerCheckR2012b(d1, (emlrtDCInfo *)&k_emlrtDCI, sp);
      }

      outsize_idx_1 = (int32_T)d1;
      if (!((outsize_idx_1 >= 1) && (outsize_idx_1 <= ibtile))) {
        emlrtDynamicBoundsCheckR2012b(outsize_idx_1, 1, ibtile, (emlrtBCInfo *)
          &qc_emlrtBCI, sp);
      }
    }

    d1 = m * (real_T)x->size[1] + 1.0;
    if (d1 > N) {
      i9 = 1;
      ibtile = 1;
    } else {
      ibtile = y->size[1];
      if (d1 != (int32_T)d1) {
        emlrtIntegerCheckR2012b(d1, (emlrtDCInfo *)&i_emlrtDCI, sp);
      }

      i9 = (int32_T)d1;
      if (!((i9 >= 1) && (i9 <= ibtile))) {
        emlrtDynamicBoundsCheckR2012b(i9, 1, ibtile, (emlrtBCInfo *)&cc_emlrtBCI,
          sp);
      }

      ibtile = y->size[1];
      jtilecol = (int32_T)N;
      if (!((jtilecol >= 1) && (jtilecol <= ibtile))) {
        emlrtDynamicBoundsCheckR2012b(jtilecol, 1, ibtile, (emlrtBCInfo *)
          &bc_emlrtBCI, sp);
      }

      ibtile = jtilecol + 1;
    }

    ibtile -= i9;
    if (ibtile != outsize_idx_1) {
      emlrtSubAssignSizeCheck1dR2017a(ibtile, outsize_idx_1, (emlrtECInfo *)
        &b_emlrtECI, sp);
    }

    for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
      y->data[(i9 + ibtile) - 1] = x->data[ibtile];
    }
  }

  emxFree_real_T(&b_x);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (repeatToComplete.cpp) */
