#include <stdio.h>


unsigned long long Fib(int n) {
    unsigned long long f0, f1, f;
    f0 = 0;
    f1 = 1;
    for (int i = 2; i <= n; i++) {
        f = f0 + f1;
        f0 = f1;
        f1 = f;
    }
    return f;
}


unsigned long long largestFibIndexLE(long long a) {
    long long f0 = 0, f1 = 1, f;
    int n = 1;
    while (f1 <= a) {
        f = f0 + f1;
        f0 = f1;
        f1 = f;
        n++;
    }
    return n - 1;
}


unsigned long long smallestFibIndexGT(long long a) {
    long long f0 = 0, f1 = 1, f;
    int n = 1;
    while (f1 <= a) {
        f = f0 + f1;
        f0 = f1;
        f1 = f;
        n++;
    }
    return n;
}



long long sumFibLE1000() {
    long long f0 = 0, f1 = 1, f, sum = 1;
    while (f1 <= 1000) {
        f = f0 + f1;
        f0 = f1;
        f1 = f;
        if (f1 <= 1000) sum += f1;
    }
    return sum;
}



int main() {
    printf("f = %llu\n", Fib(10));
    long long a = 100;
    printf("n = %llu\n", largestFibIndexLE(a));
    printf("sum = %llu\n", sumFibLE1000());

    printf("sum less 1000 = %llu\n", sumFibLE1000());

    return 0;
}