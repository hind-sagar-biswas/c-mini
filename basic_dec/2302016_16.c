#include <stdio.h>

int main() {
	int amount;
	int notes[7] = { 100, 50, 20, 10, 5, 2, 1 };
	scanf("%d", &amount);
	for (int i = 0; i < 7; i++) {
		printf("%6.2f: %d Note(s)\n", (float) notes[i], amount / notes[i]);
		amount = amount % notes[i];
	}
	return 0;
}
