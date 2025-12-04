#include <stdio.h>
#include <math.h>


int main() {
    double a = 10;
    do {a /= 2;} while (1 != a+1);
    printf("%e", a);

}

