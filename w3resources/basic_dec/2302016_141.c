#include<stdio.h>
int combination(int n, int sum, int start) {
    if (n == 0) return sum == 0 ? 1 : 0;
    int count = 0;
    for (int i = start; i <= 9; i++) {
        if (i <= sum) count += combination(n - 1, sum - i, i + 1);
    }
    return count;
}
int main() {
    int n, s;
    printf("Input the number:\n");
    scanf("%d", &n);
    printf("Sum of the digits:\n");
    scanf("%d", &s);
    printf("Number of combinations: %d\n", combination(n, s, 0));
    return 0;
}

