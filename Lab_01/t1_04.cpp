/*
 *input m1, m2 - masses of objects
 *input r - distance
 * calculate force of gravity
 */


#include <stdio.h>
#include <math.h>


int main() {
    double m1, m2, r, G, force;

    printf("input m1:");
    scanf("%lf", &m1);

    printf("input m2:");
    scanf("%lf", &m2);

    printf("input r:");
    scanf("%lf", &r);

    G = 6.67e-11;

    force = G * m1 * m2 / pow(r, 2);

    printf("force = %e\n", force);
    return 0;

}
