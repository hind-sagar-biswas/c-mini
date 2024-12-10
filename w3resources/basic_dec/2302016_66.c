
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandNum(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int main() {
	FILE* fptr;
	fptr = fopen("ran.dat", "w");
	if (fptr == NULL) {
		printf("Faled to create/open file `ra.dat`");
		exit(0);
	}
	fprintf(fptr, "50\n");
	srand(time(NULL));
	for (int i = 0; i < 50; i++)
	{
		double rand_val = (float) generateRandNum(-50000, 50000) / 100000;
		fprintf(fptr, "%.3f\n", rand_val);
	}
	fclose(fptr);
	return 0;
}
