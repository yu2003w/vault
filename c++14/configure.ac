#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

#
# Updated by Jared on March 07, 2017.
#

AC_PREREQ([2.69])
AC_INIT([cplus], [0.1.0], [yu2003w@hotmail.com])
AC_CONFIG_SRCDIR([src/concurrent/basic.cpp])
AC_CONFIG_HEADERS([config.h])

AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([-Wall foreign])

# Checks for programs.
AC_PROG_CXX([g++])
AC_PROG_CC

# Checks for libraries.

# initialize libtool
LT_PREREQ([2.4])
LT_INIT
LT_LANG([C++])
LT_OUTPUT


# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

AX_CXX_COMPILE_STDCXX([11], [noext], [mandatory])

# Checks for library functions.

AC_CONFIG_FILES([
    Makefile
    src/concurrent/Makefile
    src/lambda/Makefile
    src/misc/Makefile
    src/test/Makefile])
AC_OUTPUT
