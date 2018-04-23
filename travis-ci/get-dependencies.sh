#!/usr/bin/env sh

# Exit on errors
set -e

cd "${TRAVIS_BUILD_DIR}"

. travis-ci/defs.sh

echo "Getting dependencies for building for ${QT} on ${TRAVIS_OS_NAME}"

if [ "${TRAVIS_OS_NAME}" = "linux" ]; then
	if [ $QT = "qt5win" ]; then
		MXEDIR="/usr/lib/mxe"
		MXETARGET="i686-w64-mingw32.static"

		echo "MXEDIR=\"${MXEDIR}\"" >> travis-ci/defs.sh
		echo "MXETARGET=\"${MXETARGET}\"" >> travis-ci/defs.sh

		echo "Exporting CC = ${MXETARGET}-gcc"
		CC="${MXETARGET}-gcc"
		echo "Exporting CXX = ${MXETARGET}-g++"
		CXX="${MXETARGET}-g++"

		JOBS=$(grep '^processor' /proc/cpuinfo | wc -l)

		echo "Adding pkg.mxe.cc apt repo"
		echo "deb http://pkg.mxe.cc/repos/apt/debian jessie main" | sudo tee /etc/apt/sources.list.d/mxeapt.list > /dev/null
		sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys D43A795B73B16ABE9643FE1AFD8FFF16DB45C6AB

		echo "Updating apt cache"
		sudo apt-get -qq update

		sudo apt-get install -y mxe-i686-w64-mingw32.static-gcc \
			mxe-i686-w64-mingw32.static-pkgconf \
			mxe-i686-w64-mingw32.static-qtbase \
			mxe-i686-w64-mingw32.static-qttools \
			mxe-i686-w64-mingw32.static-nsis

		echo "Make MXE writable"
		sudo chmod -R a+w "${MXEDIR}"
	fi
else
	echo "Unsupported host/target combination '${TRAVIS_OS_NAME}'"
	exit 1
fi

cd "${TRAVIS_BUILD_DIR}"

echo "Successfully set up dependencies"
