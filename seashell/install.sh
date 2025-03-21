#!/bin/bash

mkdir -p lib
mkdir -p bin

if [ ! -d "lib/linenoise" ]; then
    mkdir -p lib/linenoise
    wget https://raw.githubusercontent.com/antirez/linenoise/refs/heads/master/linenoise.c -O ./lib/linenoise/linenoise.c
    wget https://raw.githubusercontent.com/antirez/linenoise/refs/heads/master/linenoise.h -O ./lib/linenoise/linenoise.h
fi

gcc ./src/shell.c ./src/builtins.c ./src/decoratives.c ./lib/linenoise/linenoise.c -o ./bin/seashell
