#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "records.h"

void printFile(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) { printf("Can't open file\n"); return; }

    printf("File content:\n");
    TPair r;
    while (fread(&r, sizeof(TPair), 1, f) == 1) {
        printf("key = %u, data = %s\n", r.key, r.data);
    }
    printf("------------\n");
    fclose(f);
}

int main() {
    const char *fname = "pairs.bin";
    FILE *f = fopen(fname, "wb");

    // Створюємо 6 записів
    TPair arr[6] = {
        {1, "aaa"},
        {3, "bbb"},
        {5, "ccc"},
        {7, "ddd"},
        {9, "eee"},
        {11,"fff"}
    };

    fwrite(arr, sizeof(TPair), 6, f);
    fclose(f);

    printf("Initial file:\n");
    printf("fname = %s\n", fname);
    printFile(fname);

    TPair out;
    int idx = binarySearch(fname, 7, &out);
    printf("Search key=7: idx = %d, data = %s\n", idx, out.data);

    printf("\nDelete_by_order key=5\n");
    delete_by_order(fname, 5);
    printFile(fname);

    printf("Adding disorder...\n");
    FILE *ff = fopen(fname, "ab");
    TPair extra = {42, "zzz"};
    fwrite(&extra, sizeof(TPair), 1, ff);
    fclose(ff);
    printFile(fname);

    printf("delete_not_ordered key=42\n");
    delete_not_ordered(fname, 42);
    printFile(fname);

    return 0;
}
