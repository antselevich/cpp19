#!/bin/bash

export new_gcc=g++
$new_gcc -fmodules-ts -x c++ -o speech_english.gcm.o -c speech_english.cppm
$new_gcc -fmodules-ts -x c++ -o speech_russian.gcm.o -c speech_russian.cppm
$new_gcc -fmodules-ts -x c++ -o speech.gcm.o -c speech.cppm
$new_gcc -fmodules-ts -fmodule-header -x c++ -o main.o -c main.cpp
$new_gcc -o prog main.o speech.gcm.o speech_english.gcm.o speech_russian.gcm.o
./prog
rm prog *.o *.gcm