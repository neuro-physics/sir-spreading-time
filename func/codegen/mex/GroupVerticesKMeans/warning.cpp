/*
 * warning.cpp
 *
 * Code generation for function 'warning'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "GroupVerticesKMeans.h"
#include "warning.h"

/* Variable Definitions */
static emlrtMCInfo b_emlrtMCI = { 14, 25, "warning",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

static emlrtMCInfo c_emlrtMCI = { 14, 9, "warning",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

static emlrtRSInfo cd_emlrtRSI = { 14, "warning",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

/* Function Declarations */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);
static const mxArray *c_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);

/* Function Definitions */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "feval", true, location);
}

static const mxArray *c_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m7;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m7, 3, pArrays, "feval", true, location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m6;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m6, 2, pArrays, "feval", true, location);
}

void b_warning(const emlrtStack *sp)
{
  int32_T i8;
  const mxArray *y;
  char_T u[7];
  static const char_T cv3[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *m3;
  static const int32_T iv6[2] = { 1, 7 };

  const mxArray *b_y;
  char_T b_u[7];
  static const char_T cv4[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  static const int32_T iv7[2] = { 1, 7 };

  const mxArray *c_y;
  char_T c_u[29];
  static const char_T msgID[29] = { 's', 't', 'a', 't', 's', ':', 'k', 'm', 'e',
    'a', 'n', 's', ':', 'F', 'a', 'i', 'l', 'e', 'd', 'T', 'o', 'C', 'o', 'n',
    'v', 'e', 'r', 'g', 'e' };

  static const int32_T iv8[2] = { 1, 29 };

  const mxArray *d_y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i8 = 0; i8 < 7; i8++) {
    u[i8] = cv3[i8];
  }

  y = NULL;
  m3 = emlrtCreateCharArray(2, iv6);
  emlrtInitCharArrayR2013a(sp, 7, m3, &u[0]);
  emlrtAssign(&y, m3);
  for (i8 = 0; i8 < 7; i8++) {
    b_u[i8] = cv4[i8];
  }

  b_y = NULL;
  m3 = emlrtCreateCharArray(2, iv7);
  emlrtInitCharArrayR2013a(sp, 7, m3, &b_u[0]);
  emlrtAssign(&b_y, m3);
  for (i8 = 0; i8 < 29; i8++) {
    c_u[i8] = msgID[i8];
  }

  c_y = NULL;
  m3 = emlrtCreateCharArray(2, iv8);
  emlrtInitCharArrayR2013a(sp, 29, m3, &c_u[0]);
  emlrtAssign(&c_y, m3);
  d_y = NULL;
  m3 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)mxGetData(m3) = 1000;
  emlrtAssign(&d_y, m3);
  st.site = &cd_emlrtRSI;
  b_feval(&st, y, c_feval(&st, b_y, c_y, d_y, (emlrtMCInfo *)&b_emlrtMCI),
          (emlrtMCInfo *)&c_emlrtMCI);
}

void warning(const emlrtStack *sp)
{
  int32_T i6;
  const mxArray *y;
  char_T u[7];
  static const char_T cv0[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *m1;
  static const int32_T iv2[2] = { 1, 7 };

  const mxArray *b_y;
  char_T b_u[7];
  static const char_T cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  static const int32_T iv3[2] = { 1, 7 };

  const mxArray *c_y;
  char_T c_u[31];
  static const char_T msgID[31] = { 's', 't', 'a', 't', 's', ':', 'k', 'm', 'e',
    'a', 'n', 's', ':', 'M', 'i', 's', 's', 'i', 'n', 'g', 'D', 'a', 't', 'a',
    'R', 'e', 'm', 'o', 'v', 'e', 'd' };

  static const int32_T iv4[2] = { 1, 31 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i6 = 0; i6 < 7; i6++) {
    u[i6] = cv0[i6];
  }

  y = NULL;
  m1 = emlrtCreateCharArray(2, iv2);
  emlrtInitCharArrayR2013a(sp, 7, m1, &u[0]);
  emlrtAssign(&y, m1);
  for (i6 = 0; i6 < 7; i6++) {
    b_u[i6] = cv1[i6];
  }

  b_y = NULL;
  m1 = emlrtCreateCharArray(2, iv3);
  emlrtInitCharArrayR2013a(sp, 7, m1, &b_u[0]);
  emlrtAssign(&b_y, m1);
  for (i6 = 0; i6 < 31; i6++) {
    c_u[i6] = msgID[i6];
  }

  c_y = NULL;
  m1 = emlrtCreateCharArray(2, iv4);
  emlrtInitCharArrayR2013a(sp, 31, m1, &c_u[0]);
  emlrtAssign(&c_y, m1);
  st.site = &cd_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, (emlrtMCInfo *)&b_emlrtMCI), (emlrtMCInfo
           *)&c_emlrtMCI);
}

/* End of code generation (warning.cpp) */
