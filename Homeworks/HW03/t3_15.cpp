#include <stdio.h>
#include <math.h>


int main() {
    double v, u, r;
    double a, b, c;
    double d;

    printf("Введіть центр кола (v, u) та радіус r: ");
    scanf("%lf %lf %lf", &v, &u, &r);

    printf("Введіть коефіцієнти прямої (a, b, c): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    d = fabs(a*v + b*u + c)/ sqrt(a*a + b*b);

    if (fabs(d - r) < 1e-9) {
        printf("Пряма дотична: одна точка дотику.\n");
    } else if (d < r) {
        printf("Пряма перетинає коло: дві точки перетину.\n");
    } else {
        printf("Пряма не має спільних точок з колом.\n");
    }

    return 0;
}