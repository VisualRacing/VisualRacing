echo on

SET project_dir="%cd%"

echo Set up environment...

echo Building YourApp...
cd VisualRacing 
if not exist Makefile qmake -o Makefile VisualRacing.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug" 
mingw32-make -f Makefile

echo Running tests...
dir


