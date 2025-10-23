#include "Rational.h"
#include <stdio.h>

void test_input() {
    Rational r;
    if (input_rational(&r) == 0) {
        printf("You entered: ");
        output_rational(r);
    }
}

void test_add_rational() {
    Rational r1 = {1, 2};
    Rational r2 = {1, 3};
    Rational r3 = rational_add(r1, r2);
    Rational expected = {5, 6};

    printf("Sum of ");
    output_rational(r1);
    printf(" + ");
    output_rational(r2);
    printf(" = ");
    output_rational(r3);

    if (!rational_equal(r3, expected)) {
        printf("Rational addition failed!\n");
    } else {
        printf("Rational addition correct!\n");
    }
}

int main() {
    test_input();
    test_add_rational();
    return 0;
}
