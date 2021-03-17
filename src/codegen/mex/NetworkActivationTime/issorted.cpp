/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * issorted.cpp
 *
 * Code generation for function 'issorted'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "NetworkActivationTime.h"
#include "issorted.h"

/* Function Definitions */
boolean_T issorted(const emxArray_real_T *x)
{
  boolean_T y;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  y = true;
  if (x->size[1] != 0) {
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (k <= x->size[1] - 1)) {
      if ((x->data[k - 1] <= x->data[k]) || muDoubleScalarIsNaN(x->data[k])) {
        p = true;
      } else {
        p = false;
      }

      if (!p) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return y;
}

/* End of code generation (issorted.cpp) */
