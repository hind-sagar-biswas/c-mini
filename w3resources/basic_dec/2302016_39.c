#include <stdio.h>

int min(int a, int b) {return a < b ? a : b;}
int max(int a, int b) {return a > b ? a : b;}

int main() {
	int a, b, sum = 0;
	scanf("%d %d", &a, &b);
	for (int i = min(a, b); i <= max(a, b); i++) {
		if (i % 17) sum += i;
	}
	printf("Sum: %d", sum);
	return 0;
}
