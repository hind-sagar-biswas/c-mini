#include <stdio.h>

int main() {
	int n[5], positives = 0, sum = 0;
	scanf("%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &n[4]);
	for (int i = 0; i < 5; i++) {
		if (n[i] > 0) {
			positives++;
			sum += n[i];
		}
	}
	printf("Positives: %d\nAverage: %.2f\n", positives, (float) sum / positives);
	return 0;
}
