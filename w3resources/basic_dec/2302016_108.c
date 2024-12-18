
#include <stdio.h>
int main () 
{
	int x, y, sum_odd, sum_even;
	scanf("%d %d", &x, &y);
	short int is_odd = x % 2;
	for (int i = x; i <= y; i ++, is_odd = !is_odd) {
		if (is_odd) sum_odd += i;
		else sum_even += i;
	}
	printf("\nSum of all odd numbers between %d and %d: %d", x, y, sum_odd);
	printf("\nSum of all even numbers between %d and %d: %d", x, y, sum_even);
	return 0;
}

