#include<stdio.h>
#include <stdbool.h>
struct Coordinate
{
    int x;
    int y;
};
float getSlope(struct Coordinate p1, struct Coordinate p2)
{
    return (p2.y - p1.y) / (float) (p2.x - p1.x);
}
int main() {
    struct Coordinate p, q, r, s;
    printf("Input P(x1,y1): ");
    scanf("%d %d", &p.x, &p.y);
    printf("Input Q(x2,y2): ");
    scanf("%d %d", &q.x, &q.y);
    printf("Input R(x3,y3): ");
    scanf("%d %d", &r.x, &r.y);
    printf("Input S(x4,y4): ");
    scanf("%d %d", &s.x, &s.y);

    if (getSlope(p, q) == getSlope(r, s)) printf("The lines PQ and RS are parallel.\n");
    else printf("The lines PQ and RS are not parallel.\n");
    return 0;
}
