#include <stdio.h>
int main () {
    int arr[7];
    scanf("%d", &arr[0]);
    for (int i = 0; i < 7; i++) {
	if (i > 0) arr[i] = arr[i - 1] * 2;
	printf("array_nums[%d] = %d\n", i, arr[i]);
    }
    return 0;
}
