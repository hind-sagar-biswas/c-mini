#include <stdio.h>
int main() {
	int smallest, current, pos = 0;
	printf("Enter 6 numbers:\n");
	for (int i = 0; i < 6; i++)
	{
		scanf("%d", &current);
		if (i == 0) smallest = current;
		else if (current < smallest) {
			smallest = current;
			pos = i;
		}
	}
	printf("Smallest number is %d at position %d", smallest, pos + 1);
	return 0;
}
