#ifndef MESSAGES_H_INCLUDED
#define MESSAGES_H_INCLUDED

#include <ncurses.h>
#include <unistd.h>

void showTitleMessage(int height, int width);
void showHighscoreMessage(int height, int width, int numHighscores);
void showGameOverMessage(int height, int width, int score);
void sayGoodbye(int height, int width);

#endif // MESSAGES_H_INCLUDED
