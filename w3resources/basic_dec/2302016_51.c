#include <stdio.h>
int main() {
	int arr[6], tmp;
	scanf("%d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5]);
	for (int i = 0; i < 3; i++)
	{
		tmp = arr[i];
		arr[i] = arr[5 - i];
		arr[5-i] = tmp;
	}
	for (int i = 0; i < 6; i++)
	{
		printf("array_n[%d] = %d\n", i, arr[i]);
	}
	return 0;
}
