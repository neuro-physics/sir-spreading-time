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
#include "NetworkActivationTime.h"
#include "GetNodes.h"
#include "NetworkActivationTime_emxutil.h"
#include "GetSimulationParam.h"
#include "eml_int_forloop_overflow_check.h"
#include "error.h"
#include "sort1.h"
#include "assertValidSizeArg.h"
#include "NetworkActivationTime_mexutil.h"
#include "NetworkActivationTime_data.h"

/* Variable Definitions */
static emlrtRSInfo f_emlrtRSI = { 11,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 15,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 16,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 17,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 20,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 21,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 25,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 11,  /* lineNo */
  "repeatToComplete",                  /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 44,  /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 234, /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 253, /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 18,  /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 26,  /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pathName */
};

static emlrtRTEInfo e_emlrtRTEI = { 15,/* lineNo */
  5,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 41,/* lineNo */
  9,                                   /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 44,/* lineNo */
  10,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 20,/* lineNo */
  9,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 26,/* lineNo */
  6,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 27,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 23,/* lineNo */
  9,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 24,/* lineNo */
  9,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 36,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 1, /* lineNo */
  18,                                  /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = { 88,/* lineNo */
  9,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = { 243,/* lineNo */
  9,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  1,                                   /* iLast */
  8,                                   /* lineNo */
  17,                                  /* colNo */
  "x",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  1,                                   /* iLast */
  12,                                  /* lineNo */
  25,                                  /* colNo */
  "x",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  7,                                   /* colNo */
  "y",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  10,                                  /* colNo */
  "y",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  8,                                   /* colNo */
  "y",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  15,                                  /* colNo */
  "y",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  12,                                  /* lineNo */
  5,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  73,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  59,                                  /* colNo */
  "Theta_el",                          /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  31,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  29,                                  /* colNo */
  "x_init",                            /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  28,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  24,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  17,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  24,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  30,                                  /* colNo */
  "ind",                               /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  24,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  28,                                  /* colNo */
  "ind",                               /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  69,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
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
  int32_T i12;
  int32_T j;
  i12 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity_struct_T1(sp, y, i12, (emlrtRTEInfo *)NULL);
  j = 0;
  while (j < x->size[1]) {
    y->data[j].x = x->data[j].x;
    i12 = y->data[j].neigh->size[0];
    y->data[j].neigh->size[0] = 0;
    emxEnsureCapacity_real_T(sp, y->data[j].neigh, i12, (emlrtRTEInfo *)NULL);
    i12 = y->data[j].w->size[0];
    y->data[j].w->size[0] = 0;
    emxEnsureCapacity_real_T(sp, y->data[j].w, i12, (emlrtRTEInfo *)NULL);
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
  int32_T i0;
  int32_T loop_ub;
  int32_T i1;
  emxArray_real_T *Theta_el;
  int32_T idx;
  int32_T i2;
  int32_T vlen;
  const mxArray *y;
  b_emxArray_struct_T *r0;
  const mxArray *m0;
  static const int32_T iv0[2] = { 1, 15 };

  static const d_struct_T r1 = { 0.0,  /* x */
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
  int32_T i3;
  int32_T i4;
  int32_T i5;
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
  st.site = &f_emlrtRSI;
  if (muDoubleScalarIsNaN(isCompetitive)) {
    b_st.site = &e_emlrtRSI;
    c_st.site = &e_emlrtRSI;
    error(&c_st);
  }

  if (!(isCompetitive != 0.0)) {
    nSeeds = 1.0;
  }

  emxInit_int8_T(sp, &x_init, 2, &e_emlrtRTEI, true);
  i0 = A->size[0];
  if (!(1 <= i0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, (emlrtBCInfo *)&o_emlrtBCI, sp);
  }

  i0 = A->size[1];
  st.site = &g_emlrtRSI;

  /*  y = [ x(:)', x(:)', ..., x(:)' ]; such that y is [1,N] vector */
  loop_ub = A->size[1];
  i1 = x_init->size[0] * x_init->size[1];
  x_init->size[0] = 1;
  x_init->size[1] = loop_ub;
  emxEnsureCapacity_int8_T(&st, x_init, i1, &e_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    x_init->data[i1] = 0;
  }

  loop_ub = A->size[1];
  if (loop_ub <= 1) {
    i1 = A->size[1];
    if (1 > i1) {
      loop_ub = 0;
    } else {
      i1 = A->size[1];
      if (!((i1 >= 1) && (i1 <= 1))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 1, (emlrtBCInfo *)&c_emlrtBCI, &st);
      }

      loop_ub = 1;
    }

    i1 = x_init->size[0] * x_init->size[1];
    x_init->size[0] = 1;
    x_init->size[1] = loop_ub;
    emxEnsureCapacity_int8_T(&st, x_init, i1, &e_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      x_init->data[i1] = 0;
    }
  } else {
    i1 = A->size[1];
    if (!(1 <= i1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i1, (emlrtBCInfo *)&e_emlrtBCI, &st);
    }

    i1 = A->size[1];
    if (!(loop_ub <= i1)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, (emlrtBCInfo *)&f_emlrtBCI,
        &st);
    }

    b_st.site = &m_emlrtRSI;
    c_st.site = &n_emlrtRSI;
    assertValidSizeArg(&c_st, (real_T)loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      x_init->data[i1] = 0;
    }

    i1 = A->size[1];
    i1 -= loop_ub;
    if (1 > i1) {
      idx = 0;
    } else {
      if (!(i1 <= 1)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 1, (emlrtBCInfo *)&d_emlrtBCI, &st);
      }

      idx = 1;
    }

    i1 = A->size[1];
    if (loop_ub + 1U > (uint32_T)i1) {
      i2 = 1;
      i1 = 1;
    } else {
      i1 = x_init->size[1];
      i2 = (int32_T)(loop_ub + 1U);
      if (!((i2 >= 1) && (i2 <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)&g_emlrtBCI, &st);
      }

      i1 = A->size[1];
      vlen = x_init->size[1];
      if (!((i1 >= 1) && (i1 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vlen, (emlrtBCInfo *)&h_emlrtBCI,
          &st);
      }

      i1++;
    }

    i1 -= i2;
    if (i1 != idx) {
      emlrtSubAssignSizeCheck1dR2017a(i1, idx, (emlrtECInfo *)&emlrtECI, &st);
    }

    for (i1 = 0; i1 < idx; i1++) {
      x_init->data[(i2 + i1) - 1] = 0;
    }
  }

  emxInit_real_T(&st, &Theta_el, 2, &f_emlrtRTEI, true);
  st.site = &h_emlrtRSI;

  /*  y = [ x(:)', x(:)', ..., x(:)' ]; such that y is [1,N] vector */
  loop_ub = A->size[1];
  i1 = Theta_el->size[0] * Theta_el->size[1];
  Theta_el->size[0] = 1;
  Theta_el->size[1] = loop_ub;
  emxEnsureCapacity_real_T1(&st, Theta_el, i1, &f_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    Theta_el->data[i1] = 0.0;
  }

  loop_ub = A->size[1];
  if (loop_ub <= 1) {
    i1 = A->size[1];
    if (1 > i1) {
      loop_ub = 0;
    } else {
      i1 = A->size[1];
      if (!((i1 >= 1) && (i1 <= 1))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 1, (emlrtBCInfo *)&c_emlrtBCI, &st);
      }

      loop_ub = 1;
    }

    i1 = Theta_el->size[0] * Theta_el->size[1];
    Theta_el->size[0] = 1;
    Theta_el->size[1] = loop_ub;
    emxEnsureCapacity_real_T1(&st, Theta_el, i1, &f_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      Theta_el->data[i1] = Theta;
    }
  } else {
    i1 = A->size[1];
    if (!(1 <= i1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i1, (emlrtBCInfo *)&e_emlrtBCI, &st);
    }

    i1 = A->size[1];
    if (!(loop_ub <= i1)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, (emlrtBCInfo *)&f_emlrtBCI,
        &st);
    }

    b_st.site = &m_emlrtRSI;
    c_st.site = &n_emlrtRSI;
    assertValidSizeArg(&c_st, (real_T)loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      Theta_el->data[i1] = Theta;
    }

    i1 = A->size[1];
    i1 -= loop_ub;
    if (1 > i1) {
      idx = 0;
    } else {
      if (!(i1 <= 1)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 1, (emlrtBCInfo *)&d_emlrtBCI, &st);
      }

      idx = 1;
    }

    i1 = A->size[1];
    if (loop_ub + 1U > (uint32_T)i1) {
      i2 = 1;
      i1 = 1;
    } else {
      i1 = Theta_el->size[1];
      i2 = (int32_T)(loop_ub + 1U);
      if (!((i2 >= 1) && (i2 <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)&g_emlrtBCI, &st);
      }

      i1 = A->size[1];
      vlen = Theta_el->size[1];
      if (!((i1 >= 1) && (i1 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vlen, (emlrtBCInfo *)&h_emlrtBCI,
          &st);
      }

      i1++;
    }

    i1 -= i2;
    if (i1 != idx) {
      emlrtSubAssignSizeCheck1dR2017a(i1, idx, (emlrtECInfo *)&emlrtECI, &st);
    }

    for (i1 = 0; i1 < idx; i1++) {
      Theta_el->data[(i2 + i1) - 1] = Theta;
    }
  }

  st.site = &i_emlrtRSI;
  i1 = A->size[1];
  b_st.site = &n_emlrtRSI;
  assertValidSizeArg(&b_st, (real_T)i1);
  loop_ub = A->size[1];
  i1 = A->size[1];
  if (loop_ub != i1) {
    y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    emlrtInitCharArrayR2013a(&st, 15, m0, &cv0[0]);
    emlrtAssign(&y, m0);
    b_st.site = &me_emlrtRSI;
    d_error(&b_st, y, (emlrtMCInfo *)&emlrtMCI);
  }

  emxInit_struct_T1(&st, &r0, 2, &g_emlrtRTEI, true);
  i1 = r0->size[0] * r0->size[1];
  r0->size[0] = 1;
  r0->size[1] = loop_ub;
  emxEnsureCapacity_struct_T(sp, r0, i1, &g_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    r0->data[i1] = r1;
  }

  cast(sp, r0, nodes);
  j = 1;
  emxFree_struct_T1(&r0);
  emxInit_int32_T(sp, &ind, 1, &j_emlrtRTEI, true);
  emxInit_int32_T(sp, &ii, 1, &o_emlrtRTEI, true);
  emxInit_real_T1(sp, &x, 1, &p_emlrtRTEI, true);
  if (0 <= i0 - 1) {
    nx = A->size[0];
    i3 = A->size[0];
    i1 = A->size[0];
    i4 = A->size[0];
    i5 = A->size[0];
    b_A = A->size[0];
    c_A = A->size[0];
    d_A = A->size[0];
    if (1 > i1) {
      overflow = false;
    } else {
      i1 = A->size[0];
      overflow = (i1 > 2147483646);
    }
  }

  while (j - 1 <= i0 - 1) {
    st.site = &j_emlrtRSI;
    i1 = A->size[1];
    i2 = (j - 1) + 1;
    if (!((i2 >= 1) && (i2 <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)&n_emlrtBCI, &st);
    }

    b_st.site = &o_emlrtRSI;
    idx = 0;
    i1 = ii->size[0];
    ii->size[0] = i3;
    emxEnsureCapacity_int32_T(&b_st, ii, i1, &h_emlrtRTEI);
    c_st.site = &p_emlrtRSI;
    if (overflow) {
      d_st.site = &r_emlrtRSI;
      e_st.site = &r_emlrtRSI;
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

    if (!(idx <= i4)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &tc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (i5 == 1) {
      if (idx == 0) {
        i1 = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity_int32_T(&b_st, ii, i1, &i_emlrtRTEI);
      }
    } else {
      if (1 > idx) {
        i1 = 0;
      } else {
        i1 = idx;
      }

      c_st.site = &q_emlrtRSI;
      nonSingletonDimFound = !(ii->size[0] != 1);
      if (nonSingletonDimFound) {
        nonSingletonDimFound = false;
        if (i1 != 1) {
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

      d_st.site = &s_emlrtRSI;
      if (nonSingletonDimFound) {
        emlrtErrorWithMessageIdR2012b(&d_st, &sc_emlrtRTEI,
          "Coder:FE:PotentialVectorVector", 0);
      }

      i2 = ii->size[0];
      ii->size[0] = i1;
      emxEnsureCapacity_int32_T(&b_st, ii, i2, &i_emlrtRTEI);
    }

    i1 = ind->size[0];
    ind->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&st, ind, i1, &j_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      ind->data[i1] = ii->data[i1];
    }

    st.site = &k_emlrtRSI;
    loop_ub = ind->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      i2 = ind->data[i1];
      if (!((i2 >= 1) && (i2 <= b_A))) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, b_A, (emlrtBCInfo *)&p_emlrtBCI,
          &st);
      }
    }

    i1 = A->size[1];
    i2 = (j - 1) + 1;
    if (!((i2 >= 1) && (i2 <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)&m_emlrtBCI, &st);
    }

    i1 = x->size[0];
    x->size[0] = ind->size[0];
    emxEnsureCapacity_real_T(&st, x, i1, &k_emlrtRTEI);
    loop_ub = ind->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      x->data[i1] = A->data[(ind->data[i1] + A->size[0] * (j - 1)) - 1];
    }

    b_st.site = &t_emlrtRSI;
    sort(&b_st, x, ii);
    i1 = x->size[0];
    x->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(&st, x, i1, &l_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      x->data[i1] = ii->data[i1];
    }

    /*  sorting connections from the heaviest to the lightest */
    i1 = x_init->size[1];
    i2 = (j - 1) + 1;
    if (!((i2 >= 1) && (i2 <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)&l_emlrtBCI, sp);
    }

    i1 = nodes->size[1];
    if (!((j >= 1) && (j <= i1))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i1, (emlrtBCInfo *)&q_emlrtBCI, sp);
    }

    nodes->data[j - 1].x = 0.0;
    vlen = ind->size[0];
    idx = nodes->size[1];
    if (!((j >= 1) && (j <= idx))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&r_emlrtBCI, sp);
    }

    i1 = nodes->data[j - 1].neigh->size[0];
    nodes->data[j - 1].neigh->size[0] = x->size[0];
    emxEnsureCapacity_real_T(sp, nodes->data[j - 1].neigh, i1, &m_emlrtRTEI);
    loop_ub = x->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      i2 = (int32_T)x->data[i1];
      if (!((i2 >= 1) && (i2 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, vlen, (emlrtBCInfo *)&s_emlrtBCI,
          sp);
      }

      if (!((j >= 1) && (j <= idx))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&r_emlrtBCI, sp);
      }

      nodes->data[j - 1].neigh->data[i1] = ind->data[i2 - 1];
    }

    vlen = ind->size[0];
    i1 = A->size[1];
    if (!((j >= 1) && (j <= i1))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i1, (emlrtBCInfo *)&k_emlrtBCI, sp);
    }

    idx = nodes->size[1];
    if (!((j >= 1) && (j <= idx))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&t_emlrtBCI, sp);
    }

    i1 = nodes->data[j - 1].w->size[0];
    nodes->data[j - 1].w->size[0] = x->size[0];
    emxEnsureCapacity_real_T(sp, nodes->data[j - 1].w, i1, &n_emlrtRTEI);
    loop_ub = x->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      i2 = (int32_T)x->data[i1];
      if (!((i2 >= 1) && (i2 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, vlen, (emlrtBCInfo *)&v_emlrtBCI,
          sp);
      }

      i2 = ind->data[i2 - 1];
      if (!((i2 >= 1) && (i2 <= c_A))) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, c_A, (emlrtBCInfo *)&u_emlrtBCI, sp);
      }

      if (!((j >= 1) && (j <= idx))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&t_emlrtBCI, sp);
      }

      nodes->data[j - 1].w->data[i1] = A->data[(i2 + A->size[0] * (j - 1)) - 1];
    }

    st.site = &l_emlrtRSI;
    loop_ub = ind->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      i2 = ind->data[i1];
      if (!((i2 >= 1) && (i2 <= d_A))) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, d_A, (emlrtBCInfo *)&w_emlrtBCI,
          &st);
      }
    }

    i1 = A->size[1];
    i2 = (j - 1) + 1;
    if (!((i2 >= 1) && (i2 <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)&i_emlrtBCI, &st);
    }

    b_st.site = &ac_emlrtRSI;
    if ((ind->size[0] == 1) || (ind->size[0] != 1)) {
      nonSingletonDimFound = true;
    } else {
      nonSingletonDimFound = false;
    }

    if (!nonSingletonDimFound) {
      emlrtErrorWithMessageIdR2012b(&b_st, &rc_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    c_st.site = &bc_emlrtRSI;
    vlen = ind->size[0];
    if (ind->size[0] == 0) {
      b_y = 0.0;
    } else {
      d_st.site = &cc_emlrtRSI;
      b_y = A->data[(ind->data[0] + A->size[0] * (j - 1)) - 1];
      e_st.site = &dc_emlrtRSI;
      nonSingletonDimFound = ((!(2 > ind->size[0])) && (ind->size[0] >
        2147483646));
      if (nonSingletonDimFound) {
        f_st.site = &r_emlrtRSI;
        g_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }

      for (idx = 2; idx <= vlen; idx++) {
        b_y += A->data[(ind->data[idx - 1] + A->size[0] * (j - 1)) - 1];
      }
    }

    i1 = Theta_el->size[1];
    i2 = (j - 1) + 1;
    if (!((i2 >= 1) && (i2 <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)&j_emlrtBCI, sp);
    }

    /*  Iext -> external current used to initially excite a given node */
    /*  Isyn -> sum of weighted inputs over node i; i.e. sum of w_ij * s_j */
    /*  kInp -> (only for multiple seeds) the state towards which node i must be updated (can be from 1 to nInp) */
    /*  Theta -> the element threshold for firing */
    /*  W -> total input weight over node i */
    /*  n -> number of inputs over node i */
    /*  nInp -> total number of possible states */
    /*  s -> cumulative time it took for node i to get activated during spreading time simulation (summing up all times from the initial seed stimulation) */
    i1 = nodes->size[1];
    if (!((j >= 1) && (j <= i1))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i1, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.Iext = 0.0;
    i1 = nodes->size[1];
    if (!((j >= 1) && (j <= i1))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i1, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.Isyn = 0.0;
    i1 = nodes->size[1];
    if (!((j >= 1) && (j <= i1))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i1, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.kInp = 0.0;
    i1 = nodes->size[1];
    if (!((j >= 1) && (j <= i1))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i1, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.Theta = Theta_el->data[j - 1];
    i1 = nodes->size[1];
    if (!((j >= 1) && (j <= i1))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i1, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.W = b_y;
    i1 = nodes->size[1];
    if (!((j >= 1) && (j <= i1))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i1, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.n = ind->size[0];
    i1 = nodes->size[1];
    if (!((j >= 1) && (j <= i1))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i1, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.nInp = nSeeds;
    i1 = nodes->size[1];
    if (!((j >= 1) && (j <= i1))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i1, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.spTime = 0.0;
    i1 = nodes->size[1];
    if (!((j >= 1) && (j <= i1))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i1, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    i1 = nodes->size[1];
    if (!((j >= 1) && (j <= i1))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i1, (emlrtBCInfo *)&x_emlrtBCI, sp);
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
