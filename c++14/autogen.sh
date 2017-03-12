#!/bin/sh
#
# Initiated by Jared on March 07, 2017.
#
# Invoke autoconf/automake to generate necessary build files.
#

autoreconf --install -Wall --verbose $@

if [ $? = 0 ] ; then
  echo "Running configuration succeeded"
  automake -a
  if [ $? = 0 ]; then
    echo "Running automake -a successfully."
    echo "Please try ./configure"
  fi
fi

