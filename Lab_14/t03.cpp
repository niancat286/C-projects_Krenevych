#include <iostream>
#include <fstream>
using namespace std;

bool isDelimiter(char c) {
    return c == ' ' || c == ',' || c == '.' || c == '!' || c == '?';
}

void reverse(string &s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Can't open files" << endl;
        return -1;
    }
    string word;
    char c;
    while (fin.get(c)) {
        if (isDelimiter(c)) {
            reverse(word);
            fout << word;
            word.clear();
            fout << c;
        }
        else {
            word += c;
        }
    }
    reverse(word);
    fout << word;
    fout.close();
    return 0;
}