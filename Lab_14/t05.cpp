#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>


void create_file(const char* fname) {
    std::ofstream f(fname);

    if (!f.is_open()) {
        std::cerr << "error. can't open " << fname << std::endl;
        return;
    }

    int n;
    std::cout << "n=";
    if (!(std::cin >> n) || n <= 0) {
         std::cerr << "incorrect num of students\n";
         n = 1;
    }

    std::string surname, name, group, mark;

    std::cout << "input info: surname, name, group, mark:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Student " << i + 1 << ": ";
        std::cin >> surname >> name >> group >> mark;
        f << surname << " " << name << " " << group << " " << mark << std::endl;
    }
    f.close();
}

std::string worst_student(const char* fname) {
    std::string worst_full_name = "No data";
    double min_avg_mark = 101.0;

    std::ifstream f(fname);

    if (!f.is_open()) {
        std::cerr << "error. can't open " << fname << std::endl;
        return worst_full_name;
    }

    std::string line;

    while (std::getline(f, line)) {

        // Використовуємо stringstream для розбору даних
        std::stringstream sline(line);

        std::string surname, name, group;
        double mark;

        if (!(sline >> surname >> name >> group >> mark)) {
            continue;
        }

        if (mark < min_avg_mark) {
            min_avg_mark = mark;
            worst_full_name = surname + " " + name;
        }
    }

    f.close();
    return worst_full_name;
}


int main() {
    const char* filename = "students_data.txt";
    create_file(filename);

    std::string worst_s = worst_student(filename);

    std::cout << "Worst student: " << worst_s << std::endl;

    return 0;
}