@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2016a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2016a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=findLinearTransformation_mex
set MEX_NAME=findLinearTransformation_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for findLinearTransformation > findLinearTransformation_mex.mki
echo COMPILER=%COMPILER%>> findLinearTransformation_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> findLinearTransformation_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> findLinearTransformation_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> findLinearTransformation_mex.mki
echo LINKER=%LINKER%>> findLinearTransformation_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> findLinearTransformation_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> findLinearTransformation_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> findLinearTransformation_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> findLinearTransformation_mex.mki
echo BORLAND=%BORLAND%>> findLinearTransformation_mex.mki
echo OMPFLAGS= >> findLinearTransformation_mex.mki
echo OMPLINKFLAGS= >> findLinearTransformation_mex.mki
echo EMC_COMPILER=msvc120>> findLinearTransformation_mex.mki
echo EMC_CONFIG=optim>> findLinearTransformation_mex.mki
"C:\Program Files\MATLAB\R2016a\bin\win64\gmake" -B -f findLinearTransformation_mex.mk
