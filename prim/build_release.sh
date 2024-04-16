#!/bin/bash

clang++ -Wall -Werror -Wpedantic -Wextra -O2 -c main.cpp
clang++ -o app.exe main.o