
#include <stdio.h>
int main () 
{
	int x, ctr_even = 0, ctr_odd = 0, ctr_positive = 0, ctr_negative = 0;
	printf("\nInput 7 integers:\n");
	for (int i = 0; i < 7; i++){
		scanf("%d", &x);
		if (x > 0) ctr_positive++;
		if (x < 0) ctr_negative++;
		if (x % 2 == 0) ctr_even++;
		else ctr_odd++;
	}
	printf("\nNumber of even values: %d", ctr_even);
	printf("\nNumber of odd values: %d", ctr_odd);
	printf("\nNumber of positive values: %d", ctr_positive);
	printf("\nNumber of negative values: %d", ctr_negative);
	return 0;
}

