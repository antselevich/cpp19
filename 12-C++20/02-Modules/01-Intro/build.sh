#!/bin/bash

export new_gcc=~/gcc-modules/bin/g++ 
$new_gcc -fmodules-ts -x c++ -c speech.cppm
$new_gcc -fmodules-ts -fmodule-header -x c++ -c main.cpp
$new_gcc -o prog main.o speech.o
./prog