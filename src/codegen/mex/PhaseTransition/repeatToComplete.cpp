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
#include "PhaseTransition.h"
#include "repeatToComplete.h"
#include "PhaseTransition_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "assertValidSizeArg.h"
#include "PhaseTransition_mexutil.h"
#include "PhaseTransition_data.h"

/* Variable Definitions */
static emlrtRSInfo eb_emlrtRSI = { 112,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRTEInfo y_emlrtRTEI = { 3, /* lineNo */
  5,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 4,/* lineNo */
  9,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 4,/* lineNo */
  5,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 8,/* lineNo */
  9,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 11,/* lineNo */
  18,                                  /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  11,                                  /* lineNo */
  5,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

static emlrtDCInfo e_emlrtDCI = { 12,  /* lineNo */
  8,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 11,  /* lineNo */
  10,                                  /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  25,                                  /* colNo */
  "x",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 12,  /* lineNo */
  25,                                  /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  22,                                  /* colNo */
  "x",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  17,                                  /* colNo */
  "x",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = { -1, /* iFirst */
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
  real_T d0;
  int32_T i7;
  const mxArray *b_y;
  const mxArray *m2;
  static const int32_T iv5[2] = { 1, 15 };

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
  emxEnsureCapacity_real_T(sp, y, ibtile, &y_emlrtRTEI);
  outsize_idx_1 = (int32_T)N;
  for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
    y->data[ibtile] = 0.0;
  }

  emxInit_real_T1(sp, &b_x, 2, &ab_emlrtRTEI, true);
  outsize_idx_1 = x->size[1];
  ibtile = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = outsize_idx_1;
  emxEnsureCapacity_real_T(sp, b_x, ibtile, &ab_emlrtRTEI);
  for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
    b_x->data[b_x->size[0] * ibtile] = x->data[ibtile];
  }

  ibtile = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = b_x->size[1];
  emxEnsureCapacity_real_T(sp, x, ibtile, &bb_emlrtRTEI);
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
        emlrtDynamicBoundsCheckR2012b(1, 1, ibtile, (emlrtBCInfo *)&uc_emlrtBCI,
          sp);
      }

      ibtile = x->size[1];
      outsize_idx_1 = (int32_T)N;
      if (!((outsize_idx_1 >= 1) && (outsize_idx_1 <= ibtile))) {
        emlrtDynamicBoundsCheckR2012b(outsize_idx_1, 1, ibtile, (emlrtBCInfo *)
          &tc_emlrtBCI, sp);
      }
    }

    ibtile = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = outsize_idx_1;
    emxEnsureCapacity_real_T(sp, y, ibtile, &cb_emlrtRTEI);
    for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
      y->data[y->size[0] * ibtile] = x->data[ibtile];
    }
  } else {
    d0 = m * (real_T)x->size[1];
    if (1.0 > d0) {
      i7 = 0;
    } else {
      ibtile = (int32_T)N;
      if (!(1 <= ibtile)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, ibtile, (emlrtBCInfo *)&ec_emlrtBCI,
          sp);
      }

      ibtile = (int32_T)N;
      if (d0 != (int32_T)d0) {
        emlrtIntegerCheckR2012b(d0, (emlrtDCInfo *)&f_emlrtDCI, sp);
      }

      i7 = (int32_T)d0;
      if (!((i7 >= 1) && (i7 <= ibtile))) {
        emlrtDynamicBoundsCheckR2012b(i7, 1, ibtile, (emlrtBCInfo *)&dc_emlrtBCI,
          sp);
      }
    }

    st.site = &cb_emlrtRSI;
    b_st.site = &db_emlrtRSI;
    assertValidSizeArg(&b_st, m);
    if (!(m >= 0.0)) {
      emlrtNonNegativeCheckR2012b(rtNaN, (emlrtDCInfo *)&emlrtDCI, &st);
    }

    outsize_idx_1 = x->size[1] * (int32_T)m;
    if (!(outsize_idx_1 == (real_T)x->size[1] * (real_T)(int32_T)m)) {
      b_y = NULL;
      m2 = emlrtCreateCharArray(2, iv5);
      emlrtInitCharArrayR2013a(&st, 15, m2, &cv0[0]);
      emlrtAssign(&b_y, m2);
      b_st.site = &wd_emlrtRSI;
      error(&b_st, b_y, (emlrtMCInfo *)&c_emlrtMCI);
    }

    ibtile = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = outsize_idx_1;
    emxEnsureCapacity_real_T(&st, b_x, ibtile, &db_emlrtRTEI);
    if ((!(x->size[1] == 0)) && (!(outsize_idx_1 == 0))) {
      outsize_idx_1 = x->size[1];
      b_st.site = &eb_emlrtRSI;
      if ((!(1 > (int32_T)m)) && ((int32_T)m > 2147483646)) {
        c_st.site = &gb_emlrtRSI;
        d_st.site = &gb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (jtilecol = 1; jtilecol <= (int32_T)m; jtilecol++) {
        ibtile = (jtilecol - 1) * outsize_idx_1;
        b_st.site = &fb_emlrtRSI;
        if (outsize_idx_1 > 2147483646) {
          c_st.site = &gb_emlrtRSI;
          d_st.site = &gb_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (jcol = 0; jcol + 1 <= outsize_idx_1; jcol++) {
          b_x->data[ibtile + jcol] = x->data[jcol];
        }
      }
    }

    ibtile = b_x->size[1];
    if (i7 != ibtile) {
      emlrtSubAssignSizeCheck1dR2017a(i7, ibtile, (emlrtECInfo *)&b_emlrtECI, sp);
    }

    outsize_idx_1 = b_x->size[1];
    for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
      y->data[ibtile] = b_x->data[b_x->size[0] * ibtile];
    }

    d0 = N - m * (real_T)x->size[1];
    if (1.0 > d0) {
      outsize_idx_1 = 0;
    } else {
      ibtile = x->size[1];
      if (!(1 <= ibtile)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, ibtile, (emlrtBCInfo *)&sc_emlrtBCI,
          sp);
      }

      ibtile = x->size[1];
      if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
        emlrtIntegerCheckR2012b(d0, (emlrtDCInfo *)&g_emlrtDCI, sp);
      }

      outsize_idx_1 = (int32_T)d0;
      if (!((outsize_idx_1 >= 1) && (outsize_idx_1 <= ibtile))) {
        emlrtDynamicBoundsCheckR2012b(outsize_idx_1, 1, ibtile, (emlrtBCInfo *)
          &rc_emlrtBCI, sp);
      }
    }

    d0 = m * (real_T)x->size[1] + 1.0;
    if (d0 > N) {
      i7 = 1;
      ibtile = 1;
    } else {
      ibtile = y->size[1];
      if (d0 != (int32_T)d0) {
        emlrtIntegerCheckR2012b(d0, (emlrtDCInfo *)&e_emlrtDCI, sp);
      }

      i7 = (int32_T)d0;
      if (!((i7 >= 1) && (i7 <= ibtile))) {
        emlrtDynamicBoundsCheckR2012b(i7, 1, ibtile, (emlrtBCInfo *)&cc_emlrtBCI,
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

    ibtile -= i7;
    if (ibtile != outsize_idx_1) {
      emlrtSubAssignSizeCheck1dR2017a(ibtile, outsize_idx_1, (emlrtECInfo *)
        &emlrtECI, sp);
    }

    for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
      y->data[(i7 + ibtile) - 1] = x->data[ibtile];
    }
  }

  emxFree_real_T(&b_x);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (repeatToComplete.cpp) */
