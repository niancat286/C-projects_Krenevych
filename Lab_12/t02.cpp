#include <iostream>
#include <cmath>
#include <cstdlib>  // strtoull

using namespace std;

typedef unsigned long long ULL;


int main() {
    ULL mas[10];
    ULL x,  sum = 0;
    int count = 0;
    char temp[11];
    char* pos;
    string s;


    // ЧИТАЄМО ОДИН РЯДОК (Enter завершує)
    getline(cin, s);

    // Розбиваємо по 10 символів
    for (size_t i = 0; i + 10 <= s.size(); i += 10) {
        string chunk = s.substr(i, 10);
        x = strtoull(chunk.c_str(), &pos, 10);
        mas[count++] = x;
    }

    // додаємо всі числа
    for (int i = 0; i < count; i++) {
        sum += mas[i];
    }

    cout << "sum = " << sum << "\n";
}
