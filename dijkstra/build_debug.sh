#!/bin/bash

clang++ -Wall -Werror -Wextra -Wpedantic -O0 -g --coverage -c main.cpp
clang++ -o app.exe --coverage main.o