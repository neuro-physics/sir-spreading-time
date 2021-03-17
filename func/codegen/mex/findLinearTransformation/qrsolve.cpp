/*
 * qrsolve.cpp
 *
 * Code generation for function 'qrsolve'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "findLinearTransformation.h"
#include "qrsolve.h"
#include "error1.h"
#include "eml_int_forloop_overflow_check.h"
#include "findLinearTransformation_emxutil.h"
#include "warning.h"
#include "findLinearTransformation_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo rb_emlrtRSI = { 121, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

static emlrtRSInfo sb_emlrtRSI = { 120, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

static emlrtRSInfo ub_emlrtRSI = { 78, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

static emlrtMCInfo d_emlrtMCI = { 52, 19, "flt2str",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m"
};

static emlrtRTEInfo g_emlrtRTEI = { 54, 14, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

static emlrtRSInfo qc_emlrtRSI = { 52, "flt2str",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m"
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14]);
static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[14]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14])
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m6;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m6, 2, pArrays, "sprintf", true, location);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2] = { 1, 14 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, ret, 14);
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(c_sprintf), &thisId, y);
  emlrtDestroyArray(&c_sprintf);
}

void LSQFromQR(const emlrtStack *sp, const emxArray_real_T *A, const
               emxArray_real_T *tau, const emxArray_int32_T *jpvt,
               emxArray_real_T *B, int32_T rankA, emxArray_real_T *Y)
{
  int32_T nb;
  int32_T mn;
  int32_T i;
  int32_T j;
  ptrdiff_t nrc_t;
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
  nb = B->size[1];
  mn = A->size[1];
  i = B->size[1];
  j = Y->size[0] * Y->size[1];
  Y->size[0] = mn;
  Y->size[1] = i;
  emxEnsureCapacity(sp, (emxArray__common *)Y, j, (int32_T)sizeof(real_T),
                    &g_emlrtRTEI);
  mn *= i;
  for (j = 0; j < mn; j++) {
    Y->data[j] = 0.0;
  }

  st.site = &tb_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  mn = muIntScalarMin_sint32(A->size[0], A->size[1]);
  if ((!((A->size[0] == 0) || (A->size[1] == 0))) && (!((B->size[0] == 0) ||
        (B->size[1] == 0)))) {
    nrc_t = (ptrdiff_t)B->size[0];
    nrc_t = LAPACKE_dormqr(102, 'L', 'T', nrc_t, (ptrdiff_t)B->size[1],
      (ptrdiff_t)mn, &A->data[0], (ptrdiff_t)A->size[0], &tau->data[0], &B->
      data[0], nrc_t);
    mn = (int32_T)nrc_t;
    c_st.site = &yb_emlrtRSI;
    if (mn != 0) {
      if (mn == -1010) {
        d_st.site = &y_emlrtRSI;
        error(&d_st);
      } else {
        d_st.site = &ab_emlrtRSI;
        d_error(&d_st, mn);
      }
    }
  }

  st.site = &ub_emlrtRSI;
  if ((!(1 > nb)) && (nb > 2147483646)) {
    b_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (mn = 0; mn + 1 <= nb; mn++) {
    st.site = &vb_emlrtRSI;
    if ((!(1 > rankA)) && (rankA > 2147483646)) {
      b_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (i = 0; i + 1 <= rankA; i++) {
      Y->data[(jpvt->data[i] + Y->size[0] * mn) - 1] = B->data[i + B->size[0] *
        mn];
    }

    for (j = rankA - 1; j + 1 > 0; j--) {
      Y->data[(jpvt->data[j] + Y->size[0] * mn) - 1] /= A->data[j + A->size[0] *
        j];
      st.site = &wb_emlrtRSI;
      for (i = 0; i + 1 <= j; i++) {
        Y->data[(jpvt->data[i] + Y->size[0] * mn) - 1] -= Y->data[(jpvt->data[j]
          + Y->size[0] * mn) - 1] * A->data[i + A->size[0] * j];
      }
    }
  }
}

int32_T rankFromQR(const emlrtStack *sp, const emxArray_real_T *A)
{
  int32_T r;
  real_T tol;
  int32_T minmn;
  int32_T maxmn;
  const mxArray *y;
  char_T u[6];
  static const char_T rfmt[6] = { '%', '1', '4', '.', '6', 'e' };

  const mxArray *m2;
  static const int32_T iv8[2] = { 1, 6 };

  const mxArray *b_y;
  char_T cv2[14];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  r = 0;
  tol = 0.0;
  if (A->size[0] < A->size[1]) {
    minmn = A->size[0];
    maxmn = A->size[1];
  } else {
    minmn = A->size[1];
    maxmn = A->size[0];
  }

  if (minmn > 0) {
    tol = (real_T)maxmn * muDoubleScalarAbs(A->data[0]) * 2.2204460492503131E-16;
    while ((r < minmn) && (muDoubleScalarAbs(A->data[r + A->size[0] * r]) >= tol))
    {
      r++;
    }
  }

  if (r < minmn) {
    st.site = &rb_emlrtRSI;
    for (minmn = 0; minmn < 6; minmn++) {
      u[minmn] = rfmt[minmn];
    }

    y = NULL;
    m2 = emlrtCreateCharArray(2, iv8);
    emlrtInitCharArrayR2013a(&st, 6, m2, &u[0]);
    emlrtAssign(&y, m2);
    b_y = NULL;
    m2 = emlrtCreateDoubleScalar(tol);
    emlrtAssign(&b_y, m2);
    b_st.site = &qc_emlrtRSI;
    emlrt_marshallIn(&b_st, b_sprintf(&b_st, y, b_y, (emlrtMCInfo *)&d_emlrtMCI),
                     "sprintf", cv2);
    st.site = &sb_emlrtRSI;
    b_warning(&st, r, cv2);
  }

  return r;
}

/* End of code generation (qrsolve.cpp) */
