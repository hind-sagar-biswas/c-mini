#include <stdio.h>

int main() {
	float distance, fuel;
	printf("Distance (km) & fuel (L): ");
	scanf("%f %f", &distance, &fuel);
	printf("Average Consumption: %.2f km/L", distance / fuel);
	return 0;
}
