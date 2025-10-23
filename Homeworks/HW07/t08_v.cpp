#include <stdio.h>
#include <math.h>

#define N 10


int count_powers(int arr[], int size, int n) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        double root = pow(arr[i], 1.0 / n);
        int rounded = (int)(round(root));
        if (pow(rounded, n) == arr[i]) {
            count++;
        }
    }
    return count;
}


int main() {
    int arr[N];
    int size, n;

    printf("Введіть розмір масиву N: ");
    scanf("%d", &size);

    printf("Введіть %d натуральних чисел:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Введіть n (>1): ");
    scanf("%d", &n);

    int result = count_powers(arr, size, n);
    printf("Кількість n-тих степенів серед елементів масиву: %d\n", result);

    return 0;
}
