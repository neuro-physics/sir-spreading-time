/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calcSpTime.cpp
 *
 * Code generation for function 'calcSpTime'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EvolveSINetwork.h"
#include "calcSpTime.h"
#include "EvolveSINetwork_data.h"

/* Variable Definitions */
static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  21,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo s_emlrtRTEI = { 3, /* lineNo */
  13,                                  /* colNo */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m"/* pName */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  46,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 4,   /* lineNo */
  40,                                  /* colNo */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  75,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  80,                                  /* colNo */
  "nodes(i).w",                        /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  54,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  87,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  42,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  42,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 5,   /* lineNo */
  42,                                  /* colNo */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  42,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  75,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 5,   /* lineNo */
  75,                                  /* colNo */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  75,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  30,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 6,   /* lineNo */
  30,                                  /* colNo */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  30,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
real_T calcSpTime(const emlrtStack *sp, real_T i, const emxArray_struct0_T
                  *nodes, real_T x)
{
  real_T spTime;
  real_T nAct;
  real_T spTimePrev;
  int32_T i2;
  int32_T i3;
  int32_T j;
  real_T d1;
  int32_T i4;
  spTime = 0.0;
  nAct = 0.0;
  spTimePrev = 0.0;
  i2 = nodes->size[1];
  i3 = (int32_T)i;
  if (!((i3 >= 1) && (i3 <= i2))) {
    emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&h_emlrtBCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nodes->data[(int32_T)i - 1].par.n,
    mxDOUBLE_CLASS, (int32_T)nodes->data[(int32_T)i - 1].par.n, (emlrtRTEInfo *)
    &s_emlrtRTEI, sp);
  j = 0;
  while (j <= (int32_T)nodes->data[(int32_T)i - 1].par.n - 1) {
    i2 = nodes->size[1];
    i3 = (int32_T)i;
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&i_emlrtBCI, sp);
    }

    i2 = nodes->size[1];
    i3 = (int32_T)i;
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&k_emlrtBCI, sp);
    }

    i2 = nodes->data[(int32_T)i - 1].neigh->size[0];
    if (!((j + 1 >= 1) && (j + 1 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i2, (emlrtBCInfo *)&p_emlrtBCI, sp);
    }

    d1 = nodes->data[(int32_T)i - 1].neigh->data[j];
    if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
      emlrtIntegerCheckR2012b(d1, (emlrtDCInfo *)&b_emlrtDCI, sp);
    }

    i2 = nodes->size[1];
    i3 = (int32_T)d1;
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&j_emlrtBCI, sp);
    }

    i2 = nodes->data[(int32_T)i - 1].w->size[0];
    i3 = j + 1;
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&l_emlrtBCI, sp);
    }

    spTime += (real_T)(nodes->data[(int32_T)nodes->data[(int32_T)i - 1]
                       .neigh->data[j] - 1].x == x) / nodes->data[(int32_T)i - 1]
      .w->data[j];

    /*  summing up the inverse weights (sp times) of active neighbors to reach i */
    i2 = nodes->size[1];
    i3 = (int32_T)i;
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&m_emlrtBCI, sp);
    }

    i2 = nodes->size[1];
    i3 = (int32_T)i;
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&n_emlrtBCI, sp);
    }

    i2 = nodes->size[1];
    i3 = nodes->data[(int32_T)i - 1].neigh->size[0];
    if (!((j + 1 >= 1) && (j + 1 <= i3))) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i3, (emlrtBCInfo *)&r_emlrtBCI, sp);
    }

    d1 = nodes->data[(int32_T)i - 1].neigh->data[j];
    if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
      emlrtIntegerCheckR2012b(d1, (emlrtDCInfo *)&c_emlrtDCI, sp);
    }

    i3 = (int32_T)d1;
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&q_emlrtBCI, sp);
    }

    i2 = nodes->size[1];
    i4 = nodes->data[(int32_T)i - 1].neigh->size[0];
    if (!((j + 1 >= 1) && (j + 1 <= i4))) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i4, (emlrtBCInfo *)&t_emlrtBCI, sp);
    }

    d1 = nodes->data[(int32_T)i - 1].neigh->data[j];
    if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
      emlrtIntegerCheckR2012b(d1, (emlrtDCInfo *)&d_emlrtDCI, sp);
    }

    i4 = (int32_T)d1;
    if (!((i4 >= 1) && (i4 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, i2, (emlrtBCInfo *)&s_emlrtBCI, sp);
    }

    spTimePrev += (real_T)(nodes->data[i3 - 1].x == x) * nodes->data[i4 - 1].
      par.spTime;

    /*  summing up the sp time to reach each of the active neighbors */
    i2 = nodes->size[1];
    i3 = (int32_T)i;
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&o_emlrtBCI, sp);
    }

    i2 = nodes->size[1];
    i3 = nodes->data[(int32_T)i - 1].neigh->size[0];
    if (!((j + 1 >= 1) && (j + 1 <= i3))) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i3, (emlrtBCInfo *)&v_emlrtBCI, sp);
    }

    d1 = nodes->data[(int32_T)i - 1].neigh->data[j];
    if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
      emlrtIntegerCheckR2012b(d1, (emlrtDCInfo *)&e_emlrtDCI, sp);
    }

    i3 = (int32_T)d1;
    if (!((i3 >= 1) && (i3 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, (emlrtBCInfo *)&u_emlrtBCI, sp);
    }

    nAct += (real_T)(nodes->data[i3 - 1].x == x);

    /*  x is either 0 or 1, so nAct is the total amount of active neighbors of i */
    j++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  if (nAct == 0.0) {
    nAct = 1.0;
  }

  return (spTime + spTimePrev) / nAct;
}

/* End of code generation (calcSpTime.cpp) */
