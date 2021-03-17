/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * UpdateInput1Seed.cpp
 *
 * Code generation for function 'UpdateInput1Seed'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EvolveSINetwork.h"
#include "UpdateInput1Seed.h"
#include "EvolveSINetwork_data.h"

/* Variable Definitions */
static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  21,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo t_emlrtRTEI = { 3, /* lineNo */
  13,                                  /* colNo */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m"/* pName */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  29,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  52,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  23,                                  /* colNo */
  "nodes(i).w",                        /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 4,   /* lineNo */
  40,                                  /* colNo */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "UpdateInput1Seed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInput1Seed.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
real_T UpdateInput1Seed(const emlrtStack *sp, real_T i, const emxArray_struct0_T
  *nodes)
{
  real_T Isyn;
  int32_T i5;
  int32_T i6;
  int32_T j;
  real_T d2;
  Isyn = 0.0;

  /* spTime = 0.0; nAct = 0; spTimePrev = 0.0; */
  i5 = nodes->size[1];
  i6 = (int32_T)i;
  if (!((i6 >= 1) && (i6 <= i5))) {
    emlrtDynamicBoundsCheckR2012b(i6, 1, i5, (emlrtBCInfo *)&w_emlrtBCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nodes->data[(int32_T)i - 1].par.n,
    mxDOUBLE_CLASS, (int32_T)nodes->data[(int32_T)i - 1].par.n, (emlrtRTEInfo *)
    &t_emlrtRTEI, sp);
  j = 1;
  while (j - 1 <= (int32_T)nodes->data[(int32_T)i - 1].par.n - 1) {
    i5 = nodes->size[1];
    i6 = (int32_T)i;
    if (!((i6 >= 1) && (i6 <= i5))) {
      emlrtDynamicBoundsCheckR2012b(i6, 1, i5, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    i5 = nodes->size[1];
    i6 = (int32_T)i;
    if (!((i6 >= 1) && (i6 <= i5))) {
      emlrtDynamicBoundsCheckR2012b(i6, 1, i5, (emlrtBCInfo *)&y_emlrtBCI, sp);
    }

    i5 = nodes->data[(int32_T)i - 1].w->size[0];
    if (!((j >= 1) && (j <= i5))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i5, (emlrtBCInfo *)&ab_emlrtBCI, sp);
    }

    i5 = nodes->size[1];
    i6 = nodes->data[(int32_T)i - 1].neigh->size[0];
    if (!((j >= 1) && (j <= i6))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i6, (emlrtBCInfo *)&cb_emlrtBCI, sp);
    }

    d2 = nodes->data[(int32_T)i - 1].neigh->data[j - 1];
    if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
      emlrtIntegerCheckR2012b(d2, (emlrtDCInfo *)&f_emlrtDCI, sp);
    }

    i6 = (int32_T)d2;
    if (!((i6 >= 1) && (i6 <= i5))) {
      emlrtDynamicBoundsCheckR2012b(i6, 1, i5, (emlrtBCInfo *)&bb_emlrtBCI, sp);
    }

    Isyn += nodes->data[(int32_T)i - 1].w->data[j - 1] * nodes->data[i6 - 1].x;
    j++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  return Isyn;
}

/* End of code generation (UpdateInput1Seed.cpp) */
