/*
 * unique.cpp
 *
 * Code generation for function 'unique'
 *
 */

/* Include files */
#include "unique.h"
#include "calcNiiParcelPosition.h"
#include "calcNiiParcelPosition_data.h"
#include "calcNiiParcelPosition_emxutil.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
void unique_vector(const emxArray_real32_T *a, emxArray_real32_T *b)
{
  emxArray_int32_T *idx;
  int32_T na;
  int32_T n;
  int32_T i;
  int32_T b_i;
  emxArray_int32_T *iwork;
  int32_T k;
  int32_T i2;
  int32_T j;
  int32_T pEnd;
  boolean_T exitg1;
  int32_T p;
  real32_T absx;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  real32_T x;
  int32_T exitg2;
  int32_T exponent;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_int32_T(&idx, 1, true);
  na = a->size[0];
  n = a->size[0] + 1;
  i = idx->size[0];
  idx->size[0] = a->size[0];
  emxEnsureCapacity_int32_T(idx, i);
  b_i = a->size[0];
  for (i = 0; i < b_i; i++) {
    idx->data[i] = 0;
  }

  if (a->size[0] != 0) {
    emxInit_int32_T(&iwork, 1, true);
    i = iwork->size[0];
    iwork->size[0] = a->size[0];
    emxEnsureCapacity_int32_T(iwork, i);
    i = a->size[0] - 1;
    for (k = 1; k <= i; k += 2) {
      if ((a->data[k - 1] <= a->data[k]) || muSingleScalarIsNaN(a->data[k])) {
        idx->data[k - 1] = k;
        idx->data[k] = k + 1;
      } else {
        idx->data[k - 1] = k + 1;
        idx->data[k] = k;
      }
    }

    if ((a->size[0] & 1) != 0) {
      idx->data[a->size[0] - 1] = a->size[0];
    }

    b_i = 2;
    while (b_i < n - 1) {
      i2 = b_i << 1;
      j = 1;
      for (pEnd = b_i + 1; pEnd < n; pEnd = qEnd + b_i) {
        p = j;
        q = pEnd - 1;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }

        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          absx = a->data[idx->data[q] - 1];
          i = idx->data[p - 1];
          if ((a->data[i - 1] <= absx) || muSingleScalarIsNaN(absx)) {
            iwork->data[k] = i;
            p++;
            if (p == pEnd) {
              while (q + 1 < qEnd) {
                k++;
                iwork->data[k] = idx->data[q];
                q++;
              }
            }
          } else {
            iwork->data[k] = idx->data[q];
            q++;
            if (q + 1 == qEnd) {
              while (p < pEnd) {
                k++;
                iwork->data[k] = idx->data[p - 1];
                p++;
              }
            }
          }

          k++;
        }

        for (k = 0; k < kEnd; k++) {
          idx->data[(j + k) - 1] = iwork->data[k];
        }

        j = qEnd;
      }

      b_i = i2;
    }

    emxFree_int32_T(&iwork);
  }

  i = b->size[0];
  b->size[0] = a->size[0];
  emxEnsureCapacity_real32_T(b, i);
  for (k = 0; k < na; k++) {
    b->data[k] = a->data[idx->data[k] - 1];
  }

  emxFree_int32_T(&idx);
  k = 0;
  while ((k + 1 <= na) && muSingleScalarIsInf(b->data[k]) && (b->data[k] < 0.0F))
  {
    k++;
  }

  i2 = k;
  k = a->size[0];
  while ((k >= 1) && muSingleScalarIsNaN(b->data[k - 1])) {
    k--;
  }

  pEnd = a->size[0] - k;
  exitg1 = false;
  while ((!exitg1) && (k >= 1)) {
    absx = b->data[k - 1];
    if (muSingleScalarIsInf(absx) && (absx > 0.0F)) {
      k--;
    } else {
      exitg1 = true;
    }
  }

  b_i = (a->size[0] - k) - pEnd;
  p = -1;
  if (i2 > 0) {
    p = 0;
  }

  while (i2 + 1 <= k) {
    x = b->data[i2];
    do {
      exitg2 = 0;
      i2++;
      if (i2 + 1 > k) {
        exitg2 = 1;
      } else {
        absx = muSingleScalarAbs(x / 2.0F);
        if ((!muSingleScalarIsInf(absx)) && (!muSingleScalarIsNaN(absx))) {
          if (absx <= 1.17549435E-38F) {
            absx = 1.4013E-45F;
          } else {
            frexp(static_cast<real_T>(absx), &exponent);
            absx = static_cast<real32_T>(ldexp(1.0, exponent - 24));
          }
        } else {
          absx = rtNaNF;
        }

        if ((!(muSingleScalarAbs(x - b->data[i2]) < absx)) &&
            ((!muSingleScalarIsInf(b->data[i2])) || (!muSingleScalarIsInf(x)) ||
             ((b->data[i2] > 0.0F) != (x > 0.0F)))) {
          exitg2 = 1;
        }
      }
    } while (exitg2 == 0);

    p++;
    b->data[p] = x;
  }

  if (b_i > 0) {
    p++;
    b->data[p] = b->data[k];
  }

  i2 = k + b_i;
  for (j = 0; j < pEnd; j++) {
    p++;
    b->data[p] = b->data[i2 + j];
  }

  i = b->size[0];
  if (1 > p + 1) {
    b->size[0] = 0;
  } else {
    b->size[0] = p + 1;
  }

  emxEnsureCapacity_real32_T(b, i);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (unique.cpp) */
