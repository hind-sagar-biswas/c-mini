#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < 101; i++) {
		if (i % n == 3) printf("%d ", i);
	}
	return 0;
}
