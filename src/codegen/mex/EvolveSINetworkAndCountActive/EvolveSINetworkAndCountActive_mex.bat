@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2017b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2017b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=EvolveSINetworkAndCountActive_mex
set MEX_NAME=EvolveSINetworkAndCountActive_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for EvolveSINetworkAndCountActive > EvolveSINetworkAndCountActive_mex.mki
echo COMPILER=%COMPILER%>> EvolveSINetworkAndCountActive_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> EvolveSINetworkAndCountActive_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> EvolveSINetworkAndCountActive_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> EvolveSINetworkAndCountActive_mex.mki
echo LINKER=%LINKER%>> EvolveSINetworkAndCountActive_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> EvolveSINetworkAndCountActive_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> EvolveSINetworkAndCountActive_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> EvolveSINetworkAndCountActive_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> EvolveSINetworkAndCountActive_mex.mki
echo OMPFLAGS= >> EvolveSINetworkAndCountActive_mex.mki
echo OMPLINKFLAGS= >> EvolveSINetworkAndCountActive_mex.mki
echo EMC_COMPILER=msvcpp120>> EvolveSINetworkAndCountActive_mex.mki
echo EMC_CONFIG=optim>> EvolveSINetworkAndCountActive_mex.mki
"C:\Program Files\MATLAB\R2017b\bin\win64\gmake" -B -f EvolveSINetworkAndCountActive_mex.mk
