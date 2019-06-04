#!/bin/bash

export new_gcc=~/gcc-modules/bin/g++
$new_gcc -fmodules-ts -x c++ -o speech.gcm.o -c speech.cppm
$new_gcc -fmodules-ts -x c++ -o speech_impl.gcm.o -c speech_impl.cppm
$new_gcc -fmodules-ts -fmodule-header -x c++ -o main.o -c main.cpp
$new_gcc -fmodules-ts -o prog speech.gcm.o speech_impl.gcm.o main.o
./prog