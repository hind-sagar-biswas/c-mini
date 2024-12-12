#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <stdbool.h>
int main(void) {
    printf("\n");
    printf("%-20s %-20s\n", "Type", "Range");
    printf("------------------------------------------------------\n");
    printf("%-20s %23d to %-20d\n", "char", CHAR_MIN, CHAR_MAX);
    printf("%-20s %23d to %-20d\n", "int8_t", INT8_MIN, INT8_MAX);
    printf("%-20s %23d to %-20d\n", "unsigned char", 0, UCHAR_MAX);
    printf("%-20s %23d to %-20d\n", "uint8_t", 0, UINT8_MAX);
    printf("%-20s %23d to %-20d\n", "short", SHRT_MIN, SHRT_MAX);
    printf("%-20s %23d to %-20d\n", "int16_t", INT16_MIN, INT16_MAX);
    printf("%-20s %23d to %-20d\n", "uint16_t", 0, UINT16_MAX);
    printf("%-20s %23d to %-20d\n", "int", INT_MIN, INT_MAX);
    printf("%-20s %23u to %-20u\n", "unsigned", 0, UINT_MAX);
    printf("%-20s %23ld to %-20ld\n", "long", LONG_MIN, LONG_MAX);
    printf("%-20s %23lu to %-20lu\n", "unsigned long", 0UL, ULONG_MAX);
    printf("%-20s %23d to %-20d\n", "int32_t", INT32_MIN, INT32_MAX);
    printf("%-20s %23u to %-20u\n", "uint32_t", 0, UINT32_MAX);
    printf("%-20s %23lld to %-20lld\n", "long long", LLONG_MIN, LLONG_MAX);
    printf("%-20s %23llu to %-20llu\n", "int64_t", 0LL, ULLONG_MAX);
    printf("%-20s %23lld to %-20lld\n", "int64_t", LLONG_MIN, LLONG_MAX);
    printf("%-20s %23llu to %-20llu\n", "uint64_t", 0ULL, ULLONG_MAX);
    printf("%-20s %23u to %-20u\n", "bool", 0, 1);
    printf("\n");
    return 0;
}
