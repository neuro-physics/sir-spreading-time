/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * randn.h
 *
 * Code generation for function 'randn'
 *
 */

#ifndef RANDN_H
#define RANDN_H

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
extern void randn(const emlrtStack *sp, const real_T varargin_1[2],
                  emxArray_real_T *r);

#endif

/* End of code generation (randn.h) */
