/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rand.h
 *
 * Code generation for function 'rand'
 *
 */

#ifndef RAND_H
#define RAND_H

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
extern real_T b_rand();
extern void c_rand(const emlrtStack *sp, real_T varargin_1, real_T varargin_2,
                   emxArray_real_T *r);

#endif

/* End of code generation (rand.h) */
