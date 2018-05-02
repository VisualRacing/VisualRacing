echo on

SET project_dir="%cd%"

echo Set up environment...
set PATH=%QT%\bin\;C:\Qt\Tools\QtCreator\bin\;%PATH%
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" %PLATFORM%

echo Building YourApp...
cd VisualRacing
qmake

echo Running tests...
dir
cd VRTest


