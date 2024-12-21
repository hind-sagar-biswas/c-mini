#include<stdio.h>
#include <string.h>
#include <stdbool.h>
int SieveOfEratosthenes(int n)
{
    int prime[n+1], count = 0;
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p])
        {
            count++;
            for (int i= p*p; i<=n; i += p) prime[i] = false;
        }
    }
    return count;
}
int main() {
    int n;
    printf("Input a number:\n");
    scanf("%d", &n);
    printf("Prime numbers up to %d: %d\n", n, SieveOfEratosthenes(n));
    return 0;
}

