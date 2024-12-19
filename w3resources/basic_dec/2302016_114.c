#include <stdio.h>
int main ()
{
    int x, y, sum = 0;
    scanf("%d %d", &x, &y);
    if (y > x) {
	x = x + y;
	y = x - y;
	x = x - y;
    }
    for (int i = (x % 2) ? x + 1 : x + 2; i <= y; i += 2) sum += i;
    printf("%d\n", sum);
    return 0;
}

