/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * PhaseTransition_data.cpp
 *
 * Code generation for function 'PhaseTransition_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "PhaseTransition.h"
#include "PhaseTransition_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131451U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "PhaseTransition",                   /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2433290357U, 2237796540U, 4066813863U, 833189415U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo cb_emlrtRSI = { 11,        /* lineNo */
  "repeatToComplete",                  /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pathName */
};

emlrtRSInfo db_emlrtRSI = { 18,        /* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

emlrtRSInfo fb_emlrtRSI = { 114,       /* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

emlrtRSInfo gb_emlrtRSI = { 21,        /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRSInfo hb_emlrtRSI = { 44,        /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

emlrtRSInfo ib_emlrtRSI = { 234,       /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

emlrtRSInfo jb_emlrtRSI = { 253,       /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

emlrtRSInfo lb_emlrtRSI = { 26,        /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pathName */
};

emlrtRSInfo kc_emlrtRSI = { 443,       /* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

emlrtRSInfo rc_emlrtRSI = { 9,         /* lineNo */
  "sum",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pathName */
};

emlrtRSInfo sc_emlrtRSI = { 58,        /* lineNo */
  "sumprod",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

emlrtRSInfo tc_emlrtRSI = { 106,       /* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

emlrtRSInfo uc_emlrtRSI = { 166,       /* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

emlrtMCInfo c_emlrtMCI = { 37,         /* lineNo */
  5,                                   /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

emlrtRTEInfo o_emlrtRTEI = { 44,       /* lineNo */
  10,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

emlrtRTEInfo p_emlrtRTEI = { 44,       /* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

emlrtRTEInfo r_emlrtRTEI = { 26,       /* lineNo */
  6,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pName */
};

emlrtRTEInfo w_emlrtRTEI = { 36,       /* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

emlrtDCInfo emlrtDCI = { 21,           /* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m",/* pName */
  4                                    /* checkKind */
};

emlrtECInfo emlrtECI = { -1,           /* nDims */
  12,                                  /* lineNo */
  5,                                   /* colNo */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m"/* pName */
};

emlrtBCInfo bc_emlrtBCI = { -1,        /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  15,                                  /* colNo */
  "y",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

emlrtBCInfo cc_emlrtBCI = { -1,        /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  8,                                   /* colNo */
  "y",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

emlrtBCInfo dc_emlrtBCI = { -1,        /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  10,                                  /* colNo */
  "y",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

emlrtBCInfo ec_emlrtBCI = { -1,        /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  7,                                   /* colNo */
  "y",                                 /* aName */
  "repeatToComplete",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\repeatToComplete.m",/* pName */
  0                                    /* checkKind */
};

emlrtRTEInfo hc_emlrtRTEI = { 243,     /* lineNo */
  9,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

emlrtRTEInfo ic_emlrtRTEI = { 20,      /* lineNo */
  15,                                  /* colNo */
  "sumprod",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pName */
};

emlrtRTEInfo jc_emlrtRTEI = { 59,      /* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

emlrtRTEInfo kc_emlrtRTEI = { 53,      /* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

emlrtRTEInfo mc_emlrtRTEI = { 88,      /* lineNo */
  9,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

const char_T cv0[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a', 'x',
  's', 'i', 'z', 'e' };

emlrtRSInfo wd_emlrtRSI = { 37,        /* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

/* End of code generation (PhaseTransition_data.cpp) */
