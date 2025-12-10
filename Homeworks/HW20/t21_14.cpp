#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include <string>
#include <sstream>

using namespace std;




set<string> read_data(const char* fname) {
    set<string> sort_uni_dates;
    ifstream fin(fname);

    if (!fin.is_open()) {
        cerr << "error, can't open" << endl;
        return sort_uni_dates;
    }

    stringstream ss;
    ss << fin.rdbuf();
    fin.close();

    int day, month, year;
    char sep;
    int processed = 0;

    while (ss >> day >> month >> year) {

        if (day > 0 && month > 0 && year > 1900) {

            stringstream date_ss;
            date_ss << year << "/"
                    << setfill('0') << setw(2) << month << "/"
                    << setfill('0') << setw(2) << day;

            sort_uni_dates.insert(date_ss.str());
            processed++;
        }
        ss >> sep;
    }

    return sort_uni_dates;
}


void print_in_file(const char* fname, const set<string>& dates) {
    ofstream fout(fname);
    if (!fout.is_open()) {
        cerr << "error, can't open" << endl;
        return;
    }

    for (auto it = dates.begin(); it != dates.end(); ++it) {
        fout << *it;

        if (std::next(it) != dates.end()) {
            fout << ", ";
        }
    }
    fout.close();
}


int main() {
    const char* input_file = "input21_14.txt";
    const char* out_file = "output21_14.txt";

    ofstream test_input(input_file);
    test_input << "15 5 2025, 5 1 2024, 15 5 2025, 1 2 2024, 5 1 2024";
    test_input.close();


    set<string> uni_dates = read_data(input_file);
    print_in_file(out_file, uni_dates);
}