#include "Rational.h"

int main() {
    try {
        Rational r1, r2;
        cout << "Enter first rational (num den): ";
        cin >> r1;
        cout << "Enter second rational (num den): ";
        cin >> r2;

        cout << "Sum: " << (r1 + r2) << endl;
        cout << "Diff: " << (r1 - r2) << endl;
        cout << "Prod: " << (r1 * r2) << endl;
        cout << "Quot: " << (r1 / r2) << endl;
        cout << "Quot: " << (r2 / r1) << endl;

        writeToFile(r1, "output.txt");
        writeToFile(r2, "output.txt");
        writeToFile(r1 + r2, "output.txt");
        cout << "Rational written to file successfully." << endl;
    }
    catch (const RationalError& e) {
        cerr << "[Rational exception] " << e.what() << endl;
    }

    try {
        // Створюємо правильний дріб
        Rational r1(3, 4);
        cout << "Created rational: " << r1 << endl;

        // 1 Коректний запис у файл
        writeToFile(r1, "output.txt");
        cout << " File 'output.txt' written successfully.\n";

        // 2 Некоректна спроба запису (файл у неіснуючій директорії)
        cout << "\nNow trying to write to a non-existent folder..." << endl;

        // Шлях, який майже гарантовано не існує
        writeToFile(r1, "/nonexistent_folder/output.txt");

        cout << "This line should not be reached!" << endl;
    }
    catch (const RationalError& e) {
        cerr << "RationalError caught: " << e.what() << endl;
    }

    return 0;
}