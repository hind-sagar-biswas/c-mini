#include <stdio.h>
int main() {
	int arr[5];
	scanf("%d", &arr[0]);
	printf("n[0]\t= %d\n", arr[0]);
	for (int i = 1; i < 5; i++) {
		arr[i] = arr[i - 1] * 3;
		printf("n[%d]\t= %d\n", i, arr[i]);
	}
	return 0;
}
