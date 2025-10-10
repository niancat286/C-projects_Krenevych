#include <stdio.h>



int main() {
    int i, j, k ,n;
    double a1 = 0, a2 = 1, a, b1 = 1, b2 = 0, b, S, p = 4;

    printf("n = \n");
    scanf("%d", &n);
    if (n == 1) {
        printf("S = %lf\n", 2.0);
    }
    else if (n == 2) {
        printf("S = %lf\n", 6.0);
    }
        else {
            S = 6;
            for (k =3; k <= n; k++) {
                b = b2 + a2;
                a = a2 / k + a1*b;

                a1 = a2;
                a2 = a;
                b1 = b2;
                b2 = b;
                p *= 2;
                S += p/(a+b);
            }
        }
    printf("S = %lf\n", S);
}