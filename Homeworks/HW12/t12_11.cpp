#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    FILE* f = fopen("input.txt", "r");
    if (!f) return -1;

    double nums[100];
    int count = 0;int
    maxPrecision = 0;
    char buf[100]; //temporary buffer

    while (fscanf(f, "%[^;];", buf) == 1) {
        int precision = 0;
        bool after_dot = false;

        for (int i = 0; buf[i]; i++) {
            if (buf[i] == '.') after_dot = true;
            else if (after_dot && buf[i] >= '0' and buf[i] <= '9') precision++;
        }

        if (maxPrecision < precision) maxPrecision = precision;

        double x = 0;
        sscanf(buf, "%lf", &x);
        if (x < 0) x = fabs(x);
        nums[count++] = x;

    }
    fclose(f);

    char format[10];
    sprintf(format, "%%.%df\n", maxPrecision);

    FILE* out = fopen("output.txt", "w");
    for (int i = 0; i < count; i++)
        fprintf(out, format, nums[i]);
    fclose(out);

    return 0;



}