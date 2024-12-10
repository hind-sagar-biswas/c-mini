#include <stdio.h>
#include <math.h>
int main() {
    double x;
    scanf("%lf", &x);
    if (x) printf("%.4lf", sin(1/x));
    else printf("Input can't be zero!");
    return 0;
}
