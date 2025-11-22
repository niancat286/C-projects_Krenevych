#include "Rational.h"

unsigned Rational::gcd(unsigned x, unsigned y) {
    return (y == 0) ? x : gcd(y, x % y);
}

void Rational::rational_reduce() {
    if (denominator == 0) return;
    unsigned num = (numerator < 0) ? -numerator : numerator;
    unsigned g = gcd(num, denominator);
    if (g != 0) {
        numerator /= g;
        denominator /= g;
    }
}

Rational Rational::operator+(const Rational& other) const {
    Rational result;
    result.numerator = numerator * other.denominator + other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    result.rational_reduce();
    return result;
}

Rational Rational::operator-(const Rational& other) const { //бінарний
    Rational result;
    result.numerator = numerator * other.denominator - other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    result.rational_reduce();
    return result;
}

Rational Rational::operator-() const {          //унарний
    return Rational(-numerator, denominator);
}

Rational Rational::operator*(const Rational& other) const {
    Rational result;
    result.numerator = numerator * other.numerator;
    result.denominator = denominator * other.denominator;
    result.rational_reduce();
    return result;
}

Rational Rational::operator/(const Rational& other) const {
    if (other.numerator == 0)
        throw RationalValueError("Division by zero");
    Rational result;
    result.numerator = numerator * (int)other.denominator;
    result.denominator = denominator * (unsigned)abs(other.numerator);
    if (other.numerator < 0) result.numerator = -result.numerator;
    result.rational_reduce();
    return result;
}

void writeToFile(const Rational& r, const string& filename) {
    ofstream out(filename);
    if (!out.is_open()) {
        throw RationalError("Could not open file " + filename);
    }
    out << r << endl;
    out.close();
}