#include <stdio.h>
int main(void) {
	int i;
	long long fact = 1;

	printf("Enter a positive number: ");
	scanf("%d", &i);

	if (i < 0) {
		printf("Invalid input!\n");
		return 1;
	}

	while (i) fact *= i--;
	printf("Factorial: %lld\n", fact);
	return 0;
}
