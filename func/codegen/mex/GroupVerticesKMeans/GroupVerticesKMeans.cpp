/*
 * GroupVerticesKMeans.cpp
 *
 * Code generation for function 'GroupVerticesKMeans'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "GroupVerticesKMeans.h"
#include "error.h"
#include "GroupVerticesKMeans_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "kmeans.h"
#include "repmat.h"
#include "GroupVerticesKMeans_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 11, "GroupVerticesKMeans",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\GroupVerticesKMeans.m"
};

static emlrtRSInfo b_emlrtRSI = { 16, "GroupVerticesKMeans",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\GroupVerticesKMeans.m"
};

static emlrtRSInfo c_emlrtRSI = { 17, "GroupVerticesKMeans",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\GroupVerticesKMeans.m"
};

static emlrtRSInfo d_emlrtRSI = { 19, "GroupVerticesKMeans",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\GroupVerticesKMeans.m"
};

static emlrtRSInfo e_emlrtRSI = { 44, "find",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"
};

static emlrtRSInfo h_emlrtRSI = { 28, "reshape",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m"
};

static emlrtRSInfo i_emlrtRSI = { 61, "reshape",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m"
};

static emlrtRSInfo j_emlrtRSI = { 108, "reshape",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m"
};

static emlrtMCInfo emlrtMCI = { 10, 10, "GroupVerticesKMeans",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\GroupVerticesKMeans.m"
};

static emlrtRTEInfo emlrtRTEI = { 2, 27, "GroupVerticesKMeans",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\GroupVerticesKMeans.m"
};

static emlrtRTEInfo b_emlrtRTEI = { 2, 47, "GroupVerticesKMeans",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\GroupVerticesKMeans.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 2, 50, "GroupVerticesKMeans",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\GroupVerticesKMeans.m"
};

static emlrtRTEInfo w_emlrtRTEI = { 59, 15, "assertValidSizeArg",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"
};

static emlrtRTEInfo x_emlrtRTEI = { 44, 19, "assertValidSizeArg",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"
};

static emlrtRTEInfo y_emlrtRTEI = { 71, 15, "reshape",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 14, 27, "n", "GroupVerticesKMeans",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\GroupVerticesKMeans.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 12, 27, "n", "GroupVerticesKMeans",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\GroupVerticesKMeans.m",
  0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 11, 49, "k", "GroupVerticesKMeans",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\GroupVerticesKMeans.m",
  0 };

static emlrtDCInfo emlrtDCI = { 68, 62, "reshape",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m",
  4 };

static emlrtRSInfo fd_emlrtRSI = { 10, "GroupVerticesKMeans",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\GroupVerticesKMeans.m"
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_perms, const
  char_T *identifier, real_T y[4]);
static const mxArray *perms(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *
  location);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4])
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4])
{
  static const int32_T dims[2] = { 2, 2 };

  int32_T i9;
  int32_T i10;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i9 = 0; i9 < 2; i9++) {
    for (i10 = 0; i10 < 2; i10++) {
      ret[i10 + (i9 << 1)] = (*(real_T (*)[4])mxGetData(src))[i10 + (i9 << 1)];
    }
  }

  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_perms, const
  char_T *identifier, real_T y[4])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(b_perms), &thisId, y);
  emlrtDestroyArray(&b_perms);
}

static const mxArray *perms(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *
  location)
{
  const mxArray *pArray;
  const mxArray *m5;
  pArray = b;
  return emlrtCallMATLABR2012b(sp, 1, &m5, 1, &pArray, "perms", true, location);
}

void GroupVerticesKMeans(const emlrtStack *sp, const emxArray_real_T *r, const
  emxArray_real_T *centers, emxArray_real_T *clusterNumbers)
{
  real_T sr[2];
  int32_T i0;
  real_T sc[2];
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 1, 2 };

  real_T *pData;
  int32_T maxdimlen;
  real_T pm[4];
  real_T dv0[4];
  boolean_T x[4];
  int32_T idx;
  int8_T ii_data[4];
  boolean_T exitg7;
  boolean_T guard3 = false;
  int8_T k_data[4];
  int8_T b_ii_data[2];
  boolean_T b_x[2];
  int8_T ii_size[2];
  boolean_T exitg6;
  static const int8_T iv1[2] = { 1, 2 };

  boolean_T guard2 = false;
  int32_T i1;
  int8_T n_data[2];
  int32_T sr1;
  boolean_T exitg5;
  boolean_T guard1 = false;
  int32_T i2;
  int32_T exitg4;
  boolean_T p;
  boolean_T b_guard2 = false;
  int32_T exitg3;
  real_T n;
  int32_T sz[2];
  emxArray_real_T *b_r;
  int32_T exitg2;
  boolean_T b_guard1 = false;
  int32_T exitg1;
  emxArray_real_T *b_centers;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* function groups = GroupVerticesKMeans(r, centers) */
  /*  returns groups of arbitrary number of elements from the position, r, of N elements in the network */
  /*  utilizes kmeans to produce the groups, so the number of elements in each group is random, but is around n */
  /*  each row of r is a position (3D or 2D) */
  for (i0 = 0; i0 < 2; i0++) {
    sr[i0] = r->size[i0];
  }

  for (i0 = 0; i0 < 2; i0++) {
    sc[i0] = centers->size[i0];
  }

  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m0);
  for (maxdimlen = 0; maxdimlen < 2; maxdimlen++) {
    pData[maxdimlen] = sr[maxdimlen];
  }

  emlrtAssign(&y, m0);
  st.site = &fd_emlrtRSI;
  emlrt_marshallIn(&st, perms(&st, y, (emlrtMCInfo *)&emlrtMCI), "perms", pm);
  st.site = &emlrtRSI;
  repmat(sc, dv0);
  for (i0 = 0; i0 < 4; i0++) {
    x[i0] = (pm[i0] == dv0[i0]);
  }

  b_st.site = &e_emlrtRSI;
  idx = 0;
  maxdimlen = 1;
  exitg7 = false;
  while ((!exitg7) && (maxdimlen < 5)) {
    guard3 = false;
    if (x[maxdimlen - 1]) {
      idx++;
      ii_data[idx - 1] = (int8_T)maxdimlen;
      if (idx >= 4) {
        exitg7 = true;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3) {
      maxdimlen++;
    }
  }

  if (1 > idx) {
    maxdimlen = 0;
  } else {
    maxdimlen = idx;
  }

  for (i0 = 0; i0 < maxdimlen; i0++) {
    k_data[i0] = ii_data[i0];
  }

  if (1 > idx) {
    i0 = 0;
  } else {
    i0 = idx;
  }

  if (!(1 <= i0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, (emlrtBCInfo *)&c_emlrtBCI, sp);
  }

  idx = 0;
  for (i0 = 0; i0 < 2; i0++) {
    b_x[i0] = (sr[i0] != pm[k_data[0] - 1]);
    ii_size[i0] = iv1[i0];
  }

  maxdimlen = 1;
  exitg6 = false;
  while ((!exitg6) && (maxdimlen < 3)) {
    guard2 = false;
    if (b_x[maxdimlen - 1]) {
      idx++;
      b_ii_data[idx - 1] = (int8_T)maxdimlen;
      if (idx >= 2) {
        exitg6 = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      maxdimlen++;
    }
  }

  if (1 > idx) {
    i1 = 0;
  } else {
    i1 = idx;
  }

  maxdimlen = ii_size[0] * i1;
  for (i0 = 0; i0 < maxdimlen; i0++) {
    n_data[i0] = b_ii_data[i0];
  }

  if (1 > idx) {
    i0 = 0;
  } else {
    i0 = idx;
  }

  if (!(1 <= i0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, (emlrtBCInfo *)&b_emlrtBCI, sp);
  }

  i0 = n_data[0];
  sr1 = (int32_T)(uint32_T)sr[i0 - 1];
  idx = 0;
  for (i0 = 0; i0 < 2; i0++) {
    b_x[i0] = (sc[i0] != pm[k_data[0] - 1]);
    ii_size[i0] = iv1[i0];
  }

  maxdimlen = 1;
  exitg5 = false;
  while ((!exitg5) && (maxdimlen < 3)) {
    guard1 = false;
    if (b_x[maxdimlen - 1]) {
      idx++;
      b_ii_data[idx - 1] = (int8_T)maxdimlen;
      if (idx >= 2) {
        exitg5 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      maxdimlen++;
    }
  }

  if (1 > idx) {
    i2 = 0;
  } else {
    i2 = idx;
  }

  maxdimlen = ii_size[0] * i2;
  for (i0 = 0; i0 < maxdimlen; i0++) {
    n_data[i0] = b_ii_data[i0];
  }

  if (1 > idx) {
    i0 = 0;
  } else {
    i0 = idx;
  }

  if (!(1 <= i0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, (emlrtBCInfo *)&emlrtBCI, sp);
  }

  st.site = &b_emlrtRSI;
  sr[0] = sr1;
  sr[1] = pm[k_data[0] - 1];
  idx = r->size[0] * r->size[1];
  b_st.site = &h_emlrtRSI;
  maxdimlen = 0;
  do {
    exitg4 = 0;
    if (maxdimlen < 2) {
      if ((sr[maxdimlen] != muDoubleScalarFloor(sr[maxdimlen])) ||
          muDoubleScalarIsInf(sr[maxdimlen])) {
        p = false;
        exitg4 = 1;
      } else {
        maxdimlen++;
      }
    } else {
      p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  b_guard2 = false;
  if (p) {
    maxdimlen = 0;
    do {
      exitg3 = 0;
      if (maxdimlen < 2) {
        if ((-2.147483648E+9 > sr[maxdimlen]) || (2.147483647E+9 < sr[maxdimlen]))
        {
          p = false;
          exitg3 = 1;
        } else {
          maxdimlen++;
        }
      } else {
        p = true;
        exitg3 = 1;
      }
    } while (exitg3 == 0);

    if (p) {
      p = true;
    } else {
      b_guard2 = true;
    }
  } else {
    b_guard2 = true;
  }

  if (b_guard2) {
    p = false;
  }

  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &x_emlrtRTEI,
      "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  n = 1.0;
  for (maxdimlen = 0; maxdimlen < 2; maxdimlen++) {
    if (sr[maxdimlen] <= 0.0) {
      n = 0.0;
    } else {
      n *= sr[maxdimlen];
    }
  }

  if (2.147483647E+9 >= n) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &w_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  for (i0 = 0; i0 < 2; i0++) {
    sz[i0] = (int32_T)sr[i0];
  }

  for (i0 = 0; i0 < 2; i0++) {
    sr[i0] = r->size[i0];
  }

  maxdimlen = (int32_T)(uint32_T)sr[0];
  if ((int32_T)(uint32_T)sr[1] > (int32_T)(uint32_T)sr[0]) {
    maxdimlen = (int32_T)(uint32_T)sr[1];
  }

  maxdimlen = muIntScalarMax_sint32(idx, maxdimlen);
  if (sz[0] > maxdimlen) {
    b_st.site = &i_emlrtRSI;
    error(&b_st);
  }

  if (sz[1] > maxdimlen) {
    b_st.site = &i_emlrtRSI;
    error(&b_st);
  }

  for (i0 = 0; i0 < 2; i0++) {
    maxdimlen = sz[i0];
    if (!(maxdimlen >= 0)) {
      emlrtNonNegativeCheckR2012b((real_T)maxdimlen, (emlrtDCInfo *)&emlrtDCI,
        &st);
    }
  }

  emxInit_real_T(&st, &b_r, 2, &b_emlrtRTEI, true);
  i0 = b_r->size[0] * b_r->size[1];
  b_r->size[0] = sz[0];
  b_r->size[1] = sz[1];
  emxEnsureCapacity(&st, (emxArray__common *)b_r, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  if (idx == b_r->size[0] * b_r->size[1]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &y_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  b_st.site = &j_emlrtRSI;
  if ((!(1 > idx)) && (idx > 2147483646)) {
    c_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (maxdimlen = 0; maxdimlen + 1 <= idx; maxdimlen++) {
    b_r->data[maxdimlen] = r->data[maxdimlen];
  }

  st.site = &c_emlrtRSI;
  sr[0] = (uint32_T)sc[n_data[0] - 1];
  sr[1] = pm[k_data[0] - 1];
  idx = centers->size[0] * centers->size[1];
  b_st.site = &h_emlrtRSI;
  maxdimlen = 0;
  do {
    exitg2 = 0;
    if (maxdimlen < 2) {
      if ((sr[maxdimlen] != muDoubleScalarFloor(sr[maxdimlen])) ||
          muDoubleScalarIsInf(sr[maxdimlen])) {
        p = false;
        exitg2 = 1;
      } else {
        maxdimlen++;
      }
    } else {
      p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  b_guard1 = false;
  if (p) {
    maxdimlen = 0;
    do {
      exitg1 = 0;
      if (maxdimlen < 2) {
        if ((-2.147483648E+9 > sr[maxdimlen]) || (2.147483647E+9 < sr[maxdimlen]))
        {
          p = false;
          exitg1 = 1;
        } else {
          maxdimlen++;
        }
      } else {
        p = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (p) {
      p = true;
    } else {
      b_guard1 = true;
    }
  } else {
    b_guard1 = true;
  }

  if (b_guard1) {
    p = false;
  }

  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &x_emlrtRTEI,
      "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  n = 1.0;
  for (maxdimlen = 0; maxdimlen < 2; maxdimlen++) {
    if (sr[maxdimlen] <= 0.0) {
      n = 0.0;
    } else {
      n *= sr[maxdimlen];
    }
  }

  if (2.147483647E+9 >= n) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &w_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  for (i0 = 0; i0 < 2; i0++) {
    sz[i0] = (int32_T)sr[i0];
  }

  for (i0 = 0; i0 < 2; i0++) {
    sr[i0] = centers->size[i0];
  }

  maxdimlen = (int32_T)(uint32_T)sr[0];
  if ((int32_T)(uint32_T)sr[1] > (int32_T)(uint32_T)sr[0]) {
    maxdimlen = (int32_T)(uint32_T)sr[1];
  }

  maxdimlen = muIntScalarMax_sint32(idx, maxdimlen);
  if (sz[0] > maxdimlen) {
    b_st.site = &i_emlrtRSI;
    error(&b_st);
  }

  if (sz[1] > maxdimlen) {
    b_st.site = &i_emlrtRSI;
    error(&b_st);
  }

  for (i0 = 0; i0 < 2; i0++) {
    maxdimlen = sz[i0];
    if (!(maxdimlen >= 0)) {
      emlrtNonNegativeCheckR2012b((real_T)maxdimlen, (emlrtDCInfo *)&emlrtDCI,
        &st);
    }
  }

  emxInit_real_T(&st, &b_centers, 2, &c_emlrtRTEI, true);
  i0 = b_centers->size[0] * b_centers->size[1];
  b_centers->size[0] = sz[0];
  b_centers->size[1] = sz[1];
  emxEnsureCapacity(&st, (emxArray__common *)b_centers, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  if (idx == b_centers->size[0] * b_centers->size[1]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &y_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  b_st.site = &j_emlrtRSI;
  if ((!(1 > idx)) && (idx > 2147483646)) {
    c_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (maxdimlen = 0; maxdimlen + 1 <= idx; maxdimlen++) {
    b_centers->data[maxdimlen] = centers->data[maxdimlen];
  }

  st.site = &d_emlrtRSI;
  kmeans(&st, b_r, (real_T)b_centers->size[0], b_centers, clusterNumbers);

  /*      groups = cell(1,nGroups); */
  /*      for i = 1:nGroups */
  /*          groups{i} = find(clusterNumbers == i); */
  /*      end */
  emxFree_real_T(&b_centers);
  emxFree_real_T(&b_r);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (GroupVerticesKMeans.cpp) */
