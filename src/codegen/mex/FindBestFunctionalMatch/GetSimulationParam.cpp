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
#include "FindBestFunctionalMatch.h"
#include "GetSimulationParam.h"
#include "rand.h"
#include "FindBestFunctionalMatch_emxutil.h"
#include "mod.h"
#include "FindBestFunctionalMatch_data.h"

/* Variable Definitions */
static emlrtRSInfo x_emlrtRSI = { 49,  /* lineNo */
  "GetSimulationParam",                /* fcnName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 24,  /* lineNo */
  "randperm",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m"/* pathName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 1,/* lineNo */
  10,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 49,/* lineNo */
  23,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 62,/* lineNo */
  9,                                   /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 49,/* lineNo */
  28,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 62,/* lineNo */
  5,                                   /* colNo */
  "randperm",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 63,/* lineNo */
  5,                                   /* colNo */
  "randperm",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 64,/* lineNo */
  5,                                   /* colNo */
  "randperm",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 65,/* lineNo */
  5,                                   /* colNo */
  "randperm",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m"/* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = { 48,/* lineNo */
  17,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pName */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  21,                                  /* colNo */
  "p.seeds",                           /* aName */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  49,                                  /* lineNo */
  13,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m"/* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = { 23,/* lineNo */
  19,                                  /* colNo */
  "randperm",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m"/* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = { 20,/* lineNo */
  19,                                  /* colNo */
  "randperm",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m"/* pName */
};

static emlrtDCInfo b_emlrtDCI = { 39,  /* lineNo */
  21,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 39,  /* lineNo */
  21,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 39,  /* lineNo */
  27,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 39,  /* lineNo */
  27,                                  /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 39,  /* lineNo */
  5,                                   /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 39,  /* lineNo */
  5,                                   /* colNo */
  "GetSimulationParam",                /* fName */
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\src\\GetSimulationParam.m",/* pName */
  4                                    /* checkKind */
};

