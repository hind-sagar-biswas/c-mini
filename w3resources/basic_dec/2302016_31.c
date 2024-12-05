#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n == 0) return printf("Even\n");
	if (n > 0) printf("Positive ");
	else printf("Negative ");
	if (n % 2 == 0) printf("Even");
	else printf("Odd");
	printf("\n");
	return 0;
}
