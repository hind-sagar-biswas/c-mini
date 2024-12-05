#include <stdio.h>

int main() {
	char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	unsigned int month;
	scanf("%u", &month);
	printf("%s", months[month - 1]);
	return 0;
}
