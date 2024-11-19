#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "enums.h"

struct Block* getSnake();
enum BlockType checkForCollision();

int* getNextMove();
int* getWindowSize();
int getRandomNumber(int min, int max);
int frame();

void handleExit();
void generateApple();
void gameLoop();
void setupVariables();
void extendSnake();
void freeSnake();
void emptyGrid();
void initialize();
void closeGame();
void showGameOverMessage();
void listenForKeyPresses();
void sayGoodbye();
void moveSnake();

bool startMenu();

#endif // FUNCTIONS_H_INCLUDED
