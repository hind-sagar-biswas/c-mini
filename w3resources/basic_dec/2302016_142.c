#include<stdio.h>
int main() {
    int a, b, d;
    printf("Enter adjacent sides: ");
    scanf("%d %d", &a, &b);
    printf("Enter the diagonal: ");
    scanf("%d", &d);
    if (a * a + b * b == d * d) printf("It is a Rectangle");
    else printf("It is not a Rectangle");
    if (a == b) printf("\nIt is a Rhombus");
    else printf("\nIt is not a Rhombus");
    return 0;
}

