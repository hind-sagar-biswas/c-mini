#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HIGHSCORES 5
#define HIGHSCORE_FILE "highscores.txt"
int numHighscores = 0;

Highscore highscores[MAX_HIGHSCORES];

// Load highscores from file
void loadHighscores() {
    FILE *fp = fopen(HIGHSCORE_FILE, "r");
    if (!fp) return;  // No file exists yet
    numHighscores = 0;
    while (numHighscores < MAX_HIGHSCORES &&
           fscanf(fp, "%49s %d %ld", highscores[numHighscores].name,
                  &highscores[numHighscores].score,
                  &highscores[numHighscores].timestamp) == 3) {
        numHighscores++;
    }
    fclose(fp);
}

// Save highscores to file
void saveHighscores() {
    FILE *fp = fopen(HIGHSCORE_FILE, "w");
    if (!fp) {
        fprintf(stderr, "Error opening highscores file for writing.\n");
        return;
    }
    for (int i = 0; i < numHighscores; i++) {
        fprintf(fp, "%s %d %ld\n", highscores[i].name,
                highscores[i].score,
                highscores[i].timestamp);
    }
    fclose(fp);
}

// Comparison function for qsort: sort in descending order by score.
int compareHighscores(const void *a, const void *b) {
    Highscore *hs1 = (Highscore *)a;
    Highscore *hs2 = (Highscore *)b;
    return hs2->score - hs1->score;
}

// Add a new highscore record if it qualifies
void addHighscore(int score, const char *name) {
    Highscore newScore;
    strncpy(newScore.name, name, MAX_NAME_LENGTH - 1);
    newScore.name[MAX_NAME_LENGTH - 1] = '\0';
    newScore.score = score;
    newScore.timestamp = time(NULL);

    // If we have fewer than MAX_HIGHSCORES, add the new record.
    if (numHighscores < MAX_HIGHSCORES) {
        highscores[numHighscores++] = newScore;
    }
    // Otherwise, if the new score is higher than the lowest highscore...
    else if (score > highscores[numHighscores - 1].score) {
        highscores[numHighscores - 1] = newScore;
    }

    // Sort the array in descending order by score.
    qsort(highscores, numHighscores, sizeof(Highscore), compareHighscores);
    saveHighscores();
}
