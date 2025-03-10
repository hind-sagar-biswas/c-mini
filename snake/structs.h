#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#define MAX_NAME_LENGTH 50

#include <time.h>
#include "enums.h"

typedef struct Block {
	BlockType type;

	int x;
	int y;

	struct Block *next;
} Block;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
    time_t timestamp;
} Highscore;

#endif // STRUCTS_H_INCLUDED
