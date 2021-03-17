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
#include "NetworkActivationTime.h"
#include "EvolveSINetwork.h"
#include "rand.h"
#include "NetworkActivationTime_emxutil.h"
#include "error.h"
#include "calcSpTime.h"
#include "NetworkActivationTime_data.h"

/* Variable Definitions */
static emlrtRSInfo xd_emlrtRSI = { 5,  /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo yd_emlrtRSI = { 6,  /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo ae_emlrtRSI = { 8,  /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo be_emlrtRSI = { 16, /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo ce_emlrtRSI = { 52, /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo de_emlrtRSI = { 57, /* lineNo */
  "EvolveSINetwork",                   /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pathName */
};

static emlrtRSInfo fe_emlrtRSI = { 6,  /* lineNo */
  "SINElementIter",                    /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m"/* pathName */
};

static emlrtRSInfo ge_emlrtRSI = { 10, /* lineNo */
  "SIElementIter",                     /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m"/* pathName */
};

static emlrtRTEInfo lc_emlrtRTEI = { 16,/* lineNo */
  62,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = { 41,/* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = { 42,/* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  29,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo gd_emlrtRTEI = { 50,/* lineNo */
  13,                                  /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m"/* pName */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  28,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  48,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  68,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  21,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  29,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  52,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  28,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  48,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  68,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  21,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo hd_emlrtRTEI = { 7,/* lineNo */
  13,                                  /* colNo */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m"/* pName */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  25,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  35,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  59,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  80,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  25,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  35,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  13,                                  /* colNo */
  "xData",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  36,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  13,                                  /* colNo */
  "spTime",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  47,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  32,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  23,                                  /* colNo */
  "nodes(i).w",                        /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  22,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  9,                                   /* colNo */
  "xData",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  9,                                   /* colNo */
  "spTime",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  47,                                  /* colNo */
  "par.x0",                            /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 34,  /* lineNo */
  9,                                   /* colNo */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  9,                                   /* colNo */
  "par.seeds",                         /* aName */
  "EvolveSINetwork",                   /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetwork.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  2,                                   /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  80,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  13,                                  /* colNo */
  "nodes",                             /* aName */
  "SINElementIter",                    /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SINElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  29,                                  /* colNo */
  "nodes(i).w",                        /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  47,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  47,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void EvolveSINetwork(const emlrtStack *sp, const emxArray_struct_T *nodes,
                     real_T tTotal, c_struct_T *par, emxArray_real_T *xData,
                     real_T *netActTime, emxArray_real_T *spTime)
{
  emxArray_struct_T *b_nodes;
  int32_T i16;
  int32_T loop_ub;
  int32_T N;
  int32_T i;
  int32_T i17;
  real_T d0;
  real_T t;
  boolean_T exitg1;
  boolean_T isFullyActive;
  real_T IsynAnt;
  real_T d1;
  int32_T j;
  int32_T k;
  real_T IsynM;
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
  st.site = &xd_emlrtRSI;
  if (muDoubleScalarIsNaN(par->isCompetitive)) {
    b_st.site = &e_emlrtRSI;
    c_st.site = &e_emlrtRSI;
    error(&c_st);
  }

  emxInit_struct_T(sp, &b_nodes, 2, &lc_emlrtRTEI, true);
  if (par->isCompetitive != 0.0) {
    st.site = &yd_emlrtRSI;
    b_st.site = &be_emlrtRSI;
    i16 = b_nodes->size[0] * b_nodes->size[1];
    b_nodes->size[0] = 1;
    b_nodes->size[1] = nodes->size[1];
    emxEnsureCapacity_struct_T1(&b_st, b_nodes, i16, &lc_emlrtRTEI);
    loop_ub = nodes->size[0] * nodes->size[1];
    for (i16 = 0; i16 < loop_ub; i16++) {
      emxCopyStruct_struct_T(&b_st, &b_nodes->data[i16], &nodes->data[i16],
        &lc_emlrtRTEI);
    }

    N = nodes->size[1] - 1;
    if (par->seedTrial > par->seeds->size[0]) {
      par->seedTrial = 1.0;
    }

    i = 1;
    while (i - 1 <= par->seeds->size[1] - 1) {
      i16 = par->x0->size[1];
      if (!((i >= 1) && (i <= i16))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&od_emlrtBCI,
          &b_st);
      }

      i16 = b_nodes->size[1];
      i17 = par->seeds->size[0];
      loop_ub = (int32_T)par->seedTrial;
      if (!((loop_ub >= 1) && (loop_ub <= i17))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i17, (emlrtBCInfo *)
          &qd_emlrtBCI, &b_st);
      }

      i17 = par->seeds->size[1];
      if (!((i >= 1) && (i <= i17))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i17, (emlrtBCInfo *)&qd_emlrtBCI,
          &b_st);
      }

      d0 = par->seeds->data[(loop_ub + par->seeds->size[0] * (i - 1)) - 1];
      if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
        emlrtIntegerCheckR2012b(d0, (emlrtDCInfo *)&o_emlrtDCI, &b_st);
      }

      i17 = (int32_T)d0;
      if (!((i17 >= 1) && (i17 <= i16))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)&pd_emlrtBCI,
          &b_st);
      }

      b_nodes->data[i17 - 1].x = par->x0->data[i - 1];
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&b_st);
      }
    }

    par->seedTrial++;

    /*  increasing seedTrial for next simulation run (if any) */
    i16 = xData->size[0] * xData->size[1];
    xData->size[0] = 1;
    xData->size[1] = nodes->size[1];
    emxEnsureCapacity_real_T1(&b_st, xData, i16, &mc_emlrtRTEI);
    loop_ub = nodes->size[1];
    for (i16 = 0; i16 < loop_ub; i16++) {
      xData->data[i16] = 0.0;
    }

    i16 = spTime->size[0] * spTime->size[1];
    spTime->size[0] = 1;
    spTime->size[1] = nodes->size[1];
    emxEnsureCapacity_real_T1(&b_st, spTime, i16, &nc_emlrtRTEI);
    loop_ub = nodes->size[1];
    for (i16 = 0; i16 < loop_ub; i16++) {
      spTime->data[i16] = 0.0;
    }

    i = 1;
    while (i - 1 <= N) {
      i16 = b_nodes->size[1];
      if (!((i >= 1) && (i <= i16))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&ld_emlrtBCI,
          &b_st);
      }

      i16 = xData->size[1];
      if (!((i >= 1) && (i <= i16))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&md_emlrtBCI,
          &b_st);
      }

      xData->data[xData->size[0] * (i - 1)] = b_nodes->data[i - 1].x;
      i16 = b_nodes->size[1];
      i17 = (i - 1) + 1;
      if (!((i17 >= 1) && (i17 <= i16))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)&hc_emlrtBCI,
          &b_st);
      }

      i16 = spTime->size[1];
      if (!((i >= 1) && (i <= i16))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&nd_emlrtBCI,
          &b_st);
      }

      spTime->data[spTime->size[0] * (i - 1)] = 0.0;
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&b_st);
      }
    }

    emlrtForLoopVectorCheckR2012b(2.0, 1.0, tTotal + 1.0, mxDOUBLE_CLASS,
      (int32_T)((tTotal + 1.0) + -1.0), (emlrtRTEInfo *)&gd_emlrtRTEI, &b_st);
    t = 2.0;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub <= (int32_T)((tTotal + 1.0) + -1.0) - 1)) {
      t = 2.0 + (real_T)loop_ub;
      i = 0;
      while (i <= N) {
        c_st.site = &ce_emlrtRSI;

        /* Isyn = zeros(1,nodes(i).par.nInp); */
        d0 = 1.0;
        IsynAnt = rtMinusInf;
        d1 = 0.0;
        i16 = b_nodes->size[1];
        i17 = 1 + i;
        if (!(i17 <= i16)) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)&rc_emlrtBCI,
            &c_st);
        }

        emlrtForLoopVectorCheckR2012b(1.0, 1.0, b_nodes->data[i].par.nInp,
          mxDOUBLE_CLASS, (int32_T)b_nodes->data[i].par.nInp, (emlrtRTEInfo *)
          &hd_emlrtRTEI, &c_st);
        k = 0;
        while (k <= (int32_T)b_nodes->data[i].par.nInp - 1) {
          /*  summing up contribution of color k */
          IsynM = 0.0;
          i16 = b_nodes->size[1];
          i17 = 1 + i;
          if (!(i17 <= i16)) {
            emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)
              &sc_emlrtBCI, &c_st);
          }

          j = 1;
          while (j - 1 <= (int32_T)b_nodes->data[i].par.n - 1) {
            i16 = b_nodes->size[1];
            i17 = 1 + i;
            if (!(i17 <= i16)) {
              emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)
                &tc_emlrtBCI, &c_st);
            }

            i16 = b_nodes->size[1];
            i17 = 1 + i;
            if (!(i17 <= i16)) {
              emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)
                &uc_emlrtBCI, &c_st);
            }

            i16 = b_nodes->data[i].w->size[0];
            if (!((j >= 1) && (j <= i16))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i16, (emlrtBCInfo *)
                &vd_emlrtBCI, &c_st);
            }

            i16 = b_nodes->size[1];
            i17 = b_nodes->data[i].neigh->size[0];
            if (!((j >= 1) && (j <= i17))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i17, (emlrtBCInfo *)
                &xd_emlrtBCI, &c_st);
            }

            i17 = (int32_T)b_nodes->data[i].neigh->data[j - 1];
            if (!((i17 >= 1) && (i17 <= i16))) {
              emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)
                &wd_emlrtBCI, &c_st);
            }

            IsynM += b_nodes->data[i].w->data[j - 1] * (real_T)(b_nodes->
              data[i17 - 1].x == 1.0 + (real_T)k);
            j++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(&c_st);
            }
          }

          /*  selecting color of largest contribution */
          if (IsynM > IsynAnt) {
            d0 = 1.0 + (real_T)k;
            d1 = IsynM;
          } else {
            if ((IsynM == IsynAnt) && (b_rand() > 0.5)) {
              d0 = 1.0 + (real_T)k;
              d1 = IsynM;
            }
          }

          IsynAnt = IsynM;
          k++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&c_st);
          }
        }

        i16 = b_nodes->size[1];
        i17 = 1 + i;
        if (!(i17 <= i16)) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)&gd_emlrtBCI,
            &b_st);
        }

        b_nodes->data[i17 - 1].par.Isyn = d1;
        i16 = b_nodes->size[1];
        i17 = 1 + i;
        if (!(i17 <= i16)) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)&hd_emlrtBCI,
            &b_st);
        }

        b_nodes->data[i17 - 1].par.kInp = d0;
        i++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&b_st);
        }
      }

      /* isFullyActive = nodes(1).x > 0; */
      isFullyActive = true;
      i = 1;
      while (i - 1 <= N) {
        c_st.site = &de_emlrtRSI;

        /* (x, par) */
        i16 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i16))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&rd_emlrtBCI,
            &c_st);
        }

        d0 = b_nodes->data[i - 1].x;
        i16 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i16))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&sd_emlrtBCI,
            &c_st);
        }

        d1 = b_nodes->data[i - 1].par.spTime;
        if (b_nodes->data[i - 1].x == 0.0) {
          i16 = b_nodes->size[1];
          i17 = (i - 1) + 1;
          if (!((i17 >= 1) && (i17 <= i16))) {
            emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)
              &oc_emlrtBCI, &c_st);
          }

          i16 = b_nodes->size[1];
          i17 = (i - 1) + 1;
          if (!((i17 >= 1) && (i17 <= i16))) {
            emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)
              &pc_emlrtBCI, &c_st);
          }

          i16 = b_nodes->size[1];
          i17 = (i - 1) + 1;
          if (!((i17 >= 1) && (i17 <= i16))) {
            emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)
              &qc_emlrtBCI, &c_st);
          }

          i16 = b_nodes->size[1];
          if (!((i >= 1) && (i <= i16))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&td_emlrtBCI,
              &c_st);
          }

          if (b_nodes->data[i - 1].par.Isyn / b_nodes->data[i - 1].par.W >
              b_nodes->data[i - 1].par.Theta) {
            i16 = b_nodes->size[1];
            if (!((i >= 1) && (i <= i16))) {
              emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)
                &ud_emlrtBCI, &c_st);
            }

            d0 = b_nodes->data[i - 1].par.kInp;

            /*  changing to state k (which was set by UpdateInputNSeed function) */
            d_st.site = &fe_emlrtRSI;
            d1 = calcSpTime(&d_st, 1.0 + (real_T)(i - 1), b_nodes, b_nodes->
                            data[i - 1].par.kInp);
          }
        }

        i16 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i16))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&yc_emlrtBCI,
            &b_st);
        }

        b_nodes->data[i - 1].x = d0;
        i16 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i16))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&ad_emlrtBCI,
            &b_st);
        }

        b_nodes->data[i - 1].par.spTime = d1;

        /* ElementIter(nodes(i).x, nodes(i).par); */
        i16 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i16))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&bd_emlrtBCI,
            &b_st);
        }

        i16 = xData->size[1];
        if (!((i >= 1) && (i <= i16))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&cd_emlrtBCI,
            &b_st);
        }

        xData->data[xData->size[0] * (i - 1)] = b_nodes->data[i - 1].x;
        i16 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i16))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&dd_emlrtBCI,
            &b_st);
        }

        i16 = spTime->size[1];
        if (!((i >= 1) && (i <= i16))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&ed_emlrtBCI,
            &b_st);
        }

        spTime->data[spTime->size[0] * (i - 1)] = b_nodes->data[i - 1].
          par.spTime;
        if (isFullyActive) {
          i16 = b_nodes->size[1];
          if (!((i >= 1) && (i <= i16))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&fd_emlrtBCI,
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
        loop_ub++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&b_st);
        }
      }
    }

    /* netActTime = t - 1; */
  } else {
    st.site = &ae_emlrtRSI;
    b_st.site = &be_emlrtRSI;
    i16 = b_nodes->size[0] * b_nodes->size[1];
    b_nodes->size[0] = 1;
    b_nodes->size[1] = nodes->size[1];
    emxEnsureCapacity_struct_T1(&b_st, b_nodes, i16, &lc_emlrtRTEI);
    loop_ub = nodes->size[0] * nodes->size[1];
    for (i16 = 0; i16 < loop_ub; i16++) {
      emxCopyStruct_struct_T(&b_st, &b_nodes->data[i16], &nodes->data[i16],
        &lc_emlrtRTEI);
    }

    N = nodes->size[1] - 1;
    if (par->seedTrial > par->seeds->size[0]) {
      par->seedTrial = 1.0;
    }

    i = 1;
    while (i - 1 <= par->seeds->size[1] - 1) {
      i16 = par->x0->size[1];
      if (!((i >= 1) && (i <= i16))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&od_emlrtBCI,
          &b_st);
      }

      i16 = b_nodes->size[1];
      i17 = par->seeds->size[0];
      loop_ub = (int32_T)par->seedTrial;
      if (!((loop_ub >= 1) && (loop_ub <= i17))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i17, (emlrtBCInfo *)
          &qd_emlrtBCI, &b_st);
      }

      i17 = par->seeds->size[1];
      if (!((i >= 1) && (i <= i17))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i17, (emlrtBCInfo *)&qd_emlrtBCI,
          &b_st);
      }

      d0 = par->seeds->data[(loop_ub + par->seeds->size[0] * (i - 1)) - 1];
      if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
        emlrtIntegerCheckR2012b(d0, (emlrtDCInfo *)&o_emlrtDCI, &b_st);
      }

      i17 = (int32_T)d0;
      if (!((i17 >= 1) && (i17 <= i16))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)&pd_emlrtBCI,
          &b_st);
      }

      b_nodes->data[i17 - 1].x = par->x0->data[i - 1];
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&b_st);
      }
    }

    par->seedTrial++;

    /*  increasing seedTrial for next simulation run (if any) */
    i16 = xData->size[0] * xData->size[1];
    xData->size[0] = 1;
    xData->size[1] = nodes->size[1];
    emxEnsureCapacity_real_T1(&b_st, xData, i16, &mc_emlrtRTEI);
    loop_ub = nodes->size[1];
    for (i16 = 0; i16 < loop_ub; i16++) {
      xData->data[i16] = 0.0;
    }

    i16 = spTime->size[0] * spTime->size[1];
    spTime->size[0] = 1;
    spTime->size[1] = nodes->size[1];
    emxEnsureCapacity_real_T1(&b_st, spTime, i16, &nc_emlrtRTEI);
    loop_ub = nodes->size[1];
    for (i16 = 0; i16 < loop_ub; i16++) {
      spTime->data[i16] = 0.0;
    }

    i = 1;
    while (i - 1 <= N) {
      i16 = b_nodes->size[1];
      if (!((i >= 1) && (i <= i16))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&ld_emlrtBCI,
          &b_st);
      }

      i16 = xData->size[1];
      if (!((i >= 1) && (i <= i16))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&md_emlrtBCI,
          &b_st);
      }

      xData->data[xData->size[0] * (i - 1)] = b_nodes->data[i - 1].x;
      i16 = b_nodes->size[1];
      i17 = (i - 1) + 1;
      if (!((i17 >= 1) && (i17 <= i16))) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)&hc_emlrtBCI,
          &b_st);
      }

      i16 = spTime->size[1];
      if (!((i >= 1) && (i <= i16))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&nd_emlrtBCI,
          &b_st);
      }

      spTime->data[spTime->size[0] * (i - 1)] = 0.0;
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&b_st);
      }
    }

    emlrtForLoopVectorCheckR2012b(2.0, 1.0, tTotal + 1.0, mxDOUBLE_CLASS,
      (int32_T)((tTotal + 1.0) + -1.0), (emlrtRTEInfo *)&gd_emlrtRTEI, &b_st);
    t = 2.0;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub <= (int32_T)((tTotal + 1.0) + -1.0) - 1)) {
      t = 2.0 + (real_T)loop_ub;
      i = 0;
      while (i <= N) {
        c_st.site = &ce_emlrtRSI;
        d0 = 0.0;

        /* spTime = 0.0; nAct = 0; spTimePrev = 0.0; */
        i16 = b_nodes->size[1];
        i17 = 1 + i;
        if (!(i17 <= i16)) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)&lc_emlrtBCI,
            &c_st);
        }

        j = 1;
        while (j - 1 <= (int32_T)b_nodes->data[i].par.n - 1) {
          i16 = b_nodes->size[1];
          i17 = 1 + i;
          if (!(i17 <= i16)) {
            emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)
              &mc_emlrtBCI, &c_st);
          }

          i16 = b_nodes->size[1];
          i17 = 1 + i;
          if (!(i17 <= i16)) {
            emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)
              &nc_emlrtBCI, &c_st);
          }

          i16 = b_nodes->data[i].w->size[0];
          if (!((j >= 1) && (j <= i16))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i16, (emlrtBCInfo *)&id_emlrtBCI,
              &c_st);
          }

          i16 = b_nodes->size[1];
          i17 = b_nodes->data[i].neigh->size[0];
          if (!((j >= 1) && (j <= i17))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i17, (emlrtBCInfo *)&kd_emlrtBCI,
              &c_st);
          }

          i17 = (int32_T)b_nodes->data[i].neigh->data[j - 1];
          if (!((i17 >= 1) && (i17 <= i16))) {
            emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)
              &jd_emlrtBCI, &c_st);
          }

          d0 += b_nodes->data[i].w->data[j - 1] * b_nodes->data[i17 - 1].x;
          j++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&c_st);
          }
        }

        i16 = b_nodes->size[1];
        i17 = 1 + i;
        if (!(i17 <= i16)) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)&gd_emlrtBCI,
            &b_st);
        }

        b_nodes->data[i17 - 1].par.Isyn = d0;
        i16 = b_nodes->size[1];
        i17 = 1 + i;
        if (!(i17 <= i16)) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)&hd_emlrtBCI,
            &b_st);
        }

        b_nodes->data[i17 - 1].par.kInp = 1.0;
        i++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&b_st);
        }
      }

      /* isFullyActive = nodes(1).x > 0; */
      isFullyActive = true;
      i = 1;
      while (i - 1 <= N) {
        c_st.site = &de_emlrtRSI;

        /* (x, par) */
        /*      if (par.Iext + par.Isyn / par.W) > par.Theta */
        /*          x = 1; */
        /*          spTime = calcSpTime(i,nodes); */
        /*      end */
        i16 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i16))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&vc_emlrtBCI,
            &c_st);
        }

        d0 = b_nodes->data[i - 1].x;
        i16 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i16))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&wc_emlrtBCI,
            &c_st);
        }

        d1 = b_nodes->data[i - 1].par.spTime;
        if (b_nodes->data[i - 1].x == 0.0) {
          i16 = b_nodes->size[1];
          i17 = (i - 1) + 1;
          if (!((i17 >= 1) && (i17 <= i16))) {
            emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)
              &ic_emlrtBCI, &c_st);
          }

          i16 = b_nodes->size[1];
          i17 = (i - 1) + 1;
          if (!((i17 >= 1) && (i17 <= i16))) {
            emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)
              &jc_emlrtBCI, &c_st);
          }

          i16 = b_nodes->size[1];
          i17 = (i - 1) + 1;
          if (!((i17 >= 1) && (i17 <= i16))) {
            emlrtDynamicBoundsCheckR2012b(i17, 1, i16, (emlrtBCInfo *)
              &kc_emlrtBCI, &c_st);
          }

          i16 = b_nodes->size[1];
          if (!((i >= 1) && (i <= i16))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&xc_emlrtBCI,
              &c_st);
          }

          if (b_nodes->data[i - 1].par.Isyn / b_nodes->data[i - 1].par.W >
              b_nodes->data[i - 1].par.Theta) {
            d0 = 1.0;
            d_st.site = &ge_emlrtRSI;
            d1 = calcSpTime(&d_st, 1.0 + (real_T)(i - 1), b_nodes, 1.0);
          }
        }

        i16 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i16))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&yc_emlrtBCI,
            &b_st);
        }

        b_nodes->data[i - 1].x = d0;
        i16 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i16))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&ad_emlrtBCI,
            &b_st);
        }

        b_nodes->data[i - 1].par.spTime = d1;

        /* ElementIter(nodes(i).x, nodes(i).par); */
        i16 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i16))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&bd_emlrtBCI,
            &b_st);
        }

        i16 = xData->size[1];
        if (!((i >= 1) && (i <= i16))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&cd_emlrtBCI,
            &b_st);
        }

        xData->data[xData->size[0] * (i - 1)] = b_nodes->data[i - 1].x;
        i16 = b_nodes->size[1];
        if (!((i >= 1) && (i <= i16))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&dd_emlrtBCI,
            &b_st);
        }

        i16 = spTime->size[1];
        if (!((i >= 1) && (i <= i16))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&ed_emlrtBCI,
            &b_st);
        }

        spTime->data[spTime->size[0] * (i - 1)] = b_nodes->data[i - 1].
          par.spTime;
        if (isFullyActive) {
          i16 = b_nodes->size[1];
          if (!((i >= 1) && (i <= i16))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, i16, (emlrtBCInfo *)&fd_emlrtBCI,
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
        loop_ub++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&b_st);
        }
      }
    }

    /* netActTime = t - 1; */
  }

  emxFree_struct_T(&b_nodes);
  *netActTime = t;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (EvolveSINetwork.cpp) */
