pushd VRTest/debug
dir
echo "Running Tests"
start tst_vrtest.exe
start tst_vrtest.exe -xunitxml > tests.xml
dir
type tests.xml
popd