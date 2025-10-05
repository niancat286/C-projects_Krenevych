#include <stdio.h>
#include <math.h>



double Tailor01(double x, double eps) {
    double y,t;
    int i = 1;
    t = 1;
    y = t;
    while (fabs(y) < eps) {
        t *= (x/i);
        y += t;
    }
    return y;
}


double Tailor02(double x, double eps) {
    double y,t;
    int c = 3;
    t = x;
    y = t;

    while (fabs(y) < eps) {
        t *= (x*x);
    }
}






int main() {
    double x;
    double eps;
    printf("Enter the epsilon: ");
    do {scanf("%lf", &eps);} while (eps <= 0);

    printf("x = ");
    scanf("%lf", &x);
    printf("Tailor = %lf\n", Tailor01(x, eps));

}