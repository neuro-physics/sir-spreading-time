/*
 * findLinearTransformation.cpp
 *
 * Code generation for function 'findLinearTransformation'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "findLinearTransformation.h"
#include "findLinearTransformation_emxutil.h"
#include "error1.h"
#include "eml_int_forloop_overflow_check.h"
#include "lusolve.h"
#include "qrsolve.h"
#include "xgeqp3.h"
#include "mod.h"
#include "assertValidSizeArg.h"
#include "mldivide.h"
#include "any.h"
#include "findLinearTransformation_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 31, "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m"
};

static emlrtRSInfo b_emlrtRSI = { 27, "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m"
};

static emlrtRSInfo c_emlrtRSI = { 21, "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m"
};

static emlrtRSInfo d_emlrtRSI = { 19, "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m"
};

static emlrtRSInfo e_emlrtRSI = { 14, "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m"
};

static emlrtRSInfo f_emlrtRSI = { 13, "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m"
};

static emlrtRSInfo g_emlrtRSI = { 12, "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m"
};

static emlrtRSInfo h_emlrtRSI = { 8, "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m"
};

static emlrtRSInfo i_emlrtRSI = { 92, "eye",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\eye.m" };

static emlrtRSInfo j_emlrtRSI = { 51, "eye",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\eye.m" };

static emlrtRSInfo l_emlrtRSI = { 23, "cat",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"
};

static emlrtRSInfo m_emlrtRSI = { 101, "cat",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"
};

static emlrtRSInfo n_emlrtRSI = { 1, "mrdivide",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mrdivide.p"
};

static emlrtRSInfo ac_emlrtRSI = { 79, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo bc_emlrtRSI = { 283, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo cc_emlrtRSI = { 291, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo lc_emlrtRSI = { 39, "reshape",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m"
};

static emlrtRSInfo mc_emlrtRSI = { 61, "reshape",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m"
};

static emlrtRSInfo nc_emlrtRSI = { 108, "reshape",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m"
};

static emlrtRSInfo oc_emlrtRSI = { 131, "reshape",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m"
};

static emlrtMCInfo emlrtMCI = { 27, 5, "error",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\lang\\error.m"
};

static emlrtRTEInfo emlrtRTEI = { 1, 14, "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m"
};

static emlrtRTEInfo b_emlrtRTEI = { 12, 9, "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m"
};

static emlrtRTEInfo n_emlrtRTEI = { 1, 1, "mrdivide",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mrdivide.p"
};

static emlrtRTEInfo o_emlrtRTEI = { 404, 15, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRTEInfo p_emlrtRTEI = { 71, 15, "reshape",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m"
};

static emlrtRTEInfo q_emlrtRTEI = { 245, 27, "cat",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 13, 18, "I", "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 13, 27, "I",
  "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m",
  0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 14, 18, "I",
  "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m",
  0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 14, 27, "I",
  "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m",
  0 };

static emlrtRTEInfo r_emlrtRTEI = { 26, 13, "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m"
};

static emlrtBCInfo e_emlrtBCI = { -1, -1, 27, 63, "u",
  "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m",
  0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 27, 19, "A",
  "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m",
  0 };

static emlrtECInfo emlrtECI = { -1, 27, 17, "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m"
};

static emlrtDCInfo emlrtDCI = { 27, 21, "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m",
  1 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 27, 21, "A",
  "findLinearTransformation",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\findLinearTransformation.m",
  0 };

static emlrtRSInfo rc_emlrtRSI = { 27, "error",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\lang\\error.m"
};

/* Function Declarations */
static void f_error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);

/* Function Definitions */
static void f_error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "error", true, location);
}

