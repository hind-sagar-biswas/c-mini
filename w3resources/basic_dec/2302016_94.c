#include <stdio.h>

float BMI(float weight, float height);

int main() {
	float w, h, bmi;
	scanf("%f %f", &w, &h);
	bmi = BMI(w, h);
	printf("BMI: %.2f\n", bmi);
	if (bmi < 18.5) printf("Underweight\n");
	else if (bmi < 25) printf("Normal weight\n");
	else if (bmi < 30) printf("Overweight\n");
	else printf("Obesity\n");
	return 0;
}

float BMI(float weight, float height) {
	return weight / (height * height);
}