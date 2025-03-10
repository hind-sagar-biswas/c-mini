#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "enums.h"

struct Block* getSnake();
BlockType checkForCollision();

char* takeUserInput();

int* getNextMove();
int* getWindowSize();
int getRandomNumber(int min, int max);
int frame();
int compareHighscores(const void *a, const void *b);

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

void showHighscores();
void loadHighscores();
void saveHighscores();
void addHighscore(int score, const char *name);

bool startMenu();

#endif // FUNCTIONS_H_INCLUDED
