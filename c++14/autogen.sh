#!/bin/sh
#
# Initiated by Jared on March 07, 2017.
#
# Invoke autoconf/automake to generate necessary build files.
#

if [ ! -f configure.ac ]; then
    echo "No configure.ac found. Please go to the proper directory"
    exit
fi

autoreconf --install -Wall --verbose $@

if [ $? = 0 ] ; then
    echo "Running configuration succeeded"
    echo "Please try ./configure"
fi

