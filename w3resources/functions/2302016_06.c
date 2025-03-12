#include<stdio.h>

long toBin(int);

int main()
{
    long bin;
    int dec;
    printf(" Input any decimal number : ");
    scanf("%d",&dec);
    bin = toBin(dec);
    printf("\n The Binary value is : %ld\n\n",bin);

    return 0;
}
long toBin(int dec)
{
    long bin=0,remainder,f=1;
    while(dec != 0)
    {
         remainder = dec % 2;
         bin = bin + remainder * f;
         f = f * 10;
         dec = dec / 2;
    }
    return bin;
}
