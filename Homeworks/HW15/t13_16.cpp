#include <iostream>
#include <string>
using namespace std;


string get_with_last_letter_case1(const string& s, char ch) {
    string word = "";
    string result = "";

    for (int i = 0; i <= s.size(); i++) {
        // Якщо пробіл або кінець рядка — слово закінчилося
        if (i == s.size() || s[i] == ' ') {
            if (word.size() > 0 && word[word.size() - 1] == ch) {
                // додати в результат
                if (result.size() > 0) result += " ";
                result += word;
            }
            word = "";
        } else {
            word += s[i];
        }
    }

    return result;
}


void get_with_last_letter_case2(string& s, char ch) {
    s = get_with_last_letter_case1(s, ch);
}

int main() {
    string str1;
    char ch;

    cout << "enter string\n";
    getline(cin, str1);

    cout << "enter ending\n";
    cin >> ch;

    // Варіант 1 — новий рядок
    string res1 = get_with_last_letter_case1(str1, ch);
    cout << "\nres (new line): " << res1 << endl;

    // Варіант 2 — зміна рядка
    string sentence2 = str1;
    get_with_last_letter_case2(sentence2, ch);
    cout << "res (modified): " << sentence2 << endl;

    return 0;
}