void findLinearTransformation(const emlrtStack *sp, emxArray_real_T *u,
  emxArray_real_T *v, emxArray_real_T *T)
{
  emxArray_real_T *I;
  boolean_T b_u[2];
  int32_T i0;
  int32_T nP;
  int32_T n;
  int32_T b_n;
  const mxArray *y;
  char_T c_u[21];
  static const char_T varargin_1[21] = { 'f', 'i', 'n', 'd', 'L', 'i', 'n', 'e',
    'a', 'r', 'T', 'r', 'a', 'n', 's', 'f', 'o', 'r', 'm', ':', 'u' };

  int32_T b_nP;
  const mxArray *m0;
  static const int32_T iv0[2] = { 1, 21 };

  emxArray_real_T *x;
  const mxArray *b_y;
  char_T d_u[50];
  static const char_T varargin_2[50] = { 'u', ' ', 'a', 'n', 'd', ' ', 'v', ' ',
    'm', 'u', 's', 't', ' ', 'b', 'e', ' ', 't', 'h', 'e', ' ', 's', 'a', 'm',
    'e', ' ', 's', 'h', 'a', 'p', 'e', ' ', 'a', 'n', 'd', ' ', 's', 'i', 'z',
    'e', ' ', '3', 'd', ' ', 'v', 'e', 'c', 't', 'o', 'r', 's' };

  static const int32_T iv1[2] = { 1, 50 };

  int32_T loop_ub;
  const mxArray *c_y;
  char_T e_u[21];
  emxArray_real_T *Y;
  static const int32_T iv2[2] = { 1, 21 };

  emxArray_int32_T *jpvt;
  emxArray_real_T *b_v;
  int32_T k;
  boolean_T overflow;
  emxArray_int32_T *r0;
  uint32_T x_idx_0;
  emxArray_real_T *d_y;
  uint32_T unnamed_idx_1;
  emxArray_real_T *e_y;
  const mxArray *f_y;
  char_T f_u[25];
  static const char_T b_varargin_2[25] = { 'm', 'a', 't', 'r', 'i', 'x', ' ',
    't', 'o', 'o', ' ', 'b', 'i', 'g', ' ', 't', 'o', ' ', 'r', 'e', 's', 'o',
    'l', 'v', 'e' };

  static const int32_T iv3[2] = { 1, 25 };

  real_T d0;
  real_T d;
  int32_T c_v[1];
  int32_T i1;
  int32_T i;
  int32_T b_k;
  emxArray_real_T d_v;
  int32_T maxdimlen;
  int32_T i2;
  real_T b_i;
  real_T anew;
  real_T ndbl;
  real_T apnd;
  real_T cdiff;
  boolean_T guard1 = false;
  int32_T result;
  emxArray_real_T *b_I;
  int32_T g_u;
  emxArray_real_T *h_u;
  int32_T iv4[2];
  emxArray_real_T *c_I;
  emxArray_real_T *e_v;
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
  emxInit_real_T(sp, &I, 2, &b_emlrtRTEI, true);

  /*  finds a matrix T (3x3) such that T * u(:,i) = v(:,i) */
  /*  u(:,i) and v(:,i) are 3d col vectors; the amount of col vectors in u and v must match */
  /*  */
  /*  explanation of algorithm in: */
  /*  http://stackoverflow.com/questions/26635266/matlab-calculate-3d-similarity-transformation-fitgeotrans-for-3d */
  for (i0 = 0; i0 < 2; i0++) {
    b_u[i0] = (u->size[i0] != v->size[i0]);
  }

  if (any(b_u)) {
    st.site = &h_emlrtRSI;
    for (i0 = 0; i0 < 21; i0++) {
      c_u[i0] = varargin_1[i0];
    }

    y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    emlrtInitCharArrayR2013a(&st, 21, m0, &c_u[0]);
    emlrtAssign(&y, m0);
    for (i0 = 0; i0 < 50; i0++) {
      d_u[i0] = varargin_2[i0];
    }

    b_y = NULL;
    m0 = emlrtCreateCharArray(2, iv1);
    emlrtInitCharArrayR2013a(&st, 50, m0, &d_u[0]);
    emlrtAssign(&b_y, m0);
    b_st.site = &rc_emlrtRSI;
    f_error(&b_st, y, b_y, (emlrtMCInfo *)&emlrtMCI);
  }

  nP = u->size[1];
  n = u->size[0];
  b_n = u->size[0];
  b_nP = u->size[1];
  if (u->size[1] > u->size[0]) {
    st.site = &g_emlrtRSI;
    b_st.site = &j_emlrtRSI;
    assertValidSizeArg(&b_st, (real_T)u->size[1]);
    i0 = I->size[0] * I->size[1];
    I->size[0] = u->size[1];
    I->size[1] = u->size[1];
    emxEnsureCapacity(&st, (emxArray__common *)I, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = u->size[1] * u->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      I->data[i0] = 0.0;
    }

    b_st.site = &i_emlrtRSI;
    overflow = ((!(1 > u->size[1])) && (u->size[1] > 2147483646));
    if (overflow) {
      c_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (k = 0; k + 1 <= nP; k++) {
      I->data[k + I->size[0] * k] = 1.0;
    }

    if (u->size[0] + 1U > (uint32_T)u->size[1]) {
      i1 = 1;
      i0 = 1;
    } else {
      i0 = I->size[0];
      i1 = (int32_T)(u->size[0] + 1U);
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&emlrtBCI, sp);
      }

      i0 = I->size[0];
      i2 = u->size[1];
      if (!((i2 >= 1) && (i2 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i0, (emlrtBCInfo *)&emlrtBCI, sp);
      }

      i0 = i2 + 1;
    }

    i2 = I->size[1];
    maxdimlen = u->size[1];
    if (!((maxdimlen >= 1) && (maxdimlen <= i2))) {
      emlrtDynamicBoundsCheckR2012b(maxdimlen, 1, i2, (emlrtBCInfo *)&b_emlrtBCI,
        sp);
    }

    st.site = &f_emlrtRSI;
    b_st.site = &l_emlrtRSI;
    if (!((u->size[0] == 0) || (u->size[1] == 0))) {
      b_k = u->size[1];
    } else {
      i2 = u->size[1];
      if (!((i0 - i1 == 0) || (i2 == 0))) {
        b_k = u->size[1];
      } else {
        b_k = muIntScalarMax_sint32(u->size[1], 0);
        i2 = u->size[1];
        if (i2 > b_k) {
          b_k = u->size[1];
        }
      }
    }

    c_st.site = &m_emlrtRSI;
    if ((b_k == u->size[1]) || ((u->size[0] == 0) || (u->size[1] == 0))) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &q_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    i2 = u->size[1];
    if (b_k == i2) {
    } else {
      i2 = u->size[1];
      if ((i0 - i1 == 0) || (i2 == 0)) {
      } else {
        overflow = false;
      }
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &q_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    overflow = (b_k == 0);
    if (overflow || (!((u->size[0] == 0) || (u->size[1] == 0)))) {
      k = u->size[0];
    } else {
      k = 0;
    }

    guard1 = false;
    if (overflow) {
      guard1 = true;
    } else {
      i2 = u->size[1];
      if (!((i0 - i1 == 0) || (i2 == 0))) {
        guard1 = true;
      } else {
        result = -1;
      }
    }

    if (guard1) {
      result = (i0 - i1) - 1;
    }

    emxInit_real_T(&b_st, &b_I, 2, &emlrtRTEI, true);
    g_u = u->size[1];
    i2 = b_I->size[0] * b_I->size[1];
    b_I->size[0] = i0 - i1;
    b_I->size[1] = g_u;
    emxEnsureCapacity(&b_st, (emxArray__common *)b_I, i2, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i2 = 0; i2 < g_u; i2++) {
      loop_ub = i0 - i1;
      for (maxdimlen = 0; maxdimlen < loop_ub; maxdimlen++) {
        b_I->data[maxdimlen + b_I->size[0] * i2] = I->data[((i1 + maxdimlen) +
          I->size[0] * i2) - 1];
      }
    }

    emxInit_real_T(&b_st, &h_u, 2, &emlrtRTEI, true);
    i0 = h_u->size[0] * h_u->size[1];
    h_u->size[0] = (k + result) + 1;
    h_u->size[1] = b_k;
    emxEnsureCapacity(&b_st, (emxArray__common *)h_u, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < b_k; i0++) {
      for (i1 = 0; i1 < k; i1++) {
        h_u->data[i1 + h_u->size[0] * i0] = u->data[i1 + k * i0];
      }
    }

    for (i0 = 0; i0 < b_k; i0++) {
      loop_ub = result + 1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        h_u->data[(i1 + k) + h_u->size[0] * i0] = b_I->data[i1 + (result + 1) *
          i0];
      }
    }

    emxFree_real_T(&b_I);
    i0 = u->size[0] * u->size[1];
    u->size[0] = h_u->size[0];
    u->size[1] = h_u->size[1];
    emxEnsureCapacity(&b_st, (emxArray__common *)u, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = h_u->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_k = h_u->size[0];
      for (i1 = 0; i1 < b_k; i1++) {
        u->data[i1 + u->size[0] * i0] = h_u->data[i1 + h_u->size[0] * i0];
      }
    }

    emxFree_real_T(&h_u);
    if (n + 1U > (uint32_T)nP) {
      i1 = 1;
      i0 = 1;
    } else {
      i0 = I->size[0];
      i1 = (int32_T)(n + 1U);
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&c_emlrtBCI, sp);
      }

      i0 = I->size[0];
      if (!((nP >= 1) && (nP <= i0))) {
        emlrtDynamicBoundsCheckR2012b(nP, 1, i0, (emlrtBCInfo *)&c_emlrtBCI, sp);
      }

      i0 = nP + 1;
    }

    i2 = I->size[1];
    maxdimlen = nP;
    if (!((maxdimlen >= 1) && (maxdimlen <= i2))) {
      emlrtDynamicBoundsCheckR2012b(maxdimlen, 1, i2, (emlrtBCInfo *)&d_emlrtBCI,
        sp);
    }

    st.site = &e_emlrtRSI;
    b_st.site = &l_emlrtRSI;
    if (!((v->size[0] == 0) || (v->size[1] == 0))) {
      b_k = v->size[1];
    } else if (!(i0 - i1 == 0)) {
      b_k = nP;
    } else {
      b_k = muIntScalarMax_sint32(v->size[1], 0);
      if (nP > b_k) {
        b_k = nP;
      }
    }

    c_st.site = &m_emlrtRSI;
    if ((b_k == v->size[1]) || ((v->size[0] == 0) || (v->size[1] == 0))) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &q_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    if ((b_k == nP) || (i0 - i1 == 0)) {
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &q_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    if (!((v->size[0] == 0) || (v->size[1] == 0))) {
      k = v->size[0];
    } else {
      k = 0;
    }

    if (!(i0 - i1 == 0)) {
      result = (i0 - i1) - 1;
    } else {
      result = -1;
    }

    emxInit_real_T(&b_st, &c_I, 2, &emlrtRTEI, true);
    i2 = c_I->size[0] * c_I->size[1];
    c_I->size[0] = i0 - i1;
    c_I->size[1] = nP;
    emxEnsureCapacity(&b_st, (emxArray__common *)c_I, i2, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i2 = 0; i2 < nP; i2++) {
      loop_ub = i0 - i1;
      for (maxdimlen = 0; maxdimlen < loop_ub; maxdimlen++) {
        c_I->data[maxdimlen + c_I->size[0] * i2] = I->data[((i1 + maxdimlen) +
          I->size[0] * i2) - 1];
      }
    }

    emxInit_real_T(&b_st, &e_v, 2, &emlrtRTEI, true);
    i0 = e_v->size[0] * e_v->size[1];
    e_v->size[0] = (k + result) + 1;
    e_v->size[1] = b_k;
    emxEnsureCapacity(&b_st, (emxArray__common *)e_v, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < b_k; i0++) {
      for (i1 = 0; i1 < k; i1++) {
        e_v->data[i1 + e_v->size[0] * i0] = v->data[i1 + k * i0];
      }
    }

    for (i0 = 0; i0 < b_k; i0++) {
      loop_ub = result + 1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        e_v->data[(i1 + k) + e_v->size[0] * i0] = c_I->data[i1 + (result + 1) *
          i0];
      }
    }

    emxFree_real_T(&c_I);
    i0 = v->size[0] * v->size[1];
    v->size[0] = e_v->size[0];
    v->size[1] = e_v->size[1];
    emxEnsureCapacity(&b_st, (emxArray__common *)v, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = e_v->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_k = e_v->size[0];
      for (i1 = 0; i1 < b_k; i1++) {
        v->data[i1 + v->size[0] * i0] = e_v->data[i1 + e_v->size[0] * i0];
      }
    }

    emxFree_real_T(&e_v);
    b_n = u->size[0];
    b_nP = u->size[1];
  }

  emxInit_real_T1(sp, &x, 1, &emlrtRTEI, true);
  if ((real_T)b_nP * (real_T)b_n * (real_T)b_n * (real_T)b_n > 2.147483647E+9) {
    if (b_n == b_nP) {
      st.site = &d_emlrtRSI;
      if (u->size[1] == v->size[1]) {
      } else {
        emlrtErrorWithMessageIdR2012b(&st, &n_emlrtRTEI, "Coder:MATLAB:dimagree",
          0);
      }

      emxInit_real_T(&st, &Y, 2, &emlrtRTEI, true);
      emxInit_int32_T1(&st, &jpvt, 2, &emlrtRTEI, true);
      emxInit_real_T(&st, &b_v, 2, &emlrtRTEI, true);
      if ((v->size[0] == 0) || (v->size[1] == 0) || ((u->size[0] == 0) ||
           (u->size[1] == 0))) {
        x_idx_0 = (uint32_T)v->size[0];
        unnamed_idx_1 = (uint32_T)u->size[0];
        i0 = T->size[0] * T->size[1];
        T->size[0] = (int32_T)x_idx_0;
        T->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&st, (emxArray__common *)T, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = (int32_T)x_idx_0 * (int32_T)unnamed_idx_1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          T->data[i0] = 0.0;
        }
      } else if (u->size[0] == u->size[1]) {
        b_st.site = &n_emlrtRSI;
        lusolve(&b_st, u, v, T);
      } else {
        b_st.site = &n_emlrtRSI;
        i0 = I->size[0] * I->size[1];
        I->size[0] = u->size[1];
        I->size[1] = u->size[0];
        emxEnsureCapacity(&b_st, (emxArray__common *)I, i0, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        loop_ub = u->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          b_k = u->size[1];
          for (i1 = 0; i1 < b_k; i1++) {
            I->data[i1 + I->size[0] * i0] = u->data[i0 + u->size[0] * i1];
          }
        }

        c_st.site = &kb_emlrtRSI;
        xgeqp3(&c_st, I, x, jpvt);
        c_st.site = &lb_emlrtRSI;
        maxdimlen = rankFromQR(&c_st, I);
        i0 = b_v->size[0] * b_v->size[1];
        b_v->size[0] = v->size[1];
        b_v->size[1] = v->size[0];
        emxEnsureCapacity(&b_st, (emxArray__common *)b_v, i0, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        loop_ub = v->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          b_k = v->size[1];
          for (i1 = 0; i1 < b_k; i1++) {
            b_v->data[i1 + b_v->size[0] * i0] = v->data[i0 + v->size[0] * i1];
          }
        }

        c_st.site = &mb_emlrtRSI;
        LSQFromQR(&c_st, I, x, jpvt, b_v, maxdimlen, Y);
        i0 = T->size[0] * T->size[1];
        T->size[0] = Y->size[1];
        T->size[1] = Y->size[0];
        emxEnsureCapacity(&st, (emxArray__common *)T, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = Y->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          b_k = Y->size[1];
          for (i1 = 0; i1 < b_k; i1++) {
            T->data[i1 + T->size[0] * i0] = Y->data[i0 + Y->size[0] * i1];
          }
        }
      }

      emxFree_real_T(&b_v);
      emxFree_int32_T(&jpvt);
      emxFree_real_T(&Y);
    } else {
      st.site = &c_emlrtRSI;
      for (i0 = 0; i0 < 21; i0++) {
        e_u[i0] = varargin_1[i0];
      }

      c_y = NULL;
      m0 = emlrtCreateCharArray(2, iv2);
      emlrtInitCharArrayR2013a(&st, 21, m0, &e_u[0]);
      emlrtAssign(&c_y, m0);
      for (i0 = 0; i0 < 25; i0++) {
        f_u[i0] = b_varargin_2[i0];
      }

      f_y = NULL;
      m0 = emlrtCreateCharArray(2, iv3);
      emlrtInitCharArrayR2013a(&st, 25, m0, &f_u[0]);
      emlrtAssign(&f_y, m0);
      b_st.site = &rc_emlrtRSI;
      f_error(&b_st, c_y, f_y, (emlrtMCInfo *)&emlrtMCI);
    }
  } else {
    i0 = I->size[0] * I->size[1];
    I->size[0] = (int32_T)((real_T)b_nP * (real_T)b_n);
    I->size[1] = (int32_T)((real_T)b_n * (real_T)b_n);
    emxEnsureCapacity(sp, (emxArray__common *)I, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = (int32_T)((real_T)b_nP * (real_T)b_n) * (int32_T)((real_T)b_n *
      (real_T)b_n);
    for (i0 = 0; i0 < loop_ub; i0++) {
      I->data[i0] = 0.0;
    }

    k = 0;
    emxInit_int32_T(sp, &r0, 1, &emlrtRTEI, true);
    emxInit_real_T(sp, &d_y, 2, &emlrtRTEI, true);
    emxInit_real_T(sp, &e_y, 2, &emlrtRTEI, true);
    while (k <= b_nP - 1) {
      d0 = ((1.0 + (real_T)k) - 1.0) * (real_T)b_n + 1.0;
      d = (1.0 + (real_T)k) * (real_T)b_n;
      i0 = (int32_T)(d + (1.0 - d0));
      emlrtForLoopVectorCheckR2012b(d0, 1.0, d, mxDOUBLE_CLASS, i0,
        (emlrtRTEInfo *)&r_emlrtRTEI, sp);
      i = 0;
      while (i <= i0 - 1) {
        b_i = d0 + (real_T)i;
        i1 = I->size[0];
        i2 = (int32_T)b_i;
        if (!((i2 >= 1) && (i2 <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)&f_emlrtBCI,
            sp);
        }

        st.site = &b_emlrtRSI;
        anew = (b_i - 1.0) * (real_T)b_n + 1.0;
        d = b_i * (real_T)b_n;
        b_st.site = &bb_emlrtRSI;
        c_st.site = &ac_emlrtRSI;
        if (d < anew) {
          n = 0;
          apnd = d;
          overflow = false;
        } else {
          ndbl = muDoubleScalarFloor((d - anew) + 0.5);
          apnd = anew + ndbl;
          cdiff = apnd - d;
          if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 *
              muDoubleScalarMax(anew, d)) {
            ndbl++;
            apnd = d;
          } else if (cdiff > 0.0) {
            apnd = anew + (ndbl - 1.0);
          } else {
            ndbl++;
          }

          overflow = (2.147483647E+9 < ndbl);
          if (ndbl >= 0.0) {
            n = (int32_T)ndbl;
          } else {
            n = 0;
          }
        }

        d_st.site = &bc_emlrtRSI;
        if (!overflow) {
        } else {
          emlrtErrorWithMessageIdR2012b(&d_st, &o_emlrtRTEI,
            "Coder:MATLAB:pmaxsize", 0);
        }

        i1 = d_y->size[0] * d_y->size[1];
        d_y->size[0] = 1;
        d_y->size[1] = n;
        emxEnsureCapacity(&c_st, (emxArray__common *)d_y, i1, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        if (n > 0) {
          d_y->data[0] = anew;
          if (n > 1) {
            d_y->data[n - 1] = apnd;
            maxdimlen = (n - 1) / 2;
            d_st.site = &cc_emlrtRSI;
            for (b_k = 1; b_k < maxdimlen; b_k++) {
              d_y->data[b_k] = anew + (real_T)b_k;
              d_y->data[(n - b_k) - 1] = apnd - (real_T)b_k;
            }

            if (maxdimlen << 1 == n - 1) {
              d_y->data[maxdimlen] = (anew + apnd) / 2.0;
            } else {
              d_y->data[maxdimlen] = anew + (real_T)maxdimlen;
              d_y->data[maxdimlen + 1] = apnd - (real_T)maxdimlen;
            }
          }
        }

        i1 = e_y->size[0] * e_y->size[1];
        e_y->size[0] = 1;
        e_y->size[1] = d_y->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)e_y, i1, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        loop_ub = d_y->size[0] * d_y->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          e_y->data[i1] = d_y->data[i1] - 1.0;
        }

        st.site = &b_emlrtRSI;
        b_mod(&st, e_y, (real_T)b_n * (real_T)b_n, d_y);
        maxdimlen = I->size[1];
        i1 = r0->size[0];
        r0->size[0] = d_y->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof
                          (int32_T), &emlrtRTEI);
        loop_ub = d_y->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          d = d_y->data[d_y->size[0] * i1] + 1.0;
          if (d != (int32_T)muDoubleScalarFloor(d)) {
            emlrtIntegerCheckR2012b(d, (emlrtDCInfo *)&emlrtDCI, sp);
          }

          i2 = (int32_T)d;
          if (!((i2 >= 1) && (i2 <= maxdimlen))) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, maxdimlen, (emlrtBCInfo *)
              &g_emlrtBCI, sp);
          }

          r0->data[i1] = i2 - 1;
        }

        loop_ub = u->size[0];
        i1 = u->size[1];
        i2 = 1 + k;
        if (!((i2 >= 1) && (i2 <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)&e_emlrtBCI,
            sp);
        }

        i1 = d_y->size[0] * d_y->size[1];
        d_y->size[0] = 1;
        d_y->size[1] = loop_ub;
        emxEnsureCapacity(sp, (emxArray__common *)d_y, i1, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        for (i1 = 0; i1 < loop_ub; i1++) {
          d_y->data[d_y->size[0] * i1] = u->data[i1 + u->size[0] * (i2 - 1)];
        }

        iv4[0] = 1;
        iv4[1] = r0->size[0];
        emlrtSubAssignSizeCheckR2012b(iv4, 2, *(int32_T (*)[2])d_y->size, 2,
          (emlrtECInfo *)&emlrtECI, sp);
        loop_ub = d_y->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          I->data[((int32_T)b_i + I->size[0] * r0->data[i1]) - 1] = d_y->
            data[d_y->size[0] * i1];
        }

        i++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    emxFree_real_T(&e_y);
    emxFree_real_T(&d_y);
    emxFree_int32_T(&r0);
    c_v[0] = v->size[0] * v->size[1];
    d_v = *v;
    d_v.size = (int32_T *)&c_v;
    d_v.numDimensions = 1;
    st.site = &emlrtRSI;
    mldivide(&st, I, &d_v, x);
    st.site = &emlrtRSI;
    b_st.site = &lc_emlrtRSI;
    c_st.site = &oc_emlrtRSI;
    assertValidSizeArg(&c_st, (real_T)b_n);
    c_st.site = &oc_emlrtRSI;
    assertValidSizeArg(&c_st, (real_T)b_n);
    x_idx_0 = (uint32_T)x->size[0];
    maxdimlen = (int32_T)x_idx_0;
    if (1 > (int32_T)x_idx_0) {
      maxdimlen = 1;
    }

    maxdimlen = muIntScalarMax_sint32(x->size[0], maxdimlen);
    if (b_n > maxdimlen) {
      b_st.site = &mc_emlrtRSI;
      e_error(&b_st);
    }

    if (b_n > maxdimlen) {
      b_st.site = &mc_emlrtRSI;
      e_error(&b_st);
    }

    i0 = I->size[0] * I->size[1];
    I->size[0] = b_n;
    I->size[1] = b_n;
    emxEnsureCapacity(&st, (emxArray__common *)I, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    if (x->size[0] == I->size[0] * I->size[1]) {
    } else {
      emlrtErrorWithMessageIdR2012b(&st, &p_emlrtRTEI,
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }

    b_st.site = &nc_emlrtRSI;
    overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
    if (overflow) {
      c_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (k = 0; k + 1 <= x->size[0]; k++) {
      I->data[k] = x->data[k];
    }

    i0 = T->size[0] * T->size[1];
    T->size[0] = I->size[1];
    T->size[1] = I->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)T, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = I->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_k = I->size[1];
      for (i1 = 0; i1 < b_k; i1++) {
        T->data[i1 + T->size[0] * i0] = I->data[i0 + I->size[0] * i1];
      }
    }
  }

  emxFree_real_T(&x);
  emxFree_real_T(&I);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (findLinearTransformation.cpp) */
