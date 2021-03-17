/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_EvolveSINetworkAndCountActive_api.cpp
 *
 * Code generation for function '_coder_EvolveSINetworkAndCountActive_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EvolveSINetworkAndCountActive.h"
#include "_coder_EvolveSINetworkAndCountActive_api.h"
#include "EvolveSINetworkAndCountActive_emxutil.h"
#include "EvolveSINetworkAndCountActive_data.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 1,   /* lineNo */
  1,                                   /* colNo */
  "_coder_EvolveSINetworkAndCountActive_api",/* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_struct0_T *y);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static struct1_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *nodes, const
  char_T *identifier, emxArray_struct0_T *y);
static const mxArray *emlrt_marshallOut(const real_T u);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tTotal,
  const char_T *identifier);
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
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
  int32_T i2;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckVsStructR2012b(sp, parentId, u, 4, fieldNames, 2U, dims, &bv0[0],
    sizes);
  i2 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_struct0_T(sp, y, i2, (emlrtRTEInfo *)NULL);
  for (i2 = 0; i2 < sizes[1]; i2++) {
    thisId.fIdentifier = "x";
    y->data[i2].x = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
      i2, 0, "x")), &thisId);
    thisId.fIdentifier = "neigh";
    d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i2, 1, "neigh")),
                       &thisId, y->data[i2].neigh);
    thisId.fIdentifier = "w";
    d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i2, 2, "w")),
                       &thisId, y->data[i2].w);
    thisId.fIdentifier = "par";
    y->data[i2].par = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
      u, i2, 3, "par")), &thisId);
  }

  emlrtDestroyArray(&u);
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  h_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
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

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m0;
  y = NULL;
  m0 = emlrtCreateDoubleScalar(u);
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

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[1] = { -1 };

  const boolean_T bv1[1] = { true };

  int32_T iv0[1];
  int32_T i3;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv1[0],
    iv0);
  i3 = ret->size[0];
  ret->size[0] = iv0[0];
  emxEnsureCapacity_real_T(sp, ret, i3, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

void EvolveSINetworkAndCountActive_api(const mxArray * const prhs[2], const
  mxArray *plhs[1])
{
  emxArray_struct0_T *nodes;
  real_T tTotal;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_struct0_T(&st, &nodes, 2, &emlrtRTEI, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[0]), "nodes", nodes);
  tTotal = f_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[1]),
    "tTotal");

  /* Invoke the target function */
  tTotal = EvolveSINetworkAndCountActive(&st, nodes, tTotal);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(tTotal);
  emxFree_struct0_T(&nodes);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_EvolveSINetworkAndCountActive_api.cpp) */
