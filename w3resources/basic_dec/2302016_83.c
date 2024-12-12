#include <stdio.h>
int count(int x, int digit);

int main() {
	int x, digit;
	printf("Enter number and digit: ");
	scanf("%d %d", &x, &digit);
	printf("Number of %ds in %d is %d", digit, x, count(x, digit));
	return 0;
}

int count(int x, int digit) {
	int rem, c = 0;
	while (x > 0) {
		rem = x % 10;
		x /= 10;
		if (rem == digit) c++;
	}
	return c;
}
