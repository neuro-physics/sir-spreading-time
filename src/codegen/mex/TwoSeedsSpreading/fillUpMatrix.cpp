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
#include "TwoSeedsSpreading.h"
#include "fillUpMatrix.h"
#include "TwoSeedsSpreading_emxutil.h"
#include "GetNodes.h"
#include "eml_int_forloop_overflow_check.h"
#include "eml_setop.h"
#include "sort1.h"
#include "TwoSeedsSpreading_mexutil.h"
#include "TwoSeedsSpreading_data.h"

/* Variable Definitions */
static emlrtRSInfo nb_emlrtRSI = { 14, /* lineNo */
  "fillUpMatrix",                      /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 21, /* lineNo */
  "fillUpMatrix",                      /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 28, /* lineNo */
  "fillUpMatrix",                      /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 27, /* lineNo */
  "fillUpMatrix",                      /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 23, /* lineNo */
  "intersect",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\intersect.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 70, /* lineNo */
  "eml_setop",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pathName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 12,/* lineNo */
  5,                                   /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 21,/* lineNo */
  7,                                   /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 21,/* lineNo */
  21,                                  /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 22,/* lineNo */
  7,                                   /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = { 22,/* lineNo */
  23,                                  /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  38,                                  /* colNo */
  "A",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  22,                                  /* colNo */
  "A",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  11,                                  /* colNo */
  "M",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  30,                                  /* colNo */
  "M",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  32,                                  /* colNo */
  "M",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  7,                                   /* colNo */
  "M",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 21,  /* lineNo */
  10,                                  /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  10,                                  /* colNo */
  "M",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo e_emlrtECI = { -1,  /* nDims */
  21,                                  /* lineNo */
  5,                                   /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  25,                                  /* colNo */
  "M",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 22,  /* lineNo */
  28,                                  /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  28,                                  /* colNo */
  "M",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 22,  /* lineNo */
  8,                                   /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  8,                                   /* colNo */
  "M",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  16,                                  /* colNo */
  "M",                                 /* aName */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo f_emlrtECI = { -1,  /* nDims */
  22,                                  /* lineNo */
  5,                                   /* colNo */
  "fillUpMatrix",                      /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\fillUpMatrix.m"/* pName */
};

static emlrtDCInfo f_emlrtDCI = { 21,  /* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m",/* pName */
  4                                    /* checkKind */
};

static emlrtRTEInfo jd_emlrtRTEI = { 12,/* lineNo */
  15,                                  /* colNo */
  "randperm",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m"/* pName */
};

/* Function Definitions */
void fillUpMatrix(const emlrtStack *sp, const emxArray_real_T *A, real_T m,
                  real_T N, emxArray_real_T *M)
{
  real_T mm;
  int32_T i3;
  int32_T iacol;
  int32_T ibmat;
  int32_T i4;
  real_T d1;
  emxArray_int32_T *r5;
  real_T dv0[2];
  int32_T c_size[2];
  int32_T ia_size[1];
  int32_T ib_size[1];
  boolean_T overflow;
  int32_T outsize_idx_0;
  real_T b_mm;
  const mxArray *y;
  emxArray_real_T *b_M;
  const mxArray *m1;
  static const int32_T iv5[2] = { 1, 15 };

  int32_T itilerow;
  int32_T ibcol;
  int32_T k;
  int32_T iv6[2];
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
  i3 = M->size[0] * M->size[1];
  M->size[0] = (int32_T)m;
  M->size[1] = 2;
  emxEnsureCapacity_real_T(sp, M, i3, &nb_emlrtRTEI);
  iacol = (int32_T)m << 1;
  for (i3 = 0; i3 < iacol; i3++) {
    M->data[i3] = 0.0;
  }

  ibmat = 0;
  while (ibmat <= (int32_T)mm - 1) {
    st.site = &nb_emlrtRSI;
    i3 = A->size[0];
    i4 = ibmat + 1;
    if (!((i4 >= 1) && (i4 <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, i3, (emlrtBCInfo *)&jb_emlrtBCI, &st);
    }

    b_st.site = &qb_emlrtRSI;
    if (!(N == muDoubleScalarFloor(N))) {
      emlrtErrorWithMessageIdR2012b(&b_st, &jd_emlrtRTEI,
        "MATLAB:randperm:inputType", 0);
    }

    b_st.site = &pb_emlrtRSI;
    c_st.site = &rb_emlrtRSI;
    for (i3 = 0; i3 < 2; i3++) {
      dv0[i3] = A->data[ibmat + A->size[0] * i3];
    }

    sort(dv0);
    d_st.site = &sb_emlrtRSI;
    do_vectors(&d_st, dv0, c_size, ia_size, ib_size);

    /*  if n < size(A,2), then r = [] */
    i3 = A->size[0];
    if (!((ibmat + 1 >= 1) && (ibmat + 1 <= i3))) {
      emlrtDynamicBoundsCheckR2012b(ibmat + 1, 1, i3, (emlrtBCInfo *)
        &kb_emlrtBCI, sp);
    }

    iacol = ibmat + 1;
    outsize_idx_0 = M->size[0];
    if (!((ibmat + 1 >= 1) && (ibmat + 1 <= outsize_idx_0))) {
      emlrtDynamicBoundsCheckR2012b(ibmat + 1, 1, outsize_idx_0, (emlrtBCInfo *)
        &lb_emlrtBCI, sp);
    }

    for (i3 = 0; i3 < 2; i3++) {
      M->data[ibmat + M->size[0] * i3] = A->data[(iacol + A->size[0] * i3) - 1];
    }

    ibmat++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  if (!(m <= A->size[0])) {
    mm = muDoubleScalarFloor(m / (real_T)A->size[0]);
    if (1 > A->size[0]) {
      i4 = 0;
    } else {
      i3 = M->size[0];
      if (!(1 <= i3)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i3, (emlrtBCInfo *)&mb_emlrtBCI, sp);
      }

      i3 = M->size[0];
      i4 = A->size[0];
      if (!((i4 >= 1) && (i4 <= i3))) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, i3, (emlrtBCInfo *)&nb_emlrtBCI, sp);
      }
    }

    d1 = mm * (real_T)A->size[0];
    if (1.0 > d1) {
      iacol = 0;
    } else {
      i3 = M->size[0];
      if (!(1 <= i3)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i3, (emlrtBCInfo *)&ob_emlrtBCI, sp);
      }

      if (d1 != (int32_T)d1) {
        emlrtIntegerCheckR2012b(d1, (emlrtDCInfo *)&c_emlrtDCI, sp);
      }

      i3 = M->size[0];
      iacol = (int32_T)d1;
      if (!((iacol >= 1) && (iacol <= i3))) {
        emlrtDynamicBoundsCheckR2012b(iacol, 1, i3, (emlrtBCInfo *)&pb_emlrtBCI,
          sp);
      }
    }

    emxInit_int32_T(sp, &r5, 1, &sb_emlrtRTEI, true);
    i3 = r5->size[0];
    r5->size[0] = iacol;
    emxEnsureCapacity_int32_T1(sp, r5, i3, &ob_emlrtRTEI);
    for (i3 = 0; i3 < iacol; i3++) {
      r5->data[i3] = i3;
    }

    st.site = &ob_emlrtRSI;
    b_st.site = &u_emlrtRSI;
    if ((mm != mm) || muDoubleScalarIsInf(mm)) {
      overflow = false;
    } else {
      overflow = true;
    }

    if (overflow) {
      if ((-2.147483648E+9 > mm) || (2.147483647E+9 < mm)) {
        overflow = false;
      } else {
        overflow = true;
      }

      if (overflow) {
        overflow = true;
      } else {
        overflow = false;
      }
    } else {
      overflow = false;
    }

    if (!overflow) {
      emlrtErrorWithMessageIdR2012b(&b_st, &id_emlrtRTEI,
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
    }

    if (mm <= 0.0) {
      b_mm = 0.0;
    } else {
      b_mm = mm;
    }

    if (!(2.147483647E+9 >= b_mm)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &fd_emlrtRTEI,
        "Coder:MATLAB:pmaxsize", 0);
    }

    if (!(mm >= 0.0)) {
      emlrtNonNegativeCheckR2012b(mm, (emlrtDCInfo *)&f_emlrtDCI, &st);
    }

    outsize_idx_0 = i4 * (int32_T)mm;
    if (!(outsize_idx_0 == (real_T)i4 * (real_T)(int32_T)mm)) {
      y = NULL;
      m1 = emlrtCreateCharArray(2, iv5);
      emlrtInitCharArrayR2013a(&st, 15, m1, &cv0[0]);
      emlrtAssign(&y, m1);
      b_st.site = &me_emlrtRSI;
      d_error(&b_st, y, (emlrtMCInfo *)&emlrtMCI);
    }

    emxInit_real_T(&st, &b_M, 2, &rb_emlrtRTEI, true);
    i3 = b_M->size[0] * b_M->size[1];
    b_M->size[0] = outsize_idx_0;
    b_M->size[1] = 2;
    emxEnsureCapacity_real_T(&st, b_M, i3, &pb_emlrtRTEI);
    if ((!(i4 == 0)) && (!(outsize_idx_0 == 0))) {
      overflow = ((!(1 > (int32_T)mm)) && ((int32_T)mm > 2147483646));
      for (outsize_idx_0 = 0; outsize_idx_0 < 2; outsize_idx_0++) {
        iacol = outsize_idx_0 * i4;
        ibmat = outsize_idx_0 * (i4 * (int32_T)mm) - 1;
        b_st.site = &x_emlrtRSI;
        if (overflow) {
          c_st.site = &y_emlrtRSI;
          d_st.site = &y_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (itilerow = 1; itilerow <= (int32_T)mm; itilerow++) {
          ibcol = ibmat + (itilerow - 1) * i4;
          b_st.site = &ab_emlrtRSI;
          if ((!(1 > i4)) && (i4 > 2147483646)) {
            c_st.site = &y_emlrtRSI;
            d_st.site = &y_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }

          for (k = 1; k <= i4; k++) {
            i3 = (iacol + k) - 1;
            b_M->data[ibcol + k] = M->data[i3 % i4 + M->size[0] * (i3 / i4)];
          }
        }
      }
    }

    c_size[0] = r5->size[0];
    c_size[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&c_size[0], 2, &(*(int32_T (*)[2])b_M->size)[0],
      2, (emlrtECInfo *)&e_emlrtECI, sp);
    for (i3 = 0; i3 < 2; i3++) {
      iacol = b_M->size[0];
      for (i4 = 0; i4 < iacol; i4++) {
        M->data[r5->data[i4] + M->size[0] * i3] = b_M->data[i4 + b_M->size[0] *
          i3];
      }
    }

    d1 = m - mm * (real_T)A->size[0];
    if (1.0 > d1) {
      iacol = 0;
    } else {
      i3 = M->size[0];
      if (!(1 <= i3)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i3, (emlrtBCInfo *)&qb_emlrtBCI, sp);
      }

      if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
        emlrtIntegerCheckR2012b(d1, (emlrtDCInfo *)&d_emlrtDCI, sp);
      }

      i3 = M->size[0];
      iacol = (int32_T)d1;
      if (!((iacol >= 1) && (iacol <= i3))) {
        emlrtDynamicBoundsCheckR2012b(iacol, 1, i3, (emlrtBCInfo *)&rb_emlrtBCI,
          sp);
      }
    }

    d1 = mm * (real_T)A->size[0] + 1.0;
    if (d1 > m) {
      i3 = 0;
      outsize_idx_0 = 0;
    } else {
      if (d1 != (int32_T)d1) {
        emlrtIntegerCheckR2012b(d1, (emlrtDCInfo *)&e_emlrtDCI, sp);
      }

      i3 = M->size[0];
      i4 = (int32_T)d1;
      if (!((i4 >= 1) && (i4 <= i3))) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, i3, (emlrtBCInfo *)&sb_emlrtBCI, sp);
      }

      i3 = i4 - 1;
      i4 = M->size[0];
      outsize_idx_0 = (int32_T)m;
      if (!((outsize_idx_0 >= 1) && (outsize_idx_0 <= i4))) {
        emlrtDynamicBoundsCheckR2012b(outsize_idx_0, 1, i4, (emlrtBCInfo *)
          &tb_emlrtBCI, sp);
      }
    }

    i4 = r5->size[0];
    r5->size[0] = outsize_idx_0 - i3;
    emxEnsureCapacity_int32_T1(sp, r5, i4, &qb_emlrtRTEI);
    outsize_idx_0 -= i3;
    for (i4 = 0; i4 < outsize_idx_0; i4++) {
      r5->data[i4] = i3 + i4;
    }

    c_size[0] = r5->size[0];
    c_size[1] = 2;
    iv6[0] = iacol;
    iv6[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&c_size[0], 2, &iv6[0], 2, (emlrtECInfo *)
      &f_emlrtECI, sp);
    i3 = b_M->size[0] * b_M->size[1];
    b_M->size[0] = iacol;
    b_M->size[1] = 2;
    emxEnsureCapacity_real_T(sp, b_M, i3, &rb_emlrtRTEI);
    for (i3 = 0; i3 < 2; i3++) {
      for (i4 = 0; i4 < iacol; i4++) {
        b_M->data[i4 + b_M->size[0] * i3] = M->data[i4 + M->size[0] * i3];
      }
    }

    for (i3 = 0; i3 < 2; i3++) {
      iacol = b_M->size[0];
      for (i4 = 0; i4 < iacol; i4++) {
        M->data[r5->data[i4] + M->size[0] * i3] = b_M->data[i4 + b_M->size[0] *
          i3];
      }
    }

    emxFree_real_T(&b_M);
    emxFree_int32_T(&r5);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (fillUpMatrix.cpp) */
