/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvolveSINetwork.cpp
 *
 * Code generation for function 'EvolveSINetwork'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EvolveSINetwork.h"
#include "EvolveSINetwork_emxutil.h"
#include "error.h"
#include "UpdateInputNSeed.h"
#include "calcSpTime.h"
#include "UpdateInput1Seed.h"
#include "EvolveSINetwork_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 6,     /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 8,   /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 12,  /* lineNo */
  "toLogicalCheck",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 13,  /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 14,  /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 16,  /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 68,  /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 57,  /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 52,  /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 37,  /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 6,   /* lineNo */
  "SINElementIter",                    /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 10,  /* lineNo */
  "SIElementIter",                     /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 12,  /* lineNo */
  42,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 16,/* lineNo */
  62,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 14,/* lineNo */
  62,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 41,/* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 38,/* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 42,/* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 39,/* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 16,/* lineNo */
  10,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 52,/* lineNo */
  68,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 16,/* lineNo */
  31,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 70,/* lineNo */
  17,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 70,/* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 71,/* lineNo */
  18,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 71,/* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  68,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  48,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo u_emlrtRTEI = { 50,/* lineNo */
  13,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  15,                                  /* colNo */
  "xData",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  23,                                  /* colNo */
  "xData",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  25,                                  /* colNo */
  "xData",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  16,                                  /* colNo */
  "spTime",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  25,                                  /* colNo */
  "spTime",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  27,                                  /* colNo */
  "spTime",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 38,  /* lineNo */
  23,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 38,  /* lineNo */
  23,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 39,  /* lineNo */
  24,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 39,  /* lineNo */
  24,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2,                                   /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  22,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  80,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  13,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  25,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  35,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  13,                                  /* colNo */
  "xData",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  36,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  13,                                  /* colNo */
  "spTime",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  47,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  32,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  22,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  9,                                   /* colNo */
  "xData",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  23,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  9,                                   /* colNo */
  "spTime",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  47,                                  /* colNo */
  "par.x0",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 34,  /* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  9,                                   /* colNo */
  "par.seeds",                         /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 38,  /* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 38,  /* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 39,  /* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 39,  /* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  68,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  48,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  22,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  80,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

/* Function Declarations */
static void EvolveSINetwork_internal(const emlrtStack *sp, const
  emxArray_struct0_T *nodes, real_T tTotal, struct2_T *par, real_T
  returnTimeEvol, emxArray_real_T *xData, real_T *netActTime, emxArray_real_T
  *spTime);
static void b_EvolveSINetwork_internal(const emlrtStack *sp, const
  emxArray_struct0_T *nodes, real_T tTotal, struct2_T *par, real_T
  returnTimeEvol, emxArray_real_T *xData, real_T *netActTime, emxArray_real_T
  *spTime);

