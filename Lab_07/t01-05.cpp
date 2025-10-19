#include <stdio.h>
#include <math.h>

#define N 5
#define MAX_SIZE 50

void output_vec();
void task2();
void task3();
void task4();
void task5();

int greater_Euler(double arr[N]);
int greater_Euler1(double arr[], size_t n);
int greater_Euler2(const double* arr_start, const double* arr_end);
int input_arr(int* arr, int n);

int main() {
    int task_num = 5;
    switch (task_num) {
        case 1:
            output_vec();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        default:
            printf("no task with this number\n");
    }
}

// ===== Task 1 =====
void output_vec() {
    int a[] = {1, 2, 3, 4, 5};
    int k = 0;
    double x;

    printf("x = ");
    scanf("%lf", &x);

    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n; i++) {
        if (a[i] < x) {
            k++;
        }
    }
    printf("k = %d\n", k);
}

// ===== Task 2 =====
void task2() {
    int a[] = {5, 112, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);
    int b[n];

    for (int i = 0; i < n; i++) {
        b[i] = a[n - 1 - i];
    }

    printf("b = ");
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}

// ===== Допоміжні функції для Task 3 =====
int greater_Euler(double arr[N]) {
    int k = 0;
    for (int i = 0; i < N; i++) {
        k += arr[i] > exp(1) ? 1 : 0;
    }
    return k;
}

int greater_Euler1(double arr[], size_t n) {
    int k = 0;
    for (int i = 0; i < (int)n; i++) {
        k += arr[i] > exp(1) ? 1 : 0;
    }
    return k;
}

int greater_Euler2(const double* arr_start, const double* arr_end) {
    int k = 0;
    const double* ptr = arr_start;
    while (ptr != arr_end) {
        k += (*ptr > exp(1) ? 1 : 0);
        ptr++;
    }
    return k;
}

// ===== Task 3 =====
void task3() {
    double arr[N];

    printf("Enter %d elements:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%lf", &arr[i]);
    }

    int result = greater_Euler2(arr, arr + N);
    printf("Number of elements > e: %d\n", result);
}

// ===== Допоміжна функція =====
int input_arr(int* arr, int n) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return n;
}

// ===== Task 4 =====
void task4() {
    int arr[N];
    input_arr(arr, N);

    int max_num = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] > max_num) {
            max_num = arr[i];
        }
    }
    printf("max_num = %d\n", max_num);
}

// ===== Task 5 =====
void task5() {
    int arr[MAX_SIZE];
    int n = 0;
    int even_count = 0;
    int odd_count = 0;
    int num;

    printf("Enter numbers (0 to stop, max %d elements):\n", MAX_SIZE);
    while (n < MAX_SIZE) {
        scanf("%d", &num);
        if (num == 0) break;
        arr[n++] = num;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    printf("Total elements entered: %d\n", n);
    printf("Even numbers: %d\n", even_count);
    printf("Odd numbers: %d\n", odd_count);
}
