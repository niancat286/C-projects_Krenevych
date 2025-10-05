#include <stdio.h>
#include <math.h>

int main() {
    double x, eps;
    double term, sum = 0.0;
    int n = 0;
    int sign = 1;

    printf("Введіть x (|x| < 1): ");
    scanf("%lf", &x);

    printf("Введіть точність eps (> 0): ");
    scanf("%lf", &eps);

    term = 1.0;
    sum = term;

    while (fabs(term) >= eps) {
        n++;
        sign = -sign;
        term = sign * ((n + 1.0) * (n + 2.0) / 2.0) * pow(x, n);
        if (fabs(term) < eps) break;
        sum += term;
    }

    printf("Сума членів ряду (з точністю eps): %.10f\n", sum);
    printf("Кількість доданків: %d\n", n + 1);

    return 0;
}
