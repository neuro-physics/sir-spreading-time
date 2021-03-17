@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2016a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2016a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=GroupVerticesKMeans_mex
set MEX_NAME=GroupVerticesKMeans_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for GroupVerticesKMeans > GroupVerticesKMeans_mex.mki
echo COMPILER=%COMPILER%>> GroupVerticesKMeans_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> GroupVerticesKMeans_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> GroupVerticesKMeans_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> GroupVerticesKMeans_mex.mki
echo LINKER=%LINKER%>> GroupVerticesKMeans_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> GroupVerticesKMeans_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> GroupVerticesKMeans_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> GroupVerticesKMeans_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> GroupVerticesKMeans_mex.mki
echo BORLAND=%BORLAND%>> GroupVerticesKMeans_mex.mki
echo OMPFLAGS= >> GroupVerticesKMeans_mex.mki
echo OMPLINKFLAGS= >> GroupVerticesKMeans_mex.mki
echo EMC_COMPILER=msvc120>> GroupVerticesKMeans_mex.mki
echo EMC_CONFIG=optim>> GroupVerticesKMeans_mex.mki
"C:\Program Files\MATLAB\R2016a\bin\win64\gmake" -B -f GroupVerticesKMeans_mex.mk
