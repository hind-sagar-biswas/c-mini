#include <stdio.h>
int main ()
{
	int num, min, size, pos = 0;
	printf("Input number of elements in array: ");
	scanf("%d", &size);
	printf("Input %d elements in the array:\n", size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &num);
		if (!i) min = num;
		else if (num < min) min = num, pos = i;
	}
	printf("Minimum element is %d and it's position is %d", min, pos);
	return 0;
}
