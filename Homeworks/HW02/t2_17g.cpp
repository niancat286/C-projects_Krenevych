#include <stdio.h>
#include <math.h>



// ж) invsqrt(x, α) = x / sqrt(1 + α x^2)
double invsqrt(double x, double alpha) {
    return x / sqrt(1.0 + alpha*x*x);
}
double invsqrt_derivative(double x, double alpha) {
    return 1.0 / pow(1.0 + alpha*x*x, 1.5);
}


int main() {
    double x = 1.0;
    double alpha = 2.0;
    printf("invsqrt(%.2f, %.2f) = %f, invsqrt'(%.2f, %.2f) = %f\n",
               x, alpha, invsqrt(x,alpha), x, alpha, invsqrt_derivative(x,alpha));
    return 0;
}


