#include <stdio.h>
#include <math.h>
int main() {
	unsigned short int n;
	int sum = 0;
	for (short int i = 1; i <= n; i++) {
		sum += pow(i, 4);
	}
	printf("%d", sum);
	return 0;
}
