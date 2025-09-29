#include <stdio.h>
#include <math.h>

double exp_tail(double x, unsigned n) {
    double y = 1;
    double t = 1;
    for (unsigned i = 1; i <= n; i++) {
        t += x/i;
        y += t;
    }
    return y;

}

int main() {
    double x;
    unsigned n;
    printf("Enter number x \n");
    scanf("%lf", &x);
    while (fabs(x) >= 1) {
        printf("Enter number n \n");
        scanf("%u", &n);
        double res = exp_tail(x, n);
        printf("The result is %lf\n", res);
    }


    return 0;
}