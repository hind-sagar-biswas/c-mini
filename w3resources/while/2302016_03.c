#include <stdio.h>
int main(void) {
	int i = 1, mul = 1;
	while (i <= 5) mul *= i++;
	printf("Product: %d\n", mul);
	return 0;
}
