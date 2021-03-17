/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * TwoSeedsSpreading_types.h
 *
 * Code generation for function 'TwoSeedsSpreading'
 *
 */

#ifndef TWOSEEDSSPREADING_TYPES_H
#define TWOSEEDSSPREADING_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  real_T Iext;
  real_T Isyn;
  real_T kInp;
  real_T Theta;
  real_T W;
  real_T n;
  real_T nInp;
  real_T spTime;
} struct_T;

typedef struct {
  real_T x;
  struct_T par;
} c_struct_T;

#ifndef struct_b_emxArray_struct_T
#define struct_b_emxArray_struct_T

struct b_emxArray_struct_T
{
  c_struct_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_b_emxArray_struct_T*/

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
  real_T x;
  emxArray_real_T *neigh;
  emxArray_real_T *w;
  struct_T par;
} b_struct_T;

typedef struct {
  real_T N;
  real_T nSeeds;
  real_T isCompetitive;
  emxArray_real_T *seeds;
  real_T nSim;
  char_T seedType[5];
  real_T seedTrial;
  real_T x0[2];
} d_struct_T;

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef struct_emxArray_int8_T
#define struct_emxArray_int8_T

struct emxArray_int8_T
{
  int8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int8_T*/

#ifndef struct_emxArray_struct_T
#define struct_emxArray_struct_T

struct emxArray_struct_T
{
  b_struct_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_struct_T*/
#endif

/* End of code generation (TwoSeedsSpreading_types.h) */
