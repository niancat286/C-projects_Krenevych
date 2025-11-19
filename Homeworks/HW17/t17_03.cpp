#include <iostream>
#include <string>
#include <exception>

using namespace std;

class convertationException : public std::exception {
    string message;
public:
    explicit convertationException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};


string to_base(unsigned int n, unsigned int b) {
    if (b < 2 || b > 16)
        throw convertationException("Invalid base! Must be between 2 and 16.");

    string digits = "0123456789ABCDEF";
    string result;

    if (n == 0) return "0";

    while (n > 0) {
        unsigned int rem = n % b;
        result.push_back(digits[rem]);
        n /= b;
    }

    string correct;
    for (int i = result.size() - 1; i >= 0; --i) {
        correct.push_back(result[i]);
    }
    return correct;
}


int main() {
    try {
        unsigned long number = 5679;
        unsigned int base = 16;

        string converted = to_base(number, base);
        cout << number << " in base " << base << " -> " << converted << endl;

        base = 20;
        converted = to_base(number, base);  // for exception
        cout << converted << endl;

    } catch (const convertationException& e) {
        cerr << "exception caught: " << e.what() << endl;
    }

    return 0;
}

