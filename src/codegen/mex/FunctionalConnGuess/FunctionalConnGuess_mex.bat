@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2017b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2017b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=FunctionalConnGuess_mex
set MEX_NAME=FunctionalConnGuess_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for FunctionalConnGuess > FunctionalConnGuess_mex.mki
echo COMPILER=%COMPILER%>> FunctionalConnGuess_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> FunctionalConnGuess_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> FunctionalConnGuess_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> FunctionalConnGuess_mex.mki
echo LINKER=%LINKER%>> FunctionalConnGuess_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> FunctionalConnGuess_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> FunctionalConnGuess_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> FunctionalConnGuess_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> FunctionalConnGuess_mex.mki
echo OMPFLAGS= >> FunctionalConnGuess_mex.mki
echo OMPLINKFLAGS= >> FunctionalConnGuess_mex.mki
echo EMC_COMPILER=msvcpp120>> FunctionalConnGuess_mex.mki
echo EMC_CONFIG=optim>> FunctionalConnGuess_mex.mki
"C:\Program Files\MATLAB\R2017b\bin\win64\gmake" -B -f FunctionalConnGuess_mex.mk
