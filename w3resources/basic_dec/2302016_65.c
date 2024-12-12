#include <stdio.h>
#include <stdbool.h>
bool is_prime(int num) {
    if (num <= 1) return false;
    if (num == 2)  return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
	int count = 0;
	for (int i = 1; i < 200; i++) {
		if (!is_prime(i)) continue;
		printf("%3d ", i);
		count++;
		if (!(count%20)) printf("\n");
	}
	return 0;
}
