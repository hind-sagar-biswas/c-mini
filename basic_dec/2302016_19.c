#include <stdio.h>

int main() {
	int p, q, r, s;
	scanf("%d %u %u %u", &p, &q, &r, &s);
	printf("%s values\n", (q > 0 && r > 0 && s > 0 && p % 2 == 0 && (q > r) && (s > p) && ((r+s) > (p+q))) ? "Correct" : "Wrong");
	return 0;
}

