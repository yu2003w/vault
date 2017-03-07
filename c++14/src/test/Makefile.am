#
# Initiated by Jared on March 07, 2017.
#

bin_PROGRAMS = cplus
cplus_SOURCES = test.cpp
AM_CPPFLAGS = -I $(top_srcdir)/src/

AM_CXXFLAGS = $(PTHREAD_CFLAGS)

cplus_LDADD = ../concurrent/libconcurrent.a \
              ../lambda/liblambda.a \
              ../misc/libmisc.a

