#include <stdio.h>
#include <math.h>

int main() {
    int n, x;
    printf("Введіть n: ");
    scanf("%d", &n);
    printf("Введіть x: ");
    scanf("%d", &x);

    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * (long long)pow(x, i);
    }

    printf("Результат: %lld\n", sum);

    return 0;
}