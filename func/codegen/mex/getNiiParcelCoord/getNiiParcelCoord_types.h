/*
 * getNiiParcelCoord_types.h
 *
 * Code generation for function 'getNiiParcelCoord'
 *
 */

#ifndef GETNIIPARCELCOORD_TYPES_H
#define GETNIIPARCELCOORD_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray__common*/

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

#ifndef struct_emxArray_real32_T
#define struct_emxArray_real32_T

struct emxArray_real32_T
{
  real32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real32_T*/

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

#ifndef struct_emxArray_real_T_1x8
#define struct_emxArray_real_T_1x8

struct emxArray_real_T_1x8
{
  real_T data[8];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_1x8*/

typedef struct {
  real_T sizeof_hdr;
  emxArray_char_T *data_type;
  emxArray_char_T *db_name;
  real_T extents;
  real_T session_error;
  emxArray_char_T *regular;
  real_T dim_info;
} struct2_T;

typedef struct {
  emxArray_real_T_1x8 dim;
  real_T intent_p1;
  real_T intent_p2;
  real_T intent_p3;
  real_T intent_code;
  real_T datatype;
  real_T bitpix;
  real_T slice_start;
  emxArray_real_T_1x8 pixdim;
  real_T vox_offset;
  real_T scl_slope;
  real_T scl_inter;
  real_T slice_end;
  real_T slice_code;
  real_T xyzt_units;
  real_T cal_max;
  real_T cal_min;
  real_T slice_duration;
  real_T toffset;
  real_T glmax;
  real_T glmin;
} struct3_T;

typedef struct {
  emxArray_char_T *descrip;
  emxArray_char_T *aux_file;
  real_T qform_code;
  real_T sform_code;
  real_T quatern_b;
  real_T quatern_c;
  real_T quatern_d;
  real_T qoffset_x;
  real_T qoffset_y;
  real_T qoffset_z;
  emxArray_real_T *srow_x;
  emxArray_real_T *srow_y;
  emxArray_real_T *srow_z;
  emxArray_char_T *intent_name;
  emxArray_char_T *magic;
  emxArray_real_T *originator;
  emxArray_real_T *rot_orient;
  emxArray_real_T *flip_orient;
} struct4_T;

typedef struct {
  struct2_T hk;
  struct3_T dime;
  struct4_T hist;
} struct1_T;

typedef struct {
  emxArray_real_T *dim;
  real_T intent_p1;
  real_T intent_p2;
  real_T intent_p3;
  real_T intent_code;
  real_T datatype;
  real_T bitpix;
  real_T slice_start;
  emxArray_real_T *pixdim;
  real_T vox_offset;
  real_T scl_slope;
  real_T scl_inter;
  real_T slice_end;
  real_T slice_code;
  real_T xyzt_units;
  real_T cal_max;
  real_T cal_min;
  real_T slice_duration;
  real_T toffset;
  real_T glmax;
  real_T glmin;
} struct7_T;

typedef struct {
  emxArray_char_T *descrip;
  emxArray_char_T *aux_file;
  real_T qform_code;
  real_T sform_code;
  real_T quatern_b;
  real_T quatern_c;
  real_T quatern_d;
  real_T qoffset_x;
  real_T qoffset_y;
  real_T qoffset_z;
  emxArray_real_T *srow_x;
  emxArray_real_T *srow_y;
  emxArray_real_T *srow_z;
  emxArray_char_T *intent_name;
  emxArray_char_T *magic;
  emxArray_real_T *originator;
} struct8_T;

typedef struct {
  struct2_T hk;
  struct7_T dime;
  struct8_T hist;
} struct6_T;

typedef struct {
  struct6_T hdr;
} struct5_T;

typedef struct {
  struct1_T hdr;
  real_T filetype;
  emxArray_char_T *fileprefix;
  emxArray_char_T *machine;
  emxArray_real32_T *img;
  struct5_T original;
} struct0_T;

#endif

/* End of code generation (getNiiParcelCoord_types.h) */
