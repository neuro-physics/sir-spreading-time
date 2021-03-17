/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * GetSimulationParam.cpp
 *
 * Code generation for function 'GetSimulationParam'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "NetworkActivationTime.h"
#include "GetSimulationParam.h"
#include "NetworkActivationTime_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "error.h"
#include "randperm.h"
#include "fillUpMatrix.h"
#include "assertValidSizeArg.h"
#include "sort1.h"
#include "strcmp.h"
#include "NetworkActivationTime_mexutil.h"
#include "NetworkActivationTime_data.h"

/* Variable Definitions */
static emlrtRSInfo ec_emlrtRSI = { 42, /* lineNo */
  "GetSimulationParam",                /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 49, /* lineNo */
  "GetSimulationParam",                /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 51, /* lineNo */
  "GetSimulationParam",                /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 52, /* lineNo */
  "GetSimulationParam",                /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 53, /* lineNo */
  "GetSimulationParam",                /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 54, /* lineNo */
  "GetSimulationParam",                /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 56, /* lineNo */
  "GetSimulationParam",                /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 58, /* lineNo */
  "GetSimulationParam",                /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 61, /* lineNo */
  "GetSimulationParam",                /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pathName */
};

static emlrtRSInfo vd_emlrtRSI = { 145,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtMCInfo b_emlrtMCI = { 27,  /* lineNo */
  5,                                   /* colNo */
  "error",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\lang\\error.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 1, /* lineNo */
  10,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 49,/* lineNo */
  23,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 62,/* lineNo */
  9,                                   /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 54,/* lineNo */
  22,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 106,/* lineNo */
  13,                                  /* colNo */
  "combineVectorElements",             /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 54,/* lineNo */
  18,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 55,/* lineNo */
  9,                                   /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 56,/* lineNo */
  26,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 56,/* lineNo */
  19,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 54,/* lineNo */
  9,                                   /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = { 48,/* lineNo */
  9,                                   /* colNo */
  "sumprod",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  49,                                  /* lineNo */
  13,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pName */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  21,                                  /* colNo */
  "p.seeds",                           /* aName */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  17,                                  /* colNo */
  "s",                                 /* aName */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  15,                                  /* colNo */
  "s",                                 /* aName */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 39,    /* lineNo */
  27,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 39,  /* lineNo */
  27,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 64,  /* lineNo */
  23,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 39,  /* lineNo */
  5,                                   /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 39,  /* lineNo */
  5,                                   /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 64,  /* lineNo */
  9,                                   /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRSInfo ne_emlrtRSI = { 27, /* lineNo */
  "error",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\lang\\error.m"/* pathName */
};

/* Function Declarations */
static void e_error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);

/* Function Definitions */
static void e_error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "error", true, location);
}

