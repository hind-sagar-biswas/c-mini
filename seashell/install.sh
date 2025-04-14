#!/bin/bash

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
    "./src/seal/mathexp.c"
    "./src/seal/seal.c"
    "./lib/linenoise/linenoise.c"
)
linkers=(
    "-lm"
)

mkdir -p lib
mkdir -p bin

if [ ! -d "lib/linenoise" ]; then
    echo "Downloading linenoise..."
    mkdir -p lib/linenoise
    wget https://raw.githubusercontent.com/antirez/linenoise/refs/heads/master/linenoise.c -O ./lib/linenoise/linenoise.c
    wget https://raw.githubusercontent.com/antirez/linenoise/refs/heads/master/linenoise.h -O ./lib/linenoise/linenoise.h
fi

echo "Building $name..."
gcc "${files[@]}" "${linkers[@]}" -o ./bin/$name

echo "Making $name executable..."
chmod +x ./bin/$name
echo "Installed into ./bin as $name"

echo ""
./bin/$name --version

if [[ $* == *--run* ]]; then
    echo "Running seashell..."
    ./bin/$name
else
    echo "To run seashell, use ./bin/$name"
    echo "To uninstall, delete the ./bin directory"
    echo "To run seashell with a specific rc file, use ./bin/$name --rc <file>"
    echo "To see help, use ./bin/$name --help or ./bin/$name -h"
fi
