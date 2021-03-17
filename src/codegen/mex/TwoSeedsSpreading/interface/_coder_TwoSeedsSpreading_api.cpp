/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_TwoSeedsSpreading_api.cpp
 *
 * Code generation for function '_coder_TwoSeedsSpreading_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "TwoSeedsSpreading.h"
#include "_coder_TwoSeedsSpreading_api.h"
#include "TwoSeedsSpreading_emxutil.h"
#include "TwoSeedsSpreading_data.h"

/* Variable Definitions */
static emlrtRTEInfo jc_emlrtRTEI = { 1,/* lineNo */
  1,                                   /* colNo */
  "_coder_TwoSeedsSpreading_api",      /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Theta,
  const char_T *identifier);
static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u);
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *A, const
  char_T *identifier, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m4;
  static const int32_T iv9[1] = { 0 };

  y = NULL;
  m4 = emlrtCreateNumericArray(1, iv9, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m4, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m4, u->size, 1);
  emlrtAssign(&y, m4);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Theta,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(Theta), &thisId);
  emlrtDestroyArray(&Theta);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m5;
  static const int32_T iv10[3] = { 0, 0, 0 };

  y = NULL;
  m5 = emlrtCreateNumericArray(3, iv10, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m5, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m5, u->size, 3);
  emlrtAssign(&y, m5);
  return y;
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { -1, -1 };

  const boolean_T bv0[2] = { true, true };

  int32_T iv11[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv0[0],
    iv11);
  ret->size[0] = iv11[0];
  ret->size[1] = iv11[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *A, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(A), &thisId, y);
  emlrtDestroyArray(&A);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m3;
  static const int32_T iv8[2] = { 0, 0 };

  y = NULL;
  m3 = emlrtCreateNumericArray(2, iv8, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m3, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m3, u->size, 2);
  emlrtAssign(&y, m3);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void TwoSeedsSpreading_api(const mxArray * const prhs[4], const mxArray *plhs[8])
{
  emxArray_real_T *A;
  emxArray_real_T *Cp1;
  emxArray_real_T *Cp2;
  emxArray_real_T *H;
  emxArray_real_T *Cf;
  emxArray_real_T *T;
  emxArray_real_T *Tn;
  emxArray_real_T *S;
  emxArray_real_T *Sn;
  real_T Theta;
  real_T tTotal;
  real_T isCompetitive;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &A, 2, &jc_emlrtRTEI, true);
  emxInit_real_T(&st, &Cp1, 2, &jc_emlrtRTEI, true);
  emxInit_real_T(&st, &Cp2, 2, &jc_emlrtRTEI, true);
  emxInit_real_T1(&st, &H, 1, &jc_emlrtRTEI, true);
  emxInit_real_T1(&st, &Cf, 1, &jc_emlrtRTEI, true);
  emxInit_real_T(&st, &T, 2, &jc_emlrtRTEI, true);
  emxInit_real_T2(&st, &Tn, 3, &jc_emlrtRTEI, true);
  emxInit_real_T(&st, &S, 2, &jc_emlrtRTEI, true);
  emxInit_real_T2(&st, &Sn, 3, &jc_emlrtRTEI, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[0]), "A", A);
  Theta = c_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[1]), "Theta");
  tTotal = c_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[2]),
    "tTotal");
  isCompetitive = c_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[3]),
    "isCompetitive");

  /* Invoke the target function */
  TwoSeedsSpreading(&st, A, Theta, tTotal, isCompetitive, Cp1, Cp2, H, Cf, T, Tn,
                    S, Sn);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(Cp1);
  plhs[1] = emlrt_marshallOut(Cp2);
  plhs[2] = b_emlrt_marshallOut(H);
  plhs[3] = b_emlrt_marshallOut(Cf);
  plhs[4] = emlrt_marshallOut(T);
  plhs[5] = c_emlrt_marshallOut(Tn);
  plhs[6] = emlrt_marshallOut(S);
  plhs[7] = c_emlrt_marshallOut(Sn);
  Sn->canFreeData = false;
  emxFree_real_T(&Sn);
  S->canFreeData = false;
  emxFree_real_T(&S);
  Tn->canFreeData = false;
  emxFree_real_T(&Tn);
  T->canFreeData = false;
  emxFree_real_T(&T);
  Cf->canFreeData = false;
  emxFree_real_T(&Cf);
  H->canFreeData = false;
  emxFree_real_T(&H);
  Cp2->canFreeData = false;
  emxFree_real_T(&Cp2);
  Cp1->canFreeData = false;
  emxFree_real_T(&Cp1);
  A->canFreeData = false;
  emxFree_real_T(&A);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_TwoSeedsSpreading_api.cpp) */
