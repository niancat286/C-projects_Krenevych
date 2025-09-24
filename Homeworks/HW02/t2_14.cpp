#include <float.h>
#include <stdio.h>
#include <math.h>


void quadratic() {
    double a,b,c;
    printf("a, b, c for ax^2 + bx + c = 0:\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (fabs(a) < 2 * DBL_EPSILON) {
        if (fabs(b) < 2 * DBL_EPSILON) {
            if (fabs(c) < 2 * DBL_EPSILON) {
                printf("Infinite sols\n");
            }
            else {
                printf("No sols\n");
            }
        }
        else {
            printf("One sol\n x = %lf ", -b/c);
        }
    }
    else {
        double D = b * b - 4 * a * c;
        if (D < DBL_EPSILON) {
            printf("no sols\n");
            return;
        }
        if (fabs(D) == DBL_EPSILON) {
            printf("one sol\n");
            double res1 = (-b - sqrt(D)) / (2 * a);
            printf("res1 = %lf\n", res1);
        }
        else {
            printf("two sols\n");
            double res1 = (-b - sqrt(D)) / (2 * a);
            double res2 = (-b + sqrt(D)) / (2 * a);
            printf("res1 = %lf\n", res1);
            printf("res2 = %lf\n", res2);
        }
    }

}


int main() {
    quadratic();
}