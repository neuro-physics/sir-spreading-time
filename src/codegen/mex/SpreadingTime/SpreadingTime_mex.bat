@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2017b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2017b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=SpreadingTime_mex
set MEX_NAME=SpreadingTime_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for SpreadingTime > SpreadingTime_mex.mki
echo COMPILER=%COMPILER%>> SpreadingTime_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> SpreadingTime_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> SpreadingTime_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> SpreadingTime_mex.mki
echo LINKER=%LINKER%>> SpreadingTime_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> SpreadingTime_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> SpreadingTime_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> SpreadingTime_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> SpreadingTime_mex.mki
echo OMPFLAGS= >> SpreadingTime_mex.mki
echo OMPLINKFLAGS= >> SpreadingTime_mex.mki
echo EMC_COMPILER=msvcpp120>> SpreadingTime_mex.mki
echo EMC_CONFIG=optim>> SpreadingTime_mex.mki
"C:\Program Files\MATLAB\R2017b\bin\win64\gmake" -B -f SpreadingTime_mex.mk
