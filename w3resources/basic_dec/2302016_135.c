#include<stdio.h>

int main() {
    int n;
    printf("Input a number:\n");
    scanf("%d", &n);
    if (n >= 1 && n <= 50) {
        printf("\na + b + c + d = n");
        int count = 0;
        for (int a = 0; a <= 9; a++) {
            for (int b = 0; b <= 9; b++) {
                for (int c = 0; c <= 9; c++) {
                    int d = n - (a + b + c);
                    if (d >= 0 && d <= 9) {
                        printf("\n%d, %d, %d, %d", a, b, c, d);
                        count++;
                    }
                }
            }
        }
        printf("\n\nTotal number of combinations: %d\n", count);
    } else {
        printf("Number out of range. Please enter a number between 1 and 50.\n");
    }

    return 0;
}

