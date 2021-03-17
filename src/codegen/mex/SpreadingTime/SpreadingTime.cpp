/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SpreadingTime.cpp
 *
 * Code generation for function 'SpreadingTime'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "SpreadingTime.h"
#include "SpreadingTime_emxutil.h"
#include "GetNodes.h"
#include "SpreadingTime_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 2,     /* lineNo */
  "SpreadingTime",                     /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadingTime.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 9,   /* lineNo */
  "SpreadingTime",                     /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadingTime.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 20, /* lineNo */
  "SpreadingTime",                     /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadingTime.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 17, /* lineNo */
  "SpreadNodeToNode",                  /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadNodeToNode.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 25, /* lineNo */
  "SpreadNodeToNode",                  /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadNodeToNode.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 10, /* lineNo */
  "SIElementIter",                     /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 4,   /* lineNo */
  9,                                   /* colNo */
  "SpreadingTime",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadingTime.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 2, /* lineNo */
  5,                                   /* colNo */
  "SpreadingTime",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadingTime.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 20,/* lineNo */
  40,                                  /* colNo */
  "SpreadingTime",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadingTime.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  14,                                  /* colNo */
  "T",                                 /* aName */
  "SpreadingTime",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadingTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  22,                                  /* colNo */
  "V",                                 /* aName */
  "SpreadingTime",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadingTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  30,                                  /* colNo */
  "S",                                 /* aName */
  "SpreadingTime",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadingTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo cb_emlrtRTEI = { 19,/* lineNo */
  13,                                  /* colNo */
  "SpreadingTime",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadingTime.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 9,/* lineNo */
  13,                                  /* colNo */
  "SpreadNodeToNode",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadNodeToNode.m"/* pName */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  28,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  48,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  68,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  21,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  46,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  75,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  80,                                  /* colNo */
  "nodes(i).w",                        /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  54,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  87,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  42,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  21,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  29,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  52,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  5,                                   /* colNo */
  "nodes",                             /* aName */
  "SpreadNodeToNode",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadNodeToNode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  12,                                  /* colNo */
  "nodes",                             /* aName */
  "SpreadNodeToNode",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadNodeToNode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  17,                                  /* colNo */
  "nodes",                             /* aName */
  "SpreadNodeToNode",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadNodeToNode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  9,                                   /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  80,                                  /* colNo */
  "nodes",                             /* aName */
  "SIElementIter",                     /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SIElementIter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "SpreadNodeToNode",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadNodeToNode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  25,                                  /* colNo */
  "nodes",                             /* aName */
  "SpreadNodeToNode",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadNodeToNode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  42,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  42,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  75,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  75,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  30,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  30,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  14,                                  /* colNo */
  "nodes",                             /* aName */
  "SpreadNodeToNode",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadNodeToNode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  33,                                  /* colNo */
  "nodes",                             /* aName */
  "SpreadNodeToNode",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\SpreadNodeToNode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  23,                                  /* colNo */
  "nodes(i).w",                        /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

/* Function Declarations */
static void SpreadNodeToNodeNTimes(const emlrtStack *sp, real_T i, real_T j,
  const emxArray_struct_T *nodes, real_T nSim, real_T tTotal, real_T *T, real_T *
  V, real_T *S);

/* Function Definitions */
static void SpreadNodeToNodeNTimes(const emlrtStack *sp, real_T i, real_T j,
  const emxArray_struct_T *nodes, real_T nSim, real_T tTotal, real_T *T, real_T *
  V, real_T *S)
{
  real_T nn;
  int32_T k;
  emxArray_struct_T *b_nodes;
  int32_T i7;
  int32_T loop_ub;
  real_T TT;
  real_T SS;
  int32_T N;
  int32_T t;
  int32_T exitg1;
  int32_T b_k;
  int32_T b_j;
  real_T d3;
  real_T nAct;
  real_T spTimePrev;
  int32_T i8;
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
  *T = 0.0;
  *S = 0.0;
  *V = 0.0;
  nn = 0.0;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nSim, mxDOUBLE_CLASS, (int32_T)nSim,
    (emlrtRTEInfo *)&cb_emlrtRTEI, sp);
  k = 0;
  emxInit_struct_T(sp, &b_nodes, 2, &p_emlrtRTEI, true);
  while (k <= (int32_T)nSim - 1) {
    st.site = &ac_emlrtRSI;
    i7 = b_nodes->size[0] * b_nodes->size[1];
    b_nodes->size[0] = 1;
    b_nodes->size[1] = nodes->size[1];
    emxEnsureCapacity_struct_T1(&st, b_nodes, i7, &p_emlrtRTEI);
    loop_ub = nodes->size[0] * nodes->size[1];
    for (i7 = 0; i7 < loop_ub; i7++) {
      emxCopyStruct_struct_T(&st, &b_nodes->data[i7], &nodes->data[i7],
        &p_emlrtRTEI);
    }

    TT = 0.0;
    SS = 0.0;
    if (!(i == j)) {
      i7 = nodes->size[1];
      loop_ub = (int32_T)i;
      if (!((loop_ub >= 1) && (loop_ub <= i7))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
          &nb_emlrtBCI, &st);
      }

      b_nodes->data[loop_ub - 1].x = 1.0;
      N = b_nodes->size[1] - 1;
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, tTotal, mxDOUBLE_CLASS, (int32_T)
        tTotal, (emlrtRTEInfo *)&db_emlrtRTEI, &st);
      t = 0;
      do {
        exitg1 = 0;
        if (t <= (int32_T)tTotal - 1) {
          /*          for k = 1:(i-1) */
          /*              [nodes(k).par.Isyn, nodes(k).par.kInp, nodes(k).par.spTime] = UpdateInput1Seed(k, nodes); */
          /*          end */
          /*          for k = (i+1):N */
          b_k = 0;
          while (b_k <= N) {
            /* nodes(i).par.spTime = 0.0; % forcing seed spTime == 0.0 so that it is not considered to calculate next spTime's */
            /* [nodes(k).par.Isyn, nodes(k).par.kInp, nodes(k).par.spTime] = UpdateInput1Seed(k, nodes); */
            b_st.site = &bc_emlrtRSI;
            TT = 0.0;

            /* spTime = 0.0; nAct = 0; spTimePrev = 0.0; */
            i7 = b_nodes->size[1];
            loop_ub = b_k + 1;
            if (!((loop_ub >= 1) && (loop_ub <= i7))) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                &kb_emlrtBCI, &b_st);
            }

            b_j = 1;
            while (b_j - 1 <= (int32_T)b_nodes->data[b_k].par.n - 1) {
              i7 = b_nodes->size[1];
              loop_ub = b_k + 1;
              if (!((loop_ub >= 1) && (loop_ub <= i7))) {
                emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                  &lb_emlrtBCI, &b_st);
              }

              i7 = b_nodes->size[1];
              loop_ub = b_k + 1;
              if (!((loop_ub >= 1) && (loop_ub <= i7))) {
                emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                  &mb_emlrtBCI, &b_st);
              }

              i7 = b_nodes->data[b_k].w->size[0];
              if (!((b_j >= 1) && (b_j <= i7))) {
                emlrtDynamicBoundsCheckR2012b(b_j, 1, i7, (emlrtBCInfo *)
                  &fc_emlrtBCI, &b_st);
              }

              i7 = b_nodes->size[1];
              loop_ub = b_nodes->data[b_k].neigh->size[0];
              if (!((b_j >= 1) && (b_j <= loop_ub))) {
                emlrtDynamicBoundsCheckR2012b(b_j, 1, loop_ub, (emlrtBCInfo *)
                  &hc_emlrtBCI, &b_st);
              }

              loop_ub = (int32_T)b_nodes->data[b_k].neigh->data[b_j - 1];
              if (!((loop_ub >= 1) && (loop_ub <= i7))) {
                emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                  &gc_emlrtBCI, &b_st);
              }

              TT += b_nodes->data[b_k].w->data[b_j - 1] * b_nodes->data[loop_ub
                - 1].x;
              b_j++;
              if (*emlrtBreakCheckR2012bFlagVar != 0) {
                emlrtBreakCheckR2012b(&b_st);
              }
            }

            i7 = b_nodes->size[1];
            loop_ub = 1 + b_k;
            if (!((loop_ub >= 1) && (loop_ub <= i7))) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                &dc_emlrtBCI, &st);
            }

            b_nodes->data[loop_ub - 1].par.Isyn = TT;
            i7 = b_nodes->size[1];
            loop_ub = 1 + b_k;
            if (!((loop_ub >= 1) && (loop_ub <= i7))) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                &ec_emlrtBCI, &st);
            }

            b_nodes->data[loop_ub - 1].par.kInp = 1.0;
            b_k++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(&st);
            }
          }

          /*          for k = 1:(i-1) */
          /*              nodes(k).x = SIElementIter(nodes(k).x, nodes(k).par); */
          /*          end */
          /*          for k = (i+1):N */
          b_k = 0;
          while (b_k <= N) {
            /* nodes(k).x = SIElementIter(nodes(k).x, nodes(k).par); */
            b_st.site = &cc_emlrtRSI;

            /* (x, par) */
            /*      if (par.Iext + par.Isyn / par.W) > par.Theta */
            /*          x = 1; */
            /*          spTime = calcSpTime(i,nodes); */
            /*      end */
            i7 = b_nodes->size[1];
            loop_ub = 1 + b_k;
            if (!(loop_ub <= i7)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                &qb_emlrtBCI, &b_st);
            }

            TT = b_nodes->data[loop_ub - 1].x;
            i7 = b_nodes->size[1];
            loop_ub = 1 + b_k;
            if (!(loop_ub <= i7)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                &rb_emlrtBCI, &b_st);
            }

            d3 = b_nodes->data[loop_ub - 1].par.spTime;
            if (b_nodes->data[b_k].x == 0.0) {
              i7 = b_nodes->size[1];
              loop_ub = 1 + b_k;
              if (!(loop_ub <= i7)) {
                emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                  &y_emlrtBCI, &b_st);
              }

              i7 = b_nodes->size[1];
              loop_ub = 1 + b_k;
              if (!(loop_ub <= i7)) {
                emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                  &ab_emlrtBCI, &b_st);
              }

              i7 = b_nodes->size[1];
              loop_ub = 1 + b_k;
              if (!(loop_ub <= i7)) {
                emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                  &bb_emlrtBCI, &b_st);
              }

              i7 = b_nodes->size[1];
              loop_ub = 1 + b_k;
              if (!(loop_ub <= i7)) {
                emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                  &sb_emlrtBCI, &b_st);
              }

              if (b_nodes->data[b_k].par.Isyn / b_nodes->data[b_k].par.W >
                  b_nodes->data[loop_ub - 1].par.Theta) {
                TT = 1.0;
                c_st.site = &dc_emlrtRSI;
                d3 = 0.0;
                nAct = 0.0;
                spTimePrev = 0.0;
                i7 = b_nodes->size[1];
                loop_ub = 1 + b_k;
                if (!(loop_ub <= i7)) {
                  emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                    &cb_emlrtBCI, &c_st);
                }

                b_j = 0;
                while (b_j <= (int32_T)b_nodes->data[b_k].par.n - 1) {
                  i7 = b_nodes->size[1];
                  loop_ub = 1 + b_k;
                  if (!(loop_ub <= i7)) {
                    emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                      &db_emlrtBCI, &c_st);
                  }

                  i7 = b_nodes->size[1];
                  loop_ub = 1 + b_k;
                  if (!(loop_ub <= i7)) {
                    emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                      &fb_emlrtBCI, &c_st);
                  }

                  i7 = b_nodes->size[1];
                  loop_ub = b_nodes->data[b_k].neigh->size[0];
                  if (!((b_j + 1 >= 1) && (b_j + 1 <= loop_ub))) {
                    emlrtDynamicBoundsCheckR2012b(b_j + 1, 1, loop_ub,
                      (emlrtBCInfo *)&vb_emlrtBCI, &c_st);
                  }

                  loop_ub = (int32_T)b_nodes->data[b_k].neigh->data[b_j];
                  if (!((loop_ub >= 1) && (loop_ub <= i7))) {
                    emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                      &eb_emlrtBCI, &c_st);
                  }

                  i7 = b_nodes->data[b_k].w->size[0];
                  loop_ub = b_j + 1;
                  if (!((loop_ub >= 1) && (loop_ub <= i7))) {
                    emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                      &gb_emlrtBCI, &c_st);
                  }

                  d3 += (real_T)(b_nodes->data[(int32_T)b_nodes->data[b_k].
                                 neigh->data[b_j] - 1].x == 1.0) / b_nodes->
                    data[b_k].w->data[b_j];

                  /*  summing up the inverse weights (sp times) of active neighbors to reach i */
                  i7 = b_nodes->size[1];
                  loop_ub = 1 + b_k;
                  if (!(loop_ub <= i7)) {
                    emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                      &hb_emlrtBCI, &c_st);
                  }

                  i7 = b_nodes->size[1];
                  loop_ub = 1 + b_k;
                  if (!(loop_ub <= i7)) {
                    emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                      &ib_emlrtBCI, &c_st);
                  }

                  i7 = b_nodes->size[1];
                  loop_ub = b_nodes->data[b_k].neigh->size[0];
                  if (!((b_j + 1 >= 1) && (b_j + 1 <= loop_ub))) {
                    emlrtDynamicBoundsCheckR2012b(b_j + 1, 1, loop_ub,
                      (emlrtBCInfo *)&xb_emlrtBCI, &c_st);
                  }

                  loop_ub = (int32_T)b_nodes->data[b_k].neigh->data[b_j];
                  if (!((loop_ub >= 1) && (loop_ub <= i7))) {
                    emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                      &wb_emlrtBCI, &c_st);
                  }

                  i7 = b_nodes->size[1];
                  i8 = b_nodes->data[b_k].neigh->size[0];
                  if (!((b_j + 1 >= 1) && (b_j + 1 <= i8))) {
                    emlrtDynamicBoundsCheckR2012b(b_j + 1, 1, i8, (emlrtBCInfo *)
                      &ac_emlrtBCI, &c_st);
                  }

                  i8 = (int32_T)b_nodes->data[b_k].neigh->data[b_j];
                  if (!((i8 >= 1) && (i8 <= i7))) {
                    emlrtDynamicBoundsCheckR2012b(i8, 1, i7, (emlrtBCInfo *)
                      &yb_emlrtBCI, &c_st);
                  }

                  spTimePrev += (real_T)(b_nodes->data[loop_ub - 1].x == 1.0) *
                    b_nodes->data[i8 - 1].par.spTime;

                  /*  summing up the sp time to reach each of the active neighbors */
                  i7 = b_nodes->size[1];
                  loop_ub = 1 + b_k;
                  if (!(loop_ub <= i7)) {
                    emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                      &jb_emlrtBCI, &c_st);
                  }

                  i7 = b_nodes->size[1];
                  loop_ub = b_nodes->data[b_k].neigh->size[0];
                  if (!((b_j + 1 >= 1) && (b_j + 1 <= loop_ub))) {
                    emlrtDynamicBoundsCheckR2012b(b_j + 1, 1, loop_ub,
                      (emlrtBCInfo *)&cc_emlrtBCI, &c_st);
                  }

                  loop_ub = (int32_T)b_nodes->data[b_k].neigh->data[b_j];
                  if (!((loop_ub >= 1) && (loop_ub <= i7))) {
                    emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                      &bc_emlrtBCI, &c_st);
                  }

                  nAct += (real_T)(b_nodes->data[loop_ub - 1].x == 1.0);

                  /*  x is either 0 or 1, so nAct is the total amount of active neighbors of i */
                  b_j++;
                  if (*emlrtBreakCheckR2012bFlagVar != 0) {
                    emlrtBreakCheckR2012b(&c_st);
                  }
                }

                if (nAct == 0.0) {
                  nAct = 1.0;
                }

                d3 = (d3 + spTimePrev) / nAct;
              }
            }

            i7 = b_nodes->size[1];
            loop_ub = 1 + b_k;
            if (!(loop_ub <= i7)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                &tb_emlrtBCI, &st);
            }

            b_nodes->data[loop_ub - 1].x = TT;
            i7 = b_nodes->size[1];
            loop_ub = 1 + b_k;
            if (!(loop_ub <= i7)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                &ub_emlrtBCI, &st);
            }

            b_nodes->data[loop_ub - 1].par.spTime = d3;
            b_k++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(&st);
            }
          }

          i7 = b_nodes->size[1];
          loop_ub = (int32_T)j;
          if (!((loop_ub >= 1) && (loop_ub <= i7))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
              &ob_emlrtBCI, &st);
          }

          if (b_nodes->data[loop_ub - 1].x > 0.0) {
            TT = 1.0 + (real_T)t;
            i7 = b_nodes->size[1];
            loop_ub = (int32_T)j;
            if (!((loop_ub >= 1) && (loop_ub <= i7))) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, (emlrtBCInfo *)
                &pb_emlrtBCI, &st);
            }

            SS = b_nodes->data[loop_ub - 1].par.spTime;

            /*  effective spreading time */
            exitg1 = 1;
          } else {
            t++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(&st);
            }
          }
        } else {
          TT = rtNaN;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (!muDoubleScalarIsNaN(TT)) {
      *T += TT;
      *V += TT * TT;
      *S += SS;
      nn++;
    }

    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_struct_T(&b_nodes);
  if (nn == 0.0) {
    /*  all TT were NaN */
    *T = rtNaN;
    *V = rtNaN;
    *S = rtNaN;
  } else {
    *T /= nn;
    *V = *V / nn - *T * *T;
    *S /= nn;
  }

  if (*V < 0.0) {
    *V = 0.0;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void SpreadingTime(const emlrtStack *sp, const emxArray_real_T *A, real_T Theta,
                   real_T nSim, real_T tTotal, emxArray_real_T *T,
                   emxArray_real_T *V, emxArray_real_T *S)
{
  emxArray_struct_T *nodes;
  int32_T N;
  int32_T i0;
  int32_T i;
  int32_T j;
  real_T d0;
  real_T d1;
  real_T d2;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_struct_T(sp, &nodes, 2, &b_emlrtRTEI, true);
  st.site = &emlrtRSI;
  GetNodes(&st, A, Theta, nodes);
  N = nodes->size[1] - 1;
  i0 = T->size[0] * T->size[1];
  T->size[0] = nodes->size[1];
  T->size[1] = nodes->size[1];
  emxEnsureCapacity_real_T(sp, T, i0, &emlrtRTEI);
  i0 = V->size[0] * V->size[1];
  V->size[0] = nodes->size[1];
  V->size[1] = nodes->size[1];
  emxEnsureCapacity_real_T(sp, V, i0, &emlrtRTEI);
  i0 = S->size[0] * S->size[1];
  S->size[0] = nodes->size[1];
  S->size[1] = nodes->size[1];
  emxEnsureCapacity_real_T(sp, S, i0, &emlrtRTEI);
  i = 1;
  while (i - 1 <= N) {
    j = 1;
    while (j - 1 <= N) {
      i0 = T->size[0];
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&emlrtBCI, sp);
      }

      i0 = T->size[1];
      if (!((j >= 1) && (j <= i0))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i0, (emlrtBCInfo *)&emlrtBCI, sp);
      }

      i0 = V->size[0];
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&b_emlrtBCI, sp);
      }

      i0 = V->size[1];
      if (!((j >= 1) && (j <= i0))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i0, (emlrtBCInfo *)&b_emlrtBCI, sp);
      }

      i0 = S->size[0];
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&c_emlrtBCI, sp);
      }

      i0 = S->size[1];
      if (!((j >= 1) && (j <= i0))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i0, (emlrtBCInfo *)&c_emlrtBCI, sp);
      }

      st.site = &b_emlrtRSI;
      SpreadNodeToNodeNTimes(&st, 1.0 + (real_T)(i - 1), 1.0 + (real_T)(j - 1),
        nodes, nSim, tTotal, &d0, &d1, &d2);
      S->data[(i + S->size[0] * (j - 1)) - 1] = d2;
      V->data[(i + V->size[0] * (j - 1)) - 1] = d1;
      T->data[(i + T->size[0] * (j - 1)) - 1] = d0;
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

  emxFree_struct_T(&nodes);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (SpreadingTime.cpp) */
