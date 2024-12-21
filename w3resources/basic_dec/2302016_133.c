#include <stdio.h>
int count_digits(int z) {
	int ctr = 0;
	while (z) {
		z /= 10;
		ctr++;
	}
	return ctr;
}
int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	x = count_digits(x+y);
	printf("Number of digits of the sum value of the said numbers: %d", x);
	return 0;
}
