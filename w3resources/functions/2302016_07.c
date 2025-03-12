#include<stdio.h>
int is_prime(int);
int main()
{
    int n, prime;
    printf(" Input a positive number : ");
    scanf("%d",&n);
    printf(" The number %d %s a prime number.\n", n, is_prime(n) ? "is" : "is not");
    return 0;
}
int is_prime(int n)
{
    for(int i=2; i*i<=n; i++) {
         if(n%i==0) return 0;
    }
    return 1;
}
