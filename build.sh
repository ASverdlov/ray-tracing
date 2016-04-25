#!/bin/sh
mkdir -p build
cd build
cmake .. || exit 0
make
