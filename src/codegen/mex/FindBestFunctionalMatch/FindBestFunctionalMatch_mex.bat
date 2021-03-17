@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2017b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2017b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=FindBestFunctionalMatch_mex
set MEX_NAME=FindBestFunctionalMatch_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for FindBestFunctionalMatch > FindBestFunctionalMatch_mex.mki
echo COMPILER=%COMPILER%>> FindBestFunctionalMatch_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> FindBestFunctionalMatch_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> FindBestFunctionalMatch_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> FindBestFunctionalMatch_mex.mki
echo LINKER=%LINKER%>> FindBestFunctionalMatch_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> FindBestFunctionalMatch_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> FindBestFunctionalMatch_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> FindBestFunctionalMatch_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> FindBestFunctionalMatch_mex.mki
echo OMPFLAGS= >> FindBestFunctionalMatch_mex.mki
echo OMPLINKFLAGS= >> FindBestFunctionalMatch_mex.mki
echo EMC_COMPILER=msvcpp120>> FindBestFunctionalMatch_mex.mki
echo EMC_CONFIG=optim>> FindBestFunctionalMatch_mex.mki
"C:\Program Files\MATLAB\R2017b\bin\win64\gmake" -B -f FindBestFunctionalMatch_mex.mk
