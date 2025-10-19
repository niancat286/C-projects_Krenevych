#include <stdio.h>
#include <math.h>

#define N 20

// Функція вводу n-вимірного вектора
int input_vec(float* arr, int max_n) {
    int n;
    printf("Enter vector size (max %d): ", max_n);
    scanf("%d", &n);
    if (n > max_n) n = max_n;

    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%f", &arr[i]);
    }
    return n;
}

// Функція виводу вектора
void output_vec(const float* arr, int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%g ", arr[i]);
    }
    printf("]\n");
}

// Функція додавання двох векторів
int add_vec(const float* a, const float* b, float* c, int n) {
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }
    return n;
}

// Функція обчислення скалярного добутку
float scalar_product(const float* a, const float* b, int n) {
    float res = 0.0f;
    for (int i = 0; i < n; i++) {
        res += a[i] * b[i];
    }
    return res;
}

// Тестова функція
int test() {
    float a[N], b[N], c[N];

    printf("=== Input first vector ===\n");
    int size_a = input_vec(a, N);

    printf("=== Input second vector ===\n");
    int size_b = input_vec(b, N);

    if (size_a != size_b) {
        printf("Error: vectors must have the same size!\n");
        return -1;
    }

    printf("Vector A: ");
    output_vec(a, size_a);
    printf("Vector B: ");
    output_vec(b, size_b);

    // Обчислення суми
    add_vec(a, b, c, size_a);
    printf("A + B = ");
    output_vec(c, size_a);

    // Скалярний добуток
    float prod = scalar_product(a, b, size_a);
    printf("<A, B> = %g\n", prod);

    return 0;
}

int main() {
    test();
    return 0;
}
