/*
 * getNiiParcelCoord.cpp
 *
 * Code generation for function 'getNiiParcelCoord'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "getNiiParcelCoord.h"
#include "getNiiParcelCoord_emxutil.h"
#include "rdivide.h"
#include "eml_int_forloop_overflow_check.h"
#include "isequal.h"
#include "round.h"
#include "getNiiParcelCoord_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 38, "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m"
};

static emlrtRSInfo b_emlrtRSI = { 40, "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m"
};

static emlrtRSInfo c_emlrtRSI = { 41, "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m"
};

static emlrtRSInfo d_emlrtRSI = { 42, "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m"
};

static emlrtRSInfo e_emlrtRSI = { 45, "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m"
};

static emlrtRSInfo f_emlrtRSI = { 59, "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m"
};

static emlrtRSInfo g_emlrtRSI = { 60, "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m"
};

static emlrtRSInfo h_emlrtRSI = { 44, "unique",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"
};

static emlrtRSInfo i_emlrtRSI = { 152, "unique",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"
};

static emlrtRSInfo j_emlrtRSI = { 154, "unique",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"
};

static emlrtRSInfo k_emlrtRSI = { 163, "unique",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"
};

static emlrtRSInfo l_emlrtRSI = { 188, "unique",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"
};

static emlrtRSInfo m_emlrtRSI = { 201, "unique",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"
};

static emlrtRSInfo n_emlrtRSI = { 212, "unique",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"
};

static emlrtRSInfo o_emlrtRSI = { 226, "unique",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"
};

static emlrtRSInfo p_emlrtRSI = { 101, "sortIdx",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"
};

static emlrtRSInfo q_emlrtRSI = { 239, "sortIdx",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"
};

static emlrtRSInfo r_emlrtRSI = { 292, "sortIdx",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"
};

static emlrtRSInfo t_emlrtRSI = { 13, "min",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"
};

static emlrtRSInfo u_emlrtRSI = { 19, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRSInfo v_emlrtRSI = { 140, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRSInfo w_emlrtRSI = { 375, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRSInfo x_emlrtRSI = { 347, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRSInfo bb_emlrtRSI = { 21, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo cb_emlrtRSI = { 79, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo db_emlrtRSI = { 283, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo eb_emlrtRSI = { 291, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo fb_emlrtRSI = { 44, "find",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"
};

static emlrtRSInfo gb_emlrtRSI = { 234, "find",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"
};

static emlrtRSInfo hb_emlrtRSI = { 253, "find",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"
};

static emlrtRSInfo ib_emlrtRSI = { 18, "indexShapeCheck",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"
};

static emlrtRSInfo jb_emlrtRSI = { 19, "ind2sub",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"
};

static emlrtRSInfo kb_emlrtRSI = { 66, "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m"
};

static emlrtRSInfo lb_emlrtRSI = { 21, "cat",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"
};

static emlrtRSInfo mb_emlrtRSI = { 101, "cat",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"
};

static emlrtRSInfo nb_emlrtRSI = { 40, "mean",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"
};

static emlrtRSInfo ob_emlrtRSI = { 113, "combine_vector_elements",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

static emlrtRTEInfo emlrtRTEI = { 1, 14, "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m"
};

static emlrtRTEInfo b_emlrtRTEI = { 234, 9, "sortIdx",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 220, 1, "unique",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"
};

static emlrtRTEInfo d_emlrtRTEI = { 253, 13, "find",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 40, 13, "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m"
};

static emlrtRTEInfo f_emlrtRTEI = { 152, 1, "unique",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"
};

static emlrtRTEInfo g_emlrtRTEI = { 234, 1, "sortIdx",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 42, 5, "ind2sub",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"
};

static emlrtRTEInfo k_emlrtRTEI = { 30, 5, "mean",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"
};

static emlrtRTEInfo l_emlrtRTEI = { 21, 5, "mean",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"
};

static emlrtRTEInfo m_emlrtRTEI = { 17, 15, "mean",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"
};

static emlrtRTEInfo n_emlrtRTEI = { 245, 27, "cat",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"
};

static emlrtRTEInfo o_emlrtRTEI = { 38, 15, "ind2sub",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"
};

static emlrtRTEInfo p_emlrtRTEI = { 88, 9, "indexShapeCheck",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"
};

static emlrtRTEInfo q_emlrtRTEI = { 243, 9, "find",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"
};

static emlrtRTEInfo r_emlrtRTEI = { 126, 19, "find",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"
};

static emlrtRTEInfo s_emlrtRTEI = { 404, 15, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRTEInfo t_emlrtRTEI = { 121, 27, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRTEInfo u_emlrtRTEI = { 39, 27, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRTEInfo v_emlrtRTEI = { 219, 1, "unique",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 60, 11, "r", "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 53, 20, "data.hdr.dime.dim",
  "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m",
  0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 52, 20, "data.hdr.dime.dim",
  "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m",
  0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 51, 20, "data.hdr.dime.dim",
  "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m",
  0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 41, 22, "u", "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m",
  0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 47, 9, "data.hdr.hist.originator",
  "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m",
  0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 48, 10, "data.hdr.dime.pixdim",
  "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m",
  0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 59, 62, "p", "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m",
  0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 77, 12, "x", "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m",
  0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 78, 21, "x", "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m",
  0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 80, 12, "x", "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m",
  0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 81, 21, "x", "getNiiParcelCoord",
  "D:\\Dropbox\\p\\postdoc\\programs\\matlab\\sirs\\spreading\\func\\getNiiParcelCoord.m",
  0 };

static emlrtRSInfo pb_emlrtRSI = { 18, "indexDivide",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\indexDivide.m"
};

/* Function Declarations */
static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator);
static void myMinMax(const emlrtStack *sp, const emxArray_real32_T *x, real_T
                     mm[2]);

