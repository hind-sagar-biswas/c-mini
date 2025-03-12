#include <stdio.h>
int checkPerfect(int);
void find_perfect_num(int, int);

int main()
{
    int min, max;
    printf(" Least: ");
    scanf("%d", &min);
    printf(" Highest: ");
    scanf("%d", &max);

    printf("\n The perfect numbers between %d to %d are : \n", min, max);
    find_perfect_num(min, max);
    printf("\n\n"); 
    return 0;
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

void find_perfect_num(int min, int max)
{
    for(int i = min; i <= max; i++)
    {
        if(is_perfect(i)) printf(" %d  ", i);
    }
}

