/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FindBestFunctionalMatch.cpp
 *
 * Code generation for function 'FindBestFunctionalMatch'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindBestFunctionalMatch.h"
#include "FindBestFunctionalMatch_emxutil.h"
#include "FunctionalConnGuess.h"
#include "any1.h"
#include "FindBestFunctionalMatch_mexutil.h"
#include "FindBestFunctionalMatch_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 19,    /* lineNo */
  "FindBestFunctionalMatch",           /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 20,  /* lineNo */
  "FindBestFunctionalMatch",           /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 23,  /* lineNo */
  "FindBestFunctionalMatch",           /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 25,  /* lineNo */
  "FindBestFunctionalMatch",           /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 27,  /* lineNo */
  "FindBestFunctionalMatch",           /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 28,  /* lineNo */
  "FindBestFunctionalMatch",           /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 30,  /* lineNo */
  "FindBestFunctionalMatch",           /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 32,  /* lineNo */
  "FindBestFunctionalMatch",           /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 61,  /* lineNo */
  "strcmp",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\strcmp.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 136, /* lineNo */
  "strcmp",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\strcmp.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 205, /* lineNo */
  "strcmp",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\strcmp.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 206, /* lineNo */
  "strcmp",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\strcmp.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 207, /* lineNo */
  "strcmp",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\strcmp.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 17,  /* lineNo */
  "lower",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\strfun\\lower.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 10,  /* lineNo */
  "eml_string_transform",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\strfun\\eml_string_transform.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 48,  /* lineNo */
  "FindBestFunctionalMatch",           /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 49,  /* lineNo */
  "FindBestFunctionalMatch",           /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 16, /* lineNo */
  "CalcHammingDist",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\CalcHammingDist.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 20, /* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 100,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 27,    /* lineNo */
  5,                                   /* colNo */
  "error",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\lang\\error.m"/* pName */
};

static emlrtMCInfo c_emlrtMCI = { 66,  /* lineNo */
  5,                                   /* colNo */
  "FindBestFunctionalMatch",           /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pName */
};

static emlrtMCInfo d_emlrtMCI = { 16,  /* lineNo */
  16,                                  /* colNo */
  "CalcHammingDist",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\CalcHammingDist.m"/* pName */
};

static emlrtRTEInfo emlrtRTEI = { 19,  /* lineNo */
  12,                                  /* colNo */
  "FindBestFunctionalMatch",           /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "FindBestFunctionalMatch",           /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "FindBestFunctionalMatch",           /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "FindBestFunctionalMatch",           /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 66,/* lineNo */
  18,                                  /* colNo */
  "FindBestFunctionalMatch",           /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 49,/* lineNo */
  40,                                  /* colNo */
  "FindBestFunctionalMatch",           /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 49,/* lineNo */
  50,                                  /* colNo */
  "FindBestFunctionalMatch",           /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 66,/* lineNo */
  23,                                  /* colNo */
  "FindBestFunctionalMatch",           /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 3, /* lineNo */
  7,                                   /* colNo */
  "CalcHammingDist",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\CalcHammingDist.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 49,/* lineNo */
  9,                                   /* colNo */
  "FindBestFunctionalMatch",           /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 4, /* lineNo */
  7,                                   /* colNo */
  "CalcHammingDist",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\CalcHammingDist.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 52,/* lineNo */
  13,                                  /* colNo */
  "FindBestFunctionalMatch",           /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 7, /* lineNo */
  9,                                   /* colNo */
  "CalcHammingDist",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\CalcHammingDist.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 8, /* lineNo */
  9,                                   /* colNo */
  "CalcHammingDist",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\CalcHammingDist.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 16,/* lineNo */
  23,                                  /* colNo */
  "CalcHammingDist",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\CalcHammingDist.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 16,/* lineNo */
  31,                                  /* colNo */
  "CalcHammingDist",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\CalcHammingDist.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 20,/* lineNo */
  5,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 48,/* lineNo */
  9,                                   /* colNo */
  "FindBestFunctionalMatch",           /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 1, /* lineNo */
  24,                                  /* colNo */
  "FindBestFunctionalMatch",           /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 16,/* lineNo */
  22,                                  /* colNo */
  "CalcHammingDist",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\CalcHammingDist.m"/* pName */
};

