#include<stdio.h>
int main() {
    char s[100];
    long sum = 0, n;
    printf("Enter number of sentences: ");
    scanf("%ld", &n);
    printf("Enter sentences:\n");
    for (int i = 0; i <= n; i++) {
	fgets(s, sizeof(s), stdin);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] > '0' && s[i] <= '9') sum += s[i] - '0';
	}
    }
    printf("Sum: %ld", sum);
    return 0;
}

