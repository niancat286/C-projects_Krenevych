#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int counter(const string& line, const string& tag ) {
    int count = 0;
    size_t pos = line.find(tag, 0);
    while (pos != string::npos) {
        count++;
        pos = line.find(tag, pos + tag.length());
    }
    return count;
}


void check(const string& fname) {
    ifstream infile(fname);
    if (!infile.is_open()) {
        cerr << "error. can't open '" << fname << "'" << endl;
        return;
    }

    int balance = 0;
    string line;
    int line_number = 0;

    const string open_tag = "<td>";
    const string close_tag = "</td>";

    while (getline(infile, line)) {
        line_number++;
        int open_count = counter(line, open_tag);
        int close_count = counter(line, close_tag);
        balance += open_count - close_count;

        if (balance < 0) {
            cout << "error. open_tags < close_tags '" << fname << "'" << endl;
            infile.close();
            return;
        }
    }


    infile.close();

    if (balance == 0) {
        cout << "correct" << endl;
    } else { //balance > 0
        cout << "error. open_tags > close_tags" << endl;
        cout << "rest: " << balance << " open_tags" << std::endl;
    }
}


int main() {
    const string file_name = "tags_test.txt";
    ofstream test_output(file_name);
    test_output << "<tr><td>cell 1</td> <td>cell 2"; //we have an error here
    test_output.close();

    check(file_name);

    ofstream test_output_correct(file_name);
    test_output_correct << "<tr><td>cell 1</td><td>cell 2</td></tr>";
    test_output_correct.close();

    check(file_name);

    return 0;

}