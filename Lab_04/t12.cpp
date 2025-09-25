#include <stdio.h>

int main() {
    int n;
    printf("n (n < 25): ");
    scanf("%d", &n);

    if (n < 0 || n >= 25) {
        printf("incorrect n!\n");
        return 0;
    }

    double sum = 0.0;
    double term = 1.0;
    int sign = 1;

    for (int k = 0; k <= n; k++) {
        sum += sign * term;
        sign = -sign;
        term /= (k+1);
    }

    double res = sum;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }

    printf("!%d = %.0lf\n", n, res);

    return 0;
}
