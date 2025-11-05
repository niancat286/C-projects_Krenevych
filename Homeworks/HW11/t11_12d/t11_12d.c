#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "toys.h"

int main(void) {

    const char *input = "toys.txt";
    const char *outbin = "matches.bin";

    char query[Toy_name_LEN + 1];

    printf("input name of toy for search: ");
    scanf("%50s", query);

    Toy *arr = NULL;
    size_t n = 0;

    if (load_names_from_file(input, &arr, &n) != 0) {
        fprintf(stderr, "error read file '%s'\n", input);
        return 2;
    }

    if (n == 0) {
        printf("file '%s' has no records\n", input);
        free_toy(arr);
        return 0;
    }

    printf("instaled %zu records. search '%s'...\n", n, query);

    int found = save_matches(outbin, arr, n, query);

    if (found < 0) {
        fprintf(stderr, "error writing in bin file '%s'\n", outbin);
        free_toy(arr);
        return 3;
    }

    printf("found %d record(s) results in '%s'.\n", found, outbin);

    free_toy(arr);
    return 0;
}
