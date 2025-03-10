#include <stdio.h>
int main(void) {
	int input, prvious[100], non_dup = 1, index = 0;

	while (non_dup && index < 100) {
		printf("Enter a number [duplicate to stop]: ");
		scanf("%d", &input);
		int i;
		for (i = 0; i < index; i++) {
			if (prvious[i] == input) {
				printf("Duplicate number!\n");
				break;
			}
		}
		if (i == index) prvious[index++] = input;
	}

	return 0;
}
