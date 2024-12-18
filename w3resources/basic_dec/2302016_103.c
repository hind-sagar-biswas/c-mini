#include <stdio.h>

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	int rem = (x > y) ? x % y : y % x;
	printf("%s\n", (!rem) ? "Multiples" : "Not Multiples");
	return 0;
}
