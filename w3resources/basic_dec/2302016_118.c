#include <stdio.h>
int main ()
{
    int x, total = 0;
    for (int i = 0; i < 5; i++) {
	scanf("%d", &x);
	if (x < 0 || x > 100) printf("Invalid Mark\n"), i--;
	else total += x;
    }
    printf("Average: %.2f\n", (float) total / 5);
    return 0;
}

