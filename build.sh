#!/bin/sh

# Install Google.Test from Github
if [ ! -d googletest ]; then
    echo "Installing googletest.."
    git clone https://github.com/google/googletest.git
fi

mkdir -p build
cd build
cmake .. && make
