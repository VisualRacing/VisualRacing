#!/usr/bin/env sh

echo_and_run() {
	local CMD="$1"
	echo "${CMD}"
	eval "${CMD}"
}

echo_var() {
	# echo "$1 = ${!1}" does not work in dash (Ubuntu's default sh)
	eval "echo \"$1 = \$$1\""
}
