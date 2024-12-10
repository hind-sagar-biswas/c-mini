#include <stdio.h>
int main() {
	int ctr = 0, n;
	int sum = 0;
	float avg = 0;
	printf("Input number on a separate line (888 to exit):\n");
	scanf("%d", &n);
	while (n != 888) {
		sum += n;
		ctr++;
		scanf("%d", &n);
	}
	if (ctr) avg = (float) sum / ctr;
	printf("\nAverage %f\n", avg);
	return 0;
}
