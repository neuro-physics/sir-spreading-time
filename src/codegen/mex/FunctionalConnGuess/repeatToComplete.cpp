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
#include "FunctionalConnGuess.h"
#include "repeatToComplete.h"
#include "FunctionalConnGuess_emxutil.h"
#include "GetNodes.h"
#include "eml_int_forloop_overflow_check.h"
#include "assertValidSizeArg.h"
#include "FunctionalConnGuess_mexutil.h"
#include "FunctionalConnGuess_data.h"

/* Variable Definitions */
static emlrtRSInfo r_emlrtRSI = { 112, /* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 114, /* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 3,/* lineNo */
  5,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 4,/* lineNo */
  9,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 4,/* lineNo */
  5,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 8,/* lineNo */
  9,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 11,/* lineNo */
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

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
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

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  22,                                  /* colNo */
  "x",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  17,                                  /* colNo */
  "x",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
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
  int32_T i8;
  const mxArray *b_y;
  const mxArray *m1;
  static const int32_T iv2[2] = { 1, 15 };

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
  emxEnsureCapacity_real_T(sp, y, ibtile, &ib_emlrtRTEI);
  outsize_idx_1 = (int32_T)N;
  for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
    y->data[ibtile] = 0.0;
  }

  emxInit_real_T1(sp, &b_x, 2, &jb_emlrtRTEI, true);
  outsize_idx_1 = x->size[1];
  ibtile = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = outsize_idx_1;
  emxEnsureCapacity_real_T(sp, b_x, ibtile, &jb_emlrtRTEI);
  for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
    b_x->data[b_x->size[0] * ibtile] = x->data[ibtile];
  }

  ibtile = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = b_x->size[1];
  emxEnsureCapacity_real_T(sp, x, ibtile, &kb_emlrtRTEI);
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
        emlrtDynamicBoundsCheckR2012b(1, 1, ibtile, (emlrtBCInfo *)&mc_emlrtBCI,
          sp);
      }

      ibtile = x->size[1];
      outsize_idx_1 = (int32_T)N;
      if (!((outsize_idx_1 >= 1) && (outsize_idx_1 <= ibtile))) {
        emlrtDynamicBoundsCheckR2012b(outsize_idx_1, 1, ibtile, (emlrtBCInfo *)
          &lc_emlrtBCI, sp);
      }
    }

    ibtile = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = outsize_idx_1;
    emxEnsureCapacity_real_T(sp, y, ibtile, &lb_emlrtRTEI);
    for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
      y->data[y->size[0] * ibtile] = x->data[ibtile];
    }
  } else {
    d0 = m * (real_T)x->size[1];
    if (1.0 > d0) {
      i8 = 0;
    } else {
      ibtile = (int32_T)N;
      if (!(1 <= ibtile)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, ibtile, (emlrtBCInfo *)&wb_emlrtBCI,
          sp);
      }

      ibtile = (int32_T)N;
      if (d0 != (int32_T)d0) {
        emlrtIntegerCheckR2012b(d0, (emlrtDCInfo *)&j_emlrtDCI, sp);
      }

      i8 = (int32_T)d0;
      if (!((i8 >= 1) && (i8 <= ibtile))) {
        emlrtDynamicBoundsCheckR2012b(i8, 1, ibtile, (emlrtBCInfo *)&vb_emlrtBCI,
          sp);
      }
    }

    st.site = &p_emlrtRSI;
    b_st.site = &q_emlrtRSI;
    assertValidSizeArg(&b_st, m);
    if (!(m >= 0.0)) {
      emlrtNonNegativeCheckR2012b(rtNaN, (emlrtDCInfo *)&h_emlrtDCI, &st);
    }

    outsize_idx_1 = x->size[1] * (int32_T)m;
    if (!(outsize_idx_1 == (real_T)x->size[1] * (real_T)(int32_T)m)) {
      b_y = NULL;
      m1 = emlrtCreateCharArray(2, iv2);
      emlrtInitCharArrayR2013a(&st, 15, m1, &cv0[0]);
      emlrtAssign(&b_y, m1);
      b_st.site = &pc_emlrtRSI;
      error(&b_st, b_y, (emlrtMCInfo *)&emlrtMCI);
    }

    ibtile = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = outsize_idx_1;
    emxEnsureCapacity_real_T(&st, b_x, ibtile, &mb_emlrtRTEI);
    if ((!(x->size[1] == 0)) && (!(outsize_idx_1 == 0))) {
      outsize_idx_1 = x->size[1];
      b_st.site = &r_emlrtRSI;
      if ((!(1 > (int32_T)m)) && ((int32_T)m > 2147483646)) {
        c_st.site = &t_emlrtRSI;
        d_st.site = &t_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (jtilecol = 1; jtilecol <= (int32_T)m; jtilecol++) {
        ibtile = (jtilecol - 1) * outsize_idx_1;
        b_st.site = &s_emlrtRSI;
        if (outsize_idx_1 > 2147483646) {
          c_st.site = &t_emlrtRSI;
          d_st.site = &t_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (jcol = 1; jcol <= outsize_idx_1; jcol++) {
          b_x->data[(ibtile + jcol) - 1] = 0.0;
        }
      }
    }

    ibtile = b_x->size[1];
    if (i8 != ibtile) {
      emlrtSubAssignSizeCheck1dR2017a(i8, ibtile, (emlrtECInfo *)&c_emlrtECI, sp);
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
        emlrtDynamicBoundsCheckR2012b(1, 1, ibtile, (emlrtBCInfo *)&kc_emlrtBCI,
          sp);
      }

      ibtile = x->size[1];
      if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
        emlrtIntegerCheckR2012b(d0, (emlrtDCInfo *)&k_emlrtDCI, sp);
      }

      outsize_idx_1 = (int32_T)d0;
      if (!((outsize_idx_1 >= 1) && (outsize_idx_1 <= ibtile))) {
        emlrtDynamicBoundsCheckR2012b(outsize_idx_1, 1, ibtile, (emlrtBCInfo *)
          &jc_emlrtBCI, sp);
      }
    }

    d0 = m * (real_T)x->size[1] + 1.0;
    if (d0 > N) {
      i8 = 1;
      ibtile = 1;
    } else {
      ibtile = y->size[1];
      if (d0 != (int32_T)d0) {
        emlrtIntegerCheckR2012b(d0, (emlrtDCInfo *)&i_emlrtDCI, sp);
      }

      i8 = (int32_T)d0;
      if (!((i8 >= 1) && (i8 <= ibtile))) {
        emlrtDynamicBoundsCheckR2012b(i8, 1, ibtile, (emlrtBCInfo *)&ub_emlrtBCI,
          sp);
      }

      ibtile = y->size[1];
      jtilecol = (int32_T)N;
      if (!((jtilecol >= 1) && (jtilecol <= ibtile))) {
        emlrtDynamicBoundsCheckR2012b(jtilecol, 1, ibtile, (emlrtBCInfo *)
          &tb_emlrtBCI, sp);
      }

      ibtile = jtilecol + 1;
    }

    ibtile -= i8;
    if (ibtile != outsize_idx_1) {
      emlrtSubAssignSizeCheck1dR2017a(ibtile, outsize_idx_1, (emlrtECInfo *)
        &b_emlrtECI, sp);
    }

    for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
      y->data[(i8 + ibtile) - 1] = x->data[ibtile];
    }
  }

  emxFree_real_T(&b_x);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (repeatToComplete.cpp) */
