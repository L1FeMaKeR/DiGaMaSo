@echo off
call "F:\Programme\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x64     
set compilerflags=/Od /Zi /EHsc
set linkerflags=/OUT:DiGaMaSo.exe user32.lib
pushd ..\build
"F:\Programme\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.14.26428\bin\Hostx64\x64\cl.exe" %compilerflags% ..\source\win32\win32.cpp /link %linkerflags%
popd