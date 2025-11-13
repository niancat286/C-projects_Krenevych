#include <iostream>
#include <cmath>
#include <float.h>
#include <vector>
using namespace std;


class Circle{
    double x, y;
    double r;

    public:

    Circle(double xc = 0, double yc = 0, double radius = 1)
        : x(xc), y(yc), r(radius) {}

    double getX() const { return x; }
    double getY() const { return y; }
    double getR() const { return r; }

    double diameter() const {
        return 2 * r;
    }

    double area() const {
        return M_PI * r * r;
    }

    double perimeter() const {
        return 2 * M_PI * r;
    }

    // --- Перетин двох кіл ---
    // Повертає 0, 1 або 2 точки через масив points[2][2]
    int intersect(const Circle& c, double points[2][2]) const {
        double dx = c.x - x;
        double dy = c.y - y;
        double d = sqrt(dx * dx + dy * dy);

        // Немає перетину
        if (d > r + c.r || d < fabs(r - c.r) || d == 0) {
            return 0;
        }

        // Одна точка (дотикаються)
        if (fabs(d - (r + c.r)) < DBL_EPSILON || fabs(d - fabs(r - c.r)) < DBL_EPSILON) {
            double a = (r * r - c.r * c.r + d * d) / (2 * d);
            double px = x + a * dx / d;
            double py = y + a * dy / d;
            points[0][0] = px;
            points[0][1] = py;
            return 1;
        }

        // Дві точки
        double a = (r * r - c.r * c.r + d * d) / (2 * d);
        double h = sqrt(r * r - a * a);

        double xm = x + a * dx / d;
        double ym = y + a * dy / d;

        points[0][0] = xm + h * (-dy) / d;
        points[0][1] = ym + h * ( dx) / d;

        points[1][0] = xm - h * (-dy) / d;
        points[1][1] = ym - h * ( dx) / d;

        return 2;
    }
};

void centerOfMass(Circle arr[], int count, double& cx, double& cy) {
    if (count == 0) {
        cx = cy = 0;
        return;
    }

    double sumX = 0;
    double sumY = 0;

    for (int i = 0; i < count; i++) {
        sumX += arr[i].getX();
        sumY += arr[i].getY();
    }

    cx = sumX / count;
    cy = sumY / count;
}

int main() {
    Circle c1(0, 0, 5);
    Circle c2(8, 0, 3);
    Circle c3(5, 0, 2);

    cout << "Коло c1: центр (0,0), r=5\n";
    cout << "Діаметр: " << c1.diameter() << endl;
    cout << "Площа: " << c1.area() << endl;
    cout << "Периметр: " << c1.perimeter() << endl << endl;

    double pts[2][2];
    int k = c1.intersect(c2, pts);

    cout << "Перетин c1 та c2: " << k << " точок\n";
    for (int i = 0; i < k; i++) {
        cout << "Точка " << (i+1) << ": (" << pts[i][0] << ", " << pts[i][1] << ")\n";
    }
    cout << endl;

    k = c1.intersect(c3, pts);
    cout << "Перетин c1 та c3: " << k << " точок\n";
    for (int i = 0; i < k; i++) {
        cout << "Точка " << (i+1) << ": (" << pts[i][0] << ", " << pts[i][1] << ")\n";
    }
    cout << endl;

    k = c2.intersect(c3, pts);
    cout << "Перетин c2 та c3: " << k << " точок\n";
    for (int i = 0; i < k; i++) {
        cout << "Точка " << (i+1) << ": (" << pts[i][0] << ", " << pts[i][1] << ")\n";
    }
    cout << endl;

    Circle arr[3] = {
        Circle(0, 0, 5),
        Circle(4, 0, 3),
        Circle(2, 6, 2)
    };

    double cx, cy;
    centerOfMass(arr, 3, cx, cy);

    cout << "Центр мас: (" << cx << ", " << cy << ")\n";

    return 0;

}
