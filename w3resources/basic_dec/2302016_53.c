#include <stdio.h>
int main() {
	float p, n, r;
	scanf("%f %f %f", &p, &n, &r);
	printf("Interest: %.2f percent", p * n * r / 100);
	return 0;
}
