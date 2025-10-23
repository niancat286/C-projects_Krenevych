#include "Mounts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 255

int input_mounts(struct Mounts* mounts) {
    char name[N];

    printf("Enter name of Mount: ");
    // очищення буфера, якщо перед цим був scanf
    while (getchar() != '\n' && !feof(stdin));
    if (fgets(name, N, stdin) == NULL) {
        fprintf(stderr, "Input error.\n");
        return -1;
    }

    // прибрати \n з кінця
    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n')
        name[len - 1] = '\0';

    mounts->name = (char*) malloc(strlen(name) + 1);
    strcpy(mounts->name, name);

    printf("Enter height of Mount: ");
    if (scanf("%d", &mounts->height) != 1) {
        fprintf(stderr, "Invalid height input.\n");
        return -1;
    }

    return 0;
}

void output_mounts(const struct Mounts* mounts) {
    printf("Mount %s is %d m high.\n", mounts->name, mounts->height);
}

void free_mounts(struct Mounts* mounts) {
    if (mounts && mounts->name)
        free(mounts->name);
}

void highestMount(struct Mounts* mounts, int n) {
    if (n <= 0) return;

    int highest = mounts[0].height;
    char* highest_name = mounts[0].name;

    for (int i = 1; i < n; i++) {
        if (mounts[i].height > highest) {
            highest = mounts[i].height;
            highest_name = mounts[i].name;
        }
    }

    printf("\nHighest Mount: %s (%d m)\n", highest_name, highest);
}

int get_height_mount(const struct Mounts* mounts, int n, char* name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(mounts[i].name, name) == 0) {
            printf("Height of %s: %d m\n", name, mounts[i].height);
            return mounts[i].height;
        }
    }
    printf("There is no mount named \"%s\" here.\n", name);
    return -1;
}
