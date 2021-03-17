/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.cpp
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "PhaseTransition.h"
#include "repmat.h"
#include "PhaseTransition_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "PhaseTransition_mexutil.h"
#include "PhaseTransition_data.h"

/* Variable Definitions */
static emlrtRSInfo vc_emlrtRSI = { 117,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

/* Function Definitions */
void repmat(const emlrtStack *sp, const emxArray_real_T *a, real_T varargin_1,
            emxArray_real_T *b)
{
  boolean_T overflow;
  real_T b_varargin_1;
  int32_T outsize_idx_1;
  const mxArray *y;
  int32_T ibmat;
  const mxArray *m3;
  static const int32_T iv6[2] = { 1, 15 };

  int32_T itilerow;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &db_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if ((varargin_1 != muDoubleScalarFloor(varargin_1)) || muDoubleScalarIsInf
      (varargin_1)) {
    overflow = false;
  } else {
    overflow = true;
  }

  if (overflow) {
    if ((-2.147483648E+9 > varargin_1) || (2.147483647E+9 < varargin_1)) {
      overflow = false;
    } else {
      overflow = true;
    }

    if (overflow) {
      overflow = true;
    } else {
      overflow = false;
    }
  } else {
    overflow = false;
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2012b(&st, &kc_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }

  if (varargin_1 <= 0.0) {
    b_varargin_1 = 0.0;
  } else {
    b_varargin_1 = varargin_1;
  }

  if (!(2.147483647E+9 >= b_varargin_1)) {
    emlrtErrorWithMessageIdR2012b(&st, &jc_emlrtRTEI, "Coder:MATLAB:pmaxsize", 0);
  }

  outsize_idx_1 = a->size[1];
  if (outsize_idx_1 != a->size[1]) {
    y = NULL;
    m3 = emlrtCreateCharArray(2, iv6);
    emlrtInitCharArrayR2013a(sp, 15, m3, &cv0[0]);
    emlrtAssign(&y, m3);
    st.site = &wd_emlrtRSI;
    error(&st, y, (emlrtMCInfo *)&c_emlrtMCI);
  }

  ibmat = b->size[0] * b->size[1];
  b->size[0] = (int32_T)varargin_1;
  b->size[1] = outsize_idx_1;
  emxEnsureCapacity_real_T(sp, b, ibmat, &fb_emlrtRTEI);
  if (!(a->size[1] == 0)) {
    if ((int32_T)varargin_1 == 0) {
      overflow = true;
    } else if (outsize_idx_1 == 0) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (!overflow) {
      st.site = &fb_emlrtRSI;
      overflow = (a->size[1] > 2147483646);
      if (overflow) {
        b_st.site = &gb_emlrtRSI;
        c_st.site = &gb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (outsize_idx_1 = 0; outsize_idx_1 + 1 <= a->size[1]; outsize_idx_1++)
      {
        ibmat = outsize_idx_1 * (int32_T)varargin_1;
        st.site = &vc_emlrtRSI;
        if ((!(1 > (int32_T)varargin_1)) && ((int32_T)varargin_1 > 2147483646))
        {
          b_st.site = &gb_emlrtRSI;
          c_st.site = &gb_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (itilerow = 1; itilerow <= (int32_T)varargin_1; itilerow++) {
          b->data[(ibmat + itilerow) - 1] = a->data[outsize_idx_1];
        }
      }
    }
  }
}

/* End of code generation (repmat.cpp) */
