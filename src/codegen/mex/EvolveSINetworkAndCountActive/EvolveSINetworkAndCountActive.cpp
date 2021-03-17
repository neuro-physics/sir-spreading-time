/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvolveSINetworkAndCountActive.cpp
 *
 * Code generation for function 'EvolveSINetworkAndCountActive'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EvolveSINetworkAndCountActive.h"
#include "EvolveSINetworkAndCountActive_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 5,     /* lineNo */
  "EvolveSINetworkAndCountActive",     /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetworkAndCountActive.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 10,  /* lineNo */
  "EvolveSINetworkAndCountActive",     /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetworkAndCountActive.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 10,  /* lineNo */
  "SIElementIter",                     /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m"/* pathName */
};

static emlrtRTEInfo b_emlrtRTEI = { 3, /* lineNo */
  13,                                  /* colNo */
  "EvolveSINetworkAndCountActive",     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetworkAndCountActive.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  20,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  48,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  68,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  21,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = { 3, /* lineNo */
  13,                                  /* colNo */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m"/* pName */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  46,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 4,     /* lineNo */
  40,                                  /* colNo */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  75,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  80,                                  /* colNo */
  "nodes(i).w",                        /* aName */
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

static emlrtDCInfo b_emlrtDCI = { 5,   /* lineNo */
  48,                                  /* colNo */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  48,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  87,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 5,   /* lineNo */
  81,                                  /* colNo */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  81,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  42,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 6,   /* lineNo */
  36,                                  /* colNo */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  36,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  21,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = { 3, /* lineNo */
  13,                                  /* colNo */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m"/* pName */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  29,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  52,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  12,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetworkAndCountActive",     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetworkAndCountActive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  22,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  80,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetworkAndCountActive",     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetworkAndCountActive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  43,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetworkAndCountActive",     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetworkAndCountActive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  48,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  81,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  36,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetworkAndCountActive",     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetworkAndCountActive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  32,                                  /* colNo */
  "nodes",                             /* aName */
  "EvolveSINetworkAndCountActive",     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\EvolveSINetworkAndCountActive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  23,                                  /* colNo */
  "nodes(i).w",                        /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 4,   /* lineNo */
  40,                                  /* colNo */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
real_T EvolveSINetworkAndCountActive(const emlrtStack *sp, emxArray_struct0_T
  *nodes, real_T tTotal)
{
  real_T nn;
  int32_T N;
  int32_T t;
  boolean_T exitg1;
  int32_T i;
  int32_T i0;
  boolean_T isNetActive;
  real_T d0;
  int32_T i1;
  int32_T j;
  real_T d1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  N = nodes->size[1] - 1;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, tTotal, mxDOUBLE_CLASS, (int32_T)
    tTotal, (emlrtRTEInfo *)&b_emlrtRTEI, sp);
  t = 0;
  exitg1 = false;
  while ((!exitg1) && (t <= (int32_T)tTotal - 1)) {
    i = 0;
    while (i <= N) {
      st.site = &emlrtRSI;
      d0 = 0.0;

      /* spTime = 0.0; nAct = 0; spTimePrev = 0.0; */
      i0 = nodes->size[1];
      i1 = i + 1;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&o_emlrtBCI, &st);
      }

      emlrtForLoopVectorCheckR2012b(1.0, 1.0, nodes->data[i].par.n,
        mxDOUBLE_CLASS, (int32_T)nodes->data[i].par.n, (emlrtRTEInfo *)
        &d_emlrtRTEI, &st);
      j = 1;
      while (j - 1 <= (int32_T)nodes->data[i].par.n - 1) {
        i0 = nodes->size[1];
        i1 = i + 1;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&p_emlrtBCI,
            &st);
        }

        i0 = nodes->size[1];
        i1 = i + 1;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&q_emlrtBCI,
            &st);
        }

        i0 = nodes->data[i].w->size[0];
        if (!((j >= 1) && (j <= i0))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, i0, (emlrtBCInfo *)&eb_emlrtBCI,
            &st);
        }

        i0 = nodes->size[1];
        i1 = nodes->data[i].neigh->size[0];
        if (!((j >= 1) && (j <= i1))) {
          emlrtDynamicBoundsCheckR2012b(j, 1, i1, (emlrtBCInfo *)&gb_emlrtBCI,
            &st);
        }

        d1 = nodes->data[i].neigh->data[j - 1];
        if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
          emlrtIntegerCheckR2012b(d1, (emlrtDCInfo *)&e_emlrtDCI, &st);
        }

        i1 = (int32_T)d1;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&fb_emlrtBCI,
            &st);
        }

        d0 += nodes->data[i].w->data[j - 1] * nodes->data[i1 - 1].x;
        j++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      i0 = nodes->size[1];
      i1 = 1 + i;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&cb_emlrtBCI, sp);
      }

      nodes->data[i1 - 1].par.Isyn = d0;
      i0 = nodes->size[1];
      i1 = 1 + i;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&db_emlrtBCI, sp);
      }

      nodes->data[i1 - 1].par.kInp = 1.0;
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /* isNetActive = nodes(1).x > 0; */
    isNetActive = true;
    i = 0;
    while (i <= N) {
      st.site = &b_emlrtRSI;

      /* (x, par) */
      /*      if (par.Iext + par.Isyn / par.W) > par.Theta */
      /*          x = 1; */
      /*          spTime = calcSpTime(i,nodes); */
      /*      end */
      i0 = nodes->size[1];
      i1 = 1 + i;
      if (!(i1 <= i0)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&s_emlrtBCI, &st);
      }

      d0 = nodes->data[i1 - 1].x;
      i0 = nodes->size[1];
      i1 = 1 + i;
      if (!(i1 <= i0)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&emlrtBCI, &st);
      }

      if (nodes->data[i].x == 0.0) {
        i0 = nodes->size[1];
        i1 = 1 + i;
        if (!(i1 <= i0)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&b_emlrtBCI,
            &st);
        }

        i0 = nodes->size[1];
        i1 = 1 + i;
        if (!(i1 <= i0)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&c_emlrtBCI,
            &st);
        }

        i0 = nodes->size[1];
        i1 = 1 + i;
        if (!(i1 <= i0)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&t_emlrtBCI,
            &st);
        }

        i0 = nodes->size[1];
        j = 1 + i;
        if (!(j <= i0)) {
          emlrtDynamicBoundsCheckR2012b(j, 1, i0, (emlrtBCInfo *)&u_emlrtBCI,
            &st);
        }

        if (nodes->data[i1 - 1].par.Iext + nodes->data[i].par.Isyn / nodes->
            data[i].par.W > nodes->data[j - 1].par.Theta) {
          d0 = 1.0;
          b_st.site = &c_emlrtRSI;
          i0 = nodes->size[1];
          i1 = 1 + i;
          if (!(i1 <= i0)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&d_emlrtBCI,
              &b_st);
          }

          emlrtForLoopVectorCheckR2012b(1.0, 1.0, nodes->data[i].par.n,
            mxDOUBLE_CLASS, (int32_T)nodes->data[i].par.n, (emlrtRTEInfo *)
            &c_emlrtRTEI, &b_st);
          j = 1;
          while (j - 1 <= (int32_T)nodes->data[i].par.n - 1) {
            i0 = nodes->size[1];
            i1 = 1 + i;
            if (!(i1 <= i0)) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)
                &e_emlrtBCI, &b_st);
            }

            i0 = nodes->size[1];
            i1 = 1 + i;
            if (!(i1 <= i0)) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)
                &g_emlrtBCI, &b_st);
            }

            i0 = nodes->data[i].neigh->size[0];
            if (!((j >= 1) && (j <= i0))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i0, (emlrtBCInfo *)&x_emlrtBCI,
                &b_st);
            }

            d1 = nodes->data[i].neigh->data[j - 1];
            if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
              emlrtIntegerCheckR2012b(d1, (emlrtDCInfo *)&emlrtDCI, &b_st);
            }

            i0 = nodes->size[1];
            i1 = (int32_T)d1;
            if (!((i1 >= 1) && (i1 <= i0))) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)
                &f_emlrtBCI, &b_st);
            }

            i0 = nodes->data[i].w->size[0];
            i1 = (j - 1) + 1;
            if (!((i1 >= 1) && (i1 <= i0))) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)
                &h_emlrtBCI, &b_st);
            }

            /*  summing up the inverse weights (sp times) of active neighbors to reach i */
            i0 = nodes->size[1];
            i1 = 1 + i;
            if (!(i1 <= i0)) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)
                &i_emlrtBCI, &b_st);
            }

            i0 = nodes->size[1];
            i1 = 1 + i;
            if (!(i1 <= i0)) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)
                &k_emlrtBCI, &b_st);
            }

            i0 = nodes->data[i].neigh->size[0];
            if (!((j >= 1) && (j <= i0))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i0, (emlrtBCInfo *)&y_emlrtBCI,
                &b_st);
            }

            d1 = nodes->data[i].neigh->data[j - 1];
            if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
              emlrtIntegerCheckR2012b(d1, (emlrtDCInfo *)&b_emlrtDCI, &b_st);
            }

            i0 = nodes->size[1];
            i1 = (int32_T)d1;
            if (!((i1 >= 1) && (i1 <= i0))) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)
                &j_emlrtBCI, &b_st);
            }

            i0 = nodes->data[i].neigh->size[0];
            if (!((j >= 1) && (j <= i0))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i0, (emlrtBCInfo *)
                &ab_emlrtBCI, &b_st);
            }

            d1 = nodes->data[i].neigh->data[j - 1];
            if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
              emlrtIntegerCheckR2012b(d1, (emlrtDCInfo *)&c_emlrtDCI, &b_st);
            }

            i0 = nodes->size[1];
            i1 = (int32_T)d1;
            if (!((i1 >= 1) && (i1 <= i0))) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)
                &l_emlrtBCI, &b_st);
            }

            /*  summing up the sp time to reach each of the active neighbors */
            i0 = nodes->size[1];
            i1 = 1 + i;
            if (!(i1 <= i0)) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)
                &m_emlrtBCI, &b_st);
            }

            i0 = nodes->data[i].neigh->size[0];
            if (!((j >= 1) && (j <= i0))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i0, (emlrtBCInfo *)
                &bb_emlrtBCI, &b_st);
            }

            d1 = nodes->data[i].neigh->data[j - 1];
            if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
              emlrtIntegerCheckR2012b(d1, (emlrtDCInfo *)&d_emlrtDCI, &b_st);
            }

            i0 = nodes->size[1];
            i1 = (int32_T)d1;
            if (!((i1 >= 1) && (i1 <= i0))) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)
                &n_emlrtBCI, &b_st);
            }

            /*  x is either 0 or 1, so nAct is the total amount of active neighbors of i */
            j++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(&b_st);
            }
          }
        }
      }

      i0 = nodes->size[1];
      i1 = 1 + i;
      if (!(i1 <= i0)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&v_emlrtBCI, sp);
      }

      nodes->data[i1 - 1].x = d0;

      /* SIElementIter(nodes(i).x, nodes(i).par); */
      if (isNetActive) {
        i0 = nodes->size[1];
        i1 = 1 + i;
        if (!(i1 <= i0)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&w_emlrtBCI,
            sp);
        }

        if (nodes->data[i1 - 1].x > 0.0) {
          isNetActive = true;
        } else {
          isNetActive = false;
        }
      } else {
        isNetActive = false;
      }

      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    if (isNetActive) {
      exitg1 = true;
    } else {
      t++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  }

  nn = 0.0;
  i = 0;
  while (i <= N) {
    i0 = nodes->size[1];
    if (!((i + 1 >= 1) && (i + 1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, (emlrtBCInfo *)&r_emlrtBCI, sp);
    }

    if (nodes->data[i].x > 0.0) {
      nn++;
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  return nn;
}

/* End of code generation (EvolveSINetworkAndCountActive.cpp) */
