#include <iostream>
#include <fstream>

using namespace std;

class Polynomial {
private:
    int N;           // кількість коефіцієнтів
    double* a;       // масив коефіцієнтів

public:
    Polynomial(int n = 0) {
        N = n;
        if (N > 0)
            a = new double[N];
        else
            a = nullptr;
    }

    // --- Копі-конструктор ---
    Polynomial(const Polynomial& other) {
        N = other.N;
        if (N > 0) {
            a = new double[N];
            for (int i = 0; i < N; i++)
                a[i] = other.a[i];
        } else {
            a = nullptr;
        }
    }

    // --- Оператор присвоювання ---
    Polynomial& operator=(const Polynomial& other) {
        if (this == &other) return *this;

        delete[] a;

        N = other.N;
        if (N > 0) {
            a = new double[N];
            for (int i = 0; i < N; i++)
                a[i] = other.a[i];
        } else {
            a = nullptr;
        }

        return *this;
    }

    // --- Деструктор ---
    ~Polynomial() {
        delete[] a;
    }

    void fill(double value) {
        for (int i = 0; i < N; i++)
            a[i] = value;
    }

    void setCoeff(int index, double value) {
        if (index >= 0 && index < N)
            a[index] = value;
    }

    void print() const {
        for (int i = 0; i < N; i++) {
            cout << a[i] << "x^" << i;
            if (i != N - 1) cout << " + ";
        }
        cout << endl;
    }

    friend void writeBinary(const Polynomial& p, const char* filename) {
        ofstream out(filename, ios::binary);
        out.write((char*)&p.N, sizeof(int));
        out.write((char*)p.a, sizeof(double) * p.N);
        out.close();
    }

    friend void readBinary(Polynomial& p, const char* filename) {
        ifstream in(filename, ios::binary);
        in.read((char*)&p.N, sizeof(int));

        delete[] p.a;
        p.a = new double[p.N];

        in.read((char*)p.a, sizeof(double) * p.N);
        in.close();
    }
};

int main() {
    Polynomial p(3);
    p.setCoeff(0, 1.0);
    p.setCoeff(1, -2.0);
    p.setCoeff(2, 3.5);

    cout << "Поліном p(x): ";
    p.print();

    writeBinary(p, "poly.bin");

    Polynomial q;
    readBinary(q, "poly.bin");

    cout << "Прочитаний q(x): ";
    q.print();

    return 0;
}
