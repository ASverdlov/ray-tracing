#!/bin/sh

PROJECT_ROOT="$(dirname $0)/.."
cd $PROJECT_ROOT

wget https://cmake.org/files/v3.7/cmake-3.7.0-rc1.tar.gz && \
gzip -d cmake-3.7.0-rc1.tar.gz && \
tar -xf cmake-3.7.0-rc1.tar && \
mv cmake* cmake && \
cd cmake && \
./bootstrap && make && sudo make install
