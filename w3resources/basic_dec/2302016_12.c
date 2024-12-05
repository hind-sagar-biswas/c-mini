#include <stdio.h>

int main() {
	int id, hours, amount;
	printf("Enter ID, hours and amount: ");
	scanf("%d %d %d", &id, &hours, &amount);
	printf("ID: %d\nSalary: %.2f", id, (float) hours * amount);
	return 0;
}
