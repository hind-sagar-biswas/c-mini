#include <stdio.h>
int main() {
	int notes[7] = { 100, 50, 20, 10, 5, 2, 1 };
	float coins[5] = { 0.50, 0.25, 0.10, 0.05, 0.01 };
	float val;
	int full_val;
	scanf("%f", &val);
	full_val = (int) val;
	val = val - full_val;
	printf("NOTES: \n");
	for (int i = 0; i < 7; i++) {
		if (full_val < notes[i]) continue;
		printf("%3d: %-4d Note(s)\n", notes[i], full_val / notes[i]);
		full_val = full_val - (full_val / notes[i]) * notes[i];
	}
	printf("COINS: \n");
	for (int i = 0; i < 5; i++) {
		if (val < coins[i]) continue;
		printf("%3.2f: %d\tCoin(s)\n", coins[i], (int) (val / coins[i]));
		val = val - ((int) (val / coins[i])) * coins[i];
	}
	return 0;
}
