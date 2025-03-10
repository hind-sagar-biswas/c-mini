#ifndef ENUMS_H_INCLUDED
#define ENUMS_H_INCLUDED

typedef enum {
	EMPTY = 0,
	APPLE = 1,
	SNAKE = 2,
	WALL = 3,
} BlockType;

typedef enum {
	UP,
	DOWN,
	LEFT,
	RIGHT
} Direction;

#endif // ENUMS_H_INCLUDED
