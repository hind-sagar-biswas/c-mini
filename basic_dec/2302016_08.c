#include <stdio.h>

int main() {
	int days = 1329, years, weeks, remainder;
	years = days / 365;
	remainder = days % 365;
	weeks = remainder / 7;
	days = remainder % 7;
	printf("Years: %d\nWeeks: %d\nDays: %d\n", years, weeks, days);
	return 0;
}
