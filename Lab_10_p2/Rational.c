#include <stdio.h>
#include <stdlib.h>
#include "Rational.h"

// Рекурсивний алгоритм Евкліда
unsigned gcd(unsigned x, unsigned y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

// Ввід раціонального числа
int input_rational(Rational* r) {
    printf("Enter numerator: ");
    scanf("%d", &r->numerator);

    printf("Enter denominator: ");
    scanf("%u", &r->denominator);

    if (r->denominator == 0) {
        printf("Error: denominator cannot be zero!\n");
        return 1;
    }

    rational_reduce(r);
    return 0;
}

// Вивід раціонального числа
void output_rational(Rational r) {
    printf("%d/%u\n", r.numerator, r.denominator);
}

// Скорочення дробу
void rational_reduce(Rational* r) {
    if (r->denominator == 0) return;
    unsigned num = (r->numerator < 0) ? -r->numerator : r->numerator;
    unsigned gcd_value = gcd(num, r->denominator);
    if (gcd_value == 0) return;
    r->numerator /= gcd_value;
    r->denominator /= gcd_value;
}

// Додавання
Rational rational_add(Rational r1, Rational r2) {
    Rational result;
    result.denominator = r1.denominator * r2.denominator;
    result.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    rational_reduce(&result);
    return result;
}

// Віднімання
Rational rational_sub(Rational r1, Rational r2) {
    Rational result;
    result.denominator = r1.denominator * r2.denominator;
    result.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
    rational_reduce(&result);
    return result;
}

// Множення
Rational rational_mul(Rational r1, Rational r2) {
    Rational result;
    result.denominator = r1.denominator * r2.denominator;
    result.numerator = r1.numerator * r2.numerator;
    rational_reduce(&result);
    return result;
}

// Порівняння (чи r1 > r2)
bool rational_compare(Rational r1, Rational r2) {
    return (r1.numerator * r2.denominator > r2.numerator * r1.denominator);
}

// Перевірка рівності
bool rational_equal(Rational r1, Rational r2) {
    return (r1.numerator * r2.denominator == r2.numerator * r1.denominator);
}
