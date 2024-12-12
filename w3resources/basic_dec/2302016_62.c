#include <stdio.h>
int main() {
    unsigned short int x, sum = 0;
    scanf("%hu", &x);
    if (x < 500) {
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        printf("Sum of the digits: %hu", sum);
    }
    else printf("Input must be less than 0");
    return 0;
}
