//
// Created by Yaroslava Krenevych on 03.09.2025.
//


#include <stdio.h>

int main() {
    double temp_celsius;
    double temp_fahrenheit;
    printf("intup degree in C:");
    scanf("%lf", &temp_celsius);
    temp_fahrenheit = (temp_celsius * 9 / 5) + 32;
    printf("temp_fahrenheit = %g\nis equal to temp_celsius" , temp_fahrenheit);
    return 0;
}