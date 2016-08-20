#!/bin/sh

PROJECT_ROOT="$(dirname $0)/.."
cd $PROJECT_ROOT

mkdir -p build
cd build
cmake .. && make
