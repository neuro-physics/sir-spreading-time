/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fillUpMatrix.cpp
 *
 * Code generation for function 'fillUpMatrix'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "NetworkActivationTime.h"
#include "fillUpMatrix.h"
#include "NetworkActivationTime_emxutil.h"
#include "GetSimulationParam.h"
#include "eml_int_forloop_overflow_check.h"
#include "eml_setop.h"
#include "sort1.h"
#include "randperm.h"
#include "assertValidSizeArg.h"
#include "NetworkActivationTime_mexutil.h"
#include "NetworkActivationTime_data.h"

/* Variable Definitions */
static emlrtRSInfo ad_emlrtRSI = { 14, /* lineNo */
  "fillUpMatrix",                      /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pathName */
};

static emlrtRSInfo bd_emlrtRSI = { 21, /* lineNo */
  "fillUpMatrix",                      /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 27, /* lineNo */
  "fillUpMatrix",                      /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pathName */
};

static emlrtRSInfo dd_emlrtRSI = { 28, /* lineNo */
  "fillUpMatrix",                      /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pathName */
};

static emlrtRSInfo gd_emlrtRSI = { 23, /* lineNo */
  "intersect",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\intersect.m"/* pathName */
};

static emlrtRSInfo hd_emlrtRSI = { 70, /* lineNo */
  "eml_setop",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pathName */
};

