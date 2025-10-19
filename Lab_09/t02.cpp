#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_sqr(int n) {
    if (n < 0) return false;

    int sqr_root = (int)(sqrt(n + 0.0001));
    return (sqr_root* sqr_root == n);
}

bool is_cube(int n) {

    int cube_root = (int)(pow(n+0.0001, 1./3));
    return (cube_root* cube_root* cube_root == n);
}

int input_ints(int* arr, int n) {
    int k = 0;
    do {
        printf("a[%d] = ", k);
        int res = scanf("%d", &arr[k]);
        if (res != 1) break;
        k++;
    }while (k < n);
    return k;
}

int main() {
    int* arr = (int*)malloc(100*sizeof(int));
    int n = input_ints(arr, 100);
    int count_sqr = 0;
    int count_cube = 0;

    for (int i = 0; i < n; i++) {
        if (is_sqr(arr[i])) {
            count_sqr++;
        }
        if (is_cube(arr[i])) {
            count_cube++;
        }
    }
    printf("There are %d sqr and %d cubes", count_sqr,count_cube);
}
