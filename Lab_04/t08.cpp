#include <stdio.h>

int main() {
    int m, k;
    printf("Enter number m: ");
    scanf("%d", &m);

    if (m < 1) return 0;

    k = 0;
    int r = 1; // 4^0 = 1
    while (r * 4 <= m) {
        r *= 4;
        k++;
    }

    printf("k = %d\n", k);
    return 0;
}
