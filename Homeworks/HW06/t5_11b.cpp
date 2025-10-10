#include <stdio.h>

int main() {
    int n;
    printf("n= ");
    scanf("%d", &n);

    float a1 = 1., a2 = 1., ak, suma = 12., p = 27.;

    if (n == 1) {
        printf("suma = 3");
    }
    else if (n == 2) {
        printf("suma = 12");
    }
    else {
        for (int i = 3; i <= n; i++) {
            ak = a2/i + a1;

            a2 = ak;
            a1 = a2;


            suma += p / ak;
            p *= 3;
        }
        printf("suma = %f\n", suma);
    }
    return 0;
}