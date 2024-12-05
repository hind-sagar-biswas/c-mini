#include <stdio.h>

int main() {
	float x, y;
	scanf("%f %f", &x, &y);
	if (x > 0 && y > 0) printf("Quadrant\tI: (+,+)");
	else if (x > 0 && y < 0) printf("Quadrant\tII: (+,-)");
	else if (x < 0 && y < 0) printf("Quadrant\tIII: (-,-)");
	else if (x < 0 && y > 0) printf("Quadrant\tIV: (-,+)");
	return 0;
}
