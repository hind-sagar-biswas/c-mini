#include <stdio.h>

int fact(int);
int main()
{
    int sum = 0, n = 5;
    for (int i = 1; i <= n; i++) sum += fact(i) / i;
    printf("The sum of the series is : %d\n\n",sum);
    return 0;
}

int fact(int n)
{
    int num=0,f=1;
    while(num<=n-1)
    {
        f =f+f*num;
        num++;
    }
    return f;
}
