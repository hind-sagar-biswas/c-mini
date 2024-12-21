#include <stdio.h>
#include <string.h>
int main()
{
	char str1[100], str2[100];
	printf("Enter the first string: ");
	scanf("%s", str1);
	printf("Enter the second string: ");
	scanf("%s", str2);
	int str1_len = strlen(str1), str2_len = strlen(str2);
	if (str1_len < str2_len) printf("Not Present!\n");
	else if (!strcmp(&str1[str1_len - str2_len], str2)) printf("Present!\n");
	else printf("Not Present!\n");
	return 0;
}
