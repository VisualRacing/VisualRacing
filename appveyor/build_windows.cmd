echo on

SET project_dir="%cd%"


echo Building YourApp using ming232-make...
qmake VisualRacing.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug" 
mingw32-make