/* Function Definitions */
static void EvolveSINetwork_internal(const emlrtStack *sp, const
  emxArray_struct0_T *nodes, real_T tTotal, struct2_T *par, real_T
  returnTimeEvol, emxArray_real_T *xData, real_T *netActTime, emxArray_real_T
  *spTime)
{
  emxArray_struct0_T *b_nodes;
  emxArray_struct0_T *c_nodes;
  int32_T i13;
  int32_T loop_ub;
  int32_T N;
  int32_T i;
  emxArray_real_T *b_xData;
  int32_T i14;
  real_T d3;
  int32_T t;
  emxArray_real_T *b_spTime;
  real_T b_t;
  boolean_T exitg1;
  boolean_T isFullyActive;
  emxArray_real_T *c_xData;
  real_T d4;
  real_T d5;
  real_T d6;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &d_emlrtRSI;
  if (muDoubleScalarIsNaN(returnTimeEvol)) {
    b_st.site = &c_emlrtRSI;
    c_st.site = &c_emlrtRSI;
    error(&c_st);
  }

  emxInit_struct0_T(sp, &b_nodes, 2, &c_emlrtRTEI, true);
  emxInit_struct0_T(sp, &c_nodes, 2, &j_emlrtRTEI, true);
  if (returnTimeEvol != 0.0) {
    st.site = &e_emlrtRSI;
    i13 = b_nodes->size[0] * b_nodes->size[1];
    b_nodes->size[0] = 1;
    b_nodes->size[1] = nodes->size[1];
    emxEnsureCapacity_struct0_T(&st, b_nodes, i13, &d_emlrtRTEI);
    loop_ub = nodes->size[0] * nodes->size[1];
    for (i13 = 0; i13 < loop_ub; i13++) {
      emxCopyStruct_struct0_T(&st, &b_nodes->data[i13], &nodes->data[i13],
        &d_emlrtRTEI);
    }

    N = b_nodes->size[1];
    if (par->seedTrial > par->seeds->size[0]) {
      par->seedTrial = 1.0;
    }

    i = 1;
    while (i - 1 <= par->seeds->size[1] - 1) {
      i13 = par->x0->size[1];
      if (!((i >= 1) && (i <= i13))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&ec_emlrtBCI,
          &st);
      }

      i13 = b_nodes->size[1];
      i14 = par->seeds->size[0];
      d3 = par->seedTrial;
      if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
        emlrtIntegerCheckR2012b(d3, (emlrtDCInfo *)&k_emlrtDCI, &st);
      }

      t = (int32_T)d3;
      if (!((t >= 1) && (t <= i14))) {
        emlrtDynamicBoundsCheckR2012b(t, 1, i14, (emlrtBCInfo *)&gc_emlrtBCI,
          &st);
      }

      i14 = par->seeds->size[1];
      if (!((i >= 1) && (i <= i14))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i14, (emlrtBCInfo *)&gc_emlrtBCI,
          &st);
      }

      d3 = par->seeds->data[(t + par->seeds->size[0] * (i - 1)) - 1];
      if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
        emlrtIntegerCheckR2012b(d3, (emlrtDCInfo *)&k_emlrtDCI, &st);
      }

      i14 = (int32_T)d3;
      if (!((i14 >= 1) && (i14 <= i13))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, i13, (emlrtBCInfo *)&fc_emlrtBCI,
          &st);
      }

      b_nodes->data[i14 - 1].x = par->x0->data[i - 1];
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    par->seedTrial++;

    /*  increasing seedTrial for next simulation run (if any) */
    b_st.site = &j_emlrtRSI;
    if (muDoubleScalarIsNaN(returnTimeEvol)) {
      c_st.site = &c_emlrtRSI;
      d_st.site = &c_emlrtRSI;
      error(&d_st);
    }

    if (returnTimeEvol != 0.0) {
      i13 = xData->size[0] * xData->size[1];
      if (!(tTotal + 1.0 >= 0.0)) {
        emlrtNonNegativeCheckR2012b(tTotal + 1.0, (emlrtDCInfo *)&h_emlrtDCI,
          &st);
      }

      d3 = tTotal + 1.0;
      if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
        emlrtIntegerCheckR2012b(d3, (emlrtDCInfo *)&g_emlrtDCI, &st);
      }

      xData->size[0] = (int32_T)d3;
      xData->size[1] = N;
      emxEnsureCapacity_real_T(&st, xData, i13, &f_emlrtRTEI);
      if (!(tTotal + 1.0 >= 0.0)) {
        emlrtNonNegativeCheckR2012b(tTotal + 1.0, (emlrtDCInfo *)&m_emlrtDCI,
          &st);
      }

      d3 = tTotal + 1.0;
      if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
        emlrtIntegerCheckR2012b(d3, (emlrtDCInfo *)&l_emlrtDCI, &st);
      }

      loop_ub = (int32_T)d3 * N;
      for (i13 = 0; i13 < loop_ub; i13++) {
        xData->data[i13] = 0.0;
      }

      i13 = spTime->size[0] * spTime->size[1];
      if (!(tTotal + 1.0 >= 0.0)) {
        emlrtNonNegativeCheckR2012b(tTotal + 1.0, (emlrtDCInfo *)&j_emlrtDCI,
          &st);
      }

      d3 = tTotal + 1.0;
      if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
        emlrtIntegerCheckR2012b(d3, (emlrtDCInfo *)&i_emlrtDCI, &st);
      }

      spTime->size[0] = (int32_T)d3;
      spTime->size[1] = N;
      emxEnsureCapacity_real_T(&st, spTime, i13, &h_emlrtRTEI);
      if (!(tTotal + 1.0 >= 0.0)) {
        emlrtNonNegativeCheckR2012b(tTotal + 1.0, (emlrtDCInfo *)&o_emlrtDCI,
          &st);
      }

      d3 = tTotal + 1.0;
      if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
        emlrtIntegerCheckR2012b(d3, (emlrtDCInfo *)&n_emlrtDCI, &st);
      }

      loop_ub = (int32_T)d3 * N;
      for (i13 = 0; i13 < loop_ub; i13++) {
        spTime->data[i13] = 0.0;
      }
    } else {
      i13 = xData->size[0] * xData->size[1];
      xData->size[0] = 1;
      xData->size[1] = N;
      emxEnsureCapacity_real_T(&st, xData, i13, &e_emlrtRTEI);
      for (i13 = 0; i13 < N; i13++) {
        xData->data[i13] = 0.0;
      }

      i13 = spTime->size[0] * spTime->size[1];
      spTime->size[0] = 1;
      spTime->size[1] = N;
      emxEnsureCapacity_real_T(&st, spTime, i13, &g_emlrtRTEI);
      for (i13 = 0; i13 < N; i13++) {
        spTime->data[i13] = 0.0;
      }
    }

    i = 1;
    while (i - 1 <= N - 1) {
      i13 = xData->size[0];
      if (!(1 <= i13)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i13, (emlrtBCInfo *)&fb_emlrtBCI,
          &st);
      }

      i13 = b_nodes->size[1];
      if (!((i >= 1) && (i <= i13))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&ac_emlrtBCI,
          &st);
      }

      i13 = xData->size[1];
      if (!((i >= 1) && (i <= i13))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&bc_emlrtBCI,
          &st);
      }

      xData->data[xData->size[0] * (i - 1)] = b_nodes->data[i - 1].x;
      i13 = spTime->size[0];
      if (!(1 <= i13)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i13, (emlrtBCInfo *)&ib_emlrtBCI,
          &st);
      }

      i13 = b_nodes->size[1];
      if (!((i >= 1) && (i <= i13))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&cc_emlrtBCI,
          &st);
      }

      i13 = spTime->size[1];
      if (!((i >= 1) && (i <= i13))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&dc_emlrtBCI,
          &st);
      }

      spTime->data[spTime->size[0] * (i - 1)] = b_nodes->data[i - 1].par.spTime;
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emlrtForLoopVectorCheckR2012b(2.0, 1.0, tTotal + 1.0, mxDOUBLE_CLASS,
      (int32_T)((tTotal + 1.0) + -1.0), (emlrtRTEInfo *)&u_emlrtRTEI, &st);
    b_t = 2.0;
    t = 0;
    exitg1 = false;
    while ((!exitg1) && (t <= (int32_T)((tTotal + 1.0) + -1.0) - 1)) {
      b_t = 2.0 + (real_T)t;
      i = 0;
      while (i <= N - 1) {
        i13 = c_nodes->size[0] * c_nodes->size[1];
        c_nodes->size[0] = 1;
        c_nodes->size[1] = b_nodes->size[1];
        emxEnsureCapacity_struct0_T(&st, c_nodes, i13, &j_emlrtRTEI);
        loop_ub = b_nodes->size[0] * b_nodes->size[1];
        for (i13 = 0; i13 < loop_ub; i13++) {
          emxCopyStruct_struct0_T(&st, &c_nodes->data[i13], &b_nodes->data[i13],
            &j_emlrtRTEI);
        }

        i13 = b_nodes->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i13, (emlrtBCInfo *)
            &xb_emlrtBCI, &st);
        }

        b_st.site = &i_emlrtRSI;
        UpdateInputNSeed(&b_st, 1.0 + (real_T)i, c_nodes, &d5, &d3);
        b_nodes->data[i].par.Isyn = d5;
        i13 = b_nodes->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i13, (emlrtBCInfo *)
            &yb_emlrtBCI, &st);
        }

        b_nodes->data[i].par.kInp = d3;
        i++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      /* isFullyActive = nodes(1).x > 0; */
      isFullyActive = true;
      i = 1;
      while (i - 1 <= N - 1) {
        b_st.site = &h_emlrtRSI;

        /* (x, par) */
        i13 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&lb_emlrtBCI,
            &b_st);
        }

        d3 = b_nodes->data[i - 1].x;
        i13 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&mb_emlrtBCI,
            &b_st);
        }

        d6 = b_nodes->data[i - 1].par.spTime;
        if (b_nodes->data[i - 1].x == 0.0) {
          i13 = b_nodes->size[1];
          i14 = (i - 1) + 1;
          if (!((i14 >= 1) && (i14 <= i13))) {
            emlrtDynamicBoundsCheckR2012b(i14, 1, i13, (emlrtBCInfo *)
              &eb_emlrtBCI, &b_st);
          }

          i13 = b_nodes->size[1];
          i14 = (i - 1) + 1;
          if (!((i14 >= 1) && (i14 <= i13))) {
            emlrtDynamicBoundsCheckR2012b(i14, 1, i13, (emlrtBCInfo *)
              &db_emlrtBCI, &b_st);
          }

          i13 = b_nodes->size[1];
          if (!((i >= 1) && (i <= i13))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&nb_emlrtBCI,
              &b_st);
          }

          i13 = b_nodes->size[1];
          if (!((i >= 1) && (i <= i13))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&ob_emlrtBCI,
              &b_st);
          }

          if (b_nodes->data[i - 1].par.Iext + b_nodes->data[i - 1].par.Isyn /
              b_nodes->data[i - 1].par.W > b_nodes->data[i - 1].par.Theta) {
            i13 = b_nodes->size[1];
            if (!((i >= 1) && (i <= i13))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)
                &pb_emlrtBCI, &b_st);
            }

            d3 = b_nodes->data[i - 1].par.kInp;

            /*  changing to state k (which was set by UpdateInputNSeed function) */
            c_st.site = &l_emlrtRSI;
            d6 = calcSpTime(&c_st, 1.0 + (real_T)(i - 1), b_nodes, b_nodes->
                            data[i - 1].par.kInp);
          }
        }

        i13 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&qb_emlrtBCI,
            &st);
        }

        b_nodes->data[i - 1].x = d3;
        i13 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&rb_emlrtBCI,
            &st);
        }

        b_nodes->data[i - 1].par.spTime = d6;

        /* ElementIter(nodes(i).x, nodes(i).par); */
        i13 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&sb_emlrtBCI,
            &st);
        }

        i13 = xData->size[0];
        i14 = (int32_T)(2.0 + (real_T)t);
        if (!((i14 >= 1) && (i14 <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, i13, (emlrtBCInfo *)&tb_emlrtBCI,
            &st);
        }

        i13 = xData->size[1];
        if (!((i >= 1) && (i <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&tb_emlrtBCI,
            &st);
        }

        xData->data[(i14 + xData->size[0] * (i - 1)) - 1] = b_nodes->data[i - 1]
          .x;
        i13 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&ub_emlrtBCI,
            &st);
        }

        i13 = spTime->size[0];
        i14 = (int32_T)(2.0 + (real_T)t);
        if (!((i14 >= 1) && (i14 <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, i13, (emlrtBCInfo *)&vb_emlrtBCI,
            &st);
        }

        i13 = spTime->size[1];
        if (!((i >= 1) && (i <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&vb_emlrtBCI,
            &st);
        }

        spTime->data[(i14 + spTime->size[0] * (i - 1)) - 1] = b_nodes->data[i -
          1].par.spTime;
        if (isFullyActive) {
          i13 = b_nodes->size[1];
          if (!((i >= 1) && (i <= i13))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&wb_emlrtBCI,
              &st);
          }

          if (b_nodes->data[i - 1].x > 0.0) {
            isFullyActive = true;
          } else {
            isFullyActive = false;
          }
        } else {
          isFullyActive = false;
        }

        i++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      if (isFullyActive) {
        exitg1 = true;
      } else {
        t++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
    }

    /* netActTime = t - 1; */
    b_st.site = &g_emlrtRSI;
    if (muDoubleScalarIsNaN(returnTimeEvol)) {
      c_st.site = &c_emlrtRSI;
      d_st.site = &c_emlrtRSI;
      error(&d_st);
    }

    if (returnTimeEvol != 0.0) {
      emxInit_real_T(&st, &c_xData, 2, &l_emlrtRTEI, true);

      /* xData = xData(1:(t-1),:); */
      i13 = xData->size[0];
      if (!(1 <= i13)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i13, (emlrtBCInfo *)&gb_emlrtBCI,
          &st);
      }

      i13 = xData->size[0];
      i14 = (int32_T)b_t;
      if (!((i14 >= 1) && (i14 <= i13))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, i13, (emlrtBCInfo *)&hb_emlrtBCI,
          &st);
      }

      t = xData->size[1];
      i13 = c_xData->size[0] * c_xData->size[1];
      c_xData->size[0] = (int32_T)b_t;
      c_xData->size[1] = t;
      emxEnsureCapacity_real_T(&st, c_xData, i13, &l_emlrtRTEI);
      for (i13 = 0; i13 < t; i13++) {
        loop_ub = (int32_T)b_t;
        for (i14 = 0; i14 < loop_ub; i14++) {
          c_xData->data[i14 + c_xData->size[0] * i13] = xData->data[i14 +
            xData->size[0] * i13];
        }
      }

      i13 = xData->size[0] * xData->size[1];
      xData->size[0] = c_xData->size[0];
      xData->size[1] = c_xData->size[1];
      emxEnsureCapacity_real_T(&st, xData, i13, &m_emlrtRTEI);
      loop_ub = c_xData->size[1];
      for (i13 = 0; i13 < loop_ub; i13++) {
        t = c_xData->size[0];
        for (i14 = 0; i14 < t; i14++) {
          xData->data[i14 + xData->size[0] * i13] = c_xData->data[i14 +
            c_xData->size[0] * i13];
        }
      }

      i13 = spTime->size[0];
      if (!(1 <= i13)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i13, (emlrtBCInfo *)&jb_emlrtBCI,
          &st);
      }

      i13 = spTime->size[0];
      i14 = (int32_T)b_t;
      if (!((i14 >= 1) && (i14 <= i13))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, i13, (emlrtBCInfo *)&kb_emlrtBCI,
          &st);
      }

      t = spTime->size[1];
      i13 = c_xData->size[0] * c_xData->size[1];
      c_xData->size[0] = (int32_T)b_t;
      c_xData->size[1] = t;
      emxEnsureCapacity_real_T(&st, c_xData, i13, &n_emlrtRTEI);
      for (i13 = 0; i13 < t; i13++) {
        loop_ub = (int32_T)b_t;
        for (i14 = 0; i14 < loop_ub; i14++) {
          c_xData->data[i14 + c_xData->size[0] * i13] = spTime->data[i14 +
            spTime->size[0] * i13];
        }
      }

      i13 = spTime->size[0] * spTime->size[1];
      spTime->size[0] = c_xData->size[0];
      spTime->size[1] = c_xData->size[1];
      emxEnsureCapacity_real_T(&st, spTime, i13, &o_emlrtRTEI);
      loop_ub = c_xData->size[1];
      for (i13 = 0; i13 < loop_ub; i13++) {
        t = c_xData->size[0];
        for (i14 = 0; i14 < t; i14++) {
          spTime->data[i14 + spTime->size[0] * i13] = c_xData->data[i14 +
            c_xData->size[0] * i13];
        }
      }

      emxFree_real_T(&c_xData);
    }
  } else {
    st.site = &f_emlrtRSI;
    i13 = b_nodes->size[0] * b_nodes->size[1];
    b_nodes->size[0] = 1;
    b_nodes->size[1] = nodes->size[1];
    emxEnsureCapacity_struct0_T(&st, b_nodes, i13, &c_emlrtRTEI);
    loop_ub = nodes->size[0] * nodes->size[1];
    for (i13 = 0; i13 < loop_ub; i13++) {
      emxCopyStruct_struct0_T(&st, &b_nodes->data[i13], &nodes->data[i13],
        &c_emlrtRTEI);
    }

    N = b_nodes->size[1];
    if (par->seedTrial > par->seeds->size[0]) {
      par->seedTrial = 1.0;
    }

    i = 1;
    while (i - 1 <= par->seeds->size[1] - 1) {
      i13 = par->x0->size[1];
      if (!((i >= 1) && (i <= i13))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&ec_emlrtBCI,
          &st);
      }

      i13 = b_nodes->size[1];
      i14 = par->seeds->size[0];
      d3 = par->seedTrial;
      if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
        emlrtIntegerCheckR2012b(d3, (emlrtDCInfo *)&k_emlrtDCI, &st);
      }

      t = (int32_T)d3;
      if (!((t >= 1) && (t <= i14))) {
        emlrtDynamicBoundsCheckR2012b(t, 1, i14, (emlrtBCInfo *)&gc_emlrtBCI,
          &st);
      }

      i14 = par->seeds->size[1];
      if (!((i >= 1) && (i <= i14))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i14, (emlrtBCInfo *)&gc_emlrtBCI,
          &st);
      }

      d3 = par->seeds->data[(t + par->seeds->size[0] * (i - 1)) - 1];
      if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
        emlrtIntegerCheckR2012b(d3, (emlrtDCInfo *)&k_emlrtDCI, &st);
      }

      i14 = (int32_T)d3;
      if (!((i14 >= 1) && (i14 <= i13))) {
        emlrtDynamicBoundsCheckR2012b(i14, 1, i13, (emlrtBCInfo *)&fc_emlrtBCI,
          &st);
      }

      b_nodes->data[i14 - 1].x = par->x0->data[i - 1];
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emxInit_real_T(&st, &b_xData, 2, &emlrtRTEI, true);
    par->seedTrial++;

    /*  increasing seedTrial for next simulation run (if any) */
    b_st.site = &j_emlrtRSI;
    i13 = b_xData->size[0] * b_xData->size[1];
    b_xData->size[0] = 1;
    b_xData->size[1] = N;
    emxEnsureCapacity_real_T(&st, b_xData, i13, &e_emlrtRTEI);
    for (i13 = 0; i13 < N; i13++) {
      b_xData->data[i13] = 0.0;
    }

    emxInit_real_T(&st, &b_spTime, 2, &emlrtRTEI, true);
    i13 = b_spTime->size[0] * b_spTime->size[1];
    b_spTime->size[0] = 1;
    b_spTime->size[1] = N;
    emxEnsureCapacity_real_T(&st, b_spTime, i13, &g_emlrtRTEI);
    for (i13 = 0; i13 < N; i13++) {
      b_spTime->data[i13] = 0.0;
    }

    i = 1;
    while (i - 1 <= N - 1) {
      i13 = b_nodes->size[1];
      if (!((i >= 1) && (i <= i13))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&ac_emlrtBCI,
          &st);
      }

      i13 = b_xData->size[1];
      if (!((i >= 1) && (i <= i13))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&bc_emlrtBCI,
          &st);
      }

      b_xData->data[b_xData->size[0] * (i - 1)] = b_nodes->data[i - 1].x;
      i13 = b_nodes->size[1];
      if (!((i >= 1) && (i <= i13))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&cc_emlrtBCI,
          &st);
      }

      i13 = b_spTime->size[1];
      if (!((i >= 1) && (i <= i13))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&dc_emlrtBCI,
          &st);
      }

      b_spTime->data[b_spTime->size[0] * (i - 1)] = b_nodes->data[i - 1].
        par.spTime;
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emlrtForLoopVectorCheckR2012b(2.0, 1.0, tTotal + 1.0, mxDOUBLE_CLASS,
      (int32_T)((tTotal + 1.0) + -1.0), (emlrtRTEInfo *)&u_emlrtRTEI, &st);
    b_t = 2.0;
    t = 0;
    exitg1 = false;
    while ((!exitg1) && (t <= (int32_T)((tTotal + 1.0) + -1.0) - 1)) {
      b_t = 2.0 + (real_T)t;
      i = 0;
      while (i <= N - 1) {
        i13 = c_nodes->size[0] * c_nodes->size[1];
        c_nodes->size[0] = 1;
        c_nodes->size[1] = b_nodes->size[1];
        emxEnsureCapacity_struct0_T(&st, c_nodes, i13, &j_emlrtRTEI);
        loop_ub = b_nodes->size[0] * b_nodes->size[1];
        for (i13 = 0; i13 < loop_ub; i13++) {
          emxCopyStruct_struct0_T(&st, &c_nodes->data[i13], &b_nodes->data[i13],
            &j_emlrtRTEI);
        }

        i13 = b_nodes->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i13, (emlrtBCInfo *)
            &xb_emlrtBCI, &st);
        }

        b_st.site = &i_emlrtRSI;
        UpdateInputNSeed(&b_st, 1.0 + (real_T)i, c_nodes, &d4, &d3);
        b_nodes->data[i].par.Isyn = d4;
        i13 = b_nodes->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i13, (emlrtBCInfo *)
            &yb_emlrtBCI, &st);
        }

        b_nodes->data[i].par.kInp = d3;
        i++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      /* isFullyActive = nodes(1).x > 0; */
      isFullyActive = true;
      i = 1;
      while (i - 1 <= N - 1) {
        b_st.site = &h_emlrtRSI;

        /* (x, par) */
        i13 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&lb_emlrtBCI,
            &b_st);
        }

        d3 = b_nodes->data[i - 1].x;
        i13 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&mb_emlrtBCI,
            &b_st);
        }

        d6 = b_nodes->data[i - 1].par.spTime;
        if (b_nodes->data[i - 1].x == 0.0) {
          i13 = b_nodes->size[1];
          i14 = (i - 1) + 1;
          if (!((i14 >= 1) && (i14 <= i13))) {
            emlrtDynamicBoundsCheckR2012b(i14, 1, i13, (emlrtBCInfo *)
              &eb_emlrtBCI, &b_st);
          }

          i13 = b_nodes->size[1];
          i14 = (i - 1) + 1;
          if (!((i14 >= 1) && (i14 <= i13))) {
            emlrtDynamicBoundsCheckR2012b(i14, 1, i13, (emlrtBCInfo *)
              &db_emlrtBCI, &b_st);
          }

          i13 = b_nodes->size[1];
          if (!((i >= 1) && (i <= i13))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&nb_emlrtBCI,
              &b_st);
          }

          i13 = b_nodes->size[1];
          if (!((i >= 1) && (i <= i13))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&ob_emlrtBCI,
              &b_st);
          }

          if (b_nodes->data[i - 1].par.Iext + b_nodes->data[i - 1].par.Isyn /
              b_nodes->data[i - 1].par.W > b_nodes->data[i - 1].par.Theta) {
            i13 = b_nodes->size[1];
            if (!((i >= 1) && (i <= i13))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)
                &pb_emlrtBCI, &b_st);
            }

            d3 = b_nodes->data[i - 1].par.kInp;

            /*  changing to state k (which was set by UpdateInputNSeed function) */
            c_st.site = &l_emlrtRSI;
            d6 = calcSpTime(&c_st, 1.0 + (real_T)(i - 1), b_nodes, b_nodes->
                            data[i - 1].par.kInp);
          }
        }

        i13 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&qb_emlrtBCI,
            &st);
        }

        b_nodes->data[i - 1].x = d3;
        i13 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&rb_emlrtBCI,
            &st);
        }

        b_nodes->data[i - 1].par.spTime = d6;

        /* ElementIter(nodes(i).x, nodes(i).par); */
        i13 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&sb_emlrtBCI,
            &st);
        }

        i13 = b_xData->size[1];
        if (!((i >= 1) && (i <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&tb_emlrtBCI,
            &st);
        }

        b_xData->data[b_xData->size[0] * (i - 1)] = b_nodes->data[i - 1].x;
        i13 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&ub_emlrtBCI,
            &st);
        }

        i13 = b_spTime->size[1];
        if (!((i >= 1) && (i <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&vb_emlrtBCI,
            &st);
        }

        b_spTime->data[b_spTime->size[0] * (i - 1)] = b_nodes->data[i - 1].
          par.spTime;
        if (isFullyActive) {
          i13 = b_nodes->size[1];
          if (!((i >= 1) && (i <= i13))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i13, (emlrtBCInfo *)&wb_emlrtBCI,
              &st);
          }

          if (b_nodes->data[i - 1].x > 0.0) {
            isFullyActive = true;
          } else {
            isFullyActive = false;
          }
        } else {
          isFullyActive = false;
        }

        i++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      if (isFullyActive) {
        exitg1 = true;
      } else {
        t++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
    }

    /* netActTime = t - 1; */
    b_st.site = &g_emlrtRSI;
    i13 = xData->size[0] * xData->size[1];
    xData->size[0] = 1;
    xData->size[1] = b_xData->size[1];
    emxEnsureCapacity_real_T(sp, xData, i13, &i_emlrtRTEI);
    loop_ub = b_xData->size[0] * b_xData->size[1];
    for (i13 = 0; i13 < loop_ub; i13++) {
      xData->data[i13] = b_xData->data[i13];
    }

    emxFree_real_T(&b_xData);
    i13 = spTime->size[0] * spTime->size[1];
    spTime->size[0] = 1;
    spTime->size[1] = b_spTime->size[1];
    emxEnsureCapacity_real_T(sp, spTime, i13, &k_emlrtRTEI);
    loop_ub = b_spTime->size[0] * b_spTime->size[1];
    for (i13 = 0; i13 < loop_ub; i13++) {
      spTime->data[i13] = b_spTime->data[i13];
    }

    emxFree_real_T(&b_spTime);
  }

  emxFree_struct0_T(&c_nodes);
  emxFree_struct0_T(&b_nodes);
  *netActTime = b_t;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void b_EvolveSINetwork_internal(const emlrtStack *sp, const
  emxArray_struct0_T *nodes, real_T tTotal, struct2_T *par, real_T
  returnTimeEvol, emxArray_real_T *xData, real_T *netActTime, emxArray_real_T
  *spTime)
{
  emxArray_struct0_T *b_nodes;
  int32_T i15;
  int32_T loop_ub;
  int32_T N;
  emxArray_real_T *b_xData;
  int32_T i16;
  real_T d7;
  int32_T t;
  emxArray_real_T *b_spTime;
  real_T b_t;
  boolean_T exitg1;
  boolean_T isFullyActive;
  emxArray_real_T *c_xData;
  real_T d8;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &d_emlrtRSI;
  if (muDoubleScalarIsNaN(returnTimeEvol)) {
    b_st.site = &c_emlrtRSI;
    c_st.site = &c_emlrtRSI;
    error(&c_st);
  }

  emxInit_struct0_T(sp, &b_nodes, 2, &c_emlrtRTEI, true);
  if (returnTimeEvol != 0.0) {
    st.site = &e_emlrtRSI;
    i15 = b_nodes->size[0] * b_nodes->size[1];
    b_nodes->size[0] = 1;
    b_nodes->size[1] = nodes->size[1];
    emxEnsureCapacity_struct0_T(&st, b_nodes, i15, &d_emlrtRTEI);
    loop_ub = nodes->size[0] * nodes->size[1];
    for (i15 = 0; i15 < loop_ub; i15++) {
      emxCopyStruct_struct0_T(&st, &b_nodes->data[i15], &nodes->data[i15],
        &d_emlrtRTEI);
    }

    N = nodes->size[1] - 1;
    if (par->seedTrial > par->seeds->size[0]) {
      par->seedTrial = 1.0;
    }

    loop_ub = 1;
    while (loop_ub - 1 <= par->seeds->size[1] - 1) {
      i15 = par->x0->size[1];
      if (!((loop_ub >= 1) && (loop_ub <= i15))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
          &ec_emlrtBCI, &st);
      }

      i15 = b_nodes->size[1];
      i16 = par->seeds->size[0];
      d7 = par->seedTrial;
      if (d7 != (int32_T)muDoubleScalarFloor(d7)) {
        emlrtIntegerCheckR2012b(d7, (emlrtDCInfo *)&k_emlrtDCI, &st);
      }

      t = (int32_T)d7;
      if (!((t >= 1) && (t <= i16))) {
        emlrtDynamicBoundsCheckR2012b(t, 1, i16, (emlrtBCInfo *)&gc_emlrtBCI,
          &st);
      }

      i16 = par->seeds->size[1];
      if (!((loop_ub >= 1) && (loop_ub <= i16))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i16, (emlrtBCInfo *)
          &gc_emlrtBCI, &st);
      }

      d7 = par->seeds->data[(t + par->seeds->size[0] * (loop_ub - 1)) - 1];
      if (d7 != (int32_T)muDoubleScalarFloor(d7)) {
        emlrtIntegerCheckR2012b(d7, (emlrtDCInfo *)&k_emlrtDCI, &st);
      }

      i16 = (int32_T)d7;
      if (!((i16 >= 1) && (i16 <= i15))) {
        emlrtDynamicBoundsCheckR2012b(i16, 1, i15, (emlrtBCInfo *)&fc_emlrtBCI,
          &st);
      }

      b_nodes->data[i16 - 1].x = par->x0->data[loop_ub - 1];
      loop_ub++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    par->seedTrial++;

    /*  increasing seedTrial for next simulation run (if any) */
    b_st.site = &j_emlrtRSI;
    if (muDoubleScalarIsNaN(returnTimeEvol)) {
      c_st.site = &c_emlrtRSI;
      d_st.site = &c_emlrtRSI;
      error(&d_st);
    }

    if (returnTimeEvol != 0.0) {
      i15 = xData->size[0] * xData->size[1];
      if (!(tTotal + 1.0 >= 0.0)) {
        emlrtNonNegativeCheckR2012b(tTotal + 1.0, (emlrtDCInfo *)&h_emlrtDCI,
          &st);
      }

      d7 = tTotal + 1.0;
      if (d7 != (int32_T)muDoubleScalarFloor(d7)) {
        emlrtIntegerCheckR2012b(d7, (emlrtDCInfo *)&g_emlrtDCI, &st);
      }

      xData->size[0] = (int32_T)d7;
      xData->size[1] = nodes->size[1];
      emxEnsureCapacity_real_T(&st, xData, i15, &f_emlrtRTEI);
      if (!(tTotal + 1.0 >= 0.0)) {
        emlrtNonNegativeCheckR2012b(tTotal + 1.0, (emlrtDCInfo *)&m_emlrtDCI,
          &st);
      }

      d7 = tTotal + 1.0;
      if (d7 != (int32_T)muDoubleScalarFloor(d7)) {
        emlrtIntegerCheckR2012b(d7, (emlrtDCInfo *)&l_emlrtDCI, &st);
      }

      loop_ub = (int32_T)d7 * nodes->size[1];
      for (i15 = 0; i15 < loop_ub; i15++) {
        xData->data[i15] = 0.0;
      }

      i15 = spTime->size[0] * spTime->size[1];
      if (!(tTotal + 1.0 >= 0.0)) {
        emlrtNonNegativeCheckR2012b(tTotal + 1.0, (emlrtDCInfo *)&j_emlrtDCI,
          &st);
      }

      d7 = tTotal + 1.0;
      if (d7 != (int32_T)muDoubleScalarFloor(d7)) {
        emlrtIntegerCheckR2012b(d7, (emlrtDCInfo *)&i_emlrtDCI, &st);
      }

      spTime->size[0] = (int32_T)d7;
      spTime->size[1] = nodes->size[1];
      emxEnsureCapacity_real_T(&st, spTime, i15, &h_emlrtRTEI);
      if (!(tTotal + 1.0 >= 0.0)) {
        emlrtNonNegativeCheckR2012b(tTotal + 1.0, (emlrtDCInfo *)&o_emlrtDCI,
          &st);
      }

      d7 = tTotal + 1.0;
      if (d7 != (int32_T)muDoubleScalarFloor(d7)) {
        emlrtIntegerCheckR2012b(d7, (emlrtDCInfo *)&n_emlrtDCI, &st);
      }

      loop_ub = (int32_T)d7 * nodes->size[1];
      for (i15 = 0; i15 < loop_ub; i15++) {
        spTime->data[i15] = 0.0;
      }
    } else {
      i15 = xData->size[0] * xData->size[1];
      xData->size[0] = 1;
      xData->size[1] = nodes->size[1];
      emxEnsureCapacity_real_T(&st, xData, i15, &e_emlrtRTEI);
      loop_ub = nodes->size[1];
      for (i15 = 0; i15 < loop_ub; i15++) {
        xData->data[i15] = 0.0;
      }

      i15 = spTime->size[0] * spTime->size[1];
      spTime->size[0] = 1;
      spTime->size[1] = nodes->size[1];
      emxEnsureCapacity_real_T(&st, spTime, i15, &g_emlrtRTEI);
      loop_ub = nodes->size[1];
      for (i15 = 0; i15 < loop_ub; i15++) {
        spTime->data[i15] = 0.0;
      }
    }

    loop_ub = 1;
    while (loop_ub - 1 <= N) {
      i15 = xData->size[0];
      if (!(1 <= i15)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i15, (emlrtBCInfo *)&fb_emlrtBCI,
          &st);
      }

      i15 = b_nodes->size[1];
      if (!((loop_ub >= 1) && (loop_ub <= i15))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
          &ac_emlrtBCI, &st);
      }

      i15 = xData->size[1];
      if (!((loop_ub >= 1) && (loop_ub <= i15))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
          &bc_emlrtBCI, &st);
      }

      xData->data[xData->size[0] * (loop_ub - 1)] = b_nodes->data[loop_ub - 1].x;
      i15 = spTime->size[0];
      if (!(1 <= i15)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i15, (emlrtBCInfo *)&ib_emlrtBCI,
          &st);
      }

      i15 = b_nodes->size[1];
      if (!((loop_ub >= 1) && (loop_ub <= i15))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
          &cc_emlrtBCI, &st);
      }

      i15 = spTime->size[1];
      if (!((loop_ub >= 1) && (loop_ub <= i15))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
          &dc_emlrtBCI, &st);
      }

      spTime->data[spTime->size[0] * (loop_ub - 1)] = b_nodes->data[loop_ub - 1]
        .par.spTime;
      loop_ub++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emlrtForLoopVectorCheckR2012b(2.0, 1.0, tTotal + 1.0, mxDOUBLE_CLASS,
      (int32_T)((tTotal + 1.0) + -1.0), (emlrtRTEInfo *)&u_emlrtRTEI, &st);
    b_t = 2.0;
    t = 0;
    exitg1 = false;
    while ((!exitg1) && (t <= (int32_T)((tTotal + 1.0) + -1.0) - 1)) {
      b_t = 2.0 + (real_T)t;
      loop_ub = 0;
      while (loop_ub <= N) {
        i15 = b_nodes->size[1];
        if (!(loop_ub + 1 <= i15)) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, i15, (emlrtBCInfo *)
            &xb_emlrtBCI, &st);
        }

        b_st.site = &i_emlrtRSI;
        b_nodes->data[loop_ub].par.Isyn = UpdateInput1Seed(&b_st, 1.0 + (real_T)
          loop_ub, b_nodes);
        i15 = b_nodes->size[1];
        if (!(loop_ub + 1 <= i15)) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, i15, (emlrtBCInfo *)
            &yb_emlrtBCI, &st);
        }

        b_nodes->data[loop_ub].par.kInp = 1.0;
        loop_ub++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      /* isFullyActive = nodes(1).x > 0; */
      isFullyActive = true;
      loop_ub = 1;
      while (loop_ub - 1 <= N) {
        b_st.site = &h_emlrtRSI;

        /* (x, par) */
        /*      if (par.Iext + par.Isyn / par.W) > par.Theta */
        /*          x = 1; */
        /*          spTime = calcSpTime(i,nodes); */
        /*      end */
        i15 = b_nodes->size[1];
        if (!((loop_ub >= 1) && (loop_ub <= i15))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
            &jc_emlrtBCI, &b_st);
        }

        d7 = b_nodes->data[loop_ub - 1].x;
        i15 = b_nodes->size[1];
        if (!((loop_ub >= 1) && (loop_ub <= i15))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
            &kc_emlrtBCI, &b_st);
        }

        d8 = b_nodes->data[loop_ub - 1].par.spTime;
        if (b_nodes->data[loop_ub - 1].x == 0.0) {
          i15 = b_nodes->size[1];
          i16 = (loop_ub - 1) + 1;
          if (!((i16 >= 1) && (i16 <= i15))) {
            emlrtDynamicBoundsCheckR2012b(i16, 1, i15, (emlrtBCInfo *)
              &ic_emlrtBCI, &b_st);
          }

          i15 = b_nodes->size[1];
          i16 = (loop_ub - 1) + 1;
          if (!((i16 >= 1) && (i16 <= i15))) {
            emlrtDynamicBoundsCheckR2012b(i16, 1, i15, (emlrtBCInfo *)
              &hc_emlrtBCI, &b_st);
          }

          i15 = b_nodes->size[1];
          if (!((loop_ub >= 1) && (loop_ub <= i15))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
              &lc_emlrtBCI, &b_st);
          }

          i15 = b_nodes->size[1];
          if (!((loop_ub >= 1) && (loop_ub <= i15))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
              &mc_emlrtBCI, &b_st);
          }

          if (b_nodes->data[loop_ub - 1].par.Iext + b_nodes->data[loop_ub - 1].
              par.Isyn / b_nodes->data[loop_ub - 1].par.W > b_nodes->
              data[loop_ub - 1].par.Theta) {
            d7 = 1.0;
            c_st.site = &m_emlrtRSI;
            d8 = calcSpTime(&c_st, 1.0 + (real_T)(loop_ub - 1), b_nodes, 1.0);
          }
        }

        i15 = b_nodes->size[1];
        if (!((loop_ub >= 1) && (loop_ub <= i15))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
            &qb_emlrtBCI, &st);
        }

        b_nodes->data[loop_ub - 1].x = d7;
        i15 = b_nodes->size[1];
        if (!((loop_ub >= 1) && (loop_ub <= i15))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
            &rb_emlrtBCI, &st);
        }

        b_nodes->data[loop_ub - 1].par.spTime = d8;

        /* ElementIter(nodes(i).x, nodes(i).par); */
        i15 = b_nodes->size[1];
        if (!((loop_ub >= 1) && (loop_ub <= i15))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
            &sb_emlrtBCI, &st);
        }

        i15 = xData->size[0];
        i16 = (int32_T)(2.0 + (real_T)t);
        if (!((i16 >= 1) && (i16 <= i15))) {
          emlrtDynamicBoundsCheckR2012b(i16, 1, i15, (emlrtBCInfo *)&tb_emlrtBCI,
            &st);
        }

        i15 = xData->size[1];
        if (!((loop_ub >= 1) && (loop_ub <= i15))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
            &tb_emlrtBCI, &st);
        }

        xData->data[(i16 + xData->size[0] * (loop_ub - 1)) - 1] = b_nodes->
          data[loop_ub - 1].x;
        i15 = b_nodes->size[1];
        if (!((loop_ub >= 1) && (loop_ub <= i15))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
            &ub_emlrtBCI, &st);
        }

        i15 = spTime->size[0];
        i16 = (int32_T)(2.0 + (real_T)t);
        if (!((i16 >= 1) && (i16 <= i15))) {
          emlrtDynamicBoundsCheckR2012b(i16, 1, i15, (emlrtBCInfo *)&vb_emlrtBCI,
            &st);
        }

        i15 = spTime->size[1];
        if (!((loop_ub >= 1) && (loop_ub <= i15))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
            &vb_emlrtBCI, &st);
        }

        spTime->data[(i16 + spTime->size[0] * (loop_ub - 1)) - 1] =
          b_nodes->data[loop_ub - 1].par.spTime;
        if (isFullyActive) {
          i15 = b_nodes->size[1];
          if (!((loop_ub >= 1) && (loop_ub <= i15))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
              &wb_emlrtBCI, &st);
          }

          if (b_nodes->data[loop_ub - 1].x > 0.0) {
            isFullyActive = true;
          } else {
            isFullyActive = false;
          }
        } else {
          isFullyActive = false;
        }

        loop_ub++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      if (isFullyActive) {
        exitg1 = true;
      } else {
        t++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
    }

    /* netActTime = t - 1; */
    b_st.site = &g_emlrtRSI;
    if (muDoubleScalarIsNaN(returnTimeEvol)) {
      c_st.site = &c_emlrtRSI;
      d_st.site = &c_emlrtRSI;
      error(&d_st);
    }

    if (returnTimeEvol != 0.0) {
      emxInit_real_T(&st, &c_xData, 2, &l_emlrtRTEI, true);

      /* xData = xData(1:(t-1),:); */
      i15 = xData->size[0];
      if (!(1 <= i15)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i15, (emlrtBCInfo *)&gb_emlrtBCI,
          &st);
      }

      i15 = xData->size[0];
      i16 = (int32_T)b_t;
      if (!((i16 >= 1) && (i16 <= i15))) {
        emlrtDynamicBoundsCheckR2012b(i16, 1, i15, (emlrtBCInfo *)&hb_emlrtBCI,
          &st);
      }

      t = xData->size[1];
      i15 = c_xData->size[0] * c_xData->size[1];
      c_xData->size[0] = (int32_T)b_t;
      c_xData->size[1] = t;
      emxEnsureCapacity_real_T(&st, c_xData, i15, &l_emlrtRTEI);
      for (i15 = 0; i15 < t; i15++) {
        loop_ub = (int32_T)b_t;
        for (i16 = 0; i16 < loop_ub; i16++) {
          c_xData->data[i16 + c_xData->size[0] * i15] = xData->data[i16 +
            xData->size[0] * i15];
        }
      }

      i15 = xData->size[0] * xData->size[1];
      xData->size[0] = c_xData->size[0];
      xData->size[1] = c_xData->size[1];
      emxEnsureCapacity_real_T(&st, xData, i15, &m_emlrtRTEI);
      loop_ub = c_xData->size[1];
      for (i15 = 0; i15 < loop_ub; i15++) {
        t = c_xData->size[0];
        for (i16 = 0; i16 < t; i16++) {
          xData->data[i16 + xData->size[0] * i15] = c_xData->data[i16 +
            c_xData->size[0] * i15];
        }
      }

      i15 = spTime->size[0];
      if (!(1 <= i15)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i15, (emlrtBCInfo *)&jb_emlrtBCI,
          &st);
      }

      i15 = spTime->size[0];
      i16 = (int32_T)b_t;
      if (!((i16 >= 1) && (i16 <= i15))) {
        emlrtDynamicBoundsCheckR2012b(i16, 1, i15, (emlrtBCInfo *)&kb_emlrtBCI,
          &st);
      }

      t = spTime->size[1];
      i15 = c_xData->size[0] * c_xData->size[1];
      c_xData->size[0] = (int32_T)b_t;
      c_xData->size[1] = t;
      emxEnsureCapacity_real_T(&st, c_xData, i15, &n_emlrtRTEI);
      for (i15 = 0; i15 < t; i15++) {
        loop_ub = (int32_T)b_t;
        for (i16 = 0; i16 < loop_ub; i16++) {
          c_xData->data[i16 + c_xData->size[0] * i15] = spTime->data[i16 +
            spTime->size[0] * i15];
        }
      }

      i15 = spTime->size[0] * spTime->size[1];
      spTime->size[0] = c_xData->size[0];
      spTime->size[1] = c_xData->size[1];
      emxEnsureCapacity_real_T(&st, spTime, i15, &o_emlrtRTEI);
      loop_ub = c_xData->size[1];
      for (i15 = 0; i15 < loop_ub; i15++) {
        t = c_xData->size[0];
        for (i16 = 0; i16 < t; i16++) {
          spTime->data[i16 + spTime->size[0] * i15] = c_xData->data[i16 +
            c_xData->size[0] * i15];
        }
      }

      emxFree_real_T(&c_xData);
    }
  } else {
    st.site = &f_emlrtRSI;
    i15 = b_nodes->size[0] * b_nodes->size[1];
    b_nodes->size[0] = 1;
    b_nodes->size[1] = nodes->size[1];
    emxEnsureCapacity_struct0_T(&st, b_nodes, i15, &c_emlrtRTEI);
    loop_ub = nodes->size[0] * nodes->size[1];
    for (i15 = 0; i15 < loop_ub; i15++) {
      emxCopyStruct_struct0_T(&st, &b_nodes->data[i15], &nodes->data[i15],
        &c_emlrtRTEI);
    }

    N = nodes->size[1] - 1;
    if (par->seedTrial > par->seeds->size[0]) {
      par->seedTrial = 1.0;
    }

    loop_ub = 1;
    while (loop_ub - 1 <= par->seeds->size[1] - 1) {
      i15 = par->x0->size[1];
      if (!((loop_ub >= 1) && (loop_ub <= i15))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
          &ec_emlrtBCI, &st);
      }

      i15 = b_nodes->size[1];
      i16 = par->seeds->size[0];
      d7 = par->seedTrial;
      if (d7 != (int32_T)muDoubleScalarFloor(d7)) {
        emlrtIntegerCheckR2012b(d7, (emlrtDCInfo *)&k_emlrtDCI, &st);
      }

      t = (int32_T)d7;
      if (!((t >= 1) && (t <= i16))) {
        emlrtDynamicBoundsCheckR2012b(t, 1, i16, (emlrtBCInfo *)&gc_emlrtBCI,
          &st);
      }

      i16 = par->seeds->size[1];
      if (!((loop_ub >= 1) && (loop_ub <= i16))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i16, (emlrtBCInfo *)
          &gc_emlrtBCI, &st);
      }

      d7 = par->seeds->data[(t + par->seeds->size[0] * (loop_ub - 1)) - 1];
      if (d7 != (int32_T)muDoubleScalarFloor(d7)) {
        emlrtIntegerCheckR2012b(d7, (emlrtDCInfo *)&k_emlrtDCI, &st);
      }

      i16 = (int32_T)d7;
      if (!((i16 >= 1) && (i16 <= i15))) {
        emlrtDynamicBoundsCheckR2012b(i16, 1, i15, (emlrtBCInfo *)&fc_emlrtBCI,
          &st);
      }

      b_nodes->data[i16 - 1].x = par->x0->data[loop_ub - 1];
      loop_ub++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emxInit_real_T(&st, &b_xData, 2, &emlrtRTEI, true);
    par->seedTrial++;

    /*  increasing seedTrial for next simulation run (if any) */
    b_st.site = &j_emlrtRSI;
    i15 = b_xData->size[0] * b_xData->size[1];
    b_xData->size[0] = 1;
    b_xData->size[1] = nodes->size[1];
    emxEnsureCapacity_real_T(&st, b_xData, i15, &e_emlrtRTEI);
    loop_ub = nodes->size[1];
    for (i15 = 0; i15 < loop_ub; i15++) {
      b_xData->data[i15] = 0.0;
    }

    emxInit_real_T(&st, &b_spTime, 2, &emlrtRTEI, true);
    i15 = b_spTime->size[0] * b_spTime->size[1];
    b_spTime->size[0] = 1;
    b_spTime->size[1] = nodes->size[1];
    emxEnsureCapacity_real_T(&st, b_spTime, i15, &g_emlrtRTEI);
    loop_ub = nodes->size[1];
    for (i15 = 0; i15 < loop_ub; i15++) {
      b_spTime->data[i15] = 0.0;
    }

    loop_ub = 1;
    while (loop_ub - 1 <= N) {
      i15 = b_nodes->size[1];
      if (!((loop_ub >= 1) && (loop_ub <= i15))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
          &ac_emlrtBCI, &st);
      }

      i15 = b_xData->size[1];
      if (!((loop_ub >= 1) && (loop_ub <= i15))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
          &bc_emlrtBCI, &st);
      }

      b_xData->data[b_xData->size[0] * (loop_ub - 1)] = b_nodes->data[loop_ub -
        1].x;
      i15 = b_nodes->size[1];
      if (!((loop_ub >= 1) && (loop_ub <= i15))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
          &cc_emlrtBCI, &st);
      }

      i15 = b_spTime->size[1];
      if (!((loop_ub >= 1) && (loop_ub <= i15))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
          &dc_emlrtBCI, &st);
      }

      b_spTime->data[b_spTime->size[0] * (loop_ub - 1)] = b_nodes->data[loop_ub
        - 1].par.spTime;
      loop_ub++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emlrtForLoopVectorCheckR2012b(2.0, 1.0, tTotal + 1.0, mxDOUBLE_CLASS,
      (int32_T)((tTotal + 1.0) + -1.0), (emlrtRTEInfo *)&u_emlrtRTEI, &st);
    b_t = 2.0;
    t = 0;
    exitg1 = false;
    while ((!exitg1) && (t <= (int32_T)((tTotal + 1.0) + -1.0) - 1)) {
      b_t = 2.0 + (real_T)t;
      loop_ub = 0;
      while (loop_ub <= N) {
        i15 = b_nodes->size[1];
        if (!(loop_ub + 1 <= i15)) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, i15, (emlrtBCInfo *)
            &xb_emlrtBCI, &st);
        }

        b_st.site = &i_emlrtRSI;
        b_nodes->data[loop_ub].par.Isyn = UpdateInput1Seed(&b_st, 1.0 + (real_T)
          loop_ub, b_nodes);
        i15 = b_nodes->size[1];
        if (!(loop_ub + 1 <= i15)) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, i15, (emlrtBCInfo *)
            &yb_emlrtBCI, &st);
        }

        b_nodes->data[loop_ub].par.kInp = 1.0;
        loop_ub++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      /* isFullyActive = nodes(1).x > 0; */
      isFullyActive = true;
      loop_ub = 1;
      while (loop_ub - 1 <= N) {
        b_st.site = &h_emlrtRSI;

        /* (x, par) */
        /*      if (par.Iext + par.Isyn / par.W) > par.Theta */
        /*          x = 1; */
        /*          spTime = calcSpTime(i,nodes); */
        /*      end */
        i15 = b_nodes->size[1];
        if (!((loop_ub >= 1) && (loop_ub <= i15))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
            &jc_emlrtBCI, &b_st);
        }

        d7 = b_nodes->data[loop_ub - 1].x;
        i15 = b_nodes->size[1];
        if (!((loop_ub >= 1) && (loop_ub <= i15))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
            &kc_emlrtBCI, &b_st);
        }

        d8 = b_nodes->data[loop_ub - 1].par.spTime;
        if (b_nodes->data[loop_ub - 1].x == 0.0) {
          i15 = b_nodes->size[1];
          i16 = (loop_ub - 1) + 1;
          if (!((i16 >= 1) && (i16 <= i15))) {
            emlrtDynamicBoundsCheckR2012b(i16, 1, i15, (emlrtBCInfo *)
              &ic_emlrtBCI, &b_st);
          }

          i15 = b_nodes->size[1];
          i16 = (loop_ub - 1) + 1;
          if (!((i16 >= 1) && (i16 <= i15))) {
            emlrtDynamicBoundsCheckR2012b(i16, 1, i15, (emlrtBCInfo *)
              &hc_emlrtBCI, &b_st);
          }

          i15 = b_nodes->size[1];
          if (!((loop_ub >= 1) && (loop_ub <= i15))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
              &lc_emlrtBCI, &b_st);
          }

          i15 = b_nodes->size[1];
          if (!((loop_ub >= 1) && (loop_ub <= i15))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
              &mc_emlrtBCI, &b_st);
          }

          if (b_nodes->data[loop_ub - 1].par.Iext + b_nodes->data[loop_ub - 1].
              par.Isyn / b_nodes->data[loop_ub - 1].par.W > b_nodes->
              data[loop_ub - 1].par.Theta) {
            d7 = 1.0;
            c_st.site = &m_emlrtRSI;
            d8 = calcSpTime(&c_st, 1.0 + (real_T)(loop_ub - 1), b_nodes, 1.0);
          }
        }

        i15 = b_nodes->size[1];
        if (!((loop_ub >= 1) && (loop_ub <= i15))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
            &qb_emlrtBCI, &st);
        }

        b_nodes->data[loop_ub - 1].x = d7;
        i15 = b_nodes->size[1];
        if (!((loop_ub >= 1) && (loop_ub <= i15))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
            &rb_emlrtBCI, &st);
        }

        b_nodes->data[loop_ub - 1].par.spTime = d8;

        /* ElementIter(nodes(i).x, nodes(i).par); */
        i15 = b_nodes->size[1];
        if (!((loop_ub >= 1) && (loop_ub <= i15))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
            &sb_emlrtBCI, &st);
        }

        i15 = b_xData->size[1];
        if (!((loop_ub >= 1) && (loop_ub <= i15))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
            &tb_emlrtBCI, &st);
        }

        b_xData->data[b_xData->size[0] * (loop_ub - 1)] = b_nodes->data[loop_ub
          - 1].x;
        i15 = b_nodes->size[1];
        if (!((loop_ub >= 1) && (loop_ub <= i15))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
            &ub_emlrtBCI, &st);
        }

        i15 = b_spTime->size[1];
        if (!((loop_ub >= 1) && (loop_ub <= i15))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
            &vb_emlrtBCI, &st);
        }

        b_spTime->data[b_spTime->size[0] * (loop_ub - 1)] = b_nodes->
          data[loop_ub - 1].par.spTime;
        if (isFullyActive) {
          i15 = b_nodes->size[1];
          if (!((loop_ub >= 1) && (loop_ub <= i15))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i15, (emlrtBCInfo *)
              &wb_emlrtBCI, &st);
          }

          if (b_nodes->data[loop_ub - 1].x > 0.0) {
            isFullyActive = true;
          } else {
            isFullyActive = false;
          }
        } else {
          isFullyActive = false;
        }

        loop_ub++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      if (isFullyActive) {
        exitg1 = true;
      } else {
        t++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
    }

    /* netActTime = t - 1; */
    b_st.site = &g_emlrtRSI;
    i15 = xData->size[0] * xData->size[1];
    xData->size[0] = 1;
    xData->size[1] = b_xData->size[1];
    emxEnsureCapacity_real_T(sp, xData, i15, &i_emlrtRTEI);
    loop_ub = b_xData->size[0] * b_xData->size[1];
    for (i15 = 0; i15 < loop_ub; i15++) {
      xData->data[i15] = b_xData->data[i15];
    }

    emxFree_real_T(&b_xData);
    i15 = spTime->size[0] * spTime->size[1];
    spTime->size[0] = 1;
    spTime->size[1] = b_spTime->size[1];
    emxEnsureCapacity_real_T(sp, spTime, i15, &k_emlrtRTEI);
    loop_ub = b_spTime->size[0] * b_spTime->size[1];
    for (i15 = 0; i15 < loop_ub; i15++) {
      spTime->data[i15] = b_spTime->data[i15];
    }

    emxFree_real_T(&b_spTime);
  }

  emxFree_struct0_T(&b_nodes);
  *netActTime = b_t;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void EvolveSINetwork(const emlrtStack *sp, const emxArray_struct0_T *nodes,
                     real_T tTotal, struct2_T *par, real_T returnTimeEvol,
                     emxArray_real_T *xData, real_T *netActTime, emxArray_real_T
                     *spTime)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (par->isCompetitive) {
    st.site = &emlrtRSI;
    EvolveSINetwork_internal(&st, nodes, tTotal, par, returnTimeEvol, xData,
      netActTime, spTime);
  } else {
    st.site = &b_emlrtRSI;
    b_EvolveSINetwork_internal(&st, nodes, tTotal, par, returnTimeEvol, xData,
      netActTime, spTime);
  }
}

/* End of code generation (EvolveSINetwork.cpp) */
