#include <float.h>
#include <iostream>

using namespace std;


class Quadratic {
    double a, b, c;

    public:
    Quadratic(double a, double b, double c) : a(a), b(b), c(c) {}

    double D() const {
        return b*b - 4*a*c;
    }

    int roots(double& x1, double& x2) const {
        double d = D();

        if (d < 0) return 0;

        else if (fabs(d) < DBL_EPSILON) {
            x1 = x2 = -b / (2*a);
            return 1;
        }
            else {
                double sqrtD = sqrt(d);
                x1 = (-b + sqrtD) / (2*a);
                x2 = (-b - sqrtD) / (2*a);
                return 2;
            }
    }

    void extremum(double& xv, double& yv) const {
        xv = -b / (2*a);
        yv = a*xv*xv + b*xv + c;
    }

    void intervals() const {
        double xv = -b / (2*a);

        if (a > 0) {
            cout << "Спадає: (-inf ; " << xv << ")\n";
            cout << "Зростає: (" << xv << " ; +inf)\n";
        }
        else {
            cout << "Зростає: (-inf ; " << xv << ")\n";
            cout << "Спадає: (" << xv << " ; +inf)\n";
        }
    }
};



int main() {
    const int N = 5;
    Quadratic q[N] = {
        Quadratic(1, -3, 2),   // x^2 - 3x + 2 = 0, корені 1 і 2
        Quadratic(2, 4, -6),
        Quadratic(1, 2, 1),    // дискримінант = 0
        Quadratic(3, 0, -3),
        Quadratic(1, 1, 10)    // немає коренів
    };

    double globalMin = DBL_EPSILON;
    double globalMax = -DBL_EPSILON;

    for (int i = 0; i < N; i++) {
        cout << "Рівняння #" << i+1 << endl;

        double x1, x2;
        int k = q[i].roots(x1, x2);

        if (k == 0) {
            cout << "Коренів немає.\n";
        }
        else if (k == 1) {
            cout << "Один корінь: x = " << x1 << endl;

            if (x1 < globalMin) globalMin = x1;
            if (x1 > globalMax) globalMax = x1;
        }
        else {
            cout << "Два корені: x1 = " << x1 << ", x2 = " << x2 << endl;

            if (x1 < globalMin) globalMin = x1;
            if (x1 > globalMax) globalMax = x1;

            if (x2 < globalMin) globalMin = x2;
            if (x2 > globalMax) globalMax = x2;
        }

        double xv, yv;
        q[i].extremum(xv, yv);
        cout << "Екстремум: x = " << xv << ", y = " << yv << endl;

        q[i].intervals();

        cout << endl;
    }

    cout << "=== Найменший корінь: " << globalMin << endl;
    cout << "=== Найбільший корінь: " << globalMax << endl;

    return 0;
}
