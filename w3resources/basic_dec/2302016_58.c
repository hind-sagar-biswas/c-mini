#include <stdio.h>
int main() {
	float min, max, current;
	for (int i = 0; i < 4; i++)
	{
		scanf("%f", &current);
		if (!i) {
			min = current;
			max = current;
		}
		else if (current < min) min = current;
		else if (current > max) max = current;
	}

	printf("Difference: %f\n", max - min);
	return 0;
}
