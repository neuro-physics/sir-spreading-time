/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * randperm.cpp
 *
 * Code generation for function 'randperm'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "NetworkActivationTime.h"
#include "randperm.h"
#include "rand.h"
#include "NetworkActivationTime_emxutil.h"
#include "mod.h"

/* Variable Definitions */
static emlrtRSInfo uc_emlrtRSI = { 24, /* lineNo */
  "randperm",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m"/* pathName */
};

static emlrtRTEInfo db_emlrtRTEI = { 24,/* lineNo */
  5,                                   /* colNo */
  "randperm",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 62,/* lineNo */
  5,                                   /* colNo */
  "randperm",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 63,/* lineNo */
  5,                                   /* colNo */
  "randperm",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 64,/* lineNo */
  5,                                   /* colNo */
  "randperm",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m"/* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 65,/* lineNo */
  5,                                   /* colNo */
  "randperm",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m"/* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = { 23,/* lineNo */
  19,                                  /* colNo */
  "randperm",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m"/* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = { 20,/* lineNo */
  19,                                  /* colNo */
  "randperm",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m"/* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = { 12,/* lineNo */
  15,                                  /* colNo */
  "randperm",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m"/* pName */
};

static emlrtDCInfo g_emlrtDCI = { 31,  /* lineNo */
  19,                                  /* colNo */
  "randperm",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 24,  /* lineNo */
  5,                                   /* colNo */
  "randperm",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\randfun\\randperm.m",/* pName */
  4                                    /* checkKind */
};

