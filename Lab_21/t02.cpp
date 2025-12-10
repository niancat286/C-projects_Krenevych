#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void simple_partition_list() {
    list<int> numbers = {5, 1, 8, 2, 9, 3};
    int X = 4;

    cout << "Початковий список: 5, 1, 8, 2, 9, 3" << endl;
    cout << "Роздільник X = 4" << endl;

    std::partition(
        numbers.begin(),
        numbers.end(),
        [X](int val) {
            return val <= X;
        }
    );

    cout << "Res (elems <= 4, after > 4):" << endl;
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;
}

int main() {
    simple_partition_list();
    return 0;
}