/* Function Definitions */
void GetSimulationParam(const emlrtStack *sp, const emxArray_real_T *A, real_T
  nSeeds, real_T nSim, real_T *p_N, real_T *p_nSeeds, boolean_T *p_isCompetitive,
  emxArray_real_T *p_seeds, real_T *p_nSim, char_T p_seedType[6], real_T
  *p_seedTrial, emxArray_real_T *p_x0)
{
  int32_T N;
  int32_T b_p_N;
  int32_T m;
  int32_T nleftm1;
  static const char_T seedType[6] = { 'r', 'a', 'n', 'd', 'o', 'm' };

  int32_T i;
  emxArray_int32_T *r4;
  emxArray_real_T *r5;
  emxArray_real_T *hashTbl;
  emxArray_real_T *link;
  emxArray_real_T *val;
  emxArray_real_T *loc;
  real_T t;
  int32_T iv5[2];
  real_T selectedLoc;
  real_T j;
  real_T b_i;
  real_T newEntry;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
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
  N = A->size[0];
  b_p_N = A->size[0];
  m = p_seeds->size[0] * p_seeds->size[1];
  if (!(nSim >= 0.0)) {
    emlrtNonNegativeCheckR2012b(nSim, (emlrtDCInfo *)&c_emlrtDCI, sp);
  }

  if (nSim != (int32_T)muDoubleScalarFloor(nSim)) {
    emlrtIntegerCheckR2012b(nSim, (emlrtDCInfo *)&b_emlrtDCI, sp);
  }

  p_seeds->size[0] = (int32_T)nSim;
  if (!(nSeeds >= 0.0)) {
    emlrtNonNegativeCheckR2012b(nSeeds, (emlrtDCInfo *)&e_emlrtDCI, sp);
  }

  if (nSeeds != (int32_T)muDoubleScalarFloor(nSeeds)) {
    emlrtIntegerCheckR2012b(nSeeds, (emlrtDCInfo *)&d_emlrtDCI, sp);
  }

  p_seeds->size[1] = (int32_T)nSeeds;
  emxEnsureCapacity_real_T(sp, p_seeds, m, &gb_emlrtRTEI);
  if (!(nSim >= 0.0)) {
    emlrtNonNegativeCheckR2012b(nSim, (emlrtDCInfo *)&g_emlrtDCI, sp);
  }

  if (nSim != (int32_T)muDoubleScalarFloor(nSim)) {
    emlrtIntegerCheckR2012b(nSim, (emlrtDCInfo *)&f_emlrtDCI, sp);
  }

  if (!(nSeeds >= 0.0)) {
    emlrtNonNegativeCheckR2012b(nSeeds, (emlrtDCInfo *)&g_emlrtDCI, sp);
  }

  if (nSeeds != (int32_T)muDoubleScalarFloor(nSeeds)) {
    emlrtIntegerCheckR2012b(nSeeds, (emlrtDCInfo *)&f_emlrtDCI, sp);
  }

  nleftm1 = (int32_T)nSim * (int32_T)nSeeds;
  for (m = 0; m < nleftm1; m++) {
    p_seeds->data[m] = 0.0;
  }

  for (m = 0; m < 6; m++) {
    p_seedType[m] = seedType[m];
  }

  /*  generate random permutations... */
  /*  need to take care with the total amount of unique combinations of N, take nSeeds; */
  /*  s = N!/( (nSeeds)! * (N-nSeeds)!) is total number of unique combinations */
  /*  if s < nSim, then we can only take s maximum seed combinations, instead of nSim */
  /*     otherwise we will sample with replacement */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nSim, mxDOUBLE_CLASS, (int32_T)nSim,
    (emlrtRTEInfo *)&yc_emlrtRTEI, sp);
  i = 0;
  emxInit_int32_T(sp, &r4, 1, &ob_emlrtRTEI, true);
  emxInit_real_T(sp, &r5, 2, &ob_emlrtRTEI, true);
  emxInit_real_T1(sp, &hashTbl, 1, &kb_emlrtRTEI, true);
  emxInit_real_T1(sp, &link, 1, &lb_emlrtRTEI, true);
  emxInit_real_T1(sp, &val, 1, &mb_emlrtRTEI, true);
  emxInit_real_T1(sp, &loc, 1, &nb_emlrtRTEI, true);
  while (i <= (int32_T)nSim - 1) {
    m = p_seeds->size[0];
    nleftm1 = i + 1;
    if (!((nleftm1 >= 1) && (nleftm1 <= m))) {
      emlrtDynamicBoundsCheckR2012b(nleftm1, 1, m, (emlrtBCInfo *)&sb_emlrtBCI,
        sp);
    }

    nleftm1 = p_seeds->size[1];
    m = r4->size[0];
    r4->size[0] = nleftm1;
    emxEnsureCapacity_int32_T(sp, r4, m, &hb_emlrtRTEI);
    for (m = 0; m < nleftm1; m++) {
      r4->data[m] = m;
    }

    st.site = &x_emlrtRSI;
    if (!(nSeeds == nSeeds)) {
      emlrtErrorWithMessageIdR2012b(&st, &bd_emlrtRTEI,
        "MATLAB:randperm:inputType", 0);
    }

    if (!(nSeeds <= N)) {
      emlrtErrorWithMessageIdR2012b(&st, &ad_emlrtRTEI,
        "MATLAB:randperm:inputKTooLarge", 0);
    }

    b_st.site = &y_emlrtRSI;
    m = r5->size[0] * r5->size[1];
    r5->size[0] = 1;
    r5->size[1] = (int32_T)nSeeds;
    emxEnsureCapacity_real_T(&b_st, r5, m, &jb_emlrtRTEI);
    nleftm1 = (int32_T)nSeeds;
    for (m = 0; m < nleftm1; m++) {
      r5->data[m] = 0.0;
    }

    if (!(nSeeds == 0.0)) {
      if ((int32_T)nSeeds >= N) {
        r5->data[0] = 1.0;
        for (nleftm1 = 0; nleftm1 <= N - 2; nleftm1++) {
          selectedLoc = b_rand() * ((1.0 + (real_T)nleftm1) + 1.0);
          j = muDoubleScalarFloor(selectedLoc);
          r5->data[nleftm1 + 1] = r5->data[(int32_T)(j + 1.0) - 1];
          r5->data[(int32_T)(j + 1.0) - 1] = (1.0 + (real_T)nleftm1) + 1.0;
        }
      } else if (nSeeds >= (real_T)N / 4.0) {
        t = 0.0;
        for (m = 0; m < (int32_T)nSeeds; m++) {
          nleftm1 = (int32_T)nSeeds - m;
          selectedLoc = (real_T)N - t;
          b_i = (real_T)nleftm1 / selectedLoc;
          newEntry = b_rand();
          while (newEntry > b_i) {
            t++;
            selectedLoc--;
            b_i += (1.0 - b_i) * ((real_T)nleftm1 / selectedLoc);
          }

          t++;
          selectedLoc = b_rand() * ((real_T)m + 1.0);
          j = muDoubleScalarFloor(selectedLoc);
          r5->data[m] = r5->data[(int32_T)(j + 1.0) - 1];
          r5->data[(int32_T)(j + 1.0) - 1] = t;
        }
      } else {
        m = hashTbl->size[0];
        hashTbl->size[0] = (int32_T)nSeeds;
        emxEnsureCapacity_real_T1(&b_st, hashTbl, m, &kb_emlrtRTEI);
        nleftm1 = (int32_T)nSeeds;
        for (m = 0; m < nleftm1; m++) {
          hashTbl->data[m] = 0.0;
        }

        m = link->size[0];
        link->size[0] = (int32_T)nSeeds;
        emxEnsureCapacity_real_T1(&b_st, link, m, &lb_emlrtRTEI);
        nleftm1 = (int32_T)nSeeds;
        for (m = 0; m < nleftm1; m++) {
          link->data[m] = 0.0;
        }

        m = val->size[0];
        val->size[0] = (int32_T)nSeeds;
        emxEnsureCapacity_real_T1(&b_st, val, m, &mb_emlrtRTEI);
        nleftm1 = (int32_T)nSeeds;
        for (m = 0; m < nleftm1; m++) {
          val->data[m] = 0.0;
        }

        m = loc->size[0];
        loc->size[0] = (int32_T)nSeeds;
        emxEnsureCapacity_real_T1(&b_st, loc, m, &nb_emlrtRTEI);
        nleftm1 = (int32_T)nSeeds;
        for (m = 0; m < nleftm1; m++) {
          loc->data[m] = 0.0;
        }

        newEntry = 1.0;
        for (m = 0; m < (int32_T)nSeeds; m++) {
          nleftm1 = (N - m) - 1;
          selectedLoc = b_rand() * ((real_T)nleftm1 + 1.0);
          selectedLoc = muDoubleScalarFloor(selectedLoc);
          b_i = 1.0 + b_mod(selectedLoc, nSeeds);
          j = hashTbl->data[(int32_T)b_i - 1];
          while ((j > 0.0) && (loc->data[(int32_T)j - 1] != selectedLoc)) {
            j = link->data[(int32_T)j - 1];
          }

          if (j > 0.0) {
            r5->data[m] = val->data[(int32_T)j - 1] + 1.0;
          } else {
            r5->data[m] = selectedLoc + 1.0;
            j = newEntry;
            newEntry++;
            loc->data[(int32_T)j - 1] = selectedLoc;
            link->data[(int32_T)j - 1] = hashTbl->data[(int32_T)b_i - 1];
            hashTbl->data[(int32_T)b_i - 1] = j;
          }

          if (1 + m < (int32_T)nSeeds) {
            selectedLoc = hashTbl->data[(int32_T)(1.0 + b_mod((real_T)nleftm1,
              nSeeds)) - 1];
            while ((selectedLoc > 0.0) && (loc->data[(int32_T)selectedLoc - 1]
                    != nleftm1)) {
              selectedLoc = link->data[(int32_T)selectedLoc - 1];
            }

            if (selectedLoc > 0.0) {
              selectedLoc = val->data[(int32_T)selectedLoc - 1];
            } else {
              selectedLoc = nleftm1;
            }

            val->data[(int32_T)j - 1] = selectedLoc;
          }
        }
      }
    }

    iv5[0] = 1;
    iv5[1] = r4->size[0];
    emlrtSubAssignSizeCheckR2012b(&iv5[0], 2, &(*(int32_T (*)[2])r5->size)[0], 2,
      (emlrtECInfo *)&emlrtECI, sp);
    nleftm1 = r5->size[1];
    for (m = 0; m < nleftm1; m++) {
      p_seeds->data[i + p_seeds->size[0] * r4->data[m]] = r5->data[r5->size[0] *
        m];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&loc);
  emxFree_real_T(&val);
  emxFree_real_T(&link);
  emxFree_real_T(&hashTbl);
  emxFree_real_T(&r5);
  emxFree_int32_T(&r4);
  if (nSeeds < 1.0) {
    m = p_x0->size[0] * p_x0->size[1];
    p_x0->size[0] = 1;
    p_x0->size[1] = 0;
    emxEnsureCapacity_real_T(sp, p_x0, m, &gb_emlrtRTEI);
  } else if (muDoubleScalarIsInf(nSeeds) && (1.0 == nSeeds)) {
    m = p_x0->size[0] * p_x0->size[1];
    p_x0->size[0] = 1;
    p_x0->size[1] = 1;
    emxEnsureCapacity_real_T(sp, p_x0, m, &gb_emlrtRTEI);
    p_x0->data[0] = rtNaN;
  } else {
    m = p_x0->size[0] * p_x0->size[1];
    p_x0->size[0] = 1;
    p_x0->size[1] = (int32_T)muDoubleScalarFloor(nSeeds - 1.0) + 1;
    emxEnsureCapacity_real_T(sp, p_x0, m, &ib_emlrtRTEI);
    nleftm1 = (int32_T)muDoubleScalarFloor(nSeeds - 1.0);
    for (m = 0; m <= nleftm1; m++) {
      p_x0->data[p_x0->size[0] * m] = 1.0 + (real_T)m;
    }
  }

  *p_N = b_p_N;
  *p_nSeeds = nSeeds;
  *p_isCompetitive = true;
  *p_nSim = nSim;
  *p_seedTrial = 1.0;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (GetSimulationParam.cpp) */
