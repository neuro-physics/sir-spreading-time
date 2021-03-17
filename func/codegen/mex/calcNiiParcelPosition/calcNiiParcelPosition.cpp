/*
 * calcNiiParcelPosition.cpp
 *
 * Code generation for function 'calcNiiParcelPosition'
 *
 */

/* Include files */
#include "calcNiiParcelPosition.h"
#include "calcNiiParcelPosition_data.h"
#include "calcNiiParcelPosition_emxutil.h"
#include "rt_nonfinite.h"
#include "unique.h"

/* Function Declarations */
static int32_T div_s32(int32_T numerator, int32_T denominator);

/* Function Definitions */
static int32_T div_s32(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T b_numerator;
  uint32_T b_denominator;
  if (denominator == 0) {
    emlrtDivisionByZeroErrorR2012b(NULL, emlrtRootTLSGlobal);
  } else {
    if (numerator < 0) {
      b_numerator = ~static_cast<uint32_T>(numerator) + 1U;
    } else {
      b_numerator = static_cast<uint32_T>(numerator);
    }

    if (denominator < 0) {
      b_denominator = ~static_cast<uint32_T>(denominator) + 1U;
    } else {
      b_denominator = static_cast<uint32_T>(denominator);
    }

    b_numerator /= b_denominator;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -static_cast<int32_T>(b_numerator);
    } else {
      quotient = static_cast<int32_T>(b_numerator);
    }
  }

  return quotient;
}

