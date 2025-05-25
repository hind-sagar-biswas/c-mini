#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#define MAX_NAME_LENGTH 15

#include "enums.h"
#include <time.h>
#include <stdbool.h>

typedef struct Block {
	BlockType type;

	int x;
	int y;

	struct Block* next;

	bool is_hidden;
} Block;

typedef struct {
	char name[MAX_NAME_LENGTH];
	int score;
	time_t timestamp;
} Highscore;

#endif // STRUCTS_H_INCLUDED
