//
// Created by Yaroslava Krenevych on 03.09.2025.
//

#include <stdio.h>


int main() {
    int x, y;
    double z;

    scanf("%d %d", &x, &y);

    z = 2 / (1./x + 1./y);
    printf("z == %.2lf,\nz == %e\n", z, z);

}