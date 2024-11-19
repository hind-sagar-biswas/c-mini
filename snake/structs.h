#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include "enums.h"

struct Block {
	enum BlockType type;

	int x;
	int y;

	struct Block *next;
};

#endif // STRUCTS_H_INCLUDED
