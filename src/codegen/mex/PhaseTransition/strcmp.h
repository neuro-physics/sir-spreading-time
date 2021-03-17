/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * strcmp.h
 *
 * Code generation for function 'strcmp'
 *
 */

#ifndef STRCMP_H
#define STRCMP_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "PhaseTransition_types.h"

/* Function Declarations */
extern boolean_T b_strcmp(const emlrtStack *sp, const emxArray_char_T *a);
extern boolean_T c_strcmp(const emlrtStack *sp, const emxArray_char_T *a);
extern boolean_T d_strcmp(const emlrtStack *sp, const emxArray_char_T *a);
extern boolean_T e_strcmp(const emlrtStack *sp, const emxArray_char_T *a);

#endif

/* End of code generation (strcmp.h) */
