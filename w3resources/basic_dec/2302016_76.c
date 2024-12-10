#include <stdio.h>
int main() {
	int limit;
	scanf("%d", &limit);
	for (int i = 0; i <= limit; i++) {
		printf("%2d\t%4d\t%4d\n", i, i * i, i * i * i);
	}
	return 0;
}
