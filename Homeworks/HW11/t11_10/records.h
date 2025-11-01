#ifndef C_PROJECTS_KRENEVYCH_RECORDS_H
#define C_PROJECTS_KRENEVYCH_RECORDS_H

#include <stdio.h>

typedef struct {
    unsigned key;
    char data[10];
} TPair;


int binarySearch(const char *filename, unsigned key, TPair *out);
int delete_by_order(const char *filename, unsigned key);
int delete_not_ordered(const char *filename, unsigned key);


#endif //C_PROJECTS_KRENEVYCH_RECORDS_H