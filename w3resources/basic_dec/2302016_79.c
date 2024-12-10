#include<stdio.h>
int main()
{
    int limit;
    scanf("%d", &limit);
    printf("x\tx+2\tx+4\tx+6\n\n");
    printf("---------------------------\n");
    for(int x = 1; x <= limit; x += 3)
        printf("%d\t%d\t%d\t%d\n", x, (x+2), (x+4), (x+6));
    return 0;
}
