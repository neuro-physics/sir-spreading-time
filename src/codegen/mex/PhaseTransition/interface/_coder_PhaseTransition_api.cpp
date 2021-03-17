/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_PhaseTransition_api.cpp
 *
 * Code generation for function '_coder_PhaseTransition_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "PhaseTransition.h"
#include "_coder_PhaseTransition_api.h"
#include "PhaseTransition_emxutil.h"
#include "PhaseTransition_mexutil.h"
#include "PhaseTransition_data.h"

/* Variable Definitions */
static emlrtRTEInfo lb_emlrtRTEI = { 1,/* lineNo */
  1,                                   /* colNo */
  "_coder_PhaseTransition_api",        /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *A, const
  char_T *identifier, emxArray_real_T *y);
static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *ThetaRange,
  const char_T *identifier, emxArray_real_T *y);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *icType,
  const char_T *identifier, emxArray_char_T *y);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y);
static boolean_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *useWeightSampling, const char_T *identifier);
static boolean_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_char_T *ret);
static boolean_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m5;
  static const int32_T iv7[2] = { 0, 0 };

  y = NULL;
  m5 = emlrtCreateNumericArray(2, iv7, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m5, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m5, u->size, 2);
  emlrtAssign(&y, m5);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *A, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(A), &thisId, y);
  emlrtDestroyArray(&A);
}

static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m6;
  static const int32_T iv8[2] = { 0, 0 };

  y = NULL;
  m6 = emlrtCreateNumericArray(2, iv8, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m6, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m6, u->size, 2);
  emlrtAssign(&y, m6);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *ThetaRange,
  const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(ThetaRange), &thisId, y);
  emlrtDestroyArray(&ThetaRange);
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  m_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *icType,
  const char_T *identifier, emxArray_char_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(icType), &thisId, y);
  emlrtDestroyArray(&icType);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y)
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static boolean_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *useWeightSampling, const char_T *identifier)
{
  boolean_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(sp, emlrtAlias(useWeightSampling), &thisId);
  emlrtDestroyArray(&useWeightSampling);
  return y;
}

static boolean_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { -1, -1 };

  const boolean_T bv0[2] = { true, true };

  int32_T iv9[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv0[0],
    iv9);
  ret->size[0] = iv9[0];
  ret->size[1] = iv9[1];
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

  int32_T iv10[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv1[0],
    iv10);
  ret->size[0] = iv10[0];
  ret->size[1] = iv10[1];
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

  int32_T iv11[2];
  int32_T i11;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims, &bv2[0],
    iv11);
  i11 = ret->size[0] * ret->size[1];
  ret->size[0] = iv11[0];
  ret->size[1] = iv11[1];
  emxEnsureCapacity_char_T(sp, ret, i11, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 1, false);
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

void PhaseTransition_api(const mxArray * const prhs[7], const mxArray *plhs[4])
{
  emxArray_real_T *A;
  emxArray_real_T *ThetaRange;
  emxArray_real_T *x0;
  emxArray_char_T *icType;
  emxArray_real_T *nAct;
  emxArray_real_T *nAct2;
  emxArray_real_T *stimIndex;
  emxArray_real_T *nActVec;
  real_T nSim;
  real_T tTotal;
  boolean_T useWeightSampling;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T1(&st, &A, 2, &lb_emlrtRTEI, true);
  emxInit_real_T1(&st, &ThetaRange, 2, &lb_emlrtRTEI, true);
  emxInit_real_T1(&st, &x0, 2, &lb_emlrtRTEI, true);
  emxInit_char_T(&st, &icType, 2, &lb_emlrtRTEI, true);
  emxInit_real_T1(&st, &nAct, 2, &lb_emlrtRTEI, true);
  emxInit_real_T1(&st, &nAct2, 2, &lb_emlrtRTEI, true);
  emxInit_real_T1(&st, &stimIndex, 2, &lb_emlrtRTEI, true);
  emxInit_real_T1(&st, &nActVec, 2, &lb_emlrtRTEI, true);

  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[0]), "A", A);
  e_emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[1]), "ThetaRange",
                     ThetaRange);
  nSim = emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[2]), "nSim");
  tTotal = emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[3]), "tTotal");
  e_emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[4]), "x0", x0);
  g_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[5]), "icType",
                     icType);
  useWeightSampling = i_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs
    [6]), "useWeightSampling");

  /* Invoke the target function */
  PhaseTransition(&st, A, ThetaRange, nSim, tTotal, x0, icType,
                  useWeightSampling, nAct, nAct2, stimIndex, nActVec);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(nAct);
  plhs[1] = b_emlrt_marshallOut(nAct2);
  plhs[2] = c_emlrt_marshallOut(stimIndex);
  plhs[3] = c_emlrt_marshallOut(nActVec);
  nActVec->canFreeData = false;
  emxFree_real_T(&nActVec);
  stimIndex->canFreeData = false;
  emxFree_real_T(&stimIndex);
  nAct2->canFreeData = false;
  emxFree_real_T(&nAct2);
  nAct->canFreeData = false;
  emxFree_real_T(&nAct);
  emxFree_char_T(&icType);
  x0->canFreeData = false;
  emxFree_real_T(&x0);
  ThetaRange->canFreeData = false;
  emxFree_real_T(&ThetaRange);
  A->canFreeData = false;
  emxFree_real_T(&A);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_PhaseTransition_api.cpp) */
