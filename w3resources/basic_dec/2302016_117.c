#include <stdio.h>
int main ()
{
    float x, y;
    scanf("%f %f", &x, &y);
    if (y == 0) return printf("Division is not possible\n"), 0;
    printf("%.2f\n", x / y);
    return 0;
}

