#include<stdio.h>
#include <string.h>
int SieveOfEratosthenes(int n)
{
    int prime[n+1], count = 0;
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = 0;

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p])
        {
            for (int i= p*p; i<=n; i += p) prime[i] = 0;
        }
    }

    for (int i=0; i<=n; i++) if (prime[i]) count++;
    return count;
}
int main() {
    int n;
    printf("Input a number: ");
    scanf("%d", &n);
    printf("Prime numbers up to %d: %d\n", n, SieveOfEratosthenes(n));
    return 0;
}

