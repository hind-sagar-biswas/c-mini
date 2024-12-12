#include <stdio.h>
#include <math.h>
int main() {
	int n, p;
	printf("Enter limit: ");
	scanf("%d", &n);
	printf("=======================================\n");
	printf("n\tn^2\tn^-2\n");
	printf("=======================================\n\n");
	for (int i = 0; i <= n; i++) {
		p = pow(2, i);
		printf("%d\t%d\t%f\n", i, p, 1/(float)p);
	}
	printf("=======================================\n");
	return 0;
}
