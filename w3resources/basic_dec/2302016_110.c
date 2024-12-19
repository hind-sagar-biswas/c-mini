#include <stdio.h>
int main () 
{
	int n;
	scanf("%d", &n);
	short int is_odd = n % 2;
	if (!n) return printf("Zero\n"), 0;
	printf("%s-%s", (n > 0) ? "positive" : "negative", is_odd ? "odd" : "even");
	return 0;
}

