/*
 * rdivide.cpp
 *
 * Code generation for function 'rdivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "getNiiParcelCoord.h"
#include "rdivide.h"
#include "getNiiParcelCoord_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo i_emlrtRTEI = { 1, 14, "rdivide",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m"
};

/* Function Definitions */
void rdivide(const emlrtStack *sp, const emxArray_real32_T *x, real32_T y,
             emxArray_real32_T *z)
{
  int32_T i1;
  int32_T loop_ub;
  i1 = z->size[0] * z->size[1] * z->size[2];
  z->size[0] = x->size[0];
  z->size[1] = x->size[1];
  z->size[2] = x->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)z, i1, (int32_T)sizeof(real32_T),
                    &i_emlrtRTEI);
  loop_ub = x->size[0] * x->size[1] * x->size[2];
  for (i1 = 0; i1 < loop_ub; i1++) {
    z->data[i1] = x->data[i1] / y;
  }
}

/* End of code generation (rdivide.cpp) */
