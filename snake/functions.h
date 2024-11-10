#pragma once

#include "enums.h"
int* getWindowSize();
struct Block* getSnake();
enum BlockType checkForCollision();
void generateApple();
int getRandomNumber(int min, int max);
int frame();
void gameLoop();
void setupVariables();
void extendSnake();
void freeSnake();
void emptyGrid();
void initialize();
void closeGame();
void showGameOverMessage();
void listenForKeyPresses();
int* getNextMove();
void moveSnake();
