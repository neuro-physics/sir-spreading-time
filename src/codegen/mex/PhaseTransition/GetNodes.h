/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * GetNodes.h
 *
 * Code generation for function 'GetNodes'
 *
 */

#ifndef GETNODES_H
#define GETNODES_H

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
extern void GetNodes(const emlrtStack *sp, const emxArray_real_T *A, real_T
                     Theta, const emxArray_real_T *x0, emxArray_struct_T *nodes);

#endif

/* End of code generation (GetNodes.h) */
