#include <stdio.h>
int main() {
	int p, q, current = 1;
	scanf("%d %d", &p, &q);
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < q; j++) {
			printf("%d ", current);
			current++;
		}
		printf("\n");
	}
	return 0;
}
