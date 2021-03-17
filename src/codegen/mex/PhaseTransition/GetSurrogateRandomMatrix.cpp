/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * GetSurrogateRandomMatrix.cpp
 *
 * Code generation for function 'GetSurrogateRandomMatrix'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "PhaseTransition.h"
#include "GetSurrogateRandomMatrix.h"
#include "PhaseTransition_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sort1.h"
#include "randn.h"
#include "scalexpAlloc.h"
#include "indexShapeCheck.h"
#include "PhaseTransition_data.h"

/* Variable Definitions */
static emlrtRSInfo fd_emlrtRSI = { 25, /* lineNo */
  "GetSurrogateRandomMatrix",          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSurrogateRandomMatrix.m"/* pathName */
};

static emlrtRSInfo gd_emlrtRSI = { 26, /* lineNo */
  "GetSurrogateRandomMatrix",          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSurrogateRandomMatrix.m"/* pathName */
};

static emlrtRSInfo hd_emlrtRSI = { 27, /* lineNo */
  "GetSurrogateRandomMatrix",          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSurrogateRandomMatrix.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 28, /* lineNo */
  "GetSurrogateRandomMatrix",          /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSurrogateRandomMatrix.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 14, /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 80, /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 11, /* lineNo */
  "normrnd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\stats\\eml\\normrnd.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 1,  /* lineNo */
  "rnd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\rnd.p"/* pathName */
};

static emlrtRSInfo nd_emlrtRSI = { 1,  /* lineNo */
  "normrnd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\private\\normrnd.p"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 47, /* lineNo */
  "sxalloc",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sxalloc.m"/* pathName */
};

static emlrtRSInfo pd_emlrtRSI = { 31, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pathName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "GetSurrogateRandomMatrix",          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSurrogateRandomMatrix.m"/* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 25,/* lineNo */
  16,                                  /* colNo */
  "GetSurrogateRandomMatrix",          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSurrogateRandomMatrix.m"/* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = { 25,/* lineNo */
  5,                                   /* colNo */
  "GetSurrogateRandomMatrix",          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSurrogateRandomMatrix.m"/* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 26,/* lineNo */
  5,                                   /* colNo */
  "GetSurrogateRandomMatrix",          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSurrogateRandomMatrix.m"/* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 47,/* lineNo */
  9,                                   /* colNo */
  "sxalloc",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sxalloc.m"/* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 47,/* lineNo */
  57,                                  /* colNo */
  "sxalloc",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sxalloc.m"/* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = { 27,/* lineNo */
  17,                                  /* colNo */
  "GetSurrogateRandomMatrix",          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSurrogateRandomMatrix.m"/* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = { 32,/* lineNo */
  11,                                  /* colNo */
  "GetSurrogateRandomMatrix",          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSurrogateRandomMatrix.m"/* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = { 35,/* lineNo */
  7,                                   /* colNo */
  "GetSurrogateRandomMatrix",          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSurrogateRandomMatrix.m"/* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = { 27,/* lineNo */
  5,                                   /* colNo */
  "GetSurrogateRandomMatrix",          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSurrogateRandomMatrix.m"/* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = { 17,/* lineNo */
  19,                                  /* colNo */
  "scalexpAlloc",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m"/* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = { 126,/* lineNo */
  19,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  35,                                  /* lineNo */
  5,                                   /* colNo */
  "GetSurrogateRandomMatrix",          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSurrogateRandomMatrix.m"/* pName */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  32,                                  /* lineNo */
  9,                                   /* colNo */
  "GetSurrogateRandomMatrix",          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSurrogateRandomMatrix.m"/* pName */
};

