#include <stdio.h>
int main() {
	int n, current = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("%2d %2d %2d\n", current, current + 1, current + 2);
		current += 3;
	}
	return 0;
}
