#include <stdio.h>
int main() {
	int x;
	scanf("%d", &x);
	printf("Original: %d\nAbs: %u", x, x < 0 ? -x : x);
	return 0;
}
