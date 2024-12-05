#include <stdio.h>

int main() {
	int n, max, max_pos = 0;
	printf("Number of input: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		if (i == 0) max = num;
		else if (num > max) {
			max = num;
			max_pos = i;
		}
	}
	printf("Max: %d\nPosition: %d", max, max_pos + 1);
	return 0;
}
