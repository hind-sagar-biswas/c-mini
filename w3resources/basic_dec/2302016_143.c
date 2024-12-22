#include<stdio.h>
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
int main() {
    int input, min = 0, max = 0, stream[8];
    scanf("%d", &input);
    for (int i = 0; input; i++) {
        stream[i] = input % 10;
        input /= 10;
    }
    insertion_sort(stream, 8);
    for (int i = 0; i < 8; i++) {
        min = min * 10 + stream[i];
        max = max * 10 + stream[7 - i];
    };
    printf("%d - %d = %d", max, min, max - min);
    return 0;
}

