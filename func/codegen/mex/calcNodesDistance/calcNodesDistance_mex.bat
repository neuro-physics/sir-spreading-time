@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2016a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2016a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=calcNodesDistance_mex
set MEX_NAME=calcNodesDistance_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for calcNodesDistance > calcNodesDistance_mex.mki
echo COMPILER=%COMPILER%>> calcNodesDistance_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> calcNodesDistance_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> calcNodesDistance_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> calcNodesDistance_mex.mki
echo LINKER=%LINKER%>> calcNodesDistance_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> calcNodesDistance_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> calcNodesDistance_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> calcNodesDistance_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> calcNodesDistance_mex.mki
echo BORLAND=%BORLAND%>> calcNodesDistance_mex.mki
echo OMPFLAGS= >> calcNodesDistance_mex.mki
echo OMPLINKFLAGS= >> calcNodesDistance_mex.mki
echo EMC_COMPILER=msvc120>> calcNodesDistance_mex.mki
echo EMC_CONFIG=optim>> calcNodesDistance_mex.mki
"C:\Program Files\MATLAB\R2016a\bin\win64\gmake" -B -f calcNodesDistance_mex.mk
