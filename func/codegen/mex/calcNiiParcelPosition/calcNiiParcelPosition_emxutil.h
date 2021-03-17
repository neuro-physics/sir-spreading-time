/*
 * calcNiiParcelPosition_emxutil.h
 *
 * Code generation for function 'calcNiiParcelPosition_emxutil'
 *
 */

#pragma once

/* Include files */
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "calcNiiParcelPosition_types.h"

/* Function Declarations */
CODEGEN_EXPORT_SYM void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray,
  int32_T oldNumel);
CODEGEN_EXPORT_SYM void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray,
  int32_T oldNumel);
CODEGEN_EXPORT_SYM void emxEnsureCapacity_real32_T(emxArray_real32_T *emxArray,
  int32_T oldNumel);
CODEGEN_EXPORT_SYM void emxEnsureCapacity_real_T(emxArray_real_T *emxArray,
  int32_T oldNumel);
CODEGEN_EXPORT_SYM void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
CODEGEN_EXPORT_SYM void emxFree_int32_T(emxArray_int32_T **pEmxArray);
CODEGEN_EXPORT_SYM void emxFree_real32_T(emxArray_real32_T **pEmxArray);
CODEGEN_EXPORT_SYM void emxFree_real_T(emxArray_real_T **pEmxArray);
CODEGEN_EXPORT_SYM void emxInit_boolean_T(emxArray_boolean_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
CODEGEN_EXPORT_SYM void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T
  numDimensions, boolean_T doPush);
CODEGEN_EXPORT_SYM void emxInit_real32_T(emxArray_real32_T **pEmxArray, int32_T
  numDimensions, boolean_T doPush);
CODEGEN_EXPORT_SYM void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T
  numDimensions, boolean_T doPush);

/* End of code generation (calcNiiParcelPosition_emxutil.h) */