/* Function Definitions */
static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }

    emlrtDivisionByZeroErrorR2012b(NULL, sp);
  } else {
    if (numerator < 0) {
      absNumerator = ~(uint32_T)numerator + 1U;
    } else {
      absNumerator = (uint32_T)numerator;
    }

    if (denominator < 0) {
      absDenominator = ~(uint32_T)denominator + 1U;
    } else {
      absDenominator = (uint32_T)denominator;
    }

    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    absNumerator /= absDenominator;
    if (quotientNeedsNegation) {
      quotient = -(int32_T)absNumerator;
    } else {
      quotient = (int32_T)absNumerator;
    }
  }

  return quotient;
}

static void myMinMax(const emlrtStack *sp, const emxArray_real32_T *x, real_T
                     mm[2])
{
  static real_T dv0[2] = { 0.0, 0.0 };

  int32_T i0;
  int32_T i;
  dv0[0U] = rtInf;
  dv0[1U] = rtMinusInf;
  for (i0 = 0; i0 < 2; i0++) {
    mm[i0] = dv0[i0];
  }

  i = 1;
  while (i - 1 <= x->size[1] - 1) {
    i0 = x->size[1];
    if (!((i >= 1) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&i_emlrtBCI, sp);
    }

    if (x->data[i - 1] < mm[0]) {
      i0 = x->size[1];
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&j_emlrtBCI, sp);
      }

      mm[0] = x->data[i - 1];
    }

    i0 = x->size[1];
    if (!((i >= 1) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&k_emlrtBCI, sp);
    }

    if (x->data[i - 1] > mm[1]) {
      i0 = x->size[1];
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, (emlrtBCInfo *)&l_emlrtBCI, sp);
      }

      mm[1] = x->data[i - 1];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

