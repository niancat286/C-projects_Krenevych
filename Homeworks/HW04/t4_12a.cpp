#include <stdio.h>
#include <math.h>


double polynomial(double x, int n) {
    double y = 1.0;
    for (int k = 2; k <= 2*n; k++) {
        y += pow(x, k);
    }
    return y;
}


int main() {
    double x;
    int n;
    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter n: ");
    scanf("%d", &n);

    double result = polynomial(x, n);
    printf("y = %lf\n", result);

    return 0;
}