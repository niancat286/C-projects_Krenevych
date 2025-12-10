//
// Created by Yaroslava Krenevych on 20.11.2025.
//


#include <iostream>
#include <iterator>

template <class T>
class stack {
    T data;
    stack<T>* next;
    size_t n;
public:
    stack() : next(nullptr), n(0) {}

    void reset_size() { n = 0; }
    void add(T x);
    T pop();
    bool empty() const { return next == nullptr && n == 0; }
    size_t size() const { return n; }

};

template <class T>
void stack<T>::add(T x) {
    stack<T>* new_stack = new stack<T>();

    new_stack->data = this->data;
    new_stack->next = this->next;
    new_stack->n = 0;

    this->data = x;
    this->next = new_stack;

    this->n++;
}
template <class T>
T stack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Стек порожній!");
    }
    T x = this->data;
    stack<T>* old_next = this->next;

    this->data = old_next->data;
    this->next = old_next->next;

    delete old_next;
    this->n--;
    return x;
}

template <class T>
stack<T> input_data() {
    T x;
    stack<T> s;

    s.reset_size();

    while (true) {
        std::cout << "input x: ";
        std::cin >> x;
        if (x == static_cast<T>(0)) break;
        s.add(x);
    }
    return s;
}



int main() {

    std::cout << "--- Запуск Stack (int) ---\n";
    stack<int> mas = input_data<int>();

    std::cout << "\nЕлементи POP:\n";
    while (!mas.empty()) {
        int y = mas.pop();
        std::cout << y << std::endl;
    }

    return 0;
}