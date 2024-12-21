#include<stdio.h>
int main() {
    int n;
    long arr[500];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%ld", &arr[i]);

    long max = arr[0], temp = 0;
    for (int i = 0; i < n; i++) {
	for (int j = i; j < n; j++) {
	    temp += arr[j];
	    if (temp > max) max = temp;
	}
	temp = 0;
    }

    printf("Maximum contiguous sum is %ld", max);

    return 0;
}
