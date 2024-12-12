#include <stdio.h>
#include <stdbool.h>
#define NUM_OF_PRIMES 3500

int primes[NUM_OF_PRIMES] = {2, 3, 5, 7}, num_of_primes = 4;

void setup();
bool is_prime(int num);
bool is_nearly_prime(int num);

int main() {
    setup();
    int x;
    scanf("%d", &x);
    if (is_nearly_prime(x)) printf("It is a Nearly prime number.\n");
    else printf("It is not a Nearly prime number.\n");
    return 0;
}

void setup() {
	for (int i = 0; i < 1000000000; i++)
	{
		if (is_prime(i)) primes[num_of_primes++] = i;
	}
}
bool is_prime(int num) {
    for (int i = 0; i < num_of_primes; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

bool is_nearly_prime(int num) {
    for (int i = 0; (i < num_of_primes) && primes[i] * primes[i] <= num; i++) 
    {
        if (num % primes[i] == 0 && is_prime(num / primes[i])) return false;
    }
    return true;    
}