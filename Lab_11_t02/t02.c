#include <stdio.h>
#include "functions.h"

int main() {
    double a;

    printf("Enter a > 0: ");
    scanf("%lf", &a);

    if (a <= 0) {
        printf("a must be > 0!\n");
        return 1;
    }

    filter_file("F.txt", "G.txt", a);

    printf("Done. File G.txt created. File F.txt updated.\n");
    return 0;
}
