#include <stdio.h>
void insertion_sort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i - 1, temp = arr[i];
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}
void print_array(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	int arr[3], sorted[3];
	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < 3; i++) sorted[i] = arr[i];
	insertion_sort(sorted, n);
	printf("Original array: ");
	print_array(arr, n);
	printf("Sorted array: ");
	print_array(sorted, n);
	return 0;
}
