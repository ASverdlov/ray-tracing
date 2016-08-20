#!/bin/sh
if [ ! -f cpplint.py ]; then
  echo 'Downloading cpplint ...'
  URL='https://raw.githubusercontent.com/google/styleguide/gh-pages/cpplint/cpplint.py'
  curl $URL > cpplint.py 2>/dev/null
fi

FILES=$(find src include \( -name \*.hpp -o -name \*.cc \) -print | tr '\n' ' ')
python cpplint.py --filter=-legal/copyright --extensions=hpp,cc $FILES 
