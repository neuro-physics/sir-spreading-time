/*
 * _coder_calcNodesDistance_info.cpp
 *
 * Code generation for function '_coder_calcNodesDistance_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calcNodesDistance.h"
#include "_coder_calcNodesDistance_info.h"
#include "blas.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", mxCreateString("calcNodesDistance"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", mxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", mxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", mxCreateString("9.0.0.341360 (R2016a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo()
{
  const mxArray *nameCaptureInfo;
  const char * data[16] = {
    "789ced5dcb6f1b45189fd034b44205845495f26c40aa2a55784b2b55a8a7a479346e93366dd23425aab6ebf5389e767776b5bb4e9d5e3020211017382071ec11"
    "2121ae1cf907b8c109893b48dcfa07b0b30f7b3ddd78a63bb3b643c692e57cf67cb3bfeff19bf76ec044750584af97c377a705c054f879247cbf00e2d7e1449e",
    "08dfa793cff8fb49702c913f0bdfa68303d80ee21fb1614390beea8e8db08183f55d17020ffa8eb503ebd12f0d64c17564c36527232ca150b017333f7505f293"
    "d7f4bb35032b2bc4afc80ed0b36332c78e1b193b5e4de4ad857bf397b479cf716b4e5b7335d7f183ba636aaee76c7b86ed6bb61158464df391e76bbeeb41a38e",
    "f0b6d6686153330dcbbceed4a13f8ffcc0c026acd8118e730c1c937d382601763c9be87dc4d09ba2f04f455e6ed52cc8677f95d227f256757973e1dedc256d35"
    "36f81471baafadccae2fcf5ed66e9d3ff7e145430b1cc722ee81b6a559a896fa24fc08fda011f8a1e5bd3864ed98cac13191c17134f93e447f7c6de58fd9e2fa",
    "a2d797a77f26a33f91a30f329f45ca7f0906c7f916e88f3391a5c5797a1b6297fcd9c3b3cac0f32e8587c866c81baf82c2c6c3c3865541fee516b2822abedeb2"
    "a187cc67e250840f2c3f6d52fa9b45fc44de67236bb4b3a9391a6d4ee5197e3f475e2d9dfaed77c50b8ef2fb8d1727293c44a67851b30cbfd2c69e7d7e8f3894",
    "c18b354a7fad889f72797196d8a345f6243d86407ff1fe770f557f218317c38e378b176f5078889cc70b842d8461cfce41e3aef495ad97d73feb94deba64ffc4"
    "76c40e12c8a78b473e55fdc4ff910f1ce3a7880f2d1fea1e6c90bf85f8f00d03cf5d4aefae64ff64ec9030af50bce02dff3d181c7713f4c79dc825f062ba062d",
    "e7911e343de8371dabdec5c7e2c9db143e22e7f1245b7391f9bad9343c9e76e40e85e78e647f75ed48d61d143f54bf91c5f3168587c8141fd266b63bc518c6fc"
    "6283d2df90e7a7c49e9eab04f2eac73b27d5fc42062f861d6f567b7ea80fcf2160d47c2979df66e85fa1f4af14f14366fd015a64f921442fd4fe777ebd7d5ae5",
    "394ff951c757adb3aa7556c50329ebaabe69588657212d7fcfaeb2d68f4a1c17c67624be49f114ec07befdf392ea07f643fe6f32aeff1e757d2253f96fb8aeb5"
    "bb1625cf620b9b017270cfbe1946fdaf50f513b991d4a2370d5c0f3b069e75a42daa9ead227ecae5458e79e2fcf8fae905c50f9ef2e31af7b2fa8d7dbc1fa7fa",
    "8f1cfdb2f9c18af728d747f2f0bc48e121b2070dcb465868fdb4c3d0bb465df75a113ff4f5a3e11f5a825c38dfc1cf6a7d88af7c078c479c6718385ea2701039"
    "ac5a4f733dada7acfd82bde6c9ab628e703db4630450cb9822344f5679cf597edce22d61fcd3b01c235809bfb3327696c50729e7b572fbc19e1995cc79ad82e3",
    "1eb54fc0597edcc63d12f880701db657106e0d733e501e2f7ae688f3026cbc16a8f5d483cc0b72ef4696174b8c7a4f50f59ed8a3de2a0ec6812791798a273dfd"
    "83c613563ebf4ee121725e3eaf5a2d7f14fcb849d577539abfba66c938bfa7f8c1597edcf8c1ea47dea1f010994c5ac26af586e3598ee3eace0ef41ae438a0d9",
    "84e643b17d3ad6baf47d4aef7e11ff64a763b1bb06d823320fefa8793867f95fc0e0b87f01fae34ee4b2e33e3db880de84960bbd62f36be4375019fd096bdf73"
    "91aa6fb1a81f1ba80debae13a2d0882d82e7f87e523ce12b3feaf8ce30ae7f8cba3e91918fe3a33f01b9cd5c6c3daac3d0cbbd7f5cd8fe0c7eb173dc2acf39cb",
    "eff7fea0c8fa5258b56db4cbe5c755eaba5745fd162d67c7c825ccb3d57889b3fc41e507d9e2db9ffce86e732a7e80d1cfb3f7e17d40e938ff16b41c37ad776c"
    "e7d97e483858d762ef243eca5d824a2d129a67ffbd80152f64f41b9f83feb813b9ecb84f475bbdba19f2c6d7c9c3aa0c847d3d2d3447beeee257fbe36a7f7c94",
    "fcf9010c8e771bf4c79bc8a5f307f9ba8fb631acf793468db3d438eba08db396187838d65393e7d60442e32b965fcadbd74b9f5713c878de9ff16057f180a73c"
    "6b3cfd31e88f3791b7aa9b73e2ddc2423b0efc3c7461d8fa637337dbfe49b80f296e61e7c22fb7215e8a6f1dca8d0befb9f4167e889d4798cb6f3aa5af839827",
    "dc8e1bd891e698567145f8f28ffd44f14546bf711bf4c79dc8cf157746fb787979766dd68db63504cf893ccbbf61f06254ed49415e7cf2d757ea7c084ff92760"
    "70dc1f80feb813595e7b78b5babed6725dc70b603d270fdc1e4ed5afa87e651cf9336efdca7d069e0f283c44a678329894397129c297270cfd716977147f46cb",
    "9f61cf5b59ebbd6f5278889c379f4f78d9adb7ac79fdb0db97827c38fa58cdebb9ca171d47c87edea609770c4b8f1f0128693f31e2858f1e43dd0dbcd4deb278"
    "51e2b9e6c84fa91d82e710d5733639cb8f2b2f9618b88e53b8884cf1c2d44dc30f72e29057df61aa3e2287355d380ff87821bc3f38705c159ba2c64f3d7dc58b",
    "c2fb22f1736816b60b9fdf7a9eff83b44ae9af4af3536a86d0f315cefc7b43f181a77c078c479c67183878cfad979df7eafcbacafbb2dab73c1c47281c4426f7"
    "7bd846d01c46be4b3b0742ddaf42f04b3807a2f29db33c6b9cbbd7737464e6fb7403797e10df5757f47e3cd17c1ff5fd592acfcbcbf3ff00047b0952",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 30096U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_calcNodesDistance_info.cpp) */
