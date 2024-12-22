#include <stdio.h>

int main() {
	int n, i;
	scanf("%d", &i);
	for (n = 1; n <= i; n++) {
		if (n % 2 == 0) printf("%d^2 = %d\n", n, n * n);
	}
	return 0;
}
