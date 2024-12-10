#include <stdio.h>
int main() {
	unsigned int max;
	scanf("%u", &max);

	for (int i = 1; i <= max; i++) {
		int coof = 1;
		printf("%4d ", coof);
		for (int a = 1; a <= i; a++) {
			coof = coof * (i - a + 1) / a;
			printf("%4d ", coof);
		}
		printf("\n");
	}
	
	return 0;
}
