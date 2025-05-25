#include "highscore.h"
#include "messages.h"


Highscore highscores[MAX_HIGHSCORES];

// Load highscores from file
void loadHighscores(int* numHighscores) {
    FILE* fp = fopen(HIGHSCORE_FILE, "r");
    if (!fp) return;  // No file exists yet
    *numHighscores = 0;
    while (*numHighscores < MAX_HIGHSCORES &&
        fscanf(fp, "%49s %d %ld", highscores[*numHighscores].name,
            &highscores[*numHighscores].score,
            &highscores[*numHighscores].timestamp) == 3) {
        (*numHighscores)++;
    }
    fclose(fp);
}

// Save highscores to file
void saveHighscores(int numHighscores) {
    FILE* fp = fopen(HIGHSCORE_FILE, "w");
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
int compareHighscores(const void* a, const void* b) {
    Highscore* hs1 = (Highscore*)a;
    Highscore* hs2 = (Highscore*)b;
    return hs2->score - hs1->score;
}

// Add a new highscore record if it qualifies
void addHighscore(int score, const char* name, int numHighscores) {
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
    saveHighscores(numHighscores);
}


void showHighscores(int height, int width, int numHighscores) {
        showHighscoreMessage(height, width, numHighscores);

	int y = (height / 2) - 6 - numHighscores / 2;
	int x = (width / 2) - (58 / 2);

	attron(A_STANDOUT);
	mvprintw(y + 8, x, "                                                          ");
	char timeStr[26];
	for (int i = 0; i < numHighscores; i++) {
		ctime_r(&highscores[i].timestamp, timeStr);
		timeStr[strcspn(timeStr, "\n")] = '\0';  // Remove newline
		mvprintw(y + i + 9, x, " %02d. %-*s : %03d pts [%s] ", i + 1, MAX_NAME_LENGTH, highscores[i].name, highscores[i].score, timeStr);
	}
	mvprintw(y + 9 + numHighscores, x, "                                                          ");
	attroff(A_STANDOUT);

	refresh();
	usleep(5000000);
}

int getLastHighscore(int numHighscores) {
    return highscores[numHighscores - 1].score;
}
