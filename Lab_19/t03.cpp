#include <iostream>
#include <list>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <vector>

#include "Rational.h"

using namespace std;

template<typename T>
class Polynomial {
    std::list<T> coeffs;
public:
    Polynomial() {}

    Polynomial(const std::list<T>& c) : coeffs(c) {
        removeOddZeros();
    }

    void removeOddZeros() {
        while (coeffs.size() > 1 && coeffs.back() == T(0)) {
            coeffs.pop_back();
        }
    }


    void input() {
        coeffs.clear();
        cout << "input coeffs polynome, start from c0" << endl;
        cout << "input 0 for break" << endl;

        T val;
        while (cin >> val) {
            if (val == T(0) && coeffs.empty()) {
                coeffs.push_back(T(0));
                break;
            } else if (val == T(0) && coeffs.size() > 0) {
                break;
            }
            coeffs.push_back(val);
        }
        removeOddZeros();
    }


    friend ostream& operator<<(ostream &output, const Polynomial<T>& p) {
        int degree = 0;

        if (p.coeffs.empty() || (p.coeffs.size() == 1 && p.coeffs.front() == T(0))) {
            return output << "0";
        }

        for (auto it = p.coeffs.begin(); it != p.coeffs.end(); ++it) {
            const T& coeff = *it;

            if (coeff == T(0)) {
                degree++;
                continue;
            }

            if (it != p.coeffs.begin() && coeff > T(0)) {
                output << " + ";
            } else if (coeff < T(0)) {
                output << " - ";
            }

            T abs_coeff = coeff < T(0) ? T(0) - coeff : coeff;

            if (degree == 0 || (degree > 0 && abs_coeff != T(1))) {
                output << abs_coeff;
            }

            if (degree == 1) {
                output << "x";
            } else if (degree > 1) {
                output << "x^" << degree;
            }
            degree++;
        }
        return output;

    }

    Polynomial<T> operator+(const Polynomial<T>& other) const {
        std::list<T> result_coeffs;

        const std::list<T>& longer = (coeffs.size() > other.coeffs.size()) ? coeffs : other.coeffs;
        const std::list<T>& shorter = (coeffs.size() > other.coeffs.size()) ? other.coeffs : coeffs;

        auto it1 = coeffs.begin();
        auto it2 = other.coeffs.begin();

        while (it1 != coeffs.end() && it2 != other.coeffs.end()) {
            result_coeffs.push_back(*it1 + *it2);
            ++it1;
            ++it2;
        }

        auto remaining_it = (coeffs.size() > other.coeffs.size()) ? it1 : it2;
        auto remaining_end = (coeffs.size() > other.coeffs.size()) ? coeffs.end() : other.coeffs.end();

        while (remaining_it != remaining_end) {
            result_coeffs.push_back(*remaining_it);
            ++remaining_it;
        }

        Polynomial<T> result(result_coeffs);
        result.removeOddZeros();
        return result;
    }

    Polynomial<T> operator*(const Polynomial<T>& other) const {
        int max_degree = coeffs.size() + other.coeffs.size();
        std::vector<T> result_vec(max_degree, T(0));

        int i = 0;
        for (const T& c1 : coeffs) {
            int j = 0;
            for (const T& c2 : other.coeffs) {
                result_vec[i + j] = result_vec[i + j] + c1 * c2;
                j++;
            }
            i++;
        }

        Polynomial<T> result(std::list<T>(result_vec.begin(), result_vec.end()));
        result.removeOddZeros();
        return result;
    }

    T evaluate(T x) const {
        T result = T(0);
        T power_x = T(1);

        for (const T& coeff : coeffs) {
            result = result + coeff * power_x;
            power_x = power_x * x;
        }
        return result;
    }


};


int main() {

    cout << fixed << setprecision(3);

    cout << "int " << endl;

    // P1(x) = 1 + 2x + 3x^2
    Polynomial<int> p1({1, 2, 3});
    cout << "P1(x): " << p1 << endl;

    // P2(x) = 5 + x
    Polynomial<int> p2({5, 1});
    cout << "P2(x): " << p2 << endl;

    // P3(x) = 6 + 3x + 3x^2
    Polynomial<int> p3 = p1 + p2;
    cout << "P1 + P2: " << p3 << endl; // Очікується: 6 + 3x + 3x^2

    //  P4(x) = (1+2x+3x^2)(5+x) = 5+11x+17x^2+3x^3
    Polynomial<int> p4 = p1 * p2;
    cout << "P1 * P2: " << p4 << endl; // Очікується: 5 + 11x + 17x^2 + 3x^3

    // P1(2) = 1 + 2(2) + 3(4) = 17
    cout << "P1(2): " << p1.evaluate(2) << endl; // Очікується: 17


    cout << "\n Rational " << endl;

    // R1(x) = 1/2 + 1/3 x
    Polynomial<Rational> r1({Rational(1, 2), Rational(1, 3)});
    cout << "R1(x): " << r1 << endl;

    // R2(x) = 1/4
    Polynomial<Rational> r2({Rational(1, 4)});
    cout << "R2(x): " << r2 << endl;

    //  R1 + R2 = (1/2 + 1/4) + 1/3 x = 3/4 + 1/3 x
    Polynomial<Rational> r3 = r1 + r2;
    cout << "R1 + R2: " << r3 << endl; // Очікується: 3/4 + 1/3 x

    // R1(2) = 1/2 + 1/3 (2) = 1/2 + 2/3 = 7/6
    cout << "R1(2): " << r1.evaluate(Rational(2)) << endl; // Очікується: 7/6

    return 0;
}