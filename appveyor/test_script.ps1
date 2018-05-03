pushd VRTest/debug
dir
echo "Running Tests"
.\tst_vrtest.exe
.\tst_vrtest.exe -xunitxml > tests.xml
dir
type tests.xml
popd