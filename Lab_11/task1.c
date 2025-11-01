#include <stdio.h>

#include "file_work.h"

#define MAX_SIZE 100

int main() {
    double data[MAX_SIZE];
    size_t size;

    printf("Enter number of elements (max %d): ", MAX_SIZE);
    if (scanf("%zu", &size) != 1 || size > MAX_SIZE) {
        printf("Invalid size.\n");
        return 1;
    }

    int entered = input_array(data, size);
    if (entered <= 0) {
        printf("No valid elements entered.\n");
        return 1;
    }

    const char* filename = "data.txt";
    
    write_to_file_binary(filename, data, entered);
    printf("Data written to %s\n", filename);

    double buffer[MAX_SIZE];
    int read = read_from_file_binary(filename, buffer, MAX_SIZE);
    if (read < 0) {
        printf("Error reading from file.\n");
        return 1;
    }

    printf("Data read from file:\n");
    for (int i = 0; i < read; i++) {
        printf("%lf, ", buffer[i]);
    }

    rewrite_abs(filename, "filtered_data.txt", 10.0);
    printf("\nData with abs(value) < 10.0 written to filtered_data.txt\n");
    
    double buffer2[MAX_SIZE];
    int read2 = read_from_file_binary(filename, buffer2, MAX_SIZE);
    if (read2 < 0) {
        printf("Error reading from file.\n");
        return 1;
    }
     printf("Data read from file:\n");
    for (int i = 0; i < read2; i++) {
        printf("%lf, ", buffer2[i]);
    }

    int read3 = read_from_file_binary("filtered_data.txt", buffer2 + read2, MAX_SIZE);
    if (read3 < 0) {
        printf("Error reading from file.\n");
        return 1;
    }

    printf("Data read from file:\n");
    for (int i = 0; i < read3; i++) {
        printf("%lf, ", buffer2[i+read2]);
    }


    return 0;
}


