#include <stdio.h>
int reverse(int x);

int main() {
	int x;
	scanf("%d", &x);
	printf("%d is %s", x, (reverse(x) == x) ? "a palindrome" : "not a palindrome");
	return 0;
}

int reverse(int x) {
	int r = 0, temp;
	while (x > 0) {
		temp = x % 10;
		x /= 10;
		r = r * 10 + temp;
	}
	return r;
}
