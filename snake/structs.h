#pragma once

#include "enums.h"

struct Block {
	enum BlockType type;

	int x;
	int y;

	struct Block *next;
};
