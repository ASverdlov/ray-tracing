#!/bin/sh

# Install googletest from github, if it doesn't exist
if [ ! -d googletest ]; then
    echo "Installing googletest.."
    git clone https://github.com/google/googletest.git
fi

mkdir -p build
cd build
cmake .. || exit 0
make
