#include "Dot.h"

#include <iostream>
#include <cmath>
using namespace std;

double dist(const Dot& a, const Dot& b) {
    double dx = a.getX() - b.getX();
    double dy = a.getY() - b.getY();
    return sqrt(dx*dx + dy*dy);
}

int Dot::countPoints = 0;

int main() {

    Dot* polygon = nullptr;
    int n = 0;

    while (true) {
        cout << "Ввести вершину? (Так/Ні): ";
        string ans;
        cin >> ans;

        if (ans == "Ні" || ans == "ні" || ans == "No" || ans == "no")
            break;

        double x, y;
        cout << "x, y:  ";
        cin >> x >> y;

        // розширюємо масив
        Dot* temp = new Dot[n + 1];
        for (int i = 0; i < n; i++)
            temp[i] = polygon[i];
        temp[n] = Dot(x, y);
        delete[] polygon;
        polygon = temp;
        n++;
    }

    cout << "\nКількість вершин: " << n << endl; //кількість самих обʼєктів класу Dot буде більше, бо створено також копії

    // обчислення периметра
    double perimeter = 0;
    if (n > 1) {
        for (int i = 0; i < n; i++) {
            perimeter += dist(polygon[i], polygon[(i + 1) % n]); //рахуємо по тому в якому порядку вони введені в масив
        }
    }

    cout << "Периметр багатокутника = " << perimeter << endl;

    delete[] polygon;
    return 0;
}
