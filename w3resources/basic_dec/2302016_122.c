#include <stdio.h>
int main () {
    int m, n, sum = 0;
    scanf("%d %d", &m, &n); 
    m = (m % 2) ? m + 1 : m;
    for (int i = 0; i <= n; i += 1) sum += m, m += 2;
    printf("Sum = %d\n", sum);
    return 0;
}