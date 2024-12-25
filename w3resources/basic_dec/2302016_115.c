#include <stdio.h>
int main ()
{
    int x, y, sum = 0, ctr = 0;
    scanf("%d %d", &x, &y);
    if (y < x) {
	x = x + y;
	y = x - y;
	x = x - y;
    }
    for (; x <= y; x++, ctr++) sum += x, printf("%d ", x);
    printf("\nAverage: %.2f\n", (float) sum / ctr);
    return 0;
}