void GetSimulationParam(const emlrtStack *sp, const emxArray_real_T *A, real_T
  nSeeds, real_T isCompetitive, const emxArray_char_T *seedType, const
  emxArray_real_T *seedInd, real_T nSim, real_T *p_N, real_T *p_nSeeds, real_T
  *p_isCompetitive, emxArray_real_T *p_seeds, real_T *p_nSim, emxArray_char_T
  *p_seedType, real_T *p_seedTrial, emxArray_real_T *p_x0)
{
  int32_T b_p_N;
  int32_T ibmat;
  int32_T xpageoffset;
  emxArray_real_T *s;
  boolean_T overflow;
  int32_T i;
  emxArray_int32_T *r2;
  int32_T exitg1;
  emxArray_boolean_T *x;
  int32_T iv1[2];
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv2[2] = { 1, 27 };

  static const char_T varargin_1[27] = { 'G', 'e', 't', 'S', 'i', 'm', 'u', 'l',
    'a', 't', 'i', 'o', 'n', 'P', 'a', 'r', 'a', 'm', ':', 's', 'e', 'e', 'd',
    'T', 'y', 'p', 'e' };

  const mxArray *b_y;
  static const int32_T iv3[2] = { 1, 22 };

  static const char_T varargin_2[22] = { 'U', 'n', 'r', 'e', 'c', 'o', 'g', 'n',
    'i', 'z', 'e', 'd', ' ', 's', 'e', 'e', 'd', ' ', 't', 'y', 'p', 'e' };

  static const char_T cv2[5] = { 'f', 'i', 'x', 'e', 'd' };

  boolean_T p;
  static const char_T cv3[8] = { 'm', 'o', 's', 't', 'c', 'o', 'n', 'n' };

  int32_T vlen;
  uint32_T sz[2];
  emxArray_real_T *a;
  static const int32_T iv4[2] = { 1, 15 };

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

  /*  A -> adj matrix */
  /*  nSeeds -> amount of initial seeds for activity (must be equal to the GetNodes nSeeds */
  /*  isCompetitive -> determines whether the seeds are competitive (diff states) or cooperative (eq states) */
  /*  seedType -> 'random': randomly select seeds */
  /*              'fixed': select fixed seedInd for every trial + a quantity of (nSeeds-numel(seedInd)) seeds in 1:size(A,1); */
  /*              'mostconn': selects the nSeeds most connected nodes as seeds */
  /*  seedInd -> double(1:nSim,1:nSeeds) index of 'fixed' seeds */
  /*             if there is less rows than nSim, the remaining rows are a periodic repetition of seedInd(:,:) */
  /*             if there is less columns than nSeeds, the remaining cols are going to be filled up with random seeds */
  /*  nSim -> number seed trials */
  /*  */
  /*  return: */
  /*  p struct with fields: */
  /*  .N -> network total number of elements */
  /*  .nSeeds -> same as input */
  /*  .isCompetitive -> same as input */
  /*  .seeds -> double(1:nSim,1:nSeeds); each line is a seed trial */
  /*  .seedTrial -> a counter for sim functions to determine which seed trial (out of .seeds) to take */
  /*  .nSim -> number of seed trials */
  /*  .seedType -> same as input */
  /*  .x0 -> double(1,1:nSeeds); initial condition for each of the seed nodes */
  /*  */
  b_p_N = A->size[0];
  ibmat = p_seeds->size[0] * p_seeds->size[1];
  p_seeds->size[0] = (int32_T)nSim;
  if (!(nSeeds >= 0.0)) {
    emlrtNonNegativeCheckR2012b(nSeeds, (emlrtDCInfo *)&b_emlrtDCI, sp);
  }

  if (nSeeds != (int32_T)muDoubleScalarFloor(nSeeds)) {
    emlrtIntegerCheckR2012b(nSeeds, (emlrtDCInfo *)&emlrtDCI, sp);
  }

  p_seeds->size[1] = (int32_T)nSeeds;
  emxEnsureCapacity_real_T1(sp, p_seeds, ibmat, &r_emlrtRTEI);
  if (!(nSeeds >= 0.0)) {
    emlrtNonNegativeCheckR2012b(nSeeds, (emlrtDCInfo *)&e_emlrtDCI, sp);
  }

  if (nSeeds != (int32_T)muDoubleScalarFloor(nSeeds)) {
    emlrtIntegerCheckR2012b(nSeeds, (emlrtDCInfo *)&d_emlrtDCI, sp);
  }

  xpageoffset = (int32_T)nSim * (int32_T)nSeeds;
  for (ibmat = 0; ibmat < xpageoffset; ibmat++) {
    p_seeds->data[ibmat] = 0.0;
  }

  ibmat = p_seedType->size[0] * p_seedType->size[1];
  p_seedType->size[0] = 1;
  p_seedType->size[1] = seedType->size[1];
  emxEnsureCapacity_char_T(sp, p_seedType, ibmat, &r_emlrtRTEI);
  xpageoffset = seedType->size[0] * seedType->size[1];
  for (ibmat = 0; ibmat < xpageoffset; ibmat++) {
    p_seedType->data[ibmat] = seedType->data[ibmat];
  }

  emxInit_real_T(sp, &s, 2, &bb_emlrtRTEI, true);
  st.site = &ec_emlrtRSI;
  if (b_strcmp(&st, seedType)) {
    /*  generate random permutations... */
    /*  need to take care with the total amount of unique combinations of N, take nSeeds; */
    /*  s = N!/( (nSeeds)! * (N-nSeeds)!) is total number of unique combinations */
    /*  if s < nSim, then we can only take s maximum seed combinations, instead of nSim */
    /*     otherwise we will sample with replacement */
    i = 0;
    emxInit_int32_T(sp, &r2, 1, &cb_emlrtRTEI, true);
    while (i <= (int32_T)nSim - 1) {
      ibmat = p_seeds->size[0];
      xpageoffset = i + 1;
      if (!((xpageoffset >= 1) && (xpageoffset <= ibmat))) {
        emlrtDynamicBoundsCheckR2012b(xpageoffset, 1, ibmat, (emlrtBCInfo *)
          &y_emlrtBCI, sp);
      }

      xpageoffset = p_seeds->size[1];
      ibmat = r2->size[0];
      r2->size[0] = xpageoffset;
      emxEnsureCapacity_int32_T(sp, r2, ibmat, &s_emlrtRTEI);
      for (ibmat = 0; ibmat < xpageoffset; ibmat++) {
        r2->data[ibmat] = ibmat;
      }

      st.site = &fc_emlrtRSI;
      randperm(&st, (real_T)A->size[0], nSeeds, s);
      iv1[0] = 1;
      iv1[1] = r2->size[0];
      emlrtSubAssignSizeCheckR2012b(&iv1[0], 2, &(*(int32_T (*)[2])s->size)[0],
        2, (emlrtECInfo *)&b_emlrtECI, sp);
      xpageoffset = s->size[1];
      for (ibmat = 0; ibmat < xpageoffset; ibmat++) {
        p_seeds->data[i + p_seeds->size[0] * r2->data[ibmat]] = s->data[s->size
          [0] * ibmat];
      }

      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    emxFree_int32_T(&r2);
  } else {
    st.site = &gc_emlrtRSI;
    b_st.site = &nc_emlrtRSI;
    c_st.site = &oc_emlrtRSI;
    overflow = false;
    if (seedType->size[1] == 5) {
      xpageoffset = 0;
      do {
        exitg1 = 0;
        if (xpageoffset + 1 < 6) {
          d_st.site = &pc_emlrtRSI;
          if (!((uint8_T)seedType->data[xpageoffset] <= 127)) {
            emlrtErrorWithMessageIdR2012b(&d_st, &xc_emlrtRTEI,
              "Coder:toolbox:unsupportedString", 2, 12, 127);
          }

          d_st.site = &qc_emlrtRSI;
          d_st.site = &rc_emlrtRSI;
          e_st.site = &sc_emlrtRSI;
          f_st.site = &tc_emlrtRSI;
          if (!((uint8_T)seedType->data[xpageoffset] <= 127)) {
            emlrtErrorWithMessageIdR2012b(&f_st, &xc_emlrtRTEI,
              "Coder:toolbox:unsupportedString", 2, 12, 127);
          }

          d_st.site = &rc_emlrtRSI;
          e_st.site = &sc_emlrtRSI;
          f_st.site = &tc_emlrtRSI;
          if (cv1[(uint8_T)seedType->data[xpageoffset] & 127] != cv1[(int32_T)
              cv2[xpageoffset]]) {
            exitg1 = 1;
          } else {
            xpageoffset++;
          }
        } else {
          overflow = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (overflow) {
      st.site = &hc_emlrtRSI;
      fillUpMatrix(&st, seedInd, nSim, nSeeds, (real_T)A->size[0], p_seeds);
    } else {
      st.site = &ic_emlrtRSI;
      b_st.site = &nc_emlrtRSI;
      c_st.site = &oc_emlrtRSI;
      overflow = false;
      if (seedType->size[1] == 8) {
        xpageoffset = 0;
        do {
          exitg1 = 0;
          if (xpageoffset + 1 < 9) {
            d_st.site = &pc_emlrtRSI;
            if (!((uint8_T)seedType->data[xpageoffset] <= 127)) {
              emlrtErrorWithMessageIdR2012b(&d_st, &xc_emlrtRTEI,
                "Coder:toolbox:unsupportedString", 2, 12, 127);
            }

            d_st.site = &qc_emlrtRSI;
            d_st.site = &rc_emlrtRSI;
            e_st.site = &sc_emlrtRSI;
            f_st.site = &tc_emlrtRSI;
            if (!((uint8_T)seedType->data[xpageoffset] <= 127)) {
              emlrtErrorWithMessageIdR2012b(&f_st, &xc_emlrtRTEI,
                "Coder:toolbox:unsupportedString", 2, 12, 127);
            }

            d_st.site = &rc_emlrtRSI;
            e_st.site = &sc_emlrtRSI;
            f_st.site = &tc_emlrtRSI;
            if (cv1[(uint8_T)seedType->data[xpageoffset] & 127] != cv1[(int32_T)
                cv3[xpageoffset]]) {
              exitg1 = 1;
            } else {
              xpageoffset++;
            }
          } else {
            overflow = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }

      if (overflow) {
        emxInit_boolean_T(sp, &x, 2, &u_emlrtRTEI, true);
        st.site = &jc_emlrtRSI;
        ibmat = x->size[0] * x->size[1];
        x->size[0] = A->size[0];
        x->size[1] = A->size[1];
        emxEnsureCapacity_boolean_T(&st, x, ibmat, &u_emlrtRTEI);
        xpageoffset = A->size[0] * A->size[1];
        for (ibmat = 0; ibmat < xpageoffset; ibmat++) {
          x->data[ibmat] = (A->data[ibmat] != 0.0);
        }

        b_st.site = &ac_emlrtRSI;
        if (((x->size[0] == 1) && (x->size[1] == 1)) || (x->size[0] != 1)) {
          overflow = true;
        } else {
          overflow = false;
        }

        if (!overflow) {
          emlrtErrorWithMessageIdR2012b(&b_st, &rc_emlrtRTEI,
            "Coder:toolbox:autoDimIncompatibility", 0);
        }

        overflow = false;
        p = false;
        if ((x->size[0] != 0) || (x->size[1] != 0)) {
        } else {
          p = true;
        }

        if (p) {
          overflow = true;
        }

        if (overflow) {
          emlrtErrorWithMessageIdR2012b(&b_st, &wc_emlrtRTEI,
            "Coder:toolbox:UnsupportedSpecialEmpty", 0);
        }

        c_st.site = &bc_emlrtRSI;
        vlen = x->size[0];
        if ((x->size[0] == 0) || (x->size[1] == 0)) {
          for (ibmat = 0; ibmat < 2; ibmat++) {
            sz[ibmat] = (uint32_T)x->size[ibmat];
          }

          ibmat = s->size[0] * s->size[1];
          s->size[0] = 1;
          s->size[1] = (int32_T)sz[1];
          emxEnsureCapacity_real_T1(&c_st, s, ibmat, &w_emlrtRTEI);
          xpageoffset = (int32_T)sz[1];
          for (ibmat = 0; ibmat < xpageoffset; ibmat++) {
            s->data[ibmat] = 0.0;
          }
        } else {
          d_st.site = &cc_emlrtRSI;
          ibmat = s->size[0] * s->size[1];
          s->size[0] = 1;
          s->size[1] = x->size[1];
          emxEnsureCapacity_real_T1(&d_st, s, ibmat, &v_emlrtRTEI);
          e_st.site = &vd_emlrtRSI;
          overflow = (x->size[1] > 2147483646);
          if (overflow) {
            f_st.site = &r_emlrtRSI;
            g_st.site = &r_emlrtRSI;
            check_forloop_overflow_error(&g_st);
          }

          for (i = 0; i + 1 <= x->size[1]; i++) {
            xpageoffset = i * x->size[0];
            s->data[i] = x->data[xpageoffset];
            e_st.site = &dc_emlrtRSI;
            if ((!(2 > vlen)) && (vlen > 2147483646)) {
              f_st.site = &r_emlrtRSI;
              g_st.site = &r_emlrtRSI;
              check_forloop_overflow_error(&g_st);
            }

            for (ibmat = 2; ibmat <= vlen; ibmat++) {
              s->data[i] += (real_T)x->data[(xpageoffset + ibmat) - 1];
            }
          }
        }

        emxFree_boolean_T(&x);
        st.site = &jc_emlrtRSI;
        b_st.site = &ed_emlrtRSI;
        d_sort(&b_st, s);
        if (1.0 > nSeeds) {
          xpageoffset = 0;
        } else {
          ibmat = s->size[1];
          if (!(1 <= ibmat)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, ibmat, (emlrtBCInfo *)
              &bb_emlrtBCI, sp);
          }

          ibmat = s->size[1];
          xpageoffset = (int32_T)nSeeds;
          if (!((xpageoffset >= 1) && (xpageoffset <= ibmat))) {
            emlrtDynamicBoundsCheckR2012b(xpageoffset, 1, ibmat, (emlrtBCInfo *)
              &ab_emlrtBCI, sp);
          }
        }

        emxInit_real_T(sp, &a, 2, &y_emlrtRTEI, true);
        ibmat = s->size[0] * s->size[1];
        s->size[1] = xpageoffset;
        emxEnsureCapacity_real_T1(sp, s, ibmat, &x_emlrtRTEI);

        /*  gets nSeeds most connected elements for every simulation */
        st.site = &kc_emlrtRSI;
        ibmat = a->size[0] * a->size[1];
        a->size[0] = 1;
        a->size[1] = xpageoffset;
        emxEnsureCapacity_real_T1(&st, a, ibmat, &y_emlrtRTEI);
        for (ibmat = 0; ibmat < xpageoffset; ibmat++) {
          a->data[a->size[0] * ibmat] = s->data[ibmat];
        }

        b_st.site = &n_emlrtRSI;
        b_assertValidSizeArg(&b_st, nSim);
        xpageoffset = a->size[1];
        if (xpageoffset != a->size[1]) {
          y = NULL;
          m1 = emlrtCreateCharArray(2, iv4);
          emlrtInitCharArrayR2013a(&st, 15, m1, &cv0[0]);
          emlrtAssign(&y, m1);
          b_st.site = &me_emlrtRSI;
          d_error(&b_st, y, (emlrtMCInfo *)&emlrtMCI);
        }

        ibmat = p_seeds->size[0] * p_seeds->size[1];
        p_seeds->size[0] = (int32_T)nSim;
        p_seeds->size[1] = xpageoffset;
        emxEnsureCapacity_real_T1(&st, p_seeds, ibmat, &ab_emlrtRTEI);
        if (!(a->size[1] == 0)) {
          if ((int32_T)nSim == 0) {
            overflow = true;
          } else if (xpageoffset == 0) {
            overflow = true;
          } else {
            overflow = false;
          }

          if (!overflow) {
            b_st.site = &sd_emlrtRSI;
            overflow = (a->size[1] > 2147483646);
            if (overflow) {
              c_st.site = &r_emlrtRSI;
              d_st.site = &r_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }

            for (xpageoffset = 0; xpageoffset + 1 <= a->size[1]; xpageoffset++)
            {
              ibmat = xpageoffset * (int32_T)nSim;
              b_st.site = &td_emlrtRSI;
              if ((!(1 > (int32_T)nSim)) && ((int32_T)nSim > 2147483646)) {
                c_st.site = &r_emlrtRSI;
                d_st.site = &r_emlrtRSI;
                check_forloop_overflow_error(&d_st);
              }

              for (vlen = 1; vlen <= (int32_T)nSim; vlen++) {
                p_seeds->data[(ibmat + vlen) - 1] = a->data[xpageoffset];
              }
            }
          }
        }

        emxFree_real_T(&a);
      } else {
        st.site = &lc_emlrtRSI;
        y = NULL;
        m1 = emlrtCreateCharArray(2, iv2);
        emlrtInitCharArrayR2013a(&st, 27, m1, &varargin_1[0]);
        emlrtAssign(&y, m1);
        b_y = NULL;
        m1 = emlrtCreateCharArray(2, iv3);
        emlrtInitCharArrayR2013a(&st, 22, m1, &varargin_2[0]);
        emlrtAssign(&b_y, m1);
        b_st.site = &ne_emlrtRSI;
        e_error(&b_st, y, b_y, (emlrtMCInfo *)&b_emlrtMCI);
      }
    }
  }

  emxFree_real_T(&s);
  st.site = &mc_emlrtRSI;
  if (muDoubleScalarIsNaN(isCompetitive)) {
    b_st.site = &e_emlrtRSI;
    c_st.site = &e_emlrtRSI;
    error(&c_st);
  }

  if (isCompetitive != 0.0) {
    if (nSeeds < 1.0) {
      ibmat = p_x0->size[0] * p_x0->size[1];
      p_x0->size[0] = 1;
      p_x0->size[1] = 0;
      emxEnsureCapacity_real_T1(sp, p_x0, ibmat, &r_emlrtRTEI);
    } else if (muDoubleScalarIsInf(nSeeds) && (1.0 == nSeeds)) {
      ibmat = p_x0->size[0] * p_x0->size[1];
      p_x0->size[0] = 1;
      p_x0->size[1] = 1;
      emxEnsureCapacity_real_T1(sp, p_x0, ibmat, &r_emlrtRTEI);
      p_x0->data[0] = rtNaN;
    } else {
      ibmat = p_x0->size[0] * p_x0->size[1];
      p_x0->size[0] = 1;
      p_x0->size[1] = (int32_T)muDoubleScalarFloor(nSeeds - 1.0) + 1;
      emxEnsureCapacity_real_T1(sp, p_x0, ibmat, &t_emlrtRTEI);
      xpageoffset = (int32_T)muDoubleScalarFloor(nSeeds - 1.0);
      for (ibmat = 0; ibmat <= xpageoffset; ibmat++) {
        p_x0->data[p_x0->size[0] * ibmat] = 1.0 + (real_T)ibmat;
      }
    }
  } else {
    ibmat = p_x0->size[0] * p_x0->size[1];
    p_x0->size[0] = 1;
    if (nSeeds != (int32_T)muDoubleScalarFloor(nSeeds)) {
      emlrtIntegerCheckR2012b(nSeeds, (emlrtDCInfo *)&c_emlrtDCI, sp);
    }

    p_x0->size[1] = (int32_T)nSeeds;
    emxEnsureCapacity_real_T1(sp, p_x0, ibmat, &r_emlrtRTEI);
    if (nSeeds != (int32_T)muDoubleScalarFloor(nSeeds)) {
      emlrtIntegerCheckR2012b(nSeeds, (emlrtDCInfo *)&f_emlrtDCI, sp);
    }

    xpageoffset = (int32_T)nSeeds;
    for (ibmat = 0; ibmat < xpageoffset; ibmat++) {
      p_x0->data[ibmat] = 1.0;
    }
  }

  *p_N = b_p_N;
  *p_nSeeds = nSeeds;
  *p_isCompetitive = isCompetitive;
  *p_nSim = nSim;
  *p_seedTrial = 1.0;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (GetSimulationParam.cpp) */
