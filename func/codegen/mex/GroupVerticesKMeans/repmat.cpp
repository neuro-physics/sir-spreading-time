/*
 * repmat.cpp
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "GroupVerticesKMeans.h"
#include "repmat.h"

/* Function Definitions */
void repmat(const real_T a[2], real_T b[4])
{
  int32_T jcol;
  int32_T ibmat;
  int32_T itilerow;
  for (jcol = 0; jcol < 2; jcol++) {
    ibmat = jcol << 1;
    for (itilerow = 0; itilerow < 2; itilerow++) {
      b[ibmat + itilerow] = a[jcol];
    }
  }
}

/* End of code generation (repmat.cpp) */
