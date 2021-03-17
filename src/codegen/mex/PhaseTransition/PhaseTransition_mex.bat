@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2017b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2017b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=PhaseTransition_mex
set MEX_NAME=PhaseTransition_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for PhaseTransition > PhaseTransition_mex.mki
echo COMPILER=%COMPILER%>> PhaseTransition_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> PhaseTransition_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> PhaseTransition_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> PhaseTransition_mex.mki
echo LINKER=%LINKER%>> PhaseTransition_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> PhaseTransition_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> PhaseTransition_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> PhaseTransition_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> PhaseTransition_mex.mki
echo OMPFLAGS= >> PhaseTransition_mex.mki
echo OMPLINKFLAGS= >> PhaseTransition_mex.mki
echo EMC_COMPILER=msvcpp120>> PhaseTransition_mex.mki
echo EMC_CONFIG=optim>> PhaseTransition_mex.mki
"C:\Program Files\MATLAB\R2017b\bin\win64\gmake" -B -f PhaseTransition_mex.mk
