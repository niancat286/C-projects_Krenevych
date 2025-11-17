#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

string calc(const char* fname) {
    fstream f(fname);
    if (!f.is_open()) return "Can't open";

    int t = 0, sum = 0, sign = 1;
    char c;

    while (f.get(c)) {
        if (isdigit(c)) {
            t = 10 * t + (c - '0');
        }
        else if (c == '+' || c == '-' || c == '=') {
            sum += sign * t;
            t = 0;
            if (c == '+') sign = 1;
            else if (c == '-') sign = -1;
            else break; // c == '='
        }
        else return "Incorrect format";
    }
    return to_string(sum);
}

int main() {
    cout << calc("data.txt");
}
