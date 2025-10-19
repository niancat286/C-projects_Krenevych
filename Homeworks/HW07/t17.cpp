#include <stdio.h>

#define MAX_N 100


void input_scores(double scores[], int *n) {
    printf("Введіть кількість оцінок: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        scanf("%lf", &scores[i]);
    }
}


int find_max_index(double scores[], int n) {
    int max_index = 0;
    for (int i = 1; i < n; i++) {
        if (scores[i] > scores[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}


int find_min_index(double scores[], int n) {
    int min_index = 0;
    for (int i = 1; i < n; i++) {
        if (scores[i] < scores[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}


double find_res(double scores[], int n) {
    if (n <= 2) return -1;

    int max_index = find_max_index(scores, n);
    int min_index = find_min_index(scores, n);

    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += scores[i];
    }

    if (max_index == min_index) {
        sum -= scores[max_index];
        sum -= scores[min_index];
    } else {
        sum -= scores[max_index];
        sum -= scores[min_index];
    }

    return sum / (n - 2);
}


void print_result(double final_score) {
    if (final_score < 0) {
        printf("Недостатньо оцінок для обчислення середнього.\n");
    } else {
        printf("Оцінка спортсмена: %.4lf\n", final_score);
    }
}


int main() {
    double scores[MAX_N];
    int n;

    input_scores(scores, &n);
    double result = find_res(scores, n);
    print_result(result);

    return 0;
}
