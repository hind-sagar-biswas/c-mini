#include <stdio.h>
int square(int);
int main() {
    int x = 5;
    printf("Input any number for square : ");
    scanf("%d", &x);
    int sqr = square(x);
    printf ("The square is :  %d\n", square(x));
    return 0;
}

int square(int x) {
    return x*x;
}
