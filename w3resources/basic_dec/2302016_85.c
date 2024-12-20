#include <stdio.h>
int nums[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
char *roman[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
void int_to_roman(int n);
int main() {
	int limit;
	scanf("%d", &limit);
	for (int i = 1; i <= limit; i++) {
		printf("%d\t", i);
		int_to_roman(i);
		printf("\n");
	}
	return 0;
}
void int_to_roman(int n) {
	int highest = 0;
	for (int i = 0; i < 13; i++) {
		if (n >= nums[i]) highest = i;
		else break;
	}
	while (n) {
		printf("%s", roman[highest]);
		n -= nums[highest];
		while (highest > 0 && n < nums[highest]) highest--;
	}
}
