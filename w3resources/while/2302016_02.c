#include <stdio.h>
int main(void) {
	int input = -1, sum = 0;
	while (input != 0) {
		printf("Enter a number [0 to stop]: ");
		scanf("%d", &input);
		if (input > 0) sum += input;
	}
	printf("Sum: %d\n", sum);
	return 0;
}
