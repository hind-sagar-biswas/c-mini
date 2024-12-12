#include <stdio.h>
#define STEP 10
int main() {
	float f_temp, c_temp;
	float start_temp, end_temp;

	start_temp = 0;
	end_temp = 150;

	printf("Fahrenheit to Celsius");
	printf("\n---------------------\n");
	printf("Fahrenheit  Celsius\n");

	while (start_temp <= end_temp) {
		f_temp = start_temp * 9 / 5 + 32;
		printf("%6.1f \t %8.1f\n", start_temp, f_temp);
		start_temp += STEP;
  	}

	start_temp = 0;
	end_temp = 150;

	printf("\n\nCelsius to Fahrenheit\n");
	printf("---------------------\n");
	printf("Celsius   Fahrenheit\n");
	
	while (start_temp<= end_temp) {
    	c_temp = (start_temp - 32) * 5 / 9;
		printf("%6.1f \t %8.1f\n", start_temp, c_temp);
		start_temp += STEP;
  	}
}