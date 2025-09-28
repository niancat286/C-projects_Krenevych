#include <stdio.h>
#include <math.h>


double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double triangle_area(double a, double b, double c) {
    double p = (a + b + c) / 2.0;  // півпериметр
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    printf("A(x1 y1): ");
    scanf("%lf %lf", &x1, &y1);

    printf("B(x2 y2): ");
    scanf("%lf %lf", &x2, &y2);

    printf("C(x3 y3): ");
    scanf("%lf %lf", &x3, &y3);

    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x3, y3, x1, y1);

    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("triangle doesn't exist\n");
        return -1;
    }
    double area = triangle_area(a, b, c);

    printf("a=%.4f, b=%.4f, c=%.4f\n", a, b, c);
    printf("S = %.6f\n", area);

    return 0;
}