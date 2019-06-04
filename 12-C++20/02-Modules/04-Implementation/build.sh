#!/bin/bash

export new_gcc=g++
$new_gcc -fmodules-ts -x c++ -o impl.gcm -c impl.cppm
$new_gcc -fmodules-ts -x c++ -o impl_bar.gcm -c impl_bar.cppm
$new_gcc -fmodules-ts -x c++ -o impl_foo.gcm -c impl_foo.cppm
$new_gcc -fmodules-ts -fmodule-header -x c++ -o main.o -c main.cpp
$new_gcc -fmodules-ts -o prog impl.gcm impl_foo.gcm impl_bar.gcm main.o
./prog