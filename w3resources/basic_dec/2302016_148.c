#include<stdio.h>
int main() {
    int n, matrix[11][11] = {0};
    printf("Input number of rows/columns (1-10):\n"); 
    scanf("%d", &n);

    if (n < 1 || n > 10) return printf("Invalid Number!\n"), 0;

    for (int i = 0; i < n; i++) {
	printf("\nRow %d input cell values\n", i+1);
	for (int j = 0; j < n; j++) {
	    scanf("%d", &matrix[i][j]);
	    matrix[i][n] += matrix[i][j];
	}
	printf("\n");
    }

    for (int i = 0; i <= n; i++) {
	for (int j = 0; j < n; j++) matrix[n][i] += matrix[j][i];
    }

    printf("Result:\n");
    for(int i = 0; i <= n; i++) {
      for(int j = 0; j <= n; j++) printf("%5d", matrix[i][j]);
      printf("\n");
    }

    return 0;
}

