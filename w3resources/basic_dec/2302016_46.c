#include <stdio.h>
int main() {
	unsigned int limit, denominator = 1;
	double sum = 0, numerator;
	scanf("%u", &limit);
	for (numerator = 1; numerator <= limit; numerator += 2) {
		sum += numerator / denominator;
		denominator *= 2;
	}
	printf("%.2f", sum);
	return 0;
}
