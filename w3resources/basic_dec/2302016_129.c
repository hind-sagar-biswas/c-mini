#include <stdio.h>
int main() {
	double n, arr[10];
	printf("Input an number: ");
	scanf("%lf", &n);
	for (int i = 0; i < 10; i++) {
		if (!i) arr[i] = n;
		else arr[i] = arr[i - 1] / 3;
		printf("array_n[%d] = %.4lf\n", i, arr[i]);
	}
	return 0;
}
