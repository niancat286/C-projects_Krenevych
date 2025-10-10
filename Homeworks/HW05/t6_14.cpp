#include <stdio.h>

void ver1() {
    unsigned int n;
    printf("Введіть натуральне число: ");
    scanf("%u", &n);

    unsigned int x = 1;

    while (x < n) {
        x <<= 1;
    }

    if (x == n)
        printf("%u є ступенем двійки.\n", n);
    else
        printf("%u не є ступенем двійки.\n", n);

}

void ver2() {
    unsigned int n;
    printf("Введіть натуральне число: ");
    scanf("%u", &n);

    if (n != 0 && (n & (n - 1)) == 0)
        printf("%u є ступенем двійки.\n", n);
    else
        printf("%u не є ступенем двійки.\n", n);
}

int main() {
    ver1();
    ver2();
}