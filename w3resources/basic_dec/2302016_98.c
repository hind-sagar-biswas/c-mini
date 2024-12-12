#include <stdio.h>
#include <stdbool.h>

int main() {
	int ch;
	bool last_pressed_char = false;
	printf("Enter text (Ctrl+D to end):\n");

	while ((ch = getchar()) != EOF) {
	        if (ch == ' ' || ch == '\t' || ch == '\n') {
			if (last_pressed_char) {
				last_pressed_char = false;
				printf("\n");
			}
		} else {
			last_pressed_char = true;
			putchar(ch);
		}

	}
	return 0;
}
