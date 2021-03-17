@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2016a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2016a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=getNiiParcelCoord_mex
set MEX_NAME=getNiiParcelCoord_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for getNiiParcelCoord > getNiiParcelCoord_mex.mki
echo COMPILER=%COMPILER%>> getNiiParcelCoord_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> getNiiParcelCoord_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> getNiiParcelCoord_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> getNiiParcelCoord_mex.mki
echo LINKER=%LINKER%>> getNiiParcelCoord_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> getNiiParcelCoord_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> getNiiParcelCoord_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> getNiiParcelCoord_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> getNiiParcelCoord_mex.mki
echo BORLAND=%BORLAND%>> getNiiParcelCoord_mex.mki
echo OMPFLAGS= >> getNiiParcelCoord_mex.mki
echo OMPLINKFLAGS= >> getNiiParcelCoord_mex.mki
echo EMC_COMPILER=msvc120>> getNiiParcelCoord_mex.mki
echo EMC_CONFIG=optim>> getNiiParcelCoord_mex.mki
"C:\Program Files\MATLAB\R2016a\bin\win64\gmake" -B -f getNiiParcelCoord_mex.mk
