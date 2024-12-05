#include <stdio.h>

int main() {
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	if (!(a + b > c && a + c > b && b + c > a)) return printf("Not a triangle"), 0;
	printf("Perimeter = %.2f", (a + b + c) / 2);
	return 0;
}
