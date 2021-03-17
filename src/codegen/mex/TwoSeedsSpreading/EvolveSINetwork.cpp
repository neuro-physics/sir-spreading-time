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
#include "TwoSeedsSpreading.h"
#include "EvolveSINetwork.h"
#include "TwoSeedsSpreading_emxutil.h"
#include "error.h"
#include "rand.h"
#include "calcSpTime.h"
#include "TwoSeedsSpreading_data.h"

/* Variable Definitions */
static emlrtRSInfo sd_emlrtRSI = { 5,  /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo td_emlrtRSI = { 6,  /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo ud_emlrtRSI = { 8,  /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo vd_emlrtRSI = { 14, /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo wd_emlrtRSI = { 57, /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo xd_emlrtRSI = { 52, /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo ae_emlrtRSI = { 6,  /* lineNo */
  "SINElementIter",                    /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m"/* pathName */
};

static emlrtRSInfo be_emlrtRSI = { 10, /* lineNo */
  "SIElementIter",                     /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m"/* pathName */
};

static emlrtRTEInfo uc_emlrtRTEI = { 14,/* lineNo */
  62,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = { 38,/* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = { 39,/* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = { 70,/* lineNo */
  17,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = { 70,/* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = { 71,/* lineNo */
  18,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = { 71,/* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtBCInfo pd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  27,                                  /* colNo */
  "spTime",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  25,                                  /* colNo */
  "spTime",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  16,                                  /* colNo */
  "spTime",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  25,                                  /* colNo */
  "xData",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  23,                                  /* colNo */
  "xData",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  15,                                  /* colNo */
  "xData",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo qd_emlrtRTEI = { 50,/* lineNo */
  13,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtBCInfo vd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  29,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  28,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  48,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  68,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  21,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  29,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  52,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 38,  /* lineNo */
  23,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 38,  /* lineNo */
  23,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 39,  /* lineNo */
  24,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 39,  /* lineNo */
  24,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 38,  /* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 38,  /* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 39,  /* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 39,  /* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  80,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  25,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ie_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  35,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo je_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  13,                                  /* colNo */
  "xData",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ke_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  36,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo le_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  13,                                  /* colNo */
  "spTime",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo me_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  47,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ne_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  32,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  23,                                  /* colNo */
  "nodes(i).w",                        /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo re_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo se_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  22,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo te_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  9,                                   /* colNo */
  "xData",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ue_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  9,                                   /* colNo */
  "spTime",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ve_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 34,  /* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo we_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  9,                                   /* colNo */
  "par.seeds",                         /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  28,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ye_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  48,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo af_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  68,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  21,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  25,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo df_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  35,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ef_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  59,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ff_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2,                                   /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  80,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo if_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  13,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  29,                                  /* colNo */
  "nodes(i).w",                        /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  47,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  47,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

/* Function Declarations */
static void EvolveSINetwork_internal(const emlrtStack *sp, const
  emxArray_struct_T *nodes, real_T tTotal, d_struct_T *par, emxArray_real_T
  *xData, real_T *netActTime, emxArray_real_T *spTime);

/* Function Definitions */
static void EvolveSINetwork_internal(const emlrtStack *sp, const
  emxArray_struct_T *nodes, real_T tTotal, d_struct_T *par, emxArray_real_T
  *xData, real_T *netActTime, emxArray_real_T *spTime)
{
  emxArray_struct_T *b_nodes;
  int32_T i28;
  int32_T loop_ub;
  int32_T N;
  int32_T i;
  int32_T i29;
  int32_T t;
  real_T d6;
  real_T b_t;
  boolean_T exitg1;
  emxArray_real_T *b_xData;
  boolean_T isFullyActive;
  real_T IsynAnt;
  real_T d7;
  real_T IsynM;
  int32_T j;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_struct_T(sp, &b_nodes, 2, &uc_emlrtRTEI, true);
  st.site = &vd_emlrtRSI;
  i28 = b_nodes->size[0] * b_nodes->size[1];
  b_nodes->size[0] = 1;
  b_nodes->size[1] = nodes->size[1];
  emxEnsureCapacity_struct_T1(&st, b_nodes, i28, &uc_emlrtRTEI);
  loop_ub = nodes->size[0] * nodes->size[1];
  for (i28 = 0; i28 < loop_ub; i28++) {
    emxCopyStruct_struct_T(&st, &b_nodes->data[i28], &nodes->data[i28],
      &uc_emlrtRTEI);
  }

  N = nodes->size[1] - 1;
  if (par->seedTrial > par->seeds->size[0]) {
    par->seedTrial = 1.0;
  }

  i = 0;
  while (i < 2) {
    i28 = b_nodes->size[1];
    i29 = par->seeds->size[0];
    t = (int32_T)par->seedTrial;
    if (!((t >= 1) && (t <= i29))) {
      emlrtDynamicBoundsCheckR2012b(t, 1, i29, (emlrtBCInfo *)&we_emlrtBCI, &st);
    }

    d6 = par->seeds->data[(t + par->seeds->size[0] * i) - 1];
    if (d6 != (int32_T)muDoubleScalarFloor(d6)) {
      emlrtIntegerCheckR2012b(d6, (emlrtDCInfo *)&q_emlrtDCI, &st);
    }

    i29 = (int32_T)d6;
    if (!((i29 >= 1) && (i29 <= i28))) {
      emlrtDynamicBoundsCheckR2012b(i29, 1, i28, (emlrtBCInfo *)&ve_emlrtBCI,
        &st);
    }

    b_nodes->data[i29 - 1].x = par->x0[i];
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  par->seedTrial++;

  /*  increasing seedTrial for next simulation run (if any) */
  i28 = xData->size[0] * xData->size[1];
  if (!(tTotal + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(tTotal + 1.0, (emlrtDCInfo *)&j_emlrtDCI, &st);
  }

  d6 = tTotal + 1.0;
  if (d6 != (int32_T)muDoubleScalarFloor(d6)) {
    emlrtIntegerCheckR2012b(d6, (emlrtDCInfo *)&i_emlrtDCI, &st);
  }

  xData->size[0] = (int32_T)d6;
  xData->size[1] = nodes->size[1];
  emxEnsureCapacity_real_T(&st, xData, i28, &vc_emlrtRTEI);
  if (!(tTotal + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(tTotal + 1.0, (emlrtDCInfo *)&n_emlrtDCI, &st);
  }

  d6 = tTotal + 1.0;
  if (d6 != (int32_T)muDoubleScalarFloor(d6)) {
    emlrtIntegerCheckR2012b(d6, (emlrtDCInfo *)&m_emlrtDCI, &st);
  }

  loop_ub = (int32_T)d6 * nodes->size[1];
  for (i28 = 0; i28 < loop_ub; i28++) {
    xData->data[i28] = 0.0;
  }

  i28 = spTime->size[0] * spTime->size[1];
  if (!(tTotal + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(tTotal + 1.0, (emlrtDCInfo *)&l_emlrtDCI, &st);
  }

  d6 = tTotal + 1.0;
  if (d6 != (int32_T)muDoubleScalarFloor(d6)) {
    emlrtIntegerCheckR2012b(d6, (emlrtDCInfo *)&k_emlrtDCI, &st);
  }

  spTime->size[0] = (int32_T)d6;
  spTime->size[1] = nodes->size[1];
  emxEnsureCapacity_real_T(&st, spTime, i28, &wc_emlrtRTEI);
  if (!(tTotal + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(tTotal + 1.0, (emlrtDCInfo *)&p_emlrtDCI, &st);
  }

  d6 = tTotal + 1.0;
  if (d6 != (int32_T)muDoubleScalarFloor(d6)) {
    emlrtIntegerCheckR2012b(d6, (emlrtDCInfo *)&o_emlrtDCI, &st);
  }

  loop_ub = (int32_T)d6 * nodes->size[1];
  for (i28 = 0; i28 < loop_ub; i28++) {
    spTime->data[i28] = 0.0;
  }

  i = 1;
  while (i - 1 <= N) {
    i28 = xData->size[0];
    if (!(1 <= i28)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i28, (emlrtBCInfo *)&ud_emlrtBCI, &st);
    }

    i28 = b_nodes->size[1];
    if (!((i >= 1) && (i <= i28))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i28, (emlrtBCInfo *)&se_emlrtBCI, &st);
    }

    i28 = xData->size[1];
    if (!((i >= 1) && (i <= i28))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i28, (emlrtBCInfo *)&te_emlrtBCI, &st);
    }

    xData->data[xData->size[0] * (i - 1)] = b_nodes->data[i - 1].x;
    i28 = spTime->size[0];
    if (!(1 <= i28)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i28, (emlrtBCInfo *)&rd_emlrtBCI, &st);
    }

    i28 = b_nodes->size[1];
    i29 = (i - 1) + 1;
    if (!((i29 >= 1) && (i29 <= i28))) {
      emlrtDynamicBoundsCheckR2012b(i29, 1, i28, (emlrtBCInfo *)&vd_emlrtBCI,
        &st);
    }

    i28 = spTime->size[1];
    if (!((i >= 1) && (i <= i28))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i28, (emlrtBCInfo *)&ue_emlrtBCI, &st);
    }

    spTime->data[spTime->size[0] * (i - 1)] = 0.0;
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  emlrtForLoopVectorCheckR2012b(2.0, 1.0, tTotal + 1.0, mxDOUBLE_CLASS, (int32_T)
    ((tTotal + 1.0) + -1.0), (emlrtRTEInfo *)&qd_emlrtRTEI, &st);
  b_t = 2.0;
  t = 0;
  exitg1 = false;
  while ((!exitg1) && (t <= (int32_T)((tTotal + 1.0) + -1.0) - 1)) {
    b_t = 2.0 + (real_T)t;
    i = 0;
    while (i <= N) {
      b_st.site = &xd_emlrtRSI;

      /* Isyn = zeros(1,nodes(i).par.nInp); */
      d6 = 1.0;
      IsynAnt = rtMinusInf;
      d7 = 0.0;
      i28 = b_nodes->size[1];
      i29 = 1 + i;
      if (!(i29 <= i28)) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, (emlrtBCInfo *)&bf_emlrtBCI,
          &b_st);
      }

      loop_ub = 0;
      while (loop_ub <= (int32_T)b_nodes->data[i].par.nInp - 1) {
        /*  summing up contribution of color k */
        IsynM = 0.0;
        i28 = b_nodes->size[1];
        i29 = 1 + i;
        if (!(i29 <= i28)) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, i28, (emlrtBCInfo *)&cf_emlrtBCI,
            &b_st);
        }

        j = 1;
        while (j - 1 <= (int32_T)b_nodes->data[i].par.n - 1) {
          i28 = b_nodes->size[1];
          i29 = 1 + i;
          if (!(i29 <= i28)) {
            emlrtDynamicBoundsCheckR2012b(i29, 1, i28, (emlrtBCInfo *)
              &df_emlrtBCI, &b_st);
          }

          i28 = b_nodes->size[1];
          i29 = 1 + i;
          if (!(i29 <= i28)) {
            emlrtDynamicBoundsCheckR2012b(i29, 1, i28, (emlrtBCInfo *)
              &ef_emlrtBCI, &b_st);
          }

          i28 = b_nodes->data[i].w->size[0];
          if (!((j >= 1) && (j <= i28))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i28, (emlrtBCInfo *)&jf_emlrtBCI,
              &b_st);
          }

          i28 = b_nodes->size[1];
          i29 = b_nodes->data[i].neigh->size[0];
          if (!((j >= 1) && (j <= i29))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i29, (emlrtBCInfo *)&lf_emlrtBCI,
              &b_st);
          }

          i29 = (int32_T)b_nodes->data[i].neigh->data[j - 1];
          if (!((i29 >= 1) && (i29 <= i28))) {
            emlrtDynamicBoundsCheckR2012b(i29, 1, i28, (emlrtBCInfo *)
              &kf_emlrtBCI, &b_st);
          }

          IsynM += b_nodes->data[i].w->data[j - 1] * (real_T)(b_nodes->data[i29
            - 1].x == 1.0 + (real_T)loop_ub);
          j++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&b_st);
          }
        }

        /*  selecting color of largest contribution */
        if (IsynM > IsynAnt) {
          d6 = 1.0 + (real_T)loop_ub;
          d7 = IsynM;
        } else {
          if ((IsynM == IsynAnt) && (b_rand() > 0.5)) {
            d6 = 1.0 + (real_T)loop_ub;
            d7 = IsynM;
          }
        }

        IsynAnt = IsynM;
        loop_ub++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&b_st);
        }
      }

      i28 = b_nodes->size[1];
      i29 = 1 + i;
      if (!(i29 <= i28)) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, (emlrtBCInfo *)&ne_emlrtBCI,
          &st);
      }

      b_nodes->data[i29 - 1].par.Isyn = d7;
      i28 = b_nodes->size[1];
      i29 = 1 + i;
      if (!(i29 <= i28)) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, (emlrtBCInfo *)&oe_emlrtBCI,
          &st);
      }

      b_nodes->data[i29 - 1].par.kInp = d6;
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    /* isFullyActive = nodes(1).x > 0; */
    isFullyActive = true;
    i = 1;
    while (i - 1 <= N) {
      b_st.site = &wd_emlrtRSI;

      /* (x, par) */
      i28 = b_nodes->size[1];
      if (!((i >= 1) && (i <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i28, (emlrtBCInfo *)&ff_emlrtBCI,
          &b_st);
      }

      d6 = b_nodes->data[i - 1].x;
      i28 = b_nodes->size[1];
      if (!((i >= 1) && (i <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i28, (emlrtBCInfo *)&gf_emlrtBCI,
          &b_st);
      }

      d7 = b_nodes->data[i - 1].par.spTime;
      if (b_nodes->data[i - 1].x == 0.0) {
        i28 = b_nodes->size[1];
        i29 = (i - 1) + 1;
        if (!((i29 >= 1) && (i29 <= i28))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, i28, (emlrtBCInfo *)&xe_emlrtBCI,
            &b_st);
        }

        i28 = b_nodes->size[1];
        i29 = (i - 1) + 1;
        if (!((i29 >= 1) && (i29 <= i28))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, i28, (emlrtBCInfo *)&ye_emlrtBCI,
            &b_st);
        }

        i28 = b_nodes->size[1];
        i29 = (i - 1) + 1;
        if (!((i29 >= 1) && (i29 <= i28))) {
          emlrtDynamicBoundsCheckR2012b(i29, 1, i28, (emlrtBCInfo *)&af_emlrtBCI,
            &b_st);
        }

        i28 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i28))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i28, (emlrtBCInfo *)&hf_emlrtBCI,
            &b_st);
        }

        if (b_nodes->data[i - 1].par.Isyn / b_nodes->data[i - 1].par.W >
            b_nodes->data[i - 1].par.Theta) {
          i28 = b_nodes->size[1];
          if (!((i >= 1) && (i <= i28))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i28, (emlrtBCInfo *)&if_emlrtBCI,
              &b_st);
          }

          d6 = b_nodes->data[i - 1].par.kInp;

          /*  changing to state k (which was set by UpdateInputNSeed function) */
          c_st.site = &ae_emlrtRSI;
          d7 = calcSpTime(&c_st, 1.0 + (real_T)(i - 1), b_nodes, b_nodes->data[i
                          - 1].par.kInp);
        }
      }

      i28 = b_nodes->size[1];
      if (!((i >= 1) && (i <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i28, (emlrtBCInfo *)&ge_emlrtBCI,
          &st);
      }

      b_nodes->data[i - 1].x = d6;
      i28 = b_nodes->size[1];
      if (!((i >= 1) && (i <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i28, (emlrtBCInfo *)&he_emlrtBCI,
          &st);
      }

      b_nodes->data[i - 1].par.spTime = d7;

      /* ElementIter(nodes(i).x, nodes(i).par); */
      i28 = b_nodes->size[1];
      if (!((i >= 1) && (i <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i28, (emlrtBCInfo *)&ie_emlrtBCI,
          &st);
      }

      i28 = xData->size[0];
      i29 = (int32_T)(2.0 + (real_T)t);
      if (!((i29 >= 1) && (i29 <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, (emlrtBCInfo *)&je_emlrtBCI,
          &st);
      }

      i28 = xData->size[1];
      if (!((i >= 1) && (i <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i28, (emlrtBCInfo *)&je_emlrtBCI,
          &st);
      }

      xData->data[(i29 + xData->size[0] * (i - 1)) - 1] = b_nodes->data[i - 1].x;
      i28 = b_nodes->size[1];
      if (!((i >= 1) && (i <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i28, (emlrtBCInfo *)&ke_emlrtBCI,
          &st);
      }

      i28 = spTime->size[0];
      i29 = (int32_T)(2.0 + (real_T)t);
      if (!((i29 >= 1) && (i29 <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i29, 1, i28, (emlrtBCInfo *)&le_emlrtBCI,
          &st);
      }

      i28 = spTime->size[1];
      if (!((i >= 1) && (i <= i28))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i28, (emlrtBCInfo *)&le_emlrtBCI,
          &st);
      }

      spTime->data[(i29 + spTime->size[0] * (i - 1)) - 1] = b_nodes->data[i - 1]
        .par.spTime;
      if (isFullyActive) {
        i28 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i28))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i28, (emlrtBCInfo *)&me_emlrtBCI,
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

  emxFree_struct_T(&b_nodes);
  emxInit_real_T(&st, &b_xData, 2, &xc_emlrtRTEI, true);

  /* netActTime = t - 1; */
  /* xData = xData(1:(t-1),:); */
  i28 = xData->size[0];
  if (!(1 <= i28)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i28, (emlrtBCInfo *)&td_emlrtBCI, &st);
  }

  i28 = xData->size[0];
  i29 = (int32_T)b_t;
  if (!((i29 >= 1) && (i29 <= i28))) {
    emlrtDynamicBoundsCheckR2012b(i29, 1, i28, (emlrtBCInfo *)&sd_emlrtBCI, &st);
  }

  t = xData->size[1];
  i28 = b_xData->size[0] * b_xData->size[1];
  b_xData->size[0] = (int32_T)b_t;
  b_xData->size[1] = t;
  emxEnsureCapacity_real_T(&st, b_xData, i28, &xc_emlrtRTEI);
  for (i28 = 0; i28 < t; i28++) {
    loop_ub = (int32_T)b_t;
    for (i29 = 0; i29 < loop_ub; i29++) {
      b_xData->data[i29 + b_xData->size[0] * i28] = xData->data[i29 +
        xData->size[0] * i28];
    }
  }

  i28 = xData->size[0] * xData->size[1];
  xData->size[0] = b_xData->size[0];
  xData->size[1] = b_xData->size[1];
  emxEnsureCapacity_real_T(&st, xData, i28, &yc_emlrtRTEI);
  loop_ub = b_xData->size[1];
  for (i28 = 0; i28 < loop_ub; i28++) {
    t = b_xData->size[0];
    for (i29 = 0; i29 < t; i29++) {
      xData->data[i29 + xData->size[0] * i28] = b_xData->data[i29 +
        b_xData->size[0] * i28];
    }
  }

  i28 = spTime->size[0];
  if (!(1 <= i28)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i28, (emlrtBCInfo *)&qd_emlrtBCI, &st);
  }

  i28 = spTime->size[0];
  i29 = (int32_T)b_t;
  if (!((i29 >= 1) && (i29 <= i28))) {
    emlrtDynamicBoundsCheckR2012b(i29, 1, i28, (emlrtBCInfo *)&pd_emlrtBCI, &st);
  }

  t = spTime->size[1];
  i28 = b_xData->size[0] * b_xData->size[1];
  b_xData->size[0] = (int32_T)b_t;
  b_xData->size[1] = t;
  emxEnsureCapacity_real_T(&st, b_xData, i28, &ad_emlrtRTEI);
  for (i28 = 0; i28 < t; i28++) {
    loop_ub = (int32_T)b_t;
    for (i29 = 0; i29 < loop_ub; i29++) {
      b_xData->data[i29 + b_xData->size[0] * i28] = spTime->data[i29 +
        spTime->size[0] * i28];
    }
  }

  i28 = spTime->size[0] * spTime->size[1];
  spTime->size[0] = b_xData->size[0];
  spTime->size[1] = b_xData->size[1];
  emxEnsureCapacity_real_T(&st, spTime, i28, &bd_emlrtRTEI);
  loop_ub = b_xData->size[1];
  for (i28 = 0; i28 < loop_ub; i28++) {
    t = b_xData->size[0];
    for (i29 = 0; i29 < t; i29++) {
      spTime->data[i29 + spTime->size[0] * i28] = b_xData->data[i29 +
        b_xData->size[0] * i28];
    }
  }

  emxFree_real_T(&b_xData);
  *netActTime = b_t;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void EvolveSINetwork(const emlrtStack *sp, const emxArray_struct_T *nodes,
                     real_T tTotal, d_struct_T *par, emxArray_real_T *xData,
                     real_T *netActTime, emxArray_real_T *spTime)
{
  emxArray_struct_T *b_nodes;
  real_T t;
  int32_T i26;
  int32_T loop_ub;
  int32_T N;
  int32_T i;
  int32_T i27;
  int32_T b_t;
  real_T d4;
  boolean_T exitg1;
  emxArray_real_T *b_xData;
  boolean_T isFullyActive;
  real_T d5;
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
  st.site = &sd_emlrtRSI;
  if (muDoubleScalarIsNaN(par->isCompetitive)) {
    b_st.site = &ub_emlrtRSI;
    c_st.site = &ub_emlrtRSI;
    b_error(&c_st);
  }

  if (par->isCompetitive != 0.0) {
    st.site = &td_emlrtRSI;
    EvolveSINetwork_internal(&st, nodes, tTotal, par, xData, &t, spTime);
  } else {
    emxInit_struct_T(sp, &b_nodes, 2, &uc_emlrtRTEI, true);
    st.site = &ud_emlrtRSI;
    b_st.site = &vd_emlrtRSI;
    i26 = b_nodes->size[0] * b_nodes->size[1];
    b_nodes->size[0] = 1;
    b_nodes->size[1] = nodes->size[1];
    emxEnsureCapacity_struct_T1(&b_st, b_nodes, i26, &uc_emlrtRTEI);
    loop_ub = nodes->size[0] * nodes->size[1];
    for (i26 = 0; i26 < loop_ub; i26++) {
      emxCopyStruct_struct_T(&b_st, &b_nodes->data[i26], &nodes->data[i26],
        &uc_emlrtRTEI);
    }

    N = nodes->size[1] - 1;
    if (par->seedTrial > par->seeds->size[0]) {
      par->seedTrial = 1.0;
    }

    i = 0;
    while (i < 2) {
      i26 = b_nodes->size[1];
      i27 = par->seeds->size[0];
      b_t = (int32_T)par->seedTrial;
      if (!((b_t >= 1) && (b_t <= i27))) {
        emlrtDynamicBoundsCheckR2012b(b_t, 1, i27, (emlrtBCInfo *)&we_emlrtBCI,
          &b_st);
      }

      d4 = par->seeds->data[(b_t + par->seeds->size[0] * i) - 1];
      if (d4 != (int32_T)muDoubleScalarFloor(d4)) {
        emlrtIntegerCheckR2012b(d4, (emlrtDCInfo *)&q_emlrtDCI, &b_st);
      }

      i27 = (int32_T)d4;
      if (!((i27 >= 1) && (i27 <= i26))) {
        emlrtDynamicBoundsCheckR2012b(i27, 1, i26, (emlrtBCInfo *)&ve_emlrtBCI,
          &b_st);
      }

      b_nodes->data[i27 - 1].x = par->x0[i];
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&b_st);
      }
    }

    par->seedTrial++;

    /*  increasing seedTrial for next simulation run (if any) */
    i26 = xData->size[0] * xData->size[1];
    if (!(tTotal + 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(tTotal + 1.0, (emlrtDCInfo *)&j_emlrtDCI,
        &b_st);
    }

    d4 = tTotal + 1.0;
    if (d4 != (int32_T)muDoubleScalarFloor(d4)) {
      emlrtIntegerCheckR2012b(d4, (emlrtDCInfo *)&i_emlrtDCI, &b_st);
    }

    xData->size[0] = (int32_T)d4;
    xData->size[1] = nodes->size[1];
    emxEnsureCapacity_real_T(&b_st, xData, i26, &vc_emlrtRTEI);
    if (!(tTotal + 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(tTotal + 1.0, (emlrtDCInfo *)&n_emlrtDCI,
        &b_st);
    }

    d4 = tTotal + 1.0;
    if (d4 != (int32_T)muDoubleScalarFloor(d4)) {
      emlrtIntegerCheckR2012b(d4, (emlrtDCInfo *)&m_emlrtDCI, &b_st);
    }

    loop_ub = (int32_T)d4 * nodes->size[1];
    for (i26 = 0; i26 < loop_ub; i26++) {
      xData->data[i26] = 0.0;
    }

    i26 = spTime->size[0] * spTime->size[1];
    if (!(tTotal + 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(tTotal + 1.0, (emlrtDCInfo *)&l_emlrtDCI,
        &b_st);
    }

    d4 = tTotal + 1.0;
    if (d4 != (int32_T)muDoubleScalarFloor(d4)) {
      emlrtIntegerCheckR2012b(d4, (emlrtDCInfo *)&k_emlrtDCI, &b_st);
    }

    spTime->size[0] = (int32_T)d4;
    spTime->size[1] = nodes->size[1];
    emxEnsureCapacity_real_T(&b_st, spTime, i26, &wc_emlrtRTEI);
    if (!(tTotal + 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(tTotal + 1.0, (emlrtDCInfo *)&p_emlrtDCI,
        &b_st);
    }

    d4 = tTotal + 1.0;
    if (d4 != (int32_T)muDoubleScalarFloor(d4)) {
      emlrtIntegerCheckR2012b(d4, (emlrtDCInfo *)&o_emlrtDCI, &b_st);
    }

    loop_ub = (int32_T)d4 * nodes->size[1];
    for (i26 = 0; i26 < loop_ub; i26++) {
      spTime->data[i26] = 0.0;
    }

    i = 1;
    while (i - 1 <= N) {
      i26 = xData->size[0];
      if (!(1 <= i26)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i26, (emlrtBCInfo *)&ud_emlrtBCI,
          &b_st);
      }

      i26 = b_nodes->size[1];
      if (!((i >= 1) && (i <= i26))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i26, (emlrtBCInfo *)&se_emlrtBCI,
          &b_st);
      }

      i26 = xData->size[1];
      if (!((i >= 1) && (i <= i26))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i26, (emlrtBCInfo *)&te_emlrtBCI,
          &b_st);
      }

      xData->data[xData->size[0] * (i - 1)] = b_nodes->data[i - 1].x;
      i26 = spTime->size[0];
      if (!(1 <= i26)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i26, (emlrtBCInfo *)&rd_emlrtBCI,
          &b_st);
      }

      i26 = b_nodes->size[1];
      i27 = (i - 1) + 1;
      if (!((i27 >= 1) && (i27 <= i26))) {
        emlrtDynamicBoundsCheckR2012b(i27, 1, i26, (emlrtBCInfo *)&vd_emlrtBCI,
          &b_st);
      }

      i26 = spTime->size[1];
      if (!((i >= 1) && (i <= i26))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i26, (emlrtBCInfo *)&ue_emlrtBCI,
          &b_st);
      }

      spTime->data[spTime->size[0] * (i - 1)] = 0.0;
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&b_st);
      }
    }

    emlrtForLoopVectorCheckR2012b(2.0, 1.0, tTotal + 1.0, mxDOUBLE_CLASS,
      (int32_T)((tTotal + 1.0) + -1.0), (emlrtRTEInfo *)&qd_emlrtRTEI, &b_st);
    t = 2.0;
    b_t = 0;
    exitg1 = false;
    while ((!exitg1) && (b_t <= (int32_T)((tTotal + 1.0) + -1.0) - 1)) {
      t = 2.0 + (real_T)b_t;
      i = 0;
      while (i <= N) {
        c_st.site = &xd_emlrtRSI;
        d4 = 0.0;

        /* spTime = 0.0; nAct = 0; spTimePrev = 0.0; */
        i26 = b_nodes->size[1];
        i27 = 1 + i;
        if (!(i27 <= i26)) {
          emlrtDynamicBoundsCheckR2012b(i27, 1, i26, (emlrtBCInfo *)&ae_emlrtBCI,
            &c_st);
        }

        loop_ub = 1;
        while (loop_ub - 1 <= (int32_T)b_nodes->data[i].par.n - 1) {
          i26 = b_nodes->size[1];
          i27 = 1 + i;
          if (!(i27 <= i26)) {
            emlrtDynamicBoundsCheckR2012b(i27, 1, i26, (emlrtBCInfo *)
              &be_emlrtBCI, &c_st);
          }

          i26 = b_nodes->size[1];
          i27 = 1 + i;
          if (!(i27 <= i26)) {
            emlrtDynamicBoundsCheckR2012b(i27, 1, i26, (emlrtBCInfo *)
              &ce_emlrtBCI, &c_st);
          }

          i26 = b_nodes->data[i].w->size[0];
          if (!((loop_ub >= 1) && (loop_ub <= i26))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i26, (emlrtBCInfo *)
              &pe_emlrtBCI, &c_st);
          }

          i26 = b_nodes->size[1];
          i27 = b_nodes->data[i].neigh->size[0];
          if (!((loop_ub >= 1) && (loop_ub <= i27))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i27, (emlrtBCInfo *)
              &re_emlrtBCI, &c_st);
          }

          i27 = (int32_T)b_nodes->data[i].neigh->data[loop_ub - 1];
          if (!((i27 >= 1) && (i27 <= i26))) {
            emlrtDynamicBoundsCheckR2012b(i27, 1, i26, (emlrtBCInfo *)
              &qe_emlrtBCI, &c_st);
          }

          d4 += b_nodes->data[i].w->data[loop_ub - 1] * b_nodes->data[i27 - 1].x;
          loop_ub++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&c_st);
          }
        }

        i26 = b_nodes->size[1];
        i27 = 1 + i;
        if (!(i27 <= i26)) {
          emlrtDynamicBoundsCheckR2012b(i27, 1, i26, (emlrtBCInfo *)&ne_emlrtBCI,
            &b_st);
        }

        b_nodes->data[i27 - 1].par.Isyn = d4;
        i26 = b_nodes->size[1];
        i27 = 1 + i;
        if (!(i27 <= i26)) {
          emlrtDynamicBoundsCheckR2012b(i27, 1, i26, (emlrtBCInfo *)&oe_emlrtBCI,
            &b_st);
        }

        b_nodes->data[i27 - 1].par.kInp = 1.0;
        i++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&b_st);
        }
      }

      /* isFullyActive = nodes(1).x > 0; */
      isFullyActive = true;
      i = 1;
      while (i - 1 <= N) {
        c_st.site = &wd_emlrtRSI;

        /* (x, par) */
        /*      if (par.Iext + par.Isyn / par.W) > par.Theta */
        /*          x = 1; */
        /*          spTime = calcSpTime(i,nodes); */
        /*      end */
        i26 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i26))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i26, (emlrtBCInfo *)&de_emlrtBCI,
            &c_st);
        }

        d4 = b_nodes->data[i - 1].x;
        i26 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i26))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i26, (emlrtBCInfo *)&ee_emlrtBCI,
            &c_st);
        }

        d5 = b_nodes->data[i - 1].par.spTime;
        if (b_nodes->data[i - 1].x == 0.0) {
          i26 = b_nodes->size[1];
          i27 = (i - 1) + 1;
          if (!((i27 >= 1) && (i27 <= i26))) {
            emlrtDynamicBoundsCheckR2012b(i27, 1, i26, (emlrtBCInfo *)
              &wd_emlrtBCI, &c_st);
          }

          i26 = b_nodes->size[1];
          i27 = (i - 1) + 1;
          if (!((i27 >= 1) && (i27 <= i26))) {
            emlrtDynamicBoundsCheckR2012b(i27, 1, i26, (emlrtBCInfo *)
              &xd_emlrtBCI, &c_st);
          }

          i26 = b_nodes->size[1];
          i27 = (i - 1) + 1;
          if (!((i27 >= 1) && (i27 <= i26))) {
            emlrtDynamicBoundsCheckR2012b(i27, 1, i26, (emlrtBCInfo *)
              &yd_emlrtBCI, &c_st);
          }

          i26 = b_nodes->size[1];
          if (!((i >= 1) && (i <= i26))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i26, (emlrtBCInfo *)&fe_emlrtBCI,
              &c_st);
          }

          if (b_nodes->data[i - 1].par.Isyn / b_nodes->data[i - 1].par.W >
              b_nodes->data[i - 1].par.Theta) {
            d4 = 1.0;
            d_st.site = &be_emlrtRSI;
            d5 = calcSpTime(&d_st, 1.0 + (real_T)(i - 1), b_nodes, 1.0);
          }
        }

        i26 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i26))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i26, (emlrtBCInfo *)&ge_emlrtBCI,
            &b_st);
        }

        b_nodes->data[i - 1].x = d4;
        i26 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i26))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i26, (emlrtBCInfo *)&he_emlrtBCI,
            &b_st);
        }

        b_nodes->data[i - 1].par.spTime = d5;

        /* ElementIter(nodes(i).x, nodes(i).par); */
        i26 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i26))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i26, (emlrtBCInfo *)&ie_emlrtBCI,
            &b_st);
        }

        i26 = xData->size[0];
        i27 = (int32_T)(2.0 + (real_T)b_t);
        if (!((i27 >= 1) && (i27 <= i26))) {
          emlrtDynamicBoundsCheckR2012b(i27, 1, i26, (emlrtBCInfo *)&je_emlrtBCI,
            &b_st);
        }

        i26 = xData->size[1];
        if (!((i >= 1) && (i <= i26))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i26, (emlrtBCInfo *)&je_emlrtBCI,
            &b_st);
        }

        xData->data[(i27 + xData->size[0] * (i - 1)) - 1] = b_nodes->data[i - 1]
          .x;
        i26 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i26))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i26, (emlrtBCInfo *)&ke_emlrtBCI,
            &b_st);
        }

        i26 = spTime->size[0];
        i27 = (int32_T)(2.0 + (real_T)b_t);
        if (!((i27 >= 1) && (i27 <= i26))) {
          emlrtDynamicBoundsCheckR2012b(i27, 1, i26, (emlrtBCInfo *)&le_emlrtBCI,
            &b_st);
        }

        i26 = spTime->size[1];
        if (!((i >= 1) && (i <= i26))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i26, (emlrtBCInfo *)&le_emlrtBCI,
            &b_st);
        }

        spTime->data[(i27 + spTime->size[0] * (i - 1)) - 1] = b_nodes->data[i -
          1].par.spTime;
        if (isFullyActive) {
          i26 = b_nodes->size[1];
          if (!((i >= 1) && (i <= i26))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i26, (emlrtBCInfo *)&me_emlrtBCI,
              &b_st);
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
          emlrtBreakCheckR2012b(&b_st);
        }
      }

      if (isFullyActive) {
        exitg1 = true;
      } else {
        b_t++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&b_st);
        }
      }
    }

    emxFree_struct_T(&b_nodes);
    emxInit_real_T(&b_st, &b_xData, 2, &xc_emlrtRTEI, true);

    /* netActTime = t - 1; */
    /* xData = xData(1:(t-1),:); */
    i26 = xData->size[0];
    if (!(1 <= i26)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i26, (emlrtBCInfo *)&td_emlrtBCI,
        &b_st);
    }

    i26 = xData->size[0];
    i27 = (int32_T)t;
    if (!((i27 >= 1) && (i27 <= i26))) {
      emlrtDynamicBoundsCheckR2012b(i27, 1, i26, (emlrtBCInfo *)&sd_emlrtBCI,
        &b_st);
    }

    b_t = xData->size[1];
    i26 = b_xData->size[0] * b_xData->size[1];
    b_xData->size[0] = (int32_T)t;
    b_xData->size[1] = b_t;
    emxEnsureCapacity_real_T(&b_st, b_xData, i26, &xc_emlrtRTEI);
    for (i26 = 0; i26 < b_t; i26++) {
      loop_ub = (int32_T)t;
      for (i27 = 0; i27 < loop_ub; i27++) {
        b_xData->data[i27 + b_xData->size[0] * i26] = xData->data[i27 +
          xData->size[0] * i26];
      }
    }

    i26 = xData->size[0] * xData->size[1];
    xData->size[0] = b_xData->size[0];
    xData->size[1] = b_xData->size[1];
    emxEnsureCapacity_real_T(&b_st, xData, i26, &yc_emlrtRTEI);
    loop_ub = b_xData->size[1];
    for (i26 = 0; i26 < loop_ub; i26++) {
      b_t = b_xData->size[0];
      for (i27 = 0; i27 < b_t; i27++) {
        xData->data[i27 + xData->size[0] * i26] = b_xData->data[i27 +
          b_xData->size[0] * i26];
      }
    }

    i26 = spTime->size[0];
    if (!(1 <= i26)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i26, (emlrtBCInfo *)&qd_emlrtBCI,
        &b_st);
    }

    i26 = spTime->size[0];
    i27 = (int32_T)t;
    if (!((i27 >= 1) && (i27 <= i26))) {
      emlrtDynamicBoundsCheckR2012b(i27, 1, i26, (emlrtBCInfo *)&pd_emlrtBCI,
        &b_st);
    }

    b_t = spTime->size[1];
    i26 = b_xData->size[0] * b_xData->size[1];
    b_xData->size[0] = (int32_T)t;
    b_xData->size[1] = b_t;
    emxEnsureCapacity_real_T(&b_st, b_xData, i26, &ad_emlrtRTEI);
    for (i26 = 0; i26 < b_t; i26++) {
      loop_ub = (int32_T)t;
      for (i27 = 0; i27 < loop_ub; i27++) {
        b_xData->data[i27 + b_xData->size[0] * i26] = spTime->data[i27 +
          spTime->size[0] * i26];
      }
    }

    i26 = spTime->size[0] * spTime->size[1];
    spTime->size[0] = b_xData->size[0];
    spTime->size[1] = b_xData->size[1];
    emxEnsureCapacity_real_T(&b_st, spTime, i26, &bd_emlrtRTEI);
    loop_ub = b_xData->size[1];
    for (i26 = 0; i26 < loop_ub; i26++) {
      b_t = b_xData->size[0];
      for (i27 = 0; i27 < b_t; i27++) {
        spTime->data[i27 + spTime->size[0] * i26] = b_xData->data[i27 +
          b_xData->size[0] * i26];
      }
    }

    emxFree_real_T(&b_xData);
  }

  *netActTime = t;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (EvolveSINetwork.cpp) */
