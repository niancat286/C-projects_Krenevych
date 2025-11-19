#include <chrono>
#include <string>
#include <iostream>
using namespace std;
#define N 10


class Person {
    protected:
        string name;
        unsigned byear;

    public:
        Person() {};
        Person(string name, unsigned byear) : name(name), byear(byear) {};

        int input();
        void show();
        string get_name();
};

class Friend : public Person {
    string num_phone;

public:
    Friend() {};
    Friend(string name, unsigned year, string num_phone) : Person(name, year), num_phone(num_phone) {}

    string get_phone();
    void set_phone(string num_phone);
};


int Person::input() {
    cout << "Please input your name and birth year:" << endl;
    cin >> name >> byear;
}

void Person::show() {
    cout << "name:" << name << " birth year:" << byear << endl;
}


class Phonebook {
    unsigned n;
    Friend data[N];


    public:
        Phonebook() : n(0) {}

        void add_Friend(Friend &f);
        void add_Friends(Friend* data, unsigned n);
        string find_phone(string name);
};


void Phonebook::add_Friend(Friend &f) {
    if (n < N) {
        data[n++] = f;
    }
}

string Person::get_name() {
    return name;
}

void Friend::set_phone(string num) {
    num_phone = num;
}

string Friend::get_phone() {
    return num_phone;
}

string Phonebook::find_phone(string name) {
    for (unsigned i = 0; i < n; i++) {
        if (data[i].get_name() == name) {
            return data[i].get_phone();
        }
    }
}



int main() {
    Person p;
    p.input();
    p.show();

    Friend f("Alice", 1990, "1234567890");

    Phonebook pb;

    pb.add_Friend(f);
    cout << "Alice phone" << endl;
    cout << pb.find_phone("Alice") << endl;

    Friend R[100];
    string num;
    for (unsigned i = 0; i < 100; i++) {
        R[i].input();
        cin >> num;
        R[i].set_phone(num);
        pb.add_Friend(R[i]);
    }
    cout << pb.find_phone("Alice") << endl;
}

