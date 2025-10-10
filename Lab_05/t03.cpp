#include <stdio.h>


int steps_count(int n) {
    int steps = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        steps++;
    }
    return steps;
}


int main() {
    int n;
    printf("Введіть натуральне число n (<1000): ");
    scanf("%d", &n);

    int steps = steps_count(n);
    printf("Кількість кроків для %d = %d\n", n, steps);


    int maxSteps = 0, bestN = 1;
    for (int i = 1; i < 1000; i++) {
        int s = steps_count(i);
        if (s > maxSteps) {
            maxSteps = s;
            bestN = i;
        }
    }

    printf("Число < 1000 з максимальною кількістю кроків: %d (кроків = %d)\n", bestN, maxSteps);

    return 0;
}
