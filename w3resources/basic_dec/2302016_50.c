#include <stdio.h>
int main() {
	float arr[5];
	scanf("%f %f %f %f %f", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
	for (int i = 0; i < 5; i++) {
		if (arr[i] < 5) printf("arr[%d] = %.2f\n", i, arr[i]);
	}
	return 0;
}
