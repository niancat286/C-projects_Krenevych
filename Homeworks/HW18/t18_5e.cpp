#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

template <typename T>
class Array {
private:
    vector<T> data;
    size_t size_;

public:
    Array(const vector<T>& initial_data) : data(initial_data), size_(initial_data.size()) {}

    // Метод для виведення масиву
    void print() const {
        cout << "[";
        for (size_t i = 0; i < size_; ++i) {
            cout << data[i] << (i == size_ - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }

    size_t size() const {
        return size_;
    }

    void insertionSort() {
        Array::staticInsertionSort(data);
    }

    static void staticInsertionSort(vector<T>& arr) {
        size_t n = arr.size();


        for (size_t i = 1; i < n; ++i) {
            T key = arr[i];
            long long j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    static void staticInsertionSort(T arr[], size_t n) {
        for (size_t i = 1; i < n; ++i) {
            T key = arr[i];
            long long j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
};


int main() {
    vector<int> int_data = {5, 2, 8, 1, 9, 4};
    Array<int> intArray(int_data);

    cout << "array before sort \n";
    intArray.print();

    intArray.insertionSort();

    cout << "array after sort \n";
    intArray.print();

    vector<double> double_data = {3.14, 0.5, 9.9, 2.71, 1.0};

    cout << "vector before sort [";
    for(double d : double_data) cout << d << " ";
    cout << "]" << endl;

    Array<double>::staticInsertionSort(double_data);

    cout << "vector after sort [";
    for(double d : double_data) cout << d << " ";
    cout << "]" << endl;

    return 0;
}

