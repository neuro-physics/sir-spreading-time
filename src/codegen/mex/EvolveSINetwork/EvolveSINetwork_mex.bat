@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2017b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2017b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=EvolveSINetwork_mex
set MEX_NAME=EvolveSINetwork_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for EvolveSINetwork > EvolveSINetwork_mex.mki
echo COMPILER=%COMPILER%>> EvolveSINetwork_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> EvolveSINetwork_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> EvolveSINetwork_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> EvolveSINetwork_mex.mki
echo LINKER=%LINKER%>> EvolveSINetwork_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> EvolveSINetwork_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> EvolveSINetwork_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> EvolveSINetwork_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> EvolveSINetwork_mex.mki
echo OMPFLAGS= >> EvolveSINetwork_mex.mki
echo OMPLINKFLAGS= >> EvolveSINetwork_mex.mki
echo EMC_COMPILER=msvcpp120>> EvolveSINetwork_mex.mki
echo EMC_CONFIG=optim>> EvolveSINetwork_mex.mki
"C:\Program Files\MATLAB\R2017b\bin\win64\gmake" -B -f EvolveSINetwork_mex.mk
