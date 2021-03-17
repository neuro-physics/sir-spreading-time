/*
 * xgeqp3.cpp
 *
 * Code generation for function 'xgeqp3'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "findLinearTransformation.h"
#include "xgeqp3.h"
#include "error1.h"
#include "findLinearTransformation_emxutil.h"
#include "colon.h"
#include "findLinearTransformation_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo cb_emlrtRSI = { 75, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo db_emlrtRSI = { 112, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo nb_emlrtRSI = { 14, "xgeqp3",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRSInfo ob_emlrtRSI = { 41, "xgeqp3",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRSInfo pb_emlrtRSI = { 76, "xgeqp3",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRSInfo qb_emlrtRSI = { 79, "xgeqp3",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRTEInfo f_emlrtRTEI = { 1, 25, "xgeqp3",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRTEInfo m_emlrtRTEI = { 45, 5, "xgeqp3",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

/* Function Definitions */
void xgeqp3(const emlrtStack *sp, emxArray_real_T *A, emxArray_real_T *tau,
            emxArray_int32_T *jpvt)
{
  int32_T m;
  int32_T n;
  emxArray_ptrdiff_t *jpvt_t;
  int32_T i5;
  ptrdiff_t m_t;
  boolean_T p;
  boolean_T b_p;
  int32_T loop_ub;
  int32_T i6;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &nb_emlrtRSI;
  m = A->size[0];
  n = A->size[1];
  if ((A->size[0] == 0) || (A->size[1] == 0)) {
    i5 = tau->size[0];
    tau->size[0] = 0;
    emxEnsureCapacity(&st, (emxArray__common *)tau, i5, (int32_T)sizeof(real_T),
                      &f_emlrtRTEI);
    b_st.site = &ob_emlrtRSI;
    c_st.site = &bb_emlrtRSI;
    d_st.site = &cb_emlrtRSI;
    e_st.site = &db_emlrtRSI;
    eml_signed_integer_colon(&e_st, A->size[1], jpvt);
  } else {
    emxInit_ptrdiff_t(&st, &jpvt_t, 1, &m_emlrtRTEI, true);
    i5 = tau->size[0];
    tau->size[0] = muIntScalarMin_sint32(m, n);
    emxEnsureCapacity(&st, (emxArray__common *)tau, i5, (int32_T)sizeof(real_T),
                      &f_emlrtRTEI);
    i5 = jpvt_t->size[0];
    jpvt_t->size[0] = A->size[1];
    emxEnsureCapacity(&st, (emxArray__common *)jpvt_t, i5, (int32_T)sizeof
                      (ptrdiff_t), &f_emlrtRTEI);
    m = A->size[1];
    for (i5 = 0; i5 < m; i5++) {
      jpvt_t->data[i5] = (ptrdiff_t)0;
    }

    m_t = (ptrdiff_t)A->size[0];
    m_t = LAPACKE_dgeqp3(102, m_t, (ptrdiff_t)A->size[1], &A->data[0], m_t,
                         &jpvt_t->data[0], &tau->data[0]);
    m = (int32_T)m_t;
    b_st.site = &pb_emlrtRSI;
    if (m != 0) {
      p = true;
      b_p = false;
      if (m == -4) {
        b_p = true;
      }

      if (!b_p) {
        if (m == -1010) {
          c_st.site = &y_emlrtRSI;
          error(&c_st);
        } else {
          c_st.site = &ab_emlrtRSI;
          c_error(&c_st, m);
        }
      }
    } else {
      p = false;
    }

    if (p) {
      i5 = A->size[0] * A->size[1];
      emxEnsureCapacity(&st, (emxArray__common *)A, i5, (int32_T)sizeof(real_T),
                        &f_emlrtRTEI);
      m = A->size[1];
      for (i5 = 0; i5 < m; i5++) {
        loop_ub = A->size[0];
        for (i6 = 0; i6 < loop_ub; i6++) {
          A->data[i6 + A->size[0] * i5] = rtNaN;
        }
      }

      m = tau->size[0];
      i5 = tau->size[0];
      tau->size[0] = m;
      emxEnsureCapacity(&st, (emxArray__common *)tau, i5, (int32_T)sizeof(real_T),
                        &f_emlrtRTEI);
      for (i5 = 0; i5 < m; i5++) {
        tau->data[i5] = rtNaN;
      }

      b_st.site = &qb_emlrtRSI;
      c_st.site = &bb_emlrtRSI;
      d_st.site = &cb_emlrtRSI;
      e_st.site = &db_emlrtRSI;
      eml_signed_integer_colon(&e_st, n, jpvt);
    } else {
      i5 = jpvt->size[0] * jpvt->size[1];
      jpvt->size[0] = 1;
      jpvt->size[1] = jpvt_t->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)jpvt, i5, (int32_T)sizeof
                        (int32_T), &f_emlrtRTEI);
      m = jpvt_t->size[0];
      for (i5 = 0; i5 < m; i5++) {
        jpvt->data[jpvt->size[0] * i5] = (int32_T)jpvt_t->data[i5];
      }
    }

    emxFree_ptrdiff_t(&jpvt_t);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (xgeqp3.cpp) */
