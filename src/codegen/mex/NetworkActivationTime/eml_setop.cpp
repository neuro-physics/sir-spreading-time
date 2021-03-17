/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_setop.cpp
 *
 * Code generation for function 'eml_setop'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "NetworkActivationTime.h"
#include "eml_setop.h"
#include "issorted.h"
#include "NetworkActivationTime_emxutil.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo id_emlrtRSI = { 224,/* lineNo */
  "eml_setop",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 225,/* lineNo */
  "eml_setop",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 227,/* lineNo */
  "eml_setop",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 228,/* lineNo */
  "eml_setop",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 258,/* lineNo */
  "eml_setop",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pathName */
};

static emlrtRSInfo nd_emlrtRSI = { 259,/* lineNo */
  "eml_setop",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 261,/* lineNo */
  "eml_setop",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pathName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 134,/* lineNo */
  22,                                  /* colNo */
  "eml_setop",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 434,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = { 398,/* lineNo */
  14,                                  /* colNo */
  "eml_setop",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = { 409,/* lineNo */
  18,                                  /* colNo */
  "eml_setop",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = { 398,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = { 409,/* lineNo */
  13,                                  /* colNo */
  "eml_setop",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo cd_emlrtRTEI = { 392,/* lineNo */
  5,                                   /* colNo */
  "eml_setop",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = { 403,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = { 430,/* lineNo */
  5,                                   /* colNo */
  "eml_setop",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

/* Function Declarations */
static real_T skip_to_last_equal_value(int32_T *k, const emxArray_real_T *x);

/* Function Definitions */
static real_T skip_to_last_equal_value(int32_T *k, const emxArray_real_T *x)
{
  real_T xk;
  boolean_T exitg1;
  real_T absxk;
  int32_T exponent;
  boolean_T p;
  xk = x->data[*k - 1];
  exitg1 = false;
  while ((!exitg1) && (*k < x->size[1])) {
    absxk = muDoubleScalarAbs(xk / 2.0);
    if ((!muDoubleScalarIsInf(absxk)) && (!muDoubleScalarIsNaN(absxk))) {
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &exponent);
        absxk = ldexp(1.0, exponent - 53);
      }
    } else {
      absxk = rtNaN;
    }

    if ((muDoubleScalarAbs(xk - x->data[*k]) < absxk) || (muDoubleScalarIsInf
         (x->data[*k]) && muDoubleScalarIsInf(xk) && ((x->data[*k] > 0.0) == (xk
           > 0.0)))) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      (*k)++;
    } else {
      exitg1 = true;
    }
  }

  return xk;
}

void do_vectors(const emlrtStack *sp, const emxArray_real_T *a, const
                emxArray_real_T *b, emxArray_real_T *c, emxArray_int32_T *ia,
                emxArray_int32_T *ib)
{
  int32_T na;
  int32_T nb;
  int32_T ncmax;
  int32_T ialast;
  int32_T nc;
  int32_T iafirst;
  int32_T ibfirst;
  int32_T iblast;
  emxArray_int32_T *b_ia;
  int32_T b_ialast;
  real_T ak;
  int32_T b_iblast;
  real_T bk;
  real_T absxk;
  int32_T exponent;
  boolean_T p;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  na = a->size[1];
  nb = b->size[1];
  ncmax = muIntScalarMin_sint32(na, nb);
  ialast = c->size[0] * c->size[1];
  c->size[0] = 1;
  c->size[1] = ncmax;
  emxEnsureCapacity_real_T1(sp, c, ialast, &vb_emlrtRTEI);
  ialast = ia->size[0];
  ia->size[0] = ncmax;
  emxEnsureCapacity_int32_T(sp, ia, ialast, &vb_emlrtRTEI);
  ialast = ib->size[0];
  ib->size[0] = ncmax;
  emxEnsureCapacity_int32_T(sp, ib, ialast, &vb_emlrtRTEI);
  st.site = &id_emlrtRSI;
  if (!issorted(a)) {
    st.site = &jd_emlrtRSI;
    b_st.site = &jd_emlrtRSI;
    b_error(&b_st);
  }

  st.site = &kd_emlrtRSI;
  if (!issorted(b)) {
    st.site = &ld_emlrtRSI;
    b_st.site = &ld_emlrtRSI;
    c_error(&b_st);
  }

  nc = 0;
  iafirst = 0;
  ialast = 1;
  ibfirst = 0;
  iblast = 1;
  while ((ialast <= na) && (iblast <= nb)) {
    b_ialast = ialast;
    st.site = &md_emlrtRSI;
    ak = skip_to_last_equal_value(&b_ialast, a);
    ialast = b_ialast;
    b_iblast = iblast;
    st.site = &nd_emlrtRSI;
    bk = skip_to_last_equal_value(&b_iblast, b);
    iblast = b_iblast;
    st.site = &od_emlrtRSI;
    absxk = muDoubleScalarAbs(bk / 2.0);
    if ((!muDoubleScalarIsInf(absxk)) && (!muDoubleScalarIsNaN(absxk))) {
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &exponent);
        absxk = ldexp(1.0, exponent - 53);
      }
    } else {
      absxk = rtNaN;
    }

    if ((muDoubleScalarAbs(bk - ak) < absxk) || (muDoubleScalarIsInf(ak) &&
         muDoubleScalarIsInf(bk) && ((ak > 0.0) == (bk > 0.0)))) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      nc++;
      c->data[nc - 1] = ak;
      ia->data[nc - 1] = iafirst + 1;
      ib->data[nc - 1] = ibfirst + 1;
      ialast = b_ialast + 1;
      iafirst = b_ialast;
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    } else {
      if ((ak < bk) || muDoubleScalarIsNaN(bk)) {
        p = true;
      } else {
        p = false;
      }

      if (p) {
        ialast = b_ialast + 1;
        iafirst = b_ialast;
      } else {
        iblast = b_iblast + 1;
        ibfirst = b_iblast;
      }
    }
  }

  emxInit_int32_T(sp, &b_ia, 1, &xb_emlrtRTEI, true);
  if (ncmax > 0) {
    if (!(nc <= ncmax)) {
      emlrtErrorWithMessageIdR2012b(sp, &cd_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (1 > nc) {
      iafirst = 0;
    } else {
      iafirst = nc;
    }

    ialast = b_ia->size[0];
    b_ia->size[0] = iafirst;
    emxEnsureCapacity_int32_T(sp, b_ia, ialast, &xb_emlrtRTEI);
    for (ialast = 0; ialast < iafirst; ialast++) {
      b_ia->data[ialast] = ia->data[ialast];
    }

    ialast = ia->size[0];
    ia->size[0] = b_ia->size[0];
    emxEnsureCapacity_int32_T(sp, ia, ialast, &ac_emlrtRTEI);
    iafirst = b_ia->size[0];
    for (ialast = 0; ialast < iafirst; ialast++) {
      ia->data[ialast] = b_ia->data[ialast];
    }

    if (!(nc <= ncmax)) {
      emlrtErrorWithMessageIdR2012b(sp, &dd_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (1 > nc) {
      iafirst = 0;
    } else {
      iafirst = nc;
    }

    ialast = b_ia->size[0];
    b_ia->size[0] = iafirst;
    emxEnsureCapacity_int32_T(sp, b_ia, ialast, &yb_emlrtRTEI);
    for (ialast = 0; ialast < iafirst; ialast++) {
      b_ia->data[ialast] = ib->data[ialast];
    }

    ialast = ib->size[0];
    ib->size[0] = b_ia->size[0];
    emxEnsureCapacity_int32_T(sp, ib, ialast, &bc_emlrtRTEI);
    iafirst = b_ia->size[0];
    for (ialast = 0; ialast < iafirst; ialast++) {
      ib->data[ialast] = b_ia->data[ialast];
    }
  }

  emxFree_int32_T(&b_ia);
  if (ncmax > 0) {
    if (!(nc <= ncmax)) {
      emlrtErrorWithMessageIdR2012b(sp, &ed_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    ialast = c->size[0] * c->size[1];
    if (1 > nc) {
      c->size[1] = 0;
    } else {
      c->size[1] = nc;
    }

    emxEnsureCapacity_real_T1(sp, c, ialast, &wb_emlrtRTEI);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (eml_setop.cpp) */
