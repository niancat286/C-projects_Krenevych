#ifndef C_PROJECTS_KRENEVYCH_RATIONAL_H
#define C_PROJECTS_KRENEVYCH_RATIONAL_H

#include <iostream>
#include <fstream>

using namespace std;


class RationalError : public exception{
protected:
    string message;
public:
    explicit RationalError(const string& m) : message(m) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class RationalValueError : public RationalError {
public:
    explicit RationalValueError(const string& m) : RationalError("RationalValueError: " + m) {}
};



class Rational {
private:
    int numerator;
    unsigned denominator;

    void rational_reduce();
    static unsigned gcd(unsigned x, unsigned y);

public:
    // Конструктори
    Rational(int num = 0, unsigned den = 1) {
        if (den == 0) {
            throw RationalValueError("Division by zero");
        }
        numerator = num;
        denominator = den;
        rational_reduce();
    }

    // Сеттери
    void setNumerator(int num) { numerator = num; }

    void setDenominator(unsigned den) {
        if (den == 0) {
            throw RationalValueError("Division by zero");
        }
        denominator = den;
    }

    friend istream& operator>>(istream& input, Rational& D) {
        input >> D.numerator >> D.denominator;
        if (!input) throw RationalError("Input stream error");
        if (D.denominator == 0) throw RationalValueError("Denominator cannot be zero");
        D.rational_reduce();
        return input;
    }

    friend ostream& operator<<(ostream& output, const Rational& D) {
        output << "(" << D.numerator << " / " << D.denominator << ")";
        return output;
    }

    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const; // бінарний
    Rational operator-() const;                      // унарний
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    bool operator<(const Rational& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator==(const Rational& other) const {
        return numerator * other.denominator == other.numerator * denominator;
    }


    friend void writeToFile(const Rational& r, const string& filename);
};


#endif //C_PROJECTS_KRENEVYCH_RATIONAL_H