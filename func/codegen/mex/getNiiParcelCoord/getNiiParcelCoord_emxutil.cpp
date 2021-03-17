/*
 * getNiiParcelCoord_emxutil.cpp
 *
 * Code generation for function 'getNiiParcelCoord_emxutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "getNiiParcelCoord.h"
#include "getNiiParcelCoord_emxutil.h"

/* Function Declarations */
static void emxFreeStruct_struct1_T(struct1_T *pStruct);
static void emxFreeStruct_struct2_T(struct2_T *pStruct);
static void emxFreeStruct_struct4_T(struct4_T *pStruct);
static void emxFreeStruct_struct5_T(struct5_T *pStruct);
static void emxFreeStruct_struct6_T(struct6_T *pStruct);
static void emxFreeStruct_struct7_T(struct7_T *pStruct);
static void emxFreeStruct_struct8_T(struct8_T *pStruct);
static void emxFree_char_T(emxArray_char_T **pEmxArray);
static void emxInitStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush);
static void emxInitStruct_struct2_T(const emlrtStack *sp, struct2_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush);
static void emxInitStruct_struct3_T(struct3_T *pStruct);
static void emxInitStruct_struct4_T(const emlrtStack *sp, struct4_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush);
static void emxInitStruct_struct5_T(const emlrtStack *sp, struct5_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush);
static void emxInitStruct_struct6_T(const emlrtStack *sp, struct6_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush);
static void emxInitStruct_struct7_T(const emlrtStack *sp, struct7_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush);
static void emxInitStruct_struct8_T(const emlrtStack *sp, struct8_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush);
static void emxInit_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);

/* Function Definitions */
static void emxFreeStruct_struct1_T(struct1_T *pStruct)
{
  emxFreeStruct_struct2_T(&pStruct->hk);
  emxFreeStruct_struct4_T(&pStruct->hist);
}

static void emxFreeStruct_struct2_T(struct2_T *pStruct)
{
  emxFree_char_T(&pStruct->data_type);
  emxFree_char_T(&pStruct->db_name);
  emxFree_char_T(&pStruct->regular);
}

static void emxFreeStruct_struct4_T(struct4_T *pStruct)
{
  emxFree_char_T(&pStruct->descrip);
  emxFree_char_T(&pStruct->aux_file);
  emxFree_real_T(&pStruct->srow_x);
  emxFree_real_T(&pStruct->srow_y);
  emxFree_real_T(&pStruct->srow_z);
  emxFree_char_T(&pStruct->intent_name);
  emxFree_char_T(&pStruct->magic);
  emxFree_real_T(&pStruct->originator);
  emxFree_real_T(&pStruct->rot_orient);
  emxFree_real_T(&pStruct->flip_orient);
}

static void emxFreeStruct_struct5_T(struct5_T *pStruct)
{
  emxFreeStruct_struct6_T(&pStruct->hdr);
}

static void emxFreeStruct_struct6_T(struct6_T *pStruct)
{
  emxFreeStruct_struct2_T(&pStruct->hk);
  emxFreeStruct_struct7_T(&pStruct->dime);
  emxFreeStruct_struct8_T(&pStruct->hist);
}

static void emxFreeStruct_struct7_T(struct7_T *pStruct)
{
  emxFree_real_T(&pStruct->dim);
  emxFree_real_T(&pStruct->pixdim);
}

static void emxFreeStruct_struct8_T(struct8_T *pStruct)
{
  emxFree_char_T(&pStruct->descrip);
  emxFree_char_T(&pStruct->aux_file);
  emxFree_real_T(&pStruct->srow_x);
  emxFree_real_T(&pStruct->srow_y);
  emxFree_real_T(&pStruct->srow_z);
  emxFree_char_T(&pStruct->intent_name);
  emxFree_char_T(&pStruct->magic);
  emxFree_real_T(&pStruct->originator);
}

static void emxFree_char_T(emxArray_char_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_char_T *)NULL;
  }
}

static void emxInitStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxInitStruct_struct2_T(sp, &pStruct->hk, srcLocation, doPush);
  emxInitStruct_struct3_T(&pStruct->dime);
  emxInitStruct_struct4_T(sp, &pStruct->hist, srcLocation, doPush);
}

static void emxInitStruct_struct2_T(const emlrtStack *sp, struct2_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxInit_char_T(sp, &pStruct->data_type, 2, srcLocation, doPush);
  emxInit_char_T(sp, &pStruct->db_name, 2, srcLocation, doPush);
  emxInit_char_T(sp, &pStruct->regular, 2, srcLocation, doPush);
}

static void emxInitStruct_struct3_T(struct3_T *pStruct)
{
  pStruct->dim.size[0] = 0;
  pStruct->dim.size[1] = 0;
  pStruct->pixdim.size[0] = 0;
  pStruct->pixdim.size[1] = 0;
}

static void emxInitStruct_struct4_T(const emlrtStack *sp, struct4_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxInit_char_T(sp, &pStruct->descrip, 2, srcLocation, doPush);
  emxInit_char_T(sp, &pStruct->aux_file, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->srow_x, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->srow_y, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->srow_z, 2, srcLocation, doPush);
  emxInit_char_T(sp, &pStruct->intent_name, 2, srcLocation, doPush);
  emxInit_char_T(sp, &pStruct->magic, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->originator, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->rot_orient, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->flip_orient, 2, srcLocation, doPush);
}

