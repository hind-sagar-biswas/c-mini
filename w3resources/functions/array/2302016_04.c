#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n], b[n];

	for(int i=0;i<n;i++) scanf("%d", &a[i]);

	for(int i=0;i<n;i++) b[i] = a[i];

	printf("Elements of a are: ");
	for(int i=0;i<n;i++) printf("%d ", a[i]);
	printf("\n");

	printf("Elements of b are: ");
	for(int i=0;i<n;i++) printf("%d ", b[i]);
	printf("\n");

	return 0;
}
