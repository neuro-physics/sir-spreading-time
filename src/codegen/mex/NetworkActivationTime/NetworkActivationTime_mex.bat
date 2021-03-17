@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2017b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2017b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=NetworkActivationTime_mex
set MEX_NAME=NetworkActivationTime_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for NetworkActivationTime > NetworkActivationTime_mex.mki
echo COMPILER=%COMPILER%>> NetworkActivationTime_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> NetworkActivationTime_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> NetworkActivationTime_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> NetworkActivationTime_mex.mki
echo LINKER=%LINKER%>> NetworkActivationTime_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> NetworkActivationTime_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> NetworkActivationTime_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> NetworkActivationTime_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> NetworkActivationTime_mex.mki
echo OMPFLAGS= >> NetworkActivationTime_mex.mki
echo OMPLINKFLAGS= >> NetworkActivationTime_mex.mki
echo EMC_COMPILER=msvcpp120>> NetworkActivationTime_mex.mki
echo EMC_CONFIG=optim>> NetworkActivationTime_mex.mki
"C:\Program Files\MATLAB\R2017b\bin\win64\gmake" -B -f NetworkActivationTime_mex.mk
