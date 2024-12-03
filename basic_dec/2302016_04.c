#include <stdio.h>

int main() {
	char c[3];
	scanf("%s", c);
	printf("%c%c%c", c[2], c[1], c[0]);
	return 0;
}
