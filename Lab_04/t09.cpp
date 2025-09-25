#include <stdio.h>
#include <math.h>


//
// Created by Yaroslava Krenevych on 12.09.2025.
//


#include <cstdio>
#include <cmath>


int main() {
    int n, k, r;
    printf("Enter number n \n");
    scanf("%d", &n);

    k = 2;
    r = 1;

    while (pow(k,r)<=n) {r ++;}

    printf("r= %d", r);
    return 0;
}
