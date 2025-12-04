#include <stdio.h>

int main() {
    int n;
    printf("Введіть n: ");
    scanf("%d", &n);

    // зростання
    printf("%d! = ", n);
    for (int i = 1; i <= n; i++) {
        printf("%d", i);
        if (i < n) {
            printf("*");
        }
    }
    printf("\n");

    //спадання
    printf("%d! = ", n);
    for (int i = n; i >= 1; i--) {
        printf("%d", i);
        if (i > 1) {
            printf("*");
        }
    }
    printf("\n");

    return 0;
}