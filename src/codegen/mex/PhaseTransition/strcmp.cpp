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
#include "PhaseTransition.h"
#include "strcmp.h"

/* Variable Definitions */
static emlrtRSInfo o_emlrtRSI = { 61,  /* lineNo */
  "strcmp",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\strcmp.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 136, /* lineNo */
  "strcmp",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\strcmp.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 205, /* lineNo */
  "strcmp",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\strcmp.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 206, /* lineNo */
  "strcmp",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\strcmp.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 207, /* lineNo */
  "strcmp",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\strcmp.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 17,  /* lineNo */
  "lower",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\strfun\\lower.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 10,  /* lineNo */
  "eml_string_transform",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\strfun\\eml_string_transform.m"/* pathName */
};

static emlrtRTEInfo gc_emlrtRTEI = { 14,/* lineNo */
  27,                                  /* colNo */
  "assertSupportedString",             /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\assertSupportedString.m"/* pName */
};

static const char_T cv1[128] = { '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
  '\x06', '\x07', '\x08', '	', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f',
  '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19',
  '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#', '$', '%',
  '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4',
  '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a', 'b', 'c', 'd',
  'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
  'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c',
  'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
  't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', '\x7f' };

/* Function Definitions */
boolean_T b_strcmp(const emlrtStack *sp, const emxArray_char_T *a)
{
  boolean_T b_bool;
  int32_T kstr;
  int32_T exitg1;
  static const char_T cv2[5] = { 'f', 'i', 'x', 'e', 'd' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &o_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &p_emlrtRSI;
  b_bool = false;
  if (a->size[1] == 5) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 6) {
        c_st.site = &q_emlrtRSI;
        if (!((uint8_T)a->data[kstr] <= 127)) {
          emlrtErrorWithMessageIdR2012b(&c_st, &gc_emlrtRTEI,
            "Coder:toolbox:unsupportedString", 2, 12, 127);
        }

        c_st.site = &r_emlrtRSI;
        c_st.site = &s_emlrtRSI;
        d_st.site = &t_emlrtRSI;
        e_st.site = &u_emlrtRSI;
        if (!((uint8_T)a->data[kstr] <= 127)) {
          emlrtErrorWithMessageIdR2012b(&e_st, &gc_emlrtRTEI,
            "Coder:toolbox:unsupportedString", 2, 12, 127);
        }

        c_st.site = &s_emlrtRSI;
        d_st.site = &t_emlrtRSI;
        e_st.site = &u_emlrtRSI;
        if (cv1[(uint8_T)a->data[kstr] & 127] != cv1[(int32_T)cv2[kstr]]) {
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

boolean_T c_strcmp(const emlrtStack *sp, const emxArray_char_T *a)
{
  boolean_T b_bool;
  int32_T kstr;
  int32_T exitg1;
  static const char_T cv3[8] = { 'm', 'o', 's', 't', 'c', 'o', 'n', 'n' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &o_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &p_emlrtRSI;
  b_bool = false;
  if (a->size[1] == 8) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 9) {
        c_st.site = &q_emlrtRSI;
        if (!((uint8_T)a->data[kstr] <= 127)) {
          emlrtErrorWithMessageIdR2012b(&c_st, &gc_emlrtRTEI,
            "Coder:toolbox:unsupportedString", 2, 12, 127);
        }

        c_st.site = &r_emlrtRSI;
        c_st.site = &s_emlrtRSI;
        d_st.site = &t_emlrtRSI;
        e_st.site = &u_emlrtRSI;
        if (!((uint8_T)a->data[kstr] <= 127)) {
          emlrtErrorWithMessageIdR2012b(&e_st, &gc_emlrtRTEI,
            "Coder:toolbox:unsupportedString", 2, 12, 127);
        }

        c_st.site = &s_emlrtRSI;
        d_st.site = &t_emlrtRSI;
        e_st.site = &u_emlrtRSI;
        if (cv1[(uint8_T)a->data[kstr] & 127] != cv1[(int32_T)cv3[kstr]]) {
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

boolean_T d_strcmp(const emlrtStack *sp, const emxArray_char_T *a)
{
  boolean_T b_bool;
  int32_T kstr;
  int32_T exitg1;
  static const char_T cv4[8] = { 'a', 'l', 'l', 'n', 'o', 'd', 'e', 's' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &o_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &p_emlrtRSI;
  b_bool = false;
  if (a->size[1] == 8) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 9) {
        c_st.site = &q_emlrtRSI;
        if (!((uint8_T)a->data[kstr] <= 127)) {
          emlrtErrorWithMessageIdR2012b(&c_st, &gc_emlrtRTEI,
            "Coder:toolbox:unsupportedString", 2, 12, 127);
        }

        c_st.site = &r_emlrtRSI;
        c_st.site = &s_emlrtRSI;
        d_st.site = &t_emlrtRSI;
        e_st.site = &u_emlrtRSI;
        if (!((uint8_T)a->data[kstr] <= 127)) {
          emlrtErrorWithMessageIdR2012b(&e_st, &gc_emlrtRTEI,
            "Coder:toolbox:unsupportedString", 2, 12, 127);
        }

        c_st.site = &s_emlrtRSI;
        d_st.site = &t_emlrtRSI;
        e_st.site = &u_emlrtRSI;
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

boolean_T e_strcmp(const emlrtStack *sp, const emxArray_char_T *a)
{
  boolean_T b_bool;
  int32_T kstr;
  int32_T exitg1;
  static const char_T cv5[6] = { 'r', 'a', 'n', 'd', 'o', 'm' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &o_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &p_emlrtRSI;
  b_bool = false;
  if (a->size[1] == 6) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 7) {
        c_st.site = &q_emlrtRSI;
        if (!((uint8_T)a->data[kstr] <= 127)) {
          emlrtErrorWithMessageIdR2012b(&c_st, &gc_emlrtRTEI,
            "Coder:toolbox:unsupportedString", 2, 12, 127);
        }

        c_st.site = &r_emlrtRSI;
        c_st.site = &s_emlrtRSI;
        d_st.site = &t_emlrtRSI;
        e_st.site = &u_emlrtRSI;
        if (!((uint8_T)a->data[kstr] <= 127)) {
          emlrtErrorWithMessageIdR2012b(&e_st, &gc_emlrtRTEI,
            "Coder:toolbox:unsupportedString", 2, 12, 127);
        }

        c_st.site = &s_emlrtRSI;
        d_st.site = &t_emlrtRSI;
        e_st.site = &u_emlrtRSI;
        if (cv1[(uint8_T)a->data[kstr] & 127] != cv1[(int32_T)cv5[kstr]]) {
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
