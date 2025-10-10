#include <stdio.h>


unsigned long long Min_Pos_in_seq() {
    long long x1 = -99, x2 = -99, x3 = -99, x;
    long long n = 3;
    while (x <= 0){
        x = x3 + x1 + 100;
        x1 = x2;
        x2 = x3;
        x3 = x;
        n ++;
    }
    printf("x = %lld\n", x);
    return n;
}


int main() {
    printf("n = %llu\n", Min_Pos_in_seq());
    return 0;
}