#include <stdio.h>
int main () {
    float arr[7];
    for (int i = 0; i < 7; i++) {
	scanf("%f", &arr[i]);
	if (arr[i] <= 0) arr[i] = 1;
    }
    for (int i = 0; i < 7; i++) 
    {
	if (arr[i] > 0) continue;
	printf("array_nums[%d] = %.2f\n", i, arr[i]);
    }
    return 0;
}
