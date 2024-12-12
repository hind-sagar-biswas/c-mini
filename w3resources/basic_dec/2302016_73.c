#include <stdio.h>
int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%s", x % y == 0 ? "MULTIPLE" : "NOT MULTIPLE");
	return 0;
}
