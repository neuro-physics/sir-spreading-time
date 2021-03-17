/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvolveSINetwork.h
 *
 * Code generation for function 'EvolveSINetwork'
 *
 */

#ifndef EVOLVESINETWORK_H
#define EVOLVESINETWORK_H

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
#include "EvolveSINetwork_types.h"

/* Function Declarations */
extern void EvolveSINetwork(const emlrtStack *sp, const emxArray_struct0_T
  *nodes, real_T tTotal, struct2_T *par, real_T returnTimeEvol, emxArray_real_T *
  xData, real_T *netActTime, emxArray_real_T *spTime);

#endif

/* End of code generation (EvolveSINetwork.h) */
