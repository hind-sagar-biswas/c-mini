
#include <stdio.h>
int main() {
	int x, sum, min = -1, max = -1, ctr = 0;
	while (x >= 0) {
		scanf("%d", &x);
		if (min == -1) {
			if (x < 0) return printf("Input must be a positive integer!");
			min = x;
			max = x;
			sum = x;
		}
		else {
			if (x < 0) break;
			sum += x;
			max = x > max ? x : max;
			min = x < min ? x : min;
		}
		ctr++;
	}
	printf("Max: %d\nMin: %d\nAverage: %.2f\n", max, min, (float) sum / ctr);
	return 0;
}
