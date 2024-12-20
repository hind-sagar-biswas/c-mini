#include <stdio.h>
int main () {
    int x;
    printf("\nInput a number(integer):\n");
    scanf("%d", &x);
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) printf("%d, %d\n", i, x / i);
    }
    return 0;
}
