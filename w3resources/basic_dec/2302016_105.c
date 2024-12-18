#include <stdio.h>
int main () {
    float x, p_avg = 0, n_avg = 0, sum_p = 0, sum_n = 0;
    int i, p_ctr = 0, n_ctr = 0;
    printf("Input 7 numbers(int/float):\n");
    for (i = 0; i < 7; i++){
        scanf("%f", &x);
        if (x > 0){
            p_ctr++;
            sum_p += x;
        }
        if (x < 0){
            n_ctr++;
            sum_n += x;
        }
    }
    p_avg = sum_p/p_ctr;
    n_avg = sum_n/n_ctr;
    if (p_ctr > 0){
        printf("\n%d Number of positive numbers: ", p_ctr);
        printf("Average %.2f\n", p_avg);
    }
    if (n_ctr > 0){
        printf("\n%d Number of negative numbers: ", n_ctr);
        printf("Average %.2f\n", n_avg);
    }
    return 0;
}
