
#include <stdio.h>
int main () 
{
	int n;
	short int is_odd, ctr = 0;
	scanf("%d", &n);
	printf("\nSquare of each even between 1 and %d:\n", n);
	for (int i = 2; i <= n; i += 2) printf("%d^2\t= %d\n", i, i * i);
	printf("\nSquare of each odd between 1 and %d:\n", n);
	for (int i = 1; i <= n; i += 2) printf("%d^2\t= %d\n", i, i * i);
	return 0;
}

