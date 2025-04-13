//////////////////////////////////////////////////////////////////////////////////////////
//			SNAKES V2.0							//
//			By: Hind Biswas							//
//			https://github.com/hind-sagar-biswas				//
//			https://www.hindbiswas.com					//
//////////////////////////////////////////////////////////////////////////////////////////

// A dynamic snake game written in C using ncurses library.

// OS Requirement: Linux
// Libraries Required: ncurses (sudo apt install libncurses5-dev libncursesw5-dev)
// Build Command: gcc main.c -o snake -lncurses
// Run Command: ./snake


// Includes
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <form.h>

#include "enums.h"
#include "structs.h"
#include "functions.h"

#include "Highscore.c"
#include "Log.c"

// Global Variables
int width;
int height;
int score = 0;

BlockType *grid;
Direction direction = RIGHT;

Block* snake;
Block* snakeHead;
Block apple = {APPLE, 10, 10, NULL};

FIELD *field[2];
FORM *my_form;

bool running = true;
bool paused = false;

int main() {
	atexit(handleExit);  // Register cleanup function
	initialize();

	bool choice = startMenu();

	if (choice) gameLoop();
	else closeGame();

	printf("Game Over. You scored: %d points.\n", score);
	return 0;
}

// Function Definitions

void initialize() {
	srand(time(NULL));		// Seed the random number generator
	setupVariables();		// Initialize global variables
	loadHighscores();		// Load highscores
	initscr();			// Initialize the ncurses screen
	noecho();			// Don't echo input to the screen
	cbreak();			// Disable line buffering, pass key presses directly
	keypad(stdscr, TRUE);		// Enable reading arrow keys
	nodelay(stdscr, TRUE);		// Make getch() non-blocking
	curs_set(0);			// Hide the cursor

	if (has_colors()) {
		start_color();				// Enable color
		init_pair(1, COLOR_BLACK, COLOR_RED);	// Set color pair for apple
		init_pair(2, COLOR_BLACK, COLOR_GREEN);	// Set color pair for snake
	}
}

char* takeUserName() {
	erase();
	int ch;
	char prompt[] = "Congratulations! You got into the ranking. Please enter your name:";
	char instruction[] = "Press DOWN ARROW to submit your name.";
	
	// Create a field with 1 row and 20 columns at row 4, col 10
	field[0] = new_field(1, MAX_NAME_LENGTH, height / 2 + 1, width / 2 - MAX_NAME_LENGTH / 2 - 1, 0, 0);
	field[1] = NULL;  // End of fields

	// Set field options and appearance
	set_field_back(field[0], A_UNDERLINE);
	field_opts_off(field[0], O_AUTOSKIP);

	// Create the form and post it
	my_form = new_form(field);
	post_form(my_form);
	mvprintw(height / 2 - 1, width / 2 - strlen(prompt) / 2, "%s", prompt);
	mvprintw(height / 2 + 3, width / 2 - strlen(instruction) / 2, "%s", instruction);
	refresh();

	// Loop to process user input until F1 is pressed
	while ((ch = getch()) != KEY_DOWN) {
		switch(ch) {
			case KEY_BACKSPACE:
			case 127:
				form_driver(my_form, REQ_DEL_PREV);
				break;
			case KEY_LEFT:
				form_driver(my_form, REQ_PREV_CHAR);
				break;
			case KEY_RIGHT:
				form_driver(my_form, REQ_NEXT_CHAR);
				break;
			default:
				form_driver(my_form, ch);
				break;
		}
		refresh();
	}
	
	// Commit the input by moving out and back into the field
	form_driver(my_form, REQ_NEXT_FIELD);
	form_driver(my_form, REQ_PREV_FIELD);
	
	// Retrieve the input from the field
	char *raw_input = field_buffer(field[0], 0);
	// Trim trailing whitespace
	char *end = raw_input + strlen(raw_input) - 1;
	while(end > raw_input && (*end == ' ' || *end == '\t')) {
	    *end = '\0';
	    end--;
	}
	return raw_input;
}

