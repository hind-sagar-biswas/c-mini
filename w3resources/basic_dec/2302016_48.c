#include <stdio.h>
int main() {
	int arr[5];
	scanf("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
	for (int i = 0; i < 5; i++) {
		if (arr[i] < 1) arr[i] = 100;
		printf("n[%d]\t= %3d\n", i, arr[i]);
	}
	return 0;
}
