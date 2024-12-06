#include <stdio.h>
int main() {
	double sum;
	for (float i = 1; i < 51; i++) sum += 1 / i;
	printf("%.2f ", sum);
	return 0;
}