static emlrtRTEInfo qc_emlrtRTEI = { 14,/* lineNo */
  27,                                  /* colNo */
  "assertSupportedString",             /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\assertSupportedString.m"/* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = { 281,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  48,                                  /* colNo */
  "nSeedsRange",                       /* aName */
  "FindBestFunctionalMatch",           /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  5,                                   /* colNo */
  "A",                                 /* aName */
  "CalcHammingDist",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\CalcHammingDist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  5,                                   /* colNo */
  "B",                                 /* aName */
  "CalcHammingDist",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\CalcHammingDist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  10,                                  /* colNo */
  "R",                                 /* aName */
  "FindBestFunctionalMatch",           /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  15,                                  /* colNo */
  "P",                                 /* aName */
  "FindBestFunctionalMatch",           /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  31,                                  /* colNo */
  "R",                                 /* aName */
  "FindBestFunctionalMatch",           /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  20,                                  /* colNo */
  "R",                                 /* aName */
  "FindBestFunctionalMatch",           /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRSInfo nd_emlrtRSI = { 27, /* lineNo */
  "error",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\lang\\error.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 66, /* lineNo */
  "FindBestFunctionalMatch",           /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FindBestFunctionalMatch.m"/* pathName */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void b_error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);
static void corr(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                 emlrtMCInfo *location, const mxArray **d, const mxArray **e);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *marshall_coerceToClass, const char_T *identifier);
static const mxArray *pdist(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void b_error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "error", true, location);
}

static void corr(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                 emlrtMCInfo *location, const mxArray **d, const mxArray **e)
{
  const mxArray *pArrays[2];
  const mxArray *mv0[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtAssign(d, emlrtCallMATLABR2012b(sp, 2, &mv0[0], 2, pArrays, "corr", true,
    location));
  emlrtAssign(e, mv0[1]);
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *marshall_coerceToClass, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(marshall_coerceToClass), &thisId);
  emlrtDestroyArray(&marshall_coerceToClass);
  return y;
}

static const mxArray *pdist(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m7;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m7, 2, pArrays, "pdist", true, location);
}

