/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EvolveSINetwork_types.h
 *
 * Code generation for function 'EvolveSINetwork'
 *
 */

#ifndef EVOLVESINETWORK_TYPES_H
#define EVOLVESINETWORK_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_char_T*/

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

typedef struct {
  real_T N;
  real_T nSeeds;
  boolean_T isCompetitive;
  emxArray_real_T *seeds;
  real_T nSim;
  emxArray_char_T *seedType;
  real_T seedTrial;
  emxArray_real_T *x0;
} struct2_T;

#endif

/* End of code generation (EvolveSINetwork_types.h) */
