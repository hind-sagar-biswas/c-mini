#include <stdio.h>
int main ()
{
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%s\n", (y > x) ? "Ascending" : "Descending");
    return 0;
}

