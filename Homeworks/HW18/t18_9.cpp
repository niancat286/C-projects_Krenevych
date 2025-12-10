#include <iostream>
#include <type_traits>
#include <string>

using namespace std;


template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type
sum(T* x, size_t n) {
    T result = T();

    for(size_t i = 0; i < n; i++) {
        result += x[i];
    }
    return result;
}


string sum(string* x, size_t n) {
    string result = "";
    for(size_t i = 0; i < n; i++) {
        result += x[i];
    }
    return result;
}


string sum(char* x, size_t n) {
    string result(x, n);
    return result;
}

string sum(int** x, size_t n) {
    string result = "";

    for (size_t i = 0; i < n; ++i) {
        if (x[i] != nullptr) {
            result += to_string(*x[i]);
        }
    }
    return result;
}



int main() {
    int v1[] = {1, 2, 3};
    cout << "v1 (int) = " << sum(v1, 3) << endl;

    double v2[] = {1.0, 2.0, 3.0};
    cout << "v2 (double) = " << sum(v2, 3) << endl;

    std::string v3[] = {"a", "bc", "def"};
    cout << "v3 (string) = " << sum(v3, 3) << endl;

    char v4[] = {'a', 'b', 'c'};
    cout << "v4 (char) = " << sum(v4, 3) << endl;

    int a = 1, b = 2, c = 3;
    int* p1 = &a;
    int* p2 = &b;
    int* p3 = &c;
    int* v5[] = {p1, p2, p3};

    cout << "v5 (int* - конкат значень) = " << sum(v5, 3) << endl;
    return 0;
}