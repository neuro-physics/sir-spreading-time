/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * UpdateInputNSeed.cpp
 *
 * Code generation for function 'UpdateInputNSeed'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EvolveSINetwork.h"
#include "UpdateInputNSeed.h"
#include "rand.h"
#include "EvolveSINetwork_data.h"

/* Variable Definitions */
static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  21,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo q_emlrtRTEI = { 7, /* lineNo */
  13,                                  /* colNo */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m"/* pName */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  25,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo r_emlrtRTEI = { 10,/* lineNo */
  17,                                  /* colNo */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m"/* pName */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  35,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  59,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  29,                                  /* colNo */
  "nodes(i).w",                        /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  47,                                  /* colNo */
  "nodes",                             /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 11,    /* lineNo */
  47,                                  /* colNo */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  47,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "UpdateInputNSeed",                  /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\UpdateInputNSeed.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void UpdateInputNSeed(const emlrtStack *sp, real_T i, const emxArray_struct0_T
                      *nodes, real_T *Isyn, real_T *kMax)
{
  real_T IsynAnt;
  int32_T i0;
  int32_T i1;
  int32_T k;
  real_T IsynM;
  int32_T j;
  real_T d0;

  /* Isyn = zeros(1,nodes(i).par.nInp); */
  *kMax = 1.0;
  IsynAnt = rtMinusInf;
  *Isyn = 0.0;
  i0 = nodes->size[1];
  i1 = (int32_T)i;
  if (!((i1 >= 1) && (i1 <= i0))) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&emlrtBCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nodes->data[(int32_T)i - 1].par.nInp,
    mxDOUBLE_CLASS, (int32_T)nodes->data[(int32_T)i - 1].par.nInp, (emlrtRTEInfo
    *)&q_emlrtRTEI, sp);
  k = 0;
  while (k <= (int32_T)nodes->data[(int32_T)i - 1].par.nInp - 1) {
    /*  summing up contribution of color k */
    IsynM = 0.0;
    i0 = nodes->size[1];
    i1 = (int32_T)i;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&b_emlrtBCI, sp);
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, nodes->data[(int32_T)i - 1].par.n,
      mxDOUBLE_CLASS, (int32_T)nodes->data[(int32_T)i - 1].par.n, (emlrtRTEInfo *)
      &r_emlrtRTEI, sp);
    j = 1;
    while (j - 1 <= (int32_T)nodes->data[(int32_T)i - 1].par.n - 1) {
      i0 = nodes->size[1];
      i1 = (int32_T)i;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&c_emlrtBCI, sp);
      }

      i0 = nodes->size[1];
      i1 = (int32_T)i;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&d_emlrtBCI, sp);
      }

      i0 = nodes->data[(int32_T)i - 1].w->size[0];
      if (!((j >= 1) && (j <= i0))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i0, (emlrtBCInfo *)&e_emlrtBCI, sp);
      }

      i0 = nodes->size[1];
      i1 = nodes->data[(int32_T)i - 1].neigh->size[0];
      if (!((j >= 1) && (j <= i1))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i1, (emlrtBCInfo *)&g_emlrtBCI, sp);
      }

      d0 = nodes->data[(int32_T)i - 1].neigh->data[j - 1];
      if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
        emlrtIntegerCheckR2012b(d0, (emlrtDCInfo *)&emlrtDCI, sp);
      }

      i1 = (int32_T)d0;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, (emlrtBCInfo *)&f_emlrtBCI, sp);
      }

      IsynM += nodes->data[(int32_T)i - 1].w->data[j - 1] * (real_T)(nodes->
        data[i1 - 1].x == 1.0 + (real_T)k);
      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  selecting color of largest contribution */
    if (IsynM > IsynAnt) {
      *kMax = 1.0 + (real_T)k;
      *Isyn = IsynM;
    } else {
      if ((IsynM == IsynAnt) && (b_rand() > 0.5)) {
        *kMax = 1.0 + (real_T)k;
        *Isyn = IsynM;
      }
    }

    IsynAnt = IsynM;
    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

/* End of code generation (UpdateInputNSeed.cpp) */
