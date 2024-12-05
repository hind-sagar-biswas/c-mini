#include <stdio.h>

int main() {
	int n[5], odds = 0, sum = 0;
	scanf("%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &n[4]);
	for (int i = 0; i < 5; i++) {
		if (n[i] % 2) {
			odds++;
			sum += n[i];
		}
	}
	printf("Odds: %d\nSum: %d\n", odds, sum);
	return 0;
}
