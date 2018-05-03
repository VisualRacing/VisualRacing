pushd VRTest/debug
dir
echo "Running Tests"
start tst_vrtest
start tst_vrtest -xunitxml > tests.xml
dir
type tests.xml
popd