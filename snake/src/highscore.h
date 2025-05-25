#ifndef HIGHSCORE_H_INCLUDED
#define HIGHSCORE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>

#include "structs.h"

#define MAX_HIGHSCORES 5
#define HIGHSCORE_FILE "highscores.txt"

void loadHighscores(int* highscores);
void saveHighscores(int highscores);
void showHighscores(int height, int width, int highscores);
void addHighscore(int score, const char* name, int highscores);

int getLastHighscore(int numHighscores);
int compareHighscores(const void* a, const void* b);

#endif // HIGHSCORE_H_INCLUDED
