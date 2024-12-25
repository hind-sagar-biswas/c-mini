#include <stdio.h>
void insersion_sort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i - 1, temp = arr[i];
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}
int main()
{
	int arr[8];
	printf("Input heights(integer values) of the top eight buildings:\n");
	for (int i = 0; i < 8; i++) scanf("%d", &arr[i]);
	insersion_sort(arr, 8);
	printf("Heights of the top three building:\n%d\n%d\n%d\n", arr[7], arr[6], arr[5]);
	return 0;
}
