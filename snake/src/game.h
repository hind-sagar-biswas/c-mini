#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <ncurses.h>
#include <unistd.h>
#include <form.h>

#include "enums.h"
#include "structs.h"

struct Block* getSnake();
BlockType checkForCollision();

char* takeUserInput();

int* getNextMove();
int* getWindowSize();
int getRandomNumber(int min, int max);
int frame();
int compareHighscores(const void* a, const void* b);

void handleExit();
void generateApple();
void generateBanana();
void gameLoop();
void setupVariables();
void extendSnake();
void freeSnake();
void emptyGrid();
void initialize();
void closeGame();
void listenForKeyPresses();
void moveSnake();

void* spawnBanana(void*);
void* despawnBanana(void*);

bool startMenu();

#endif // MAIN_H_INCLUDED
