#!/bin/bash

if [[ "$#" == "1" ]]; then
  clang++ -std=c++20 $1 util.cpp -o /tmp/a.out && echo "Done compiling" && /tmp/a.out
else
  echo "Gib missing filename"
fi
