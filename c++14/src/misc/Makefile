#
# Initiated by Jared on Feb 23, 2017.
#

CXX = g++
CXXFLAGS = -g1 -O0 -Wno-unused-local-typedefs -std=c++14 -fpic -DDEBUG

#INCLUDEDIRS = -I /home/dcos/repo/mesos/build/3rdparty/glog-0.3.3/src \
#        -I/home/dcos/repo/mesos/build/3rdparty/protobuf-2.6.1/src/ \
#        -I/home/dcos/repo/mesos/build/3rdparty/boost-1.53.0/
#        -I/home/dcos/repo/cyrus-sasl/include

#LDFLAGS = -fPIC -DPIC -shared -lmesos -lrestclient-cpp -lsasl2

OBJS = misc.o test.o

%.o:%.cpp
	$(CXX)  $(CXXFLAGS)     $(INCLUDEDIRS)  -c      $<      -o      $@

all:$(OBJS)
	$(CXX)	$(LDFLAGS)	-o	test	$(OBJS)
	./test
.PHONY:clean
clean:
	rm	-rf	*.o	test

