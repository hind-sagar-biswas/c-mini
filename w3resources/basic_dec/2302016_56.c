#include <stdio.h>
int main() {
	int x;
	scanf("%d", &x);
	printf("Actual: %d; Shifted: %d\n", x, x << 2);
	return 0;
}
