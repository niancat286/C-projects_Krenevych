//
// Created by Yaroslava Krenevych on 03.12.2025.
//



#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;


void count(const char* fname) {
    map<string, int> word_counts;
    ifstream fin(fname);

    if (!fin.is_open()) {
        cerr << "erorr open" << endl;
        return;
    }
    string word;

    while (fin >> word) {
        word_counts[word]++;
    }
    fin.close();

    for (const auto& p : word_counts) {
        cout << p.first << " " << p.second << endl;
    }

    cout << "\nЗнайдено " << word_counts.size() << " унікальних слів.\n";
}

int main() {
    const char* fname = "test.txt";
    ofstream test_file(fname);
    test_file << "The quick brown fox jumps over the lazy dog." << endl;
    test_file << "Dog, dog, and fox. The FOX is quick!" << endl;

    count("test.txt");
}
