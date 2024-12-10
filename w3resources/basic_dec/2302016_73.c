#include <stdio.h>
int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%s", y % x == 0 ? "MULTIPLE" : "NOT MULTIPLE");
	return 0;
}
