echo on

SET project_dir="%cd%"
SET PATH=%QT%\bin\;C:\Qt\Tools\QtCreator\bin\;C:\Qt\QtIFW2.0.1\bin\;%PATH%

echo Set up environment...
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" %PLATFORM%

echo Building YourApp using ming232-make...
cd VisualRacing 
if not exist Makefile qmake -o Makefile VisualRacing.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug" 
mingw32-make -f Makefile

echo Building YourApp using nmake...
qmake -spec win32-msvc2015 CONFIG+=x86_64 CONFIG-=debug CONFIG+=release
nmake

echo Running tests...
dir


