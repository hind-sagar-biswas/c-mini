#include <stdio.h>
int main () {
    int n, i;
    printf("\nInput a number(integer):\n");
    scanf("%d", &n);
    if (n > 0) {
        printf("Sequence:\n");
        for (i = 1; i < n; i++) printf("%d, ", i);
        printf("%d\n", i);
    }
}