static emlrtBCInfo vc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  11,                                  /* colNo */
  "A",                                 /* aName */
  "GetSurrogateRandomMatrix",          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSurrogateRandomMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  11,                                  /* colNo */
  "w",                                 /* aName */
  "GetSurrogateRandomMatrix",          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSurrogateRandomMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  7,                                   /* colNo */
  "M",                                 /* aName */
  "GetSurrogateRandomMatrix",          /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSurrogateRandomMatrix.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void GetSurrogateRandomMatrix(const emlrtStack *sp, emxArray_real_T *A, real_T
  mu, real_T sigma)
{
  emxArray_boolean_T *x;
  int32_T i14;
  int32_T nx;
  int32_T idx;
  boolean_T nonSingletonDimFound;
  emxArray_int32_T *ii;
  int32_T b_ii;
  boolean_T exitg1;
  int32_T iv12[2];
  emxArray_int32_T *ind;
  emxArray_real_T *w;
  emxArray_real_T *wSub;
  emxArray_boolean_T *r1;
  real_T varargin_1[2];
  emxArray_real_T *b_x;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T(sp, &x, 2, &sb_emlrtRTEI, true);

  /*  generates new weights based on the weight distribution of adjacency matrix A */
  /*  considering that A has Gaussian distributed weights */
  /*  */
  /*  1) fits a Gaussian function to the distribution of weights P(A_ij) to estimate mean and std */
  /*  2) generates numel(A~=0) Gaussian random numbers with the estimated mean and std; */
  /*     if rescaleWeights == true, then the surrogate weights are contained within the boundaries minmax(A_ij) */
  /*  3) replaces orderly the elements of A, from the smallest to the largest */
  /*     i.e. the smallest element of A is replaced by the smallest random element, second smallest by the second random smallest, and so on */
  /*  */
  /*  based on algorithm by: */
  /*  Honey CJ, Sporns O, Cammoun L, Gigandet X, Thiran JP, Meuli R, Hagmann P. */
  /*  Predicting human resting-state functional connectivity from structural connectivity. */
  /*  Proc Natl Acad Sci USA. 2009 Feb 10;106(6):2035-40. doi: 10.1073/pnas.0811168106. Epub 2009 Feb 2. */
  st.site = &fd_emlrtRSI;
  i14 = x->size[0] * x->size[1];
  x->size[0] = A->size[0];
  x->size[1] = A->size[1];
  emxEnsureCapacity_boolean_T(&st, x, i14, &sb_emlrtRTEI);
  nx = A->size[0] * A->size[1];
  for (i14 = 0; i14 < nx; i14++) {
    x->data[i14] = (A->data[i14] != 0.0);
  }

  b_st.site = &hb_emlrtRSI;
  nx = x->size[0] * x->size[1];
  idx = 0;
  if ((!((x->size[0] == 1) || (x->size[1] == 1))) || (x->size[0] != 1) ||
      (x->size[1] <= 1)) {
    nonSingletonDimFound = true;
  } else {
    nonSingletonDimFound = false;
  }

  if (!nonSingletonDimFound) {
    emlrtErrorWithMessageIdR2012b(&b_st, &pc_emlrtRTEI,
      "Coder:toolbox:find_incompatibleShape", 0);
  }

  emxInit_int32_T(&b_st, &ii, 1, &w_emlrtRTEI, true);
  i14 = ii->size[0];
  ii->size[0] = nx;
  emxEnsureCapacity_int32_T(&b_st, ii, i14, &o_emlrtRTEI);
  c_st.site = &ib_emlrtRSI;
  if ((!(1 > nx)) && (nx > 2147483646)) {
    d_st.site = &gb_emlrtRSI;
    e_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  b_ii = 1;
  exitg1 = false;
  while ((!exitg1) && (b_ii <= nx)) {
    if (x->data[b_ii - 1]) {
      idx++;
      ii->data[idx - 1] = b_ii;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    } else {
      b_ii++;
    }
  }

  emxFree_boolean_T(&x);
  if (!(idx <= nx)) {
    emlrtErrorWithMessageIdR2012b(&b_st, &hc_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (nx == 1) {
    if (idx == 0) {
      i14 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity_int32_T(&b_st, ii, i14, &p_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i14 = 0;
    } else {
      i14 = idx;
    }

    iv12[0] = 1;
    iv12[1] = i14;
    c_st.site = &jb_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv12);
    idx = ii->size[0];
    ii->size[0] = i14;
    emxEnsureCapacity_int32_T(&b_st, ii, idx, &p_emlrtRTEI);
  }

  emxInit_int32_T(&b_st, &ind, 1, &tb_emlrtRTEI, true);
  i14 = ind->size[0];
  ind->size[0] = ii->size[0];
  emxEnsureCapacity_int32_T(&st, ind, i14, &tb_emlrtRTEI);
  nx = ii->size[0];
  for (i14 = 0; i14 < nx; i14++) {
    ind->data[i14] = ii->data[i14];
  }

  st.site = &gd_emlrtRSI;
  nonSingletonDimFound = false;
  if (A->size[0] != 1) {
    nonSingletonDimFound = true;
  }

  if (A->size[1] != 1) {
    if (nonSingletonDimFound) {
      nonSingletonDimFound = false;
    } else {
      nonSingletonDimFound = true;
    }
  }

  if (nonSingletonDimFound) {
    nonSingletonDimFound = false;
    if (ind->size[0] != 1) {
      nonSingletonDimFound = true;
    }

    if (nonSingletonDimFound) {
      b_st.site = &jd_emlrtRSI;
      nonSingletonDimFound = ((A->size[0] == 1) != (ind->size[0] == 1));
      if (nonSingletonDimFound || (A->size[1] != 1)) {
        nonSingletonDimFound = true;
      } else {
        nonSingletonDimFound = false;
      }

      c_st.site = &kd_emlrtRSI;
      if (nonSingletonDimFound) {
        emlrtErrorWithMessageIdR2012b(&c_st, &mc_emlrtRTEI,
          "Coder:FE:PotentialMatrixMatrix", 0);
      }
    }
  }

  emxInit_real_T(&st, &w, 1, &ub_emlrtRTEI, true);
  b_ii = A->size[0] * A->size[1];
  i14 = w->size[0];
  w->size[0] = ind->size[0];
  emxEnsureCapacity_real_T1(sp, w, i14, &ub_emlrtRTEI);
  nx = ind->size[0];
  for (i14 = 0; i14 < nx; i14++) {
    idx = ind->data[i14];
    if (!((idx >= 1) && (idx <= b_ii))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, b_ii, (emlrtBCInfo *)&vc_emlrtBCI,
        sp);
    }

    w->data[i14] = A->data[idx - 1];
  }

  emxInit_real_T1(sp, &wSub, 2, &bc_emlrtRTEI, true);
  emxInit_boolean_T(sp, &r1, 2, &wb_emlrtRTEI, true);
  st.site = &hd_emlrtRSI;
  b_ii = ind->size[0];
  b_st.site = &ld_emlrtRSI;
  c_st.site = &md_emlrtRSI;
  d_st.site = &nd_emlrtRSI;
  e_st.site = &od_emlrtRSI;
  i14 = wSub->size[0] * wSub->size[1];
  wSub->size[0] = b_ii;
  wSub->size[1] = 1;
  emxEnsureCapacity_real_T(&e_st, wSub, i14, &vb_emlrtRTEI);
  i14 = r1->size[0] * r1->size[1];
  r1->size[0] = b_ii;
  r1->size[1] = 1;
  emxEnsureCapacity_boolean_T(&e_st, r1, i14, &wb_emlrtRTEI);
  for (i14 = 0; i14 < b_ii; i14++) {
    r1->data[i14] = false;
  }

  if (!dimagree(wSub, r1)) {
    emlrtErrorWithMessageIdR2012b(&e_st, &oc_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  emxFree_boolean_T(&r1);
  varargin_1[0] = (uint32_T)b_ii;
  varargin_1[1] = 1.0;
  d_st.site = &nd_emlrtRSI;
  randn(&d_st, varargin_1, wSub);
  i14 = wSub->size[0] * wSub->size[1];
  wSub->size[1] = 1;
  emxEnsureCapacity_real_T(&c_st, wSub, i14, &xb_emlrtRTEI);
  b_ii = wSub->size[0];
  nx = wSub->size[1];
  nx *= b_ii;
  for (i14 = 0; i14 < nx; i14++) {
    wSub->data[i14] = wSub->data[i14] * sigma + mu;
  }

  if (sigma < 0.0) {
    i14 = wSub->size[0] * wSub->size[1];
    wSub->size[1] = 1;
    emxEnsureCapacity_real_T(&c_st, wSub, i14, &xb_emlrtRTEI);
    nx = wSub->size[0];
    for (i14 = 0; i14 < nx; i14++) {
      wSub->data[i14] = rtNaN;
    }
  }

  emxInit_real_T(&c_st, &b_x, 1, &jb_emlrtRTEI, true);
  st.site = &hd_emlrtRSI;
  b_st.site = &pd_emlrtRSI;
  c_sort(&b_st, wSub);
  st.site = &id_emlrtRSI;
  i14 = b_x->size[0];
  b_x->size[0] = w->size[0];
  emxEnsureCapacity_real_T1(&st, b_x, i14, &r_emlrtRTEI);
  nx = w->size[0];
  for (i14 = 0; i14 < nx; i14++) {
    b_x->data[i14] = w->data[i14];
  }

  b_st.site = &lb_emlrtRSI;
  e_sort(&b_st, b_x, ii);
  b_ii = ind->size[0];
  i14 = ii->size[0];
  emxEnsureCapacity_int32_T(sp, ii, i14, &yb_emlrtRTEI);
  nx = ii->size[0];
  emxFree_real_T(&b_x);
  for (i14 = 0; i14 < nx; i14++) {
    idx = ii->data[i14];
    if (!((idx >= 1) && (idx <= b_ii))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, b_ii, (emlrtBCInfo *)&wc_emlrtBCI,
        sp);
    }

    ii->data[i14] = idx;
  }

  i14 = ii->size[0];
  idx = wSub->size[0];
  if (i14 != idx) {
    emlrtSubAssignSizeCheck1dR2017a(i14, idx, (emlrtECInfo *)&d_emlrtECI, sp);
  }

  nx = ii->size[0];
  for (i14 = 0; i14 < nx; i14++) {
    w->data[ii->data[i14] - 1] = wSub->data[i14];
  }

  emxFree_real_T(&wSub);
  b_ii = A->size[0] * A->size[1];
  i14 = ii->size[0];
  ii->size[0] = ind->size[0];
  emxEnsureCapacity_int32_T(sp, ii, i14, &ac_emlrtRTEI);
  nx = ind->size[0];
  for (i14 = 0; i14 < nx; i14++) {
    idx = ind->data[i14];
    if (!((idx >= 1) && (idx <= b_ii))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, b_ii, (emlrtBCInfo *)&xc_emlrtBCI,
        sp);
    }

    ii->data[i14] = idx;
  }

  emxFree_int32_T(&ind);
  i14 = ii->size[0];
  idx = w->size[0];
  if (i14 != idx) {
    emlrtSubAssignSizeCheck1dR2017a(i14, idx, (emlrtECInfo *)&c_emlrtECI, sp);
  }

  nx = w->size[0];
  for (i14 = 0; i14 < nx; i14++) {
    A->data[ii->data[i14] - 1] = w->data[i14];
  }

  emxFree_int32_T(&ii);
  emxFree_real_T(&w);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (GetSurrogateRandomMatrix.cpp) */
