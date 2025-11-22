#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// ============================
//       CUSTOM EXCEPTION
// ============================
class InputException : public std::runtime_error {
public:
    explicit InputException(const std::string& msg)
        : std::runtime_error("Input error: " + msg) {}
};

// ============================
//          PERSON
// ============================
class Person {
protected:
    string name;
    string sex;
    unsigned int age{0};
    string university;   // університет винесено сюди

public:
    Person() = default;
    Person(string name, string sex, unsigned int age, string university = "N/A")
        : name(name), sex(sex), age(age), university(university) {}

    virtual ~Person() = default;

    virtual void input() {
        cout << "Enter name: ";
        cin >> name;
        if (name.empty()) throw InputException("Empty name");

        cout << "Enter sex (M/F): ";
        cin >> sex;
        if (sex != "M" && sex != "F")
            throw InputException("Unknown sex: " + sex);

        cout << "Enter age: ";
        cin >> age;
        if (age == 0 || age > 120)
            throw InputException("Invalid age: " + to_string(age));

        cout << "Enter university: ";
        cin >> university;
        if (university.empty())
            throw InputException("Empty university");
    }

    virtual void show() const {
        cout << "Name: " << name
             << "\nSex: " << sex
             << "\nAge: " << age
             << "\nUniversity: " << university << endl;
    }

    virtual string get_university() const { return university; }
    virtual void set_university(const string& u) { university = u; }
};

// ============================
//          STUDENT
// ============================
class Student : virtual public Person {
protected:
    unsigned int course{0};
    string group;

public:
    Student() = default;
    Student(string name, string sex, unsigned int age,
            unsigned int course, string group, string university)
        : Person(name, sex, age, university), course(course), group(group) {}

    void input() override {
        Person::input();

        cout << "Enter course: ";
        cin >> course;
        if (course == 0 || course > 6)
            throw InputException("Invalid course number");

        cout << "Enter group: ";
        cin >> group;
        if (group.empty())
            throw InputException("Empty group");
    }

    void show() const override {
        Person::show();
        cout << "Course: " << course
             << "\nGroup: " << group << endl;
        cout << "------------------------\n";
    }
};

// ============================
//          TEACHER
// ============================
class Teacher : virtual public Person {
protected:
    string position;
    double salary{0};

public:
    Teacher() = default;
    Teacher(string name, string sex, unsigned int age,
            string university, string position, double salary)
        : Person(name, sex, age, university), position(position), salary(salary) {}

    void input() override {
        Person::input();

        cout << "Enter position: ";
        cin >> position;
        if (position.empty())
            throw InputException("Empty position");

        cout << "Enter salary: ";
        cin >> salary;
        if (salary < 0)
            throw InputException("Salary cannot be negative");
    }

    void show() const override {
        Person::show();
        cout << "Position: " << position
             << "\nSalary: " << salary << endl;
        cout << "------------------------\n";
    }
};

// ============================
//          ASPIRANT
// ============================
class Aspirant : public Student, public Teacher {
public:
    Aspirant() = default;

    Aspirant(string name, string sex, unsigned int age,
             unsigned int course, string group, string university,
             string position, double salary)
        : Person(name, sex, age, university),
          Student(name, sex, age, course, group, university),
          Teacher(name, sex, age, university, position, salary) {}

    void input() override {
        Person::input();

        cout << "Enter course: ";
        cin >> course;

        cout << "Enter group: ";
        cin >> group;

        cout << "Enter position: ";
        cin >> position;

        cout << "Enter salary: ";
        cin >> salary;
        if (salary < 0)
            throw InputException("Salary cannot be negative");
    }

    void show() const override {
        Person::show();
        cout << "Course: " << course
             << "\nGroup: " << group
             << "\nPosition: " << position
             << "\nSalary: " << salary << endl;
        cout << "------------------------\n";
    }
};

// ============================
//            MAIN
// ============================
int main() {
    try {
        Person* arr[3];

        arr[0] = new Student();
        arr[1] = new Teacher();
        arr[2] = new Aspirant();

        for (int i = 0; i < 3; ++i) {
            cout << "\nInput object #" << (i + 1) << endl;
            arr[i]->input();
        }

        cout << "\n===== OUTPUT =====\n";
        for (int i = 0; i < 3; ++i) {
            arr[i]->show();
            cout << "Correct university: " << arr[i]->get_university() << endl;
        }

        for (int i = 0; i < 3; ++i)
            delete arr[i];

    } catch (const InputException& e) {
        cerr << e.what() << endl;
    }
    return 0;
}