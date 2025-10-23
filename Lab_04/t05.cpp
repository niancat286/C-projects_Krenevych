#include <stdio.h>
#include <math.h>


unsigned long long dbl_factorial(unsigned n) {
    unsigned long long y = 1;
    for (unsigned i = n; i > 0; i -= 2) {
        y *= i;
    }
    return y;
}


int main() {
    unsigned n;
    printf("Enter number n: \n");
    scanf("%u", &n);
    unsigned long long x = dbl_factorial(n);
    printf("res = %llu\n", x);
    return 0;
}