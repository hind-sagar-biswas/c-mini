#include <stdio.h>

int main() {
	int days, years, months, remainder;
	scanf("%d", &days);
	years = days / 365;
	remainder = days % 365;
	months = remainder / 30;
	days = remainder % 30;
	printf("Years: %d\nMonths: %d\nDays: %d\n", years, months, days);
	return 0;
}

