#!/bin/bash

mkdir -p lib
mkdir -p bin

if [ ! -d "lib/linenoise" ]; then
    mkdir -p lib/linenoise
    wget https://raw.githubusercontent.com/antirez/linenoise/refs/heads/master/linenoise.c -O ./lib/linenoise/linenoise.c
    wget https://raw.githubusercontent.com/antirez/linenoise/refs/heads/master/linenoise.h -O ./lib/linenoise/linenoise.h
fi

files=(
    "./src/shell.c"
    "./src/loadrc.c"
    "./src/decoratives.c"
    "./src/builtins/builtins.c"
    "./src/builtins/runfile.c"
    "./src/builtins/alias.c"
    "./src/seal/lexer.c"
    "./src/seal/parser.c"
    "./src/seal/seal.c"
    "./lib/linenoise/linenoise.c"
)

gcc "${files[@]}" -o ./bin/seashell

# gcc ./src/shell.c ./src/builtins/builtins.c ./src/builtins/alias.c ./src/decoratives.c ./src/seal/lexer.c ./src/seal/parser.c ./src/seal/seal.c ./lib/linenoise/linenoise.c -o ./bin/seashell
