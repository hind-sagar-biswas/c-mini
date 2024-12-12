#include <stdio.h>
#include <stdbool.h>

int main() {
    int ch, words = 0, characters = 0, newlines = 0;
	bool last_pressed_char = false;
    printf("Enter text (Ctrl+D to end):\n");

    while ((ch = getchar()) != EOF) {
        if (ch == ' ' || ch == '\t') {
            characters++;
			if (last_pressed_char) {
				words++;
				last_pressed_char = false;
			}
        } else if (ch == '\n') newlines++;
		else {
			characters++;
			last_pressed_char = true;
		}
    }
    
    printf("\nNumber of blanks, tabs, and newlines:\n");
    printf("blank=%d, tab=%d, newline=%d\n", blanks, tabs, newlines);

    return 0;
}