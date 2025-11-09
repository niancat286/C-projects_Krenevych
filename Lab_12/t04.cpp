#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    int n;
    cout << "n:";
    cin >> n;

    int* m = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "m[" << i << "]:";
        cin >> m[i];
    }
    char fname[] = "data.txt";
    ifstream f;
    f.open(fname);
    if (f.bad()) {
        cerr << "Can't open file " << fname << endl;
        return -1;
    }

    double * x = new double[n];
    int count = 0;
    while (f >> x[count]) {
        count++;
    }
    f.close();
    if (count<n) {
        delete[] m;
        cerr << "not enough data in " << fname << endl;
        cerr << "there are " << count << " x in file instead of " << n << endl;

        return -2;
    }

    char gname[] = "output.txt";
    ofstream g(gname);
    if (g) {
        for (int i = 0; i < n; i++) {
            double z = pow(x[i], m[i]);
            g << z << "\n";
        }
        g.close();
    }
    delete[] m;
    delete[] x;
}
