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
#include "FindBestFunctionalMatch.h"
#include "GetNodes.h"
#include "FindBestFunctionalMatch_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sort1.h"
#include "assertValidSizeArg.h"
#include "repeatToComplete.h"
#include "FindBestFunctionalMatch_mexutil.h"
#include "FindBestFunctionalMatch_data.h"

/* Type Definitions */
typedef struct {
  real_T x;
  struct_T par;
} c_struct_T;

/* Variable Definitions */
static emlrtRSInfo eb_emlrtRSI = { 15, /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 16, /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 17, /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 20, /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 21, /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 25, /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 44, /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 234,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 253,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 18, /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 26, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 9,  /* lineNo */
  "sum",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 58, /* lineNo */
  "sumprod",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

static emlrtRSInfo bd_emlrtRSI = { 106,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 166,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 15,/* lineNo */
  31,                                  /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = { 17,/* lineNo */
  5,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 44,/* lineNo */
  10,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 20,/* lineNo */
  9,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 26,/* lineNo */
  6,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 27,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = { 23,/* lineNo */
  9,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = { 24,/* lineNo */
  9,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = { 15,/* lineNo */
  5,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = { 36,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = { 1,/* lineNo */
  18,                                  /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  17,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  24,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  28,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  29,                                  /* colNo */
  "x_init",                            /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  31,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  59,                                  /* colNo */
  "Theta_el",                          /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  73,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { 1,  /* iFirst */
  1,                                   /* iLast */
  12,                                  /* lineNo */
  25,                                  /* colNo */
  "x",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { 1,  /* iFirst */
  1,                                   /* iLast */
  8,                                   /* lineNo */
  17,                                  /* colNo */
  "x",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo cd_emlrtRTEI = { 243,/* lineNo */
  9,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = { 88,/* lineNo */
  9,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = { 20,/* lineNo */
  15,                                  /* colNo */
  "sumprod",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pName */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  24,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  30,                                  /* colNo */
  "ind",                               /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  24,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  28,                                  /* colNo */
  "ind",                               /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  69,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void GetNodes(const emlrtStack *sp, const emxArray_real_T *A, real_T Theta,
              const emxArray_real_T *x0, real_T nSeeds, emxArray_struct_T *nodes)
{
  emxArray_real_T *b_x0;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T loop_ub;
  emxArray_real_T *x_init;
  emxArray_real_T *Theta_el;
  int32_T idx;
  const mxArray *y;
  const mxArray *m3;
  static const int32_T iv6[2] = { 1, 15 };

  int32_T vlen;
  int32_T j;
  emxArray_int32_T *ind;
  emxArray_int32_T *ii;
  emxArray_real_T *x;
  int32_T nx;
  int32_T i6;
  static const c_struct_T r6 = { 0.0,  /* x */
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

  int32_T i7;
  int32_T i8;
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
  emxInit_real_T(sp, &b_x0, 2, &pb_emlrtRTEI, true);

  /*  A       -> [N,N] adjacency matrix (either weighted or binary) */
  /*  Theta   -> [1,1] to [1,N] vector activation threshold; if a vector is provided, each element has Theta(i) activation Threshold */
  /*  x0      -> [1,1] to [1,N] initial condition; if a vector is provided, each element has ic x0(i) */
  i3 = A->size[0];
  if (!(1 <= i3)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i3, (emlrtBCInfo *)&tb_emlrtBCI, sp);
  }

  i3 = A->size[1];
  i4 = A->size[1];
  i5 = b_x0->size[0] * b_x0->size[1];
  b_x0->size[0] = 1;
  b_x0->size[1] = x0->size[1];
  emxEnsureCapacity_real_T(sp, b_x0, i5, &pb_emlrtRTEI);
  loop_ub = x0->size[0] * x0->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    b_x0->data[i5] = x0->data[i5];
  }

  emxInit_real_T(sp, &x_init, 2, &ac_emlrtRTEI, true);
  emxInit_real_T(sp, &Theta_el, 2, &qb_emlrtRTEI, true);
  st.site = &eb_emlrtRSI;
  repeatToComplete(&st, b_x0, (real_T)i4, x_init);
  st.site = &fb_emlrtRSI;

  /*  y = [ x(:)', x(:)', ..., x(:)' ]; such that y is [1,N] vector */
  loop_ub = A->size[1];
  i4 = Theta_el->size[0] * Theta_el->size[1];
  Theta_el->size[0] = 1;
  Theta_el->size[1] = loop_ub;
  emxEnsureCapacity_real_T(&st, Theta_el, i4, &qb_emlrtRTEI);
  emxFree_real_T(&b_x0);
  for (i4 = 0; i4 < loop_ub; i4++) {
    Theta_el->data[i4] = 0.0;
  }

  loop_ub = A->size[1];
  if (loop_ub <= 1) {
    i4 = A->size[1];
    if (1 > i4) {
      loop_ub = 0;
    } else {
      i4 = A->size[1];
      if (!((i4 >= 1) && (i4 <= 1))) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, 1, (emlrtBCInfo *)&gc_emlrtBCI, &st);
      }

      loop_ub = 1;
    }

    i4 = Theta_el->size[0] * Theta_el->size[1];
    Theta_el->size[0] = 1;
    Theta_el->size[1] = loop_ub;
    emxEnsureCapacity_real_T(&st, Theta_el, i4, &qb_emlrtRTEI);
    for (i4 = 0; i4 < loop_ub; i4++) {
      Theta_el->data[i4] = Theta;
    }
  } else {
    i4 = A->size[1];
    if (!(1 <= i4)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i4, (emlrtBCInfo *)&ec_emlrtBCI, &st);
    }

    i4 = A->size[1];
    if (!(loop_ub <= i4)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i4, (emlrtBCInfo *)&dc_emlrtBCI,
        &st);
    }

    b_st.site = &kb_emlrtRSI;
    c_st.site = &lb_emlrtRSI;
    assertValidSizeArg(&c_st, (real_T)loop_ub);
    for (i4 = 0; i4 < loop_ub; i4++) {
      Theta_el->data[i4] = Theta;
    }

    i4 = A->size[1];
    i4 -= loop_ub;
    if (1 > i4) {
      idx = 0;
    } else {
      if (!(i4 <= 1)) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, 1, (emlrtBCInfo *)&fc_emlrtBCI, &st);
      }

      idx = 1;
    }

    i4 = A->size[1];
    if (loop_ub + 1U > (uint32_T)i4) {
      i4 = 0;
      i5 = 0;
    } else {
      i4 = Theta_el->size[1];
      i5 = (int32_T)(loop_ub + 1U);
      if (!((i5 >= 1) && (i5 <= i4))) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, (emlrtBCInfo *)&cc_emlrtBCI,
          &st);
      }

      i4 = i5 - 1;
      i5 = A->size[1];
      vlen = Theta_el->size[1];
      if (!((i5 >= 1) && (i5 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, vlen, (emlrtBCInfo *)&bc_emlrtBCI,
          &st);
      }
    }

    i5 -= i4;
    if (i5 != idx) {
      emlrtSubAssignSizeCheck1dR2017a(i5, idx, (emlrtECInfo *)&b_emlrtECI, &st);
    }

    for (i5 = 0; i5 < idx; i5++) {
      Theta_el->data[i4 + i5] = Theta;
    }
  }

  st.site = &gb_emlrtRSI;
  i4 = A->size[1];
  b_st.site = &lb_emlrtRSI;
  assertValidSizeArg(&b_st, (real_T)i4);
  i4 = A->size[1];
  i5 = A->size[1];
  if (i4 != i5) {
    y = NULL;
    m3 = emlrtCreateCharArray(2, iv6);
    emlrtInitCharArrayR2013a(&st, 15, m3, &cv0[0]);
    emlrtAssign(&y, m3);
    b_st.site = &md_emlrtRSI;
    error(&b_st, y, (emlrtMCInfo *)&b_emlrtMCI);
  }

  i5 = nodes->size[0] * nodes->size[1];
  nodes->size[0] = 1;
  emxEnsureCapacity_struct_T(sp, nodes, i5, &rb_emlrtRTEI);
  i5 = nodes->size[0] * nodes->size[1];
  nodes->size[1] = i4;
  emxEnsureCapacity_struct_T(sp, nodes, i5, &rb_emlrtRTEI);
  j = 0;
  while (j < i4) {
    nodes->data[j].x = 0.0;
    i5 = nodes->data[j].neigh->size[0];
    nodes->data[j].neigh->size[0] = 0;
    emxEnsureCapacity_real_T1(sp, nodes->data[j].neigh, i5, &rb_emlrtRTEI);
    i5 = nodes->data[j].w->size[0];
    nodes->data[j].w->size[0] = 0;
    emxEnsureCapacity_real_T1(sp, nodes->data[j].w, i5, &rb_emlrtRTEI);
    nodes->data[j].par = r6.par;
    j++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  j = 1;
  emxInit_int32_T(sp, &ind, 1, &ub_emlrtRTEI, true);
  emxInit_int32_T(sp, &ii, 1, &bc_emlrtRTEI, true);
  emxInit_real_T1(sp, &x, 1, &cc_emlrtRTEI, true);
  if (0 <= i3 - 1) {
    nx = A->size[0];
    i6 = A->size[0];
    i4 = A->size[0];
    i7 = A->size[0];
    i8 = A->size[0];
    b_A = A->size[0];
    c_A = A->size[0];
    d_A = A->size[0];
    if (1 > i4) {
      overflow = false;
    } else {
      i4 = A->size[0];
      overflow = (i4 > 2147483646);
    }
  }

  while (j - 1 <= i3 - 1) {
    st.site = &hb_emlrtRSI;
    i4 = A->size[1];
    i5 = (j - 1) + 1;
    if (!((i5 >= 1) && (i5 <= i4))) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, i4, (emlrtBCInfo *)&ub_emlrtBCI, &st);
    }

    b_st.site = &ob_emlrtRSI;
    idx = 0;
    i4 = ii->size[0];
    ii->size[0] = i6;
    emxEnsureCapacity_int32_T(&b_st, ii, i4, &sb_emlrtRTEI);
    c_st.site = &pb_emlrtRSI;
    if (overflow) {
      d_st.site = &k_emlrtRSI;
      e_st.site = &k_emlrtRSI;
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

    if (!(idx <= i7)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &cd_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (i8 == 1) {
      if (idx == 0) {
        i4 = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity_int32_T(&b_st, ii, i4, &tb_emlrtRTEI);
      }
    } else {
      if (1 > idx) {
        i4 = 0;
      } else {
        i4 = idx;
      }

      c_st.site = &qb_emlrtRSI;
      nonSingletonDimFound = !(ii->size[0] != 1);
      if (nonSingletonDimFound) {
        nonSingletonDimFound = false;
        if (i4 != 1) {
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

      d_st.site = &rb_emlrtRSI;
      if (nonSingletonDimFound) {
        emlrtErrorWithMessageIdR2012b(&d_st, &dd_emlrtRTEI,
          "Coder:FE:PotentialVectorVector", 0);
      }

      i5 = ii->size[0];
      ii->size[0] = i4;
      emxEnsureCapacity_int32_T(&b_st, ii, i5, &tb_emlrtRTEI);
    }

    i4 = ind->size[0];
    ind->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&st, ind, i4, &ub_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      ind->data[i4] = ii->data[i4];
    }

    st.site = &ib_emlrtRSI;
    loop_ub = ind->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      i5 = ind->data[i4];
      if (!((i5 >= 1) && (i5 <= b_A))) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, b_A, (emlrtBCInfo *)&hc_emlrtBCI,
          &st);
      }
    }

    i4 = A->size[1];
    i5 = (j - 1) + 1;
    if (!((i5 >= 1) && (i5 <= i4))) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, i4, (emlrtBCInfo *)&vb_emlrtBCI, &st);
    }

    i4 = x->size[0];
    x->size[0] = ind->size[0];
    emxEnsureCapacity_real_T1(&st, x, i4, &vb_emlrtRTEI);
    loop_ub = ind->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      x->data[i4] = A->data[(ind->data[i4] + A->size[0] * (j - 1)) - 1];
    }

    b_st.site = &sb_emlrtRSI;
    sort(&b_st, x, ii);
    i4 = x->size[0];
    x->size[0] = ii->size[0];
    emxEnsureCapacity_real_T1(&st, x, i4, &wb_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      x->data[i4] = ii->data[i4];
    }

    /*  sorting connections from the heaviest to the lightest */
    i4 = x_init->size[1];
    i5 = (j - 1) + 1;
    if (!((i5 >= 1) && (i5 <= i4))) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, i4, (emlrtBCInfo *)&wb_emlrtBCI, sp);
    }

    i4 = nodes->size[1];
    if (!((j >= 1) && (j <= i4))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i4, (emlrtBCInfo *)&ic_emlrtBCI, sp);
    }

    nodes->data[j - 1].x = 0.0;
    vlen = ind->size[0];
    idx = nodes->size[1];
    if (!((j >= 1) && (j <= idx))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&jc_emlrtBCI, sp);
    }

    i4 = nodes->data[j - 1].neigh->size[0];
    nodes->data[j - 1].neigh->size[0] = x->size[0];
    emxEnsureCapacity_real_T1(sp, nodes->data[j - 1].neigh, i4, &xb_emlrtRTEI);
    loop_ub = x->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      i5 = (int32_T)x->data[i4];
      if (!((i5 >= 1) && (i5 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, vlen, (emlrtBCInfo *)&kc_emlrtBCI,
          sp);
      }

      if (!((j >= 1) && (j <= idx))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&jc_emlrtBCI, sp);
      }

      nodes->data[j - 1].neigh->data[i4] = ind->data[i5 - 1];
    }

    vlen = ind->size[0];
    i4 = A->size[1];
    if (!((j >= 1) && (j <= i4))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i4, (emlrtBCInfo *)&xb_emlrtBCI, sp);
    }

    idx = nodes->size[1];
    if (!((j >= 1) && (j <= idx))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&lc_emlrtBCI, sp);
    }

    i4 = nodes->data[j - 1].w->size[0];
    nodes->data[j - 1].w->size[0] = x->size[0];
    emxEnsureCapacity_real_T1(sp, nodes->data[j - 1].w, i4, &yb_emlrtRTEI);
    loop_ub = x->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      i5 = (int32_T)x->data[i4];
      if (!((i5 >= 1) && (i5 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, vlen, (emlrtBCInfo *)&nc_emlrtBCI,
          sp);
      }

      i5 = ind->data[i5 - 1];
      if (!((i5 >= 1) && (i5 <= c_A))) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, c_A, (emlrtBCInfo *)&mc_emlrtBCI,
          sp);
      }

      if (!((j >= 1) && (j <= idx))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&lc_emlrtBCI, sp);
      }

      nodes->data[j - 1].w->data[i4] = A->data[(i5 + A->size[0] * (j - 1)) - 1];
    }

    st.site = &jb_emlrtRSI;
    loop_ub = ind->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      i5 = ind->data[i4];
      if (!((i5 >= 1) && (i5 <= d_A))) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, d_A, (emlrtBCInfo *)&oc_emlrtBCI,
          &st);
      }
    }

    i4 = A->size[1];
    i5 = (j - 1) + 1;
    if (!((i5 >= 1) && (i5 <= i4))) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, i4, (emlrtBCInfo *)&ac_emlrtBCI, &st);
    }

    b_st.site = &yc_emlrtRSI;
    if ((ind->size[0] == 1) || (ind->size[0] != 1)) {
      nonSingletonDimFound = true;
    } else {
      nonSingletonDimFound = false;
    }

    if (!nonSingletonDimFound) {
      emlrtErrorWithMessageIdR2012b(&b_st, &ed_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    c_st.site = &ad_emlrtRSI;
    vlen = ind->size[0];
    if (ind->size[0] == 0) {
      b_y = 0.0;
    } else {
      d_st.site = &bd_emlrtRSI;
      b_y = A->data[(ind->data[0] + A->size[0] * (j - 1)) - 1];
      e_st.site = &cd_emlrtRSI;
      nonSingletonDimFound = ((!(2 > ind->size[0])) && (ind->size[0] >
        2147483646));
      if (nonSingletonDimFound) {
        f_st.site = &k_emlrtRSI;
        g_st.site = &k_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }

      for (idx = 2; idx <= vlen; idx++) {
        b_y += A->data[(ind->data[idx - 1] + A->size[0] * (j - 1)) - 1];
      }
    }

    i4 = Theta_el->size[1];
    i5 = (j - 1) + 1;
    if (!((i5 >= 1) && (i5 <= i4))) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, i4, (emlrtBCInfo *)&yb_emlrtBCI, sp);
    }

    /*  Iext -> external current used to initially excite a given node */
    /*  Isyn -> sum of weighted inputs over node i; i.e. sum of w_ij * s_j */
    /*  kInp -> (only for multiple seeds) the state towards which node i must be updated (can be from 1 to nInp) */
    /*  Theta -> the element threshold for firing */
    /*  W -> total input weight over node i */
    /*  n -> number of inputs over node i */
    /*  nInp -> total number of possible states */
    /*  s -> cumulative time it took for node i to get activated during spreading time simulation (summing up all times from the initial seed stimulation) */
    i4 = nodes->size[1];
    if (!((j >= 1) && (j <= i4))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i4, (emlrtBCInfo *)&pc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.Iext = 0.0;
    i4 = nodes->size[1];
    if (!((j >= 1) && (j <= i4))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i4, (emlrtBCInfo *)&pc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.Isyn = 0.0;
    i4 = nodes->size[1];
    if (!((j >= 1) && (j <= i4))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i4, (emlrtBCInfo *)&pc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.kInp = 0.0;
    i4 = nodes->size[1];
    if (!((j >= 1) && (j <= i4))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i4, (emlrtBCInfo *)&pc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.Theta = Theta_el->data[j - 1];
    i4 = nodes->size[1];
    if (!((j >= 1) && (j <= i4))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i4, (emlrtBCInfo *)&pc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.W = b_y;
    i4 = nodes->size[1];
    if (!((j >= 1) && (j <= i4))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i4, (emlrtBCInfo *)&pc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.n = ind->size[0];
    i4 = nodes->size[1];
    if (!((j >= 1) && (j <= i4))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i4, (emlrtBCInfo *)&pc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.nInp = nSeeds;
    i4 = nodes->size[1];
    if (!((j >= 1) && (j <= i4))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i4, (emlrtBCInfo *)&pc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.spTime = 0.0;
    i4 = nodes->size[1];
    if (!((j >= 1) && (j <= i4))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i4, (emlrtBCInfo *)&pc_emlrtBCI, sp);
    }

    i4 = nodes->size[1];
    if (!((j >= 1) && (j <= i4))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i4, (emlrtBCInfo *)&pc_emlrtBCI, sp);
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
  emxFree_real_T(&x_init);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (GetNodes.cpp) */
