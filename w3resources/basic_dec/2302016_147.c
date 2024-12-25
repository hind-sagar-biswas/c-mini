#include <stdio.h>
#include <stdlib.h>
#define check_num(x) (x>0?x:0)
int main(void) {
	int n, result = 0, x;
	scanf("%d", &n);
	for (x = check_num(n - 2000); x <= 2000 && n >= x; x++) {
		result += (1001 - abs(1000 - (n - x))) * (1001 - abs(1000 - x));
	}
	printf("%d\n", result);
	return 0;
}
