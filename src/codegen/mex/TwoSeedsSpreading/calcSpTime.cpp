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
#include "TwoSeedsSpreading.h"
#include "calcSpTime.h"
#include "TwoSeedsSpreading_data.h"

/* Variable Definitions */
static emlrtBCInfo rc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  21,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  46,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  75,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  80,                                  /* colNo */
  "nodes(i).w",                        /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  54,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  87,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  42,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  40,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  42,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  42,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  75,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  75,                                  /* colNo */
  "nodes(i).neigh",                    /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  30,                                  /* colNo */
  "nodes",                             /* aName */
  "calcSpTime",                        /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\calcSpTime.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = { -1, /* iFirst */
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
  int32_T i11;
  int32_T i12;
  int32_T j;
  int32_T i13;
  spTime = 0.0;
  nAct = 0.0;
  spTimePrev = 0.0;
  i11 = nodes->size[1];
  i12 = (int32_T)i;
  if (!((i12 >= 1) && (i12 <= i11))) {
    emlrtDynamicBoundsCheckR2012b(i12, 1, i11, (emlrtBCInfo *)&rc_emlrtBCI, sp);
  }

  j = 0;
  while (j <= (int32_T)nodes->data[(int32_T)i - 1].par.n - 1) {
    i11 = nodes->size[1];
    i12 = (int32_T)i;
    if (!((i12 >= 1) && (i12 <= i11))) {
      emlrtDynamicBoundsCheckR2012b(i12, 1, i11, (emlrtBCInfo *)&sc_emlrtBCI, sp);
    }

    i11 = nodes->size[1];
    i12 = (int32_T)i;
    if (!((i12 >= 1) && (i12 <= i11))) {
      emlrtDynamicBoundsCheckR2012b(i12, 1, i11, (emlrtBCInfo *)&uc_emlrtBCI, sp);
    }

    i11 = nodes->size[1];
    i12 = nodes->data[(int32_T)i - 1].neigh->size[0];
    if (!((j + 1 >= 1) && (j + 1 <= i12))) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i12, (emlrtBCInfo *)&ad_emlrtBCI,
        sp);
    }

    i12 = (int32_T)nodes->data[(int32_T)i - 1].neigh->data[j];
    if (!((i12 >= 1) && (i12 <= i11))) {
      emlrtDynamicBoundsCheckR2012b(i12, 1, i11, (emlrtBCInfo *)&tc_emlrtBCI, sp);
    }

    i11 = nodes->data[(int32_T)i - 1].w->size[0];
    i12 = j + 1;
    if (!((i12 >= 1) && (i12 <= i11))) {
      emlrtDynamicBoundsCheckR2012b(i12, 1, i11, (emlrtBCInfo *)&vc_emlrtBCI, sp);
    }

    spTime += (real_T)(nodes->data[(int32_T)nodes->data[(int32_T)i - 1]
                       .neigh->data[j] - 1].x == x) / nodes->data[(int32_T)i - 1]
      .w->data[j];

    /*  summing up the inverse weights (sp times) of active neighbors to reach i */
    i11 = nodes->size[1];
    i12 = (int32_T)i;
    if (!((i12 >= 1) && (i12 <= i11))) {
      emlrtDynamicBoundsCheckR2012b(i12, 1, i11, (emlrtBCInfo *)&wc_emlrtBCI, sp);
    }

    i11 = nodes->size[1];
    i12 = (int32_T)i;
    if (!((i12 >= 1) && (i12 <= i11))) {
      emlrtDynamicBoundsCheckR2012b(i12, 1, i11, (emlrtBCInfo *)&xc_emlrtBCI, sp);
    }

    i11 = nodes->size[1];
    i12 = nodes->data[(int32_T)i - 1].neigh->size[0];
    if (!((j + 1 >= 1) && (j + 1 <= i12))) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i12, (emlrtBCInfo *)&cd_emlrtBCI,
        sp);
    }

    i12 = (int32_T)nodes->data[(int32_T)i - 1].neigh->data[j];
    if (!((i12 >= 1) && (i12 <= i11))) {
      emlrtDynamicBoundsCheckR2012b(i12, 1, i11, (emlrtBCInfo *)&bd_emlrtBCI, sp);
    }

    i11 = nodes->size[1];
    i13 = nodes->data[(int32_T)i - 1].neigh->size[0];
    if (!((j + 1 >= 1) && (j + 1 <= i13))) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i13, (emlrtBCInfo *)&ed_emlrtBCI,
        sp);
    }

    i13 = (int32_T)nodes->data[(int32_T)i - 1].neigh->data[j];
    if (!((i13 >= 1) && (i13 <= i11))) {
      emlrtDynamicBoundsCheckR2012b(i13, 1, i11, (emlrtBCInfo *)&dd_emlrtBCI, sp);
    }

    spTimePrev += (real_T)(nodes->data[i12 - 1].x == x) * nodes->data[i13 - 1].
      par.spTime;

    /*  summing up the sp time to reach each of the active neighbors */
    i11 = nodes->size[1];
    i12 = (int32_T)i;
    if (!((i12 >= 1) && (i12 <= i11))) {
      emlrtDynamicBoundsCheckR2012b(i12, 1, i11, (emlrtBCInfo *)&yc_emlrtBCI, sp);
    }

    i11 = nodes->size[1];
    i12 = nodes->data[(int32_T)i - 1].neigh->size[0];
    if (!((j + 1 >= 1) && (j + 1 <= i12))) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i12, (emlrtBCInfo *)&gd_emlrtBCI,
        sp);
    }

    i12 = (int32_T)nodes->data[(int32_T)i - 1].neigh->data[j];
    if (!((i12 >= 1) && (i12 <= i11))) {
      emlrtDynamicBoundsCheckR2012b(i12, 1, i11, (emlrtBCInfo *)&fd_emlrtBCI, sp);
    }

    nAct += (real_T)(nodes->data[i12 - 1].x == x);

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
