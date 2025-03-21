#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n], b[n], c[n + n];

	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	for(int i=0;i<n;i++) scanf("%d", &b[i]);

	for(int i=0;i<n;i++) c[i] = a[i];
	for(int i=0;i<n;i++) c[i + n] = b[i];

	printf("Elements of c are: ");
	for(int i=0;i<n*2;i++) printf("%d ", c[i]);
	printf("\n");

	return 0;
}
