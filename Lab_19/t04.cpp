//
// Created by Yaroslava Krenevych on 26.11.2025.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>


using namespace std;

using Matrix = vector<list<int>>;


Matrix input_matrix(int n, int m) {
    Matrix matrix(n);
    cout << "Введіть елементи матриці " << n << "x" << m << " по рядках:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val;
            if (!(cin >> val)) {
                cerr << "Помилка введення. Використовуйте 0." << endl;
                val = 0;
            }
            matrix[i].push_back(val);
        }
    }

    return matrix;
}

void print_matrix(const Matrix& matrix) {
    if (matrix.empty()) return;

    cout << "Матриця " << matrix.size() << "x" << matrix[0].size() << ":" << endl;

    for (const auto& row_list : matrix) {
        for (int val : row_list) {
            cout << val << " ";
        }
        cout << endl;
    }
}


Matrix sort_max(const Matrix& matrix) {
    if (matrix.empty()) return matrix;


    int n = matrix.size();

    vector<pair<int, int>> criteria;

    for (int i = 0; i < n; ++i) {
        const auto& row_list = matrix[i];

        if (row_list.empty()) continue;

        auto max_it = max_element(row_list.begin(), row_list.end());

        criteria.push_back({*max_it, i});
    }

    sort(criteria.begin(), criteria.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.first > b.first;
         });

    Matrix sorted;

    for (int i = 0; i < n; ++i) {
        int original_index = criteria[i].second;
        int max_val = criteria[i].first;

        sorted.push_back(matrix[original_index]);
        cout << "  #" << i + 1 << " Рядок (Індекс " << original_index << ") Max: " << max_val << endl;
    }
    return sorted;

}




int main() {
    int n, m;
    cout << "Enter n" << endl;
    cin >> n;
    cout << "Enter m" << endl;
    cin >> m;

    Matrix my_matrix = input_matrix(n, m);

    cout << "\n вхідна матриця\n";
    print_matrix(my_matrix);

    Matrix sorted_matrix = sort_max(my_matrix);

    cout << "\nвідсортована матриця\n";
    print_matrix(sorted_matrix);

    return 0;
}