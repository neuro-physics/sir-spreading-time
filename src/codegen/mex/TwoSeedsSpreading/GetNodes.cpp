/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * GetNodes.cpp
 *
 * Code generation for function 'GetNodes'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "TwoSeedsSpreading.h"
#include "GetNodes.h"
#include "TwoSeedsSpreading_emxutil.h"
#include "error.h"
#include "eml_int_forloop_overflow_check.h"
#include "sort1.h"
#include "assertValidSizeArg.h"
#include "TwoSeedsSpreading_mexutil.h"
#include "TwoSeedsSpreading_data.h"

/* Variable Definitions */
static emlrtRSInfo vb_emlrtRSI = { 11, /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 15, /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 16, /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 17, /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 20, /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 21, /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 25, /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 11, /* lineNo */
  "repeatToComplete",                  /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 253,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 18, /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 26, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 9,  /* lineNo */
  "sum",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pathName */
};

static emlrtRSInfo pd_emlrtRSI = { 58, /* lineNo */
  "sumprod",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

static emlrtRSInfo qd_emlrtRSI = { 106,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo rd_emlrtRSI = { 166,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRTEInfo tb_emlrtRTEI = { 15,/* lineNo */
  5,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 41,/* lineNo */
  9,                                   /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 20,/* lineNo */
  9,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = { 26,/* lineNo */
  6,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = { 27,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = { 23,/* lineNo */
  9,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = { 24,/* lineNo */
  9,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = { 1,/* lineNo */
  18,                                  /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo ld_emlrtRTEI = { 20,/* lineNo */
  15,                                  /* colNo */
  "sumprod",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pName */
};

static emlrtRTEInfo md_emlrtRTEI = { 88,/* lineNo */
  9,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtBCInfo ub_emlrtBCI = { 1,  /* iFirst */
  1,                                   /* iLast */
  8,                                   /* lineNo */
  17,                                  /* colNo */
  "x",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { 1,  /* iFirst */
  1,                                   /* iLast */
  12,                                  /* lineNo */
  25,                                  /* colNo */
  "x",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  7,                                   /* colNo */
  "y",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  10,                                  /* colNo */
  "y",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  8,                                   /* colNo */
  "y",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  15,                                  /* colNo */
  "y",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  12,                                  /* lineNo */
  5,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  73,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  59,                                  /* colNo */
  "Theta_el",                          /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  31,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  29,                                  /* colNo */
  "x_init",                            /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  28,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  24,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  17,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  24,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  30,                                  /* colNo */
  "ind",                               /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  24,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  28,                                  /* colNo */
  "ind",                               /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  69,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

/* Function Declarations */
static void cast(const emlrtStack *sp, const b_emxArray_struct_T *x,
                 emxArray_struct_T *y);

/* Function Definitions */
static void cast(const emlrtStack *sp, const b_emxArray_struct_T *x,
                 emxArray_struct_T *y)
{
  int32_T i23;
  int32_T j;
  i23 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity_struct_T1(sp, y, i23, (emlrtRTEInfo *)NULL);
  j = 0;
  while (j < x->size[1]) {
    y->data[j].x = x->data[j].x;
    i23 = y->data[j].neigh->size[0];
    y->data[j].neigh->size[0] = 0;
    emxEnsureCapacity_real_T1(sp, y->data[j].neigh, i23, (emlrtRTEInfo *)NULL);
    i23 = y->data[j].w->size[0];
    y->data[j].w->size[0] = 0;
    emxEnsureCapacity_real_T1(sp, y->data[j].w, i23, (emlrtRTEInfo *)NULL);
    y->data[j].par = x->data[j].par;
    j++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

void GetNodes(const emlrtStack *sp, const emxArray_real_T *A, real_T Theta,
              real_T nSeeds, real_T isCompetitive, emxArray_struct_T *nodes)
{
  emxArray_int8_T *x_init;
  int32_T i5;
  int32_T loop_ub;
  int32_T i6;
  emxArray_real_T *Theta_el;
  int32_T idx;
  int32_T i7;
  int32_T vlen;
  const mxArray *y;
  b_emxArray_struct_T *r6;
  const mxArray *m2;
  static const int32_T iv7[2] = { 1, 15 };

  static const c_struct_T r7 = { 0.0,  /* x */
    { 0.0,                             /* Iext */
      0.0,                             /* Isyn */
      0.0,                             /* kInp */
      0.0,                             /* Theta */
      0.0,                             /* W */
      0.0,                             /* n */
      0.0,                             /* nInp */
      0.0                              /* spTime */
    }                                  /* par */
  };

  int32_T j;
  emxArray_int32_T *ind;
  emxArray_int32_T *ii;
  emxArray_real_T *x;
  int32_T nx;
  int32_T i8;
  int32_T i9;
  int32_T i10;
  int32_T b_A;
  int32_T c_A;
  int32_T d_A;
  boolean_T overflow;
  boolean_T exitg1;
  boolean_T nonSingletonDimFound;
  real_T b_y;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  A       -> [N,N] adjacency matrix (either weighted or binary) */
  /*  Theta   -> [1,1] to [1,N] vector activation threshold; if a vector is provided, each element has Theta(i) activation Threshold */
  /*  x0      -> [1,1] to [1,N] initial condition; if a vector is provided, each element has ic x0(i) */
  st.site = &vb_emlrtRSI;
  if (muDoubleScalarIsNaN(isCompetitive)) {
    b_st.site = &ub_emlrtRSI;
    c_st.site = &ub_emlrtRSI;
    b_error(&c_st);
  }

  if (!(isCompetitive != 0.0)) {
    nSeeds = 1.0;
  }

  emxInit_int8_T(sp, &x_init, 2, &tb_emlrtRTEI, true);
  i5 = A->size[0];
  if (!(1 <= i5)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i5, (emlrtBCInfo *)&hc_emlrtBCI, sp);
  }

  i5 = A->size[1];
  st.site = &wb_emlrtRSI;

  /*  y = [ x(:)', x(:)', ..., x(:)' ]; such that y is [1,N] vector */
  loop_ub = A->size[1];
  i6 = x_init->size[0] * x_init->size[1];
  x_init->size[0] = 1;
  x_init->size[1] = loop_ub;
  emxEnsureCapacity_int8_T(&st, x_init, i6, &tb_emlrtRTEI);
  for (i6 = 0; i6 < loop_ub; i6++) {
    x_init->data[i6] = 0;
  }

  loop_ub = A->size[1];
  if (loop_ub <= 1) {
    i6 = A->size[1];
    if (1 > i6) {
      loop_ub = 0;
    } else {
      i6 = A->size[1];
      if (!((i6 >= 1) && (i6 <= 1))) {
        emlrtDynamicBoundsCheckR2012b(i6, 1, 1, (emlrtBCInfo *)&ub_emlrtBCI, &st);
      }

      loop_ub = 1;
    }

    i6 = x_init->size[0] * x_init->size[1];
    x_init->size[0] = 1;
    x_init->size[1] = loop_ub;
    emxEnsureCapacity_int8_T(&st, x_init, i6, &tb_emlrtRTEI);
    for (i6 = 0; i6 < loop_ub; i6++) {
      x_init->data[i6] = 0;
    }
  } else {
    i6 = A->size[1];
    if (!(1 <= i6)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i6, (emlrtBCInfo *)&wb_emlrtBCI, &st);
    }

    i6 = A->size[1];
    if (!(loop_ub <= i6)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i6, (emlrtBCInfo *)&xb_emlrtBCI,
        &st);
    }

    b_st.site = &dc_emlrtRSI;
    c_st.site = &u_emlrtRSI;
    b_assertValidSizeArg(&c_st, (real_T)loop_ub);
    for (i6 = 0; i6 < loop_ub; i6++) {
      x_init->data[i6] = 0;
    }

    i6 = A->size[1];
    i6 -= loop_ub;
    if (1 > i6) {
      idx = 0;
    } else {
      if (!(i6 <= 1)) {
        emlrtDynamicBoundsCheckR2012b(i6, 1, 1, (emlrtBCInfo *)&vb_emlrtBCI, &st);
      }

      idx = 1;
    }

    i6 = A->size[1];
    if (loop_ub + 1U > (uint32_T)i6) {
      i7 = 1;
      i6 = 1;
    } else {
      i6 = x_init->size[1];
      i7 = (int32_T)(loop_ub + 1U);
      if (!((i7 >= 1) && (i7 <= i6))) {
        emlrtDynamicBoundsCheckR2012b(i7, 1, i6, (emlrtBCInfo *)&yb_emlrtBCI,
          &st);
      }

      i6 = A->size[1];
      vlen = x_init->size[1];
      if (!((i6 >= 1) && (i6 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i6, 1, vlen, (emlrtBCInfo *)&ac_emlrtBCI,
          &st);
      }

      i6++;
    }

    i6 -= i7;
    if (i6 != idx) {
      emlrtSubAssignSizeCheck1dR2017a(i6, idx, (emlrtECInfo *)&g_emlrtECI, &st);
    }

    for (i6 = 0; i6 < idx; i6++) {
      x_init->data[(i7 + i6) - 1] = 0;
    }
  }

  emxInit_real_T(&st, &Theta_el, 2, &ub_emlrtRTEI, true);
  st.site = &xb_emlrtRSI;

  /*  y = [ x(:)', x(:)', ..., x(:)' ]; such that y is [1,N] vector */
  loop_ub = A->size[1];
  i6 = Theta_el->size[0] * Theta_el->size[1];
  Theta_el->size[0] = 1;
  Theta_el->size[1] = loop_ub;
  emxEnsureCapacity_real_T(&st, Theta_el, i6, &ub_emlrtRTEI);
  for (i6 = 0; i6 < loop_ub; i6++) {
    Theta_el->data[i6] = 0.0;
  }

  loop_ub = A->size[1];
  if (loop_ub <= 1) {
    i6 = A->size[1];
    if (1 > i6) {
      loop_ub = 0;
    } else {
      i6 = A->size[1];
      if (!((i6 >= 1) && (i6 <= 1))) {
        emlrtDynamicBoundsCheckR2012b(i6, 1, 1, (emlrtBCInfo *)&ub_emlrtBCI, &st);
      }

      loop_ub = 1;
    }

    i6 = Theta_el->size[0] * Theta_el->size[1];
    Theta_el->size[0] = 1;
    Theta_el->size[1] = loop_ub;
    emxEnsureCapacity_real_T(&st, Theta_el, i6, &ub_emlrtRTEI);
    for (i6 = 0; i6 < loop_ub; i6++) {
      Theta_el->data[i6] = Theta;
    }
  } else {
    i6 = A->size[1];
    if (!(1 <= i6)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i6, (emlrtBCInfo *)&wb_emlrtBCI, &st);
    }

    i6 = A->size[1];
    if (!(loop_ub <= i6)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i6, (emlrtBCInfo *)&xb_emlrtBCI,
        &st);
    }

    b_st.site = &dc_emlrtRSI;
    c_st.site = &u_emlrtRSI;
    b_assertValidSizeArg(&c_st, (real_T)loop_ub);
    for (i6 = 0; i6 < loop_ub; i6++) {
      Theta_el->data[i6] = Theta;
    }

    i6 = A->size[1];
    i6 -= loop_ub;
    if (1 > i6) {
      idx = 0;
    } else {
      if (!(i6 <= 1)) {
        emlrtDynamicBoundsCheckR2012b(i6, 1, 1, (emlrtBCInfo *)&vb_emlrtBCI, &st);
      }

      idx = 1;
    }

    i6 = A->size[1];
    if (loop_ub + 1U > (uint32_T)i6) {
      i7 = 1;
      i6 = 1;
    } else {
      i6 = Theta_el->size[1];
      i7 = (int32_T)(loop_ub + 1U);
      if (!((i7 >= 1) && (i7 <= i6))) {
        emlrtDynamicBoundsCheckR2012b(i7, 1, i6, (emlrtBCInfo *)&yb_emlrtBCI,
          &st);
      }

      i6 = A->size[1];
      vlen = Theta_el->size[1];
      if (!((i6 >= 1) && (i6 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i6, 1, vlen, (emlrtBCInfo *)&ac_emlrtBCI,
          &st);
      }

      i6++;
    }

    i6 -= i7;
    if (i6 != idx) {
      emlrtSubAssignSizeCheck1dR2017a(i6, idx, (emlrtECInfo *)&g_emlrtECI, &st);
    }

    for (i6 = 0; i6 < idx; i6++) {
      Theta_el->data[(i7 + i6) - 1] = Theta;
    }
  }

  st.site = &yb_emlrtRSI;
  i6 = A->size[1];
  b_st.site = &u_emlrtRSI;
  b_assertValidSizeArg(&b_st, (real_T)i6);
  loop_ub = A->size[1];
  i6 = A->size[1];
  if (loop_ub != i6) {
    y = NULL;
    m2 = emlrtCreateCharArray(2, iv7);
    emlrtInitCharArrayR2013a(&st, 15, m2, &cv0[0]);
    emlrtAssign(&y, m2);
    b_st.site = &me_emlrtRSI;
    d_error(&b_st, y, (emlrtMCInfo *)&emlrtMCI);
  }

  emxInit_struct_T1(&st, &r6, 2, &vb_emlrtRTEI, true);
  i6 = r6->size[0] * r6->size[1];
  r6->size[0] = 1;
  r6->size[1] = loop_ub;
  emxEnsureCapacity_struct_T(sp, r6, i6, &vb_emlrtRTEI);
  for (i6 = 0; i6 < loop_ub; i6++) {
    r6->data[i6] = r7;
  }

  cast(sp, r6, nodes);
  j = 1;
  emxFree_struct_T1(&r6);
  emxInit_int32_T(sp, &ind, 1, &wb_emlrtRTEI, true);
  emxInit_int32_T(sp, &ii, 1, &cc_emlrtRTEI, true);
  emxInit_real_T1(sp, &x, 1, &dc_emlrtRTEI, true);
  if (0 <= i5 - 1) {
    nx = A->size[0];
    i8 = A->size[0];
    i6 = A->size[0];
    i9 = A->size[0];
    i10 = A->size[0];
    b_A = A->size[0];
    c_A = A->size[0];
    d_A = A->size[0];
    if (1 > i6) {
      overflow = false;
    } else {
      i6 = A->size[0];
      overflow = (i6 > 2147483646);
    }
  }

  while (j - 1 <= i5 - 1) {
    st.site = &ac_emlrtRSI;
    i6 = A->size[1];
    i7 = (j - 1) + 1;
    if (!((i7 >= 1) && (i7 <= i6))) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, i6, (emlrtBCInfo *)&gc_emlrtBCI, &st);
    }

    b_st.site = &ec_emlrtRSI;
    idx = 0;
    i6 = ii->size[0];
    ii->size[0] = i8;
    emxEnsureCapacity_int32_T1(&b_st, ii, i6, &r_emlrtRTEI);
    c_st.site = &fc_emlrtRSI;
    if (overflow) {
      d_st.site = &y_emlrtRSI;
      e_st.site = &y_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    vlen = 1;
    exitg1 = false;
    while ((!exitg1) && (vlen <= nx)) {
      if (A->data[(vlen + A->size[0] * (j - 1)) - 1] != 0.0) {
        idx++;
        ii->data[idx - 1] = vlen;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          vlen++;
        }
      } else {
        vlen++;
      }
    }

    if (!(idx <= i9)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &nd_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (i10 == 1) {
      if (idx == 0) {
        i6 = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity_int32_T1(&b_st, ii, i6, &t_emlrtRTEI);
      }
    } else {
      if (1 > idx) {
        i6 = 0;
      } else {
        i6 = idx;
      }

      c_st.site = &gc_emlrtRSI;
      nonSingletonDimFound = !(ii->size[0] != 1);
      if (nonSingletonDimFound) {
        nonSingletonDimFound = false;
        if (i6 != 1) {
          nonSingletonDimFound = true;
        }

        if (nonSingletonDimFound) {
          nonSingletonDimFound = true;
        } else {
          nonSingletonDimFound = false;
        }
      } else {
        nonSingletonDimFound = false;
      }

      d_st.site = &hc_emlrtRSI;
      if (nonSingletonDimFound) {
        emlrtErrorWithMessageIdR2012b(&d_st, &md_emlrtRTEI,
          "Coder:FE:PotentialVectorVector", 0);
      }

      i7 = ii->size[0];
      ii->size[0] = i6;
      emxEnsureCapacity_int32_T1(&b_st, ii, i7, &t_emlrtRTEI);
    }

    i6 = ind->size[0];
    ind->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T1(&st, ind, i6, &wb_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      ind->data[i6] = ii->data[i6];
    }

    st.site = &bc_emlrtRSI;
    loop_ub = ind->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      i7 = ind->data[i6];
      if (!((i7 >= 1) && (i7 <= b_A))) {
        emlrtDynamicBoundsCheckR2012b(i7, 1, b_A, (emlrtBCInfo *)&ic_emlrtBCI,
          &st);
      }
    }

    i6 = A->size[1];
    i7 = (j - 1) + 1;
    if (!((i7 >= 1) && (i7 <= i6))) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, i6, (emlrtBCInfo *)&fc_emlrtBCI, &st);
    }

    i6 = x->size[0];
    x->size[0] = ind->size[0];
    emxEnsureCapacity_real_T1(&st, x, i6, &xb_emlrtRTEI);
    loop_ub = ind->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      x->data[i6] = A->data[(ind->data[i6] + A->size[0] * (j - 1)) - 1];
    }

    b_st.site = &ic_emlrtRSI;
    b_sort(&b_st, x, ii);
    i6 = x->size[0];
    x->size[0] = ii->size[0];
    emxEnsureCapacity_real_T1(&st, x, i6, &yb_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      x->data[i6] = ii->data[i6];
    }

    /*  sorting connections from the heaviest to the lightest */
    i6 = x_init->size[1];
    i7 = (j - 1) + 1;
    if (!((i7 >= 1) && (i7 <= i6))) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, i6, (emlrtBCInfo *)&ec_emlrtBCI, sp);
    }

    i6 = nodes->size[1];
    if (!((j >= 1) && (j <= i6))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i6, (emlrtBCInfo *)&jc_emlrtBCI, sp);
    }

    nodes->data[j - 1].x = 0.0;
    vlen = ind->size[0];
    idx = nodes->size[1];
    if (!((j >= 1) && (j <= idx))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&kc_emlrtBCI, sp);
    }

    i6 = nodes->data[j - 1].neigh->size[0];
    nodes->data[j - 1].neigh->size[0] = x->size[0];
    emxEnsureCapacity_real_T1(sp, nodes->data[j - 1].neigh, i6, &ac_emlrtRTEI);
    loop_ub = x->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      i7 = (int32_T)x->data[i6];
      if (!((i7 >= 1) && (i7 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i7, 1, vlen, (emlrtBCInfo *)&lc_emlrtBCI,
          sp);
      }

      if (!((j >= 1) && (j <= idx))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&kc_emlrtBCI, sp);
      }

      nodes->data[j - 1].neigh->data[i6] = ind->data[i7 - 1];
    }

    vlen = ind->size[0];
    i6 = A->size[1];
    if (!((j >= 1) && (j <= i6))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i6, (emlrtBCInfo *)&dc_emlrtBCI, sp);
    }

    idx = nodes->size[1];
    if (!((j >= 1) && (j <= idx))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&mc_emlrtBCI, sp);
    }

    i6 = nodes->data[j - 1].w->size[0];
    nodes->data[j - 1].w->size[0] = x->size[0];
    emxEnsureCapacity_real_T1(sp, nodes->data[j - 1].w, i6, &bc_emlrtRTEI);
    loop_ub = x->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      i7 = (int32_T)x->data[i6];
      if (!((i7 >= 1) && (i7 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i7, 1, vlen, (emlrtBCInfo *)&oc_emlrtBCI,
          sp);
      }

      i7 = ind->data[i7 - 1];
      if (!((i7 >= 1) && (i7 <= c_A))) {
        emlrtDynamicBoundsCheckR2012b(i7, 1, c_A, (emlrtBCInfo *)&nc_emlrtBCI,
          sp);
      }

      if (!((j >= 1) && (j <= idx))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&mc_emlrtBCI, sp);
      }

      nodes->data[j - 1].w->data[i6] = A->data[(i7 + A->size[0] * (j - 1)) - 1];
    }

    st.site = &cc_emlrtRSI;
    loop_ub = ind->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      i7 = ind->data[i6];
      if (!((i7 >= 1) && (i7 <= d_A))) {
        emlrtDynamicBoundsCheckR2012b(i7, 1, d_A, (emlrtBCInfo *)&pc_emlrtBCI,
          &st);
      }
    }

    i6 = A->size[1];
    i7 = (j - 1) + 1;
    if (!((i7 >= 1) && (i7 <= i6))) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, i6, (emlrtBCInfo *)&bc_emlrtBCI, &st);
    }

    b_st.site = &od_emlrtRSI;
    if ((ind->size[0] == 1) || (ind->size[0] != 1)) {
      nonSingletonDimFound = true;
    } else {
      nonSingletonDimFound = false;
    }

    if (!nonSingletonDimFound) {
      emlrtErrorWithMessageIdR2012b(&b_st, &ld_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    c_st.site = &pd_emlrtRSI;
    vlen = ind->size[0];
    if (ind->size[0] == 0) {
      b_y = 0.0;
    } else {
      d_st.site = &qd_emlrtRSI;
      b_y = A->data[(ind->data[0] + A->size[0] * (j - 1)) - 1];
      e_st.site = &rd_emlrtRSI;
      nonSingletonDimFound = ((!(2 > ind->size[0])) && (ind->size[0] >
        2147483646));
      if (nonSingletonDimFound) {
        f_st.site = &y_emlrtRSI;
        g_st.site = &y_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }

      for (idx = 2; idx <= vlen; idx++) {
        b_y += A->data[(ind->data[idx - 1] + A->size[0] * (j - 1)) - 1];
      }
    }

    i6 = Theta_el->size[1];
    i7 = (j - 1) + 1;
    if (!((i7 >= 1) && (i7 <= i6))) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, i6, (emlrtBCInfo *)&cc_emlrtBCI, sp);
    }

    /*  Iext -> external current used to initially excite a given node */
    /*  Isyn -> sum of weighted inputs over node i; i.e. sum of w_ij * s_j */
    /*  kInp -> (only for multiple seeds) the state towards which node i must be updated (can be from 1 to nInp) */
    /*  Theta -> the element threshold for firing */
    /*  W -> total input weight over node i */
    /*  n -> number of inputs over node i */
    /*  nInp -> total number of possible states */
    /*  s -> cumulative time it took for node i to get activated during spreading time simulation (summing up all times from the initial seed stimulation) */
    i6 = nodes->size[1];
    if (!((j >= 1) && (j <= i6))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i6, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.Iext = 0.0;
    i6 = nodes->size[1];
    if (!((j >= 1) && (j <= i6))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i6, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.Isyn = 0.0;
    i6 = nodes->size[1];
    if (!((j >= 1) && (j <= i6))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i6, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.kInp = 0.0;
    i6 = nodes->size[1];
    if (!((j >= 1) && (j <= i6))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i6, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.Theta = Theta_el->data[j - 1];
    i6 = nodes->size[1];
    if (!((j >= 1) && (j <= i6))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i6, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.W = b_y;
    i6 = nodes->size[1];
    if (!((j >= 1) && (j <= i6))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i6, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.n = ind->size[0];
    i6 = nodes->size[1];
    if (!((j >= 1) && (j <= i6))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i6, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.nInp = nSeeds;
    i6 = nodes->size[1];
    if (!((j >= 1) && (j <= i6))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i6, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.spTime = 0.0;
    i6 = nodes->size[1];
    if (!((j >= 1) && (j <= i6))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i6, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    i6 = nodes->size[1];
    if (!((j >= 1) && (j <= i6))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i6, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    j++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&x);
  emxFree_int32_T(&ii);
  emxFree_int32_T(&ind);
  emxFree_real_T(&Theta_el);
  emxFree_int8_T(&x_init);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (GetNodes.cpp) */
