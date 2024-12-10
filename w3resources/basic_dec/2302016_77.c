#include <stdio.h>
int main() {
	float principal = -1, rate, time;
	while (principal != 0) {
		printf("Principal, Rate and Days [0 to exit]: ");
		scanf("%f %f %f", &principal, &rate, &time);
		printf("Interest: %f$", principal * rate * time / 365 / 100);
	}
	return 0;
}
