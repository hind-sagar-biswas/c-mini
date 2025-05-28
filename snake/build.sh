#!/usr/bin/env bash

name="snake"
files=(
	"./src/main.c"
	"./src/messages.c"
	"./src/highscore.c"
	"./src/log.c"
)
linkers=(
	"-lncursesw"
	"-lform"
	"-lpthread"
)
required_packages=(libncurses-dev)


check_and_install_dependencies() {
    echo "[INFO] Checking required packages..."

    missing_packages=()
    for pkg in "${required_packages[@]}"; do
        if dpkg -s "$pkg" &>/dev/null; then
            echo "[OKAY] $pkg is already installed."
        else
            echo "[WARN] $pkg is missing."
            missing_packages+=("$pkg")
        fi
    done

    if (( ${#missing_packages[@]} > 0 )); then
        echo "[INFO] Installing missing packages (requires sudo)..."
        sudo apt update
        sudo apt install -y "${missing_packages[@]}"
    else
        echo "[OKAY] All required packages are installed."
    fi
}

check_and_install_dependencies
mkdir -p bin

echo "[INFO] Building $name..."
gcc "${files[@]}" "${linkers[@]}" -o ./bin/$name
echo "[OKAY] Build complete!"

echo "[INFO] Making $name executable..."
chmod +x ./bin/$name
echo "[OKAY] Installed into ./bin as $name!"

if [[ $* == *--run* ]]; then
    echo "[INFO] Running Snake Game..."
    ./bin/$name
fi
