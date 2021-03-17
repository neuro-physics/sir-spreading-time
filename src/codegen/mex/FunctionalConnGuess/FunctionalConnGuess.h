/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FunctionalConnGuess.h
 *
 * Code generation for function 'FunctionalConnGuess'
 *
 */

#ifndef FUNCTIONALCONNGUESS_H
#define FUNCTIONALCONNGUESS_H

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
#include "FunctionalConnGuess_types.h"

/* Function Declarations */
extern void FunctionalConnGuess(const emlrtStack *sp, const emxArray_real_T *A,
  real_T Theta, real_T nSeeds, real_T nSim, real_T tTotal, emxArray_real_T *F);

#endif

/* End of code generation (FunctionalConnGuess.h) */
