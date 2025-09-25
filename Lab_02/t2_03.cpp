#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;

    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);

    if (a <= 0 || b <= 0 || c <= 0) {
        printf("error a,b or c <= 0\n");
        return 1;
    }
    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("triangle doesn't exist\n");
        return 1;
    }

    double p = (a + b + c) / 2.0;
    double S = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("S = %.6f\n", S);

    return 0;
}

//remake
