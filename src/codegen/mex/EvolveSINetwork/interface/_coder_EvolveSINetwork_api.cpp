/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_EvolveSINetwork_api.cpp
 *
 * Code generation for function '_coder_EvolveSINetwork_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EvolveSINetwork.h"
#include "_coder_EvolveSINetwork_api.h"
#include "EvolveSINetwork_emxutil.h"
#include "EvolveSINetwork_data.h"

/* Variable Definitions */
static emlrtRTEInfo b_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_EvolveSINetwork_api",        /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_struct0_T *y);
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const struct2_T
  u);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *c_emlrt_marshallOut(const real_T u);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static struct1_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *nodes, const
  char_T *identifier, emxArray_struct0_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tTotal,
  const char_T *identifier);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *par, const
  char_T *identifier, struct2_T *y);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y);
static boolean_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static boolean_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_char_T *ret);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[4] = { "x", "neigh", "w", "par" };

  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv0[2] = { false, true };

  int32_T sizes[2];
  int32_T i7;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckVsStructR2012b(sp, parentId, u, 4, fieldNames, 2U, dims, &bv0[0],
    sizes);
  i7 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_struct0_T(sp, y, i7, (emlrtRTEInfo *)NULL);
  for (i7 = 0; i7 < sizes[1]; i7++) {
    thisId.fIdentifier = "x";
    y->data[i7].x = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
      i7, 0, "x")), &thisId);
    thisId.fIdentifier = "neigh";
    d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i7, 1, "neigh")),
                       &thisId, y->data[i7].neigh);
    thisId.fIdentifier = "w";
    d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i7, 2, "w")),
                       &thisId, y->data[i7].w);
    thisId.fIdentifier = "par";
    y->data[i7].par = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
      u, i7, 3, "par")), &thisId);
  }

  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const struct2_T
  u)
{
  const mxArray *y;
  emxArray_real_T *b_u;
  static const char * sv0[8] = { "N", "nSeeds", "isCompetitive", "seeds", "nSim",
    "seedType", "seedTrial", "x0" };

  const mxArray *b_y;
  const mxArray *m1;
  int32_T i8;
  int32_T loop_ub;
  real_T *pData;
  emxArray_char_T *c_u;
  int32_T i;
  emxArray_real_T *d_u;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_u, 2, (emlrtRTEInfo *)NULL, true);
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 8, sv0));
  emlrtSetFieldR2017b(y, 0, "N", c_emlrt_marshallOut(u.N), 0);
  emlrtSetFieldR2017b(y, 0, "nSeeds", c_emlrt_marshallOut(u.nSeeds), 1);
  b_y = NULL;
  m1 = emlrtCreateLogicalScalar(u.isCompetitive);
  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "isCompetitive", b_y, 2);
  i8 = b_u->size[0] * b_u->size[1];
  b_u->size[0] = u.seeds->size[0];
  b_u->size[1] = u.seeds->size[1];
  emxEnsureCapacity_real_T(sp, b_u, i8, (emlrtRTEInfo *)NULL);
  loop_ub = u.seeds->size[0] * u.seeds->size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    b_u->data[i8] = u.seeds->data[i8];
  }

  b_y = NULL;
  m1 = emlrtCreateNumericArray(2, *(int32_T (*)[2])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = (real_T *)emlrtMxGetPr(m1);
  i8 = 0;
  loop_ub = 0;
  emxFree_real_T(&b_u);
  while (loop_ub < u.seeds->size[1]) {
    for (i = 0; i < u.seeds->size[0]; i++) {
      pData[i8] = u.seeds->data[i + u.seeds->size[0] * loop_ub];
      i8++;
    }

    loop_ub++;
  }

  emxInit_char_T(sp, &c_u, 2, (emlrtRTEInfo *)NULL, true);
  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "seeds", b_y, 3);
  emlrtSetFieldR2017b(y, 0, "nSim", c_emlrt_marshallOut(u.nSim), 4);
  i8 = c_u->size[0] * c_u->size[1];
  c_u->size[0] = 1;
  c_u->size[1] = u.seedType->size[1];
  emxEnsureCapacity_char_T(sp, c_u, i8, (emlrtRTEInfo *)NULL);
  loop_ub = u.seedType->size[0] * u.seedType->size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    c_u->data[i8] = u.seedType->data[i8];
  }

  emxInit_real_T(sp, &d_u, 2, (emlrtRTEInfo *)NULL, true);
  b_y = NULL;
  m1 = emlrtCreateCharArray(2, *(int32_T (*)[2])c_u->size);
  emlrtInitCharArrayR2013a(sp, u.seedType->size[1], m1, &c_u->data[0]);
  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "seedType", b_y, 5);
  emlrtSetFieldR2017b(y, 0, "seedTrial", c_emlrt_marshallOut(u.seedTrial), 6);
  i8 = d_u->size[0] * d_u->size[1];
  d_u->size[0] = 1;
  d_u->size[1] = u.x0->size[1];
  emxEnsureCapacity_real_T(sp, d_u, i8, (emlrtRTEInfo *)NULL);
  loop_ub = u.x0->size[0] * u.x0->size[1];
  emxFree_char_T(&c_u);
  for (i8 = 0; i8 < loop_ub; i8++) {
    d_u->data[i8] = u.x0->data[i8];
  }

  b_y = NULL;
  m1 = emlrtCreateNumericArray(2, *(int32_T (*)[2])d_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = (real_T *)emlrtMxGetPr(m1);
  i8 = 0;
  loop_ub = 0;
  emxFree_real_T(&d_u);
  while (loop_ub < u.x0->size[1]) {
    pData[i8] = u.x0->data[u.x0->size[0] * loop_ub];
    i8++;
    loop_ub++;
  }

  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "x0", b_y, 7);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = m_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m2;
  y = NULL;
  m2 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m2);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static struct1_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  struct1_T y;
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[8] = { "Iext", "Isyn", "kInp", "Theta", "W",
    "n", "nInp", "spTime" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 8, fieldNames, 0U, &dims);
  thisId.fIdentifier = "Iext";
  y.Iext = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "Iext")), &thisId);
  thisId.fIdentifier = "Isyn";
  y.Isyn = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "Isyn")), &thisId);
  thisId.fIdentifier = "kInp";
  y.kInp = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "kInp")), &thisId);
  thisId.fIdentifier = "Theta";
  y.Theta = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "Theta")), &thisId);
  thisId.fIdentifier = "W";
  y.W = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4, "W")),
    &thisId);
  thisId.fIdentifier = "n";
  y.n = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5, "n")),
    &thisId);
  thisId.fIdentifier = "nInp";
  y.nInp = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6,
    "nInp")), &thisId);
  thisId.fIdentifier = "spTime";
  y.spTime = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7,
    "spTime")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *nodes, const
  char_T *identifier, emxArray_struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(nodes), &thisId, y);
  emlrtDestroyArray(&nodes);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 0, 0 };

  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m0, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m0, u->size, 2);
  emlrtAssign(&y, m0);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tTotal,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(sp, emlrtAlias(tTotal), &thisId);
  emlrtDestroyArray(&tTotal);
  return y;
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *par, const
  char_T *identifier, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(par), &thisId, y);
  emlrtDestroyArray(&par);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[8] = { "N", "nSeeds", "isCompetitive", "seeds",
    "nSim", "seedType", "seedTrial", "x0" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 8, fieldNames, 0U, &dims);
  thisId.fIdentifier = "N";
  y->N = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "N")),
    &thisId);
  thisId.fIdentifier = "nSeeds";
  y->nSeeds = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "nSeeds")), &thisId);
  thisId.fIdentifier = "isCompetitive";
  y->isCompetitive = i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 2, "isCompetitive")), &thisId);
  thisId.fIdentifier = "seeds";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "seeds")),
                     &thisId, y->seeds);
  thisId.fIdentifier = "nSim";
  y->nSim = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4,
    "nSim")), &thisId);
  thisId.fIdentifier = "seedType";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5, "seedType")),
                     &thisId, y->seedType);
  thisId.fIdentifier = "seedTrial";
  y->seedTrial = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    6, "seedTrial")), &thisId);
  thisId.fIdentifier = "x0";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7, "x0")),
                     &thisId, y->x0);
  emlrtDestroyArray(&u);
}

