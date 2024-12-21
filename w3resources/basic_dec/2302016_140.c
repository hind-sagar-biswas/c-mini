#include<stdio.h>
int main() {
    int freq[101] = {0}, n;
    while (scanf("%d", &n) != EOF) {
	if (n < 0 || n > 100) printf("Invalid number! Must be between 0 and 100\n");
	else freq[n]++;
    }

    int max_freq = 0;
    for (int i = 0; i < 101; i++) if (freq[i] > max_freq) max_freq = freq[i];
    for (int i = 0; i < 101; i++) if (freq[i] == max_freq) printf("%d ", i);
    printf("\n");
    return 0;
}
