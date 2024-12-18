#include <stdio.h>

int main() {
	int i;
	scanf("%d", &i);
	if (i > 100 || i < 0) printf("Outside the range\n");
	else if (i > 80) printf("Range (80, 100]\n");
	else if (i > 50) printf("Range (50 - 80]\n");
	else if (i > 30) printf("Range (30 - 50]\n");
	else if (i >= 0) printf("Range [00 - 30]\n");
	return 0;
}
