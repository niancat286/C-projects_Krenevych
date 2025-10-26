#include "Mounts.h"
#include <stdio.h>

int main() {
    int n;
    struct Mounts mounts[10];

    printf("Enter number of mounts (n): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\n--- Mount %d ---\n", i + 1);
        input_mounts(&mounts[i]);
    }

    printf("\nAll mounts:\n");
    for (int i = 0; i < n; i++) {
        output_mounts(&mounts[i]);
    }

    highestMount(mounts, n);
    get_height_mount(mounts, n, "Everest");

    // звільнення пам’яті
    for (int i = 0; i < n; i++) {
        free_mounts(&mounts[i]);
    }

    return 0;
}
