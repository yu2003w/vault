#
# Initiated by Jared on Feb 23, 2017.
#

CXX = g++
CXXFLAGS = -g1 -O0 -Wno-unused-local-typedefs -std=c++14 -fpic -DDEBUG -pthread

INCLUDEDIRS = -I ../ 

LDFLAGS = -fPIC -DPIC -pthread
#LDFLAGS = -fPIC -DPIC -shared -lmesos -lrestclient-cpp -lsasl2

OBJS = test.o ../concurrent/basic.o

%.o:%.cpp
	$(CXX)  $(CXXFLAGS)     $(INCLUDEDIRS)  -c      $<      -o      $@

all:$(OBJS)
	$(CXX)	$(LDFLAGS)	-o	test	$(OBJS)	
	./test
.PHONY:clean
clean:
	rm	-rf	*.o	test

