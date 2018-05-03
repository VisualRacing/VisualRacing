echo on

SET project_dir="%cd%"

echo Set up environment...

echo Building YourApp...
cd VRMain\ 
if not exist Makefile qmake -o Makefile VRMain.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug" 
mingw32-make -f Makefile

echo Running tests...
dir


