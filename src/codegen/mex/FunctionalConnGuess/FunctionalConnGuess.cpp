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
#include "FunctionalConnGuess.h"
#include "rand.h"
#include "FunctionalConnGuess_emxutil.h"
#include "calcSpTime.h"
#include "GetNodes.h"
#include "GetSimulationParam.h"
#include "FunctionalConnGuess_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 3,     /* lineNo */
  "FunctionalConnGuess",               /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 5,   /* lineNo */
  "FunctionalConnGuess",               /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 9,   /* lineNo */
  "FunctionalConnGuess",               /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 6,  /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 16, /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 52, /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 57, /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 6,  /* lineNo */
  "SINElementIter",                    /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 4,   /* lineNo */
  11,                                  /* colNo */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 6, /* lineNo */
  5,                                   /* colNo */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 20,/* lineNo */
  5,                                   /* colNo */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 16,/* lineNo */
  62,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 28,/* lineNo */
  78,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 41,/* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 42,/* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 3, /* lineNo */
  5,                                   /* colNo */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 5, /* lineNo */
  5,                                   /* colNo */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 9, /* lineNo */
  9,                                   /* colNo */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 7,/* lineNo */
  13,                                  /* colNo */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 12,/* lineNo */
  21,                                  /* colNo */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  29,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo xb_emlrtRTEI = { 50,/* lineNo */
  13,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  28,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  48,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  68,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  21,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo yb_emlrtRTEI = { 7,/* lineNo */
  13,                                  /* colNo */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m"/* pName */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  25,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  35,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  59,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  20,                                  /* colNo */
  "x",                                 /* aName */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  32,                                  /* colNo */
  "x",                                 /* aName */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  30,                                  /* colNo */
  "F",                                 /* aName */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  21,                                  /* colNo */
  "F",                                 /* aName */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  30,                                  /* colNo */
  "F",                                 /* aName */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  21,                                  /* colNo */
  "F",                                 /* aName */
  "FunctionalConnGuess",               /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\FunctionalConnGuess.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  2,                                   /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  80,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  13,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  25,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  35,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  13,                                  /* colNo */
  "xData",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  36,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  13,                                  /* colNo */
  "spTime",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  47,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  32,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  29,                                  /* colNo */
  "nodes(i).w",                        /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  47,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  47,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  22,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  9,                                   /* colNo */
  "xData",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  9,                                   /* colNo */
  "spTime",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  47,                                  /* colNo */
  "par.x0",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
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

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
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
  emxArray_real_T *r0;
  int32_T N;
  real_T expl_temp;
  real_T IsynAnt;
  boolean_T isFullyActive;
  real_T IsynM;
  char_T b_expl_temp[6];
  real_T p_seedTrial;
  int32_T i0;
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
  int32_T i1;
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
  emxInit_real_T1(sp, &p_seeds, 2, &h_emlrtRTEI, true);
  emxInit_real_T1(sp, &p_x0, 2, &h_emlrtRTEI, true);
  emxInit_real_T1(sp, &r0, 2, &emlrtRTEI, true);
  N = A->size[0];
  st.site = &emlrtRSI;
  GetSimulationParam(&st, A, nSeeds, nSim, &expl_temp, &IsynAnt, &isFullyActive,
                     p_seeds, &IsynM, b_expl_temp, &p_seedTrial, p_x0);
  i0 = r0->size[0] * r0->size[1];
  r0->size[0] = 1;
  r0->size[1] = A->size[0];
  emxEnsureCapacity_real_T(sp, r0, i0, &emlrtRTEI);
  loop_ub = A->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    r0->data[i0] = 0.0;
  }

  emxInit_struct_T(sp, &n, 2, &i_emlrtRTEI, true);
  st.site = &b_emlrtRSI;
  GetNodes(&st, A, Theta, r0, nSeeds, n);
  i0 = F->size[0] * F->size[1];
  F->size[0] = A->size[0];
  F->size[1] = A->size[0];
  emxEnsureCapacity_real_T(sp, F, i0, &b_emlrtRTEI);
  loop_ub = A->size[0] * A->size[0];
  emxFree_real_T(&r0);
  for (i0 = 0; i0 < loop_ub; i0++) {
    F->data[i0] = 0.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nSim, mxDOUBLE_CLASS, (int32_T)nSim,
    (emlrtRTEInfo *)&vb_emlrtRTEI, sp);
  k = 0;
  emxInit_real_T1(sp, &x, 2, &j_emlrtRTEI, true);
  emxInit_real_T1(sp, &par_seeds, 2, &k_emlrtRTEI, true);
  emxInit_real_T1(sp, &par_x0, 2, &k_emlrtRTEI, true);
  emxInit_real_T1(sp, &spTime, 2, &k_emlrtRTEI, true);
  emxInit_struct_T(sp, &nodes, 2, &d_emlrtRTEI, true);
  while (k <= (int32_T)nSim - 1) {
    /*  needs to be set because EvolveSINetwork uses the seeds for sim index given in p.seedTrial */
    st.site = &c_emlrtRSI;
    b_st.site = &jc_emlrtRSI;
    c_st.site = &kc_emlrtRSI;
    i0 = nodes->size[0] * nodes->size[1];
    nodes->size[0] = 1;
    nodes->size[1] = n->size[1];
    emxEnsureCapacity_struct_T(&c_st, nodes, i0, &d_emlrtRTEI);
    loop_ub = n->size[0] * n->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      emxCopyStruct_struct_T(&c_st, &nodes->data[i0], &n->data[i0], &d_emlrtRTEI);
    }

    i0 = par_seeds->size[0] * par_seeds->size[1];
    par_seeds->size[0] = p_seeds->size[0];
    par_seeds->size[1] = p_seeds->size[1];
    emxEnsureCapacity_real_T(&c_st, par_seeds, i0, &e_emlrtRTEI);
    loop_ub = p_seeds->size[0] * p_seeds->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      par_seeds->data[i0] = p_seeds->data[i0];
    }

    expl_temp = 1.0 + (real_T)k;
    i0 = par_x0->size[0] * par_x0->size[1];
    par_x0->size[0] = 1;
    par_x0->size[1] = p_x0->size[1];
    emxEnsureCapacity_real_T(&c_st, par_x0, i0, &e_emlrtRTEI);
    loop_ub = p_x0->size[0] * p_x0->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      par_x0->data[i0] = p_x0->data[i0];
    }

    b_N = n->size[1] - 1;
    if (1.0 + (real_T)k > par_seeds->size[0]) {
      expl_temp = 1.0;
    }

    i = 1;
    while (i - 1 <= par_seeds->size[1] - 1) {
      i0 = par_x0->size[1];
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&ib_emlrtBCI,
          &c_st);
      }

      i0 = nodes->size[1];
      i1 = par_seeds->size[0];
      loop_ub = (int32_T)expl_temp;
      if (!((loop_ub >= 1) && (loop_ub <= i1))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, (emlrtBCInfo *)
          &kb_emlrtBCI, &c_st);
      }

      i1 = par_seeds->size[1];
      if (!((i >= 1) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&kb_emlrtBCI,
          &c_st);
      }

      p_seedTrial = par_seeds->data[(loop_ub + par_seeds->size[0] * (i - 1)) - 1];
      if (p_seedTrial != (int32_T)muDoubleScalarFloor(p_seedTrial)) {
        emlrtIntegerCheckR2012b(p_seedTrial, (emlrtDCInfo *)&emlrtDCI, &c_st);
      }

      i1 = (int32_T)p_seedTrial;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&jb_emlrtBCI,
          &c_st);
      }

      nodes->data[i1 - 1].x = par_x0->data[i - 1];
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&c_st);
      }
    }

    /*  increasing seedTrial for next simulation run (if any) */
    i0 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = n->size[1];
    emxEnsureCapacity_real_T(&c_st, x, i0, &f_emlrtRTEI);
    loop_ub = n->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      x->data[i0] = 0.0;
    }

    i0 = spTime->size[0] * spTime->size[1];
    spTime->size[0] = 1;
    spTime->size[1] = n->size[1];
    emxEnsureCapacity_real_T(&c_st, spTime, i0, &g_emlrtRTEI);
    loop_ub = n->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      spTime->data[i0] = 0.0;
    }

    i = 1;
    while (i - 1 <= b_N) {
      i0 = nodes->size[1];
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&fb_emlrtBCI,
          &c_st);
      }

      i0 = x->size[1];
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&gb_emlrtBCI,
          &c_st);
      }

      x->data[x->size[0] * (i - 1)] = nodes->data[i - 1].x;
      i0 = nodes->size[1];
      i1 = (i - 1) + 1;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&emlrtBCI, &c_st);
      }

      i0 = spTime->size[1];
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&hb_emlrtBCI,
          &c_st);
      }

      spTime->data[spTime->size[0] * (i - 1)] = 0.0;
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&c_st);
      }
    }

    emlrtForLoopVectorCheckR2012b(2.0, 1.0, tTotal + 1.0, mxDOUBLE_CLASS,
      (int32_T)((tTotal + 1.0) + -1.0), (emlrtRTEInfo *)&xb_emlrtRTEI, &c_st);
    b_F = 0;
    exitg1 = false;
    while ((!exitg1) && (b_F <= (int32_T)((tTotal + 1.0) + -1.0) - 1)) {
      i = 0;
      while (i <= b_N) {
        d_st.site = &lc_emlrtRSI;

        /* Isyn = zeros(1,nodes(i).par.nInp); */
        p_seedTrial = 1.0;
        IsynAnt = rtMinusInf;
        expl_temp = 0.0;
        i0 = nodes->size[1];
        i1 = 1 + i;
        if (!(i1 <= i0)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&e_emlrtBCI,
            &d_st);
        }

        emlrtForLoopVectorCheckR2012b(1.0, 1.0, nodes->data[i].par.nInp,
          mxDOUBLE_CLASS, (int32_T)nodes->data[i].par.nInp, (emlrtRTEInfo *)
          &yb_emlrtRTEI, &d_st);
        loop_ub = 0;
        while (loop_ub <= (int32_T)nodes->data[i].par.nInp - 1) {
          /*  summing up contribution of color k */
          IsynM = 0.0;
          i0 = nodes->size[1];
          i1 = 1 + i;
          if (!(i1 <= i0)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&f_emlrtBCI,
              &d_st);
          }

          j = 1;
          while (j - 1 <= (int32_T)nodes->data[i].par.n - 1) {
            i0 = nodes->size[1];
            i1 = 1 + i;
            if (!(i1 <= i0)) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)
                &g_emlrtBCI, &d_st);
            }

            i0 = nodes->size[1];
            i1 = 1 + i;
            if (!(i1 <= i0)) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)
                &h_emlrtBCI, &d_st);
            }

            i0 = nodes->data[i].w->size[0];
            if (!((j >= 1) && (j <= i0))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i0, (emlrtBCInfo *)
                &cb_emlrtBCI, &d_st);
            }

            i0 = nodes->size[1];
            i1 = nodes->data[i].neigh->size[0];
            if (!((j >= 1) && (j <= i1))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i1, (emlrtBCInfo *)
                &eb_emlrtBCI, &d_st);
            }

            i1 = (int32_T)nodes->data[i].neigh->data[j - 1];
            if (!((i1 >= 1) && (i1 <= i0))) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)
                &db_emlrtBCI, &d_st);
            }

            IsynM += nodes->data[i].w->data[j - 1] * (real_T)(nodes->data[i1 - 1]
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

        i0 = nodes->size[1];
        i1 = 1 + i;
        if (!(i1 <= i0)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&ab_emlrtBCI,
            &c_st);
        }

        nodes->data[i1 - 1].par.Isyn = expl_temp;
        i0 = nodes->size[1];
        i1 = 1 + i;
        if (!(i1 <= i0)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&bb_emlrtBCI,
            &c_st);
        }

        nodes->data[i1 - 1].par.kInp = p_seedTrial;
        i++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&c_st);
        }
      }

      /* isFullyActive = nodes(1).x > 0; */
      isFullyActive = true;
      i = 1;
      while (i - 1 <= b_N) {
        d_st.site = &mc_emlrtRSI;

        /* (x, par) */
        i0 = nodes->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&o_emlrtBCI,
            &d_st);
        }

        p_seedTrial = nodes->data[i - 1].x;
        i0 = nodes->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&p_emlrtBCI,
            &d_st);
        }

        expl_temp = nodes->data[i - 1].par.spTime;
        if (nodes->data[i - 1].x == 0.0) {
          i0 = nodes->size[1];
          i1 = (i - 1) + 1;
          if (!((i1 >= 1) && (i1 <= i0))) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&b_emlrtBCI,
              &d_st);
          }

          i0 = nodes->size[1];
          i1 = (i - 1) + 1;
          if (!((i1 >= 1) && (i1 <= i0))) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&c_emlrtBCI,
              &d_st);
          }

          i0 = nodes->size[1];
          i1 = (i - 1) + 1;
          if (!((i1 >= 1) && (i1 <= i0))) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&d_emlrtBCI,
              &d_st);
          }

          i0 = nodes->size[1];
          if (!((i >= 1) && (i <= i0))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&q_emlrtBCI,
              &d_st);
          }

          if (nodes->data[i - 1].par.Isyn / nodes->data[i - 1].par.W >
              nodes->data[i - 1].par.Theta) {
            i0 = nodes->size[1];
            if (!((i >= 1) && (i <= i0))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&r_emlrtBCI,
                &d_st);
            }

            p_seedTrial = nodes->data[i - 1].par.kInp;

            /*  changing to state k (which was set by UpdateInputNSeed function) */
            e_st.site = &oc_emlrtRSI;
            expl_temp = calcSpTime(&e_st, 1.0 + (real_T)(i - 1), nodes,
              nodes->data[i - 1].par.kInp);
          }
        }

        i0 = nodes->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&s_emlrtBCI,
            &c_st);
        }

        nodes->data[i - 1].x = p_seedTrial;
        i0 = nodes->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&t_emlrtBCI,
            &c_st);
        }

        nodes->data[i - 1].par.spTime = expl_temp;

        /* ElementIter(nodes(i).x, nodes(i).par); */
        i0 = nodes->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&u_emlrtBCI,
            &c_st);
        }

        i0 = x->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&v_emlrtBCI,
            &c_st);
        }

        x->data[x->size[0] * (i - 1)] = nodes->data[i - 1].x;
        i0 = nodes->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&w_emlrtBCI,
            &c_st);
        }

        i0 = spTime->size[1];
        if (!((i >= 1) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&x_emlrtBCI,
            &c_st);
        }

        spTime->data[spTime->size[0] * (i - 1)] = nodes->data[i - 1].par.spTime;
        if (isFullyActive) {
          i0 = nodes->size[1];
          if (!((i >= 1) && (i <= i0))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&y_emlrtBCI,
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
      i0 = N + (int32_T)(1.0 - ((1.0 + (real_T)(i - 1)) + 1.0));
      emlrtForLoopVectorCheckR2012b((1.0 + (real_T)(i - 1)) + 1.0, 1.0, (real_T)
        N, mxDOUBLE_CLASS, i0, (emlrtRTEInfo *)&wb_emlrtRTEI, sp);
      j = 0;
      while (j <= i0 - 1) {
        b_j = ((uint32_T)i + j) + 1U;
        i1 = x->size[1];
        if (!((i >= 1) && (i <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&i_emlrtBCI, sp);
        }

        i1 = x->size[1];
        loop_ub = (int32_T)b_j;
        if (!((loop_ub >= 1) && (loop_ub <= i1))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, (emlrtBCInfo *)
            &j_emlrtBCI, sp);
        }

        if (x->data[x->size[0] * (i - 1)] == x->data[x->size[0] * (loop_ub - 1)])
        {
          i1 = F->size[0];
          if (!((i >= 1) && (i <= i1))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&k_emlrtBCI,
              sp);
          }

          i1 = F->size[1];
          loop_ub = (int32_T)b_j;
          if (!((loop_ub >= 1) && (loop_ub <= i1))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, (emlrtBCInfo *)
              &k_emlrtBCI, sp);
          }

          i1 = F->size[0];
          if (!((i >= 1) && (i <= i1))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&l_emlrtBCI,
              sp);
          }

          i1 = F->size[1];
          b_F = (int32_T)b_j;
          if (!((b_F >= 1) && (b_F <= i1))) {
            emlrtDynamicBoundsCheckR2012b(b_F, 1, i1, (emlrtBCInfo *)&l_emlrtBCI,
              sp);
          }

          F->data[(i + F->size[0] * (b_F - 1)) - 1] = F->data[(i + F->size[0] *
            (loop_ub - 1)) - 1] + 1.0;

          /*  couting how many times the pair (i,j) ended in the same state */
          i1 = F->size[0];
          loop_ub = (int32_T)b_j;
          if (!((loop_ub >= 1) && (loop_ub <= i1))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, (emlrtBCInfo *)
              &m_emlrtBCI, sp);
          }

          i1 = F->size[1];
          if (!((i >= 1) && (i <= i1))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&m_emlrtBCI,
              sp);
          }

          i1 = F->size[0];
          b_F = (int32_T)b_j;
          if (!((b_F >= 1) && (b_F <= i1))) {
            emlrtDynamicBoundsCheckR2012b(b_F, 1, i1, (emlrtBCInfo *)&n_emlrtBCI,
              sp);
          }

          i1 = F->size[1];
          if (!((i >= 1) && (i <= i1))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i1, (emlrtBCInfo *)&n_emlrtBCI,
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
  i0 = F->size[0] * F->size[1];
  emxEnsureCapacity_real_T(sp, F, i0, &c_emlrtRTEI);
  loop_ub = F->size[0];
  b_F = F->size[1];
  loop_ub *= b_F;
  for (i0 = 0; i0 < loop_ub; i0++) {
    F->data[i0] /= nSim;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (FunctionalConnGuess.cpp) */
