#include <stdio.h>
#include <math.h>


#define  N 3
#define  M 3


int replace_el(int mat[N][M], int n,  int m) {
    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == n) {
                mat[i][j] = m;
                k++;
            }
        }
    }
    return k;
}


int replace_el_2(int mat[N][M], int i,  int j, double a) {
    if ((i<0) || (i>=N)) return -1;
    if ((j<0) || (j>=M)) return -2;
    mat[i][j] = a;

    return 0;
}


void output_mat(int mat[N][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}


void task1() {
    int mat[][M]= {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    printf("Original matrix:\n");
    output_mat(mat, N, M);

    int k = replace_el(mat, 3, 0);  // заміна всіх 3 на 0
    printf("\nReplaced %d elements (3 -> 0):\n", k);
    output_mat(mat, N, M);

    int status = replace_el_2(mat, 1, 1, 99); // заміна конкретного елемента
    if (status == 0) {
        printf("\nElement at (1,1) replaced with 99:\n");
        output_mat(mat, N, M);
    } else {
        printf("Index error: %d\n", status);
    }
}

int main() {
    task1();
    return 0;
}


// не памʼятаю що це була за програма, але вона не з методички))) тому дописала просто як це бачу, щоб не висів незавершений код