#include <stdio.h>
#include <math.h>

int main() {
    double x;
    int i = 0;

    double sum = 0;
    long long count = 0;
    long long sum_int = 0;
    double product = 1;

    while (1) {
        printf("a[%d]= ", i);
        scanf("%lf", &x);

        if (fabs(x) < 1e-12) break;

        sum += x;

        if ((long long)x == x) {
            int xi = (int)x;
            sum_int += xi;
            product *= xi;
            count++;
        }
        i++;
    }

    printf("\nСума введених дійсних чисел = %.2lf\n", sum);

    if (count > 0) {
        double avg_arith = (double)sum_int / count;
        double avg_geom = pow(product, 1.0 / count);

        printf("Середнє арифметичне цілих чисел = %.2lf\n", avg_arith);
        printf("Середнє геометричне цілих чисел = %.2lf\n", avg_geom);
    } else {
        printf("Не було введено цілих ненульових чисел.\n");
    }

    return 0;
}
