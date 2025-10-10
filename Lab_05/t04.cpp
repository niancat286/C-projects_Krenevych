#include <stdio.h>


unsigned long long Mult01(unsigned long long n) {
    unsigned long long p = 1, q = 1;
    for (int i = 1; i <= n; i++) {
        p /= i;
        q *= (1+p);
    }
    return q;
}


int main() {
    unsigned long long n = 3;

    printf("%llu\n", Mult01(n));
    return 0;
}



