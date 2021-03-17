/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * PhaseTransition.cpp
 *
 * Code generation for function 'PhaseTransition'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "PhaseTransition.h"
#include "rand.h"
#include "PhaseTransition_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "GetNodes.h"
#include "GetSurrogateRandomMatrix.h"
#include "repmat.h"
#include "assertValidSizeArg.h"
#include "sum.h"
#include "strcmp.h"
#include "PhaseTransition_mexutil.h"
#include "PhaseTransition_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 24,    /* lineNo */
  "PhaseTransition",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 29,  /* lineNo */
  "PhaseTransition",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 34,  /* lineNo */
  "PhaseTransition",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 39,  /* lineNo */
  "PhaseTransition",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 42,  /* lineNo */
  "PhaseTransition",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 50,  /* lineNo */
  "PhaseTransition",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 54,  /* lineNo */
  "PhaseTransition",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 57,  /* lineNo */
  "PhaseTransition",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 59,  /* lineNo */
  "PhaseTransition",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 62,  /* lineNo */
  "PhaseTransition",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 80,  /* lineNo */
  "PhaseTransition",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 81,  /* lineNo */
  "PhaseTransition",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 83,  /* lineNo */
  "PhaseTransition",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 85,  /* lineNo */
  "PhaseTransition",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pathName */
};

