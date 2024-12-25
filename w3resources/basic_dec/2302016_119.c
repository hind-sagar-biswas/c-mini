#include <stdio.h>
int main ()
{
    int x, y, sum = 0;
    scanf("%d %d", &x, &y);
    if (y < x) {
	x = x + y;
	y = x - y;
	x = x - y;
    }
    for (; x <= y; x++) {
	if (x % 7) sum += x;
    }
    printf("Sum: %d\n", sum);
    return 0;
}

