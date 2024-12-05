#include <stdio.h>

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	if (!y) return printf("Cannot divide by zero"), 0;
	printf("Quotient: %lf", (double) x / y);
	return 0;
}