bool startMenu() {
	char menuItems[2][13] = {" Start Game \0", "    Quit    \0"};
	int ch, i = 0;
	int y = (height / 2) - 6;
	int x = (width / 2) - 6;

	char intro[6][31] ={
		"   _____             _        ",
		"  / ____|           | |       ",
		" | (___  _ __   __ _| | _____ ",
		"  \\___ \\| '_ \\ / _` | |/ / _ \\",
		"  ____) | | | | (_| |   <  __/",
		" |_____/|_| |_|\\__,_|_|\\_\\___|",
	};

	for (int j = 0; j < 6; j++) {
		int x = (width / 2) - 16;
		mvprintw(y+j, x, "%s", intro[j]);
	}

	y += 6;

	for( i=0; i<2; i++ ) {
		if( i == 0 ) attron(A_STANDOUT); // highlights the first item.
		else attroff(A_STANDOUT);
		mvprintw( y+i+1, x, "%s", menuItems[i] );
	}
	refresh();
	i = 0;

	while(( ch = getch()) != 'q'){
		mvprintw( y+i+1, x, "%s", menuItems[i] );
		switch( ch ) {
			case KEY_UP:
				i--;
				i = ( i<0 ) ? 1 : i;
				break;
			case KEY_DOWN:
				i++;
				i = ( i>1 ) ? 0 : i;
				break;
			case KEY_RIGHT:
				return !(i);
				break;;
			default:
				break;
		}
		attron(A_STANDOUT);
		mvprintw( y+i+1, x, "%s", menuItems[i]);
		attroff(A_STANDOUT);
	}

	return (i);
}

void setupVariables() {
	int *wsize = getWindowSize();
	width = wsize[0];
	height = wsize[1] - 2;

	grid = malloc(width * height * sizeof(BlockType));
	for (int i = 0; i < width * height; i++) {
		grid[i] = EMPTY;
	}

	snake = getSnake();

	generateApple();
}

void closeGame() {
	if (running) {
		running = false;

		if (numHighscores < MAX_HIGHSCORES || score > highscores[numHighscores - 1].score) {	
			char *name = takeUserName();
			addHighscore(score, name);
		}
		showHighscores();

		sayGoodbye();
		freeSnake();

		unpost_form(my_form);
		free_form(my_form);
		free_field(field[0]);
		free(grid);
		endwin();  // Close the ncurses window
		exit(0);
	}
}

void sayGoodbye() {
	clear();

	int y = (height / 2) - 4;
	int x = (width / 2) - 23;

	char message[8][45] = {
		" _____                 _  ______            ",
		"|  __ \\               | | | ___ \\           ",
		"| |  \\/ ___   ___   __| | | |_/ /_   _  ___ ",
		"| | __ / _ \\ / _ \\ / _` | | ___ \\ | | |/ _ \\",
		"| |_\\ \\ (_) | (_) | (_| | | |_/ / |_| |  __/",
		" \\____/\\___/ \\___/ \\__,_| \\____/ \\__, |\\___|",
		"                                  __/ |     ",
		"                                 |___/      ",
	};

	for (int j = 0; j < 8; j++) {
		mvprintw(y+j, x, "%s", message[j]);
	}

	refresh();
	usleep(1500000); // 1.5 seconds
}

void gameLoop() {
	while (running) {
		int result = frame();
		if (result == -1 && running) {
			closeGame();
		} else if (result != 0) {
			score += result;
		}
	}
}

int frame() {
    int frameScore = 0;  // Tracks score changes in this frame -> 0: No change; 1: Eat apple; -1: Game over


    listenForKeyPresses();  // Handle user input for direction changes

    if (!paused) {
	erase();  // Clear the screen for rendering the next frame
	emptyGrid();  // Reset the grid
	// Draw the apple
	attron(COLOR_PAIR(1));  // Apply apple color
	mvprintw(apple.y, apple.x, " ");
	attroff(COLOR_PAIR(1));

	// Mark the apple position on the grid
	grid[apple.y * width + apple.x] = APPLE;

	// Draw the snake
	Block* current = snake;
	while (current) {
	attron(COLOR_PAIR(2));  // Apply snake color
	if (current == snakeHead) {
	    mvprintw(current->y, current->x, "O");  // Draw the head
	} else {
	    mvprintw(current->y, current->x, " ");
	}
	attroff(COLOR_PAIR(2));

	// Mark the snake position on the grid
	grid[current->y * width + current->x] = SNAKE;

	current = current->next;
	}

	// Check for collisions and handle accordingly
	BlockType block = checkForCollision();
	switch (block) {
	case EMPTY:
	    moveSnake();  // Continue moving
	    break;
	case APPLE:
	    extendSnake();  // Grow the snake
	    generateApple();  // Spawn a new apple
	    frameScore = 1;  // Increase the score
	    break;
	default:  // Collision with the snake itself or a wall
	    showGameOverMessage();  // Display game-over screen
	    frameScore = -1;
	    break;
	}

	// Display the current score
	attron(COLOR_PAIR(2));
	mvprintw(height + 1, 0, "q: quit; p: pause/resume; Score: %d", score);
	attroff(COLOR_PAIR(2));

	wnoutrefresh(stdscr);
	doupdate();  // Render the updated frame
    }
    usleep(100000);  // Delay for smooth game speed

    // Pause briefly on game-over
    if (frameScore < 0) {
        usleep(1500000);
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
	    case 'p':  // Pause game if 'p' is pressed else unpause
		paused = !paused;
		break;
            case 'q':  // Quit game if 'q' is pressed
                closeGame();
                return;
        }
}

