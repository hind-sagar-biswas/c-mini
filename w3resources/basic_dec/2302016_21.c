#include <stdio.h>

int main() {
	int i;
	scanf("%d", &i);
	if (i > 80 || i < 0) printf("Outside the range\n");
	else if (i > 60) printf("Range [60, 80]\n");
	else if (i > 40) printf("Range [40 - 60]\n");
	else if (i > 20) printf("Range [20 - 40]\n");
	else if (i > 0) printf("Range [00 - 20]\n");
	return 0;
}
