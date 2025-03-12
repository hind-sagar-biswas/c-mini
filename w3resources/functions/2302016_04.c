#include <stdio.h>

int checkOddEven(int n1)
{
    return (n1 & 1);
}

int main()
{
    int n1;
    printf("Input any number : ");
    scanf("%d", &n1);
    printf("%s", checkOddEven(n1) ? "Odd" : "Even");
    return 0;
}
