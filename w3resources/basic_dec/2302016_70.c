#include <stdio.h>
int main() {
	for (int i = 65; i <= 122; i++)
	{
		if (i > 90 && i < 97) continue;
		printf("[%d-%c]\t", i, i);
	}
	printf("\n");
	return 0;
}
