#include <stdio.h>
int main(void) {
	int x = 0;
	while (x <= 10) printf("%d\n", x++);
	while (x >= 0) printf("%d\n", x--);
	return 0;
}
