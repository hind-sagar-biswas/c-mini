#include <stdio.h>
int main() {
	short n, arr[10];
	printf("Input an integer (2-10): ");
	scanf("%hd", &n);
	if (n < 2 || n > 10) return printf("Invalid number!\n"), 0;	
	for (int i = 0, j = 0; i < 10; i++, j++) {
		if (j == n) j = 0;
		arr[i] = j;
		printf("array_n[%d] = %d\n", i, arr[i]);
	}
	return 0;
}