static emlrtRSInfo ud_emlrtRSI = { 119,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 12,/* lineNo */
  5,                                   /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 14,/* lineNo */
  36,                                  /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 21,/* lineNo */
  7,                                   /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 21,/* lineNo */
  16,                                  /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 28,/* lineNo */
  32,                                  /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 21,/* lineNo */
  21,                                  /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 15,/* lineNo */
  13,                                  /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 15,/* lineNo */
  18,                                  /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 22,/* lineNo */
  7,                                   /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = { 22,/* lineNo */
  18,                                  /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 22,/* lineNo */
  23,                                  /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = { 14,/* lineNo */
  9,                                   /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtDCInfo i_emlrtDCI = { 21,  /* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m",/* pName */
  4                                    /* checkKind */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  22,                                  /* lineNo */
  5,                                   /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  16,                                  /* colNo */
  "M",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  8,                                   /* colNo */
  "M",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 22,  /* lineNo */
  8,                                   /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  28,                                  /* colNo */
  "M",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 22,  /* lineNo */
  28,                                  /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  25,                                  /* colNo */
  "M",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  21,                                  /* lineNo */
  5,                                   /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  10,                                  /* colNo */
  "M",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 21,  /* lineNo */
  10,                                  /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  7,                                   /* colNo */
  "M",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  32,                                  /* colNo */
  "M",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  30,                                  /* colNo */
  "M",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo e_emlrtECI = { -1,  /* nDims */
  15,                                  /* lineNo */
  9,                                   /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  11,                                  /* colNo */
  "M",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  26,                                  /* colNo */
  "A",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  24,                                  /* colNo */
  "A",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  22,                                  /* colNo */
  "A",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  42,                                  /* colNo */
  "A",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  40,                                  /* colNo */
  "A",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  38,                                  /* colNo */
  "A",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 12,  /* lineNo */
  17,                                  /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 12,  /* lineNo */
  5,                                   /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
void fillUpMatrix(const emlrtStack *sp, const emxArray_real_T *A, real_T m,
                  real_T n, real_T N, emxArray_real_T *M)
{
  real_T mm;
  real_T nn;
  int32_T i6;
  int32_T ibcol;
  int32_T iacol;
  emxArray_real_T *r;
  emxArray_real_T *x;
  emxArray_real_T *varargin_2;
  emxArray_real_T *c;
  emxArray_int32_T *ia;
  emxArray_int32_T *ib;
  real_T b_m;
  int32_T ibmat;
  int32_T loop_ub;
  int32_T outsize_idx_0;
  int32_T i7;
  const mxArray *y;
  const mxArray *m2;
  static const int32_T iv5[2] = { 1, 15 };

  int32_T i8;
  emxArray_real_T *b_M;
  static const int32_T iv6[2] = { 1, 15 };

  boolean_T overflow;
  int32_T b_ia[2];
  int32_T iv7[2];
  int32_T k;
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

  /*  M is a matrix m X n */
  /*  composed of A (top left corner) */
  /*  if size(A) > size(M), then A is trimmed to fit M */
  /*  if number of cols of A is less than n, then the remaining n-size(A,2) cols of each line of A are */
  /*        filled with randperm(N,n-size(A,2)) numbers not contained in the given line of A */
  /*  if number of rows of A is less than m, the matrix (with given corrections) is periodically */
  /*        repeated, one below each other. */
  mm = muDoubleScalarMin(m, (real_T)A->size[0]);
  nn = muDoubleScalarMin(n, (real_T)A->size[1]);
  i6 = M->size[0] * M->size[1];
  M->size[0] = (int32_T)m;
  if (n != (int32_T)muDoubleScalarFloor(n)) {
    emlrtIntegerCheckR2012b(n, (emlrtDCInfo *)&m_emlrtDCI, sp);
  }

  M->size[1] = (int32_T)n;
  emxEnsureCapacity_real_T1(sp, M, i6, &ib_emlrtRTEI);
  if (n != (int32_T)muDoubleScalarFloor(n)) {
    emlrtIntegerCheckR2012b(n, (emlrtDCInfo *)&n_emlrtDCI, sp);
  }

  ibcol = (int32_T)m * (int32_T)n;
  for (i6 = 0; i6 < ibcol; i6++) {
    M->data[i6] = 0.0;
  }

  iacol = 0;
  emxInit_real_T(sp, &r, 2, &tb_emlrtRTEI, true);
  emxInit_real_T(sp, &x, 2, &jb_emlrtRTEI, true);
  emxInit_real_T(sp, &varargin_2, 2, &mb_emlrtRTEI, true);
  emxInit_real_T(sp, &c, 2, &ub_emlrtRTEI, true);
  emxInit_int32_T(sp, &ia, 1, &ub_emlrtRTEI, true);
  emxInit_int32_T(sp, &ib, 1, &ub_emlrtRTEI, true);
  if (0 <= (int32_T)mm - 1) {
    b_m = n - nn;
    if (1.0 > nn) {
      ibmat = 0;
      loop_ub = 0;
    } else {
      i6 = A->size[1];
      if (!(1 <= i6)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i6, (emlrtBCInfo *)&pb_emlrtBCI, sp);
      }

      i6 = A->size[1];
      ibmat = (int32_T)nn;
      if (!(ibmat <= i6)) {
        emlrtDynamicBoundsCheckR2012b(ibmat, 1, i6, (emlrtBCInfo *)&ob_emlrtBCI,
          sp);
      }

      i6 = A->size[1];
      if (!(1 <= i6)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i6, (emlrtBCInfo *)&mb_emlrtBCI, sp);
      }

      i6 = A->size[1];
      loop_ub = (int32_T)nn;
      if (!(loop_ub <= i6)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i6, (emlrtBCInfo *)
          &lb_emlrtBCI, sp);
      }
    }
  }

  while (iacol <= (int32_T)mm - 1) {
    st.site = &ad_emlrtRSI;
    i6 = A->size[0];
    if (!((iacol + 1 >= 1) && (iacol + 1 <= i6))) {
      emlrtDynamicBoundsCheckR2012b(iacol + 1, 1, i6, (emlrtBCInfo *)
        &qb_emlrtBCI, &st);
    }

    outsize_idx_0 = iacol + 1;
    i6 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = ibmat;
    emxEnsureCapacity_real_T1(&st, x, i6, &jb_emlrtRTEI);
    for (i6 = 0; i6 < ibmat; i6++) {
      x->data[x->size[0] * i6] = A->data[(outsize_idx_0 + A->size[0] * i6) - 1];
    }

    do {
      b_st.site = &cd_emlrtRSI;
      randperm(&b_st, N, b_m, r);
      b_st.site = &dd_emlrtRSI;
      i6 = varargin_2->size[0] * varargin_2->size[1];
      varargin_2->size[0] = 1;
      varargin_2->size[1] = x->size[1];
      emxEnsureCapacity_real_T1(&b_st, varargin_2, i6, &mb_emlrtRTEI);
      ibcol = x->size[0] * x->size[1];
      for (i6 = 0; i6 < ibcol; i6++) {
        varargin_2->data[i6] = x->data[i6];
      }

      c_st.site = &ed_emlrtRSI;
      c_sort(&c_st, varargin_2);
      b_st.site = &dd_emlrtRSI;
      c_st.site = &gd_emlrtRSI;
      d_st.site = &hd_emlrtRSI;
      do_vectors(&d_st, r, varargin_2, c, ia, ib);
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    } while (!(c->size[1] == 0));

    /*  if n < size(A,2), then r = [] */
    i6 = M->size[0];
    i7 = iacol + 1;
    if (!((i7 >= 1) && (i7 <= i6))) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, i6, (emlrtBCInfo *)&kb_emlrtBCI, sp);
    }

    ibcol = M->size[1];
    i6 = ia->size[0];
    ia->size[0] = ibcol;
    emxEnsureCapacity_int32_T(sp, ia, i6, &ob_emlrtRTEI);
    for (i6 = 0; i6 < ibcol; i6++) {
      ia->data[i6] = i6;
    }

    i6 = A->size[0];
    if (!((iacol + 1 >= 1) && (iacol + 1 <= i6))) {
      emlrtDynamicBoundsCheckR2012b(iacol + 1, 1, i6, (emlrtBCInfo *)
        &nb_emlrtBCI, sp);
    }

    outsize_idx_0 = iacol + 1;
    i6 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = loop_ub + r->size[1];
    emxEnsureCapacity_real_T1(sp, x, i6, &pb_emlrtRTEI);
    for (i6 = 0; i6 < loop_ub; i6++) {
      x->data[x->size[0] * i6] = A->data[(outsize_idx_0 + A->size[0] * i6) - 1];
    }

    ibcol = r->size[1];
    for (i6 = 0; i6 < ibcol; i6++) {
      x->data[x->size[0] * (i6 + loop_ub)] = r->data[r->size[0] * i6];
    }

    iv7[0] = 1;
    iv7[1] = ia->size[0];
    emlrtSubAssignSizeCheckR2012b(&iv7[0], 2, &(*(int32_T (*)[2])x->size)[0], 2,
      (emlrtECInfo *)&e_emlrtECI, sp);
    ibcol = x->size[1];
    for (i6 = 0; i6 < ibcol; i6++) {
      M->data[iacol + M->size[0] * ia->data[i6]] = x->data[x->size[0] * i6];
    }

    iacol++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&c);
  emxFree_real_T(&varargin_2);
  emxFree_real_T(&x);
  emxFree_real_T(&r);
  if (!(m <= A->size[0])) {
    mm = muDoubleScalarFloor(m / (real_T)A->size[0]);
    if (1 > A->size[0]) {
      i7 = 0;
    } else {
      i6 = M->size[0];
      if (!(1 <= i6)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i6, (emlrtBCInfo *)&jb_emlrtBCI, sp);
      }

      i6 = M->size[0];
      i7 = A->size[0];
      if (!((i7 >= 1) && (i7 <= i6))) {
        emlrtDynamicBoundsCheckR2012b(i7, 1, i6, (emlrtBCInfo *)&ib_emlrtBCI, sp);
      }
    }

    nn = mm * (real_T)A->size[0];
    if (1.0 > nn) {
      ibcol = 0;
    } else {
      i6 = M->size[0];
      if (!(1 <= i6)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i6, (emlrtBCInfo *)&hb_emlrtBCI, sp);
      }

      i6 = M->size[0];
      if (nn != (int32_T)nn) {
        emlrtIntegerCheckR2012b(nn, (emlrtDCInfo *)&l_emlrtDCI, sp);
      }

      ibcol = (int32_T)nn;
      if (!((ibcol >= 1) && (ibcol <= i6))) {
        emlrtDynamicBoundsCheckR2012b(ibcol, 1, i6, (emlrtBCInfo *)&gb_emlrtBCI,
          sp);
      }
    }

    i6 = ia->size[0];
    ia->size[0] = ibcol;
    emxEnsureCapacity_int32_T(sp, ia, i6, &kb_emlrtRTEI);
    for (i6 = 0; i6 < ibcol; i6++) {
      ia->data[i6] = i6;
    }

    ibcol = M->size[1];
    i6 = ib->size[0];
    ib->size[0] = ibcol;
    emxEnsureCapacity_int32_T(sp, ib, i6, &lb_emlrtRTEI);
    for (i6 = 0; i6 < ibcol; i6++) {
      ib->data[i6] = i6;
    }

    st.site = &bd_emlrtRSI;
    b_st.site = &n_emlrtRSI;
    b_assertValidSizeArg(&b_st, mm);
    if (!(mm >= 0.0)) {
      emlrtNonNegativeCheckR2012b(mm, (emlrtDCInfo *)&i_emlrtDCI, &st);
    }

    outsize_idx_0 = i7 * (int32_T)mm;
    if (!(outsize_idx_0 == (real_T)i7 * (real_T)(int32_T)mm)) {
      y = NULL;
      m2 = emlrtCreateCharArray(2, iv5);
      emlrtInitCharArrayR2013a(&st, 15, m2, &cv0[0]);
      emlrtAssign(&y, m2);
      b_st.site = &me_emlrtRSI;
      d_error(&b_st, y, (emlrtMCInfo *)&emlrtMCI);
    }

    i6 = M->size[1];
    i8 = M->size[1];
    if (i6 != i8) {
      y = NULL;
      m2 = emlrtCreateCharArray(2, iv6);
      emlrtInitCharArrayR2013a(&st, 15, m2, &cv0[0]);
      emlrtAssign(&y, m2);
      b_st.site = &me_emlrtRSI;
      d_error(&b_st, y, (emlrtMCInfo *)&emlrtMCI);
    }

    emxInit_real_T(&st, &b_M, 2, &sb_emlrtRTEI, true);
    i8 = b_M->size[0] * b_M->size[1];
    b_M->size[0] = outsize_idx_0;
    b_M->size[1] = i6;
    emxEnsureCapacity_real_T1(&st, b_M, i8, &nb_emlrtRTEI);
    i8 = M->size[1];
    if (!((i7 == 0) || (i8 == 0))) {
      if (outsize_idx_0 == 0) {
        overflow = true;
      } else if (i6 == 0) {
        overflow = true;
      } else {
        overflow = false;
      }

      if (!overflow) {
        i6 = M->size[1];
        b_st.site = &sd_emlrtRSI;
        i8 = M->size[1];
        if (1 > i8) {
          overflow = false;
        } else {
          i8 = M->size[1];
          overflow = (i8 > 2147483646);
        }

        if (overflow) {
          c_st.site = &r_emlrtRSI;
          d_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (outsize_idx_0 = 0; outsize_idx_0 + 1 <= i6; outsize_idx_0++) {
          iacol = outsize_idx_0 * i7;
          ibmat = outsize_idx_0 * (i7 * (int32_T)mm);
          b_st.site = &td_emlrtRSI;
          if ((!(1 > (int32_T)mm)) && ((int32_T)mm > 2147483646)) {
            c_st.site = &r_emlrtRSI;
            d_st.site = &r_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }

          for (loop_ub = 1; loop_ub <= (int32_T)mm; loop_ub++) {
            ibcol = ibmat + (loop_ub - 1) * i7;
            b_st.site = &ud_emlrtRSI;
            for (k = 0; k + 1 <= i7; k++) {
              i8 = iacol + k;
              b_M->data[ibcol + k] = M->data[i8 % i7 + M->size[0] * (i8 / i7)];
            }
          }
        }
      }
    }

    b_ia[0] = ia->size[0];
    b_ia[1] = ib->size[0];
    emlrtSubAssignSizeCheckR2012b(&b_ia[0], 2, &(*(int32_T (*)[2])b_M->size)[0],
      2, (emlrtECInfo *)&d_emlrtECI, sp);
    ibcol = b_M->size[1];
    for (i6 = 0; i6 < ibcol; i6++) {
      ibmat = b_M->size[0];
      for (i7 = 0; i7 < ibmat; i7++) {
        M->data[ia->data[i7] + M->size[0] * ib->data[i6]] = b_M->data[i7 +
          b_M->size[0] * i6];
      }
    }

    nn = m - mm * (real_T)A->size[0];
    if (1.0 > nn) {
      ibcol = 0;
    } else {
      i6 = M->size[0];
      if (!(1 <= i6)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i6, (emlrtBCInfo *)&fb_emlrtBCI, sp);
      }

      i6 = M->size[0];
      if (nn != (int32_T)muDoubleScalarFloor(nn)) {
        emlrtIntegerCheckR2012b(nn, (emlrtDCInfo *)&k_emlrtDCI, sp);
      }

      ibcol = (int32_T)nn;
      if (!((ibcol >= 1) && (ibcol <= i6))) {
        emlrtDynamicBoundsCheckR2012b(ibcol, 1, i6, (emlrtBCInfo *)&eb_emlrtBCI,
          sp);
      }
    }

    nn = mm * (real_T)A->size[0] + 1.0;
    if (nn > m) {
      i6 = 0;
      i8 = 0;
    } else {
      i6 = M->size[0];
      if (nn != (int32_T)nn) {
        emlrtIntegerCheckR2012b(nn, (emlrtDCInfo *)&j_emlrtDCI, sp);
      }

      i7 = (int32_T)nn;
      if (!((i7 >= 1) && (i7 <= i6))) {
        emlrtDynamicBoundsCheckR2012b(i7, 1, i6, (emlrtBCInfo *)&db_emlrtBCI, sp);
      }

      i6 = i7 - 1;
      i7 = M->size[0];
      i8 = (int32_T)m;
      if (!((i8 >= 1) && (i8 <= i7))) {
        emlrtDynamicBoundsCheckR2012b(i8, 1, i7, (emlrtBCInfo *)&cb_emlrtBCI, sp);
      }
    }

    i7 = ia->size[0];
    ia->size[0] = i8 - i6;
    emxEnsureCapacity_int32_T(sp, ia, i7, &qb_emlrtRTEI);
    ibmat = i8 - i6;
    for (i7 = 0; i7 < ibmat; i7++) {
      ia->data[i7] = i6 + i7;
    }

    ibmat = M->size[1];
    i6 = ib->size[0];
    ib->size[0] = ibmat;
    emxEnsureCapacity_int32_T(sp, ib, i6, &rb_emlrtRTEI);
    for (i6 = 0; i6 < ibmat; i6++) {
      ib->data[i6] = i6;
    }

    i6 = M->size[1];
    b_ia[0] = ia->size[0];
    b_ia[1] = ib->size[0];
    iv7[0] = ibcol;
    iv7[1] = i6;
    emlrtSubAssignSizeCheckR2012b(&b_ia[0], 2, &iv7[0], 2, (emlrtECInfo *)
      &c_emlrtECI, sp);
    outsize_idx_0 = M->size[1];
    i6 = b_M->size[0] * b_M->size[1];
    b_M->size[0] = ibcol;
    b_M->size[1] = outsize_idx_0;
    emxEnsureCapacity_real_T1(sp, b_M, i6, &sb_emlrtRTEI);
    for (i6 = 0; i6 < outsize_idx_0; i6++) {
      for (i7 = 0; i7 < ibcol; i7++) {
        b_M->data[i7 + b_M->size[0] * i6] = M->data[i7 + M->size[0] * i6];
      }
    }

    ibcol = b_M->size[1];
    for (i6 = 0; i6 < ibcol; i6++) {
      ibmat = b_M->size[0];
      for (i7 = 0; i7 < ibmat; i7++) {
        M->data[ia->data[i7] + M->size[0] * ib->data[i6]] = b_M->data[i7 +
          b_M->size[0] * i6];
      }
    }

    emxFree_real_T(&b_M);
  }

  emxFree_int32_T(&ib);
  emxFree_int32_T(&ia);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (fillUpMatrix.cpp) */
