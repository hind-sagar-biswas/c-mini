
#include <stdio.h>
int main () 
{
	int n, i;
	short int is_odd, ctr = 0;
	scanf("%d", &n);
	is_odd = n % 2;
	printf("\nNext 10 consecutive %s numbers:\n", is_odd ? "even" : "odd");
	for(i = n + 1; ctr < 10; i += 2, ctr++) printf("%d ", i);
	printf("\n");
	printf("\nPrevious 10 consecutive %s numbers:\n", is_odd ? "odd" : "even");
	for(i = n + 2, ctr = 0; ctr < 10; i -= 2, ctr++) printf("%d ", i);
	printf("\n");
	return 0;
}

