echo on

SET project_dir="%cd%"
SET PATH=%QT%\bin\;%PATH%

cd VisualRacing 

echo Building YourApp using ming232-make...
qmake VisualRacing.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug" 
mingw32-make

