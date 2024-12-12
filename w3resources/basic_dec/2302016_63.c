#include <stdio.h>
#include <math.h>
int main() {
	unsigned short int n, j = 1;
	int sum = 0;
	scanf("%hu", &n);
	if (n > 100) return printf("Input must be less than 100"), 1;
	for (short int i = 1; j <= n; i++) {
		sum += (int) pow(j, 4);
		j+=i;
	}
	printf("%d", sum);
	return 0;
}
