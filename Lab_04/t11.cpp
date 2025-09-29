#include <stdio.h>
#include <math.h>

int main() {
    double x, sum_real = 0;
    int i = 0;

    printf("Введення дійсних чисел (завершується, якщо введено 0):\n");

    while (1) {
        printf("a[%d]= ", i);
        scanf("%lf", &x);

        if (fabs(x) < 1e-12) break;

        sum_real += x;
        i++;
    }

    printf("\nСума введених дійсних чисел = %.2lf\n", sum_real);

    int y, count = 0;
    long long sum_int = 0;
    double product = 1;

    printf("\nВведення цілих ненульових чисел (завершується при 0):\n");

    while (1) {
        printf("b[%d]= ", count);
        if (scanf("%d", &y) == 1) {
            if (y == 0) break; 

            sum_int += y;
            product *= y;
            count++;
        }
        else  {
            printf("Це НЕ ціле число (має дробову частину).\n");
            sum_int -= y;
            product /= y;
            count--;
            break;
        }
    }

    if (count > 0) {
        double avg_arith = (double)sum_int / count;
        double avg_geom = pow(product, 1.0 / count);

        printf("\nСереднє арифметичне цілих чисел = %.2lf\n", avg_arith);
        printf("Середнє геометричне цілих чисел = %.2lf\n", avg_geom);
    } else {
        printf("\nНе було введено цілих ненульових чисел.\n");
    }

    return 0;
}
