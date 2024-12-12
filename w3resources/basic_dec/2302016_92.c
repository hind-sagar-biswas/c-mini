/***************************************************************************************
C program to calculate factorial with deferred multiplication by powers of two
Ref: "Comments on Factorial Programs" by Richard J. Fateman
(https://people.eecs.berkeley.edu/~fateman/papers/factorial.pdf)
Used Algorithms:
	- Deferred multiplication by powers of two 
		- Reduces cost for powers of two
		- Time Complexity: O(n)
		- [Best for small integers below 20]
	- Interleaved Prime sieve
		- Skips composite number multiplications
		- Time Complexity: O(n log log n)
		- [Best for large integers above 30
**************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t int_pow(int base, int exp);
void generate_primes(int n, int *is_prime);
uint64_t factorial_deferred_shift(int n);
uint64_t factorial_prime_sieve(int n);
unsigned int get_last_non_zero_digit(uint64_t num);

int main() {
    int num;
    long long result;

    scanf("%d", &num);

    if (num < 0) return printf("Factorial is not defined for negative numbers.\n"), 1;
    else if (num <= 20)  result = factorial_deferred_shift(num);
    else result = factorial_prime_sieve(num);

    printf("%d! = %llu\nLast non-zero digit: %u\n", num, result, get_last_non_zero_digit(result));
    return 0;
}

uint64_t factorial_deferred_shift(int n) {
    uint64_t result = 1;
    unsigned int shift_count = 0;     // Count the powers of two

    for (int i = 1; i <= n; i++) {
        int current = i;

        // Extract powers of two from the current number
        while (current % 2 == 0) {
            current /= 2;
            shift_count++;
        }

        // Multiply the remaining value after removing powers of two
        result *= current;
    }

    // Apply the deferred powers of two using bit-shifting
    result <<= shift_count;

    return result;
}

void generate_primes(int n, int *is_prime) {
    for (int i = 0; i <= n; i++) {
        is_prime[i] = 1; // Assume all numbers are prime initially
    }
    is_prime[0] = is_prime[1] = 0; // 0 and 1 are not prime

    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = 0; // Mark multiples of p as non-prime
            }
        }
    }
}

uint64_t factorial_prime_sieve(int n) {
    if (n == 0 || n == 1) return 1; // Base cases

    // Allocate space for prime sieve
    int *is_prime = (int *)malloc((n + 1) * sizeof(int));
    if (!is_prime) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Generate primes up to n
    generate_primes(n, is_prime);

    uint64_t result = 1;

    // Loop over primes and calculate their contribution
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) {
            // Calculate the power of the prime in the factorial
            int power = 0;
            int current = n;

            while (current > 0) {
                power += current / p;
                current /= p;
            }

            // Multiply the prime raised to its power into the result
	    result *= int_pow(p, power);
        }
    }

    free(is_prime); // Free allocated memory
    return result;
}

unsigned int get_last_non_zero_digit(uint64_t num) {
    while (num % 10 == 0) num /= 10;
    return num % 10;
}

uint64_t int_pow(int base, int exp) {
    uint64_t result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base; // If exp is odd, multiply base
        base *= base; // Square the base
        exp /= 2;     // Halve the exponent
    }
    return result;
}
