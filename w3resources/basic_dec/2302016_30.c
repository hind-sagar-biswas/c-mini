#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (n = 0; n < 5; n++) {
		if (n % 2 == 0) printf("%d^2 = %d\n", n, n * n);
	}
	return 0;
}
