#!/bin/bash

cmake -H. -Bbuild
cd build
cmake --build .
ctest -V