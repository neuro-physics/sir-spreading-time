@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2017b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2017b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=TwoSeedsSpreading_mex
set MEX_NAME=TwoSeedsSpreading_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for TwoSeedsSpreading > TwoSeedsSpreading_mex.mki
echo COMPILER=%COMPILER%>> TwoSeedsSpreading_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> TwoSeedsSpreading_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> TwoSeedsSpreading_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> TwoSeedsSpreading_mex.mki
echo LINKER=%LINKER%>> TwoSeedsSpreading_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> TwoSeedsSpreading_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> TwoSeedsSpreading_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> TwoSeedsSpreading_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> TwoSeedsSpreading_mex.mki
echo OMPFLAGS= >> TwoSeedsSpreading_mex.mki
echo OMPLINKFLAGS= >> TwoSeedsSpreading_mex.mki
echo EMC_COMPILER=msvcpp120>> TwoSeedsSpreading_mex.mki
echo EMC_CONFIG=optim>> TwoSeedsSpreading_mex.mki
"C:\Program Files\MATLAB\R2017b\bin\win64\gmake" -B -f TwoSeedsSpreading_mex.mk
