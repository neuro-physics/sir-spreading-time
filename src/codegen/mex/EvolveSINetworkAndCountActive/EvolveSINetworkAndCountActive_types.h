/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvolveSINetworkAndCountActive_types.h
 *
 * Code generation for function 'EvolveSINetworkAndCountActive'
 *
 */

#ifndef EVOLVESINETWORKANDCOUNTACTIVE_TYPES_H
#define EVOLVESINETWORKANDCOUNTACTIVE_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

typedef struct {
  real_T Iext;
  real_T Isyn;
  real_T kInp;
  real_T Theta;
  real_T W;
  real_T n;
  real_T nInp;
  real_T spTime;
} struct1_T;

typedef struct {
  real_T x;
  emxArray_real_T *neigh;
  emxArray_real_T *w;
  struct1_T par;
} struct0_T;

#ifndef struct_emxArray_struct0_T
#define struct_emxArray_struct0_T

struct emxArray_struct0_T
{
  struct0_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_struct0_T*/
#endif

/* End of code generation (EvolveSINetworkAndCountActive_types.h) */
