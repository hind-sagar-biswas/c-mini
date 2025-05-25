#include "messages.h"

void sayGoodbye(int height, int width) {
	clear();

	int y = (height / 2) - 4;
	int x = (width / 2) - 6;

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
		int x = (width / 2) - 23;
		mvprintw(y + j, x, "%s", message[j]);
	}

	refresh();
	usleep(1500000);
}

void showHighscoreMessage(int height, int width, int numHighscores) {
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
		mvprintw(y + j, x, "%s", message[j]);
	}
}

void showGameOverMessage(int height, int width, int score) {
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
		mvprintw(y + j, x, "%s", message[j]);
	}

	mvprintw(y + 8, x, "SCORE:  %d", score);

	attroff(COLOR_PAIR(1));
}

void showTitleMessage(int height, int width) {
	int y = (height / 2) - 6;
	int x = (width / 2) - 6;

	char intro[6][31] = {
		"   _____             _        ",
		"  / ____|           | |       ",
		" | (___  _ __   __ _| | _____ ",
		"  \\___ \\| '_ \\ / _` | |/ / _ \\",
		"  ____) | | | | (_| |   <  __/",
		" |_____/|_| |_|\\__,_|_|\\_\\___|",
	};

	for (int j = 0; j < 6; j++) {
		int x = (width / 2) - 16;
		mvprintw(y + j, x, "%s", intro[j]);
	}
}
