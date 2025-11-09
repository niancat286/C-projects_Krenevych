#include "Rational.h"
#include <iostream>

using namespace std;

bool Rational::input_rational() {
    cout << "Please enter a numerator: " << endl;
    cin >> numerator;

    cout << "Please enter a denominator: " << endl;
    cin >> denominator;

    if (denominator == 0) {
        cout << "Error: denominator cannot be zero " << endl;
        return false;
    }

    rational_reduce();
    return true;
}

void Rational::output_rational() {
    cout << numerator << "/" << denominator << endl;
}

Rational Rational::rational_add(Rational other) {
    Rational result;
    result.denominator = denominator * other.denominator;
    result.numerator = numerator * other.denominator + other.numerator * denominator;
    result.rational_reduce();
    return result;
}


Rational Rational::rational_sub(Rational other) {
    Rational result;
    result.denominator = denominator * other.denominator;
    result.numerator = numerator * other.denominator - other.numerator * denominator;
    result.rational_reduce();
    return result;
}

Rational Rational::rational_mul(Rational other) {
    Rational result;
    result.denominator = denominator * other.denominator;
    result.numerator = numerator * other.numerator;
    result.rational_reduce();
    return result;
}

bool Rational::rational_compare(Rational other) {
    return (numerator * other.denominator > other.numerator * denominator);
}

bool Rational::rational_equal(Rational other) {
    return (numerator * other.denominator == other.numerator * denominator);
}

unsigned Rational::gcd(unsigned x, unsigned y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

void Rational::rational_reduce() {
    if (denominator == 0) return;
    unsigned num = (numerator < 0) ? -numerator : numerator;
    unsigned gcd_value = gcd(num, denominator);
    if (gcd_value == 0) return;
    numerator /= gcd_value;
    denominator /= gcd_value;
};
