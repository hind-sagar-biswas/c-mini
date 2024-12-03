#include <stdio.h>
#define PI 3.14159265359
int main() {
	float r;
	printf("Enter radius: ");
	scanf("%f", &r);
	printf("Perimeter of the Circle = %f inches\n", 2 * PI * r);
	printf("Area of the Circle = %f square inches\n", PI * r * r);
	return 0;
}
