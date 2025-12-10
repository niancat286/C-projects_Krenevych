#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <numeric>
#include <cstdlib>


namespace CustomSpace {
    class Rational {
    private:
        int numerator;
        int denominator;

        void reduce() {
            int common_divisor = std::gcd(std::abs(numerator), denominator);
            numerator /= common_divisor;
            denominator /= common_divisor;

            if (denominator < 0) {
                numerator *= -1;
                denominator *= -1;
            }
        }

    public:
        Rational() : numerator(0), denominator(1) {}

        Rational(int num, int den) {
            if (den == 0) {
                throw std::invalid_argument("Denominator cannot be zero.");
            }
            numerator = num;
            denominator = den;
            reduce();
        }

        bool operator>(const Rational& other) const {
            return (numerator * other.denominator) > (other.numerator * denominator);
        }

        friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
            os << r.numerator << "/" << r.denominator;
            return os;
        }


    };

    template <typename T>
    T findMaximum(T a, T b) {
        return (a > b) ? a : b;
    }
}


int main() {
    using namespace CustomSpace;

    int i1 = 51;
    int i2 = 73;
    std::cout << "Max int: " << findMaximum(i1, i2) << std::endl;

    double d1 = 8.92;
    double d2 = 3.14;
    std::cout << "Max double: " << findMaximum(d1, d2) << std::endl;

    std::string s1 = "strawberry";
    std::string s2 = "peach";
    std::cout << "Max string: " << findMaximum(s1, s2) << std::endl;

    Rational r1(1, 7);
    Rational r2(5, 4);
    std::cout << "Max Rational: " << findMaximum(r1, r2) << std::endl;

    return 0;
}



// є нюанс. на моїй ОС лаганув стандарт і не працює gcd. довелось напряму запускати через термінал через
// стандарт С++17 нижче команди. якщо віндовс то замість clang++ g++

//$ clang++ t_01.cpp -o t_01_app -std=c++17
//$ ./t_01_app