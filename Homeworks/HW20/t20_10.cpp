#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void find_same(const string& fname) {
    vector<int> v;
    cout << "Enter numbers (0 for break):" << endl;
    int input_n;

    while (cin >> input_n && input_n != 0) {
        v.push_back(input_n);
    }

    if (v.size() < 2) {
        cerr << "Not enough numbers entered" << endl;
        return;
    }

    size_t m = v.size() / 2;

    vector<int> v1(v.begin(), v.begin() + m);
    vector<int> v2(v.begin() + m, v.end());

    /*
    cout << "\nПерша половина V1: ";
    for(int x : v1) cout << x << " "; cout << endl;
    cout << "Друга половина V2: ";
    for(int x : v2) cout << x << " "; cout << endl;
    */

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());


    vector<int> res;

    set_intersection(
        v1.begin(), v1.end(),
        v2.begin(), v2.end(),
        back_inserter(res)
    );

    ofstream fout(fname);

    if (!fout.is_open()) {
        cerr << "error in creating file" << fname << endl;
        return;
    }

    cout << "\n result ";

    for (int num : res) {
        fout << num << " ";
        cout << num << " ";
    }

    fout.close();
}


int main() {
    const string outfile = "outfile20_10.txt";
    find_same(outfile);

    return 0;
}