static emlrtRSInfo xc_emlrtRSI = { 15, /* lineNo */
  "max",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 16, /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 140,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo bd_emlrtRSI = { 376,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 348,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo dd_emlrtRSI = { 61, /* lineNo */
  "randi",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randi.m"/* pathName */
};

static emlrtRSInfo ed_emlrtRSI = { 60, /* lineNo */
  "randi",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randi.m"/* pathName */
};

static emlrtRSInfo rd_emlrtRSI = { 5,  /* lineNo */
  "EvolveSINetworkAndCountActive",     /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetworkAndCountActive.m"/* pathName */
};

static emlrtRSInfo sd_emlrtRSI = { 10, /* lineNo */
  "EvolveSINetworkAndCountActive",     /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetworkAndCountActive.m"/* pathName */
};

static emlrtRSInfo td_emlrtRSI = { 10, /* lineNo */
  "SIElementIter",                     /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 19,    /* lineNo */
  5,                                   /* colNo */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pName */
};

static emlrtMCInfo b_emlrtMCI = { 69,  /* lineNo */
  9,                                   /* colNo */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pName */
};

static emlrtRTEInfo emlrtRTEI = { 44,  /* lineNo */
  5,                                   /* colNo */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 45,/* lineNo */
  5,                                   /* colNo */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 50,/* lineNo */
  32,                                  /* colNo */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 54,/* lineNo */
  38,                                  /* colNo */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 64,/* lineNo */
  15,                                  /* colNo */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 59,/* lineNo */
  13,                                  /* colNo */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 76,/* lineNo */
  13,                                  /* colNo */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 80,/* lineNo */
  17,                                  /* colNo */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 85,/* lineNo */
  54,                                  /* colNo */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 79,/* lineNo */
  17,                                  /* colNo */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  52,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  29,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  21,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  36,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  42,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  81,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  87,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  48,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  54,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  80,                                  /* colNo */
  "nodes(i).w",                        /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  75,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  46,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  21,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  68,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  48,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  28,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  20,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo cc_emlrtRTEI = { 3,/* lineNo */
  13,                                  /* colNo */
  "EvolveSINetworkAndCountActive",     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetworkAndCountActive.m"/* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = { 121,/* lineNo */
  27,                                  /* colNo */
  "minOrMax",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = { 39,/* lineNo */
  27,                                  /* colNo */
  "minOrMax",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pName */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  54,                                  /* colNo */
  "ThetaRange",                        /* aName */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo fc_emlrtRTEI = { 75,/* lineNo */
  17,                                  /* colNo */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pName */
};

static emlrtDCInfo b_emlrtDCI = { 64,  /* lineNo */
  28,                                  /* colNo */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 64,  /* lineNo */
  28,                                  /* colNo */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  36,                                  /* colNo */
  "ThetaRange",                        /* aName */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  9,                                   /* colNo */
  "nAct",                              /* aName */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  39,                                  /* colNo */
  "nAct",                              /* aName */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  50,                                  /* colNo */
  "nAct",                              /* aName */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  9,                                   /* colNo */
  "nAct2",                             /* aName */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  13,                                  /* colNo */
  "x0i",                               /* aName */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 77,  /* lineNo */
  13,                                  /* colNo */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  13,                                  /* colNo */
  "stimIndex",                         /* aName */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  9,                                   /* colNo */
  "n",                                 /* aName */
  "ResetNodes",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\ResetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  18,                                  /* colNo */
  "x0",                                /* aName */
  "ResetNodes",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\ResetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  9,                                   /* colNo */
  "n",                                 /* aName */
  "ResetNodes",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\ResetNodes.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  41,                                  /* colNo */
  "ThetaRange",                        /* aName */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  13,                                  /* colNo */
  "nActVec",                           /* aName */
  "PhaseTransition",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  12,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetworkAndCountActive",     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetworkAndCountActive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  80,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetworkAndCountActive",     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetworkAndCountActive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  43,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetworkAndCountActive",     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetworkAndCountActive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  48,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  81,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  36,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetworkAndCountActive",     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetworkAndCountActive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  32,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetworkAndCountActive",     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetworkAndCountActive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  23,                                  /* colNo */
  "nodes(i).w",                        /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRSInfo ud_emlrtRSI = { 19, /* lineNo */
  "PhaseTransition",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pathName */
};

static emlrtRSInfo vd_emlrtRSI = { 69, /* lineNo */
  "PhaseTransition",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\PhaseTransition.m"/* pathName */
};

/* Function Declarations */
static void FitMatrixWeights(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location, const mxArray **e, const
  mxArray **f);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void rng(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                emlrtMCInfo *location);

/* Function Definitions */
static void FitMatrixWeights(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location, const mxArray **e, const
  mxArray **f)
{
  const mxArray *pArrays[3];
  const mxArray *mv0[2];
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  emlrtAssign(e, emlrtCallMATLABR2012b(sp, 2, &mv0[0], 3, pArrays,
    "FitMatrixWeights", true, location));
  emlrtAssign(f, mv0[1]);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m4;
  real_T *pData;
  int32_T i10;
  int32_T i;
  int32_T b_i;
  y = NULL;
  m4 = emlrtCreateNumericArray(2, *(int32_T (*)[2])u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = (real_T *)emlrtMxGetPr(m4);
  i10 = 0;
  for (i = 0; i < u->size[1]; i++) {
    for (b_i = 0; b_i < u->size[0]; b_i++) {
      pData[i10] = u->data[b_i + u->size[0] * i];
      i10++;
    }
  }

  emlrtAssign(&y, m4);
  return y;
}

static void rng(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "rng", true, location);
}

void PhaseTransition(const emlrtStack *sp, const emxArray_real_T *A, const
                     emxArray_real_T *ThetaRange, real_T nSim, real_T tTotal,
                     const emxArray_real_T *x0, const emxArray_char_T *icType,
                     boolean_T useWeightSampling, emxArray_real_T *nAct,
                     emxArray_real_T *nAct2, emxArray_real_T *stimIndex,
                     emxArray_real_T *nActVec)
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 1, 7 };

  static const char_T u[7] = { 's', 'h', 'u', 'f', 'f', 'l', 'e' };

  const mxArray *b_y;
  static const int32_T iv1[2] = { 1, 7 };

  static const char_T b_u[7] = { 't', 'w', 'i', 's', 't', 'e', 'r' };

  boolean_T isFixed;
  boolean_T mostConn;
  boolean_T isAllNodes;
  emxArray_struct_T *nodes;
  int32_T i0;
  uint32_T uv0[2];
  int32_T n;
  emxArray_real_T *x0i;
  emxArray_boolean_T *b_A;
  real_T stInd;
  int32_T ixstart;
  int32_T k;
  real_T mu;
  real_T sigma;
  static const int32_T iv2[2] = { 1, 15 };

  int32_T i;
  emxArray_real_T *Asurr;
  const mxArray *b_mu = NULL;
  const mxArray *b_sigma = NULL;
  emxArray_struct_T *b_nodes;
  real_T nActSum;
  int32_T N;
  real_T nAct2Sum;
  int32_T ix;
  boolean_T exitg1;
  int32_T j;
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

  /*  A -> adjacency matrix */
  /*  ThetaRange -> 1,nTheta vector containing the threshold values for the elements */
  /*  nSim -> number of simulations for each theta in ThetaRange */
  /*  tTotal -> max number of time steps used to try to activate entire network */
  /*  x0 -> 1,N vector containing the initial condition for each of the N nodes */
  /*  icType -> 'fixed': the same node is stimulated for every theta and sim */
  /*            'mostconn': the same node (most connected) is stimulated for every theta and sim */
  /*            'random': randomly choose one seed node */
  /*            'allnodes': runs one simulation for each node */
  /*  useWeightSampling -> if true, a new weight sampling is generated for each simulation of each theta */
  /*  */
  /*  returns */
  /*  nAct -> number of activated sites for each theta in ThetaRange */
  /*  nAct2 -> variance of nAct */
  y = NULL;
  m0 = emlrtCreateCharArray(2, iv0);
  emlrtInitCharArrayR2013a(sp, 7, m0, &u[0]);
  emlrtAssign(&y, m0);
  b_y = NULL;
  m0 = emlrtCreateCharArray(2, iv1);
  emlrtInitCharArrayR2013a(sp, 7, m0, &b_u[0]);
  emlrtAssign(&b_y, m0);
  st.site = &ud_emlrtRSI;
  rng(&st, y, b_y, (emlrtMCInfo *)&emlrtMCI);
  isFixed = false;
  mostConn = false;
  isAllNodes = false;
  st.site = &emlrtRSI;
  if (b_strcmp(&st, icType)) {
    isFixed = true;
  }

  st.site = &b_emlrtRSI;
  if (c_strcmp(&st, icType)) {
    isFixed = true;
    mostConn = true;
  }

  st.site = &c_emlrtRSI;
  if (d_strcmp(&st, icType)) {
    isFixed = true;
    mostConn = false;
    isAllNodes = true;
  }

  st.site = &d_emlrtRSI;
  if (e_strcmp(&st, icType)) {
    isFixed = false;
  }

  emxInit_struct_T(sp, &nodes, 2, &j_emlrtRTEI, true);
  i0 = ThetaRange->size[1];
  if (!(1 <= i0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, (emlrtBCInfo *)&t_emlrtBCI, sp);
  }

  st.site = &e_emlrtRSI;
  GetNodes(&st, A, ThetaRange->data[0], x0, nodes);
  for (i0 = 0; i0 < 2; i0++) {
    uv0[i0] = (uint32_T)ThetaRange->size[i0];
  }

  i0 = nAct->size[0] * nAct->size[1];
  nAct->size[0] = 1;
  nAct->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity_real_T(sp, nAct, i0, &emlrtRTEI);
  n = (int32_T)uv0[1];
  for (i0 = 0; i0 < n; i0++) {
    nAct->data[i0] = 0.0;
  }

  for (i0 = 0; i0 < 2; i0++) {
    uv0[i0] = (uint32_T)ThetaRange->size[i0];
  }

  i0 = nAct2->size[0] * nAct2->size[1];
  nAct2->size[0] = 1;
  nAct2->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity_real_T(sp, nAct2, i0, &b_emlrtRTEI);
  n = (int32_T)uv0[1];
  for (i0 = 0; i0 < n; i0++) {
    nAct2->data[i0] = 0.0;
  }

  emxInit_real_T1(sp, &x0i, 2, &g_emlrtRTEI, true);
  if (isFixed) {
    if (isAllNodes) {
      if (nodes->size[1] < 1) {
        i0 = x0i->size[0] * x0i->size[1];
        x0i->size[0] = 1;
        x0i->size[1] = 0;
        emxEnsureCapacity_real_T(sp, x0i, i0, &c_emlrtRTEI);
      } else {
        i0 = nodes->size[1];
        ixstart = x0i->size[0] * x0i->size[1];
        x0i->size[0] = 1;
        x0i->size[1] = (int32_T)((real_T)i0 - 1.0) + 1;
        emxEnsureCapacity_real_T(sp, x0i, ixstart, &c_emlrtRTEI);
        n = (int32_T)((real_T)i0 - 1.0);
        for (i0 = 0; i0 <= n; i0++) {
          x0i->data[x0i->size[0] * i0] = 1.0 + (real_T)i0;
        }
      }

      st.site = &f_emlrtRSI;
      repmat(&st, x0i, (real_T)ThetaRange->size[1], stimIndex);
      nSim = nodes->size[1];
    } else {
      if (mostConn) {
        emxInit_boolean_T(sp, &b_A, 2, &d_emlrtRTEI, true);
        i0 = b_A->size[0] * b_A->size[1];
        b_A->size[0] = A->size[0];
        b_A->size[1] = A->size[1];
        emxEnsureCapacity_boolean_T(sp, b_A, i0, &d_emlrtRTEI);
        n = A->size[0] * A->size[1];
        for (i0 = 0; i0 < n; i0++) {
          b_A->data[i0] = (A->data[i0] != 0.0);
        }

        st.site = &g_emlrtRSI;
        sum(&st, b_A, x0i);
        st.site = &g_emlrtRSI;
        b_st.site = &xc_emlrtRSI;
        c_st.site = &yc_emlrtRSI;
        emxFree_boolean_T(&b_A);
        if ((x0i->size[1] == 1) || (x0i->size[1] != 1)) {
          isFixed = true;
        } else {
          isFixed = false;
        }

        if (!isFixed) {
          emlrtErrorWithMessageIdR2012b(&c_st, &ec_emlrtRTEI,
            "Coder:toolbox:autoDimIncompatibility", 0);
        }

        if (!(x0i->size[1] > 0)) {
          emlrtErrorWithMessageIdR2012b(&c_st, &dc_emlrtRTEI,
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
        }

        d_st.site = &ad_emlrtRSI;
        ixstart = 1;
        n = x0i->size[1];
        stInd = x0i->data[0];
        N = 1;
        if (x0i->size[1] > 1) {
          if (muDoubleScalarIsNaN(x0i->data[0])) {
            e_st.site = &cd_emlrtRSI;
            isFixed = (x0i->size[1] > 2147483646);
            if (isFixed) {
              f_st.site = &gb_emlrtRSI;
              g_st.site = &gb_emlrtRSI;
              check_forloop_overflow_error(&g_st);
            }

            ix = 2;
            exitg1 = false;
            while ((!exitg1) && (ix <= n)) {
              ixstart = ix;
              if (!muDoubleScalarIsNaN(x0i->data[ix - 1])) {
                stInd = x0i->data[ix - 1];
                N = ix;
                exitg1 = true;
              } else {
                ix++;
              }
            }
          }

          if (ixstart < x0i->size[1]) {
            e_st.site = &bd_emlrtRSI;
            isFixed = ((!(ixstart + 1 > x0i->size[1])) && (x0i->size[1] >
                        2147483646));
            if (isFixed) {
              f_st.site = &gb_emlrtRSI;
              g_st.site = &gb_emlrtRSI;
              check_forloop_overflow_error(&g_st);
            }

            while (ixstart + 1 <= n) {
              if (x0i->data[ixstart] > stInd) {
                stInd = x0i->data[ixstart];
                N = ixstart + 1;
              }

              ixstart++;
            }
          }
        }

        stInd = N;
      } else {
        st.site = &h_emlrtRSI;
        b_st.site = &dd_emlrtRSI;
        stInd = b_rand();
        stInd = 1.0 + muDoubleScalarFloor(stInd * (real_T)x0->size[1]);
      }

      st.site = &i_emlrtRSI;
      b_st.site = &db_emlrtRSI;
      b_assertValidSizeArg(&b_st, (real_T)ThetaRange->size[1], nSim);
      if (!(nSim >= 0.0)) {
        emlrtNonNegativeCheckR2012b(nSim, (emlrtDCInfo *)&emlrtDCI, &st);
      }

      ixstart = ThetaRange->size[1];
      n = ThetaRange->size[1];
      if (ixstart != n) {
        y = NULL;
        m0 = emlrtCreateCharArray(2, iv2);
        emlrtInitCharArrayR2013a(&st, 15, m0, &cv0[0]);
        emlrtAssign(&y, m0);
        b_st.site = &wd_emlrtRSI;
        error(&b_st, y, (emlrtMCInfo *)&c_emlrtMCI);
      }

      i0 = stimIndex->size[0] * stimIndex->size[1];
      stimIndex->size[0] = ixstart;
      stimIndex->size[1] = (int32_T)nSim;
      emxEnsureCapacity_real_T(&st, stimIndex, i0, &f_emlrtRTEI);
      n = ixstart * (int32_T)nSim;
      for (i0 = 0; i0 < n; i0++) {
        stimIndex->data[i0] = stInd;
      }
    }
  } else {
    st.site = &j_emlrtRSI;
    b_st.site = &ed_emlrtRSI;
    b_assertValidSizeArg(&b_st, (real_T)ThetaRange->size[1], nSim);
    b_st.site = &dd_emlrtRSI;
    c_rand(&b_st, (real_T)ThetaRange->size[1], nSim, stimIndex);
    i0 = stimIndex->size[0] * stimIndex->size[1];
    for (k = 0; k < i0; k++) {
      stimIndex->data[k] = 1.0 + muDoubleScalarFloor(stimIndex->data[k] *
        (real_T)x0->size[1]);
    }
  }

  if (!(nSim >= 0.0)) {
    emlrtNonNegativeCheckR2012b(nSim, (emlrtDCInfo *)&c_emlrtDCI, sp);
  }

  if (nSim != (int32_T)muDoubleScalarFloor(nSim)) {
    emlrtIntegerCheckR2012b(nSim, (emlrtDCInfo *)&b_emlrtDCI, sp);
  }

  mu = 0.0;
  sigma = 0.0;
  if (useWeightSampling) {
    y = NULL;
    m0 = emlrtCreateDoubleScalar(100.0);
    emlrtAssign(&y, m0);
    b_y = NULL;
    m0 = emlrtCreateLogicalScalar(false);
    emlrtAssign(&b_y, m0);
    st.site = &vd_emlrtRSI;
    FitMatrixWeights(&st, emlrt_marshallOut(A), y, b_y, (emlrtMCInfo *)
                     &b_emlrtMCI, &b_mu, &b_sigma);
    st.site = &vd_emlrtRSI;
    mu = emlrt_marshallIn(&st, emlrtAlias(b_mu), "mu");
    st.site = &vd_emlrtRSI;
    sigma = emlrt_marshallIn(&st, emlrtAlias(b_sigma), "sigma");
  }

  i0 = nActVec->size[0] * nActVec->size[1];
  nActVec->size[0] = ThetaRange->size[1];
  nActVec->size[1] = (int32_T)nSim;
  emxEnsureCapacity_real_T(sp, nActVec, i0, &e_emlrtRTEI);
  i = 1;
  emxInit_real_T1(sp, &Asurr, 2, &k_emlrtRTEI, true);
  emxInit_struct_T(sp, &b_nodes, 2, &i_emlrtRTEI, true);
  while (i - 1 <= ThetaRange->size[1] - 1) {
    nActSum = 0.0;
    nAct2Sum = 0.0;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, nSim, mxDOUBLE_CLASS, (int32_T)nSim,
      (emlrtRTEInfo *)&fc_emlrtRTEI, sp);
    k = 1;
    while (k - 1 <= (int32_T)nSim - 1) {
      i0 = x0i->size[0] * x0i->size[1];
      x0i->size[0] = 1;
      x0i->size[1] = x0->size[1];
      emxEnsureCapacity_real_T(sp, x0i, i0, &g_emlrtRTEI);
      n = x0->size[0] * x0->size[1];
      for (i0 = 0; i0 < n; i0++) {
        x0i->data[i0] = x0->data[i0];
      }

      i0 = x0->size[1];
      ixstart = stimIndex->size[0];
      if (!((i >= 1) && (i <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, ixstart, (emlrtBCInfo *)&ab_emlrtBCI,
          sp);
      }

      ixstart = stimIndex->size[1];
      if (!((k >= 1) && (k <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, ixstart, (emlrtBCInfo *)&ab_emlrtBCI,
          sp);
      }

      stInd = stimIndex->data[(i + stimIndex->size[0] * (k - 1)) - 1];
      if (stInd != (int32_T)muDoubleScalarFloor(stInd)) {
        emlrtIntegerCheckR2012b(stInd, (emlrtDCInfo *)&d_emlrtDCI, sp);
      }

      ixstart = (int32_T)stInd;
      if (!((ixstart >= 1) && (ixstart <= i0))) {
        emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)&y_emlrtBCI,
          sp);
      }

      x0i->data[ixstart - 1] = 1.0;
      if (useWeightSampling) {
        /*  avoids "Subscripting into an mxArray is not supported" error https://www.mathworks.com/matlabcentral/answers/122167-subscripting-into-an-mxarray-is-not-supported */
        i0 = Asurr->size[0] * Asurr->size[1];
        Asurr->size[0] = A->size[0];
        Asurr->size[1] = A->size[1];
        emxEnsureCapacity_real_T(sp, Asurr, i0, &h_emlrtRTEI);
        n = A->size[0] * A->size[1];
        for (i0 = 0; i0 < n; i0++) {
          Asurr->data[i0] = A->data[i0];
        }

        st.site = &k_emlrtRSI;
        GetSurrogateRandomMatrix(&st, Asurr, mu, sigma);
        i0 = ThetaRange->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&eb_emlrtBCI,
            sp);
        }

        st.site = &l_emlrtRSI;
        GetNodes(&st, Asurr, ThetaRange->data[i - 1], x0i, nodes);
      } else {
        st.site = &m_emlrtRSI;
        i0 = ThetaRange->size[1];
        ixstart = (i - 1) + 1;
        if (!((ixstart >= 1) && (ixstart <= i0))) {
          emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
            &s_emlrtBCI, &st);
        }

        i0 = nodes->size[1];
        n = 1;
        while (n - 1 <= i0 - 1) {
          ixstart = nodes->size[1];
          if (!((n >= 1) && (n <= ixstart))) {
            emlrtDynamicBoundsCheckR2012b(n, 1, ixstart, (emlrtBCInfo *)
              &bb_emlrtBCI, &st);
          }

          nodes->data[n - 1].par.Theta = ThetaRange->data[i - 1];
          ixstart = x0i->size[1];
          if (!((n >= 1) && (n <= ixstart))) {
            emlrtDynamicBoundsCheckR2012b(n, 1, ixstart, (emlrtBCInfo *)
              &cb_emlrtBCI, &st);
          }

          ixstart = nodes->size[1];
          if (!((n >= 1) && (n <= ixstart))) {
            emlrtDynamicBoundsCheckR2012b(n, 1, ixstart, (emlrtBCInfo *)
              &db_emlrtBCI, &st);
          }

          nodes->data[n - 1].x = x0i->data[n - 1];
          n++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&st);
          }
        }
      }

      st.site = &n_emlrtRSI;
      i0 = b_nodes->size[0] * b_nodes->size[1];
      b_nodes->size[0] = 1;
      b_nodes->size[1] = nodes->size[1];
      emxEnsureCapacity_struct_T(&st, b_nodes, i0, &i_emlrtRTEI);
      n = nodes->size[0] * nodes->size[1];
      for (i0 = 0; i0 < n; i0++) {
        emxCopyStruct_struct_T(&st, &b_nodes->data[i0], &nodes->data[i0],
          &i_emlrtRTEI);
      }

      N = nodes->size[1] - 1;
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, tTotal, mxDOUBLE_CLASS, (int32_T)
        tTotal, (emlrtRTEInfo *)&cc_emlrtRTEI, &st);
      ix = 0;
      exitg1 = false;
      while ((!exitg1) && (ix <= (int32_T)tTotal - 1)) {
        n = 0;
        while (n <= N) {
          b_st.site = &rd_emlrtRSI;
          stInd = 0.0;

          /* spTime = 0.0; nAct = 0; spTimePrev = 0.0; */
          i0 = b_nodes->size[1];
          ixstart = n + 1;
          if (!((ixstart >= 1) && (ixstart <= i0))) {
            emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
              &c_emlrtBCI, &b_st);
          }

          j = 1;
          while (j - 1 <= (int32_T)b_nodes->data[n].par.n - 1) {
            i0 = b_nodes->size[1];
            ixstart = n + 1;
            if (!((ixstart >= 1) && (ixstart <= i0))) {
              emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                &b_emlrtBCI, &b_st);
            }

            i0 = b_nodes->size[1];
            ixstart = n + 1;
            if (!((ixstart >= 1) && (ixstart <= i0))) {
              emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                &emlrtBCI, &b_st);
            }

            i0 = b_nodes->data[n].w->size[0];
            if (!((j >= 1) && (j <= i0))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i0, (emlrtBCInfo *)
                &rb_emlrtBCI, &b_st);
            }

            i0 = b_nodes->size[1];
            ixstart = b_nodes->data[n].neigh->size[0];
            if (!((j >= 1) && (j <= ixstart))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, ixstart, (emlrtBCInfo *)
                &tb_emlrtBCI, &b_st);
            }

            ixstart = (int32_T)b_nodes->data[n].neigh->data[j - 1];
            if (!((ixstart >= 1) && (ixstart <= i0))) {
              emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                &sb_emlrtBCI, &b_st);
            }

            stInd += b_nodes->data[n].w->data[j - 1] * b_nodes->data[ixstart - 1]
              .x;
            j++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(&b_st);
            }
          }

          i0 = b_nodes->size[1];
          ixstart = 1 + n;
          if (!((ixstart >= 1) && (ixstart <= i0))) {
            emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
              &pb_emlrtBCI, &st);
          }

          b_nodes->data[ixstart - 1].par.Isyn = stInd;
          i0 = b_nodes->size[1];
          ixstart = 1 + n;
          if (!((ixstart >= 1) && (ixstart <= i0))) {
            emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
              &qb_emlrtBCI, &st);
          }

          b_nodes->data[ixstart - 1].par.kInp = 1.0;
          n++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&st);
          }
        }

        /* isNetActive = nodes(1).x > 0; */
        isFixed = true;
        n = 0;
        while (n <= N) {
          b_st.site = &sd_emlrtRSI;

          /* (x, par) */
          /*      if (par.Iext + par.Isyn / par.W) > par.Theta */
          /*          x = 1; */
          /*          spTime = calcSpTime(i,nodes); */
          /*      end */
          i0 = b_nodes->size[1];
          ixstart = 1 + n;
          if (!(ixstart <= i0)) {
            emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
              &hb_emlrtBCI, &b_st);
          }

          stInd = b_nodes->data[ixstart - 1].x;
          i0 = b_nodes->size[1];
          ixstart = 1 + n;
          if (!(ixstart <= i0)) {
            emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
              &r_emlrtBCI, &b_st);
          }

          if (b_nodes->data[n].x == 0.0) {
            i0 = b_nodes->size[1];
            ixstart = 1 + n;
            if (!(ixstart <= i0)) {
              emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                &q_emlrtBCI, &b_st);
            }

            i0 = b_nodes->size[1];
            ixstart = 1 + n;
            if (!(ixstart <= i0)) {
              emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                &p_emlrtBCI, &b_st);
            }

            i0 = b_nodes->size[1];
            ixstart = 1 + n;
            if (!(ixstart <= i0)) {
              emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                &o_emlrtBCI, &b_st);
            }

            i0 = b_nodes->size[1];
            ixstart = 1 + n;
            if (!(ixstart <= i0)) {
              emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                &ib_emlrtBCI, &b_st);
            }

            if (b_nodes->data[n].par.Isyn / b_nodes->data[n].par.W >
                b_nodes->data[ixstart - 1].par.Theta) {
              stInd = 1.0;
              c_st.site = &td_emlrtRSI;
              i0 = b_nodes->size[1];
              ixstart = 1 + n;
              if (!(ixstart <= i0)) {
                emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                  &n_emlrtBCI, &c_st);
              }

              j = 1;
              while (j - 1 <= (int32_T)b_nodes->data[n].par.n - 1) {
                i0 = b_nodes->size[1];
                ixstart = 1 + n;
                if (!(ixstart <= i0)) {
                  emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                    &m_emlrtBCI, &c_st);
                }

                i0 = b_nodes->size[1];
                ixstart = 1 + n;
                if (!(ixstart <= i0)) {
                  emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                    &k_emlrtBCI, &c_st);
                }

                i0 = b_nodes->size[1];
                ixstart = b_nodes->data[n].neigh->size[0];
                if (!((j >= 1) && (j <= ixstart))) {
                  emlrtDynamicBoundsCheckR2012b(j, 1, ixstart, (emlrtBCInfo *)
                    &lb_emlrtBCI, &c_st);
                }

                ixstart = (int32_T)b_nodes->data[n].neigh->data[j - 1];
                if (!((ixstart >= 1) && (ixstart <= i0))) {
                  emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                    &l_emlrtBCI, &c_st);
                }

                i0 = b_nodes->data[n].w->size[0];
                ixstart = (j - 1) + 1;
                if (!((ixstart >= 1) && (ixstart <= i0))) {
                  emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                    &j_emlrtBCI, &c_st);
                }

                /*  summing up the inverse weights (sp times) of active neighbors to reach i */
                i0 = b_nodes->size[1];
                ixstart = 1 + n;
                if (!(ixstart <= i0)) {
                  emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                    &i_emlrtBCI, &c_st);
                }

                i0 = b_nodes->size[1];
                ixstart = 1 + n;
                if (!(ixstart <= i0)) {
                  emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                    &g_emlrtBCI, &c_st);
                }

                i0 = b_nodes->size[1];
                ixstart = b_nodes->data[n].neigh->size[0];
                if (!((j >= 1) && (j <= ixstart))) {
                  emlrtDynamicBoundsCheckR2012b(j, 1, ixstart, (emlrtBCInfo *)
                    &mb_emlrtBCI, &c_st);
                }

                ixstart = (int32_T)b_nodes->data[n].neigh->data[j - 1];
                if (!((ixstart >= 1) && (ixstart <= i0))) {
                  emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                    &h_emlrtBCI, &c_st);
                }

                i0 = b_nodes->size[1];
                ixstart = b_nodes->data[n].neigh->size[0];
                if (!((j >= 1) && (j <= ixstart))) {
                  emlrtDynamicBoundsCheckR2012b(j, 1, ixstart, (emlrtBCInfo *)
                    &nb_emlrtBCI, &c_st);
                }

                ixstart = (int32_T)b_nodes->data[n].neigh->data[j - 1];
                if (!((ixstart >= 1) && (ixstart <= i0))) {
                  emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                    &f_emlrtBCI, &c_st);
                }

                /*  summing up the sp time to reach each of the active neighbors */
                i0 = b_nodes->size[1];
                ixstart = 1 + n;
                if (!(ixstart <= i0)) {
                  emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                    &e_emlrtBCI, &c_st);
                }

                i0 = b_nodes->size[1];
                ixstart = b_nodes->data[n].neigh->size[0];
                if (!((j >= 1) && (j <= ixstart))) {
                  emlrtDynamicBoundsCheckR2012b(j, 1, ixstart, (emlrtBCInfo *)
                    &ob_emlrtBCI, &c_st);
                }

                ixstart = (int32_T)b_nodes->data[n].neigh->data[j - 1];
                if (!((ixstart >= 1) && (ixstart <= i0))) {
                  emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                    &d_emlrtBCI, &c_st);
                }

                /*  x is either 0 or 1, so nAct is the total amount of active neighbors of i */
                j++;
                if (*emlrtBreakCheckR2012bFlagVar != 0) {
                  emlrtBreakCheckR2012b(&c_st);
                }
              }
            }
          }

          i0 = b_nodes->size[1];
          ixstart = 1 + n;
          if (!(ixstart <= i0)) {
            emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
              &jb_emlrtBCI, &st);
          }

          b_nodes->data[ixstart - 1].x = stInd;

          /* SIElementIter(nodes(i).x, nodes(i).par); */
          if (isFixed) {
            i0 = b_nodes->size[1];
            ixstart = 1 + n;
            if (!(ixstart <= i0)) {
              emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, (emlrtBCInfo *)
                &kb_emlrtBCI, &st);
            }

            if (b_nodes->data[ixstart - 1].x > 0.0) {
              isFixed = true;
            } else {
              isFixed = false;
            }
          } else {
            isFixed = false;
          }

          n++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&st);
          }
        }

        if (isFixed) {
          exitg1 = true;
        } else {
          ix++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&st);
          }
        }
      }

      stInd = 0.0;
      n = 0;
      while (n <= N) {
        i0 = b_nodes->size[1];
        if (!((n + 1 >= 1) && (n + 1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(n + 1, 1, i0, (emlrtBCInfo *)
            &gb_emlrtBCI, &st);
        }

        if (b_nodes->data[n].x > 0.0) {
          stInd++;
        }

        n++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      i0 = nActVec->size[0];
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&fb_emlrtBCI, sp);
      }

      i0 = nActVec->size[1];
      if (!((k >= 1) && (k <= i0))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i0, (emlrtBCInfo *)&fb_emlrtBCI, sp);
      }

      nActVec->data[(i + nActVec->size[0] * (k - 1)) - 1] = stInd;
      nActSum += stInd;
      nAct2Sum += stInd * stInd;
      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    i0 = nAct->size[1];
    if (!((i >= 1) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&u_emlrtBCI, sp);
    }

    nAct->data[i - 1] = nActSum / nSim;
    i0 = nAct->size[1];
    if (!((i >= 1) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&v_emlrtBCI, sp);
    }

    i0 = nAct->size[1];
    if (!((i >= 1) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&w_emlrtBCI, sp);
    }

    i0 = nAct2->size[1];
    if (!((i >= 1) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    nAct2->data[i - 1] = nAct2Sum / nSim - nAct->data[i - 1] * nAct->data[i - 1];

    /*          if rho2(i) < 0.0 */
    /*              rho2(i) = 0.0; */
    /*          end */
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_struct_T(&b_nodes);
  emxFree_real_T(&Asurr);
  emxFree_real_T(&x0i);
  emxFree_struct_T(&nodes);

  /*  function nn = EvolveSINetworkAndCountActive(nodes, tTotal) */
  /*      N = numel(nodes); */
  /*      for t = 1:tTotal */
  /*          for i = 1:N */
  /*              nodes(i).par.Isyn = UpdateInput(i, nodes); */
  /*          end */
  /*          isNetActive = nodes(1).x > 0; */
  /*          for i = 1:N */
  /*              nodes(i).x = SIElementIter(nodes(i).x, nodes(i).par); */
  /*              isNetActive = isNetActive && (nodes(i).x > 0); */
  /*          end */
  /*          if isNetActive */
  /*              break; */
  /*          end */
  /*      end */
  /*      nn = 0; */
  /*      for i = 1:N */
  /*          if nodes(i).x > 0 */
  /*              nn = nn + 1; */
  /*          end */
  /*      end */
  /*  end */
  emlrtDestroyArray(&b_mu);
  emlrtDestroyArray(&b_sigma);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (PhaseTransition.cpp) */
