/*
 * _coder_GroupVerticesKMeans_api.cpp
 *
 * Code generation for function '_coder_GroupVerticesKMeans_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "GroupVerticesKMeans.h"
#include "_coder_GroupVerticesKMeans_api.h"
#include "GroupVerticesKMeans_emxutil.h"
#include "GroupVerticesKMeans_data.h"

/* Variable Definitions */
static emlrtRTEInfo n_emlrtRTEI = { 1, 1, "_coder_GroupVerticesKMeans_api", "" };

/* Function Declarations */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *r, const
  char_T *identifier, emxArray_real_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *r, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(r), &thisId, y);
  emlrtDestroyArray(&r);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m4;
  static const int32_T iv9[1] = { 0 };

  y = NULL;
  m4 = emlrtCreateNumericArray(1, iv9, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m4, (void *)u->data);
  emlrtSetDimensions((mxArray *)m4, u->size, 1);
  emlrtAssign(&y, m4);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { -1, 3 };

  boolean_T bv0[2] = { true, true };

  int32_T iv10[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv0[0],
    iv10);
  ret->size[0] = iv10[0];
  ret->size[1] = iv10[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

void GroupVerticesKMeans_api(const mxArray * const prhs[2], const mxArray *plhs
  [1])
{
  emxArray_real_T *r;
  emxArray_real_T *centers;
  emxArray_real_T *clusterNumbers;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &r, 2, &n_emlrtRTEI, true);
  emxInit_real_T(&st, &centers, 2, &n_emlrtRTEI, true);
  emxInit_real_T1(&st, &clusterNumbers, 1, &n_emlrtRTEI, true);

  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[0]), "r", r);
  c_emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[1]), "centers",
                     centers);

  /* Invoke the target function */
  GroupVerticesKMeans(&st, r, centers, clusterNumbers);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(clusterNumbers);
  clusterNumbers->canFreeData = false;
  emxFree_real_T(&clusterNumbers);
  centers->canFreeData = false;
  emxFree_real_T(&centers);
  r->canFreeData = false;
  emxFree_real_T(&r);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_GroupVerticesKMeans_api.cpp) */
