#!/bin/sh
# simple commands for snort3 testing
export my_path=$(pwd)/snort3_install/
$my_path/bin/snort --help
if [ $? != 0 ]; then
	echo "Possibly snort is not deployed successfully"
	return 1
fi
$my_path/bin/snort -i tap0
