/*
 * _coder_getNiiParcelCoord_api.cpp
 *
 * Code generation for function '_coder_getNiiParcelCoord_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "getNiiParcelCoord.h"
#include "_coder_getNiiParcelCoord_api.h"
#include "getNiiParcelCoord_emxutil.h"
#include "getNiiParcelCoord_data.h"

/* Variable Definitions */
static emlrtRTEInfo j_emlrtRTEI = { 1, 1, "_coder_getNiiParcelCoord_api", "" };

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *niiFile, const
  char_T *identifier, struct0_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y_data[], int32_T y_size[2]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct4_T *y);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real32_T *y);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct5_T *y);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct6_T *y);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct7_T *y);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct8_T *y);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *p, const
  char_T *identifier, emxArray_real_T *y);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_char_T *ret);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret_data[], int32_T ret_size[2]);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real32_T *ret);
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[6] = { "hdr", "filetype", "fileprefix",
    "machine", "img", "original" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 6, fieldNames, 0U, &dims);
  thisId.fIdentifier = "hdr";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "hdr")),
                     &thisId, &y->hdr);
  thisId.fIdentifier = "filetype";
  y->filetype = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "filetype")), &thisId);
  thisId.fIdentifier = "fileprefix";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "fileprefix")),
                     &thisId, y->fileprefix);
  thisId.fIdentifier = "machine";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "machine")),
                     &thisId, y->machine);
  thisId.fIdentifier = "img";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "img")),
                     &thisId, y->img);
  thisId.fIdentifier = "original";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "original")),
                     &thisId, &y->original);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[3] = { "hk", "dime", "hist" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, &dims);
  thisId.fIdentifier = "hk";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "hk")),
                     &thisId, &y->hk);
  thisId.fIdentifier = "dime";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "dime")),
                     &thisId, &y->dime);
  thisId.fIdentifier = "hist";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "hist")),
                     &thisId, &y->hist);
  emlrtDestroyArray(&u);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[7] = { "sizeof_hdr", "data_type", "db_name",
    "extents", "session_error", "regular", "dim_info" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 7, fieldNames, 0U, &dims);
  thisId.fIdentifier = "sizeof_hdr";
  y->sizeof_hdr = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "sizeof_hdr")), &thisId);
  thisId.fIdentifier = "data_type";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "data_type")),
                     &thisId, y->data_type);
  thisId.fIdentifier = "db_name";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "db_name")),
                     &thisId, y->db_name);
  thisId.fIdentifier = "extents";
  y->extents = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "extents")), &thisId);
  thisId.fIdentifier = "session_error";
  y->session_error = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
    0, "session_error")), &thisId);
  thisId.fIdentifier = "regular";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "regular")),
                     &thisId, y->regular);
  thisId.fIdentifier = "dim_info";
  y->dim_info = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "dim_info")), &thisId);
  emlrtDestroyArray(&u);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = r_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *niiFile, const
  char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(niiFile), &thisId, y);
  emlrtDestroyArray(&niiFile);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 0, 0 };

  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)u->data);
  emlrtSetDimensions((mxArray *)m0, u->size, 2);
  emlrtAssign(&y, m0);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y)
{
  s_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[21] = { "dim", "intent_p1", "intent_p2",
    "intent_p3", "intent_code", "datatype", "bitpix", "slice_start", "pixdim",
    "vox_offset", "scl_slope", "scl_inter", "slice_end", "slice_code",
    "xyzt_units", "cal_max", "cal_min", "slice_duration", "toffset", "glmax",
    "glmin" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 21, fieldNames, 0U, &dims);
  thisId.fIdentifier = "dim";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "dim")),
                     &thisId, y->dim.data, y->dim.size);
  thisId.fIdentifier = "intent_p1";
  y->intent_p1 = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "intent_p1")), &thisId);
  thisId.fIdentifier = "intent_p2";
  y->intent_p2 = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "intent_p2")), &thisId);
  thisId.fIdentifier = "intent_p3";
  y->intent_p3 = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "intent_p3")), &thisId);
  thisId.fIdentifier = "intent_code";
  y->intent_code = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
    0, "intent_code")), &thisId);
  thisId.fIdentifier = "datatype";
  y->datatype = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "datatype")), &thisId);
  thisId.fIdentifier = "bitpix";
  y->bitpix = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "bitpix")), &thisId);
  thisId.fIdentifier = "slice_start";
  y->slice_start = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
    0, "slice_start")), &thisId);
  thisId.fIdentifier = "pixdim";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "pixdim")),
                     &thisId, y->pixdim.data, y->pixdim.size);
  thisId.fIdentifier = "vox_offset";
  y->vox_offset = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "vox_offset")), &thisId);
  thisId.fIdentifier = "scl_slope";
  y->scl_slope = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "scl_slope")), &thisId);
  thisId.fIdentifier = "scl_inter";
  y->scl_inter = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "scl_inter")), &thisId);
  thisId.fIdentifier = "slice_end";
  y->slice_end = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "slice_end")), &thisId);
  thisId.fIdentifier = "slice_code";
  y->slice_code = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "slice_code")), &thisId);
  thisId.fIdentifier = "xyzt_units";
  y->xyzt_units = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "xyzt_units")), &thisId);
  thisId.fIdentifier = "cal_max";
  y->cal_max = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "cal_max")), &thisId);
  thisId.fIdentifier = "cal_min";
  y->cal_min = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "cal_min")), &thisId);
  thisId.fIdentifier = "slice_duration";
  y->slice_duration = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
    u, 0, "slice_duration")), &thisId);
  thisId.fIdentifier = "toffset";
  y->toffset = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "toffset")), &thisId);
  thisId.fIdentifier = "glmax";
  y->glmax = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "glmax")), &thisId);
  thisId.fIdentifier = "glmin";
  y->glmin = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "glmin")), &thisId);
  emlrtDestroyArray(&u);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y_data[], int32_T y_size[2])
{
  t_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct4_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[18] = { "descrip", "aux_file", "qform_code",
    "sform_code", "quatern_b", "quatern_c", "quatern_d", "qoffset_x",
    "qoffset_y", "qoffset_z", "srow_x", "srow_y", "srow_z", "intent_name",
    "magic", "originator", "rot_orient", "flip_orient" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 18, fieldNames, 0U, &dims);
  thisId.fIdentifier = "descrip";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "descrip")),
                     &thisId, y->descrip);
  thisId.fIdentifier = "aux_file";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "aux_file")),
                     &thisId, y->aux_file);
  thisId.fIdentifier = "qform_code";
  y->qform_code = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "qform_code")), &thisId);
  thisId.fIdentifier = "sform_code";
  y->sform_code = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "sform_code")), &thisId);
  thisId.fIdentifier = "quatern_b";
  y->quatern_b = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "quatern_b")), &thisId);
  thisId.fIdentifier = "quatern_c";
  y->quatern_c = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "quatern_c")), &thisId);
  thisId.fIdentifier = "quatern_d";
  y->quatern_d = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "quatern_d")), &thisId);
  thisId.fIdentifier = "qoffset_x";
  y->qoffset_x = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "qoffset_x")), &thisId);
  thisId.fIdentifier = "qoffset_y";
  y->qoffset_y = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "qoffset_y")), &thisId);
  thisId.fIdentifier = "qoffset_z";
  y->qoffset_z = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "qoffset_z")), &thisId);
  thisId.fIdentifier = "srow_x";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "srow_x")),
                     &thisId, y->srow_x);
  thisId.fIdentifier = "srow_y";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "srow_y")),
                     &thisId, y->srow_y);
  thisId.fIdentifier = "srow_z";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "srow_z")),
                     &thisId, y->srow_z);
  thisId.fIdentifier = "intent_name";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "intent_name")),
                     &thisId, y->intent_name);
  thisId.fIdentifier = "magic";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "magic")),
                     &thisId, y->magic);
  thisId.fIdentifier = "originator";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "originator")),
                     &thisId, y->originator);
  thisId.fIdentifier = "rot_orient";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "rot_orient")),
                     &thisId, y->rot_orient);
  thisId.fIdentifier = "flip_orient";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "flip_orient")),
                     &thisId, y->flip_orient);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real32_T *y)
{
  v_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct5_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[1] = { "hdr" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 1, fieldNames, 0U, &dims);
  thisId.fIdentifier = "hdr";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "hdr")),
                     &thisId, &y->hdr);
  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct6_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[3] = { "hk", "dime", "hist" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, &dims);
  thisId.fIdentifier = "hk";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "hk")),
                     &thisId, &y->hk);
  thisId.fIdentifier = "dime";
  n_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "dime")),
                     &thisId, &y->dime);
  thisId.fIdentifier = "hist";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "hist")),
                     &thisId, &y->hist);
  emlrtDestroyArray(&u);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct7_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[21] = { "dim", "intent_p1", "intent_p2",
    "intent_p3", "intent_code", "datatype", "bitpix", "slice_start", "pixdim",
    "vox_offset", "scl_slope", "scl_inter", "slice_end", "slice_code",
    "xyzt_units", "cal_max", "cal_min", "slice_duration", "toffset", "glmax",
    "glmin" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 21, fieldNames, 0U, &dims);
  thisId.fIdentifier = "dim";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "dim")),
                     &thisId, y->dim);
  thisId.fIdentifier = "intent_p1";
  y->intent_p1 = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "intent_p1")), &thisId);
  thisId.fIdentifier = "intent_p2";
  y->intent_p2 = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "intent_p2")), &thisId);
  thisId.fIdentifier = "intent_p3";
  y->intent_p3 = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "intent_p3")), &thisId);
  thisId.fIdentifier = "intent_code";
  y->intent_code = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
    0, "intent_code")), &thisId);
  thisId.fIdentifier = "datatype";
  y->datatype = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "datatype")), &thisId);
  thisId.fIdentifier = "bitpix";
  y->bitpix = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "bitpix")), &thisId);
  thisId.fIdentifier = "slice_start";
  y->slice_start = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
    0, "slice_start")), &thisId);
  thisId.fIdentifier = "pixdim";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "pixdim")),
                     &thisId, y->pixdim);
  thisId.fIdentifier = "vox_offset";
  y->vox_offset = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "vox_offset")), &thisId);
  thisId.fIdentifier = "scl_slope";
  y->scl_slope = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "scl_slope")), &thisId);
  thisId.fIdentifier = "scl_inter";
  y->scl_inter = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "scl_inter")), &thisId);
  thisId.fIdentifier = "slice_end";
  y->slice_end = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "slice_end")), &thisId);
  thisId.fIdentifier = "slice_code";
  y->slice_code = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "slice_code")), &thisId);
  thisId.fIdentifier = "xyzt_units";
  y->xyzt_units = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "xyzt_units")), &thisId);
  thisId.fIdentifier = "cal_max";
  y->cal_max = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "cal_max")), &thisId);
  thisId.fIdentifier = "cal_min";
  y->cal_min = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "cal_min")), &thisId);
  thisId.fIdentifier = "slice_duration";
  y->slice_duration = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
    u, 0, "slice_duration")), &thisId);
  thisId.fIdentifier = "toffset";
  y->toffset = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "toffset")), &thisId);
  thisId.fIdentifier = "glmax";
  y->glmax = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "glmax")), &thisId);
  thisId.fIdentifier = "glmin";
  y->glmin = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "glmin")), &thisId);
  emlrtDestroyArray(&u);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct8_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[16] = { "descrip", "aux_file", "qform_code",
    "sform_code", "quatern_b", "quatern_c", "quatern_d", "qoffset_x",
    "qoffset_y", "qoffset_z", "srow_x", "srow_y", "srow_z", "intent_name",
    "magic", "originator" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 16, fieldNames, 0U, &dims);
  thisId.fIdentifier = "descrip";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "descrip")),
                     &thisId, y->descrip);
  thisId.fIdentifier = "aux_file";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "aux_file")),
                     &thisId, y->aux_file);
  thisId.fIdentifier = "qform_code";
  y->qform_code = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "qform_code")), &thisId);
  thisId.fIdentifier = "sform_code";
  y->sform_code = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "sform_code")), &thisId);
  thisId.fIdentifier = "quatern_b";
  y->quatern_b = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "quatern_b")), &thisId);
  thisId.fIdentifier = "quatern_c";
  y->quatern_c = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "quatern_c")), &thisId);
  thisId.fIdentifier = "quatern_d";
  y->quatern_d = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "quatern_d")), &thisId);
  thisId.fIdentifier = "qoffset_x";
  y->qoffset_x = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "qoffset_x")), &thisId);
  thisId.fIdentifier = "qoffset_y";
  y->qoffset_y = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "qoffset_y")), &thisId);
  thisId.fIdentifier = "qoffset_z";
  y->qoffset_z = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "qoffset_z")), &thisId);
  thisId.fIdentifier = "srow_x";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "srow_x")),
                     &thisId, y->srow_x);
  thisId.fIdentifier = "srow_y";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "srow_y")),
                     &thisId, y->srow_y);
  thisId.fIdentifier = "srow_z";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "srow_z")),
                     &thisId, y->srow_z);
  thisId.fIdentifier = "intent_name";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "intent_name")),
                     &thisId, y->intent_name);
  thisId.fIdentifier = "magic";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "magic")),
                     &thisId, y->magic);
  thisId.fIdentifier = "originator";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "originator")),
                     &thisId, y->originator);
  emlrtDestroyArray(&u);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *p, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  q_emlrt_marshallIn(sp, emlrtAlias(p), &thisId, y);
  emlrtDestroyArray(&p);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  w_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_char_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  boolean_T bv0[2] = { true, true };

  int32_T iv1[2];
  int32_T i2;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims, &bv0[0],
    iv1);
  i2 = ret->size[0] * ret->size[1];
  ret->size[0] = iv1[0];
  ret->size[1] = iv1[1];
  emxEnsureCapacity(sp, (emxArray__common *)ret, i2, (int32_T)sizeof(char_T),
                    (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 1, false);
  emlrtDestroyArray(&src);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret_data[], int32_T ret_size[2])
{
  static const int32_T dims[2] = { 1, 8 };

  boolean_T bv1[2] = { false, true };

  int32_T iv2[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv1[0],
    iv2);
  ret_size[0] = iv2[0];
  ret_size[1] = iv2[1];
  emlrtImportArrayR2015b(sp, src, (void *)ret_data, 8, false);
  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  boolean_T bv2[2] = { false, true };

  int32_T iv3[2];
  int32_T i3;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv2[0],
    iv3);
  i3 = ret->size[0] * ret->size[1];
  ret->size[0] = iv3[0];
  ret->size[1] = iv3[1];
  emxEnsureCapacity(sp, (emxArray__common *)ret, i3, (int32_T)sizeof(real_T),
                    (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real32_T *ret)
{
  static const int32_T dims[3] = { -1, -1, -1 };

  boolean_T bv3[3] = { true, true, true };

  int32_T iv4[3];
  int32_T i4;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "single", false, 3U, dims, &bv3[0],
    iv4);
  i4 = ret->size[0] * ret->size[1] * ret->size[2];
  ret->size[0] = iv4[0];
  ret->size[1] = iv4[1];
  ret->size[2] = iv4[2];
  emxEnsureCapacity(sp, (emxArray__common *)ret, i4, (int32_T)sizeof(real32_T),
                    (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 4, false);
  emlrtDestroyArray(&src);
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  boolean_T bv4[2] = { true, true };

  int32_T iv5[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv4[0],
    iv5);
  ret->size[0] = iv5[0];
  ret->size[1] = iv5[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

void getNiiParcelCoord_api(const mxArray *prhs[2], const mxArray *plhs[1])
{
  struct0_T niiFile;
  emxArray_real_T *p;
  emxArray_real_T *r;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInitStruct_struct0_T(&st, &niiFile, &j_emlrtRTEI, true);
  emxInit_real_T(&st, &p, 2, &j_emlrtRTEI, true);
  emxInit_real_T(&st, &r, 2, &j_emlrtRTEI, true);
  prhs[1] = emlrtProtectR2012b(prhs[1], 1, false, -1);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "niiFile", &niiFile);
  p_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "p", p);

  /* Invoke the target function */
  getNiiParcelCoord(&st, &niiFile, p, r);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(r);
  r->canFreeData = false;
  emxFree_real_T(&r);
  p->canFreeData = false;
  emxFree_real_T(&p);
  emxFreeStruct_struct0_T(&niiFile);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_getNiiParcelCoord_api.cpp) */