static void emxInitStruct_struct5_T(const emlrtStack *sp, struct5_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxInitStruct_struct6_T(sp, &pStruct->hdr, srcLocation, doPush);
}

static void emxInitStruct_struct6_T(const emlrtStack *sp, struct6_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxInitStruct_struct2_T(sp, &pStruct->hk, srcLocation, doPush);
  emxInitStruct_struct7_T(sp, &pStruct->dime, srcLocation, doPush);
  emxInitStruct_struct8_T(sp, &pStruct->hist, srcLocation, doPush);
}

static void emxInitStruct_struct7_T(const emlrtStack *sp, struct7_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->dim, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->pixdim, 2, srcLocation, doPush);
}

static void emxInitStruct_struct8_T(const emlrtStack *sp, struct8_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxInit_char_T(sp, &pStruct->descrip, 2, srcLocation, doPush);
  emxInit_char_T(sp, &pStruct->aux_file, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->srow_x, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->srow_y, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->srow_z, 2, srcLocation, doPush);
  emxInit_char_T(sp, &pStruct->intent_name, 2, srcLocation, doPush);
  emxInit_char_T(sp, &pStruct->magic, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->originator, 2, srcLocation, doPush);
}

static void emxInit_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxArray_char_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T *)emlrtMallocMex(sizeof(emxArray_char_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b((emlrtRTEInfo *)srcLocation, sp);
  }

  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_char_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b((emlrtRTEInfo *)srcLocation, sp);
  }

  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxEnsureCapacity(const emlrtStack *sp, emxArray__common *emxArray, int32_T
  oldNumel, int32_T elementSize, const emlrtRTEInfo *srcLocation)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)newNumel, (uint32_T)
      emxArray->size[i], (emlrtRTEInfo *)srcLocation, sp);
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = emlrtCallocMex((uint32_T)i, (uint32_T)elementSize);
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b((emlrtRTEInfo *)srcLocation, sp);
    }

    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, (uint32_T)(elementSize * oldNumel));
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }

    emxArray->data = newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFreeStruct_struct1_T(&pStruct->hdr);
  emxFree_char_T(&pStruct->fileprefix);
  emxFree_char_T(&pStruct->machine);
  emxFree_real32_T(&pStruct->img);
  emxFreeStruct_struct5_T(&pStruct->original);
}

void emxFree_boolean_T(emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) && (*pEmxArray)->canFreeData)
    {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int32_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

void emxFree_real32_T(emxArray_real32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real32_T *)NULL) {
    if (((*pEmxArray)->data != (real32_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_real32_T *)NULL;
  }
}

void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct, const
  emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxInitStruct_struct1_T(sp, &pStruct->hdr, srcLocation, doPush);
  emxInit_char_T(sp, &pStruct->fileprefix, 2, srcLocation, doPush);
  emxInit_char_T(sp, &pStruct->machine, 2, srcLocation, doPush);
  emxInit_real32_T(sp, &pStruct->img, 3, srcLocation, doPush);
  emxInitStruct_struct5_T(sp, &pStruct->original, srcLocation, doPush);
}

void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxArray_boolean_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_boolean_T *)emlrtMallocMex(sizeof(emxArray_boolean_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b((emlrtRTEInfo *)srcLocation, sp);
  }

  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_boolean_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b((emlrtRTEInfo *)srcLocation, sp);
  }

  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray, int32_T
                     numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
                     doPush)
{
  emxArray_int32_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_int32_T *)emlrtMallocMex(sizeof(emxArray_int32_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b((emlrtRTEInfo *)srcLocation, sp);
  }

  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_int32_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b((emlrtRTEInfo *)srcLocation, sp);
  }

  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_int32_T1(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
                      int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                      boolean_T doPush)
{
  emxArray_int32_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_int32_T *)emlrtMallocMex(sizeof(emxArray_int32_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b((emlrtRTEInfo *)srcLocation, sp);
  }

  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_int32_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b((emlrtRTEInfo *)srcLocation, sp);
  }

  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_real32_T(const emlrtStack *sp, emxArray_real32_T **pEmxArray,
                      int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                      boolean_T doPush)
{
  emxArray_real32_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real32_T *)emlrtMallocMex(sizeof(emxArray_real32_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b((emlrtRTEInfo *)srcLocation, sp);
  }

  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real32_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b((emlrtRTEInfo *)srcLocation, sp);
  }

  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_real32_T1(const emlrtStack *sp, emxArray_real32_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxArray_real32_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real32_T *)emlrtMallocMex(sizeof(emxArray_real32_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b((emlrtRTEInfo *)srcLocation, sp);
  }

  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real32_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b((emlrtRTEInfo *)srcLocation, sp);
  }

  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray, int32_T
                    numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
                    doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b((emlrtRTEInfo *)srcLocation, sp);
  }

  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b((emlrtRTEInfo *)srcLocation, sp);
  }

  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_real_T1(const emlrtStack *sp, emxArray_real_T **pEmxArray, int32_T
                     numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
                     doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b((emlrtRTEInfo *)srcLocation, sp);
  }

  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b((emlrtRTEInfo *)srcLocation, sp);
  }

  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/* End of code generation (getNiiParcelCoord_emxutil.cpp) */
