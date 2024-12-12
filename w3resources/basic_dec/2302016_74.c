#include <stdio.h>
int main() {
	char* letters = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	printf("List of integer equivalents of letters (a-z, A-Z).");
	printf("\n==================================================\n");
	for (int i = 0; i < 52; i++) printf("%d ", letters[i]);
	printf("\n==================================================\n");
	return 0;
}
