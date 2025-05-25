//////////////////////////////////////////////////////////////////////////////////////////
//			SNAKES V2.2.0							//
//			By: Hind Biswas Krishna						//
//			https://github.com/hind-sagar-biswas				//
//			https://www.hindbiswas.com					//
//////////////////////////////////////////////////////////////////////////////////////////

// A dynamic snake game written in C using ncurses library.

// OS Requirement: Linux
// Libraries Required: ncurses (sudo apt install libncurses5-dev libncursesw5-dev)
// Build Command: ./build.sh
// Run Command: ./bin/snake


// Check if the OS is Windows
#ifdef _WIN32

#include <stdio.h>
int main() {
	printf("[INFO]    This game is not supported on Windows as it uses the Linux's ncurses library.\n");
	return 0;
}

#else

#include "game.c"

#endif