void FindBestFunctionalMatch(const emlrtStack *sp, const emxArray_real_T *As,
  const emxArray_real_T *Af, real_T Theta, const emxArray_real_T *nSeedsRange,
  real_T nSim, real_T tTotal, const emxArray_char_T *comparisonMethod,
  emxArray_real_T *F, emxArray_real_T *R, emxArray_real_T *P)
{
  emxArray_boolean_T *b_nSeedsRange;
  int32_T i0;
  int32_T loop_ub;
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 1, 85 };

  static const char_T varargin_1[85] = { 't', 'h', 'e', ' ', 'm', 'o', 'd', 'e',
    'l', ' ', 'h', 'a', 's', ' ', 't', 'o', ' ', 'h', 'a', 'v', 'e', ' ', 'a',
    't', ' ', 'l', 'e', 'a', 's', 't', ' ', '2', ' ', 's', 'e', 'e', 'd', 's',
    ';', ' ', 'n', 'S', 'e', 'e', 'd', 's', 'R', 'a', 'n', 'g', 'e', ' ', 'c',
    'a', 'n', 'n', 'o', 't', ' ', 'h', 'a', 'v', 'e', ' ', 'v', 'a', 'l', 'u',
    'e', 's', ' ', 's', 'm', 'a', 'l', 'l', 'e', 'r', ' ', 't', 'h', 'a', 'n',
    ' ', '2' };

  static const int32_T iv1[2] = { 1, 29 };

  static const char_T b_varargin_1[29] = { 'T', 'h', 'e', 't', 'a', ' ', 'h',
    'a', 's', ' ', 't', 'o', ' ', 'b', 'e', ' ', 'a', ' ', 's', 'c', 'a', 'l',
    'a', 'r', ' ', '>', '=', ' ', '0' };

  boolean_T b_bool;
  int32_T kstr;
  int32_T exitg1;
  emxArray_real_T *Ftemp;
  emxArray_real_T *A;
  uint32_T uv0[2];
  const mxArray *m1 = NULL;
  static const int32_T iv2[2] = { 1, 40 };

  static const char_T c_varargin_1[40] = { 'F', 'i', 'n', 'd', 'B', 'e', 's',
    't', 'F', 'u', 'n', 'c', 't', 'i', 'o', 'n', 'a', 'l', 'M', 'a', 't', 'c',
    'h', ':', 'c', 'o', 'm', 'p', 'a', 'r', 'i', 's', 'o', 'n', 'M', 'e', 't',
    'h', 'o', 'd' };

  const mxArray *b_y;
  static const int32_T iv3[2] = { 1, 29 };

  static const char_T varargin_2[29] = { 'U', 'n', 'r', 'e', 'c', 'o', 'g', 'n',
    'i', 'z', 'e', 'd', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'i', 's', 'o', 'n',
    'M', 'e', 't', 'h', 'o', 'd' };

  static const char_T cv1[128] = { '\x00', '\x01', '\x02', '\x03', '\x04',
    '\x05', '\x06', '\x07', '\x08', '	', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
    '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
    '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
    '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?',
    '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']',
    '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{',
    '|', '}', '~', '\x7f' };

  static const char_T cv2[4] = { 'c', 'o', 'r', 'r' };

  static const char_T cv3[7] = { 'h', 'a', 'm', 'm', 'i', 'n', 'g' };

  real_T CExt;
  int32_T i;
  const mxArray *m2 = NULL;
  emxArray_real_T *B;
  emxArray_int32_T *r0;
  emxArray_int32_T *r1;
  emxArray_boolean_T *r2;
  emxArray_real_T *result;
  emxArray_real_T *d_varargin_1;
  emxArray_real_T *b_varargin_2;
  real_T *pData;
  const mxArray *r = NULL;
  const mxArray *p = NULL;
  int32_T N;
  static const int32_T iv4[2] = { 1, 7 };

  static const char_T b[7] = { 'h', 'a', 'm', 'm', 'i', 'n', 'g' };

  real_T d0;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T(sp, &b_nSeedsRange, 1, &emlrtRTEI, true);

  /*  This function maximizes (minimizes) the correlation (hamming distance) between functional connectivity estimates F_k and Af (the actual functional connectivity matrix) */
  /*  k is the amount of seeds used to seed the spreading model... it has to be greater than 2 */
  /*  */
  /*  Input: */
  /*  As -> structural connectivity matrix */
  /*  Af -> functional connectivity matrix */
  /*  Theta -> threshold of the spreading model (0 is mostly fine, but keep it smaller than the smallest FA weight in As) */
  /*  nSeedsRange -> vector with the range of number of seeds to search for the best match between F and Af */
  /*  nSim -> number of trials for each number of seed (at least 100 trials for each number of seeds; the higher the better) */
  /*  tTotal -> maximum spreading time (usually, the signal activates the whole network in less than 20 time steps...) */
  /*  comparisonMethod -> 'corr': maximizes correlation between trials F_k and Af for each number of seeds k */
  /*                      'hamming': minimizes hamming distance between trials F_k and Af for each number of seeds k */
  /*  */
  /*  Output: */
  /*  F -> best functional connectivity estimate in the number of seeds input range according to minimization or maximization of the comparison method (either Hamming distance or correlation, respectively) */
  /*  R -> correlation coefficient or hamming distance between estimates F_k and Af for each number k of seeds in the vector nSeedsRange */
  /*  P -> p-values or normalized hamming distance between estimates F_k and Af for each number k of seeds in the vector nSeedsRange */
  i0 = b_nSeedsRange->size[0];
  b_nSeedsRange->size[0] = nSeedsRange->size[1];
  emxEnsureCapacity_boolean_T(sp, b_nSeedsRange, i0, &emlrtRTEI);
  loop_ub = nSeedsRange->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_nSeedsRange->data[i0] = (nSeedsRange->data[i0] < 2.0);
  }

  st.site = &emlrtRSI;
  if (any(&st, b_nSeedsRange)) {
    st.site = &b_emlrtRSI;
    y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    emlrtInitCharArrayR2013a(&st, 85, m0, &varargin_1[0]);
    emlrtAssign(&y, m0);
    b_st.site = &nd_emlrtRSI;
    error(&b_st, y, (emlrtMCInfo *)&emlrtMCI);
  }

  emxFree_boolean_T(&b_nSeedsRange);
  if (Theta < 0.0) {
    st.site = &c_emlrtRSI;
    y = NULL;
    m0 = emlrtCreateCharArray(2, iv1);
    emlrtInitCharArrayR2013a(&st, 29, m0, &b_varargin_1[0]);
    emlrtAssign(&y, m0);
    b_st.site = &nd_emlrtRSI;
    error(&b_st, y, (emlrtMCInfo *)&emlrtMCI);
  }

  st.site = &d_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  b_bool = false;
  if (comparisonMethod->size[1] == 4) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 5) {
        d_st.site = &n_emlrtRSI;
        if (!((uint8_T)comparisonMethod->data[kstr] <= 127)) {
          emlrtErrorWithMessageIdR2012b(&d_st, &qc_emlrtRTEI,
            "Coder:toolbox:unsupportedString", 2, 12, 127);
        }

        d_st.site = &o_emlrtRSI;
        d_st.site = &p_emlrtRSI;
        e_st.site = &q_emlrtRSI;
        f_st.site = &r_emlrtRSI;
        if (!((uint8_T)comparisonMethod->data[kstr] <= 127)) {
          emlrtErrorWithMessageIdR2012b(&f_st, &qc_emlrtRTEI,
            "Coder:toolbox:unsupportedString", 2, 12, 127);
        }

        d_st.site = &p_emlrtRSI;
        e_st.site = &q_emlrtRSI;
        f_st.site = &r_emlrtRSI;
        if (cv1[(uint8_T)comparisonMethod->data[kstr] & 127] != cv1[(int32_T)
            cv2[kstr]]) {
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

  emxInit_real_T(sp, &Ftemp, 2, &r_emlrtRTEI, true);
  emxInit_real_T1(sp, &A, 1, &f_emlrtRTEI, true);
  if (b_bool) {
    /*          [ F, R, P ] = FindBestFunctionalMatch_internal(As, Af, Theta, nSeedsRange, nSim, tTotal, @GreaterThan, @CalcCorrCoeff); */
    st.site = &e_emlrtRSI;
    for (i0 = 0; i0 < 2; i0++) {
      uv0[i0] = (uint32_T)As->size[i0];
    }

    i0 = F->size[0] * F->size[1];
    F->size[0] = (int32_T)uv0[0];
    F->size[1] = (int32_T)uv0[1];
    emxEnsureCapacity_real_T(&st, F, i0, &b_emlrtRTEI);
    loop_ub = (int32_T)uv0[0] * (int32_T)uv0[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      F->data[i0] = 0.0;
    }

    for (i0 = 0; i0 < 2; i0++) {
      uv0[i0] = (uint32_T)nSeedsRange->size[i0];
    }

    i0 = R->size[0] * R->size[1];
    R->size[0] = 1;
    R->size[1] = (int32_T)uv0[1];
    emxEnsureCapacity_real_T(&st, R, i0, &c_emlrtRTEI);
    loop_ub = (int32_T)uv0[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      R->data[i0] = 0.0;
    }

    for (i0 = 0; i0 < 2; i0++) {
      uv0[i0] = (uint32_T)nSeedsRange->size[i0];
    }

    i0 = P->size[0] * P->size[1];
    P->size[0] = 1;
    P->size[1] = (int32_T)uv0[1];
    emxEnsureCapacity_real_T(&st, P, i0, &d_emlrtRTEI);
    loop_ub = (int32_T)uv0[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      P->data[i0] = 0.0;
    }

    /*  condition is seeking for a > b */
    CExt = rtMinusInf;

    /* Ftemp = mycell(numOfTestSeeds); */
    i = 1;
    while (i - 1 <= nSeedsRange->size[1] - 1) {
      i0 = nSeedsRange->size[1];
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&emlrtBCI, &st);
      }

      b_st.site = &s_emlrtRSI;
      FunctionalConnGuess(&b_st, As, Theta, nSeedsRange->data[i - 1], nSim,
                          tTotal, Ftemp);
      b_st.site = &t_emlrtRSI;
      m2 = NULL;
      m1 = NULL;
      i0 = A->size[0];
      A->size[0] = Ftemp->size[0] * Ftemp->size[1];
      emxEnsureCapacity_real_T1(&b_st, A, i0, &e_emlrtRTEI);
      loop_ub = Ftemp->size[0] * Ftemp->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        A->data[i0] = Ftemp->data[i0];
      }

      y = NULL;
      m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])A->size, mxDOUBLE_CLASS,
        mxREAL);
      pData = (real_T *)emlrtMxGetPr(m0);
      i0 = 0;
      for (loop_ub = 0; loop_ub < Ftemp->size[0] * Ftemp->size[1]; loop_ub++) {
        pData[i0] = Ftemp->data[loop_ub];
        i0++;
      }

      emlrtAssign(&y, m0);
      i0 = A->size[0];
      A->size[0] = Af->size[0] * Af->size[1];
      emxEnsureCapacity_real_T1(&b_st, A, i0, &h_emlrtRTEI);
      loop_ub = Af->size[0] * Af->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        A->data[i0] = Af->data[i0];
      }

      b_y = NULL;
      m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])A->size, mxDOUBLE_CLASS,
        mxREAL);
      pData = (real_T *)emlrtMxGetPr(m0);
      i0 = 0;
      for (loop_ub = 0; loop_ub < Af->size[0] * Af->size[1]; loop_ub++) {
        pData[i0] = Af->data[loop_ub];
        i0++;
      }

      emlrtAssign(&b_y, m0);
      c_st.site = &od_emlrtRSI;
      corr(&c_st, y, b_y, (emlrtMCInfo *)&c_emlrtMCI, &r, &p);
      emlrtAssign(&m1, emlrtAlias(r));
      emlrtAssign(&m2, emlrtAlias(p));

      /*  function r = GreaterThan(a,b) */
      /*      r = a > b; */
      /*  end */
      /*   */
      /*  function r = LessThan(a,b) */
      /*      r = a < b; */
      /*  end */
      emlrtDestroyArray(&r);
      emlrtDestroyArray(&p);
      i0 = R->size[1];
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&d_emlrtBCI, &st);
      }

      b_st.site = &t_emlrtRSI;
      R->data[i - 1] = emlrt_marshallIn(&b_st, emlrtCoerceToClassR2014b
        (emlrtAlias(m1), "double"), "marshall.coerceToClass");
      i0 = P->size[1];
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&e_emlrtBCI, &st);
      }

      b_st.site = &t_emlrtRSI;
      P->data[i - 1] = emlrt_marshallIn(&b_st, emlrtCoerceToClassR2014b
        (emlrtAlias(m2), "double"), "marshall.coerceToClass");
      i0 = R->size[1];
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&f_emlrtBCI, &st);
      }

      if (R->data[i - 1] > CExt) {
        i0 = R->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&g_emlrtBCI,
            &st);
        }

        CExt = R->data[i - 1];
        i0 = F->size[0] * F->size[1];
        F->size[0] = Ftemp->size[0];
        F->size[1] = Ftemp->size[1];
        emxEnsureCapacity_real_T(&st, F, i0, &l_emlrtRTEI);
        loop_ub = Ftemp->size[0] * Ftemp->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          F->data[i0] = Ftemp->data[i0];
        }
      }

      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emlrtDestroyArray(&m1);
    emlrtDestroyArray(&m2);
  } else {
    st.site = &f_emlrtRSI;
    b_st.site = &l_emlrtRSI;
    c_st.site = &m_emlrtRSI;
    b_bool = false;
    if (comparisonMethod->size[1] == 7) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr + 1 < 8) {
          d_st.site = &n_emlrtRSI;
          if (!((uint8_T)comparisonMethod->data[kstr] <= 127)) {
            emlrtErrorWithMessageIdR2012b(&d_st, &qc_emlrtRTEI,
              "Coder:toolbox:unsupportedString", 2, 12, 127);
          }

          d_st.site = &o_emlrtRSI;
          d_st.site = &p_emlrtRSI;
          e_st.site = &q_emlrtRSI;
          f_st.site = &r_emlrtRSI;
          if (!((uint8_T)comparisonMethod->data[kstr] <= 127)) {
            emlrtErrorWithMessageIdR2012b(&f_st, &qc_emlrtRTEI,
              "Coder:toolbox:unsupportedString", 2, 12, 127);
          }

          d_st.site = &p_emlrtRSI;
          e_st.site = &q_emlrtRSI;
          f_st.site = &r_emlrtRSI;
          if (cv1[(uint8_T)comparisonMethod->data[kstr] & 127] != cv1[(int32_T)
              cv3[kstr]]) {
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

    if (b_bool) {
      /*          [ F, R, P ] = FindBestFunctionalMatch_internal(As, Af, Theta, nSeedsRange, nSim, tTotal, @LessThan, @CalcHammingDist); */
      st.site = &g_emlrtRSI;
      for (i0 = 0; i0 < 2; i0++) {
        uv0[i0] = (uint32_T)As->size[i0];
      }

      i0 = F->size[0] * F->size[1];
      F->size[0] = (int32_T)uv0[0];
      F->size[1] = (int32_T)uv0[1];
      emxEnsureCapacity_real_T(&st, F, i0, &b_emlrtRTEI);
      loop_ub = (int32_T)uv0[0] * (int32_T)uv0[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        F->data[i0] = 0.0;
      }

      for (i0 = 0; i0 < 2; i0++) {
        uv0[i0] = (uint32_T)nSeedsRange->size[i0];
      }

      i0 = R->size[0] * R->size[1];
      R->size[0] = 1;
      R->size[1] = (int32_T)uv0[1];
      emxEnsureCapacity_real_T(&st, R, i0, &c_emlrtRTEI);
      loop_ub = (int32_T)uv0[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        R->data[i0] = 0.0;
      }

      for (i0 = 0; i0 < 2; i0++) {
        uv0[i0] = (uint32_T)nSeedsRange->size[i0];
      }

      i0 = P->size[0] * P->size[1];
      P->size[0] = 1;
      P->size[1] = (int32_T)uv0[1];
      emxEnsureCapacity_real_T(&st, P, i0, &d_emlrtRTEI);
      loop_ub = (int32_T)uv0[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        P->data[i0] = 0.0;
      }

      /*  condition is seeking for a < b */
      CExt = rtInf;

      /* Ftemp = mycell(numOfTestSeeds); */
      i = 1;
      emxInit_real_T1(&st, &B, 1, &g_emlrtRTEI, true);
      emxInit_int32_T(&st, &r0, 1, &s_emlrtRTEI, true);
      emxInit_int32_T(&st, &r1, 1, &s_emlrtRTEI, true);
      emxInit_boolean_T(&st, &r2, 1, &s_emlrtRTEI, true);
      emxInit_real_T(&st, &result, 2, &t_emlrtRTEI, true);
      emxInit_real_T(&st, &d_varargin_1, 2, &o_emlrtRTEI, true);
      emxInit_real_T(&st, &b_varargin_2, 2, &p_emlrtRTEI, true);
      while (i - 1 <= nSeedsRange->size[1] - 1) {
        i0 = nSeedsRange->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&emlrtBCI, &st);
        }

        b_st.site = &s_emlrtRSI;
        FunctionalConnGuess(&b_st, As, Theta, nSeedsRange->data[i - 1], nSim,
                            tTotal, Ftemp);
        b_st.site = &t_emlrtRSI;
        i0 = A->size[0];
        A->size[0] = Ftemp->size[0] * Ftemp->size[1];
        emxEnsureCapacity_real_T1(&b_st, A, i0, &f_emlrtRTEI);
        loop_ub = Ftemp->size[0] * Ftemp->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          A->data[i0] = Ftemp->data[i0];
        }

        i0 = B->size[0];
        B->size[0] = Af->size[0] * Af->size[1];
        emxEnsureCapacity_real_T1(&b_st, B, i0, &g_emlrtRTEI);
        loop_ub = Af->size[0] * Af->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          B->data[i0] = Af->data[i0];
        }

        i0 = r2->size[0];
        r2->size[0] = Ftemp->size[0] * Ftemp->size[1];
        emxEnsureCapacity_boolean_T(&b_st, r2, i0, &i_emlrtRTEI);
        loop_ub = Ftemp->size[0] * Ftemp->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          r2->data[i0] = muDoubleScalarIsNaN(Ftemp->data[i0]);
        }

        N = r2->size[0] - 1;
        kstr = 0;
        for (loop_ub = 0; loop_ub <= N; loop_ub++) {
          if (r2->data[loop_ub]) {
            kstr++;
          }
        }

        i0 = r0->size[0];
        r0->size[0] = kstr;
        emxEnsureCapacity_int32_T(&b_st, r0, i0, &j_emlrtRTEI);
        kstr = 0;
        for (loop_ub = 0; loop_ub <= N; loop_ub++) {
          if (r2->data[loop_ub]) {
            r0->data[kstr] = loop_ub + 1;
            kstr++;
          }
        }

        kstr = Ftemp->size[0] * Ftemp->size[1];
        loop_ub = r0->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          N = r0->data[i0];
          if (!((N >= 1) && (N <= kstr))) {
            emlrtDynamicBoundsCheckR2012b(N, 1, kstr, (emlrtBCInfo *)&b_emlrtBCI,
              &b_st);
          }

          A->data[N - 1] = rtInf;
        }

        i0 = r2->size[0];
        r2->size[0] = Af->size[0] * Af->size[1];
        emxEnsureCapacity_boolean_T(&b_st, r2, i0, &k_emlrtRTEI);
        loop_ub = Af->size[0] * Af->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          r2->data[i0] = muDoubleScalarIsNaN(Af->data[i0]);
        }

        N = r2->size[0] - 1;
        kstr = 0;
        for (loop_ub = 0; loop_ub <= N; loop_ub++) {
          if (r2->data[loop_ub]) {
            kstr++;
          }
        }

        i0 = r1->size[0];
        r1->size[0] = kstr;
        emxEnsureCapacity_int32_T(&b_st, r1, i0, &j_emlrtRTEI);
        kstr = 0;
        for (loop_ub = 0; loop_ub <= N; loop_ub++) {
          if (r2->data[loop_ub]) {
            r1->data[kstr] = loop_ub + 1;
            kstr++;
          }
        }

        kstr = Af->size[0] * Af->size[1];
        loop_ub = r1->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          N = r1->data[i0];
          if (!((N >= 1) && (N <= kstr))) {
            emlrtDynamicBoundsCheckR2012b(N, 1, kstr, (emlrtBCInfo *)&c_emlrtBCI,
              &b_st);
          }

          B->data[N - 1] = rtMinusInf;
        }

        N = A->size[0];
        kstr = A->size[0];
        i0 = A->size[0];
        A->size[0] = kstr;
        emxEnsureCapacity_real_T1(&b_st, A, i0, &m_emlrtRTEI);
        kstr = B->size[0];
        i0 = B->size[0];
        B->size[0] = kstr;
        emxEnsureCapacity_real_T1(&b_st, B, i0, &n_emlrtRTEI);
        c_st.site = &jd_emlrtRSI;
        loop_ub = A->size[0];
        i0 = d_varargin_1->size[0] * d_varargin_1->size[1];
        d_varargin_1->size[0] = 1;
        d_varargin_1->size[1] = loop_ub;
        emxEnsureCapacity_real_T(&c_st, d_varargin_1, i0, &o_emlrtRTEI);
        for (i0 = 0; i0 < loop_ub; i0++) {
          d_varargin_1->data[d_varargin_1->size[0] * i0] = A->data[i0];
        }

        loop_ub = B->size[0];
        i0 = b_varargin_2->size[0] * b_varargin_2->size[1];
        b_varargin_2->size[0] = 1;
        b_varargin_2->size[1] = loop_ub;
        emxEnsureCapacity_real_T(&c_st, b_varargin_2, i0, &p_emlrtRTEI);
        for (i0 = 0; i0 < loop_ub; i0++) {
          b_varargin_2->data[b_varargin_2->size[0] * i0] = B->data[i0];
        }

        d_st.site = &kd_emlrtRSI;
        e_st.site = &ld_emlrtRSI;
        b_bool = true;
        if (b_varargin_2->size[1] != d_varargin_1->size[1]) {
          b_bool = false;
        }

        if (!b_bool) {
          emlrtErrorWithMessageIdR2012b(&e_st, &rc_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        i0 = result->size[0] * result->size[1];
        result->size[0] = 2;
        result->size[1] = d_varargin_1->size[1];
        emxEnsureCapacity_real_T(&d_st, result, i0, &q_emlrtRTEI);
        loop_ub = d_varargin_1->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          result->data[result->size[0] * i0] = d_varargin_1->data
            [d_varargin_1->size[0] * i0];
        }

        loop_ub = b_varargin_2->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          result->data[1 + result->size[0] * i0] = b_varargin_2->
            data[b_varargin_2->size[0] * i0];
        }

        y = NULL;
        m1 = emlrtCreateNumericArray(2, *(int32_T (*)[1])result->size,
          mxDOUBLE_CLASS, mxREAL);
        pData = (real_T *)emlrtMxGetPr(m1);
        i0 = 0;
        for (loop_ub = 0; loop_ub < result->size[1]; loop_ub++) {
          for (kstr = 0; kstr < 2; kstr++) {
            pData[i0] = result->data[kstr + result->size[0] * loop_ub];
            i0++;
          }
        }

        emlrtAssign(&y, m1);
        b_y = NULL;
        m1 = emlrtCreateCharArray(2, iv4);
        emlrtInitCharArrayR2013a(&b_st, 7, m1, &b[0]);
        emlrtAssign(&b_y, m1);
        c_st.site = &jd_emlrtRSI;
        d0 = emlrt_marshallIn(&c_st, emlrtCoerceToClassR2014b(pdist(&c_st, y,
          b_y, (emlrtMCInfo *)&d_emlrtMCI), "double"), "pdist");
        i0 = R->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&d_emlrtBCI,
            &st);
        }

        R->data[i - 1] = d0 * (real_T)N;
        i0 = P->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&e_emlrtBCI,
            &st);
        }

        P->data[i - 1] = d0;
        i0 = R->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&f_emlrtBCI,
            &st);
        }

        if (R->data[i - 1] < CExt) {
          i0 = R->size[1];
          if (!((i >= 1) && (i <= i0))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&g_emlrtBCI,
              &st);
          }

          CExt = R->data[i - 1];
          i0 = F->size[0] * F->size[1];
          F->size[0] = Ftemp->size[0];
          F->size[1] = Ftemp->size[1];
          emxEnsureCapacity_real_T(&st, F, i0, &l_emlrtRTEI);
          loop_ub = Ftemp->size[0] * Ftemp->size[1];
          for (i0 = 0; i0 < loop_ub; i0++) {
            F->data[i0] = Ftemp->data[i0];
          }
        }

        i++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      emxFree_real_T(&b_varargin_2);
      emxFree_real_T(&d_varargin_1);
      emxFree_real_T(&result);
      emxFree_boolean_T(&r2);
      emxFree_int32_T(&r1);
      emxFree_int32_T(&r0);
      emxFree_real_T(&B);
    } else {
      st.site = &h_emlrtRSI;
      y = NULL;
      m1 = emlrtCreateCharArray(2, iv2);
      emlrtInitCharArrayR2013a(&st, 40, m1, &c_varargin_1[0]);
      emlrtAssign(&y, m1);
      b_y = NULL;
      m1 = emlrtCreateCharArray(2, iv3);
      emlrtInitCharArrayR2013a(&st, 29, m1, &varargin_2[0]);
      emlrtAssign(&b_y, m1);
      b_st.site = &nd_emlrtRSI;
      b_error(&b_st, y, b_y, (emlrtMCInfo *)&emlrtMCI);
    }
  }

  emxFree_real_T(&A);
  emxFree_real_T(&Ftemp);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (FindBestFunctionalMatch.cpp) */
