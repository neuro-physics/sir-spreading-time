/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * NetworkActivationTime.cpp
 *
 * Code generation for function 'NetworkActivationTime'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "NetworkActivationTime.h"
#include "NetworkActivationTime_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "EvolveSINetwork.h"
#include "GetSimulationParam.h"
#include "GetNodes.h"
#include "NetworkActivationTime_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 2,     /* lineNo */
  "NetworkActivationTime",             /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\NetworkActivationTime.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 4,   /* lineNo */
  "NetworkActivationTime",             /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\NetworkActivationTime.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 8,   /* lineNo */
  "NetworkActivationTime",             /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\NetworkActivationTime.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 9,   /* lineNo */
  "NetworkActivationTime",             /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\NetworkActivationTime.m"/* pathName */
};

static emlrtRSInfo he_emlrtRSI = { 13, /* lineNo */
  "max",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRSInfo ie_emlrtRSI = { 19, /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo je_emlrtRSI = { 140,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo ke_emlrtRSI = { 376,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo le_emlrtRSI = { 348,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 5,   /* lineNo */
  9,                                   /* colNo */
  "NetworkActivationTime",             /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\NetworkActivationTime.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 2, /* lineNo */
  5,                                   /* colNo */
  "NetworkActivationTime",             /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\NetworkActivationTime.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 4, /* lineNo */
  5,                                   /* colNo */
  "NetworkActivationTime",             /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\NetworkActivationTime.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 1, /* lineNo */
  18,                                  /* colNo */
  "NetworkActivationTime",             /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\NetworkActivationTime.m"/* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = { 39,/* lineNo */
  27,                                  /* colNo */
  "minOrMax",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = { 121,/* lineNo */
  27,                                  /* colNo */
  "minOrMax",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  14,                                  /* colNo */
  "T",                                 /* aName */
  "NetworkActivationTime",             /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\NetworkActivationTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  9,                                   /* colNo */
  "S",                                 /* aName */
  "NetworkActivationTime",             /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\NetworkActivationTime.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void NetworkActivationTime(const emlrtStack *sp, const emxArray_real_T *A,
  real_T Theta, real_T tTotal, real_T nSeeds, real_T isCompetitive, const
  emxArray_char_T *seedType, const emxArray_real_T *seedInd, emxArray_real_T *T,
  emxArray_real_T *S)
{
  emxArray_struct_T *n;
  c_struct_T p;
  int32_T ixstart;
  int32_T i;
  emxArray_real_T *unusedU0;
  emxArray_real_T *s;
  boolean_T overflow;
  int32_T b_n;
  real_T mtmp;
  int32_T ix;
  boolean_T exitg1;
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
  emxInit_struct_T(sp, &n, 2, &b_emlrtRTEI, true);
  emxInitStruct_struct_T(sp, &p, &c_emlrtRTEI, true);
  st.site = &emlrtRSI;
  GetNodes(&st, A, Theta, nSeeds, isCompetitive, n);
  st.site = &b_emlrtRSI;
  GetSimulationParam(&st, A, nSeeds, isCompetitive, seedType, seedInd, (real_T)
                     seedInd->size[0], &p.N, &p.nSeeds, &p.isCompetitive,
                     p.seeds, &p.nSim, p.seedType, &p.seedTrial, p.x0);
  ixstart = T->size[0];
  T->size[0] = seedInd->size[0];
  emxEnsureCapacity_real_T(sp, T, ixstart, &emlrtRTEI);
  ixstart = S->size[0];
  S->size[0] = seedInd->size[0];
  emxEnsureCapacity_real_T(sp, S, ixstart, &emlrtRTEI);
  i = 1;
  emxInit_real_T(sp, &unusedU0, 2, &d_emlrtRTEI, true);
  emxInit_real_T(sp, &s, 2, &d_emlrtRTEI, true);
  while (i - 1 <= seedInd->size[0] - 1) {
    ixstart = T->size[0];
    if (!((i >= 1) && (i <= ixstart))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, ixstart, (emlrtBCInfo *)&emlrtBCI, sp);
    }

    st.site = &c_emlrtRSI;
    EvolveSINetwork(&st, n, tTotal, &p, unusedU0, &T->data[i - 1], s);
    st.site = &d_emlrtRSI;
    b_st.site = &he_emlrtRSI;
    c_st.site = &ie_emlrtRSI;
    if ((s->size[1] == 1) || (s->size[1] != 1)) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (!overflow) {
      emlrtErrorWithMessageIdR2012b(&c_st, &oc_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (!(s->size[1] > 0)) {
      emlrtErrorWithMessageIdR2012b(&c_st, &pc_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    d_st.site = &je_emlrtRSI;
    ixstart = 1;
    b_n = s->size[1];
    mtmp = s->data[0];
    if (s->size[1] > 1) {
      if (muDoubleScalarIsNaN(s->data[0])) {
        e_st.site = &le_emlrtRSI;
        overflow = ((!(2 > s->size[1])) && (s->size[1] > 2147483646));
        if (overflow) {
          f_st.site = &r_emlrtRSI;
          g_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }

        ix = 2;
        exitg1 = false;
        while ((!exitg1) && (ix <= b_n)) {
          ixstart = ix;
          if (!muDoubleScalarIsNaN(s->data[ix - 1])) {
            mtmp = s->data[ix - 1];
            exitg1 = true;
          } else {
            ix++;
          }
        }
      }

      if (ixstart < s->size[1]) {
        e_st.site = &ke_emlrtRSI;
        overflow = ((!(ixstart + 1 > s->size[1])) && (s->size[1] > 2147483646));
        if (overflow) {
          f_st.site = &r_emlrtRSI;
          g_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }

        while (ixstart + 1 <= b_n) {
          if (s->data[ixstart] > mtmp) {
            mtmp = s->data[ixstart];
          }

          ixstart++;
        }
      }
    }

    ixstart = S->size[0];
    if (!((i >= 1) && (i <= ixstart))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, ixstart, (emlrtBCInfo *)&b_emlrtBCI,
        sp);
    }

    S->data[i - 1] = mtmp;

    /* T(i) = size(x,1); */
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&s);
  emxFree_real_T(&unusedU0);
  emxFreeStruct_struct_T1(&p);
  emxFree_struct_T(&n);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (NetworkActivationTime.cpp) */
