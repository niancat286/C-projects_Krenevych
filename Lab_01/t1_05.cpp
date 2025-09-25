#include <stdio.h>

int main() {
    int y;
    printf("y=\n");
    scanf("%d", &y);

    int z;

    // x^4 за 2 операції
    z = y * y;       // y^2
    z = z * z;       // (y^2)^2 = y^4
    printf("%d^4 == %d\n", y, z);

    // x^6 за 3 операції
    int y2 = y * y;  // 1: y^2
    int y4 = y2 * y2; // 2: y^4
    z = y4 * y2;     // 3: y^6
    printf("%d^6 == %d\n", y, z);

    // x^9 за 4 операції
    y2 = y * y;      // 1: y^2
    int y3 = y2 * y; // 2: y^3
    int y6 = y3 * y3; // 3: y^6
    z = y6 * y3;     // 4: y^9
    printf("%d^9 == %d\n", y, z);

    // x^15 за 5 операцій
    y2 = y * y;      // 1: y^2
    y3 = y2 * y;     // 2: y^3
    y6 = y3 * y3;    // 3: y^6
    int y12 = y6 * y6; // 4: y^12
    z = y12 * y3;    // 5: y^15
    printf("%d^15 == %d\n", y, z);

    // x^28 за 6 операцій
    y2 = y * y;       // 1: y^2
    y4 = y2 * y2;     // 2: y^4
    long y7 = y4 * y3; // 3: y^7
    long y14 = y7 * y7; // 4: y^14
    long y28 = y14 * y14; // 5: y^28
    z = y28;          // (усього 6 множень)
    printf("%d^28 == %d\n", y, z);

    // x^64 за 6 операцій (чиста схема подвоєння)
    z = y * y;       // 1: y^2
    z = z * z;       // 2: y^4
    z = z * z;       // 3: y^8
    z = z * z;       // 4: y^16
    z = z * z;       // 5: y^32
    z = z * z;       // 6: y^64
    printf("%d^64 == %d\n", y, z); // тут проблема з типом даних, бо всі значення виходять за рамки

    return 0;
}