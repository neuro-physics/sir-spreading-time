/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * strcmp.cpp
 *
 * Code generation for function 'strcmp'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "NetworkActivationTime.h"
#include "strcmp.h"
#include "NetworkActivationTime_data.h"

/* Function Definitions */
boolean_T b_strcmp(const emlrtStack *sp, const emxArray_char_T *a)
{
  boolean_T b_bool;
  int32_T kstr;
  int32_T exitg1;
  static const char_T cv4[6] = { 'r', 'a', 'n', 'd', 'o', 'm' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &nc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &oc_emlrtRSI;
  b_bool = false;
  if (a->size[1] == 6) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 7) {
        c_st.site = &pc_emlrtRSI;
        if (!((uint8_T)a->data[kstr] <= 127)) {
          emlrtErrorWithMessageIdR2012b(&c_st, &xc_emlrtRTEI,
            "Coder:toolbox:unsupportedString", 2, 12, 127);
        }

        c_st.site = &qc_emlrtRSI;
        c_st.site = &rc_emlrtRSI;
        d_st.site = &sc_emlrtRSI;
        e_st.site = &tc_emlrtRSI;
        if (!((uint8_T)a->data[kstr] <= 127)) {
          emlrtErrorWithMessageIdR2012b(&e_st, &xc_emlrtRTEI,
            "Coder:toolbox:unsupportedString", 2, 12, 127);
        }

        c_st.site = &rc_emlrtRSI;
        d_st.site = &sc_emlrtRSI;
        e_st.site = &tc_emlrtRSI;
        if (cv1[(uint8_T)a->data[kstr] & 127] != cv1[(int32_T)cv4[kstr]]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

/* End of code generation (strcmp.cpp) */
