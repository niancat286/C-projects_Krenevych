#include <stdio.h>

int main() {
    double m, v;
    printf("Please enter mass: ");
    scanf("%lf", &m);
    printf("Please enter velocity: ");
    scanf("%lf", &v);

    double res = (m * v * v)/2;
    printf("Kinetic energy = %.2lf\n", res);
}