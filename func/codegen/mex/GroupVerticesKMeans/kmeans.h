/*
 * kmeans.h
 *
 * Code generation for function 'kmeans'
 *
 */

#ifndef KMEANS_H
#define KMEANS_H

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
#include "GroupVerticesKMeans_types.h"

/* Function Declarations */
extern void kmeans(const emlrtStack *sp, emxArray_real_T *X, real_T kin, const
                   emxArray_real_T *varargin_2, emxArray_real_T *idxbest);

#endif

/* End of code generation (kmeans.h) */