static boolean_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  p_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y)
{
  q_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[1] = { -1 };

  const boolean_T bv1[1] = { true };

  int32_T iv1[1];
  int32_T i9;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv1[0],
    iv1);
  i9 = ret->size[0];
  ret->size[0] = iv1[0];
  emxEnsureCapacity_real_T1(sp, ret, i9, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static boolean_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  boolean_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 0U, &dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { -1, -1 };

  const boolean_T bv2[2] = { true, true };

  int32_T iv2[2];
  int32_T i10;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv2[0],
    iv2);
  i10 = ret->size[0] * ret->size[1];
  ret->size[0] = iv2[0];
  ret->size[1] = iv2[1];
  emxEnsureCapacity_real_T(sp, ret, i10, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_char_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv3[2] = { false, true };

  int32_T iv3[2];
  int32_T i11;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims, &bv3[0],
    iv3);
  i11 = ret->size[0] * ret->size[1];
  ret->size[0] = iv3[0];
  ret->size[1] = iv3[1];
  emxEnsureCapacity_char_T(sp, ret, i11, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 1, false);
  emlrtDestroyArray(&src);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv4[2] = { false, true };

  int32_T iv4[2];
  int32_T i12;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv4[0],
    iv4);
  i12 = ret->size[0] * ret->size[1];
  ret->size[0] = iv4[0];
  ret->size[1] = iv4[1];
  emxEnsureCapacity_real_T(sp, ret, i12, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

void EvolveSINetwork_api(const mxArray * const prhs[4], const mxArray *plhs[4])
{
  emxArray_struct0_T *nodes;
  struct2_T par;
  emxArray_real_T *xData;
  emxArray_real_T *spTime;
  real_T tTotal;
  real_T returnTimeEvol;
  real_T netActTime;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_struct0_T(&st, &nodes, 2, &b_emlrtRTEI, true);
  emxInitStruct_struct2_T(&st, &par, &b_emlrtRTEI, true);
  emxInit_real_T(&st, &xData, 2, &b_emlrtRTEI, true);
  emxInit_real_T(&st, &spTime, 2, &b_emlrtRTEI, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[0]), "nodes", nodes);
  tTotal = f_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[1]),
    "tTotal");
  g_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[2]), "par", &par);
  returnTimeEvol = f_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[3]),
    "returnTimeEvol");

  /* Invoke the target function */
  EvolveSINetwork(&st, nodes, tTotal, &par, returnTimeEvol, xData, &netActTime,
                  spTime);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(xData);
  plhs[1] = b_emlrt_marshallOut(&st, par);
  plhs[2] = c_emlrt_marshallOut(netActTime);
  plhs[3] = emlrt_marshallOut(spTime);
  spTime->canFreeData = false;
  emxFree_real_T(&spTime);
  xData->canFreeData = false;
  emxFree_real_T(&xData);
  emxFreeStruct_struct2_T(&par);
  emxFree_struct0_T(&nodes);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_EvolveSINetwork_api.cpp) */
