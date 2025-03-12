#include <stdio.h>
 
int is_armstrong(int n);
int is_perfect(int n);
 
int main()
{
    int n;
    printf(" Input any number: ");
    scanf("%d", &n);
    printf(" The %d %s an Armstrong number.\n", n, is_armstrong(n) ? "is" : "is not");
    printf(" The %d %s a Perfect number.\n", n, is_perfect(n) ? "is" : "is not");
    return 0;
}

int is_armstrong(int n) 
{
    int ld, sum = 0;
    for(int num  = n; num; num /= 10)
    {
        ld = num % 10;
        sum += ld * ld * ld;
    }
    return (n == sum);
}

int is_perfect(int n) 
{
    int sum = 0, num = n;
    for(int i = 1; i < num; i++)  
    {
        if(num % i == 0) sum += i;
    }
    return (n == sum);
}

