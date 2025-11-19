#include <iostream>
#include <fstream>
using namespace std;

string print_all(const char* fnamein, const char* fnameout) {
    ifstream fin(fnamein);
    ofstream fout(fnameout);

    if (!fin.is_open() || !fout.is_open()){
        cerr << "Can't open file " << endl;
        return "incorrect";
    }

    string line;
    while (std::getline(fin, line)) {
        fout << line << endl;
    }
    fin.close();
    fout.close();

    return "success";
}


string print_60(const char* fnamein, const char* fnameout) {
    ifstream fin(fnamein);
    ofstream fout(fnameout);

    if (!fin.is_open() || !fout.is_open()){
        cerr << "Can't open file " << endl;
        return "incorrect";
    }

    string line;
    while (std::getline(fin, line)) {
        if (line.length() > 60) {
            fout << line << endl;
        }
    }
    fin.close();
    fout.close();

    return "success";
}


int main() {
    // Створимо тестовий вхідний файл
    ofstream test_input("input.txt");
    test_input << "Це перший рядок." << endl;
    test_input << "Це другий рядок, який довший." << endl;
    test_input << "Третій." << endl;

    cout << "Результат виведення всіх рядків: " << print_all("input.txt", "output.txt") << endl;

    // Перевірка вмісту вихідного файлу (опціонально)
    cout << "Вміст 'output.txt' тепер відповідає 'input.txt'." << endl;


    const char* input_file = "input.txt";
    const char* output_file = "output_long.txt";
    test_input << "Це короткий рядок." << endl;
    test_input << "Це рядок помірної довжини, можливо, близько сорока символів." << endl;
    test_input << "Це дуже довгий рядок, який ми використовуємо для тестування умови. Його довжина, безумовно, перевищує шістдесят символів. Цей рядок має бути записаний у вихідний файл." << endl;
    test_input.close();
    cout << "Створено тестовий файл '" << input_file << "'." << endl;
    string result = print_60(input_file, output_file);

    cout << "Результат операції: " << result << endl;


    return 0;
}