//
// Created by Yaroslava Krenevych on 10.09.2025.
//
#include <float.h>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>

void task3_1a(unsigned n) {
    unsigned last_digit = n % 10;
    unsigned second_digit = (n / 10) % 10;
    unsigned first_digit = n / 100;

    printf("1st digit: %u, 2nd: %u, 3rd: %u \n",
        first_digit, second_digit, last_digit);
}


void task3_1b(unsigned n) {
    unsigned last_digit = n % 10;
    unsigned second_digit = (n / 10) % 10;
    unsigned first_digit = n / 100;

    unsigned suma = last_digit + second_digit + first_digit;
    printf("suma= %u \n", suma);
}


void task3_1c(unsigned n) {
    unsigned last_digit = n % 10;
    unsigned second_digit = (n / 10) % 10;
    unsigned first_digit = n / 100;

    printf("%u %u %u \n",
        last_digit, second_digit, first_digit);
}


void task3_2(unsigned n) {
    unsigned last_digit = n % 10;
    unsigned second_digit = (n / 10) % 10;
    unsigned first_digit = n / 100;

    if ((first_digit == second_digit) || (first_digit == last_digit) || (second_digit == last_digit)) {
        return;
    }

    unsigned r1 = 100*first_digit + 10* second_digit + last_digit;
    unsigned r2 = 100*first_digit + 10* last_digit + second_digit;

    unsigned r3 = 100*second_digit + 10* last_digit + first_digit;
    unsigned r4 = 100*second_digit + 10* first_digit + last_digit;

    unsigned r5 = 100*last_digit + 10* first_digit + second_digit;
    unsigned r6 = 100*last_digit + 10* second_digit + first_digit;

    printf("all the nums: %u, %u, %u, %u, %u, %u \n", r1, r2, r3, r4, r5, r6);
}

void task3_3() {
    int a,b,c;
    int res1;
    long long res2;
    int inp_corr = scanf("%d,%d,%d",&a,&b,&c);
    if (inp_corr != 3) {
        printf("Incorrect input\n");
        return;
    }
    res1 = a * b * c;
    printf("res1 = %d\n", res1);

    res2 = (long long)a * (long long)b * (long long)c;
    printf("res2 = %lld\n", res2);

}

uint16_t mult_task3_4(uint8_t x, uint8_t y) {
    return x * y;
};


void task3_4() {
    uint16_t x,y;
    printf("x, y:");
    scanf("%hu %hu \n", &x, &y);
    uint16_t res = mult_task3_4(x, y);
    printf("res = %" PRIu16 "\n", res);
}

void task3_5() {
    int a,b;

    printf("a, b:\n");
    scanf("%d %d\n", &a, &b);

    int min_num, max_num;

    min_num = (a < b) ? a : b;
    max_num = (a > b) ? a : b;
    printf("min_num = %d, max_num = %d\n", min_num, max_num);
}

void task3_6(double x, double y, double z) {
    double maxAbs = x, minAbs = x;

    if (fabs(y) > fabs(maxAbs)) maxAbs = y;
    if (fabs(y) < fabs(minAbs)) minAbs = y;

    if (fabs(z) > fabs(maxAbs)) maxAbs = z;
    if (fabs(z) < fabs(minAbs)) minAbs = z;

    printf("maxAbs = %f, minAbs = %f\n", maxAbs, minAbs);
}


void task3_7a() {
    double a,b,c;
    printf("a, b, c for ax^2 + bx + c = 0:\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (fabs(a) < 2 * DBL_EPSILON) {
        if (fabs(b) < 2 * DBL_EPSILON) {
            if (fabs(c) < 2 * DBL_EPSILON) {
                printf("Infinite sols\n");
            }
            else {
                printf("No sols\n");
            }
        }
        else {
            printf("One sol\n x = %lf ", -b/c);
        }
    }
    else {
        double D = b * b - 4 * a * c;
        if (D < 0) {
            printf("no sols\n");
            return;
        }
        if (fabs(D) < DBL_EPSILON) {
            printf("one sol\n");
            double res1 = (-b - sqrt(D)) / (2 * a);
            printf("res1 = %lf\n", res1);
        }
        else {
            printf("two sols\n");
            double res1 = (-b - sqrt(D)) / (2 * a);
            double res2 = (-b + sqrt(D)) / (2 * a);
            printf("res1 = %lf\n", res1);
            printf("res2 = %lf\n", res2);
        }
    }

}


void task3_7b() {
    double a, b, c;
    printf("a, b, c for ax^4 + bx^2 + c = 0:\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    double y1, y2;
    int n = 0;

    if (fabs(a) < 2 * DBL_EPSILON) {
        if (fabs(b) < 2 * DBL_EPSILON) {
            if (fabs(c) < 2 * DBL_EPSILON) {
                printf("Infinite solutions\n");
                return;
            } else {
                printf("No real solutions\n");
                return;
            }
        } else {
            double y = -c / b;
            if (y < -DBL_EPSILON) {
                printf("No real solutions\n");
                return;
            } else if (fabs(y) < DBL_EPSILON) {
                printf("x = 0\n");
                return;
            } else {
                printf("x = %lf\n", sqrt(y));
                printf("x = %lf\n", -sqrt(y));
                return;
            }
        }
    }

    printf("Solve the quadratic equation for y = x^2:\n");
    printf("%lf %lf %lf\n", a, b, c); // тут користувач має ввести ті самі a,b,c, можна оптимізувати

    double D = b*b - 4*a*c;
    if (D < -DBL_EPSILON) {
        printf("No real solutions\n");
        return;
    } else if (fabs(D) < DBL_EPSILON) {
        y1 = -b/(2*a);
        if (y1 < -DBL_EPSILON) {
            printf("No real solutions\n");
            return;
        } else if (fabs(y1) < DBL_EPSILON) {
            printf("x = 0\n");
            return;
        } else {
            printf("x = %lf\n", sqrt(y1));
            printf("x = %lf\n", -sqrt(y1));
            return;
        }
    } else {
        y1 = (-b - sqrt(D)) / (2*a);
        y2 = (-b + sqrt(D)) / (2*a);

        if (y1 > -DBL_EPSILON) {
            if (y1 < DBL_EPSILON) printf("x = 0\n");
            else {
                printf("x = %lf\n", sqrt(y1));
                printf("x = %lf\n", -sqrt(y1));
            }
        }

        if (y2 > -DBL_EPSILON && fabs(y2 - y1) > DBL_EPSILON) {
            if (y2 < DBL_EPSILON) printf("x = 0\n");
            else {
                printf("x = %lf\n", sqrt(y2));
                printf("x = %lf\n", -sqrt(y2));
            }
        }
    }
}


int main() {

    //unsigned n;
    //printf("n=");
    //scanf("%u", &n);
    //if (n >= 99 || n <= 999) {
        //task3_1a(n);
        //task3_1b(n);
        //task3_2(n);
        //task3_1c(n);
    //}
    //task3_3();
    //task3_4();
    //task3_5();
    //double x,y,z;

    //printf("x,y, z:");
    //scanf("%lf %lf %lf", &x, &y, &z);

    //task3_6(x,y,z);
    //task3_7a();
    task3_7b();

    return 0;
}