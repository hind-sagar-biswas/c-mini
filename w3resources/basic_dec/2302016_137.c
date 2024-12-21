#include<stdio.h>
#include <math.h>
#include <stdbool.h>

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return fabsf((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/ (float) 2);
}
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
    float A = area (x1, y1, x2, y2, x3, y3);
    float A1 = area (x, y, x2, y2, x3, y3);
    float A2 = area (x1, y1, x, y, x3, y3);
    float A3 = area (x1, y1, x2, y2, x, y);
    return (A == A1 + A2 + A3);
}
int main() {
    int x1, y1, x2, y2, x3, y3, x, y;
    printf("Enter the coordinates of three points: ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    printf("Enter the coordinates of a point: ");
    scanf("%d %d", &x, &y);
    if (isInside(x1, y1, x2, y2, x3, y3, x, y)) printf("The point is inside the triangle!\n");
    else printf("The point is not inside the triangle!\n");
    return 0;
}
