#include <stdio.h>

typedef int marks;

void one() {
	int n;
	scanf("%d", &n);
	for (float i = 1; i <= n; i++) {
		printf("%f\n", 1/i);
	}
}

void two() {
	float rice, sugar;
	scanf("%f %f", &rice, &sugar);
	printf("Item\tPrice\n");
	printf("Rice\t%.2f\n", rice);
	printf("Sugar\t%.2f\n", sugar);
}

void three() {
	int n[5], positives = 0, negatives = 0;
	scanf("%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &n[4]);
	for (int i = 0; i < 5; i++) {
		if (n[i] > 0) positives++;
		else if (n[i] < 0) negatives++;
	}
	printf("Positives: %d\nNegatives: %d\n", positives, negatives);
}

void four() {
	int x, y;
	short z;
	scanf("%d %d", &x, &y);
	z = x+y;
	printf("%hd", z);
}

void five() {
	marks mark_of_one = 56;
}

void six() {

}

void seven() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < 11; i++) printf("%d x %d = %d\n", n, i, n*i);
}

void eight() {
	int n;
	scanf("%d", &n);
	printf("%d", n*n);
}

void nine() {
	for (int i = 0; i < 129; i++) printf("%c", i);
}

void ten() {
	int days, years, weeks, remainder;
	scanf("%d", &days);
	years = days / 365;
	remainder = days % 365;
	weeks = remainder / 7;
	days = remainder % 7;
	printf("Years: %d\nWeeks: %d\nDays: %d\n", years, weeks, days);
}

void eleven() {
	float distance, fuel;
	printf("Distance (km) & fuel (L): ");
	scanf("%f %f", &distance, &fuel);
	printf("Average Consumption: %.2f km/L", distance / fuel);
}

void tweleve() {
	int amount;
	int notes[7] = { 100, 50, 20, 10, 5, 2, 1 };
	scanf("%d", &amount);
	for (int i = 0; i < 7; i++) {
		printf("%6.2f: %d Note(s)\n", (float) notes[i], amount / notes[i]);
		amount = amount % notes[i];
	}
}

int main() {
	return 0;
}
