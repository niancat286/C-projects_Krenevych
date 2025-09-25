#include <stdio.h>

int main() {
    long long n;
    printf("Enter number n: ");
    scanf("%lld", &n);

    long long result = 0;
    long long place = 1;

    while (n > 0) {
        int digit = n % 10;
        if (digit != 0 && digit != 5) {
            result = result + digit * place;
            place *= 10;
        }
        n /= 10;
    }

    printf("Result: %lld\n", result);
    return 0;
}
