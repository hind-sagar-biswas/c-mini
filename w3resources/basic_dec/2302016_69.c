#include <stdio.h>
int main() {
	unsigned int max;
	printf("Enter max number: ");
	scanf("%u", &max);

	for (int i = 0; i <= max; i++) {
		int coof = 1;
		printf("%2d: %6d ", i, coof);
		for (int a = 1; a <= i; a++) {
			coof = coof * (i - a + 1) / a;
			printf("%6d ", coof);
		}
		printf("\n");
	}
	
	return 0;
}
