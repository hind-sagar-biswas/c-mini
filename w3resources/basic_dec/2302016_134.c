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
int main()
{
	int sides[3];
	scanf("%d %d %d", &sides[0], &sides[1], &sides[2]);
	insertion_sort(sides, 3);
	short is_right = (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2]);
	if (is_right) printf("Right angled triangle\n");
	else printf("Not right angled triangle\n");
	return 0;
}
