#include <stdio.h>
int main() {
	unsigned int x, r = 0, temp;
	scanf("%u", &x);
	while (x > 0) {
		temp = x % 10;
		x /= 10;
		r = r * 10 + temp;
	}
	printf("%u\n", r);
	return 0;
}
