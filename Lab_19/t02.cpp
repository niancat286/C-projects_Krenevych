//
// Created by Yaroslava Krenevych on 26.11.2025.
//


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


vector<int> input_vector(int d) {
    vector<int> v;
    int elem;

    cout << "Введіть " << d << " компонент(и) вектора (числа):" << endl;

    for (int i = 0; i < d; i++) {
        cout << "елемент " << i + 1 << ": " << endl;


        if (cin >> elem) {
            v.push_back(elem);
        }
        else {
            cerr << "Помилка введення" << endl;
            cin.clear();
            break;
        }

    }
    return v;
}


double calc_norm(const vector<int>& vec) {
    double sum_of_squares = 0.0;
    for (double el : vec) {
        sum_of_squares += el * el;
    }
    return sqrt(sum_of_squares);
}


int main() {
    int n;
    int d;
    cout << "Введіть розмірність векторів (d): ";
    if (!(cin >> d) || d <= 0) {
        cerr << "Некоректна розмірність." << endl;
        return 2;
    }

    cout << "Введіть кількість векторів (n): ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Некоректна кількість векторів." << endl;
        return 2;
    }

    double total_norm_sum = 0.0;

    for (int i = 0; i < n; i++) {
        cout << "\nВведення вектора #" << i + 1 << " (" << d << "-вимірний):\n";
        vector<int> curr = input_vector(d);

        if (curr.size() != d) {
            cerr << "Вектор проігноровано через помилку введення.\n";
            continue;
        }

        double current_norm = calc_norm(curr);

        total_norm_sum += current_norm;

        cout << "Норма вектора #" << i + 1 << ": " << current_norm << endl;
    }
    cout << "Сума норм усіх " << n << " векторів: " << total_norm_sum << endl;
    return 0;
}