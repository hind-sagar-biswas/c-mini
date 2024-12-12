#include <stdio.h>
#include <stdbool.h>
bool is_prime(long int num);
bool is_palindrome(long int num);
long int reverse(long int x);
int main() {
	long int min, max;
	scanf("%ld %ld", &min, &max);
	for (long int i = min; i <= max; i++) {
		if (!is_prime(i)) continue;
		if (!is_palindrome(i)) continue;
		printf("%ld ", i);
	}
	return 0;
}
bool is_prime(long int num) {
    if (num <= 1) return false;
    if (num == 2)  return true;
    if (num % 2 == 0) return false;

    for (long int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}
bool is_palindrome(long int num) {
    return num == reverse(num);
}
long int reverse(long int x) {
	long int r = 0, temp;
	while (x > 0) {
		temp = x % 10;
		x /= 10;
		r = r * 10 + temp;
	}
	return r;
}
