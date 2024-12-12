#include <stdio.h>
int main() {
	int n, val[10];
	printf("Number of inputs: ");
	scanf("%d", &n);
	if (n > 10) {
		printf("Limit exeeded! Setting n = 10\n");
		n = 10;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &val[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < val[i]; j++) {
			printf("#");
		}
		printf("\n");
	}
	return 0;
}
