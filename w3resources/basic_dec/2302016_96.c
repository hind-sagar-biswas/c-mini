#include <stdio.h>

int main() {
    int ch;
    int blanks = 0, tabs = 0, newlines = 0;

    printf("Enter text (Ctrl+D to end):\n");

    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            blanks++;
        } else if (ch == '\t') {
            tabs++;
        } else if (ch == '\n') {
            newlines++;
        }
    }
    
    printf("\nNumber of blanks, tabs, and newlines:\n");
    printf("blank=%d, tab=%d, newline=%d\n", blanks, tabs, newlines);

    return 0;
}