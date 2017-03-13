#
# Initiated by Jared on March 07, 2017.
#

# specify "subdir-objects" to build objects in respect subdirectories
AUTOMAKE_OPTIONS = subdir-objects

# initialize variables here to enable usage of += operator everywhere else
lib_LTLIBRARIES = 
noinst_LTLIBRARIES = 
bin_PROGRAMS = 
sbin_PROGRAMS =
noinst_LIBRARIES =
BUILT_SOURCES = 
LDADD = 

AM_LDFLAGS =

#AM_CPPFLAGS = -I $(top_srcdir)/src/concurrent/

# link only needed libraries
AM_LDFLAGS += -Wl,--as-needed

# enable multiple-thread support
AM_CXXFLAGS = $(PTHREAD_CFLAGS)

AM_CXXFLAGS += -Wall -Wsign-compare -Wformat-security -fPIC -fPIE

# set CPPFLAGS that used for general compile options
COMMON_CPPFLAGS = $(AM_CPPFLAGS)
COMMON_CPPFLAGS += -Werror
COMMON_CPPFLAGS += -I$(top_srcdir)/include

# set DEBUG flag to use in source code
COMMON_CPPFLAGS += -DDEBUG

# PTHREAD_LIBS and PTHREAD_CFLAGS are defined in m4/ax_pthread.m4
AM_LIBS = $(PTHREAD_LIBS)

noinst_LTLIBRARIES += libconcurrent.la

# noted: for all variables, each line should be tab started.
libconcurrent_la_SOURCES =                                    \
	concurrent/basic.cpp                                  \
	concurrent/sync.cpp

libconcurrent_la_CPPFLAGS = $(COMMON_CPPFLAGS)
libconcurrent_la_LIBADD = 

noinst_LTLIBRARIES += libmisc.la

libmisc_la_SOURCES =                                           \
	misc/misc.cpp                                           

libmisc_la_CPPFLAGS = $(COMMON_CPPFLAGS)
libmisc_la_LIBADD =

noinst_LTLIBRARIES += liblambda.la

liblambda_la_SOURCES =                                          \
	lambda/lambda_exam.cpp

liblambda_la_CPPFLAGS = $(COMMON_CPPFLAGS)
liblambda_la_LIBADD =

# final result
lib_LTLIBRARIES += libcore.la
libcore_la_SOURCES =

libcore_la_LDFLAGS = -release $(PACKAGE_VERSION)

# for convenience libraries, need to tell libtool to build as C++ library
libcore_la_LIBTOOLFLAGS = --tag=CXX
libcore_la_LIBADD =                                             \
	libconcurrent.la					\
	liblambda.la						\
	libmisc.la


bin_PROGRAMS += toy
toy_SOURCES = demo/demo.cpp
toy_CPPFLAGS = $(COMMON_CPPFLAGS)
toy_LDADD = libcore.la

