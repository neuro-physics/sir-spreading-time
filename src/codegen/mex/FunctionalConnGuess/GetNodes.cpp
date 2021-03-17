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
#include "FunctionalConnGuess.h"
#include "GetNodes.h"
#include "FunctionalConnGuess_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sort1.h"
#include "assertValidSizeArg.h"
#include "repeatToComplete.h"
#include "FunctionalConnGuess_mexutil.h"
#include "FunctionalConnGuess_data.h"

/* Type Definitions */
typedef struct {
  real_T x;
  struct_T par;
} c_struct_T;

/* Variable Definitions */
static emlrtRSInfo j_emlrtRSI = { 15,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 16,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 17,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 20,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 21,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 25,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 44,  /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 234, /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 253, /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 18,  /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 26,  /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 9,  /* lineNo */
  "sum",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 58, /* lineNo */
  "sumprod",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 106,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 166,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRTEInfo u_emlrtRTEI = { 15,/* lineNo */
  31,                                  /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 17,/* lineNo */
  5,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 44,/* lineNo */
  10,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 20,/* lineNo */
  9,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 26,/* lineNo */
  6,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 27,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 23,/* lineNo */
  9,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 24,/* lineNo */
  9,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 15,/* lineNo */
  5,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 36,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 1,/* lineNo */
  18,                                  /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  17,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  24,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  28,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  29,                                  /* colNo */
  "x_init",                            /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  31,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  59,                                  /* colNo */
  "Theta_el",                          /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  73,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { 1,  /* iFirst */
  1,                                   /* iLast */
  12,                                  /* lineNo */
  25,                                  /* colNo */
  "x",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { 1,  /* iFirst */
  1,                                   /* iLast */
  8,                                   /* lineNo */
  17,                                  /* colNo */
  "x",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo dc_emlrtRTEI = { 243,/* lineNo */
  9,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = { 88,/* lineNo */
  9,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = { 20,/* lineNo */
  15,                                  /* colNo */
  "sumprod",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pName */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  24,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  30,                                  /* colNo */
  "ind",                               /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  24,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  28,                                  /* colNo */
  "ind",                               /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  69,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
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
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T loop_ub;
  emxArray_real_T *x_init;
  emxArray_real_T *Theta_el;
  int32_T idx;
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv1[2] = { 1, 15 };

  int32_T vlen;
  int32_T j;
  emxArray_int32_T *ind;
  emxArray_int32_T *ii;
  emxArray_real_T *x;
  int32_T nx;
  int32_T i5;
  static const c_struct_T r3 = { 0.0,  /* x */
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

  int32_T i6;
  int32_T i7;
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
  emxInit_real_T1(sp, &b_x0, 2, &u_emlrtRTEI, true);

  /*  A       -> [N,N] adjacency matrix (either weighted or binary) */
  /*  Theta   -> [1,1] to [1,N] vector activation threshold; if a vector is provided, each element has Theta(i) activation Threshold */
  /*  x0      -> [1,1] to [1,N] initial condition; if a vector is provided, each element has ic x0(i) */
  i2 = A->size[0];
  if (!(1 <= i2)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i2, (emlrtBCInfo *)&mb_emlrtBCI, sp);
  }

  i2 = A->size[1];
  i3 = A->size[1];
  i4 = b_x0->size[0] * b_x0->size[1];
  b_x0->size[0] = 1;
  b_x0->size[1] = x0->size[1];
  emxEnsureCapacity_real_T(sp, b_x0, i4, &u_emlrtRTEI);
  loop_ub = x0->size[0] * x0->size[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_x0->data[i4] = x0->data[i4];
  }

  emxInit_real_T1(sp, &x_init, 2, &fb_emlrtRTEI, true);
  emxInit_real_T1(sp, &Theta_el, 2, &v_emlrtRTEI, true);
  st.site = &j_emlrtRSI;
  repeatToComplete(&st, b_x0, (real_T)i3, x_init);
  st.site = &k_emlrtRSI;

  /*  y = [ x(:)', x(:)', ..., x(:)' ]; such that y is [1,N] vector */
  loop_ub = A->size[1];
  i3 = Theta_el->size[0] * Theta_el->size[1];
  Theta_el->size[0] = 1;
  Theta_el->size[1] = loop_ub;
  emxEnsureCapacity_real_T(&st, Theta_el, i3, &v_emlrtRTEI);
  emxFree_real_T(&b_x0);
  for (i3 = 0; i3 < loop_ub; i3++) {
    Theta_el->data[i3] = 0.0;
  }

  loop_ub = A->size[1];
  if (loop_ub <= 1) {
    i3 = A->size[1];
    if (1 > i3) {
      loop_ub = 0;
    } else {
      i3 = A->size[1];
      if (!((i3 >= 1) && (i3 <= 1))) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, 1, (emlrtBCInfo *)&yb_emlrtBCI, &st);
      }

      loop_ub = 1;
    }

    i3 = Theta_el->size[0] * Theta_el->size[1];
    Theta_el->size[0] = 1;
    Theta_el->size[1] = loop_ub;
    emxEnsureCapacity_real_T(&st, Theta_el, i3, &v_emlrtRTEI);
    for (i3 = 0; i3 < loop_ub; i3++) {
      Theta_el->data[i3] = Theta;
    }
  } else {
    i3 = A->size[1];
    if (!(1 <= i3)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i3, (emlrtBCInfo *)&wb_emlrtBCI, &st);
    }

    i3 = A->size[1];
    if (!(loop_ub <= i3)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i3, (emlrtBCInfo *)&vb_emlrtBCI,
        &st);
    }

    b_st.site = &p_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    assertValidSizeArg(&c_st, (real_T)loop_ub);
    for (i3 = 0; i3 < loop_ub; i3++) {
      Theta_el->data[i3] = Theta;
    }

    i3 = A->size[1];
    i3 -= loop_ub;
    if (1 > i3) {
      idx = 0;
    } else {
      if (!(i3 <= 1)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, 1, (emlrtBCInfo *)&xb_emlrtBCI, &st);
      }

      idx = 1;
    }

    i3 = A->size[1];
    if (loop_ub + 1U > (uint32_T)i3) {
      i3 = 0;
      i4 = 0;
    } else {
      i3 = Theta_el->size[1];
      i4 = (int32_T)(loop_ub + 1U);
      if (!((i4 >= 1) && (i4 <= i3))) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, i3, (emlrtBCInfo *)&ub_emlrtBCI,
          &st);
      }

      i3 = i4 - 1;
      i4 = A->size[1];
      vlen = Theta_el->size[1];
      if (!((i4 >= 1) && (i4 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, vlen, (emlrtBCInfo *)&tb_emlrtBCI,
          &st);
      }
    }

    i4 -= i3;
    if (i4 != idx) {
      emlrtSubAssignSizeCheck1dR2017a(i4, idx, (emlrtECInfo *)&b_emlrtECI, &st);
    }

    for (i4 = 0; i4 < idx; i4++) {
      Theta_el->data[i3 + i4] = Theta;
    }
  }

  st.site = &l_emlrtRSI;
  i3 = A->size[1];
  b_st.site = &q_emlrtRSI;
  assertValidSizeArg(&b_st, (real_T)i3);
  i3 = A->size[1];
  i4 = A->size[1];
  if (i3 != i4) {
    y = NULL;
    m0 = emlrtCreateCharArray(2, iv1);
    emlrtInitCharArrayR2013a(&st, 15, m0, &cv0[0]);
    emlrtAssign(&y, m0);
    b_st.site = &pc_emlrtRSI;
    error(&b_st, y, (emlrtMCInfo *)&emlrtMCI);
  }

  i4 = nodes->size[0] * nodes->size[1];
  nodes->size[0] = 1;
  emxEnsureCapacity_struct_T(sp, nodes, i4, &w_emlrtRTEI);
  i4 = nodes->size[0] * nodes->size[1];
  nodes->size[1] = i3;
  emxEnsureCapacity_struct_T(sp, nodes, i4, &w_emlrtRTEI);
  j = 0;
  while (j < i3) {
    nodes->data[j].x = 0.0;
    i4 = nodes->data[j].neigh->size[0];
    nodes->data[j].neigh->size[0] = 0;
    emxEnsureCapacity_real_T1(sp, nodes->data[j].neigh, i4, &w_emlrtRTEI);
    i4 = nodes->data[j].w->size[0];
    nodes->data[j].w->size[0] = 0;
    emxEnsureCapacity_real_T1(sp, nodes->data[j].w, i4, &w_emlrtRTEI);
    nodes->data[j].par = r3.par;
    j++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  j = 1;
  emxInit_int32_T(sp, &ind, 1, &ab_emlrtRTEI, true);
  emxInit_int32_T(sp, &ii, 1, &gb_emlrtRTEI, true);
  emxInit_real_T(sp, &x, 1, &hb_emlrtRTEI, true);
  if (0 <= i2 - 1) {
    nx = A->size[0];
    i5 = A->size[0];
    i3 = A->size[0];
    i6 = A->size[0];
    i7 = A->size[0];
    b_A = A->size[0];
    c_A = A->size[0];
    d_A = A->size[0];
    if (1 > i3) {
      overflow = false;
    } else {
      i3 = A->size[0];
      overflow = (i3 > 2147483646);
    }
  }

  while (j - 1 <= i2 - 1) {
    st.site = &m_emlrtRSI;
    i3 = A->size[1];
    i4 = (j - 1) + 1;
    if (!((i4 >= 1) && (i4 <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, i3, (emlrtBCInfo *)&nb_emlrtBCI, &st);
    }

    b_st.site = &u_emlrtRSI;
    idx = 0;
    i3 = ii->size[0];
    ii->size[0] = i5;
    emxEnsureCapacity_int32_T(&b_st, ii, i3, &x_emlrtRTEI);
    c_st.site = &v_emlrtRSI;
    if (overflow) {
      d_st.site = &t_emlrtRSI;
      e_st.site = &t_emlrtRSI;
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

    if (!(idx <= i6)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &dc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (i7 == 1) {
      if (idx == 0) {
        i3 = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity_int32_T(&b_st, ii, i3, &y_emlrtRTEI);
      }
    } else {
      if (1 > idx) {
        i3 = 0;
      } else {
        i3 = idx;
      }

      c_st.site = &w_emlrtRSI;
      nonSingletonDimFound = !(ii->size[0] != 1);
      if (nonSingletonDimFound) {
        nonSingletonDimFound = false;
        if (i3 != 1) {
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

      d_st.site = &x_emlrtRSI;
      if (nonSingletonDimFound) {
        emlrtErrorWithMessageIdR2012b(&d_st, &ec_emlrtRTEI,
          "Coder:FE:PotentialVectorVector", 0);
      }

      i4 = ii->size[0];
      ii->size[0] = i3;
      emxEnsureCapacity_int32_T(&b_st, ii, i4, &y_emlrtRTEI);
    }

    i3 = ind->size[0];
    ind->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&st, ind, i3, &ab_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i3 = 0; i3 < loop_ub; i3++) {
      ind->data[i3] = ii->data[i3];
    }

    st.site = &n_emlrtRSI;
    loop_ub = ind->size[0];
    for (i3 = 0; i3 < loop_ub; i3++) {
      i4 = ind->data[i3];
      if (!((i4 >= 1) && (i4 <= b_A))) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, b_A, (emlrtBCInfo *)&ac_emlrtBCI,
          &st);
      }
    }

    i3 = A->size[1];
    i4 = (j - 1) + 1;
    if (!((i4 >= 1) && (i4 <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, i3, (emlrtBCInfo *)&ob_emlrtBCI, &st);
    }

    i3 = x->size[0];
    x->size[0] = ind->size[0];
    emxEnsureCapacity_real_T1(&st, x, i3, &bb_emlrtRTEI);
    loop_ub = ind->size[0];
    for (i3 = 0; i3 < loop_ub; i3++) {
      x->data[i3] = A->data[(ind->data[i3] + A->size[0] * (j - 1)) - 1];
    }

    b_st.site = &y_emlrtRSI;
    sort(&b_st, x, ii);
    i3 = x->size[0];
    x->size[0] = ii->size[0];
    emxEnsureCapacity_real_T1(&st, x, i3, &cb_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i3 = 0; i3 < loop_ub; i3++) {
      x->data[i3] = ii->data[i3];
    }

    /*  sorting connections from the heaviest to the lightest */
    i3 = x_init->size[1];
    i4 = (j - 1) + 1;
    if (!((i4 >= 1) && (i4 <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, i3, (emlrtBCInfo *)&pb_emlrtBCI, sp);
    }

    i3 = nodes->size[1];
    if (!((j >= 1) && (j <= i3))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i3, (emlrtBCInfo *)&bc_emlrtBCI, sp);
    }

    nodes->data[j - 1].x = 0.0;
    vlen = ind->size[0];
    idx = nodes->size[1];
    if (!((j >= 1) && (j <= idx))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&cc_emlrtBCI, sp);
    }

    i3 = nodes->data[j - 1].neigh->size[0];
    nodes->data[j - 1].neigh->size[0] = x->size[0];
    emxEnsureCapacity_real_T1(sp, nodes->data[j - 1].neigh, i3, &db_emlrtRTEI);
    loop_ub = x->size[0];
    for (i3 = 0; i3 < loop_ub; i3++) {
      i4 = (int32_T)x->data[i3];
      if (!((i4 >= 1) && (i4 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, vlen, (emlrtBCInfo *)&dc_emlrtBCI,
          sp);
      }

      if (!((j >= 1) && (j <= idx))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&cc_emlrtBCI, sp);
      }

      nodes->data[j - 1].neigh->data[i3] = ind->data[i4 - 1];
    }

    vlen = ind->size[0];
    i3 = A->size[1];
    if (!((j >= 1) && (j <= i3))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i3, (emlrtBCInfo *)&qb_emlrtBCI, sp);
    }

    idx = nodes->size[1];
    if (!((j >= 1) && (j <= idx))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&ec_emlrtBCI, sp);
    }

    i3 = nodes->data[j - 1].w->size[0];
    nodes->data[j - 1].w->size[0] = x->size[0];
    emxEnsureCapacity_real_T1(sp, nodes->data[j - 1].w, i3, &eb_emlrtRTEI);
    loop_ub = x->size[0];
    for (i3 = 0; i3 < loop_ub; i3++) {
      i4 = (int32_T)x->data[i3];
      if (!((i4 >= 1) && (i4 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, vlen, (emlrtBCInfo *)&gc_emlrtBCI,
          sp);
      }

      i4 = ind->data[i4 - 1];
      if (!((i4 >= 1) && (i4 <= c_A))) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, c_A, (emlrtBCInfo *)&fc_emlrtBCI,
          sp);
      }

      if (!((j >= 1) && (j <= idx))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&ec_emlrtBCI, sp);
      }

      nodes->data[j - 1].w->data[i3] = A->data[(i4 + A->size[0] * (j - 1)) - 1];
    }

    st.site = &o_emlrtRSI;
    loop_ub = ind->size[0];
    for (i3 = 0; i3 < loop_ub; i3++) {
      i4 = ind->data[i3];
      if (!((i4 >= 1) && (i4 <= d_A))) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, d_A, (emlrtBCInfo *)&hc_emlrtBCI,
          &st);
      }
    }

    i3 = A->size[1];
    i4 = (j - 1) + 1;
    if (!((i4 >= 1) && (i4 <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, i3, (emlrtBCInfo *)&sb_emlrtBCI, &st);
    }

    b_st.site = &fc_emlrtRSI;
    if ((ind->size[0] == 1) || (ind->size[0] != 1)) {
      nonSingletonDimFound = true;
    } else {
      nonSingletonDimFound = false;
    }

    if (!nonSingletonDimFound) {
      emlrtErrorWithMessageIdR2012b(&b_st, &fc_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    c_st.site = &gc_emlrtRSI;
    vlen = ind->size[0];
    if (ind->size[0] == 0) {
      b_y = 0.0;
    } else {
      d_st.site = &hc_emlrtRSI;
      b_y = A->data[(ind->data[0] + A->size[0] * (j - 1)) - 1];
      e_st.site = &ic_emlrtRSI;
      nonSingletonDimFound = ((!(2 > ind->size[0])) && (ind->size[0] >
        2147483646));
      if (nonSingletonDimFound) {
        f_st.site = &t_emlrtRSI;
        g_st.site = &t_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }

      for (idx = 2; idx <= vlen; idx++) {
        b_y += A->data[(ind->data[idx - 1] + A->size[0] * (j - 1)) - 1];
      }
    }

    i3 = Theta_el->size[1];
    i4 = (j - 1) + 1;
    if (!((i4 >= 1) && (i4 <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, i3, (emlrtBCInfo *)&rb_emlrtBCI, sp);
    }

    /*  Iext -> external current used to initially excite a given node */
    /*  Isyn -> sum of weighted inputs over node i; i.e. sum of w_ij * s_j */
    /*  kInp -> (only for multiple seeds) the state towards which node i must be updated (can be from 1 to nInp) */
    /*  Theta -> the element threshold for firing */
    /*  W -> total input weight over node i */
    /*  n -> number of inputs over node i */
    /*  nInp -> total number of possible states */
    /*  s -> cumulative time it took for node i to get activated during spreading time simulation (summing up all times from the initial seed stimulation) */
    i3 = nodes->size[1];
    if (!((j >= 1) && (j <= i3))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i3, (emlrtBCInfo *)&ic_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.Iext = 0.0;
    i3 = nodes->size[1];
    if (!((j >= 1) && (j <= i3))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i3, (emlrtBCInfo *)&ic_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.Isyn = 0.0;
    i3 = nodes->size[1];
    if (!((j >= 1) && (j <= i3))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i3, (emlrtBCInfo *)&ic_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.kInp = 0.0;
    i3 = nodes->size[1];
    if (!((j >= 1) && (j <= i3))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i3, (emlrtBCInfo *)&ic_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.Theta = Theta_el->data[j - 1];
    i3 = nodes->size[1];
    if (!((j >= 1) && (j <= i3))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i3, (emlrtBCInfo *)&ic_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.W = b_y;
    i3 = nodes->size[1];
    if (!((j >= 1) && (j <= i3))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i3, (emlrtBCInfo *)&ic_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.n = ind->size[0];
    i3 = nodes->size[1];
    if (!((j >= 1) && (j <= i3))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i3, (emlrtBCInfo *)&ic_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.nInp = nSeeds;
    i3 = nodes->size[1];
    if (!((j >= 1) && (j <= i3))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i3, (emlrtBCInfo *)&ic_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.spTime = 0.0;
    i3 = nodes->size[1];
    if (!((j >= 1) && (j <= i3))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i3, (emlrtBCInfo *)&ic_emlrtBCI, sp);
    }

    i3 = nodes->size[1];
    if (!((j >= 1) && (j <= i3))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i3, (emlrtBCInfo *)&ic_emlrtBCI, sp);
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
