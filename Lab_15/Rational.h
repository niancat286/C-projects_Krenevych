#ifndef C_PROJECTS_KRENEVYCH_RATIONAL_H
#define C_PROJECTS_KRENEVYCH_RATIONAL_H

#include <iostream>
#include <fstream>

using namespace std;



class Rational {
    private:
    void rational_reduce();

    static unsigned gcd(unsigned x, unsigned y);

    int numerator;              // чисельник
    unsigned int denominator;   //знаменник


    public:

    Rational (int num,  unsigned den) {
        numerator = num;
        denominator = den;
    }

    Rational () {
    }

    bool input_rational();
    void output_rational();

    friend ostream &operator<<( ostream &output, const Rational &D) {
        output << "(" << D.numerator << " / " << D.denominator << ")";
        return output;
    }

    friend istream &operator>>(istream& input, Rational &D ) {
        input >> D.numerator >> D.denominator;
        return input;
    }

    Rational rational_add(Rational other);

    Rational operator+(Rational other) {
        return rational_add(other);
    }

    Rational rational_sub(Rational other);

    Rational operator-(Rational other) {
        return rational_sub(other);
    }

    Rational rational_mul(Rational other);

    Rational operator* (Rational other) {
        return rational_mul(other);
    }

    bool rational_compare(Rational other);

    bool rational_equal(Rational other);

    bool operator<(Rational other) {
        return numerator * other.denominator < other.numerator * denominator;
    }


};


#endif //C_PROJECTS_KRENEVYCH_RATIONAL_H