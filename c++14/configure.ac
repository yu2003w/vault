#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

#
# Updated by Jared on March 07, 2017.
#

AC_PREREQ([2.69])
AC_INIT([cplus], [0.1.0], [yu2003w@hotmail.com])
# AC_CONFIG_SRCDIR([src])
AC_CONFIG_HEADERS([config.h])

AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([-Wall -Wno-portability foreign])

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

AC_ARG_ENABLE([debug],
              AS_HELP_STRING([--enable-debug],
                             [enable debugging. If CFLAGS/CXXFLAGS are set,
                              this option won't change them]),
              [], [enable_debug=no])


############################################################
# Debug/Optimization checks
# Only update CFLAGS and CXXFLAGS if none are provided
############################################################

AM_CONDITIONAL([DEBUG],[test x"$enable_debug" = "xyes"])
AM_CONDITIONAL([OPTIMIZE],[test x"$enable_optimize" = "xyes"])

debug_flags="-g1"
if test "x$enable_debug" = "xyes"; then
  debug_flags="-g"
elif test "x$enable_optimize" = "xyes"; then
  debug_flags=""
fi

if test "x$enable_optimize" = "xyes"; then
  optimize_flags="-O2"
else
  optimize_flags="-O0"
fi

AS_IF([test "x${ac_cv_env_CFLAGS_set}" = "x"],
      [CFLAGS="$debug_flags $optimize_flags"])
AS_IF([test "x${ac_cv_env_CXXFLAGS_set}" = "x"],
      [CXXFLAGS="$debug_flags $optimize_flags"])

# check for pthreads support (m4/ax_pthread.m4)
AX_PTHREAD([],[AC_MSG_ERROR([failed to find pthread support])])

# Checks for library functions.

AC_CONFIG_FILES([
    Makefile
    src/Makefile])
AC_OUTPUT
