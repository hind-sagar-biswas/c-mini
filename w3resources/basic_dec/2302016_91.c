#include <stdio.h>
#define H_ANGLE 30
#define M_ANGLE 6
#define MH_ANGLE 0.5
int main() {
	float hour, minute, degree;
	scanf("%f %f", &hour, &minute);
	degree = (hour * H_ANGLE + minute * MH_ANGLE) - (minute * M_ANGLE);
	printf("%.2f", degree < 180 ? degree : 360 - degree);
	return 0;
}
