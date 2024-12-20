#include <stdio.h>
#define SIZE 8
int main() {
	int arr[SIZE], tmp;
	printf("Enter %d numbers: ", SIZE);
	scanf("%d %d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7]);
	for (int i = 0; i < SIZE / 2; i++)
	{
		tmp = arr[i];
		arr[i] = arr[SIZE - 1 - i];
		arr[SIZE - 1 - i] = tmp;
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("array_n[%d] = %d\n", i, arr[i]);
	}
	return 0;
}
