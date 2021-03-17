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
#include "NetworkActivationTime.h"
#include "calcSpTime.h"
#include "NetworkActivationTime_data.h"

/* Variable Definitions */
static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  21,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  46,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  75,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  80,                                  /* colNo */
  "nodes(i).w",                        /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  54,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  87,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  42,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  42,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  42,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  75,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  75,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  30,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  30,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
real_T calcSpTime(const emlrtStack *sp, real_T i, const emxArray_struct_T *nodes,
                  real_T x)
{
  real_T spTime;
  real_T nAct;
  real_T spTimePrev;
  int32_T i9;
  int32_T i10;
  int32_T j;
  int32_T i11;
  spTime = 0.0;
  nAct = 0.0;
  spTimePrev = 0.0;
  i9 = nodes->size[1];
  i10 = (int32_T)i;
  if (!((i10 >= 1) && (i10 <= i9))) {
    emlrtDynamicBoundsCheckR2012b(i10, 1, i9, (emlrtBCInfo *)&rb_emlrtBCI, sp);
  }

  j = 0;
  while (j <= (int32_T)nodes->data[(int32_T)i - 1].par.n - 1) {
    i9 = nodes->size[1];
    i10 = (int32_T)i;
    if (!((i10 >= 1) && (i10 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(i10, 1, i9, (emlrtBCInfo *)&sb_emlrtBCI, sp);
    }

    i9 = nodes->size[1];
    i10 = (int32_T)i;
    if (!((i10 >= 1) && (i10 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(i10, 1, i9, (emlrtBCInfo *)&ub_emlrtBCI, sp);
    }

    i9 = nodes->size[1];
    i10 = nodes->data[(int32_T)i - 1].neigh->size[0];
    if (!((j + 1 >= 1) && (j + 1 <= i10))) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i10, (emlrtBCInfo *)&ac_emlrtBCI,
        sp);
    }

    i10 = (int32_T)nodes->data[(int32_T)i - 1].neigh->data[j];
    if (!((i10 >= 1) && (i10 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(i10, 1, i9, (emlrtBCInfo *)&tb_emlrtBCI, sp);
    }

    i9 = nodes->data[(int32_T)i - 1].w->size[0];
    i10 = j + 1;
    if (!((i10 >= 1) && (i10 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(i10, 1, i9, (emlrtBCInfo *)&vb_emlrtBCI, sp);
    }

    spTime += (real_T)(nodes->data[(int32_T)nodes->data[(int32_T)i - 1]
                       .neigh->data[j] - 1].x == x) / nodes->data[(int32_T)i - 1]
      .w->data[j];

    /*  summing up the inverse weights (sp times) of active neighbors to reach i */
    i9 = nodes->size[1];
    i10 = (int32_T)i;
    if (!((i10 >= 1) && (i10 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(i10, 1, i9, (emlrtBCInfo *)&wb_emlrtBCI, sp);
    }

    i9 = nodes->size[1];
    i10 = (int32_T)i;
    if (!((i10 >= 1) && (i10 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(i10, 1, i9, (emlrtBCInfo *)&xb_emlrtBCI, sp);
    }

    i9 = nodes->size[1];
    i10 = nodes->data[(int32_T)i - 1].neigh->size[0];
    if (!((j + 1 >= 1) && (j + 1 <= i10))) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i10, (emlrtBCInfo *)&cc_emlrtBCI,
        sp);
    }

    i10 = (int32_T)nodes->data[(int32_T)i - 1].neigh->data[j];
    if (!((i10 >= 1) && (i10 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(i10, 1, i9, (emlrtBCInfo *)&bc_emlrtBCI, sp);
    }

    i9 = nodes->size[1];
    i11 = nodes->data[(int32_T)i - 1].neigh->size[0];
    if (!((j + 1 >= 1) && (j + 1 <= i11))) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i11, (emlrtBCInfo *)&ec_emlrtBCI,
        sp);
    }

    i11 = (int32_T)nodes->data[(int32_T)i - 1].neigh->data[j];
    if (!((i11 >= 1) && (i11 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(i11, 1, i9, (emlrtBCInfo *)&dc_emlrtBCI, sp);
    }

    spTimePrev += (real_T)(nodes->data[i10 - 1].x == x) * nodes->data[i11 - 1].
      par.spTime;

    /*  summing up the sp time to reach each of the active neighbors */
    i9 = nodes->size[1];
    i10 = (int32_T)i;
    if (!((i10 >= 1) && (i10 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(i10, 1, i9, (emlrtBCInfo *)&yb_emlrtBCI, sp);
    }

    i9 = nodes->size[1];
    i10 = nodes->data[(int32_T)i - 1].neigh->size[0];
    if (!((j + 1 >= 1) && (j + 1 <= i10))) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i10, (emlrtBCInfo *)&gc_emlrtBCI,
        sp);
    }

    i10 = (int32_T)nodes->data[(int32_T)i - 1].neigh->data[j];
    if (!((i10 >= 1) && (i10 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(i10, 1, i9, (emlrtBCInfo *)&fc_emlrtBCI, sp);
    }

    nAct += (real_T)(nodes->data[i10 - 1].x == x);

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
