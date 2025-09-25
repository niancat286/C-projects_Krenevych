#include <stdio.h>
#include <math.h>

int poly_a(int x, int n) {
    int sum = 0;
    for (int i = n; i >= 0; i--) {
        sum += (int)pow(x, i);
    }
    return sum;
}

int poly_b(int x, int y, int n) {
    int sum = 1; // останній доданок "1"
    for (int i = 1; i <= n; i++) {
        sum += (int)pow(x, 2*i) * (int)pow(y, i);
    }
    return sum;
}

int main() {
    int n1 = 3, x1 = 2;
    int result_a = poly_a(x1, n1);
    printf("a) y = %d (при n=%d, x=%d)\n", result_a, n1, x1);

    int n2 = 4, x2 = 1, y2 = 2;
    int result_b = poly_b(x2, y2, n2);
    printf("b) y = %d (при n=%d, x=%d, y=%d)\n", result_b, n2, x2, y2);

    return 0;
}
