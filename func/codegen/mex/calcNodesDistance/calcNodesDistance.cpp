/*
 * calcNodesDistance.cpp
 *
 * Code generation for function 'calcNodesDistance'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calcNodesDistance.h"
#include "calcNodesDistance_emxutil.h"
#include "calcNodesDistance_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 1, 14, "calcNodesDistance",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\calcNodesDistance.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 12, 33, "r", "calcNodesDistance",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\calcNodesDistance.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 12, 42, "r", "calcNodesDistance",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\calcNodesDistance.m",
  0 };

static emlrtECInfo emlrtECI = { 2, 12, 31, "calcNodesDistance",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\calcNodesDistance.m"
};

static emlrtBCInfo c_emlrtBCI = { -1, -1, 11, 18, "A", "calcNodesDistance",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\calcNodesDistance.m",
  0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 11, 20, "A", "calcNodesDistance",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\calcNodesDistance.m",
  0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 12, 19, "d", "calcNodesDistance",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\calcNodesDistance.m",
  0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 12, 21, "d", "calcNodesDistance",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\calcNodesDistance.m",
  0 };

/* Function Definitions */
void calcNodesDistance(const emlrtStack *sp, const emxArray_real_T *A, const
  emxArray_real_T *r, emxArray_real_T *d)
{
  int32_T N;
  uint32_T uv0[2];
  int32_T i0;
  int32_T loop_ub;
  int32_T i;
  int32_T j;
  int32_T i1;
  int32_T r_size[2];
  int32_T b_r[2];
  int32_T b_r_size[2];
  int32_T c_r[2];
  real_T x_data[3];
  ptrdiff_t n_t;
  real_T y;
  ptrdiff_t incx_t;

  /*  A (NxN): adjacency matrix */
  /*  r (Nx3): position of each node in A */
  /*  */
  /*  return: */
  /*  d (NxN): distance between each connected node in A */
  N = A->size[0] - 1;
  for (i0 = 0; i0 < 2; i0++) {
    uv0[i0] = (uint32_T)A->size[i0];
  }

  i0 = d->size[0] * d->size[1];
  d->size[0] = (int32_T)uv0[0];
  d->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity(sp, (emxArray__common *)d, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = (int32_T)uv0[0] * (int32_T)uv0[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    d->data[i0] = 0.0;
  }

  i = 0;
  while (i <= N) {
    j = 0;
    while (j <= N) {
      i0 = A->size[0];
      loop_ub = 1 + i;
      if (!((loop_ub >= 1) && (loop_ub <= i0))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i0, (emlrtBCInfo *)&c_emlrtBCI,
          sp);
      }

      i0 = A->size[1];
      i1 = 1 + j;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&d_emlrtBCI, sp);
      }

      if (A->data[(loop_ub + A->size[0] * (i1 - 1)) - 1] != 0.0) {
        i0 = r->size[0];
        loop_ub = i + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i0))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i0, (emlrtBCInfo *)&emlrtBCI,
            sp);
        }

        i0 = r->size[0];
        loop_ub = j + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i0))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i0, (emlrtBCInfo *)
            &b_emlrtBCI, sp);
        }

        i0 = r->size[1];
        r_size[0] = 1;
        r_size[1] = i0;
        for (i0 = 0; i0 < 2; i0++) {
          b_r[i0] = r_size[i0];
        }

        i0 = r->size[1];
        b_r_size[0] = 1;
        b_r_size[1] = i0;
        for (i0 = 0; i0 < 2; i0++) {
          c_r[i0] = b_r_size[i0];
        }

        if ((b_r[0] != c_r[0]) || (b_r[1] != c_r[1])) {
          emlrtSizeEqCheckNDR2012b(&b_r[0], &c_r[0], (emlrtECInfo *)&emlrtECI,
            sp);
        }

        loop_ub = r->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          x_data[i0] = r->data[i + r->size[0] * i0] - r->data[j + r->size[0] *
            i0];
        }

        if (loop_ub == 0) {
          y = 0.0;
        } else {
          n_t = (ptrdiff_t)loop_ub;
          incx_t = (ptrdiff_t)1;
          y = dnrm2(&n_t, &x_data[0], &incx_t);
        }

        i0 = d->size[0];
        loop_ub = 1 + i;
        if (!((loop_ub >= 1) && (loop_ub <= i0))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i0, (emlrtBCInfo *)
            &e_emlrtBCI, sp);
        }

        i0 = d->size[1];
        i1 = 1 + j;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&f_emlrtBCI,
            sp);
        }

        d->data[(loop_ub + d->size[0] * (i1 - 1)) - 1] = y;
      }

      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

/* End of code generation (calcNodesDistance.cpp) */
