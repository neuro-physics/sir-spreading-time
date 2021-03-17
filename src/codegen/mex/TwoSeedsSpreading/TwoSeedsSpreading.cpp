/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * TwoSeedsSpreading.cpp
 *
 * Code generation for function 'TwoSeedsSpreading'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "TwoSeedsSpreading.h"
#include "TwoSeedsSpreading_emxutil.h"
#include "rdivide.h"
#include "error.h"
#include "eml_int_forloop_overflow_check.h"
#include "EvolveSINetwork.h"
#include "GetNodes.h"
#include "GetSimulationParam.h"
#include "nullAssignment.h"
#include "meshgrid.h"
#include "TwoSeedsSpreading_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 36,    /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 37,  /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 38,  /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 40,  /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 41,  /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 54,  /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 55,  /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 57,  /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 58,  /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 59,  /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 60,  /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 61,  /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 73,  /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 74,  /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 75,  /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 76,  /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 77,  /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 78,  /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 20, /* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 100,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo ce_emlrtRSI = { 13, /* lineNo */
  "max",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRSInfo de_emlrtRSI = { 19, /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo ee_emlrtRSI = { 140,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo fe_emlrtRSI = { 376,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo ge_emlrtRSI = { 348,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo he_emlrtRSI = { 165,/* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo ie_emlrtRSI = { 147,/* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo je_emlrtRSI = { 159,/* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRSInfo ke_emlrtRSI = { 13, /* lineNo */
  "log",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elfun\\log.m"/* pathName */
};

static emlrtRSInfo le_emlrtRSI = { 88, /* lineNo */
  "TwoSeedsSpreading",                 /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 36,  /* lineNo */
  24,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 36,/* lineNo */
  28,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 38,/* lineNo */
  13,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 48,/* lineNo */
  5,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 49,/* lineNo */
  5,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 43,/* lineNo */
  10,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 55,/* lineNo */
  21,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 79,/* lineNo */
  9,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 80,/* lineNo */
  10,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 56,/* lineNo */
  9,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 59,/* lineNo */
  19,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 59,/* lineNo */
  9,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 60,/* lineNo */
  17,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 60,/* lineNo */
  9,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 61,/* lineNo */
  15,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 61,/* lineNo */
  20,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 62,/* lineNo */
  15,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 62,/* lineNo */
  20,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 63,/* lineNo */
  15,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 1, /* lineNo */
  37,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 41,/* lineNo */
  5,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 43,/* lineNo */
  5,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 45,/* lineNo */
  5,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 46,/* lineNo */
  5,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 47,/* lineNo */
  5,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 54,/* lineNo */
  10,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = { 164,/* lineNo */
  14,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = { 111,/* lineNo */
  5,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = { 98,/* lineNo */
  5,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  28,                                  /* colNo */
  "spTemp",                            /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  16,                                  /* colNo */
  "xx",                                /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 57,    /* lineNo */
  45,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  45,                                  /* colNo */
  "x",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 58,  /* lineNo */
  45,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  45,                                  /* colNo */
  "x",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  59,                                  /* lineNo */
  14,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  60,                                  /* lineNo */
  13,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  27,                                  /* colNo */
  "spTemp",                            /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  13,                                  /* colNo */
  "SSn",                               /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  62,                                  /* lineNo */
  9,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  13,                                  /* colNo */
  "SSn",                               /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  19,                                  /* colNo */
  "SSn",                               /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  13,                                  /* colNo */
  "TTn",                               /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  61,                                  /* lineNo */
  9,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m"/* pName */
};

static emlrtRTEInfo cd_emlrtRTEI = { 281,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = { 39,/* lineNo */
  27,                                  /* colNo */
  "minOrMax",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = { 121,/* lineNo */
  27,                                  /* colNo */
  "minOrMax",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pName */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  123,                                 /* lineNo */
  28,                                  /* colNo */
  "n",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  19,                                  /* colNo */
  "n",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  28,                                  /* colNo */
  "n(i).neigh",                        /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  29,                                  /* colNo */
  "n",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  140,                                 /* lineNo */
  32,                                  /* colNo */
  "n",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  141,                                 /* lineNo */
  23,                                  /* colNo */
  "n",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  141,                                 /* lineNo */
  32,                                  /* colNo */
  "n(i).neigh",                        /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  146,                                 /* lineNo */
  35,                                  /* colNo */
  "n",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  22,                                  /* colNo */
  "x",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  54,                                  /* lineNo */
  15,                                  /* colNo */
  "TT",                                /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  9,                                   /* colNo */
  "SS",                                /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  45,                                  /* colNo */
  "seedInd",                           /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  9,                                   /* colNo */
  "CCp1",                              /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  45,                                  /* colNo */
  "seedInd",                           /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  9,                                   /* colNo */
  "CCp2",                              /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  9,                                   /* colNo */
  "SSn",                               /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  13,                                  /* colNo */
  "Tn",                                /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  149,                                 /* lineNo */
  17,                                  /* colNo */
  "H",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  149,                                 /* lineNo */
  9,                                   /* colNo */
  "H",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  147,                                 /* lineNo */
  20,                                  /* colNo */
  "H",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  147,                                 /* lineNo */
  13,                                  /* colNo */
  "H",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  142,                                 /* lineNo */
  21,                                  /* colNo */
  "x",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  9,                                   /* colNo */
  "C",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  125,                                 /* lineNo */
  17,                                  /* colNo */
  "x",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  125,                                 /* lineNo */
  25,                                  /* colNo */
  "x",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  165,                                 /* lineNo */
  22,                                  /* colNo */
  "x",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  30,                                  /* colNo */
  "v",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  9,                                   /* colNo */
  "M",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 113, /* lineNo */
  9,                                   /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  9,                                   /* colNo */
  "si",                                /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  20,                                  /* colNo */
  "si",                                /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  20,                                  /* colNo */
  "si",                                /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  24,                                  /* colNo */
  "M",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  13,                                  /* colNo */
  "T",                                 /* aName */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 104, /* lineNo */
  13,                                  /* colNo */
  "TwoSeedsSpreading",                 /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\TwoSeedsSpreading.m",/* pName */
  1                                    /* checkKind */
};

/* Function Declarations */
static real_T getAvalancheSizeForNode(const emlrtStack *sp, real_T xk, const
  emxArray_real_T *x);
static void matToTensor(const emlrtStack *sp, const emxArray_real_T *M, const
  emxArray_real_T *si, real_T N, emxArray_real_T *T);
static void vecToMatrix(const emlrtStack *sp, const emxArray_real_T *v, const
  emxArray_real_T *si, real_T N, emxArray_real_T *M);

/* Function Definitions */
static real_T getAvalancheSizeForNode(const emlrtStack *sp, real_T xk, const
  emxArray_real_T *x)
{
  real_T s;
  int32_T idx;
  int32_T trueCount;
  int32_T nx;
  emxArray_int32_T *r8;
  int32_T i14;
  emxArray_int32_T *ii;
  boolean_T overflow;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  idx = x->size[1] - 1;
  trueCount = 0;
  for (nx = 0; nx <= idx; nx++) {
    if (x->data[nx] == xk) {
      trueCount++;
    }
  }

  emxInit_int32_T1(sp, &r8, 2, &fc_emlrtRTEI, true);
  i14 = r8->size[0] * r8->size[1];
  r8->size[0] = 1;
  r8->size[1] = trueCount;
  emxEnsureCapacity_int32_T(sp, r8, i14, &fc_emlrtRTEI);
  trueCount = 0;
  for (nx = 0; nx <= idx; nx++) {
    if (x->data[nx] == xk) {
      r8->data[trueCount] = nx + 1;
      trueCount++;
    }
  }

  st.site = &he_emlrtRSI;
  trueCount = x->size[1];
  nx = r8->size[0] * r8->size[1];
  for (i14 = 0; i14 < nx; i14++) {
    idx = r8->data[i14];
    if (!((idx >= 1) && (idx <= trueCount))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, trueCount, (emlrtBCInfo *)
        &hd_emlrtBCI, &st);
    }
  }

  emxInit_int32_T1(&st, &ii, 2, &cc_emlrtRTEI, true);
  b_st.site = &ec_emlrtRSI;
  nx = r8->size[1];
  idx = 0;
  i14 = ii->size[0] * ii->size[1];
  ii->size[0] = 1;
  ii->size[1] = r8->size[1];
  emxEnsureCapacity_int32_T(&b_st, ii, i14, &r_emlrtRTEI);
  c_st.site = &fc_emlrtRSI;
  overflow = ((!(1 > r8->size[1])) && (r8->size[1] > 2147483646));
  if (overflow) {
    d_st.site = &y_emlrtRSI;
    e_st.site = &y_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  trueCount = 1;
  exitg1 = false;
  while ((!exitg1) && (trueCount <= nx)) {
    if (x->data[r8->data[r8->size[0] * (trueCount - 1)] - 1] != 0.0) {
      idx++;
      ii->data[idx - 1] = trueCount;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        trueCount++;
      }
    } else {
      trueCount++;
    }
  }

  if (!(idx <= r8->size[1])) {
    emlrtErrorWithMessageIdR2012b(&b_st, &nd_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (r8->size[1] == 1) {
    if (idx == 0) {
      i14 = ii->size[0] * ii->size[1];
      ii->size[1] = 0;
      emxEnsureCapacity_int32_T(&b_st, ii, i14, &t_emlrtRTEI);
    }
  } else {
    i14 = ii->size[0] * ii->size[1];
    if (1 > idx) {
      ii->size[1] = 0;
    } else {
      ii->size[1] = idx;
    }

    emxEnsureCapacity_int32_T(&b_st, ii, i14, &t_emlrtRTEI);
  }

  emxFree_int32_T(&r8);
  s = ii->size[1];
  emxFree_int32_T(&ii);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return s;
}

static void matToTensor(const emlrtStack *sp, const emxArray_real_T *M, const
  emxArray_real_T *si, real_T N, emxArray_real_T *T)
{
  int32_T i18;
  int32_T loop_ub;
  int32_T ii;
  int32_T i19;
  real_T d3;
  int32_T i20;
  int32_T i21;
  i18 = T->size[0] * T->size[1] * T->size[2];
  T->size[0] = (int32_T)N;
  T->size[1] = (int32_T)N;
  T->size[2] = (int32_T)N;
  emxEnsureCapacity_real_T2(sp, T, i18, &hc_emlrtRTEI);
  loop_ub = (int32_T)N * (int32_T)N * (int32_T)N;
  for (i18 = 0; i18 < loop_ub; i18++) {
    T->data[i18] = 0.0;
  }

  loop_ub = 1;
  while (loop_ub - 1 <= (int32_T)N - 1) {
    ii = 0;
    while (ii <= si->size[0] - 1) {
      i18 = si->size[0];
      i19 = ii + 1;
      if (!((i19 >= 1) && (i19 <= i18))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, i18, (emlrtBCInfo *)&ld_emlrtBCI,
          sp);
      }

      i18 = si->size[0];
      i19 = ii + 1;
      if (!((i19 >= 1) && (i19 <= i18))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, i18, (emlrtBCInfo *)&md_emlrtBCI,
          sp);
      }

      i18 = M->size[0];
      i19 = 1 + ii;
      if (!((i19 >= 1) && (i19 <= i18))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, i18, (emlrtBCInfo *)&nd_emlrtBCI,
          sp);
      }

      i18 = M->size[1];
      if (!((loop_ub >= 1) && (loop_ub <= i18))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i18, (emlrtBCInfo *)
          &nd_emlrtBCI, sp);
      }

      i18 = T->size[0];
      d3 = si->data[ii];
      if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
        emlrtIntegerCheckR2012b(d3, (emlrtDCInfo *)&h_emlrtDCI, sp);
      }

      i20 = (int32_T)d3;
      if (!((i20 >= 1) && (i20 <= i18))) {
        emlrtDynamicBoundsCheckR2012b(i20, 1, i18, (emlrtBCInfo *)&od_emlrtBCI,
          sp);
      }

      i18 = T->size[1];
      d3 = si->data[ii + si->size[0]];
      if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
        emlrtIntegerCheckR2012b(d3, (emlrtDCInfo *)&h_emlrtDCI, sp);
      }

      i21 = (int32_T)d3;
      if (!((i21 >= 1) && (i21 <= i18))) {
        emlrtDynamicBoundsCheckR2012b(i21, 1, i18, (emlrtBCInfo *)&od_emlrtBCI,
          sp);
      }

      i18 = T->size[2];
      if (!((loop_ub >= 1) && (loop_ub <= i18))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i18, (emlrtBCInfo *)
          &od_emlrtBCI, sp);
      }

      T->data[((i20 + T->size[0] * (i21 - 1)) + T->size[0] * T->size[1] *
               (loop_ub - 1)) - 1] = M->data[(i19 + M->size[0] * (loop_ub - 1))
        - 1];
      ii++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    loop_ub++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

static void vecToMatrix(const emlrtStack *sp, const emxArray_real_T *v, const
  emxArray_real_T *si, real_T N, emxArray_real_T *M)
{
  int32_T i15;
  int32_T loop_ub;
  int32_T i16;
  real_T d2;
  int32_T i17;

  /*      M = 1-eye(N); */
  i15 = M->size[0] * M->size[1];
  M->size[0] = (int32_T)N;
  M->size[1] = (int32_T)N;
  emxEnsureCapacity_real_T(sp, M, i15, &gc_emlrtRTEI);
  loop_ub = (int32_T)N * (int32_T)N;
  for (i15 = 0; i15 < loop_ub; i15++) {
    M->data[i15] = 0.0;
  }

  loop_ub = 1;
  while (loop_ub - 1 <= v->size[0] - 1) {
    i15 = v->size[0];
    if (!((loop_ub >= 1) && (loop_ub <= i15))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)&id_emlrtBCI,
        sp);
    }

    i15 = M->size[0];
    i16 = si->size[0];
    if (!((loop_ub >= 1) && (loop_ub <= i16))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i16, (emlrtBCInfo *)&kd_emlrtBCI,
        sp);
    }

    d2 = si->data[loop_ub - 1];
    if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
      emlrtIntegerCheckR2012b(d2, (emlrtDCInfo *)&g_emlrtDCI, sp);
    }

    i16 = (int32_T)d2;
    if (!((i16 >= 1) && (i16 <= i15))) {
      emlrtDynamicBoundsCheckR2012b(i16, 1, i15, (emlrtBCInfo *)&jd_emlrtBCI, sp);
    }

    i15 = M->size[1];
    i17 = si->size[0];
    if (!((loop_ub >= 1) && (loop_ub <= i17))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i17, (emlrtBCInfo *)&kd_emlrtBCI,
        sp);
    }

    d2 = si->data[(loop_ub + si->size[0]) - 1];
    if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
      emlrtIntegerCheckR2012b(d2, (emlrtDCInfo *)&g_emlrtDCI, sp);
    }

    i17 = (int32_T)d2;
    if (!((i17 >= 1) && (i17 <= i15))) {
      emlrtDynamicBoundsCheckR2012b(i17, 1, i15, (emlrtBCInfo *)&jd_emlrtBCI, sp);
    }

    M->data[(i16 + M->size[0] * (i17 - 1)) - 1] = v->data[loop_ub - 1];
    loop_ub++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

void TwoSeedsSpreading(const emlrtStack *sp, const emxArray_real_T *A, real_T
  Theta, real_T tTotal, real_T isCompetitive, emxArray_real_T *Cp1,
  emxArray_real_T *Cp2, emxArray_real_T *H, emxArray_real_T *Cf, emxArray_real_T
  *T, emxArray_real_T *Tn, emxArray_real_T *S, emxArray_real_T *Sn)
{
  emxArray_real_T *x;
  int32_T i0;
  int32_T i1;
  int32_T idx;
  emxArray_real_T *jj;
  emxArray_real_T *ii;
  emxArray_real_T *b_jj;
  boolean_T overflow;
  emxArray_real_T *seedInd;
  int32_T ixstart;
  emxArray_int32_T *r0;
  real_T k;
  real_T d0;
  d_struct_T p;
  emxArray_struct_T *n;
  emxArray_real_T *SS;
  emxArray_real_T *TT;
  emxArray_real_T *SSn;
  emxArray_real_T *TTn;
  emxArray_real_T *CCp1;
  emxArray_real_T *CCp2;
  int32_T i;
  emxArray_real_T *r1;
  emxArray_int32_T *r2;
  emxArray_boolean_T *r3;
  emxArray_int32_T *r4;
  int32_T c_jj;
  int32_T b_n;
  boolean_T exitg1;
  int32_T b_i;
  real_T P[2];
  int32_T iv0[2];
  int32_T ii_data[1];
  int32_T f_data[1];
  int32_T d_jj[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  Cp -> competitiveness of a node */
  /*  H -> entropy of a node */
  /*  Cf -> conformity of a node */
  /*  T -> network activation time for each pair of seeds */
  /*  Tn -> node activation time for each pair of seeds Tn(i,j,k) -> time for seeds (i,j) to activate node k */
  /*  S -> network activation time (in inverse weight units) for each pair of seeds */
  /*  Sn -> node activation time (in inverse weight units) for each pair of seeds Tn(i,j,k) -> time for seeds (i,j) to activate node k */
  /*  */
  /*  defined in Misic et al 2015 Neuron; pg 1527-1528 (pdf 11-12). */
  /*  */
  /*  Cp_i == size of cascades iniated at node i, averaged over all competing nodes j */
  /*  H_i == - sum_c P(x_c)*log[P(x_c)] */
  /*       where c runs over all available states (2 seeds, c = 2) */
  /*       P_i(x_c)=n_i(x_c)/k_i is the probability of finding a neighbor of i with state x_c; */
  /*          n_i(x_c) is the amount of neighbors of i with state x_c; */
  /*          k_i is the connectivity of node i */
  /*       the definition of P(x_c) in the paper is ambiguous, */
  /*       it could also be interpreted as the probability of finding all the neighbors of i in state x_c */
  /*  Cf_i == the proportion of neighbors in the same state as i */
  /*  */
  /*  these measures must be averaged over all seeds */
  /*  */
  /*  Cp1 is the average avalanche size of state 1 */
  /*  Cp2 is the average avalanche size of state 2 */
  /*  */
  /*  theoretically, Cp1' == Cp2, because of the symmetry of the system */
  /*        (avalanche sizes for state 1 seeds (i,j) are equal to avalanche sizes of state 2 for seeds (j,i); */
  /*  however, the function UpdateInputNSeed does not treat all the states equally: */
  /*  if the input weights for each state to a given node are equal, */
  /*  then the state state 1 is preferred over state 2, 2 over 3, and so on, */
  /*  due to the finding of maximum weight algorithm in that function */
  /*  I improved the UpdateInputNSeed function to change to a random state when an equal weighted input is found */
  /*  now, Cp1' is statistically equal Cp2 */
  emxInit_real_T(sp, &x, 2, &k_emlrtRTEI, true);
  if (A->size[0] < 1) {
    i0 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = 0;
    emxEnsureCapacity_real_T(sp, x, i0, &emlrtRTEI);
  } else {
    i0 = A->size[0];
    i1 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = (int32_T)((real_T)i0 - 1.0) + 1;
    emxEnsureCapacity_real_T(sp, x, i1, &emlrtRTEI);
    idx = (int32_T)((real_T)i0 - 1.0);
    for (i0 = 0; i0 <= idx; i0++) {
      x->data[x->size[0] * i0] = 1.0 + (real_T)i0;
    }
  }

  emxInit_real_T(sp, &jj, 2, &u_emlrtRTEI, true);
  if (A->size[0] < 1) {
    i0 = jj->size[0] * jj->size[1];
    jj->size[0] = 1;
    jj->size[1] = 0;
    emxEnsureCapacity_real_T(sp, jj, i0, &b_emlrtRTEI);
  } else {
    i0 = A->size[0];
    i1 = jj->size[0] * jj->size[1];
    jj->size[0] = 1;
    jj->size[1] = (int32_T)((real_T)i0 - 1.0) + 1;
    emxEnsureCapacity_real_T(sp, jj, i1, &b_emlrtRTEI);
    idx = (int32_T)((real_T)i0 - 1.0);
    for (i0 = 0; i0 <= idx; i0++) {
      jj->data[jj->size[0] * i0] = 1.0 + (real_T)i0;
    }
  }

  emxInit_real_T(sp, &ii, 2, &hb_emlrtRTEI, true);
  emxInit_real_T(sp, &b_jj, 2, &w_emlrtRTEI, true);
  st.site = &emlrtRSI;
  meshgrid(&st, x, jj, ii, b_jj);
  st.site = &b_emlrtRSI;
  b_st.site = &bb_emlrtRSI;
  c_st.site = &cb_emlrtRSI;
  overflow = true;
  if (b_jj->size[0] * b_jj->size[1] != ii->size[0] * ii->size[1]) {
    overflow = false;
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2012b(&c_st, &cd_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_real_T(&c_st, &seedInd, 2, &x_emlrtRTEI, true);
  idx = ii->size[0] * ii->size[1];
  ixstart = b_jj->size[0] * b_jj->size[1];
  i0 = seedInd->size[0] * seedInd->size[1];
  seedInd->size[0] = idx;
  seedInd->size[1] = 2;
  emxEnsureCapacity_real_T(sp, seedInd, i0, &c_emlrtRTEI);
  for (i0 = 0; i0 < idx; i0++) {
    seedInd->data[i0] = ii->data[i0];
  }

  for (i0 = 0; i0 < ixstart; i0++) {
    seedInd->data[i0 + seedInd->size[0]] = b_jj->data[i0];
  }

  emxInit_int32_T1(sp, &r0, 2, &d_emlrtRTEI, true);
  k = (real_T)A->size[0] + 1.0;
  d0 = (real_T)A->size[0] * (real_T)A->size[0];
  i0 = r0->size[0] * r0->size[1];
  r0->size[0] = 1;
  r0->size[1] = (int32_T)muDoubleScalarFloor((d0 - 1.0) / k) + 1;
  emxEnsureCapacity_int32_T(sp, r0, i0, &d_emlrtRTEI);
  idx = (int32_T)muDoubleScalarFloor((d0 - 1.0) / k);
  for (i0 = 0; i0 <= idx; i0++) {
    r0->data[r0->size[0] * i0] = (int32_T)(1.0 + k * (real_T)i0);
  }

  emxInitStruct_struct_T(sp, &p, &y_emlrtRTEI, true);
  emxInit_struct_T(sp, &n, 2, &ab_emlrtRTEI, true);
  st.site = &c_emlrtRSI;
  nullAssignment(&st, seedInd, r0);

  /*  excluding the entries with two seeds in the same node */
  /*  one simulation for each seed combination */
  st.site = &d_emlrtRSI;
  GetSimulationParam(&st, A, isCompetitive, seedInd, (real_T)seedInd->size[0],
                     &p.N, &p.nSeeds, &p.isCompetitive, p.seeds, &p.nSim,
                     p.seedType, &p.seedTrial, p.x0);
  st.site = &e_emlrtRSI;
  GetNodes(&st, A, Theta, 2.0, isCompetitive, n);

  /*  spreading time (in inverse weight units) from each seed combination to the whole network */
  /*  spreading time from each seed combination to the whole network */
  /*  spreading time (in inverse weight units) from each seed combination to each node in the network */
  /*  spreading time from each seed combination to each node in the network */
  i0 = Cf->size[0];
  Cf->size[0] = A->size[0];
  emxEnsureCapacity_real_T1(sp, Cf, i0, &e_emlrtRTEI);
  idx = A->size[0];
  emxFree_int32_T(&r0);
  for (i0 = 0; i0 < idx; i0++) {
    Cf->data[i0] = 0.0;
  }

  i0 = H->size[0];
  H->size[0] = A->size[0];
  emxEnsureCapacity_real_T1(sp, H, i0, &f_emlrtRTEI);
  idx = A->size[0];
  for (i0 = 0; i0 < idx; i0++) {
    H->data[i0] = 0.0;
  }

  emxInit_real_T1(sp, &SS, 1, &bb_emlrtRTEI, true);
  emxInit_real_T1(sp, &TT, 1, &cb_emlrtRTEI, true);
  emxInit_real_T(sp, &SSn, 2, &db_emlrtRTEI, true);
  emxInit_real_T(sp, &TTn, 2, &eb_emlrtRTEI, true);
  emxInit_real_T1(sp, &CCp1, 1, &fb_emlrtRTEI, true);
  emxInit_real_T1(sp, &CCp2, 1, &gb_emlrtRTEI, true);

  /* CCf = zeros(nSim, 1); */
  /* HH = zeros(nSim, 1); */
  /*      x = zeros(nSim, N); */
  i0 = TT->size[0];
  TT->size[0] = seedInd->size[0];
  emxEnsureCapacity_real_T1(sp, TT, i0, &g_emlrtRTEI);
  i0 = SS->size[0];
  SS->size[0] = seedInd->size[0];
  emxEnsureCapacity_real_T1(sp, SS, i0, &g_emlrtRTEI);
  i0 = CCp1->size[0];
  CCp1->size[0] = seedInd->size[0];
  emxEnsureCapacity_real_T1(sp, CCp1, i0, &g_emlrtRTEI);
  i0 = CCp2->size[0];
  CCp2->size[0] = seedInd->size[0];
  emxEnsureCapacity_real_T1(sp, CCp2, i0, &g_emlrtRTEI);
  i0 = TTn->size[0] * TTn->size[1];
  TTn->size[0] = seedInd->size[0];
  TTn->size[1] = A->size[0];
  emxEnsureCapacity_real_T(sp, TTn, i0, &g_emlrtRTEI);
  i0 = SSn->size[0] * SSn->size[1];
  SSn->size[0] = seedInd->size[0];
  SSn->size[1] = A->size[0];
  emxEnsureCapacity_real_T(sp, SSn, i0, &g_emlrtRTEI);
  i = 0;
  emxInit_real_T1(sp, &r1, 1, &w_emlrtRTEI, true);
  emxInit_int32_T(sp, &r2, 1, &w_emlrtRTEI, true);
  emxInit_boolean_T(sp, &r3, 2, &w_emlrtRTEI, true);
  emxInit_int32_T1(sp, &r4, 2, &w_emlrtRTEI, true);
  while (i <= seedInd->size[0] - 1) {
    i0 = TT->size[0];
    if (!((i + 1 >= 1) && (i + 1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, (emlrtBCInfo *)&s_emlrtBCI, sp);
    }

    st.site = &f_emlrtRSI;
    EvolveSINetwork(&st, n, tTotal, &p, ii, &TT->data[i], b_jj);
    st.site = &g_emlrtRSI;
    idx = b_jj->size[1];
    i0 = b_jj->size[0];
    c_jj = b_jj->size[0];
    if (!((c_jj >= 1) && (c_jj <= i0))) {
      emlrtDynamicBoundsCheckR2012b(c_jj, 1, i0, (emlrtBCInfo *)&emlrtBCI, &st);
    }

    i0 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = idx;
    emxEnsureCapacity_real_T(&st, x, i0, &h_emlrtRTEI);
    for (i0 = 0; i0 < idx; i0++) {
      x->data[x->size[0] * i0] = b_jj->data[(c_jj + b_jj->size[0] * i0) - 1];
    }

    b_st.site = &ce_emlrtRSI;
    c_st.site = &de_emlrtRSI;
    i0 = b_jj->size[1];
    if (i0 == 1) {
      overflow = true;
    } else {
      i0 = b_jj->size[1];
      if (i0 != 1) {
        overflow = true;
      } else {
        overflow = false;
      }
    }

    if (!overflow) {
      emlrtErrorWithMessageIdR2012b(&c_st, &dd_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    i0 = b_jj->size[1];
    if (!(i0 > 0)) {
      emlrtErrorWithMessageIdR2012b(&c_st, &ed_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    d_st.site = &ee_emlrtRSI;
    ixstart = 1;
    b_n = b_jj->size[1];
    c_jj = b_jj->size[0];
    k = b_jj->data[c_jj - 1];
    i0 = b_jj->size[1];
    if (i0 > 1) {
      if (muDoubleScalarIsNaN(k)) {
        e_st.site = &ge_emlrtRSI;
        i0 = b_jj->size[1];
        if (2 > i0) {
          overflow = false;
        } else {
          i0 = b_jj->size[1];
          overflow = (i0 > 2147483646);
        }

        if (overflow) {
          f_st.site = &y_emlrtRSI;
          g_st.site = &y_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }

        idx = 2;
        exitg1 = false;
        while ((!exitg1) && (idx <= b_n)) {
          ixstart = idx;
          if (!muDoubleScalarIsNaN(x->data[idx - 1])) {
            k = x->data[idx - 1];
            exitg1 = true;
          } else {
            idx++;
          }
        }
      }

      i0 = b_jj->size[1];
      if (ixstart < i0) {
        e_st.site = &fe_emlrtRSI;
        i0 = b_jj->size[1];
        if (ixstart + 1 > i0) {
          overflow = false;
        } else {
          i0 = b_jj->size[1];
          overflow = (i0 > 2147483646);
        }

        if (overflow) {
          f_st.site = &y_emlrtRSI;
          g_st.site = &y_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }

        while (ixstart + 1 <= b_n) {
          if (x->data[ixstart] > k) {
            k = x->data[ixstart];
          }

          ixstart++;
        }
      }
    }

    i0 = SS->size[0];
    if (!((i + 1 >= 1) && (i + 1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, (emlrtBCInfo *)&t_emlrtBCI, sp);
    }

    SS->data[i] = k;
    idx = ii->size[1];
    i0 = ii->size[0];
    b_n = ii->size[0];
    if (!((b_n >= 1) && (b_n <= i0))) {
      emlrtDynamicBoundsCheckR2012b(b_n, 1, i0, (emlrtBCInfo *)&b_emlrtBCI, sp);
    }

    i0 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = idx;
    emxEnsureCapacity_real_T(sp, x, i0, &k_emlrtRTEI);
    for (i0 = 0; i0 < idx; i0++) {
      x->data[x->size[0] * i0] = ii->data[(b_n + ii->size[0] * i0) - 1];
    }

    i0 = ii->size[1];
    i1 = seedInd->size[0];
    if (!((i + 1 >= 1) && (i + 1 <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, i1, (emlrtBCInfo *)&u_emlrtBCI, sp);
    }

    k = seedInd->data[i];
    if (k != (int32_T)muDoubleScalarFloor(k)) {
      emlrtIntegerCheckR2012b(k, (emlrtDCInfo *)&emlrtDCI, sp);
    }

    i1 = (int32_T)k;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&c_emlrtBCI, sp);
    }

    i0 = i1 - 1;
    b_n = ii->size[0];
    i1 = CCp1->size[0];
    if (!((i + 1 >= 1) && (i + 1 <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, i1, (emlrtBCInfo *)&v_emlrtBCI, sp);
    }

    st.site = &h_emlrtRSI;
    CCp1->data[i] = getAvalancheSizeForNode(&st, ii->data[(b_n + ii->size[0] *
      i0) - 1], x);

    /*  get size of avalanche starting at seed seedInd(i,1) */
    i0 = ii->size[1];
    i1 = seedInd->size[0];
    if (!((i + 1 >= 1) && (i + 1 <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, i1, (emlrtBCInfo *)&w_emlrtBCI, sp);
    }

    k = seedInd->data[i + seedInd->size[0]];
    if (k != (int32_T)muDoubleScalarFloor(k)) {
      emlrtIntegerCheckR2012b(k, (emlrtDCInfo *)&b_emlrtDCI, sp);
    }

    i1 = (int32_T)k;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&d_emlrtBCI, sp);
    }

    i0 = i1 - 1;
    b_n = ii->size[0];
    i1 = CCp2->size[0];
    if (!((i + 1 >= 1) && (i + 1 <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, i1, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    st.site = &i_emlrtRSI;
    CCp2->data[i] = getAvalancheSizeForNode(&st, ii->data[(b_n + ii->size[0] *
      i0) - 1], x);

    /*  get size of avalanche starting at seed seedInd(i,1) */
    st.site = &j_emlrtRSI;
    i0 = r1->size[0];
    r1->size[0] = n->size[1];
    emxEnsureCapacity_real_T1(&st, r1, i0, &l_emlrtRTEI);
    b_i = 0;
    while (b_i <= n->size[1] - 1) {
      /*  for each node */
      /*  find the number of neighbors with the same state of i */
      k = 0.0;
      i0 = n->size[1];
      i1 = b_i + 1;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&j_emlrtBCI, &st);
      }

      c_jj = 0;
      while (c_jj <= n->data[b_i].neigh->size[0] - 1) {
        /*  for each neighbor */
        i0 = n->size[1];
        i1 = b_i + 1;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&k_emlrtBCI,
            &st);
        }

        i0 = n->data[b_i].neigh->size[0];
        i1 = c_jj + 1;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&l_emlrtBCI,
            &st);
        }

        i0 = ii->size[1];
        i1 = ii->size[1];
        b_n = (int32_T)n->data[b_i].neigh->data[c_jj];
        if (!((b_n >= 1) && (b_n <= i0))) {
          emlrtDynamicBoundsCheckR2012b(b_n, 1, i0, (emlrtBCInfo *)&hb_emlrtBCI,
            &st);
        }

        i0 = 1 + b_i;
        if (!((i0 >= 1) && (i0 <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i0, 1, i1, (emlrtBCInfo *)&ib_emlrtBCI,
            &st);
        }

        if (x->data[b_n - 1] == x->data[i0 - 1]) {
          k++;
        }

        c_jj++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      i0 = n->size[1];
      i1 = b_i + 1;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&m_emlrtBCI, &st);
      }

      i0 = r1->size[0];
      i1 = 1 + b_i;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&gb_emlrtBCI,
          &st);
      }

      r1->data[i1 - 1] = k / (real_T)n->data[b_i].neigh->size[0];
      b_i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    i0 = Cf->size[0];
    i1 = r1->size[0];
    if (i0 != i1) {
      emlrtSizeEqCheck1DR2012b(i0, i1, (emlrtECInfo *)&emlrtECI, sp);
    }

    i0 = Cf->size[0];
    emxEnsureCapacity_real_T1(sp, Cf, i0, &m_emlrtRTEI);
    idx = Cf->size[0];
    for (i0 = 0; i0 < idx; i0++) {
      Cf->data[i0] += r1->data[i0];
    }

    st.site = &k_emlrtRSI;
    i0 = r1->size[0];
    r1->size[0] = n->size[1];
    emxEnsureCapacity_real_T1(&st, r1, i0, &n_emlrtRTEI);
    idx = n->size[1];
    for (i0 = 0; i0 < idx; i0++) {
      r1->data[i0] = 0.0;
    }

    b_i = 0;
    while (b_i <= n->size[1] - 1) {
      for (i0 = 0; i0 < 2; i0++) {
        P[i0] = 0.0;
      }

      /*  probability of finding a neighbor in each of the available states xc */
      ixstart = 0;
      while (ixstart < 2) {
        /*  check which neighbors of i are in each state */
        i0 = n->size[1];
        i1 = b_i + 1;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&n_emlrtBCI,
            &st);
        }

        c_jj = 0;
        while (c_jj <= n->data[b_i].neigh->size[0] - 1) {
          i0 = n->size[1];
          i1 = b_i + 1;
          if (!((i1 >= 1) && (i1 <= i0))) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&o_emlrtBCI,
              &st);
          }

          i0 = n->data[b_i].neigh->size[0];
          i1 = c_jj + 1;
          if (!((i1 >= 1) && (i1 <= i0))) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&p_emlrtBCI,
              &st);
          }

          i0 = ii->size[1];
          i1 = (int32_T)n->data[b_i].neigh->data[c_jj];
          if (!((i1 >= 1) && (i1 <= i0))) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&fb_emlrtBCI,
              &st);
          }

          if (x->data[i1 - 1] == p.x0[ixstart]) {
            /*  if a given neighbor is in the state k */
            P[ixstart]++;

            /*  sums 1 to probability of finding neighbor in state k */
          }

          c_jj++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&st);
          }
        }

        i0 = n->size[1];
        i1 = b_i + 1;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&q_emlrtBCI,
            &st);
        }

        P[ixstart] /= (real_T)n->data[b_i].neigh->size[0];
        b_st.site = &ie_emlrtRSI;
        if (P[ixstart] == 0.0) {
          k = 0.0;
        } else {
          c_st.site = &je_emlrtRSI;
          if (P[ixstart] < 0.0) {
            d_st.site = &ke_emlrtRSI;
            e_st.site = &ke_emlrtRSI;
            c_error(&e_st);
          }

          k = P[ixstart] * muDoubleScalarLog(P[ixstart]);
        }

        i0 = r1->size[0];
        i1 = 1 + b_i;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&db_emlrtBCI,
            &st);
        }

        i0 = r1->size[0];
        b_n = 1 + b_i;
        if (!((b_n >= 1) && (b_n <= i0))) {
          emlrtDynamicBoundsCheckR2012b(b_n, 1, i0, (emlrtBCInfo *)&eb_emlrtBCI,
            &st);
        }

        r1->data[b_n - 1] = r1->data[i1 - 1] + k;
        ixstart++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      i0 = r1->size[0];
      i1 = 1 + b_i;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&bb_emlrtBCI,
          &st);
      }

      i0 = r1->size[0];
      b_n = 1 + b_i;
      if (!((b_n >= 1) && (b_n <= i0))) {
        emlrtDynamicBoundsCheckR2012b(b_n, 1, i0, (emlrtBCInfo *)&cb_emlrtBCI,
          &st);
      }

      r1->data[b_n - 1] = -r1->data[i1 - 1];

      /* H(i) = - sum(P.*log(P)); */
      b_i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    i0 = H->size[0];
    i1 = r1->size[0];
    if (i0 != i1) {
      emlrtSizeEqCheck1DR2012b(i0, i1, (emlrtECInfo *)&b_emlrtECI, sp);
    }

    i0 = H->size[0];
    emxEnsureCapacity_real_T1(sp, H, i0, &o_emlrtRTEI);
    idx = H->size[0];
    for (i0 = 0; i0 < idx; i0++) {
      H->data[i0] += r1->data[i0];
    }

    i0 = TTn->size[0];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&i_emlrtBCI, sp);
    }

    idx = TTn->size[1];
    i0 = r2->size[0];
    r2->size[0] = idx;
    emxEnsureCapacity_int32_T1(sp, r2, i0, &p_emlrtRTEI);
    for (i0 = 0; i0 < idx; i0++) {
      r2->data[i0] = i0;
    }

    st.site = &l_emlrtRSI;

    /*  x(:,i) is the timeseries for each node i */
    i0 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = ii->size[1];
    emxEnsureCapacity_real_T(&st, x, i0, &q_emlrtRTEI);
    b_i = 0;
    while (b_i <= ii->size[1] - 1) {
      b_st.site = &le_emlrtRSI;
      i0 = ii->size[1];
      i1 = b_i + 1;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&r_emlrtBCI,
          &b_st);
      }

      c_st.site = &ec_emlrtRSI;
      i0 = ii->size[0];
      idx = 0;
      ixstart = 1;
      d_st.site = &fc_emlrtRSI;
      i1 = ii->size[0];
      if (1 > i1) {
        overflow = false;
      } else {
        i1 = ii->size[0];
        overflow = (i1 > 2147483646);
      }

      if (overflow) {
        e_st.site = &y_emlrtRSI;
        f_st.site = &y_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      b_n = 1;
      exitg1 = false;
      while ((!exitg1) && (b_n <= i0)) {
        if (ii->data[(b_n + ii->size[0] * b_i) - 1] != 0.0) {
          idx = 1;
          ii_data[0] = b_n;
          exitg1 = true;
        } else {
          b_n++;
        }
      }

      if (idx == 0) {
        ixstart = 0;
      }

      if (0 <= ixstart - 1) {
        memcpy(&f_data[0], &ii_data[0], (uint32_T)(ixstart * (int32_T)sizeof
                (int32_T)));
      }

      i0 = x->size[1];
      i1 = 1 + b_i;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&ab_emlrtBCI,
          &st);
      }

      if (ixstart == 0) {
        x->data[i1 - 1] = rtNaN;
      } else {
        x->data[i1 - 1] = f_data[0];
      }

      b_i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    iv0[0] = 1;
    iv0[1] = r2->size[0];
    emlrtSubAssignSizeCheckR2012b(&iv0[0], 2, &(*(int32_T (*)[2])x->size)[0], 2,
      (emlrtECInfo *)&d_emlrtECI, sp);
    idx = x->size[1];
    for (i0 = 0; i0 < idx; i0++) {
      TTn->data[i + TTn->size[0] * r2->data[i0]] = x->data[x->size[0] * i0];
    }

    i0 = SSn->size[0];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&f_emlrtBCI, sp);
    }

    idx = SSn->size[1];
    i0 = r2->size[0];
    r2->size[0] = idx;
    emxEnsureCapacity_int32_T1(sp, r2, i0, &s_emlrtRTEI);
    for (i0 = 0; i0 < idx; i0++) {
      r2->data[i0] = i0;
    }

    i0 = b_jj->size[0];
    i1 = b_jj->size[0];
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&e_emlrtBCI, sp);
    }

    iv0[0] = 1;
    iv0[1] = r2->size[0];
    idx = b_jj->size[1];
    c_jj = b_jj->size[0];
    i0 = jj->size[0] * jj->size[1];
    jj->size[0] = 1;
    jj->size[1] = idx;
    emxEnsureCapacity_real_T(sp, jj, i0, &u_emlrtRTEI);
    for (i0 = 0; i0 < idx; i0++) {
      jj->data[jj->size[0] * i0] = b_jj->data[(c_jj + b_jj->size[0] * i0) - 1];
    }

    for (i0 = 0; i0 < 2; i0++) {
      d_jj[i0] = jj->size[i0];
    }

    emlrtSubAssignSizeCheckR2012b(&iv0[0], 2, &d_jj[0], 2, (emlrtECInfo *)
      &c_emlrtECI, sp);
    idx = b_jj->size[1] - 1;
    c_jj = b_jj->size[0];
    for (i0 = 0; i0 <= idx; i0++) {
      SSn->data[i + SSn->size[0] * r2->data[i0]] = b_jj->data[(c_jj + b_jj->
        size[0] * i0) - 1];
    }

    i0 = SSn->size[0];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&h_emlrtBCI, sp);
    }

    idx = SSn->size[1];
    i0 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = idx;
    emxEnsureCapacity_boolean_T(sp, r3, i0, &v_emlrtRTEI);
    for (i0 = 0; i0 < idx; i0++) {
      r3->data[r3->size[0] * i0] = (SSn->data[i + SSn->size[0] * i0] == 0.0);
    }

    b_n = r3->size[1] - 1;
    ixstart = 0;
    for (b_i = 0; b_i <= b_n; b_i++) {
      if (r3->data[b_i]) {
        ixstart++;
      }
    }

    i0 = r4->size[0] * r4->size[1];
    r4->size[0] = 1;
    r4->size[1] = ixstart;
    emxEnsureCapacity_int32_T(sp, r4, i0, &w_emlrtRTEI);
    idx = 0;
    for (b_i = 0; b_i <= b_n; b_i++) {
      if (r3->data[b_i]) {
        r4->data[idx] = b_i + 1;
        idx++;
      }
    }

    ixstart = r4->size[1];
    idx = SSn->size[0];
    b_n = SSn->size[1];
    if (!((i + 1 >= 1) && (i + 1 <= idx))) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, idx, (emlrtBCInfo *)&g_emlrtBCI,
        sp);
    }

    for (i0 = 0; i0 < ixstart; i0++) {
      i1 = r4->data[r4->size[0] * i0];
      if (!((i1 >= 1) && (i1 <= b_n))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, b_n, (emlrtBCInfo *)&y_emlrtBCI, sp);
      }

      SSn->data[i + SSn->size[0] * (i1 - 1)] = rtNaN;
    }

    /*          [x(i,:),p,TT(i)] = EvolveSINetwork(n, tTotal, p, 0); */
    /*          CCp1(i) = getAvalancheSizeForNode(x(i,seedInd(i,1)), x(i,:)); % get size of avalanche starting at seed seedInd(i,1) */
    /*          CCp2(i) = getAvalancheSizeForNode(x(i,seedInd(i,2)), x(i,:)); % get size of avalanche starting at seed seedInd(i,1) */
    /*          Cf = Cf + getConformityForNetwork(n, x(i,:)); */
    /*          H = H + getEntropyForNetwork(n, x(i,:), p.x0); */
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&jj);
  emxFree_int32_T(&r4);
  emxFree_boolean_T(&r3);
  emxFree_int32_T(&r2);
  emxFree_real_T(&r1);
  emxFree_real_T(&b_jj);
  emxFree_real_T(&ii);
  emxFree_real_T(&x);
  emxFree_struct_T(&n);
  emxFreeStruct_struct_T1(&p);

  /* Cp = averageForOneSeed(CCp, N); */
  /* T = averageForOneSeed(TT, N); */
  st.site = &m_emlrtRSI;
  vecToMatrix(&st, CCp1, seedInd, (real_T)A->size[0], Cp1);
  st.site = &n_emlrtRSI;
  vecToMatrix(&st, CCp2, seedInd, (real_T)A->size[0], Cp2);
  st.site = &o_emlrtRSI;
  vecToMatrix(&st, TT, seedInd, (real_T)A->size[0], T);
  st.site = &p_emlrtRSI;
  matToTensor(&st, TTn, seedInd, (real_T)A->size[0], Tn);
  st.site = &q_emlrtRSI;
  vecToMatrix(&st, SS, seedInd, (real_T)A->size[0], S);
  st.site = &r_emlrtRSI;
  matToTensor(&st, SSn, seedInd, (real_T)A->size[0], Sn);
  i0 = TT->size[0];
  TT->size[0] = H->size[0];
  emxEnsureCapacity_real_T1(sp, TT, i0, &i_emlrtRTEI);
  idx = H->size[0];
  emxFree_real_T(&CCp2);
  emxFree_real_T(&CCp1);
  emxFree_real_T(&TTn);
  emxFree_real_T(&SSn);
  emxFree_real_T(&SS);
  for (i0 = 0; i0 < idx; i0++) {
    TT->data[i0] = H->data[i0];
  }

  rdivide(sp, TT, (real_T)seedInd->size[0], H);
  i0 = TT->size[0];
  TT->size[0] = Cf->size[0];
  emxEnsureCapacity_real_T1(sp, TT, i0, &j_emlrtRTEI);
  idx = Cf->size[0];
  for (i0 = 0; i0 < idx; i0++) {
    TT->data[i0] = Cf->data[i0];
  }

  rdivide(sp, TT, (real_T)seedInd->size[0], Cf);
  emxFree_real_T(&TT);
  emxFree_real_T(&seedInd);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (TwoSeedsSpreading.cpp) */
