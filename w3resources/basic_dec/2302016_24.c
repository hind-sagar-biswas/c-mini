#include <stdio.h>
int min(int a, int b) {return a < b ? a : b;}
int max(int a, int b) {return a > b ? a : b;}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%s\n", max(a, b) % min(a, b) ? "Not Multiplied!" : "Multiplied!");
	return 0;
}