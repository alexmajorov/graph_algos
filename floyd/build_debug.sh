#!/bin/bash

clang++ -Wall -Werror -Wextra -Wpedantic -Wno-vla-extension -O0 -g --coverage -c main.cpp
clang++ -o app.exe --coverage main.o