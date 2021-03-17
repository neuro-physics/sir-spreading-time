/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * randperm.h
 *
 * Code generation for function 'randperm'
 *
 */

#ifndef RANDPERM_H
#define RANDPERM_H

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
#include "NetworkActivationTime_types.h"

/* Function Declarations */
extern void randperm(const emlrtStack *sp, real_T n, real_T k, emxArray_real_T
                     *p);

#endif

/* End of code generation (randperm.h) */
