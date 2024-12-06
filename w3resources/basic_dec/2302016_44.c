#include <stdio.h>
int main() {
	int num, sum = 0, count = 0;
	while (1) {
		scanf("%d", &num);
		if (num == 0) break;
		sum += num;
		count++;
	}
	printf("%.2f", (float) sum / count);
	return 0;
}
