# dockerfile for building snort3
FROM ubuntu:22.04
# install dependencies
RUN apt update && apt-get install -y cmake gcc g++ git autoconf libtool pkg-config check flex \
    libssl-dev libpcap-dev libpcre++-dev zlib1g-dev liblzma-dev iproute2 wget curl iputils-ping && \
    unminimize
ENV proxy="127.0.0.1:7890"
# build libdaq
RUN mkdir /home/package && git config --global http.proxy $proxy
RUN cd /home/package && git clone https://github.com/snort3/libdaq.git \
    && cd libdaq && git checkout -l v3.0.13 && ./bootstrap && ./configure && make && make install
    
# build libdnet
RUN cd /home/package && git clone https://github.com/ofalk/libdnet.git \
    && cd libdnet && ./configure && make && make install

# build hwloc
RUN cd /home/package && git clone https://github.com/open-mpi/hwloc.git \
    && cd hwloc && ./autogen.sh && ./configure && make && make install

# build luajit
RUN cd /home/package && git clone https://luajit.org/git/luajit.git \
    && cd luajit && make && make install

WORKDIR /home/repo
# build snort3 with master branch
RUN git clone https://github.com/snort3/snort3.git && cd snort3 && \
    export my_path=$(pwd)/snort3_install/ && ./configure_cmake.sh --prefix=$my_path && cd build && \
    make -j 2 install && ldconfig

COPY snort_test.sh /home/repo
