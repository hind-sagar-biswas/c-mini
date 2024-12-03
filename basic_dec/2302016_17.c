#include <stdio.h>

int main() {
	int seconds, hours, minutes;
	printf("Seconds: ");
	scanf("%d", &seconds);
	hours = seconds / 3600;
	minutes = (seconds % 3600) / 60;
	seconds = (seconds % 3600) % 60;
	printf("H:M:S - %d:%d:%d", hours, minutes, seconds);
	return 0;
}
