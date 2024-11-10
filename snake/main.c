#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

#include "enums.h"
#include "structs.h"
#include "functions.h"

/*#include "log.c"*/

// Global Variables
int width;
int height;
int score = 0;
enum BlockType *grid;
struct Block* snake;
struct Block* snakeHead;
struct Block apple = {APPLE, 10, 10, NULL};
enum Direction direction = RIGHT;
bool running = true;

int main() {
	initialize();
	gameLoop();

	printf("Game Over. You scored: %d points.\n", score);
	return 0;
}

// Function Definitions

void initialize() {
	srand(time(NULL));	// Seed the random number generator
	setupVariables();	// Initialize global variables
	initscr();              // Initialize the ncurses screen
	noecho();               // Don't echo input to the screen
	cbreak();               // Disable line buffering, pass key presses directly
	keypad(stdscr, TRUE);   // Enable reading arrow keys
	nodelay(stdscr, TRUE);  // Make getch() non-blocking
	curs_set(0);            // Hide the cursor
	
	start_color();				// Enable color
	init_pair(1, COLOR_BLACK, COLOR_RED);	// Set color pair for apple
	init_pair(2, COLOR_BLACK, COLOR_GREEN);	// Set color pair for snake
}

void setupVariables() {
	int *wsize = getWindowSize();
	width = wsize[0];
	height = wsize[1] - 2;

	grid = malloc(width * height * sizeof(enum BlockType));
	for (int i = 0; i < width * height; i++) {
		grid[i] = EMPTY;
	}
	
	snake = getSnake();

	generateApple();

}

void closeGame() {
	running = false;
	freeSnake();
	free(grid);
	endwin();  // Close the ncurses window
}

void gameLoop() {
	while (running) {
		int result = frame();
		if (result == -1) {
			closeGame();
		} else if (result != 0) {
			score += result;
		}
	}
}

int frame() {
	int frameScore = 0;

	clear();
	emptyGrid();

	listenForKeyPresses();

	attron(COLOR_PAIR(1));
	mvprintw(apple.y, apple.x, " ");
	grid[apple.y * width + apple.x] = APPLE;

	struct Block* current = snake;
	while (current != NULL) {
		attron(COLOR_PAIR(2));
		mvprintw(current->y, current->x, " ");
		grid[current->y * width + current->x] = SNAKE;
		current = current->next;
	}

	enum BlockType block = checkForCollision();

	switch (block) {
		case EMPTY:
			moveSnake();
			break;
		case APPLE:
			extendSnake();
			generateApple();
			frameScore = (int) block;
			break;
		default:
			showGameOverMessage();
			frameScore = -1;
			break;
	}

	attron(COLOR_PAIR(2));
	mvprintw(height + 1, 0, "q: quit; Score: %d", score);

        refresh();
        usleep(100000);  // Sleep for 1 s
	

	if (frameScore < 0) {
		usleep(5000000);
	}
	
	return frameScore;
}

void listenForKeyPresses() {
	int ch = getch();
        switch (ch) {
            case KEY_UP:
		if (direction != DOWN) {	
			direction = UP;
		}
                break;
	    case KEY_DOWN:
		if (direction != UP) {
			direction = DOWN;
		}
		break;
	    case KEY_LEFT:
		if (direction != RIGHT) {
			direction = LEFT;
		}
		break;
	    case KEY_RIGHT:
		if (direction != LEFT) {
			direction = RIGHT;
		}
		break;
            case 'q':  // Quit game if 'q' is pressed
                closeGame();
                return;
        }
}

void showGameOverMessage() {
	attron(COLOR_PAIR(1));
	mvprintw(height / 2, width / 2 - 8, "Game Over!");
	mvprintw(height / 2 + 1, width / 2 - 8, "Score: %d", score);
}

int* getNextMove() {
	int* move = malloc(2 * sizeof(int));
	move[0] = snakeHead->x;
	move[1] = snakeHead->y;
	switch (direction) {
		case UP:
			if (snakeHead->y > 0) move[1] -= 1;
			else move[1] = height;
			break;
		case DOWN:
			if (snakeHead->y < height) move[1] += 1;
			else move[1] = 0;
			break;
		case LEFT:
			if (snakeHead->x > 0) move[0] -= 1;
			else move[0] = width;
			break;
		case RIGHT:
			if (snakeHead->x < width) move[0] += 1;
			else move[0] = 0;
			break;
		default:
			break;
	}

	return move;
}

void moveSnake() {
	struct Block* current = snake;
	struct Block* next = current->next;
	while (next != NULL) {
		current->x = next->x;
		current->y = next->y;
		current = next;
		next = current->next;
	}
	
	int* move = getNextMove();
	current->x = move[0];
	current->y = move[1];
	free(move);

}

void extendSnake() {
	struct Block* newHead = (struct Block*) malloc(sizeof(struct Block));
	newHead->type = SNAKE;

	int* move = getNextMove();
	newHead->x = move[0];
	newHead->y = move[1];
	free(move);

	newHead->next = NULL;

	snakeHead->next = newHead;
	snakeHead = newHead;

}

int* getWindowSize() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	int *wsize = malloc(2 * sizeof(int));
	wsize[0] = w.ws_col;
	wsize[1] = w.ws_row;
	return wsize;
}

enum BlockType checkForCollision() {
	int* move = getNextMove();
	int x = move[0];
	int y = move[1];
	free(move);
	return grid[y * width + x];
}

struct Block* getSnake() {
	struct Block* head = (struct Block*) malloc(sizeof(struct Block));
	head->type = SNAKE;
	head->x = 3;
	head->y = 1;

	struct Block* body = (struct Block*) malloc(sizeof(struct Block));
	body->type = SNAKE;
	body->x = 2;
	body->y = 1;

	struct Block* tail = (struct Block*) malloc(sizeof(struct Block));
	tail->type = SNAKE;
	tail->x = 1;
	tail->y = 1;

	head->next = NULL;
	body->next = head;
	tail->next = body;

	snakeHead = head;
	return tail;
}

void generateApple() {
	apple.x = getRandomNumber(0, width - 1);
	apple.y = getRandomNumber(0, height - 1);
}

int getRandomNumber(int min, int max) {
	return min + rand() % (max - min + 1);
}

void emptyGrid() {
	for (int i = 0; i < width * height; i++) {
		grid[i] = EMPTY;
	}
}

void freeSnake() {
	struct Block* current = snake;
	while (current != NULL) {
		struct Block* next = current->next;
		free(current);
		current = next;
	}
}
