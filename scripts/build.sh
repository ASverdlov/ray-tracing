#!/bin/sh

PROJECT_ROOT="$(dirname $0)/.."
cd $PROJECT_ROOT

mkdir -p build
cd build

CMAKE_FLAGS=""
if [ "$1" == "-g" ]
then
  CMAKE_FLAGS="-DCMAKE_BUILD_TYPE=Debug"
fi
cmake "${CMAKE_FLAGS}" ..  && make
