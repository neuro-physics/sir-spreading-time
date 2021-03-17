/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_EvolveSINetworkAndCountActive_info.cpp
 *
 * Code generation for function '_coder_EvolveSINetworkAndCountActive_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EvolveSINetworkAndCountActive.h"
#include "_coder_EvolveSINetworkAndCountActive_info.h"

/* Function Definitions */
mxArray *emlrtMexFcnProperties()
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * fldNames[4] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 4, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString(
    "EvolveSINetworkAndCountActive"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.3.0.713579 (R2017b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo()
{
  const mxArray *nameCaptureInfo;
  const char * data[10] = {
    "789ced5a4d6fe344189eae966517096458405af6b015421c58a9eed736692f1b2771496852364d2292a0a23af6349dd6f6b8fe5a674f7be15ff0035642487082"
    "630ffc0538003f820b779cd84ee259460db265b7a9478a26af9f649e99578f9f198f072c55eb4b008077dccfa876b6c0b8bced5580f1eb5b205c487cc9afef11",
    "7150de00b743ff0bf0effc5ac4aa091dd30b64a4c27d4be943dd0d544181936624ac205550cdd65083408706966d288d916324c31652600dcf0415e406caee0c"
    "340946d0e87be9048a674d4b01fa8931edae3c1b8099fc5c50c67f7bcefcf428f96108fc6bfeb0bcc39675acf5b1c36aac860d53c222abe978a00b8ac12a8229",
    "0b7dd640bac11a9a0e0509a903d6d04596b747596956f7a1f91ceb679c2a95b0a59a9c68221bae28e1f11c51fa7b67cef1907550ee81bb33d1fb85804fa3b437"
    "6ffec81810d783baad498209abaa66996b4d08a5cbc63b2fff1d229ef27b8861ea96684ef3fb6344be3a952f8c47d00b99aab14492d3c7cbbfee7ffb3b97ac1e",
    "93d67f7a7c0ea5bd79f5f721858f2170beb667e8dbcd123ee83407ab6df4e485eaa8bbd37e3cbb84e7b27e004a9c54fb1794ff67be1f2e611d7e129bef93eb06"
    "40fc2ec09b555e860a54cdaa395e3d5c57dfff82ca17c623e82594aa14f4f1d1bbaf32dfbfeebe6fadf6cfb69ccda6b43e3cc5656ea3ce39dc905f1cdfcfeee3",
    "ffee7f5877cb85b87cf62e1183c9ef3c44d12564230926e5eb12b6fa324c410fd55a873f2cedb0cf3c012c8f9e550db6ceb56a5c913d585f5dcbf55913637924"
    "17a8c8ac8cfa8146b0e6cac5cfd38a3ff126a8871ffe3c5c685fffe9ab07bfa536bea8befe01858f2170a7dbebf1030ee9e79bb6c23f6975b9c6a900325fbf41",
    "f7b15bfe7e1a97cfbe49e1637cc41f6662ebf5b87dbd4ae50be351f510c8c19fe693dca7f9fe61233ddf5b74bea47c3dffbc71dcee6c6ee52ab67cb05dcee76b"
    "b82d82ccd7afca7d4cdb27995777b7883828c17b192674f5e382577f3a59bfbfa4b43f6ffe1e51f8190217b1e43eac20d57d645105790519450bc96655ddb714",
    "a82331b579e097887c1d2a5f18ffdffa197d1e8fb3c63e0ed2c692695b51129c0f7efee78f6c3eb8aaf3c1bcfb375fdae725eeb862e75b8dcda1c82beafa6e4f"
    "ae64f3c155990f8e28fd8b57779fc5e6ffcb143e86c009ff374441868e56c28a2698c875e4b4fcff22225f97ca17c6e3f1ffd7d296867ebef9f5fe42eff7a4ca",
    "97d43c7022697aaff3821707b9722d37dcb004ae912f66f3c0cd9a07760a71e9ee3d0a1f43e0c43ce08edebb7e5df781f6a87c613c1eff77d3e52b25f3fbc5e0"
    "4bcaef07c5e250ca6df07ccf59b72b7b2d54eeea07d9ba7fd2decd786f1bdff99cb7287c0c81bb0b56b1a98d0ee07a715ae7735e45e4fb9cca17c623e8639a2a",
    "571cd979ccc5e04bcadfdb7d6eb86d1876d75a3b3dab0f77b72574de5da0f398d7f5fe4d767f9f2978f5747fff88d27e763ec72b37e0bd7e763e275ebe71c9ce"
    "e7c4d3febf523032b4", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 13968U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_EvolveSINetworkAndCountActive_info.cpp) */
