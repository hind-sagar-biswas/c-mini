#!/usr/bin/env bash

name="snake"
files=(
	"./src/main.c"
	"./src/messages.c"
	"./src/highscore.c"
	"./src/log.c"
)
linkers=(
	"-lncurses"
	"-lform"
	"-lpthread"
)

mkdir -p bin

echo "[INFO]    Building $name..."
gcc "${files[@]}" "${linkers[@]}" -o ./bin/$name
echo "[INFO]    Build complete!"

echo "[INFO]    Making $name executable..."
chmod +x ./bin/$name
echo "[INFO]    Installed into ./bin as $name!"

if [[ $* == *--run* ]]; then
    echo "[INFO]    Running Snake Game..."
    ./bin/$name
fi
