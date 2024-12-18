#include <stdio.h>
#define SIZE 5
float prices[SIZE] = {2000.01, 1200.01, 800.01, 400.01, 100.01};
int rates[SIZE] = {3, 6, 9, 11, 14};
int main() {
	float price, new_price;
	short int i = 0;
	scanf("%f", &price);

	for (; i < SIZE && price < prices[i]; i++) {}

	if (i == SIZE) {
		printf("Invalid price\n");
	} else {
		new_price = price + price * rates[i] / 100;
		printf("New Item Price: %.2f\n", new_price);
		printf("Increased Item Price: %.2f\n", new_price - price);
		printf("Increase Rate: %d%%\n", rates[i]);
	}

	return 0;
}
