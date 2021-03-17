/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_FindBestFunctionalMatch_api.cpp
 *
 * Code generation for function '_coder_FindBestFunctionalMatch_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindBestFunctionalMatch.h"
#include "_coder_FindBestFunctionalMatch_api.h"
#include "FindBestFunctionalMatch_emxutil.h"
#include "FindBestFunctionalMatch_mexutil.h"
#include "FindBestFunctionalMatch_data.h"

/* Variable Definitions */
static emlrtRTEInfo jc_emlrtRTEI = { 1,/* lineNo */
  1,                                   /* colNo */
  "_coder_FindBestFunctionalMatch_api",/* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *As, const
  char_T *identifier, emxArray_real_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Theta,
  const char_T *identifier);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nSeedsRange,
  const char_T *identifier, emxArray_real_T *y);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *comparisonMethod, const char_T *identifier, emxArray_char_T *y);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_char_T *ret);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m6;
  static const int32_T iv9[2] = { 0, 0 };

  y = NULL;
  m6 = emlrtCreateNumericArray(2, iv9, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m6, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m6, u->size, 2);
  emlrtAssign(&y, m6);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *As, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(As), &thisId, y);
  emlrtDestroyArray(&As);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Theta,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(Theta), &thisId);
  emlrtDestroyArray(&Theta);
  return y;
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m5;
  static const int32_T iv8[2] = { 0, 0 };

  y = NULL;
  m5 = emlrtCreateNumericArray(2, iv8, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m5, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m5, u->size, 2);
  emlrtAssign(&y, m5);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nSeedsRange,
  const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(nSeedsRange), &thisId, y);
  emlrtDestroyArray(&nSeedsRange);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  m_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *comparisonMethod, const char_T *identifier, emxArray_char_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(comparisonMethod), &thisId, y);
  emlrtDestroyArray(&comparisonMethod);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y)
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { -1, -1 };

  const boolean_T bv0[2] = { true, true };

  int32_T iv10[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv0[0],
    iv10);
  ret->size[0] = iv10[0];
  ret->size[1] = iv10[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv1[2] = { false, true };

  int32_T iv11[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv1[0],
    iv11);
  ret->size[0] = iv11[0];
  ret->size[1] = iv11[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_char_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv2[2] = { false, true };

  int32_T iv12[2];
  int32_T i13;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims, &bv2[0],
    iv12);
  i13 = ret->size[0] * ret->size[1];
  ret->size[0] = iv12[0];
  ret->size[1] = iv12[1];
  emxEnsureCapacity_char_T(sp, ret, i13, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 1, false);
  emlrtDestroyArray(&src);
}

void FindBestFunctionalMatch_api(const mxArray * const prhs[7], const mxArray
  *plhs[3])
{
  emxArray_real_T *As;
  emxArray_real_T *Af;
  emxArray_real_T *nSeedsRange;
  emxArray_char_T *comparisonMethod;
  emxArray_real_T *F;
  emxArray_real_T *R;
  emxArray_real_T *P;
  real_T Theta;
  real_T nSim;
  real_T tTotal;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &As, 2, &jc_emlrtRTEI, true);
  emxInit_real_T(&st, &Af, 2, &jc_emlrtRTEI, true);
  emxInit_real_T(&st, &nSeedsRange, 2, &jc_emlrtRTEI, true);
  emxInit_char_T(&st, &comparisonMethod, 2, &jc_emlrtRTEI, true);
  emxInit_real_T(&st, &F, 2, &jc_emlrtRTEI, true);
  emxInit_real_T(&st, &R, 2, &jc_emlrtRTEI, true);
  emxInit_real_T(&st, &P, 2, &jc_emlrtRTEI, true);

  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[0]), "As", As);
  c_emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[1]), "Af", Af);
  Theta = e_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[2]), "Theta");
  g_emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[3]), "nSeedsRange",
                     nSeedsRange);
  nSim = e_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[4]), "nSim");
  tTotal = e_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[5]),
    "tTotal");
  i_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[6]),
                     "comparisonMethod", comparisonMethod);

  /* Invoke the target function */
  FindBestFunctionalMatch(&st, As, Af, Theta, nSeedsRange, nSim, tTotal,
    comparisonMethod, F, R, P);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(F);
  plhs[1] = b_emlrt_marshallOut(R);
  plhs[2] = b_emlrt_marshallOut(P);
  P->canFreeData = false;
  emxFree_real_T(&P);
  R->canFreeData = false;
  emxFree_real_T(&R);
  F->canFreeData = false;
  emxFree_real_T(&F);
  emxFree_char_T(&comparisonMethod);
  nSeedsRange->canFreeData = false;
  emxFree_real_T(&nSeedsRange);
  Af->canFreeData = false;
  emxFree_real_T(&Af);
  As->canFreeData = false;
  emxFree_real_T(&As);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_FindBestFunctionalMatch_api.cpp) */
