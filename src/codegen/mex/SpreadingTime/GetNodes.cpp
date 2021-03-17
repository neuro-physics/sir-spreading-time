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
#include "SpreadingTime.h"
#include "GetNodes.h"
#include "SpreadingTime_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sort1.h"
#include "SpreadingTime_data.h"

/* Variable Definitions */
static emlrtRSInfo c_emlrtRSI = { 15,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 16,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 17,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 20,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 21,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 25,  /* lineNo */
  "GetNodes",                          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 11,  /* lineNo */
  "repeatToComplete",                  /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 18,  /* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 44,  /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 234, /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 253, /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 18,  /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 26,  /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 9,  /* lineNo */
  "sum",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 58, /* lineNo */
  "sumprod",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 106,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 166,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 37,    /* lineNo */
  5,                                   /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 15,/* lineNo */
  5,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 41,/* lineNo */
  9,                                   /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 44,/* lineNo */
  10,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 20,/* lineNo */
  9,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 26,/* lineNo */
  6,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 27,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 23,/* lineNo */
  9,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 24,/* lineNo */
  9,                                   /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 36,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 1, /* lineNo */
  18,                                  /* colNo */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 20,/* lineNo */
  15,                                  /* colNo */
  "sumprod",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 88,/* lineNo */
  9,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 243,/* lineNo */
  9,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  1,                                   /* iLast */
  8,                                   /* lineNo */
  17,                                  /* colNo */
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

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  11,                                  /* lineNo */
  5,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
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

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
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
  24,                                  /* lineNo */
  31,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  29,                                  /* colNo */
  "x_init",                            /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  28,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  24,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  17,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  24,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  30,                                  /* colNo */
  "ind",                               /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  24,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  28,                                  /* colNo */
  "ind",                               /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  69,                                  /* colNo */
  "A",                                 /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  50,                                  /* colNo */
  "Theta_el",                          /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  24,                                  /* colNo */
  "nodes",                             /* aName */
  "GetNodes",                          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRSInfo ec_emlrtRSI = { 37, /* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

/* Function Declarations */
static void cast(const emlrtStack *sp, const b_emxArray_struct_T *x,
                 emxArray_struct_T *y);
static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);
static void getParStruct(real_T Theta, real_T W, real_T n, real_T *p_Iext,
  real_T *p_Isyn, real_T *p_kInp, real_T *p_Theta, real_T *p_W, real_T *p_n,
  real_T *p_nInp, real_T *p_spTime);

/* Function Definitions */
static void cast(const emlrtStack *sp, const b_emxArray_struct_T *x,
                 emxArray_struct_T *y)
{
  int32_T i9;
  int32_T j;
  i9 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity_struct_T1(sp, y, i9, (emlrtRTEInfo *)NULL);
  j = 0;
  while (j < x->size[1]) {
    y->data[j].x = x->data[j].x;
    i9 = y->data[j].neigh->size[0];
    y->data[j].neigh->size[0] = 0;
    emxEnsureCapacity_real_T1(sp, y->data[j].neigh, i9, (emlrtRTEInfo *)NULL);
    i9 = y->data[j].w->size[0];
    y->data[j].w->size[0] = 0;
    emxEnsureCapacity_real_T1(sp, y->data[j].w, i9, (emlrtRTEInfo *)NULL);
    y->data[j].par = x->data[j].par;
    j++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

static void getParStruct(real_T Theta, real_T W, real_T n, real_T *p_Iext,
  real_T *p_Isyn, real_T *p_kInp, real_T *p_Theta, real_T *p_W, real_T *p_n,
  real_T *p_nInp, real_T *p_spTime)
{
  /*  Iext -> external current used to initially excite a given node */
  /*  Isyn -> sum of weighted inputs over node i; i.e. sum of w_ij * s_j */
  /*  kInp -> (only for multiple seeds) the state towards which node i must be updated (can be from 1 to nInp) */
  /*  Theta -> the element threshold for firing */
  /*  W -> total input weight over node i */
  /*  n -> number of inputs over node i */
  /*  nInp -> total number of possible states */
  /*  s -> cumulative time it took for node i to get activated during spreading time simulation (summing up all times from the initial seed stimulation) */
  *p_Iext = 0.0;
  *p_Isyn = 0.0;
  *p_kInp = 0.0;
  *p_Theta = Theta;
  *p_W = W;
  *p_n = n;
  *p_nInp = 1.0;
  *p_spTime = 0.0;
}

void GetNodes(const emlrtStack *sp, const emxArray_real_T *A, real_T Theta,
              emxArray_struct_T *nodes)
{
  emxArray_int8_T *x_init;
  int32_T i1;
  int32_T vlen;
  int32_T i2;
  int32_T i3;
  emxArray_real_T *Theta_el;
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 1, 15 };

  static const char_T u[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a',
    'x', 's', 'i', 'z', 'e' };

  static const int32_T iv1[2] = { 1, 15 };

  b_emxArray_struct_T *r0;
  static const int32_T iv2[2] = { 1, 15 };

  static const c_struct_T r1 = { 0.0,  /* x */
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
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T b_A;
  int32_T c_A;
  int32_T d_A;
  int32_T idx;
  boolean_T overflow;
  boolean_T exitg1;
  boolean_T nonSingletonDimFound;
  int32_T b_nodes;
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
  emxInit_int8_T(sp, &x_init, 2, &c_emlrtRTEI, true);

  /*  A       -> [N,N] adjacency matrix (either weighted or binary) */
  /*  Theta   -> [1,1] to [1,N] vector activation threshold; if a vector is provided, each element has Theta(i) activation Threshold */
  /*  x0      -> [1,1] to [1,N] initial condition; if a vector is provided, each element has ic x0(i) */
  i1 = A->size[0];
  if (!(1 <= i1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i1, (emlrtBCInfo *)&n_emlrtBCI, sp);
  }

  i1 = A->size[1];
  st.site = &c_emlrtRSI;

  /*  y = [ x(:)', x(:)', ..., x(:)' ]; such that y is [1,N] vector */
  vlen = A->size[1];
  i2 = x_init->size[0] * x_init->size[1];
  x_init->size[0] = 1;
  x_init->size[1] = vlen;
  emxEnsureCapacity_int8_T(&st, x_init, i2, &c_emlrtRTEI);
  for (i2 = 0; i2 < vlen; i2++) {
    x_init->data[i2] = 0;
  }

  i2 = A->size[1];
  if (i2 <= 1) {
    i2 = A->size[1];
    if (1 > i2) {
      vlen = 0;
    } else {
      i2 = A->size[1];
      if (!((i2 >= 1) && (i2 <= 1))) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 1, (emlrtBCInfo *)&d_emlrtBCI, &st);
      }

      vlen = 1;
    }

    i2 = x_init->size[0] * x_init->size[1];
    x_init->size[0] = 1;
    x_init->size[1] = vlen;
    emxEnsureCapacity_int8_T(&st, x_init, i2, &c_emlrtRTEI);
    for (i2 = 0; i2 < vlen; i2++) {
      x_init->data[i2] = 0;
    }
  } else {
    i2 = A->size[1];
    if (!(1 <= i2)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i2, (emlrtBCInfo *)&e_emlrtBCI, &st);
    }

    i2 = A->size[1];
    i3 = A->size[1];
    if (!((i2 >= 1) && (i2 <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i3, (emlrtBCInfo *)&f_emlrtBCI, &st);
    }

    b_st.site = &i_emlrtRSI;
    c_st.site = &j_emlrtRSI;
    vlen = A->size[1];
    i2 = A->size[1];
    if (vlen != i2) {
      y = NULL;
      m0 = emlrtCreateCharArray(2, iv0);
      emlrtInitCharArrayR2013a(&b_st, 15, m0, &u[0]);
      emlrtAssign(&y, m0);
      c_st.site = &ec_emlrtRSI;
      error(&c_st, y, (emlrtMCInfo *)&emlrtMCI);
    }

    if (i1 != vlen) {
      emlrtSubAssignSizeCheck1dR2017a(i1, vlen, (emlrtECInfo *)&emlrtECI, &st);
    }

    for (i2 = 0; i2 < vlen; i2++) {
      x_init->data[i2] = 0;
    }

    i2 = A->size[1];
    if (i1 + 1U > (uint32_T)i2) {
      i3 = 1;
      i2 = 1;
    } else {
      i2 = x_init->size[1];
      i3 = (int32_T)(i1 + 1U);
      if (!((i3 >= 1) && (i3 <= i2))) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&g_emlrtBCI, &st);
      }

      i2 = A->size[1];
      vlen = x_init->size[1];
      if (!((i2 >= 1) && (i2 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, vlen, (emlrtBCInfo *)&h_emlrtBCI,
          &st);
      }

      i2++;
    }

    i2 -= i3;
    if (i2 != 0) {
      emlrtSubAssignSizeCheck1dR2017a(i2, 0, (emlrtECInfo *)&b_emlrtECI, &st);
    }
  }

  emxInit_real_T(&st, &Theta_el, 2, &d_emlrtRTEI, true);
  st.site = &d_emlrtRSI;

  /*  y = [ x(:)', x(:)', ..., x(:)' ]; such that y is [1,N] vector */
  vlen = A->size[1];
  i2 = Theta_el->size[0] * Theta_el->size[1];
  Theta_el->size[0] = 1;
  Theta_el->size[1] = vlen;
  emxEnsureCapacity_real_T(&st, Theta_el, i2, &d_emlrtRTEI);
  for (i2 = 0; i2 < vlen; i2++) {
    Theta_el->data[i2] = 0.0;
  }

  i2 = A->size[1];
  if (i2 <= 1) {
    i2 = A->size[1];
    if (1 > i2) {
      vlen = 0;
    } else {
      i2 = A->size[1];
      if (!((i2 >= 1) && (i2 <= 1))) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 1, (emlrtBCInfo *)&d_emlrtBCI, &st);
      }

      vlen = 1;
    }

    i2 = Theta_el->size[0] * Theta_el->size[1];
    Theta_el->size[0] = 1;
    Theta_el->size[1] = vlen;
    emxEnsureCapacity_real_T(&st, Theta_el, i2, &d_emlrtRTEI);
    for (i2 = 0; i2 < vlen; i2++) {
      Theta_el->data[i2] = Theta;
    }
  } else {
    i2 = A->size[1];
    if (!(1 <= i2)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i2, (emlrtBCInfo *)&e_emlrtBCI, &st);
    }

    i2 = A->size[1];
    i3 = A->size[1];
    if (!((i2 >= 1) && (i2 <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i3, (emlrtBCInfo *)&f_emlrtBCI, &st);
    }

    b_st.site = &i_emlrtRSI;
    c_st.site = &j_emlrtRSI;
    vlen = A->size[1];
    i2 = A->size[1];
    if (vlen != i2) {
      y = NULL;
      m0 = emlrtCreateCharArray(2, iv1);
      emlrtInitCharArrayR2013a(&b_st, 15, m0, &u[0]);
      emlrtAssign(&y, m0);
      c_st.site = &ec_emlrtRSI;
      error(&c_st, y, (emlrtMCInfo *)&emlrtMCI);
    }

    if (i1 != vlen) {
      emlrtSubAssignSizeCheck1dR2017a(i1, vlen, (emlrtECInfo *)&emlrtECI, &st);
    }

    for (i2 = 0; i2 < vlen; i2++) {
      Theta_el->data[i2] = Theta;
    }

    i2 = A->size[1];
    if (i1 + 1U > (uint32_T)i2) {
      i3 = 1;
      i2 = 1;
    } else {
      i2 = Theta_el->size[1];
      i3 = (int32_T)(i1 + 1U);
      if (!((i3 >= 1) && (i3 <= i2))) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&g_emlrtBCI, &st);
      }

      i2 = A->size[1];
      vlen = Theta_el->size[1];
      if (!((i2 >= 1) && (i2 <= vlen))) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, vlen, (emlrtBCInfo *)&h_emlrtBCI,
          &st);
      }

      i2++;
    }

    i2 -= i3;
    if (i2 != 0) {
      emlrtSubAssignSizeCheck1dR2017a(i2, 0, (emlrtECInfo *)&b_emlrtECI, &st);
    }
  }

  st.site = &e_emlrtRSI;
  b_st.site = &j_emlrtRSI;
  vlen = A->size[1];
  i2 = A->size[1];
  if (vlen != i2) {
    y = NULL;
    m0 = emlrtCreateCharArray(2, iv2);
    emlrtInitCharArrayR2013a(&st, 15, m0, &u[0]);
    emlrtAssign(&y, m0);
    b_st.site = &ec_emlrtRSI;
    error(&b_st, y, (emlrtMCInfo *)&emlrtMCI);
  }

  emxInit_struct_T1(&st, &r0, 2, &e_emlrtRTEI, true);
  i2 = r0->size[0] * r0->size[1];
  r0->size[0] = 1;
  r0->size[1] = vlen;
  emxEnsureCapacity_struct_T(sp, r0, i2, &e_emlrtRTEI);
  for (i2 = 0; i2 < vlen; i2++) {
    r0->data[i2] = r1;
  }

  cast(sp, r0, nodes);
  j = 1;
  emxFree_struct_T1(&r0);
  emxInit_int32_T(sp, &ind, 1, &h_emlrtRTEI, true);
  emxInit_int32_T(sp, &ii, 1, &m_emlrtRTEI, true);
  emxInit_real_T1(sp, &x, 1, &n_emlrtRTEI, true);
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
    st.site = &f_emlrtRSI;
    i2 = A->size[1];
    i3 = (j - 1) + 1;
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&m_emlrtBCI, &st);
    }

    b_st.site = &k_emlrtRSI;
    idx = 0;
    i2 = ii->size[0];
    ii->size[0] = i4;
    emxEnsureCapacity_int32_T(&b_st, ii, i2, &f_emlrtRTEI);
    c_st.site = &l_emlrtRSI;
    if (overflow) {
      d_st.site = &n_emlrtRSI;
      e_st.site = &n_emlrtRSI;
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
      emlrtErrorWithMessageIdR2012b(&b_st, &ab_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (i6 == 1) {
      if (idx == 0) {
        i2 = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity_int32_T(&b_st, ii, i2, &g_emlrtRTEI);
      }
    } else {
      if (1 > idx) {
        i2 = 0;
      } else {
        i2 = idx;
      }

      c_st.site = &m_emlrtRSI;
      nonSingletonDimFound = !(ii->size[0] != 1);
      if (nonSingletonDimFound) {
        nonSingletonDimFound = false;
        if (i2 != 1) {
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

      d_st.site = &o_emlrtRSI;
      if (nonSingletonDimFound) {
        emlrtErrorWithMessageIdR2012b(&d_st, &y_emlrtRTEI,
          "Coder:FE:PotentialVectorVector", 0);
      }

      i3 = ii->size[0];
      ii->size[0] = i2;
      emxEnsureCapacity_int32_T(&b_st, ii, i3, &g_emlrtRTEI);
    }

    i2 = ind->size[0];
    ind->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&st, ind, i2, &h_emlrtRTEI);
    vlen = ii->size[0];
    for (i2 = 0; i2 < vlen; i2++) {
      ind->data[i2] = ii->data[i2];
    }

    st.site = &g_emlrtRSI;
    vlen = ind->size[0];
    for (i2 = 0; i2 < vlen; i2++) {
      i3 = ind->data[i2];
      if (!((i3 >= 1) && (i3 <= b_A))) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, b_A, (emlrtBCInfo *)&o_emlrtBCI,
          &st);
      }
    }

    i2 = A->size[1];
    i3 = (j - 1) + 1;
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&l_emlrtBCI, &st);
    }

    i2 = x->size[0];
    x->size[0] = ind->size[0];
    emxEnsureCapacity_real_T1(&st, x, i2, &i_emlrtRTEI);
    vlen = ind->size[0];
    for (i2 = 0; i2 < vlen; i2++) {
      x->data[i2] = A->data[(ind->data[i2] + A->size[0] * (j - 1)) - 1];
    }

    b_st.site = &p_emlrtRSI;
    sort(&b_st, x, ii);
    i2 = x->size[0];
    x->size[0] = ii->size[0];
    emxEnsureCapacity_real_T1(&st, x, i2, &j_emlrtRTEI);
    vlen = ii->size[0];
    for (i2 = 0; i2 < vlen; i2++) {
      x->data[i2] = ii->data[i2];
    }

    /*  sorting connections from the heaviest to the lightest */
    i2 = x_init->size[1];
    i3 = (j - 1) + 1;
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&k_emlrtBCI, sp);
    }

    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&p_emlrtBCI, sp);
    }

    nodes->data[j - 1].x = 0.0;
    idx = ind->size[0];
    b_nodes = nodes->size[1];
    if (!((j >= 1) && (j <= b_nodes))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, b_nodes, (emlrtBCInfo *)&q_emlrtBCI,
        sp);
    }

    i2 = nodes->data[j - 1].neigh->size[0];
    nodes->data[j - 1].neigh->size[0] = x->size[0];
    emxEnsureCapacity_real_T1(sp, nodes->data[j - 1].neigh, i2, &k_emlrtRTEI);
    vlen = x->size[0];
    for (i2 = 0; i2 < vlen; i2++) {
      i3 = (int32_T)x->data[i2];
      if (!((i3 >= 1) && (i3 <= idx))) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, idx, (emlrtBCInfo *)&r_emlrtBCI, sp);
      }

      if (!((j >= 1) && (j <= b_nodes))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, b_nodes, (emlrtBCInfo *)&q_emlrtBCI,
          sp);
      }

      nodes->data[j - 1].neigh->data[i2] = ind->data[i3 - 1];
    }

    idx = ind->size[0];
    i2 = A->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&j_emlrtBCI, sp);
    }

    b_nodes = nodes->size[1];
    if (!((j >= 1) && (j <= b_nodes))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, b_nodes, (emlrtBCInfo *)&s_emlrtBCI,
        sp);
    }

    i2 = nodes->data[j - 1].w->size[0];
    nodes->data[j - 1].w->size[0] = x->size[0];
    emxEnsureCapacity_real_T1(sp, nodes->data[j - 1].w, i2, &l_emlrtRTEI);
    vlen = x->size[0];
    for (i2 = 0; i2 < vlen; i2++) {
      i3 = (int32_T)x->data[i2];
      if (!((i3 >= 1) && (i3 <= idx))) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, idx, (emlrtBCInfo *)&u_emlrtBCI, sp);
      }

      i3 = ind->data[i3 - 1];
      if (!((i3 >= 1) && (i3 <= c_A))) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, c_A, (emlrtBCInfo *)&t_emlrtBCI, sp);
      }

      if (!((j >= 1) && (j <= b_nodes))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, b_nodes, (emlrtBCInfo *)&s_emlrtBCI,
          sp);
      }

      nodes->data[j - 1].w->data[i2] = A->data[(i3 + A->size[0] * (j - 1)) - 1];
    }

    st.site = &h_emlrtRSI;
    vlen = ind->size[0];
    for (i2 = 0; i2 < vlen; i2++) {
      i3 = ind->data[i2];
      if (!((i3 >= 1) && (i3 <= d_A))) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, d_A, (emlrtBCInfo *)&v_emlrtBCI,
          &st);
      }
    }

    i2 = A->size[1];
    i3 = (j - 1) + 1;
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&i_emlrtBCI, &st);
    }

    b_st.site = &vb_emlrtRSI;
    if ((ind->size[0] == 1) || (ind->size[0] != 1)) {
      nonSingletonDimFound = true;
    } else {
      nonSingletonDimFound = false;
    }

    if (!nonSingletonDimFound) {
      emlrtErrorWithMessageIdR2012b(&b_st, &x_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    c_st.site = &wb_emlrtRSI;
    vlen = ind->size[0];
    if (ind->size[0] == 0) {
      b_y = 0.0;
    } else {
      d_st.site = &xb_emlrtRSI;
      b_y = A->data[(ind->data[0] + A->size[0] * (j - 1)) - 1];
      e_st.site = &yb_emlrtRSI;
      nonSingletonDimFound = ((!(2 > ind->size[0])) && (ind->size[0] >
        2147483646));
      if (nonSingletonDimFound) {
        f_st.site = &n_emlrtRSI;
        g_st.site = &n_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }

      for (idx = 2; idx <= vlen; idx++) {
        b_y += A->data[(ind->data[idx - 1] + A->size[0] * (j - 1)) - 1];
      }
    }

    i2 = Theta_el->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&w_emlrtBCI, sp);
    }

    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    i2 = nodes->size[1];
    if (!((j >= 1) && (j <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    getParStruct(Theta_el->data[j - 1], b_y, (real_T)ind->size[0], &nodes->
                 data[j - 1].par.Iext, &nodes->data[j - 1].par.Isyn,
                 &nodes->data[j - 1].par.kInp, &nodes->data[j - 1].par.Theta,
                 &nodes->data[j - 1].par.W, &nodes->data[j - 1].par.n,
                 &nodes->data[j - 1].par.nInp, &nodes->data[j - 1].par.spTime);
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
