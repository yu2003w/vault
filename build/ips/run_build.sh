#!/bin/sh
# install dependencies
if [ "$1"x = "image"x ]; then
	podman build --network=host -t snort3_base:0.1 -f snort3.dockerfile
	if [ $? != 0 ]; then
		echo "build snort3 base image failed"
		return 1
	fi
	echo "build snort3 image successfully"
        return 0
fi

# podman run --network=host --privileged -v ./:/home/repo -it snort3_base:0.1 /bin/bash

# run some tests
$my_path/bin/snort --help
