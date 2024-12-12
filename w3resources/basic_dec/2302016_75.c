#include <stdio.h>
int reverse(int x) {
	int r = 0, temp;
	while (x > 0) {
		temp = x % 10;
		x /= 10;
		r = r * 10 + temp;
	}
	return r;
}
int main() {
	int n;
	scanf("%d", &n);
	n = reverse(n);
	while (n > 0) {
		printf("%d ", n % 10);
		n /= 10;
	}
	return 0;
}