void getNiiParcelCoord(const emlrtStack *sp, const struct0_T *niiFile,
  emxArray_real_T *p, emxArray_real_T *r)
{
  emxArray_real32_T *data_img;
  int32_T qEnd;
  int32_T i2;
  emxArray_int32_T *iwork;
  emxArray_real32_T *b_niiFile;
  int32_T b_p;
  real_T o[3];
  real_T sc[3];
  int32_T q;
  emxArray_real_T *c_niiFile;
  real_T mm[2];
  emxArray_real32_T *a;
  int32_T n;
  real_T s;
  real_T apnd;
  real_T ndbl;
  boolean_T overflow;
  emxArray_int32_T *idx;
  emxArray_real_T *d_niiFile;
  real_T cdiff;
  int32_T na;
  emxArray_real_T *y;
  emxArray_real32_T *u;
  emxArray_real_T *e_niiFile;
  real_T indRangeY[2];
  int32_T k;
  int32_T i;
  real_T indRangeZ[2];
  real_T brainRangeX[2];
  int32_T j;
  int32_T pEnd;
  real_T brainRangeY[2];
  real_T brainRangeZ[2];
  int32_T kEnd;
  real32_T x;
  int32_T exitg4;
  emxArray_real_T *b_x;
  emxArray_boolean_T *c_x;
  emxArray_int32_T *varargout_6;
  real32_T absxk;
  emxArray_int32_T *vk;
  emxArray_real_T *varargin_1;
  emxArray_real_T *varargin_2;
  int32_T exponent;
  emxArray_real_T *varargin_3;
  boolean_T exitg2;
  boolean_T guard1 = false;
  boolean_T b_guard1 = false;
  real_T siz[3];
  emxArray_real32_T *r0;
  int32_T cpsiz[2];
  boolean_T exitg3;
  int32_T exitg1;
  real32_T fv0[2];
  real_T xR[4];
  real_T yR[4];
  real_T zR[4];
  real_T b_a;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real32_T(sp, &data_img, 3, &emlrtRTEI, true);

  /*  load nii file */
  /*  find indices i,j,k corresponding to each non-zero element in .img of loaded file */
  /*  calculate centroid (mean) of i,j,k */
  /*  displace this coord by summing up it with .hdr.hist.originator */
  qEnd = data_img->size[0] * data_img->size[1] * data_img->size[2];
  data_img->size[0] = niiFile->img->size[0];
  data_img->size[1] = niiFile->img->size[1];
  data_img->size[2] = niiFile->img->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)data_img, qEnd, (int32_T)sizeof
                    (real32_T), &emlrtRTEI);
  i2 = niiFile->img->size[0] * niiFile->img->size[1] * niiFile->img->size[2];
  for (qEnd = 0; qEnd < i2; qEnd++) {
    data_img->data[qEnd] = niiFile->img->data[qEnd];
  }

  emxInit_int32_T1(sp, &iwork, 1, &g_emlrtRTEI, true);
  if ((p->size[0] == 0) || (p->size[1] == 0)) {
    emxInit_real32_T1(sp, &b_niiFile, 2, &emlrtRTEI, true);
    b_p = niiFile->img->size[0] * niiFile->img->size[1] * niiFile->img->size[2];
    qEnd = b_niiFile->size[0] * b_niiFile->size[1];
    b_niiFile->size[0] = 1;
    b_niiFile->size[1] = b_p;
    emxEnsureCapacity(sp, (emxArray__common *)b_niiFile, qEnd, (int32_T)sizeof
                      (real32_T), &emlrtRTEI);
    for (qEnd = 0; qEnd < b_p; qEnd++) {
      b_niiFile->data[b_niiFile->size[0] * qEnd] = niiFile->img->data[qEnd];
    }

    st.site = &emlrtRSI;
    myMinMax(&st, b_niiFile, mm);
    emxFree_real32_T(&b_niiFile);
    if (muDoubleScalarFloor(mm[1]) != mm[1]) {
      emxInit_real32_T1(sp, &a, 2, &emlrtRTEI, true);
      st.site = &b_emlrtRSI;
      b_p = niiFile->img->size[0] * niiFile->img->size[1] * niiFile->img->size[2];
      qEnd = a->size[0] * a->size[1];
      a->size[0] = 1;
      a->size[1] = b_p;
      emxEnsureCapacity(&st, (emxArray__common *)a, qEnd, (int32_T)sizeof
                        (real32_T), &emlrtRTEI);
      for (qEnd = 0; qEnd < b_p; qEnd++) {
        a->data[a->size[0] * qEnd] = niiFile->img->data[qEnd];
      }

      emxInit_int32_T(&st, &idx, 2, &f_emlrtRTEI, true);
      b_st.site = &h_emlrtRSI;
      na = a->size[1];
      c_st.site = &i_emlrtRSI;
      qEnd = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = a->size[1];
      emxEnsureCapacity(&c_st, (emxArray__common *)idx, qEnd, (int32_T)sizeof
                        (int32_T), &emlrtRTEI);
      i2 = a->size[1];
      for (qEnd = 0; qEnd < i2; qEnd++) {
        idx->data[qEnd] = 0;
      }

      if (a->size[1] == 0) {
      } else {
        d_st.site = &p_emlrtRSI;
        n = a->size[1] + 1;
        b_p = a->size[1];
        qEnd = iwork->size[0];
        iwork->size[0] = b_p;
        emxEnsureCapacity(&d_st, (emxArray__common *)iwork, qEnd, (int32_T)
                          sizeof(int32_T), &b_emlrtRTEI);
        e_st.site = &q_emlrtRSI;
        overflow = ((!(1 > a->size[1] - 1)) && (a->size[1] - 1 > 2147483645));
        if (overflow) {
          f_st.site = &s_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        for (k = 1; k <= n - 2; k += 2) {
          if ((a->data[k - 1] <= a->data[k]) || muSingleScalarIsNaN(a->data[k]))
          {
            overflow = true;
          } else {
            overflow = false;
          }

          if (overflow) {
            idx->data[k - 1] = k;
            idx->data[k] = k + 1;
          } else {
            idx->data[k - 1] = k + 1;
            idx->data[k] = k;
          }
        }

        if ((a->size[1] & 1) != 0) {
          idx->data[a->size[1] - 1] = a->size[1];
        }

        i = 2;
        while (i < n - 1) {
          i2 = i << 1;
          j = 1;
          for (pEnd = 1 + i; pEnd < n; pEnd = qEnd + i) {
            b_p = j;
            q = pEnd - 1;
            qEnd = j + i2;
            if (qEnd > n) {
              qEnd = n;
            }

            k = 0;
            kEnd = qEnd - j;
            while (k + 1 <= kEnd) {
              if ((a->data[idx->data[b_p - 1] - 1] <= a->data[idx->data[q] - 1])
                  || muSingleScalarIsNaN(a->data[idx->data[q] - 1])) {
                overflow = true;
              } else {
                overflow = false;
              }

              if (overflow) {
                iwork->data[k] = idx->data[b_p - 1];
                b_p++;
                if (b_p == pEnd) {
                  while (q + 1 < qEnd) {
                    k++;
                    iwork->data[k] = idx->data[q];
                    q++;
                  }
                }
              } else {
                iwork->data[k] = idx->data[q];
                q++;
                if (q + 1 == qEnd) {
                  while (b_p < pEnd) {
                    k++;
                    iwork->data[k] = idx->data[b_p - 1];
                    b_p++;
                  }
                }
              }

              k++;
            }

            e_st.site = &r_emlrtRSI;
            for (k = 0; k + 1 <= kEnd; k++) {
              idx->data[(j + k) - 1] = iwork->data[k];
            }

            j = qEnd;
          }

          i = i2;
        }
      }

      emxInit_real32_T1(&c_st, &u, 2, &e_emlrtRTEI, true);
      qEnd = u->size[0] * u->size[1];
      u->size[0] = 1;
      u->size[1] = a->size[1];
      emxEnsureCapacity(&b_st, (emxArray__common *)u, qEnd, (int32_T)sizeof
                        (real32_T), &emlrtRTEI);
      c_st.site = &j_emlrtRSI;
      overflow = ((!(1 > a->size[1])) && (a->size[1] > 2147483646));
      if (overflow) {
        d_st.site = &s_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (k = 0; k + 1 <= na; k++) {
        u->data[k] = a->data[idx->data[k] - 1];
      }

      k = 0;
      while ((k + 1 <= na) && muSingleScalarIsInf(u->data[k]) && (u->data[k] <
              0.0F)) {
        k++;
      }

      qEnd = k;
      k = a->size[1];
      while ((k >= 1) && muSingleScalarIsNaN(u->data[k - 1])) {
        k--;
      }

      q = a->size[1] - k;
      while ((k >= 1) && muSingleScalarIsInf(u->data[k - 1]) && (u->data[k - 1] >
              0.0F)) {
        k--;
      }

      pEnd = (a->size[1] - k) - q;
      kEnd = 0;
      if (qEnd > 0) {
        kEnd = 1;
        c_st.site = &k_emlrtRSI;
      }

      b_p = (qEnd + k) - qEnd;
      while (qEnd + 1 <= b_p) {
        x = u->data[qEnd];
        i2 = qEnd;
        do {
          exitg4 = 0;
          qEnd++;
          if (qEnd + 1 > b_p) {
            exitg4 = 1;
          } else {
            absxk = muSingleScalarAbs(x / 2.0F);
            if ((!muSingleScalarIsInf(absxk)) && (!muSingleScalarIsNaN(absxk)))
            {
              if (absxk <= 1.17549435E-38F) {
                absxk = 1.4013E-45F;
              } else {
                frexp((real_T)absxk, &exponent);
                absxk = (real32_T)ldexp(1.0, exponent - 24);
              }
            } else {
              absxk = ((real32_T)rtNaN);
            }

            if ((muSingleScalarAbs(x - u->data[qEnd]) < absxk) ||
                (muSingleScalarIsInf(u->data[qEnd]) && muSingleScalarIsInf(x) &&
                 ((u->data[qEnd] > 0.0F) == (x > 0.0F)))) {
              overflow = true;
            } else {
              overflow = false;
            }

            if (!overflow) {
              exitg4 = 1;
            }
          }
        } while (exitg4 == 0);

        kEnd++;
        u->data[kEnd - 1] = x;
        c_st.site = &l_emlrtRSI;
        if ((!(i2 + 1 > qEnd)) && (qEnd > 2147483646)) {
          d_st.site = &s_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
      }

      if (pEnd > 0) {
        kEnd++;
        u->data[kEnd - 1] = u->data[b_p];
        c_st.site = &m_emlrtRSI;
        if (pEnd > 2147483646) {
          d_st.site = &s_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
      }

      qEnd = b_p + pEnd;
      c_st.site = &n_emlrtRSI;
      if ((!(1 > q)) && (q > 2147483646)) {
        d_st.site = &s_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (j = 1; j <= q; j++) {
        kEnd++;
        u->data[kEnd - 1] = u->data[(qEnd + j) - 1];
      }

      if (kEnd <= a->size[1]) {
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &v_emlrtRTEI,
          "Coder:builtins:AssertionFailed", 0);
      }

      emxFree_real32_T(&a);
      if (1 > kEnd) {
        qEnd = 0;
      } else {
        qEnd = kEnd;
      }

      q = u->size[0] * u->size[1];
      u->size[1] = qEnd;
      emxEnsureCapacity(&b_st, (emxArray__common *)u, q, (int32_T)sizeof
                        (real32_T), &c_emlrtRTEI);
      c_st.site = &o_emlrtRSI;
      if ((!(1 > kEnd)) && (kEnd > 2147483646)) {
        d_st.site = &s_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      i2 = u->size[1] - 1;
      b_p = 0;
      for (i = 0; i <= i2; i++) {
        if (u->data[i] != 0.0F) {
          b_p++;
        }
      }

      q = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = b_p;
      emxEnsureCapacity(sp, (emxArray__common *)idx, q, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      b_p = 0;
      for (i = 0; i <= i2; i++) {
        if (u->data[i] != 0.0F) {
          idx->data[b_p] = i + 1;
          b_p++;
        }
      }

      st.site = &c_emlrtRSI;
      i2 = idx->size[0] * idx->size[1];
      for (q = 0; q < i2; q++) {
        b_p = idx->data[q];
        if (!((b_p >= 1) && (b_p <= qEnd))) {
          emlrtDynamicBoundsCheckR2012b(b_p, 1, qEnd, (emlrtBCInfo *)&e_emlrtBCI,
            &st);
        }
      }

      b_st.site = &t_emlrtRSI;
      c_st.site = &u_emlrtRSI;
      if ((idx->size[1] == 1) || (idx->size[1] != 1)) {
        overflow = true;
      } else {
        overflow = false;
      }

      if (overflow) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &u_emlrtRTEI,
          "Coder:toolbox:autoDimIncompatibility", 0);
      }

      if (idx->size[1] > 0) {
      } else {
        emlrtErrorWithMessageIdR2012b(&c_st, &t_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      d_st.site = &v_emlrtRSI;
      b_p = 1;
      n = idx->size[1];
      absxk = u->data[idx->data[0] - 1];
      if (idx->size[1] > 1) {
        if (muSingleScalarIsNaN(absxk)) {
          e_st.site = &x_emlrtRSI;
          overflow = ((!(2 > idx->size[1])) && (idx->size[1] > 2147483646));
          if (overflow) {
            f_st.site = &s_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          i2 = 2;
          exitg3 = false;
          while ((!exitg3) && (i2 <= n)) {
            b_p = i2;
            if (!muSingleScalarIsNaN(u->data[idx->data[idx->size[0] * (i2 - 1)]
                 - 1])) {
              absxk = u->data[idx->data[idx->size[0] * (i2 - 1)] - 1];
              exitg3 = true;
            } else {
              i2++;
            }
          }
        }

        if (b_p < idx->size[1]) {
          e_st.site = &w_emlrtRSI;
          overflow = ((!(b_p + 1 > idx->size[1])) && (idx->size[1] > 2147483646));
          if (overflow) {
            f_st.site = &s_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          while (b_p + 1 <= n) {
            if (u->data[idx->data[idx->size[0] * b_p] - 1] < absxk) {
              absxk = u->data[idx->data[idx->size[0] * b_p] - 1];
            }

            b_p++;
          }
        }
      }

      emxFree_int32_T(&idx);
      emxFree_real32_T(&u);
      emxInit_real32_T(&d_st, &r0, 3, &emlrtRTEI, true);
      rdivide(sp, niiFile->img, absxk, r0);
      qEnd = data_img->size[0] * data_img->size[1] * data_img->size[2];
      data_img->size[0] = r0->size[0];
      data_img->size[1] = r0->size[1];
      data_img->size[2] = r0->size[2];
      emxEnsureCapacity(sp, (emxArray__common *)data_img, qEnd, (int32_T)sizeof
                        (real32_T), &emlrtRTEI);
      i2 = r0->size[0] * r0->size[1] * r0->size[2];
      for (qEnd = 0; qEnd < i2; qEnd++) {
        data_img->data[qEnd] = r0->data[qEnd];
      }

      emxFree_real32_T(&r0);
      st.site = &d_emlrtRSI;
      b_round(&st, data_img);
      for (qEnd = 0; qEnd < 2; qEnd++) {
        fv0[qEnd] = (real32_T)mm[qEnd] / absxk;
      }

      c_round(fv0);
      for (qEnd = 0; qEnd < 2; qEnd++) {
        mm[qEnd] = fv0[qEnd];
      }
    }

    st.site = &e_emlrtRSI;
    b_st.site = &bb_emlrtRSI;
    c_st.site = &cb_emlrtRSI;
    if (muDoubleScalarIsNaN(mm[1])) {
      n = 1;
      s = rtNaN;
      apnd = mm[1];
      overflow = false;
    } else if (mm[1] < 1.0) {
      n = 0;
      s = 1.0;
      apnd = mm[1];
      overflow = false;
    } else if (muDoubleScalarIsInf(mm[1])) {
      n = 1;
      s = rtNaN;
      apnd = mm[1];
      overflow = !(1.0 == mm[1]);
    } else {
      s = 1.0;
      ndbl = muDoubleScalarFloor((mm[1] - 1.0) + 0.5);
      apnd = 1.0 + ndbl;
      cdiff = (1.0 + ndbl) - mm[1];
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * mm[1]) {
        ndbl++;
        apnd = mm[1];
      } else if (cdiff > 0.0) {
        apnd = 1.0 + (ndbl - 1.0);
      } else {
        ndbl++;
      }

      overflow = (2.147483647E+9 < ndbl);
      if (ndbl >= 0.0) {
        n = (int32_T)ndbl;
      } else {
        n = 0;
      }
    }

    d_st.site = &db_emlrtRSI;
    if (!overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &s_emlrtRTEI, "Coder:MATLAB:pmaxsize",
        0);
    }

    emxInit_real_T(&d_st, &y, 2, &emlrtRTEI, true);
    qEnd = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = n;
    emxEnsureCapacity(&c_st, (emxArray__common *)y, qEnd, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    if (n > 0) {
      y->data[0] = s;
      if (n > 1) {
        y->data[n - 1] = apnd;
        b_p = (n - 1) / 2;
        d_st.site = &eb_emlrtRSI;
        for (k = 1; k < b_p; k++) {
          y->data[k] = s + (real_T)k;
          y->data[(n - k) - 1] = apnd - (real_T)k;
        }

        if (b_p << 1 == n - 1) {
          y->data[b_p] = (s + apnd) / 2.0;
        } else {
          y->data[b_p] = s + (real_T)b_p;
          y->data[b_p + 1] = apnd - (real_T)b_p;
        }
      }
    }

    qEnd = p->size[0] * p->size[1];
    p->size[0] = 1;
    p->size[1] = y->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)p, qEnd, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    i2 = y->size[0] * y->size[1];
    for (qEnd = 0; qEnd < i2; qEnd++) {
      p->data[qEnd] = y->data[qEnd];
    }

    emxFree_real_T(&y);
  }

  b_p = niiFile->hdr.hist.originator->size[1];
  for (qEnd = 0; qEnd < 3; qEnd++) {
    q = 1 + qEnd;
    if (!(q <= b_p)) {
      emlrtDynamicBoundsCheckR2012b(q, 1, b_p, (emlrtBCInfo *)&f_emlrtBCI, sp);
    }

    o[qEnd] = niiFile->hdr.hist.originator->data[q - 1];
  }

  for (qEnd = 0; qEnd < 3; qEnd++) {
    q = niiFile->hdr.dime.pixdim.size[1];
    b_p = 2 + qEnd;
    if (!(b_p <= q)) {
      emlrtDynamicBoundsCheckR2012b(b_p, 1, q, (emlrtBCInfo *)&g_emlrtBCI, sp);
    }

    sc[qEnd] = niiFile->hdr.dime.pixdim.data[b_p - 1];
  }

  emxInit_real_T(sp, &c_niiFile, 2, &emlrtRTEI, true);

  /*      o = zeros(1,3); */
  /*      sc = ones(1,3); */
  qEnd = niiFile->hdr.dime.dim.size[1];
  if (!(2 <= qEnd)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, qEnd, (emlrtBCInfo *)&d_emlrtBCI, sp);
  }

  qEnd = c_niiFile->size[0] * c_niiFile->size[1];
  c_niiFile->size[0] = 1;
  c_niiFile->size[1] = niiFile->hdr.dime.dim.size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_niiFile, qEnd, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  i2 = niiFile->hdr.dime.dim.size[1];
  for (qEnd = 0; qEnd < i2; qEnd++) {
    c_niiFile->data[c_niiFile->size[0] * qEnd] = niiFile->
      hdr.dime.dim.data[niiFile->hdr.dime.dim.size[0] * qEnd];
  }

  emxInit_real_T(sp, &d_niiFile, 2, &emlrtRTEI, true);
  mm[0] = 1.0;
  mm[1] = c_niiFile->data[1];
  qEnd = niiFile->hdr.dime.dim.size[1];
  if (!(3 <= qEnd)) {
    emlrtDynamicBoundsCheckR2012b(3, 1, qEnd, (emlrtBCInfo *)&c_emlrtBCI, sp);
  }

  qEnd = d_niiFile->size[0] * d_niiFile->size[1];
  d_niiFile->size[0] = 1;
  d_niiFile->size[1] = niiFile->hdr.dime.dim.size[1];
  emxEnsureCapacity(sp, (emxArray__common *)d_niiFile, qEnd, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  i2 = niiFile->hdr.dime.dim.size[1];
  emxFree_real_T(&c_niiFile);
  for (qEnd = 0; qEnd < i2; qEnd++) {
    d_niiFile->data[d_niiFile->size[0] * qEnd] = niiFile->
      hdr.dime.dim.data[niiFile->hdr.dime.dim.size[0] * qEnd];
  }

  emxInit_real_T(sp, &e_niiFile, 2, &emlrtRTEI, true);
  indRangeY[0] = 1.0;
  indRangeY[1] = d_niiFile->data[2];
  qEnd = niiFile->hdr.dime.dim.size[1];
  if (!(4 <= qEnd)) {
    emlrtDynamicBoundsCheckR2012b(4, 1, qEnd, (emlrtBCInfo *)&b_emlrtBCI, sp);
  }

  qEnd = e_niiFile->size[0] * e_niiFile->size[1];
  e_niiFile->size[0] = 1;
  e_niiFile->size[1] = niiFile->hdr.dime.dim.size[1];
  emxEnsureCapacity(sp, (emxArray__common *)e_niiFile, qEnd, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  i2 = niiFile->hdr.dime.dim.size[1];
  emxFree_real_T(&d_niiFile);
  for (qEnd = 0; qEnd < i2; qEnd++) {
    e_niiFile->data[e_niiFile->size[0] * qEnd] = niiFile->
      hdr.dime.dim.data[niiFile->hdr.dime.dim.size[0] * qEnd];
  }

  indRangeZ[0] = 1.0;
  indRangeZ[1] = e_niiFile->data[3];
  brainRangeX[0] = 0.0;
  brainRangeX[1] = muDoubleScalarAbs(niiFile->hdr.hist.qoffset_x);
  brainRangeY[0] = 0.0;
  brainRangeY[1] = muDoubleScalarAbs(niiFile->hdr.hist.qoffset_y);
  brainRangeZ[0] = 0.0;
  brainRangeZ[1] = muDoubleScalarAbs(niiFile->hdr.hist.qoffset_z);
  qEnd = r->size[0] * r->size[1];
  r->size[0] = p->size[1];
  r->size[1] = 3;
  emxEnsureCapacity(sp, (emxArray__common *)r, qEnd, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i2 = p->size[1] * 3;
  emxFree_real_T(&e_niiFile);
  for (qEnd = 0; qEnd < i2; qEnd++) {
    r->data[qEnd] = 0.0;
  }

  qEnd = p->size[1];
  i = 1;
  emxInit_real_T(sp, &b_x, 2, &emlrtRTEI, true);
  emxInit_boolean_T(sp, &c_x, 3, &emlrtRTEI, true);
  emxInit_int32_T1(sp, &varargout_6, 1, &emlrtRTEI, true);
  emxInit_int32_T1(sp, &vk, 1, &h_emlrtRTEI, true);
  emxInit_real_T1(sp, &varargin_1, 1, &emlrtRTEI, true);
  emxInit_real_T1(sp, &varargin_2, 1, &emlrtRTEI, true);
  emxInit_real_T1(sp, &varargin_3, 1, &emlrtRTEI, true);
  while (i - 1 <= qEnd - 1) {
    st.site = &f_emlrtRSI;
    q = c_x->size[0] * c_x->size[1] * c_x->size[2];
    c_x->size[0] = data_img->size[0];
    c_x->size[1] = data_img->size[1];
    c_x->size[2] = data_img->size[2];
    emxEnsureCapacity(&st, (emxArray__common *)c_x, q, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    q = p->size[1];
    if (!((i >= 1) && (i <= q))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, q, (emlrtBCInfo *)&h_emlrtBCI, &st);
    }

    s = p->data[i - 1];
    i2 = data_img->size[0] * data_img->size[1] * data_img->size[2];
    for (q = 0; q < i2; q++) {
      c_x->data[q] = (data_img->data[q] == s);
    }

    b_st.site = &fb_emlrtRSI;
    i2 = c_x->size[0] * c_x->size[1] * c_x->size[2];
    pEnd = 0;
    if ((!(((c_x->size[0] == 1) || (c_x->size[1] == 1)) && (c_x->size[2] == 1)))
        || (c_x->size[0] != 1) || (c_x->size[1] <= 1)) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &r_emlrtRTEI,
        "Coder:toolbox:find_incompatibleShape", 0);
    }

    q = iwork->size[0];
    iwork->size[0] = i2;
    emxEnsureCapacity(&b_st, (emxArray__common *)iwork, q, (int32_T)sizeof
                      (int32_T), &emlrtRTEI);
    c_st.site = &gb_emlrtRSI;
    if ((!(1 > i2)) && (i2 > 2147483646)) {
      d_st.site = &s_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    b_p = 1;
    exitg2 = false;
    while ((!exitg2) && (b_p <= i2)) {
      guard1 = false;
      if (c_x->data[b_p - 1]) {
        pEnd++;
        iwork->data[pEnd - 1] = b_p;
        if (pEnd >= i2) {
          exitg2 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        b_p++;
      }
    }

    if (pEnd <= i2) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &q_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (i2 == 1) {
      if (pEnd == 0) {
        q = iwork->size[0];
        iwork->size[0] = 0;
        emxEnsureCapacity(&b_st, (emxArray__common *)iwork, q, (int32_T)sizeof
                          (int32_T), &emlrtRTEI);
      }
    } else {
      if (1 > pEnd) {
        q = 0;
      } else {
        q = pEnd;
      }

      c_st.site = &hb_emlrtRSI;
      overflow = !(iwork->size[0] != 1);
      b_guard1 = false;
      if (overflow) {
        overflow = false;
        if (q != 1) {
          overflow = true;
        }

        if (overflow) {
          overflow = true;
        } else {
          b_guard1 = true;
        }
      } else {
        b_guard1 = true;
      }

      if (b_guard1) {
        overflow = false;
      }

      d_st.site = &ib_emlrtRSI;
      if (!overflow) {
      } else {
        emlrtErrorWithMessageIdR2012b(&d_st, &p_emlrtRTEI,
          "Coder:FE:PotentialVectorVector", 0);
      }

      b_p = iwork->size[0];
      iwork->size[0] = q;
      emxEnsureCapacity(&b_st, (emxArray__common *)iwork, b_p, (int32_T)sizeof
                        (int32_T), &d_emlrtRTEI);
    }

    st.site = &f_emlrtRSI;
    for (q = 0; q < 3; q++) {
      siz[q] = data_img->size[q];
    }

    b_st.site = &jb_emlrtRSI;
    for (q = 0; q < 2; q++) {
      cpsiz[q] = (int32_T)siz[q];
    }

    cpsiz[1] *= cpsiz[0];
    b_p = cpsiz[1] * (int32_T)siz[2];
    k = 0;
    do {
      exitg1 = 0;
      if (k <= iwork->size[0] - 1) {
        if ((iwork->data[k] >= 1) && (iwork->data[k] <= b_p)) {
          overflow = true;
        } else {
          overflow = false;
        }

        if (!overflow) {
          overflow = false;
          exitg1 = 1;
        } else {
          k++;
        }
      } else {
        overflow = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &o_emlrtRTEI,
        "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
    }

    q = iwork->size[0];
    emxEnsureCapacity(&b_st, (emxArray__common *)iwork, q, (int32_T)sizeof
                      (int32_T), &emlrtRTEI);
    i2 = iwork->size[0];
    for (q = 0; q < i2; q++) {
      iwork->data[q]--;
    }

    q = vk->size[0];
    vk->size[0] = iwork->size[0];
    emxEnsureCapacity(&b_st, (emxArray__common *)vk, q, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    i2 = iwork->size[0];
    for (q = 0; q < i2; q++) {
      c_st.site = &pb_emlrtRSI;
      vk->data[q] = div_s32(&c_st, iwork->data[q], cpsiz[1]);
    }

    q = varargout_6->size[0];
    varargout_6->size[0] = vk->size[0];
    emxEnsureCapacity(&b_st, (emxArray__common *)varargout_6, q, (int32_T)sizeof
                      (int32_T), &emlrtRTEI);
    i2 = vk->size[0];
    for (q = 0; q < i2; q++) {
      varargout_6->data[q] = vk->data[q] + 1;
    }

    q = iwork->size[0];
    emxEnsureCapacity(&b_st, (emxArray__common *)iwork, q, (int32_T)sizeof
                      (int32_T), &emlrtRTEI);
    i2 = iwork->size[0];
    for (q = 0; q < i2; q++) {
      iwork->data[q] -= vk->data[q] * cpsiz[1];
    }

    q = vk->size[0];
    vk->size[0] = iwork->size[0];
    emxEnsureCapacity(&b_st, (emxArray__common *)vk, q, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    i2 = iwork->size[0];
    for (q = 0; q < i2; q++) {
      c_st.site = &pb_emlrtRSI;
      vk->data[q] = div_s32(&c_st, iwork->data[q], cpsiz[0]);
    }

    q = iwork->size[0];
    emxEnsureCapacity(&b_st, (emxArray__common *)iwork, q, (int32_T)sizeof
                      (int32_T), &emlrtRTEI);
    i2 = iwork->size[0];
    for (q = 0; q < i2; q++) {
      iwork->data[q] -= vk->data[q] * cpsiz[0];
    }

    st.site = &g_emlrtRSI;
    for (q = 0; q < 2; q++) {
      xR[q << 1] = mm[q];
      xR[1 + (q << 1)] = brainRangeX[q];
      yR[q << 1] = indRangeY[q];
      yR[1 + (q << 1)] = brainRangeY[q];
      zR[q << 1] = indRangeZ[q];
      zR[1 + (q << 1)] = brainRangeZ[q];
    }

    b_a = (xR[3] - xR[1]) / (xR[2] - xR[0]);
    s = xR[1] - b_a * xR[0];
    q = varargin_1->size[0];
    varargin_1->size[0] = iwork->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)varargin_1, q, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    i2 = iwork->size[0];
    for (q = 0; q < i2; q++) {
      varargin_1->data[q] = b_a * (real_T)(iwork->data[q] + 1) + s;
    }

    b_a = (yR[3] - yR[1]) / (yR[2] - yR[0]);
    s = yR[1] - b_a * yR[0];
    q = varargin_2->size[0];
    varargin_2->size[0] = vk->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)varargin_2, q, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    i2 = vk->size[0];
    for (q = 0; q < i2; q++) {
      varargin_2->data[q] = b_a * (real_T)(vk->data[q] + 1) + s;
    }

    b_a = (zR[3] - zR[1]) / (zR[2] - zR[0]);
    s = zR[1] - b_a * zR[0];
    q = varargin_3->size[0];
    varargin_3->size[0] = varargout_6->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)varargin_3, q, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    i2 = varargout_6->size[0];
    for (q = 0; q < i2; q++) {
      varargin_3->data[q] = b_a * (real_T)varargout_6->data[q] + s;
    }

    b_st.site = &kb_emlrtRSI;
    c_st.site = &lb_emlrtRSI;
    d_st.site = &mb_emlrtRSI;
    overflow = true;
    if (varargin_1->size[0] == varargin_2->size[0]) {
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &n_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    if (varargin_1->size[0] == varargin_3->size[0]) {
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &n_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    q = b_x->size[0] * b_x->size[1];
    b_x->size[0] = varargin_1->size[0];
    b_x->size[1] = 3;
    emxEnsureCapacity(&c_st, (emxArray__common *)b_x, q, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    i2 = varargin_1->size[0];
    for (q = 0; q < i2; q++) {
      b_x->data[q] = varargin_1->data[q];
    }

    i2 = varargin_2->size[0];
    for (q = 0; q < i2; q++) {
      b_x->data[q + b_x->size[0]] = varargin_2->data[q];
    }

    i2 = varargin_3->size[0];
    for (q = 0; q < i2; q++) {
      b_x->data[q + (b_x->size[0] << 1)] = varargin_3->data[q];
    }

    st.site = &g_emlrtRSI;
    overflow = (b_x->size[0] != 1);
    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&st, &m_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    overflow = !isequal(b_x);
    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&st, &l_emlrtRTEI,
        "Coder:toolbox:UnsupportedSpecialEmpty", 0);
    }

    overflow = !isequal(b_x);
    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&st, &k_emlrtRTEI,
        "Coder:toolbox:UnsupportedSpecialEmpty", 0);
    }

    b_st.site = &nb_emlrtRSI;
    if (b_x->size[0] == 0) {
      for (q = 0; q < 3; q++) {
        siz[q] = 0.0;
      }
    } else {
      b_p = b_x->size[0];
      for (i2 = 0; i2 < 3; i2++) {
        pEnd = i2 * b_p;
        s = b_x->data[pEnd];
        c_st.site = &ob_emlrtRSI;
        if ((!(2 > b_p)) && (b_p > 2147483646)) {
          d_st.site = &s_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (k = 2; k <= b_p; k++) {
          s += b_x->data[(pEnd + k) - 1];
        }

        siz[i2] = s;
      }
    }

    i2 = b_x->size[0];
    b_p = r->size[0];
    if (!((i >= 1) && (i <= b_p))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, b_p, (emlrtBCInfo *)&emlrtBCI, sp);
    }

    for (q = 0; q < 3; q++) {
      r->data[(i + r->size[0] * q) - 1] = (siz[q] / (real_T)i2 - o[q]) * sc[q];
    }

    /* r(i,:) = (mean([ii,jj,kk]) - o) .* sc; */
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&varargin_3);
  emxFree_real_T(&varargin_2);
  emxFree_real_T(&varargin_1);
  emxFree_int32_T(&vk);
  emxFree_int32_T(&varargout_6);
  emxFree_boolean_T(&c_x);
  emxFree_int32_T(&iwork);
  emxFree_real_T(&b_x);
  emxFree_real32_T(&data_img);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (getNiiParcelCoord.cpp) */
