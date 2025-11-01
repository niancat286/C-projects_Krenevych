#include <stdio.h>
#include "file_work.h"

#define MAX_SIZE 100

int main() {
    const char* fileF = "F.dat";
    const char* fileG = "G.dat";

    printf("Creating file F (integers until 0):\n");
    input_to_file_until_zero(fileF);

    filter_fibonacci(fileF, fileG);
    printf("\nFile G created with Fibonacci numbers from F.\n");

    int buffer[MAX_SIZE];
    int count = read_from_file_binary(fileG, buffer, MAX_SIZE);
    if (count > 0) {
        printf("Fibonacci numbers in G:\n");
        for (int i = 0; i < count; i++)
            printf("%d ", buffer[i]);
        printf("\n");
    } else {
        printf("No Fibonacci numbers found.\n");
    }

    return 0;
}
