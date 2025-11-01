#include "records.h"

#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <io.h>
#define TRUNCATE _chsize
#else
#include <unistd.h>
#define TRUNCATE ftruncate
#endif
// this found as a problem of compilation


int binarySearch(const char *filename, unsigned key, TPair *out) {
    FILE *f = fopen(filename, "rb");
    if (!f) return -1;

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    long count = size / sizeof(TPair);

    long left = 0, right = count - 1;

    while (left <= right) {
        long mid = (left + right) / 2;
        TPair tmp;

        fseek(f, mid * sizeof(TPair), SEEK_SET);
        fread(&tmp, sizeof(TPair), 1, f);

        if (tmp.key == key) {
            *out = tmp;
            fclose(f);
            return mid;
        } else if (tmp.key < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    fclose(f);
    return -1;
}


int delete_by_order(const char *filename, unsigned key) {
    FILE *f = fopen(filename, "rb");
    if (!f) return -1;

    FILE *tmp = fopen("tmp.bin", "wb");
    if (!tmp) return -2;

    TPair r;
    int deleted = 0;

    while (fread(&r, sizeof(TPair), 1, f) == 1) {
        if (r.key != key)
            fwrite(&r, sizeof(TPair), 1, tmp);
        else
            deleted = 1;
    }

    fclose(f);
    fclose(tmp);

    remove(filename);
    rename("tmp.bin", filename);

    return deleted;
}


int delete_not_ordered(const char *filename, unsigned key) {
    FILE *f = fopen(filename, "rb+");
    if (!f) return -1;

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    long count = size / sizeof(TPair);

    TPair last, cur;

    fseek(f, (count - 1) * sizeof(TPair), SEEK_SET);
    fread(&last, sizeof(TPair), 1, f);

    rewind(f);

    for (long i = 0; i < count; i++) {
        fseek(f, i * sizeof(TPair), SEEK_SET);
        fread(&cur, sizeof(TPair), 1, f);

        if (cur.key == key) {
            fseek(f, i * sizeof(TPair), SEEK_SET);
            fwrite(&last, sizeof(TPair), 1, f);

            freopen(filename, "rb+", f);
            TRUNCATE(fileno(f), (count - 1) * sizeof(TPair));
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}
