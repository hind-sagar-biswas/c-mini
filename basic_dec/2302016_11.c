#include <stdio.h>
struct Item {
	int count;
	float weight;
};
int main() {
	struct Item i1, i2;
	printf("Enter weight & count of item 1: ");
	scanf("%f %d", &i1.weight, &i1.count);
	printf("Enter weight & count of item 2: ");
	scanf("%f %d", &i2.weight, &i2.count);
	printf("Average: %f", (i1.weight * i1.count + i2.weight * i2.count) / (i1.count + i2.count));
	return 0;
}
