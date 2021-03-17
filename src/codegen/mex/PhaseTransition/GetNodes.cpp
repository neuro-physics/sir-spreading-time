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
#include "PhaseTransition.h"
#include "GetNodes.h"
#include "PhaseTransition_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sort1.h"
#include "indexShapeCheck.h"
#include "assertValidSizeArg.h"
#include "repeatToComplete.h"
#include "PhaseTransition_mexutil.h"
#include "PhaseTransition_data.h"

/* Type Definitions */
typedef struct {
  real_T x;
  struct_T par;
} c_struct_T;

/* Variable Definitions */
static emlrtRSInfo v_emlrtRSI = { 15,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 16,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 17,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 20,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 21, /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 25, /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRTEInfo l_emlrtRTEI = { 15,/* lineNo */
  31,                                  /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 17,/* lineNo */
  5,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 20,/* lineNo */
  9,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 27,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 23,/* lineNo */
  9,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 24,/* lineNo */
  9,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 15,/* lineNo */
  5,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 1, /* lineNo */
  18,                                  /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  17,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  24,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  28,                                  /* colNo */
  "A",                                 /* aName */
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
  22,                                  /* colNo */
  "x_init",                            /* aName */
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

/* Function Definitions */
void GetNodes(const emlrtStack *sp, const emxArray_real_T *A, real_T Theta,
              const emxArray_real_T *x0, emxArray_struct_T *nodes)
{
  emxArray_real_T *b_x0;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T loop_ub;
  emxArray_real_T *x_init;
  emxArray_real_T *Theta_el;
  int32_T idx;
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv3[2] = { 1, 15 };

  int32_T vlen;
  int32_T j;
  emxArray_int32_T *ind;
  emxArray_int32_T *ii;
  emxArray_real_T *x;
  int32_T nx;
  int32_T i4;
  static const c_struct_T r0 = { 0.0,  /* x */
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

  int32_T i5;
  int32_T i6;
  int32_T b_A;
  int32_T c_A;
  int32_T d_A;
  boolean_T overflow;
  boolean_T exitg1;
  int32_T iv4[2];
  boolean_T b_overflow;
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
  emxInit_real_T1(sp, &b_x0, 2, &l_emlrtRTEI, true);

  /*  A       -> [N,N] adjacency matrix (either weighted or binary) */
  /*  Theta   -> [1,1] to [1,N] vector activation threshold; if a vector is provided, each element has Theta(i) activation Threshold */
  /*  x0      -> [1,1] to [1,N] initial condition; if a vector is provided, each element has ic x0(i) */
  i1 = A->size[0];
  if (!(1 <= i1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i1, (emlrtBCInfo *)&ub_emlrtBCI, sp);
  }

  i1 = A->size[1];
  i2 = A->size[1];
  i3 = b_x0->size[0] * b_x0->size[1];
  b_x0->size[0] = 1;
  b_x0->size[1] = x0->size[1];
  emxEnsureCapacity_real_T(sp, b_x0, i3, &l_emlrtRTEI);
  loop_ub = x0->size[0] * x0->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    b_x0->data[i3] = x0->data[i3];
  }

  emxInit_real_T1(sp, &x_init, 2, &v_emlrtRTEI, true);
  emxInit_real_T1(sp, &Theta_el, 2, &m_emlrtRTEI, true);
  st.site = &v_emlrtRSI;
  repeatToComplete(&st, b_x0, (real_T)i2, x_init);
  st.site = &w_emlrtRSI;

  /*  y = [ x(:)', x(:)', ..., x(:)' ]; such that y is [1,N] vector */
  loop_ub = A->size[1];
  i2 = Theta_el->size[0] * Theta_el->size[1];
  Theta_el->size[0] = 1;
  Theta_el->size[1] = loop_ub;
  emxEnsureCapacity_real_T(&st, Theta_el, i2, &m_emlrtRTEI);
  emxFree_real_T(&b_x0);
  for (i2 = 0; i2 < loop_ub; i2++) {
    Theta_el->data[i2] = 0.0;
  }

  loop_ub = A->size[1];
  if (loop_ub <= 1) {
    i2 = A->size[1];
    if (1 > i2) {
      loop_ub = 0;
    } else {
      i2 = A->size[1];
      if (!((i2 >= 1) && (i2 <= 1))) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 1, (emlrtBCInfo *)&gc_emlrtBCI, &st);
      }

      loop_ub = 1;
    }

    i2 = Theta_el->size[0] * Theta_el->size[1];
    Theta_el->size[0] = 1;
    Theta_el->size[1] = loop_ub;
    emxEnsureCapacity_real_T(&st, Theta_el, i2, &m_emlrtRTEI);
    for (i2 = 0; i2 < loop_ub; i2++) {
      Theta_el->data[i2] = Theta;
    }
  } else {
    i2 = A->size[1];
    if (!(1 <= i2)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i2, (emlrtBCInfo *)&ec_emlrtBCI, &st);
    }

    i2 = A->size[1];
    if (!(loop_ub <= i2)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, (emlrtBCInfo *)&dc_emlrtBCI,
        &st);
    }

    b_st.site = &cb_emlrtRSI;
    c_st.site = &db_emlrtRSI;
    assertValidSizeArg(&c_st, (real_T)loop_ub);
    for (i2 = 0; i2 < loop_ub; i2++) {
      Theta_el->data[i2] = Theta;
    }

    i2 = A->size[1];
    i2 -= loop_ub;
    if (1 > i2) {
      idx = 0;
    } else {
      if (!(i2 <= 1)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 1, (emlrtBCInfo *)&fc_emlrtBCI, &st);
      }

      idx = 1;
    }

    i2 = A->size[1];
    if (loop_ub + 1U > (uint32_T)i2) {
      i2 = 0;
      i3 = 0;
    } else {
      i2 = Theta_el->size[1];
      i3 = (int32_T)(loop_ub + 1U);
      if (!((i3 >= 1) && (i3 <= i2))) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&cc_emlrtBCI,
          &st);
      }

      i2 = i3 - 1;
      i3 = A->size[1];
      vlen = Theta_el->size[1];
      if (!((i3 >= 1) && (i3 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, vlen, (emlrtBCInfo *)&bc_emlrtBCI,
          &st);
      }
    }

    i3 -= i2;
    if (i3 != idx) {
      emlrtSubAssignSizeCheck1dR2017a(i3, idx, (emlrtECInfo *)&emlrtECI, &st);
    }

    for (i3 = 0; i3 < idx; i3++) {
      Theta_el->data[i2 + i3] = Theta;
    }
  }

  st.site = &x_emlrtRSI;
  i2 = A->size[1];
  b_st.site = &db_emlrtRSI;
  assertValidSizeArg(&b_st, (real_T)i2);
  i2 = A->size[1];
  i3 = A->size[1];
  if (i2 != i3) {
    y = NULL;
    m1 = emlrtCreateCharArray(2, iv3);
    emlrtInitCharArrayR2013a(&st, 15, m1, &cv0[0]);
    emlrtAssign(&y, m1);
    b_st.site = &wd_emlrtRSI;
    error(&b_st, y, (emlrtMCInfo *)&c_emlrtMCI);
  }

  i3 = nodes->size[0] * nodes->size[1];
  nodes->size[0] = 1;
  emxEnsureCapacity_struct_T(sp, nodes, i3, &n_emlrtRTEI);
  i3 = nodes->size[0] * nodes->size[1];
  nodes->size[1] = i2;
  emxEnsureCapacity_struct_T(sp, nodes, i3, &n_emlrtRTEI);
  j = 0;
  while (j < i2) {
    nodes->data[j].x = 0.0;
    i3 = nodes->data[j].neigh->size[0];
    nodes->data[j].neigh->size[0] = 0;
    emxEnsureCapacity_real_T1(sp, nodes->data[j].neigh, i3, &n_emlrtRTEI);
    i3 = nodes->data[j].w->size[0];
    nodes->data[j].w->size[0] = 0;
    emxEnsureCapacity_real_T1(sp, nodes->data[j].w, i3, &n_emlrtRTEI);
    nodes->data[j].par = r0.par;
    j++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  j = 1;
  emxInit_int32_T(sp, &ind, 1, &q_emlrtRTEI, true);
  emxInit_int32_T(sp, &ii, 1, &w_emlrtRTEI, true);
  emxInit_real_T(sp, &x, 1, &x_emlrtRTEI, true);
  if (0 <= i1 - 1) {
    nx = A->size[0];
    i4 = A->size[0];
    i2 = A->size[0];
    i5 = A->size[0];
    i6 = A->size[0];
    b_A = A->size[0];
    c_A = A->size[0];
    d_A = A->size[0];
    if (1 > i2) {
      overflow = false;
    } else {
      i2 = A->size[0];
      overflow = (i2 > 2147483646);
    }
  }

  while (j - 1 <= i1 - 1) {
    st.site = &y_emlrtRSI;
    i2 = A->size[1];
    i3 = (j - 1) + 1;
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&vb_emlrtBCI, &st);
    }

    b_st.site = &hb_emlrtRSI;
    idx = 0;
    i2 = ii->size[0];
    ii->size[0] = i4;
    emxEnsureCapacity_int32_T(&b_st, ii, i2, &o_emlrtRTEI);
    c_st.site = &ib_emlrtRSI;
    if (overflow) {
      d_st.site = &gb_emlrtRSI;
      e_st.site = &gb_emlrtRSI;
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

    if (!(idx <= i5)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &hc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (i6 == 1) {
      if (idx == 0) {
        i2 = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity_int32_T(&b_st, ii, i2, &p_emlrtRTEI);
      }
    } else {
      if (1 > idx) {
        i2 = 0;
      } else {
        i2 = idx;
      }

      iv4[0] = 1;
      iv4[1] = i2;
      c_st.site = &jb_emlrtRSI;
      indexShapeCheck(&c_st, ii->size[0], iv4);
      i3 = ii->size[0];
      ii->size[0] = i2;
      emxEnsureCapacity_int32_T(&b_st, ii, i3, &p_emlrtRTEI);
    }

    i2 = ind->size[0];
    ind->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&st, ind, i2, &q_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      ind->data[i2] = ii->data[i2];
    }

    st.site = &ab_emlrtRSI;
    loop_ub = ind->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      i3 = ind->data[i2];
      if (!((i3 >= 1) && (i3 <= b_A))) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, b_A, (emlrtBCInfo *)&hc_emlrtBCI,
          &st);
      }
    }

    i2 = A->size[1];
    i3 = (j - 1) + 1;
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&wb_emlrtBCI, &st);
    }

    i2 = x->size[0];
    x->size[0] = ind->size[0];
    emxEnsureCapacity_real_T1(&st, x, i2, &r_emlrtRTEI);
    loop_ub = ind->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      x->data[i2] = A->data[(ind->data[i2] + A->size[0] * (j - 1)) - 1];
    }

    b_st.site = &lb_emlrtRSI;
    sort(&b_st, x, ii);
    i2 = x->size[0];
    x->size[0] = ii->size[0];
    emxEnsureCapacity_real_T1(&st, x, i2, &s_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      x->data[i2] = ii->data[i2];
    }

    /*  sorting connections from the heaviest to the lightest */
    i2 = x_init->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&ic_emlrtBCI, sp);
    }

    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&jc_emlrtBCI, sp);
    }

    nodes->data[j - 1].x = x_init->data[j - 1];
    vlen = ind->size[0];
    idx = nodes->size[1];
    if (!((j >= 1) && (j <= idx))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&kc_emlrtBCI, sp);
    }

    i2 = nodes->data[j - 1].neigh->size[0];
    nodes->data[j - 1].neigh->size[0] = x->size[0];
    emxEnsureCapacity_real_T1(sp, nodes->data[j - 1].neigh, i2, &t_emlrtRTEI);
    loop_ub = x->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      i3 = (int32_T)x->data[i2];
      if (!((i3 >= 1) && (i3 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, vlen, (emlrtBCInfo *)&lc_emlrtBCI,
          sp);
      }

      if (!((j >= 1) && (j <= idx))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&kc_emlrtBCI, sp);
      }

      nodes->data[j - 1].neigh->data[i2] = ind->data[i3 - 1];
    }

    vlen = ind->size[0];
    i2 = A->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&xb_emlrtBCI, sp);
    }

    idx = nodes->size[1];
    if (!((j >= 1) && (j <= idx))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&mc_emlrtBCI, sp);
    }

    i2 = nodes->data[j - 1].w->size[0];
    nodes->data[j - 1].w->size[0] = x->size[0];
    emxEnsureCapacity_real_T1(sp, nodes->data[j - 1].w, i2, &u_emlrtRTEI);
    loop_ub = x->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      i3 = (int32_T)x->data[i2];
      if (!((i3 >= 1) && (i3 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, vlen, (emlrtBCInfo *)&oc_emlrtBCI,
          sp);
      }

      i3 = ind->data[i3 - 1];
      if (!((i3 >= 1) && (i3 <= c_A))) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, c_A, (emlrtBCInfo *)&nc_emlrtBCI,
          sp);
      }

      if (!((j >= 1) && (j <= idx))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, idx, (emlrtBCInfo *)&mc_emlrtBCI, sp);
      }

      nodes->data[j - 1].w->data[i2] = A->data[(i3 + A->size[0] * (j - 1)) - 1];
    }

    st.site = &bb_emlrtRSI;
    loop_ub = ind->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      i3 = ind->data[i2];
      if (!((i3 >= 1) && (i3 <= d_A))) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, d_A, (emlrtBCInfo *)&pc_emlrtBCI,
          &st);
      }
    }

    i2 = A->size[1];
    i3 = (j - 1) + 1;
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&ac_emlrtBCI, &st);
    }

    b_st.site = &rc_emlrtRSI;
    if ((ind->size[0] == 1) || (ind->size[0] != 1)) {
      b_overflow = true;
    } else {
      b_overflow = false;
    }

    if (!b_overflow) {
      emlrtErrorWithMessageIdR2012b(&b_st, &ic_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    c_st.site = &sc_emlrtRSI;
    vlen = ind->size[0];
    if (ind->size[0] == 0) {
      b_y = 0.0;
    } else {
      d_st.site = &tc_emlrtRSI;
      b_y = A->data[(ind->data[0] + A->size[0] * (j - 1)) - 1];
      e_st.site = &uc_emlrtRSI;
      b_overflow = ((!(2 > ind->size[0])) && (ind->size[0] > 2147483646));
      if (b_overflow) {
        f_st.site = &gb_emlrtRSI;
        g_st.site = &gb_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }

      for (idx = 2; idx <= vlen; idx++) {
        b_y += A->data[(ind->data[idx - 1] + A->size[0] * (j - 1)) - 1];
      }
    }

    i2 = Theta_el->size[1];
    i3 = (j - 1) + 1;
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&yb_emlrtBCI, sp);
    }

    /*  Iext -> external current used to initially excite a given node */
    /*  Isyn -> sum of weighted inputs over node i; i.e. sum of w_ij * s_j */
    /*  kInp -> (only for multiple seeds) the state towards which node i must be updated (can be from 1 to nInp) */
    /*  Theta -> the element threshold for firing */
    /*  W -> total input weight over node i */
    /*  n -> number of inputs over node i */
    /*  nInp -> total number of possible states */
    /*  s -> cumulative time it took for node i to get activated during spreading time simulation (summing up all times from the initial seed stimulation) */
    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.Iext = 0.0;
    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.Isyn = 0.0;
    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.kInp = 0.0;
    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.Theta = Theta_el->data[j - 1];
    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.W = b_y;
    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.n = ind->size[0];
    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.nInp = 1.0;
    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    nodes->data[j - 1].par.spTime = 0.0;
    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&qc_emlrtBCI, sp);
    }

    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&qc_emlrtBCI, sp);
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
