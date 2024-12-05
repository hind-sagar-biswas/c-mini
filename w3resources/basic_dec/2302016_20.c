#include <stdio.h>
#include <math.h>

int main() {
	float a, b, c, d;
	scanf("%f %f %f", &a, &b, &c);
	d = b * b - 4 * a * c;
	if (d < 0) printf("No real roots");
	else if (d == 0) printf("One real root: %.5f", -b / (2 * a));
	else printf("Two real roots: %.5f and %.5f", (-b + sqrt(d)) / (2 * a), (-b - sqrt(d)) / (2 * a));
	return 0;
}
