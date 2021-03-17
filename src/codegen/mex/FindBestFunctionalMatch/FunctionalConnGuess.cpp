/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FunctionalConnGuess.cpp
 *
 * Code generation for function 'FunctionalConnGuess'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindBestFunctionalMatch.h"
#include "FunctionalConnGuess.h"
#include "rand.h"
#include "FindBestFunctionalMatch_emxutil.h"
#include "calcSpTime.h"
#include "GetNodes.h"
#include "GetSimulationParam.h"
#include "FindBestFunctionalMatch_data.h"

/* Variable Definitions */
static emlrtRSInfo u_emlrtRSI = { 3,   /* lineNo */
  "FunctionalConnGuess",               /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 5,   /* lineNo */
  "FunctionalConnGuess",               /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 9,   /* lineNo */
  "FunctionalConnGuess",               /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pathName */
};

static emlrtRSInfo dd_emlrtRSI = { 6,  /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo ed_emlrtRSI = { 16, /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo fd_emlrtRSI = { 52, /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo gd_emlrtRSI = { 57, /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 6,  /* lineNo */
  "SINElementIter",                    /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m"/* pathName */
};

static emlrtRTEInfo u_emlrtRTEI = { 4, /* lineNo */
  11,                                  /* colNo */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 6, /* lineNo */
  5,                                   /* colNo */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 20,/* lineNo */
  5,                                   /* colNo */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 16,/* lineNo */
  62,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 28,/* lineNo */
  78,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 41,/* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 42,/* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 3,/* lineNo */
  5,                                   /* colNo */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 5,/* lineNo */
  5,                                   /* colNo */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 9,/* lineNo */
  9,                                   /* colNo */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = { 7,/* lineNo */
  13,                                  /* colNo */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = { 12,/* lineNo */
  21,                                  /* colNo */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pName */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  29,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo wc_emlrtRTEI = { 50,/* lineNo */
  13,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  28,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  48,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  68,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  21,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo xc_emlrtRTEI = { 7,/* lineNo */
  13,                                  /* colNo */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m"/* pName */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  25,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  35,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  59,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  20,                                  /* colNo */
  "x",                                 /* aName */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  32,                                  /* colNo */
  "x",                                 /* aName */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  30,                                  /* colNo */
  "F",                                 /* aName */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  21,                                  /* colNo */
  "F",                                 /* aName */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  30,                                  /* colNo */
  "F",                                 /* aName */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  21,                                  /* colNo */
  "F",                                 /* aName */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  2,                                   /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  80,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  13,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  25,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  35,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  13,                                  /* colNo */
  "xData",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  36,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  13,                                  /* colNo */
  "spTime",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  47,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  32,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  29,                                  /* colNo */
  "nodes(i).w",                        /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  47,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  47,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  22,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  9,                                   /* colNo */
  "xData",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  9,                                   /* colNo */
  "spTime",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  47,                                  /* colNo */
  "par.x0",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 34,    /* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  9,                                   /* colNo */
  "par.seeds",                         /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void FunctionalConnGuess(const emlrtStack *sp, const emxArray_real_T *A, real_T
  Theta, real_T nSeeds, real_T nSim, real_T tTotal, emxArray_real_T *F)
{
  emxArray_real_T *p_seeds;
  emxArray_real_T *p_x0;
  emxArray_real_T *r3;
  int32_T N;
  real_T expl_temp;
  real_T IsynAnt;
  boolean_T isFullyActive;
  real_T IsynM;
  char_T b_expl_temp[6];
  real_T p_seedTrial;
  int32_T i1;
  int32_T loop_ub;
  emxArray_struct_T *n;
  int32_T k;
  emxArray_real_T *x;
  emxArray_real_T *par_seeds;
  emxArray_real_T *par_x0;
  emxArray_real_T *spTime;
  emxArray_struct_T *nodes;
  int32_T b_F;
  int32_T b_N;
  int32_T i;
  int32_T i2;
  boolean_T exitg1;
  int32_T j;
  uint32_T b_j;
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
  emxInit_real_T(sp, &p_seeds, 2, &cb_emlrtRTEI, true);
  emxInit_real_T(sp, &p_x0, 2, &cb_emlrtRTEI, true);
  emxInit_real_T(sp, &r3, 2, &u_emlrtRTEI, true);
  N = A->size[0];
  st.site = &u_emlrtRSI;
  GetSimulationParam(&st, A, nSeeds, nSim, &expl_temp, &IsynAnt, &isFullyActive,
                     p_seeds, &IsynM, b_expl_temp, &p_seedTrial, p_x0);
  i1 = r3->size[0] * r3->size[1];
  r3->size[0] = 1;
  r3->size[1] = A->size[0];
  emxEnsureCapacity_real_T(sp, r3, i1, &u_emlrtRTEI);
  loop_ub = A->size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    r3->data[i1] = 0.0;
  }

  emxInit_struct_T(sp, &n, 2, &db_emlrtRTEI, true);
  st.site = &v_emlrtRSI;
  GetNodes(&st, A, Theta, r3, nSeeds, n);
  i1 = F->size[0] * F->size[1];
  F->size[0] = A->size[0];
  F->size[1] = A->size[0];
  emxEnsureCapacity_real_T(sp, F, i1, &v_emlrtRTEI);
  loop_ub = A->size[0] * A->size[0];
  emxFree_real_T(&r3);
  for (i1 = 0; i1 < loop_ub; i1++) {
    F->data[i1] = 0.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nSim, mxDOUBLE_CLASS, (int32_T)nSim,
    (emlrtRTEInfo *)&uc_emlrtRTEI, sp);
  k = 0;
  emxInit_real_T(sp, &x, 2, &eb_emlrtRTEI, true);
  emxInit_real_T(sp, &par_seeds, 2, &fb_emlrtRTEI, true);
  emxInit_real_T(sp, &par_x0, 2, &fb_emlrtRTEI, true);
  emxInit_real_T(sp, &spTime, 2, &fb_emlrtRTEI, true);
  emxInit_struct_T(sp, &nodes, 2, &x_emlrtRTEI, true);
  while (k <= (int32_T)nSim - 1) {
    /*  needs to be set because EvolveSINetwork uses the seeds for sim index given in p.seedTrial */
    st.site = &w_emlrtRSI;
    b_st.site = &dd_emlrtRSI;
    c_st.site = &ed_emlrtRSI;
    i1 = nodes->size[0] * nodes->size[1];
    nodes->size[0] = 1;
    nodes->size[1] = n->size[1];
    emxEnsureCapacity_struct_T(&c_st, nodes, i1, &x_emlrtRTEI);
    loop_ub = n->size[0] * n->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      emxCopyStruct_struct_T(&c_st, &nodes->data[i1], &n->data[i1], &x_emlrtRTEI);
    }

    i1 = par_seeds->size[0] * par_seeds->size[1];
    par_seeds->size[0] = p_seeds->size[0];
    par_seeds->size[1] = p_seeds->size[1];
    emxEnsureCapacity_real_T(&c_st, par_seeds, i1, &y_emlrtRTEI);
    loop_ub = p_seeds->size[0] * p_seeds->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      par_seeds->data[i1] = p_seeds->data[i1];
    }

    expl_temp = 1.0 + (real_T)k;
    i1 = par_x0->size[0] * par_x0->size[1];
    par_x0->size[0] = 1;
    par_x0->size[1] = p_x0->size[1];
    emxEnsureCapacity_real_T(&c_st, par_x0, i1, &y_emlrtRTEI);
    loop_ub = p_x0->size[0] * p_x0->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      par_x0->data[i1] = p_x0->data[i1];
    }

    b_N = n->size[1] - 1;
    if (1.0 + (real_T)k > par_seeds->size[0]) {
      expl_temp = 1.0;
    }

    i = 1;
    while (i - 1 <= par_seeds->size[1] - 1) {
      i1 = par_x0->size[1];
      if (!((i >= 1) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&pb_emlrtBCI,
          &c_st);
      }

      i1 = nodes->size[1];
      i2 = par_seeds->size[0];
      loop_ub = (int32_T)expl_temp;
      if (!((loop_ub >= 1) && (loop_ub <= i2))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, (emlrtBCInfo *)
          &rb_emlrtBCI, &c_st);
      }

      i2 = par_seeds->size[1];
      if (!((i >= 1) && (i <= i2))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i2, (emlrtBCInfo *)&rb_emlrtBCI,
          &c_st);
      }

      p_seedTrial = par_seeds->data[(loop_ub + par_seeds->size[0] * (i - 1)) - 1];
      if (p_seedTrial != (int32_T)muDoubleScalarFloor(p_seedTrial)) {
        emlrtIntegerCheckR2012b(p_seedTrial, (emlrtDCInfo *)&emlrtDCI, &c_st);
      }

      i2 = (int32_T)p_seedTrial;
      if (!((i2 >= 1) && (i2 <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)&qb_emlrtBCI,
          &c_st);
      }

      nodes->data[i2 - 1].x = par_x0->data[i - 1];
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&c_st);
      }
    }

    /*  increasing seedTrial for next simulation run (if any) */
    i1 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = n->size[1];
    emxEnsureCapacity_real_T(&c_st, x, i1, &ab_emlrtRTEI);
    loop_ub = n->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      x->data[i1] = 0.0;
    }

    i1 = spTime->size[0] * spTime->size[1];
    spTime->size[0] = 1;
    spTime->size[1] = n->size[1];
    emxEnsureCapacity_real_T(&c_st, spTime, i1, &bb_emlrtRTEI);
    loop_ub = n->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      spTime->data[i1] = 0.0;
    }

    i = 1;
    while (i - 1 <= b_N) {
      i1 = nodes->size[1];
      if (!((i >= 1) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&mb_emlrtBCI,
          &c_st);
      }

      i1 = x->size[1];
      if (!((i >= 1) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&nb_emlrtBCI,
          &c_st);
      }

      x->data[x->size[0] * (i - 1)] = nodes->data[i - 1].x;
      i1 = nodes->size[1];
      i2 = (i - 1) + 1;
      if (!((i2 >= 1) && (i2 <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)&h_emlrtBCI,
          &c_st);
      }

      i1 = spTime->size[1];
      if (!((i >= 1) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&ob_emlrtBCI,
          &c_st);
      }

      spTime->data[spTime->size[0] * (i - 1)] = 0.0;
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&c_st);
      }
    }

    emlrtForLoopVectorCheckR2012b(2.0, 1.0, tTotal + 1.0, mxDOUBLE_CLASS,
      (int32_T)((tTotal + 1.0) + -1.0), (emlrtRTEInfo *)&wc_emlrtRTEI, &c_st);
    b_F = 0;
    exitg1 = false;
    while ((!exitg1) && (b_F <= (int32_T)((tTotal + 1.0) + -1.0) - 1)) {
      i = 0;
      while (i <= b_N) {
        d_st.site = &fd_emlrtRSI;

        /* Isyn = zeros(1,nodes(i).par.nInp); */
        p_seedTrial = 1.0;
        IsynAnt = rtMinusInf;
        expl_temp = 0.0;
        i1 = nodes->size[1];
        i2 = 1 + i;
        if (!(i2 <= i1)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)&l_emlrtBCI,
            &d_st);
        }

        emlrtForLoopVectorCheckR2012b(1.0, 1.0, nodes->data[i].par.nInp,
          mxDOUBLE_CLASS, (int32_T)nodes->data[i].par.nInp, (emlrtRTEInfo *)
          &xc_emlrtRTEI, &d_st);
        loop_ub = 0;
        while (loop_ub <= (int32_T)nodes->data[i].par.nInp - 1) {
          /*  summing up contribution of color k */
          IsynM = 0.0;
          i1 = nodes->size[1];
          i2 = 1 + i;
          if (!(i2 <= i1)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)&m_emlrtBCI,
              &d_st);
          }

          j = 1;
          while (j - 1 <= (int32_T)nodes->data[i].par.n - 1) {
            i1 = nodes->size[1];
            i2 = 1 + i;
            if (!(i2 <= i1)) {
              emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)
                &n_emlrtBCI, &d_st);
            }

            i1 = nodes->size[1];
            i2 = 1 + i;
            if (!(i2 <= i1)) {
              emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)
                &o_emlrtBCI, &d_st);
            }

            i1 = nodes->data[i].w->size[0];
            if (!((j >= 1) && (j <= i1))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i1, (emlrtBCInfo *)
                &jb_emlrtBCI, &d_st);
            }

            i1 = nodes->size[1];
            i2 = nodes->data[i].neigh->size[0];
            if (!((j >= 1) && (j <= i2))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i2, (emlrtBCInfo *)
                &lb_emlrtBCI, &d_st);
            }

            i2 = (int32_T)nodes->data[i].neigh->data[j - 1];
            if (!((i2 >= 1) && (i2 <= i1))) {
              emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)
                &kb_emlrtBCI, &d_st);
            }

            IsynM += nodes->data[i].w->data[j - 1] * (real_T)(nodes->data[i2 - 1]
              .x == 1.0 + (real_T)loop_ub);
            j++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(&d_st);
            }
          }

          /*  selecting color of largest contribution */
          if (IsynM > IsynAnt) {
            p_seedTrial = 1.0 + (real_T)loop_ub;
            expl_temp = IsynM;
          } else {
            if ((IsynM == IsynAnt) && (b_rand() > 0.5)) {
              p_seedTrial = 1.0 + (real_T)loop_ub;
              expl_temp = IsynM;
            }
          }

          IsynAnt = IsynM;
          loop_ub++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&d_st);
          }
        }

        i1 = nodes->size[1];
        i2 = 1 + i;
        if (!(i2 <= i1)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)&hb_emlrtBCI,
            &c_st);
        }

        nodes->data[i2 - 1].par.Isyn = expl_temp;
        i1 = nodes->size[1];
        i2 = 1 + i;
        if (!(i2 <= i1)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)&ib_emlrtBCI,
            &c_st);
        }

        nodes->data[i2 - 1].par.kInp = p_seedTrial;
        i++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&c_st);
        }
      }

      /* isFullyActive = nodes(1).x > 0; */
      isFullyActive = true;
      i = 1;
      while (i - 1 <= b_N) {
        d_st.site = &gd_emlrtRSI;

        /* (x, par) */
        i1 = nodes->size[1];
        if (!((i >= 1) && (i <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&v_emlrtBCI,
            &d_st);
        }

        p_seedTrial = nodes->data[i - 1].x;
        i1 = nodes->size[1];
        if (!((i >= 1) && (i <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&w_emlrtBCI,
            &d_st);
        }

        expl_temp = nodes->data[i - 1].par.spTime;
        if (nodes->data[i - 1].x == 0.0) {
          i1 = nodes->size[1];
          i2 = (i - 1) + 1;
          if (!((i2 >= 1) && (i2 <= i1))) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)&i_emlrtBCI,
              &d_st);
          }

          i1 = nodes->size[1];
          i2 = (i - 1) + 1;
          if (!((i2 >= 1) && (i2 <= i1))) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)&j_emlrtBCI,
              &d_st);
          }

          i1 = nodes->size[1];
          i2 = (i - 1) + 1;
          if (!((i2 >= 1) && (i2 <= i1))) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, (emlrtBCInfo *)&k_emlrtBCI,
              &d_st);
          }

          i1 = nodes->size[1];
          if (!((i >= 1) && (i <= i1))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&x_emlrtBCI,
              &d_st);
          }

          if (nodes->data[i - 1].par.Isyn / nodes->data[i - 1].par.W >
              nodes->data[i - 1].par.Theta) {
            i1 = nodes->size[1];
            if (!((i >= 1) && (i <= i1))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&y_emlrtBCI,
                &d_st);
            }

            p_seedTrial = nodes->data[i - 1].par.kInp;

            /*  changing to state k (which was set by UpdateInputNSeed function) */
            e_st.site = &id_emlrtRSI;
            expl_temp = calcSpTime(&e_st, 1.0 + (real_T)(i - 1), nodes,
              nodes->data[i - 1].par.kInp);
          }
        }

        i1 = nodes->size[1];
        if (!((i >= 1) && (i <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&ab_emlrtBCI,
            &c_st);
        }

        nodes->data[i - 1].x = p_seedTrial;
        i1 = nodes->size[1];
        if (!((i >= 1) && (i <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&bb_emlrtBCI,
            &c_st);
        }

        nodes->data[i - 1].par.spTime = expl_temp;

        /* ElementIter(nodes(i).x, nodes(i).par); */
        i1 = nodes->size[1];
        if (!((i >= 1) && (i <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&cb_emlrtBCI,
            &c_st);
        }

        i1 = x->size[1];
        if (!((i >= 1) && (i <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&db_emlrtBCI,
            &c_st);
        }

        x->data[x->size[0] * (i - 1)] = nodes->data[i - 1].x;
        i1 = nodes->size[1];
        if (!((i >= 1) && (i <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&eb_emlrtBCI,
            &c_st);
        }

        i1 = spTime->size[1];
        if (!((i >= 1) && (i <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&fb_emlrtBCI,
            &c_st);
        }

        spTime->data[spTime->size[0] * (i - 1)] = nodes->data[i - 1].par.spTime;
        if (isFullyActive) {
          i1 = nodes->size[1];
          if (!((i >= 1) && (i <= i1))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&gb_emlrtBCI,
              &c_st);
          }

          if (nodes->data[i - 1].x > 0.0) {
            isFullyActive = true;
          } else {
            isFullyActive = false;
          }
        } else {
          isFullyActive = false;
        }

        i++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&c_st);
        }
      }

      if (isFullyActive) {
        exitg1 = true;
      } else {
        b_F++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&c_st);
        }
      }
    }

    /* netActTime = t - 1; */
    i = 1;
    while (i - 1 <= N - 1) {
      i1 = N + (int32_T)(1.0 - ((1.0 + (real_T)(i - 1)) + 1.0));
      emlrtForLoopVectorCheckR2012b((1.0 + (real_T)(i - 1)) + 1.0, 1.0, (real_T)
        N, mxDOUBLE_CLASS, i1, (emlrtRTEInfo *)&vc_emlrtRTEI, sp);
      j = 0;
      while (j <= i1 - 1) {
        b_j = ((uint32_T)i + j) + 1U;
        i2 = x->size[1];
        if (!((i >= 1) && (i <= i2))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i2, (emlrtBCInfo *)&p_emlrtBCI, sp);
        }

        i2 = x->size[1];
        loop_ub = (int32_T)b_j;
        if (!((loop_ub >= 1) && (loop_ub <= i2))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, (emlrtBCInfo *)
            &q_emlrtBCI, sp);
        }

        if (x->data[x->size[0] * (i - 1)] == x->data[x->size[0] * (loop_ub - 1)])
        {
          i2 = F->size[0];
          if (!((i >= 1) && (i <= i2))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i2, (emlrtBCInfo *)&r_emlrtBCI,
              sp);
          }

          i2 = F->size[1];
          loop_ub = (int32_T)b_j;
          if (!((loop_ub >= 1) && (loop_ub <= i2))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, (emlrtBCInfo *)
              &r_emlrtBCI, sp);
          }

          i2 = F->size[0];
          if (!((i >= 1) && (i <= i2))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i2, (emlrtBCInfo *)&s_emlrtBCI,
              sp);
          }

          i2 = F->size[1];
          b_F = (int32_T)b_j;
          if (!((b_F >= 1) && (b_F <= i2))) {
            emlrtDynamicBoundsCheckR2012b(b_F, 1, i2, (emlrtBCInfo *)&s_emlrtBCI,
              sp);
          }

          F->data[(i + F->size[0] * (b_F - 1)) - 1] = F->data[(i + F->size[0] *
            (loop_ub - 1)) - 1] + 1.0;

          /*  couting how many times the pair (i,j) ended in the same state */
          i2 = F->size[0];
          loop_ub = (int32_T)b_j;
          if (!((loop_ub >= 1) && (loop_ub <= i2))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, (emlrtBCInfo *)
              &t_emlrtBCI, sp);
          }

          i2 = F->size[1];
          if (!((i >= 1) && (i <= i2))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i2, (emlrtBCInfo *)&t_emlrtBCI,
              sp);
          }

          i2 = F->size[0];
          b_F = (int32_T)b_j;
          if (!((b_F >= 1) && (b_F <= i2))) {
            emlrtDynamicBoundsCheckR2012b(b_F, 1, i2, (emlrtBCInfo *)&u_emlrtBCI,
              sp);
          }

          i2 = F->size[1];
          if (!((i >= 1) && (i <= i2))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i2, (emlrtBCInfo *)&u_emlrtBCI,
              sp);
          }

          F->data[(b_F + F->size[0] * (i - 1)) - 1] = F->data[(loop_ub + F->
            size[0] * (i - 1)) - 1] + 1.0;

          /*  couting how many times the pair (i,j) ended in the same state */
        }

        j++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_struct_T(&nodes);
  emxFree_real_T(&spTime);
  emxFree_real_T(&par_x0);
  emxFree_real_T(&par_seeds);
  emxFree_real_T(&x);
  emxFree_struct_T(&n);
  emxFree_real_T(&p_x0);
  emxFree_real_T(&p_seeds);
  i1 = F->size[0] * F->size[1];
  emxEnsureCapacity_real_T(sp, F, i1, &w_emlrtRTEI);
  loop_ub = F->size[0];
  b_F = F->size[1];
  loop_ub *= b_F;
  for (i1 = 0; i1 < loop_ub; i1++) {
    F->data[i1] /= nSim;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (FunctionalConnGuess.cpp) */
