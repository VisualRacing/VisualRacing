#!/usr/bin/env sh

# Exit on errors
set -e

cd "${TRAVIS_BUILD_DIR}"

. travis-ci/defs.sh

echo "Configuring for building for ${QT} on ${TRAVIS_OS_NAME}"

if [ $QT = qt5win ]; then
	PATH=$PATH:${MXEDIR}/usr/bin
	$MXEDIR/usr/bin/${MXETARGET}-qmake-qt5 --version
	$MXEDIR/usr/bin/${MXETARGET}-qmake-qt5 VisualRacing/VRMain/VRMain.pro MXE=1
fi

cd "${TRAVIS_BUILD_DIR}"

echo "Successfully configured build"
