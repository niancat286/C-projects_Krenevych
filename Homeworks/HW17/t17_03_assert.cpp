#include <iostream>
#include <string>
#include <exception>
#include <cassert>

using namespace std;

class convertationException : public std::exception {
    string message;
public:
    explicit convertationException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

int char_to_digit(char c, unsigned int b) {
    string digits = "0123456789ABCDEF";

    if (c >= 'a' && c <= 'f')
        c = c - 'a' + 'A';

    size_t pos = digits.find(c);

    assert(pos == string::npos || pos < 16);

    // перевірка символа як цифри у поточній основі
    if (pos == string::npos || pos >= b)
        throw convertationException(string("Invalid digit '") + c + "' for base " + to_string(b));

    return (int)pos;
}

unsigned long from_base(const string& s, unsigned int b) {
    if (b < 2 || b > 16)
        throw convertationException("Invalid base! Must be between 2 and 16.");

    unsigned long result = 0;

    for (char c : s) {
        int d = char_to_digit(c, b);
        result = result * b + d;
    }
    return result;
}

int main() {
    try {
        string s = "1A3";
        unsigned int base = 16;

        unsigned long number = from_base(s, base);
        cout << s << " (base " << base << ") = " << number << endl;

        // here is error
        string bad = "19A";
        cout << from_base(bad, 10) << endl;

    } catch (const convertationException& e) {
        cerr << "exception caught: " << e.what() << endl;
    }

    return 0;
}
