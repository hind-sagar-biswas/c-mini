#!/bin/bash

mkdir -p lib
mkdir -p bin

if [ ! -d "lib/linenoise" ]; then
    mkdir -p lib/linenoise
    wget https://raw.githubusercontent.com/antirez/linenoise/refs/heads/master/linenoise.c -O ./lib/linenoise/linenoise.c
    wget https://raw.githubusercontent.com/antirez/linenoise/refs/heads/master/linenoise.h -O ./lib/linenoise/linenoise.h
fi

# name of output file
name="seashell"

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

gcc "${files[@]}" -o ./bin/$name

chmod +x ./bin/$name

echo "Installed seashell to ./bin/ as $name"

if [[ $* == *--run* ]]; then
    echo "Running seashell..."
    ./bin/$name
fi
