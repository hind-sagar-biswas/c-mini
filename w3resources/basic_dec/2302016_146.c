#include<stdio.h>
#include <string.h>
int main() {
    char s[1025];
    fgets(s, sizeof(s), stdin);
    char *token, *str = s;
    printf("\nExtracted words of 3 to 6 characters length from the said sentence:\n");
    while ((token = strtok_r(str, " .,\n", &str))) {
	int len = strlen(token);
	if (len >= 3 && len<=6) printf("%s\n", token);
    }
    return 0;
}