void calcNiiParcelPosition(const emxArray_real32_T *img, emxArray_real_T *r)
{
  emxArray_real32_T *u;
  int32_T nxin;
  emxArray_real32_T b_img;
  int32_T c_img[1];
  int32_T i;
  int32_T nxout;
  int32_T idx;
  emxArray_boolean_T *target;
  emxArray_int32_T *ii;
  emxArray_int32_T *varargout_6;
  emxArray_int32_T *result;
  emxArray_int32_T *vk;
  int32_T b_i;
  int32_T i1;
  boolean_T exitg1;
  real_T y[3];
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real32_T(&u, 1, true);
  nxin = img->size[0] * img->size[1] * img->size[2];
  b_img = *img;
  c_img[0] = nxin;
  b_img.size = &c_img[0];
  b_img.numDimensions = 1;
  unique_vector(&b_img, u);
  if (u->data[0] == 0.0F) {
    nxin = u->size[0];
    nxout = u->size[0] - 1;
    for (idx = 0; idx < nxout; idx++) {
      u->data[idx] = u->data[idx + 1];
    }

    i = u->size[0];
    if (1 > nxout) {
      u->size[0] = 0;
    } else {
      u->size[0] = nxin - 1;
    }

    emxEnsureCapacity_real32_T(u, i);
  }

  i = r->size[0] * r->size[1];
  r->size[0] = u->size[0];
  r->size[1] = 3;
  emxEnsureCapacity_real_T(r, i);
  nxin = u->size[0] * 3;
  for (i = 0; i < nxin; i++) {
    r->data[i] = 0.0;
  }

  i = u->size[0];
  emxInit_boolean_T(&target, 3, true);
  emxInit_int32_T(&ii, 1, true);
  emxInit_int32_T(&varargout_6, 1, true);
  emxInit_int32_T(&result, 2, true);
  emxInit_int32_T(&vk, 1, true);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = target->size[0] * target->size[1] * target->size[2];
    target->size[0] = img->size[0];
    target->size[1] = img->size[1];
    target->size[2] = img->size[2];
    emxEnsureCapacity_boolean_T(target, i1);
    nxin = img->size[0] * img->size[1] * img->size[2];
    for (i1 = 0; i1 < nxin; i1++) {
      target->data[i1] = (img->data[i1] == u->data[b_i]);
    }

    nxout = target->size[0] * target->size[1] * target->size[2];
    idx = 0;
    i1 = ii->size[0];
    ii->size[0] = nxout;
    emxEnsureCapacity_int32_T(ii, i1);
    nxin = 0;
    exitg1 = false;
    while ((!exitg1) && (nxin <= nxout - 1)) {
      if (target->data[nxin]) {
        idx++;
        ii->data[idx - 1] = nxin + 1;
        if (idx >= nxout) {
          exitg1 = true;
        } else {
          nxin++;
        }
      } else {
        nxin++;
      }
    }

    if (nxout == 1) {
      if (idx == 0) {
        ii->size[0] = 0;
      }
    } else {
      i1 = ii->size[0];
      if (1 > idx) {
        ii->size[0] = 0;
      } else {
        ii->size[0] = idx;
      }

      emxEnsureCapacity_int32_T(ii, i1);
    }

    nxout = target->size[0];
    idx = target->size[1] * target->size[0];
    nxin = ii->size[0];
    for (i1 = 0; i1 < nxin; i1++) {
      ii->data[i1]--;
    }

    i1 = vk->size[0];
    vk->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(vk, i1);
    nxin = ii->size[0];
    for (i1 = 0; i1 < nxin; i1++) {
      vk->data[i1] = div_s32(ii->data[i1], idx);
    }

    nxin = vk->size[0];
    i1 = varargout_6->size[0];
    varargout_6->size[0] = vk->size[0];
    emxEnsureCapacity_int32_T(varargout_6, i1);
    for (i1 = 0; i1 < nxin; i1++) {
      varargout_6->data[i1] = vk->data[i1] + 1;
    }

    nxin = ii->size[0];
    for (i1 = 0; i1 < nxin; i1++) {
      ii->data[i1] -= vk->data[i1] * idx;
    }

    i1 = vk->size[0];
    vk->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(vk, i1);
    nxin = ii->size[0];
    for (i1 = 0; i1 < nxin; i1++) {
      vk->data[i1] = div_s32(ii->data[i1], nxout);
    }

    nxin = ii->size[0];
    for (i1 = 0; i1 < nxin; i1++) {
      ii->data[i1] -= vk->data[i1] * nxout;
    }

    i1 = result->size[0] * result->size[1];
    result->size[0] = ii->size[0];
    result->size[1] = 3;
    emxEnsureCapacity_int32_T(result, i1);
    nxin = ii->size[0];
    for (i1 = 0; i1 < nxin; i1++) {
      result->data[i1] = ii->data[i1] + 1;
    }

    nxin = vk->size[0];
    for (i1 = 0; i1 < nxin; i1++) {
      result->data[i1 + result->size[0]] = vk->data[i1] + 1;
    }

    nxin = varargout_6->size[0];
    for (i1 = 0; i1 < nxin; i1++) {
      result->data[i1 + result->size[0] * 2] = varargout_6->data[i1];
    }

    i1 = result->size[0];
    if (result->size[0] == 0) {
      y[0] = 0.0;
      y[1] = 0.0;
      y[2] = 0.0;
    } else {
      for (nxin = 0; nxin < 3; nxin++) {
        nxout = nxin * result->size[0];
        y[nxin] = result->data[nxout];
        for (idx = 2; idx <= i1; idx++) {
          y[nxin] += static_cast<real_T>(result->data[(nxout + idx) - 1]);
        }
      }
    }

    r->data[b_i] = y[0] / static_cast<real_T>(result->size[0]);
    r->data[b_i + r->size[0]] = y[1] / static_cast<real_T>(result->size[0]);
    r->data[b_i + r->size[0] * 2] = y[2] / static_cast<real_T>(result->size[0]);
  }

  emxFree_int32_T(&vk);
  emxFree_int32_T(&result);
  emxFree_int32_T(&varargout_6);
  emxFree_int32_T(&ii);
  emxFree_boolean_T(&target);
  emxFree_real32_T(&u);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (calcNiiParcelPosition.cpp) */
