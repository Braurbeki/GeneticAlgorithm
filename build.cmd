@echo off
set WORK_DIR=%CD%

if not exist %WORK_DIR%\build\ (
    mkdir %WORK_DIR%\build
)
pushd %WORK_DIR%\build
cmake ..\src\ .
cmake --build .
popd

if exist %WORK_DIR%\Ship\ (
    @RD /S /Q "%WORK_DIR%\Ship"
)
mkdir %WORK_DIR%\Ship
mkdir %WORK_DIR%\Ship\bin
set BIN_DIR=%WORK_DIR%\Ship\bin

move %WORK_DIR%\build\Debug\*.dll %BIN_DIR%

if exist %WORK_DIR%\build\ (
    @RD /S /Q "%WORK_DIR%\build"
)

py -3 test.py