/* Function Definitions */
void randperm(const emlrtStack *sp, real_T n, real_T k, emxArray_real_T *p)
{
  boolean_T b0;
  int32_T m;
  int32_T loop_ub;
  emxArray_real_T *hashTbl;
  real_T t;
  real_T selectedLoc;
  real_T j;
  real_T i;
  real_T nleftm1;
  emxArray_real_T *link;
  real_T newEntry;
  emxArray_real_T *val;
  emxArray_real_T *loc;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  if (!(n == muDoubleScalarFloor(n))) {
    emlrtErrorWithMessageIdR2012b(sp, &bd_emlrtRTEI, "MATLAB:randperm:inputType",
      0);
  }

  if ((k >= 0.0) && (k == muDoubleScalarFloor(k))) {
    b0 = true;
  } else {
    b0 = false;
  }

  if (!b0) {
    emlrtErrorWithMessageIdR2012b(sp, &ad_emlrtRTEI, "MATLAB:randperm:inputType",
      0);
  }

  if (!(k <= n)) {
    emlrtErrorWithMessageIdR2012b(sp, &yc_emlrtRTEI,
      "MATLAB:randperm:inputKTooLarge", 0);
  }

  st.site = &uc_emlrtRSI;
  m = p->size[0] * p->size[1];
  p->size[0] = 1;
  if (!(k >= 0.0)) {
    emlrtNonNegativeCheckR2012b(k, (emlrtDCInfo *)&g_emlrtDCI, &st);
  }

  p->size[1] = (int32_T)k;
  emxEnsureCapacity_real_T1(&st, p, m, &db_emlrtRTEI);
  if (!(k >= 0.0)) {
    emlrtNonNegativeCheckR2012b(k, (emlrtDCInfo *)&h_emlrtDCI, &st);
  }

  loop_ub = (int32_T)k;
  for (m = 0; m < loop_ub; m++) {
    p->data[m] = 0.0;
  }

  if (!(k == 0.0)) {
    if (k >= n) {
      p->data[0] = 1.0;
      for (m = 0; m < (int32_T)(n - 1.0); m++) {
        selectedLoc = b_rand() * ((1.0 + (real_T)m) + 1.0);
        j = muDoubleScalarFloor(selectedLoc);
        p->data[(int32_T)((1.0 + (real_T)m) + 1.0) - 1] = p->data[(int32_T)(j +
          1.0) - 1];
        p->data[(int32_T)(j + 1.0) - 1] = (1.0 + (real_T)m) + 1.0;
      }
    } else if (k >= n / 4.0) {
      t = 0.0;
      for (m = 0; m < (int32_T)((k - 1.0) + 1.0); m++) {
        selectedLoc = k - (real_T)m;
        i = n - t;
        nleftm1 = selectedLoc / i;
        newEntry = b_rand();
        while (newEntry > nleftm1) {
          t++;
          i--;
          nleftm1 += (1.0 - nleftm1) * (selectedLoc / i);
        }

        t++;
        selectedLoc = b_rand() * ((real_T)m + 1.0);
        j = muDoubleScalarFloor(selectedLoc);
        p->data[m] = p->data[(int32_T)(j + 1.0) - 1];
        p->data[(int32_T)(j + 1.0) - 1] = t;
      }
    } else {
      emxInit_real_T1(&st, &hashTbl, 1, &eb_emlrtRTEI, true);
      m = hashTbl->size[0];
      hashTbl->size[0] = (int32_T)k;
      emxEnsureCapacity_real_T(&st, hashTbl, m, &eb_emlrtRTEI);
      loop_ub = (int32_T)k;
      for (m = 0; m < loop_ub; m++) {
        hashTbl->data[m] = 0.0;
      }

      emxInit_real_T1(&st, &link, 1, &fb_emlrtRTEI, true);
      m = link->size[0];
      link->size[0] = (int32_T)k;
      emxEnsureCapacity_real_T(&st, link, m, &fb_emlrtRTEI);
      loop_ub = (int32_T)k;
      for (m = 0; m < loop_ub; m++) {
        link->data[m] = 0.0;
      }

      emxInit_real_T1(&st, &val, 1, &gb_emlrtRTEI, true);
      m = val->size[0];
      val->size[0] = (int32_T)k;
      emxEnsureCapacity_real_T(&st, val, m, &gb_emlrtRTEI);
      loop_ub = (int32_T)k;
      for (m = 0; m < loop_ub; m++) {
        val->data[m] = 0.0;
      }

      emxInit_real_T1(&st, &loc, 1, &hb_emlrtRTEI, true);
      m = loc->size[0];
      loc->size[0] = (int32_T)k;
      emxEnsureCapacity_real_T(&st, loc, m, &hb_emlrtRTEI);
      loop_ub = (int32_T)k;
      for (m = 0; m < loop_ub; m++) {
        loc->data[m] = 0.0;
      }

      newEntry = 1.0;
      for (m = 0; m < (int32_T)k; m++) {
        nleftm1 = n - (1.0 + (real_T)m);
        selectedLoc = b_rand() * (nleftm1 + 1.0);
        selectedLoc = muDoubleScalarFloor(selectedLoc);
        i = 1.0 + b_mod(selectedLoc, k);
        j = hashTbl->data[(int32_T)i - 1];
        while ((j > 0.0) && (loc->data[(int32_T)j - 1] != selectedLoc)) {
          j = link->data[(int32_T)j - 1];
        }

        if (j > 0.0) {
          p->data[m] = val->data[(int32_T)j - 1] + 1.0;
        } else {
          p->data[m] = selectedLoc + 1.0;
          j = newEntry;
          newEntry++;
          loc->data[(int32_T)j - 1] = selectedLoc;
          link->data[(int32_T)j - 1] = hashTbl->data[(int32_T)i - 1];
          hashTbl->data[(int32_T)i - 1] = j;
        }

        if (1.0 + (real_T)m < k) {
          selectedLoc = hashTbl->data[(int32_T)(1.0 + b_mod(nleftm1, k)) - 1];
          while ((selectedLoc > 0.0) && (loc->data[(int32_T)selectedLoc - 1] !=
                  nleftm1)) {
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

      emxFree_real_T(&loc);
      emxFree_real_T(&val);
      emxFree_real_T(&link);
      emxFree_real_T(&hashTbl);
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (randperm.cpp) */
