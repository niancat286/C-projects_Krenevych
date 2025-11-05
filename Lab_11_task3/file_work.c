#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "file_work.h"

static int is_fibonacci(int n) {
    if (n < 0) return 0;
    // Число n є числом Фібоначчі тоді і тільки тоді, коли
    // 5n² + 4 або 5n² - 4 є повним квадратом
    long long x1 = 5LL * n * n + 4;
    long long x2 = 5LL * n * n - 4;
    long long r1 = sqrt(x1);
    long long r2 = sqrt(x2);
    return (r1 * r1 == x1) || (r2 * r2 == x2);
}

void input_to_file_until_zero(const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Cannot open file for writing");
        return;
    }

    int value;
    while (1) {
        printf("Enter integer (0 to stop): ");
        if (scanf("%d", &value) != 1) {
            printf("Invalid input. Stopping.\n");
            break;
        }
        if (value == 0) break;
        fwrite(&value, sizeof(int), 1, file);
    }

    fclose(file);
}

void write_to_file_binary(const char* filename, const int* data, size_t size) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for binary writing");
        return;
    }
    fwrite(data, sizeof(int), size, file);
    fclose(file);
}

int read_from_file_binary(const char* filename, int* buffer, size_t size) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file for binary reading");
        return -1;
    }
    size_t count = fread(buffer, sizeof(int), size, file);
    fclose(file);
    return (int)count;
}

void filter_fibonacci(const char* src_filename, const char* dst_filename) {
    FILE* src = fopen(src_filename, "rb");
    if (!src) {
        perror("Cannot open source file");
        return;
    }

    FILE* dst = fopen(dst_filename, "wb");
    if (!dst) {
        perror("Cannot open destination file");
        fclose(src);
        return;
    }

    int value;
    while (fread(&value, sizeof(int), 1, src) == 1) {
        if (is_fibonacci(value)) {
            fwrite(&value, sizeof(int), 1, dst);
        }
    }

    fclose(src);
    fclose(dst);
}
