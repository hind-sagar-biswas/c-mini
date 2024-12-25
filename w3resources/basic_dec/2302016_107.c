
#include <stdio.h>
int main () 
{
	int n;
	scanf("%d", &n);
	short int is_odd = n % 2;
	printf("\nNext 10 consecutive odd numbers:\n");
	for(int i = n + is_odd + 1, ctr = 0; ctr < 10; i += 2, ctr++) printf("%d ", i);
	printf("\n");
	printf("\nNext 10 consecutive even numbers:\n");
	for(int i = n + !is_odd + 1, ctr = 0; ctr < 10; i += 2, ctr++) printf("%d ", i);
	printf("\n");
}

