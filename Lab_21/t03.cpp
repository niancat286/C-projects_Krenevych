#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


long long sum_largest(const vector<int>& V, size_t k) {
    if (k == 0 || k > V.size()) {
        return 0;
    }

    vector<int> temp_V = V;

    sort(temp_V.begin(), temp_V.end(), [](int a, int b) {
        return a > b;
    });

    long long sum = 0;
    for (size_t i = 0; i < k; ++i) {
        sum += temp_V[i];
    }

    return sum;
}


vector<int> get_smallest(const vector<int>& V, size_t k) {
    if (k == 0 || k > V.size()) {
        return {};
    }

    vector<int> temp_V = V;

    sort(temp_V.begin(), temp_V.end());

    vector<int> res(temp_V.begin(), temp_V.begin() + k);

    return res;
}



int main() {
    vector<int> data = {10, 3, 40, 5, 20, 15, 50, 2};
    size_t k_val = 3;

    cout << "{10, 3, 40, 5, 20, 15, 50, 2}, K = " << k_val << endl;

    // a
    long long max_sum = sum_largest(data, k_val);
    cout << "\nsum " << k_val << " max numbers: " << max_sum << endl;

    // b
    vector<int> min_array = get_smallest(data, k_val);
    cout << "arr " << k_val << " min num: {";
    for (int x : min_array) {
        cout << x << (x == min_array.back() ? "" : ", ");
    }
    cout << "}" << endl;

    return 0;
}