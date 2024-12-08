#include <stdio.h>
int main() {
	int smallest, current, pos = 0;
	for (int i = 0; i < 6; i++)
	{
		scanf("%d", &current);
		if (i == 0) smallest = current;
		else if (current < smallest) {
			smallest = current;
			pos = i;
		}
	}
	return 0;
}
