#include <stdio.h>
int main () {
    int arr[7];
    for (int i = 0; i < 7; i++) {
	scanf("%d", &arr[i]);
	if (arr[i] <= 0) arr[i] = 1;
    }
    for (int i = 0; i < 7; i++) printf("array_nums[%d] = %d\n", i, arr[i]);
    return 0;
}