void showHighscores() {
	int y = (height / 2) - 6 - numHighscores / 2;
	int x = width / 2 - 49 / 2;
	char message[6][49] = {
		"    __  ___       __                            ",
		"   / / / (_)___ _/ /_  ______________  ________ ",
		"  / /_/ / / __ `/ __ \\/ ___/ ___/ __ \\/ ___/ _ \\",
		" / __  / / /_/ / / / (__  ) /__/ /_/ / /  /  __/",
		"/_/ /_/_/\\__, /_/ /_/____/\\___/\\____/_/   \\___/ ",
		"        /____/                                  ",
	};

	erase();

	for (int j = 0; j < 6; j++) {
		mvprintw(y+j, x, "%s", message[j]);
	}

	attron(A_STANDOUT);
	x = (width / 2) - (58 / 2);
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


void showGameOverMessage() {
	int y = (height / 2) - 4;
	int x = (width / 2) - 57 / 2;

	char message[6][57] = {
		"   _____                         ____                 _ ",
		"  / ____|                       / __ \\               | |",
		" | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __| |",
		" | | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__| |",
		" | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |  |_|",
		"  \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|  (_)",
	};

	attron(COLOR_PAIR(1));

	for (int j = 0; j < 6; j++) {
		mvprintw(y+j, x, "%s", message[j]);
	}

	mvprintw(y + 8, x, "SCORE:  %d", score);

	attroff(COLOR_PAIR(1));
}


int* getNextMove() {
    int* move = malloc(2 * sizeof(int));
    move[0] = snakeHead->x;
    move[1] = snakeHead->y;
    switch (direction) {
        case UP:
            if (snakeHead->y > 0)
                move[1] -= 1;
            else
                move[1] = height - 1;
            break;
        case DOWN:
            if (snakeHead->y < height - 1)  // Fix: use height - 1 here
                move[1] += 1;
            else
                move[1] = 0;
            break;
        case LEFT:
            if (snakeHead->x > 0)
                move[0] -= 1;
            else
                move[0] = width - 1;
            break;
        case RIGHT:
            if (snakeHead->x < width - 1)   // Fix: use width - 1 here
                move[0] += 1;
            else
                move[0] = 0;
            break;
        default:
            break;
    }
    return move;
}

void moveSnake() {
    // Move each segment of the snake to the position of the segment ahead of it
    Block* current = snake;
    Block* next = current->next;

    while (next) {
        // Update the current segment's position to match the next segment
        current->x = next->x;
        current->y = next->y;

        // Move to the next pair of segments
        current = next;
        if (current->next == NULL) break;
        next = current->next;
    }

    // Update the snake head position based on the next move
    int* move = getNextMove();
    current->x = move[0];
    current->y = move[1];
    free(move);
}

void extendSnake() {
    // Allocate a new segment for the snake
    Block* newHead = (Block*) malloc(sizeof(Block));
    newHead->type = SNAKE;

    // Position the new segment at the next move location
    int* move = getNextMove();
    newHead->x = move[0];
    newHead->y = move[1];
    free(move);

    // Attach the new segment to the front of the snake
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

BlockType checkForCollision() {
	int* move = getNextMove();
	int x = move[0];
	int y = move[1];
	free(move);
	return grid[y * width + x];
}

Block* getSnake() {
	Block* head = (Block*) malloc(sizeof(Block));
	head->type = SNAKE;
	head->x = 3;
	head->y = 1;

	Block* body = (Block*) malloc(sizeof(Block));
	body->type = SNAKE;
	body->x = 2;
	body->y = 1;

	Block* tail = (Block*) malloc(sizeof(Block));
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
    do {
        // Randomly generate coordinates within the grid dimensions
        apple.x = getRandomNumber(0, width - 1);
        apple.y = getRandomNumber(0, height - 1);

        // Ensure the apple does not spawn on the snake
    } while (grid[apple.y * width + apple.x] != EMPTY);
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
	Block* current = snake;
	while (current) {
		Block* next = current->next;
		free(current);
		current = next;
	}
}

void handleExit() {
    closeGame();
    printf("Game exited safely.\n");
}
