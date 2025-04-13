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
    "./src/seal/seal.c"
    "./lib/linenoise/linenoise.c"
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
gcc "${files[@]}" -o ./bin/$name

echo "Making $name executable..."
chmod +x ./bin/$name

./bin/$name --version
echo "Installed into ./bin as $name"

if [[ $* == *--run* ]]; then
    echo "Running seashell..."
    ./bin/$name
else
    echo "To run seashell, use ./bin/$name"
    echo "To uninstall, delete the ./bin directory"
    echo "To run seashell with a specific rc file, use ./bin/$name --rc <file>"
fi
