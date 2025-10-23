#ifndef C_PROJECTS_KRENEVYCH_RATIONAL_H
#define C_PROJECTS_KRENEVYCH_RATIONAL_H

#include <stdbool.h>

typedef struct {
    int numerator;              // чисельник
    unsigned int denominator;   // знаменник
} Rational;

extern int input_rational(Rational* r);
extern void output_rational(Rational r);
extern Rational rational_add(Rational r1, Rational r2);
extern Rational rational_sub(Rational r1, Rational r2);
extern Rational rational_mul(Rational r1, Rational r2);
extern bool rational_compare(Rational r1, Rational r2);
extern void rational_reduce(Rational* r);
extern bool rational_equal(Rational r1, Rational r2);

#endif //C_PROJECTS_KRENEVYCH_RATIONAL_H
