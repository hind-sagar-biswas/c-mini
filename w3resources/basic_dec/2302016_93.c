#include <stdio.h>
#include <stdbool.h>
#define NUM_OF_PRIMES 3500

int primes[NUM_OF_PRIMES] = {2, 3, 5, 7}, num_of_primes = 4;

void setup();
bool is_nearly_prime(int num);
bool is_prime(int num, bool generative);

int main() {
    setup();
    printf("Enter a number: ");
    int x;
    scanf("%d", &x);
    if (is_nearly_prime(x)) printf("It is a Nearly prime number.\n");
    else printf("It is not a Nearly prime number.\n");
    return 0;
}

void setup() {
	for (int i = 8; (i < 1000000000) && (num_of_primes < NUM_OF_PRIMES); i++)
	{
		if (is_prime(i, true)) primes[num_of_primes++] = i;
	}
}
bool is_prime(int num, bool generative) {
    if (num < 2) return false;
    for (int i = 0; i < num_of_primes; i++) {
        if (generative && num % primes[i] == 0) return false;
	else if (!generative && num == primes[i]) return true;
    }
    return generative ? true : false;
}

bool is_nearly_prime(int num) {
    for (int i = 0; (i < num_of_primes) && primes[i] * primes[i] <= num; i++) 
    {
        if (num % primes[i] == 0 && is_prime(num / primes[i], false)) return true;
    }
    return false;
}
