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

#libconcurrent_a_SOURCES = basic.cpp
#AM_CPPFLAGS = -I $(top_srcdir)/src/concurrent/

# link only needed libraries
AM_LDFLAGS += -Wl,--as-needed

# enable multiple-thread support
AM_CXXFLAGS = $(PTHREAD_CFLAGS)

AM_CXXFLAGS += -Wall -Wsign-compare -Wformat-security -fPIC -fPIE


# PTHREAD_LIBS and PTHREAD_CFLAGS are defined in m4/ax_pthread.m4
AM_LIBS = $(PTHREAD_LIBS)

# final result
lib_LTLIBRARIES += libcore.la

noinst_LTLIBRARIES += libconcurrent.la
noinst_LTLIBRARIES += libmisc.la
noinst_LTLIBRARIES += liblambda.la

