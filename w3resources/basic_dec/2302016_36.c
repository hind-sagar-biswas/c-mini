#include <stdio.h>
#include <string.h>
#define PASS "1234"
int main() {
	char pass[32];
	while (1) {
		printf("Enter the correct password: ");
		scanf("%s", pass);
		if (!strcmp(pass, PASS)) break;
		else printf("Wrong Password! ");
	}
	printf("Correct Password!\n");
	return 0;
}
