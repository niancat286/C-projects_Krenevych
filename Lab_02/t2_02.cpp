#include <stdio.h>
#include <math.h>

int main() {
    double a, b;
    printf("Введіть катет a: ");
    scanf("%lf", &a);
    printf("Введіть катет b: ");
    scanf("%lf", &b);

    if (a <= 0 || b <= 0) {
        printf("error, a or b <= 0\n");
        return -1;
    }

    double c = sqrt(a * a + b * b);
    printf("Гіпотенуза c = %.6f\n", c);

    return 0;
}