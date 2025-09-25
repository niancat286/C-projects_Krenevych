#include <stdio.h>
#include <math.h>


double Rosenbrock2d(double x, double y) {
    return 100 * pow((x * x - y), 2) + pow((x - 1), 2);
}


int main() {
    double x1 = 1.0, y1 = 1.0;
    double x2 = -1.2, y2 = 1.0;
    double x3 = 0.5, y3 = 0.25;

    printf("Rosenbrock2d(%.2f, %.2f) = %.6f\n", x1, y1, Rosenbrock2d(x1, y1));
    printf("Rosenbrock2d(%.2f, %.2f) = %.6f\n", x2, y2, Rosenbrock2d(x2, y2));
    printf("Rosenbrock2d(%.2f, %.2f) = %.6f\n", x3, y3, Rosenbrock2d(x3, y3));

    return 0;
}

//remake
