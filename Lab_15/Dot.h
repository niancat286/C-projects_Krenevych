#ifndef C_PROJECTS_KRENEVYCH_DOT_H
#define C_PROJECTS_KRENEVYCH_DOT_H

#include <cmath>

class Dot {
private:
    double x, y;
    static int countPoints;
public:
    Dot(double _x = 0, double _y = 0) {
        x = _x;
        y = _y;
        countPoints++;
    }

    double getX() const { return x; }
    double getY() const { return y; }

    static int counter() {
        return countPoints;
    }

    double distance(const Dot& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx*dx + dy*dy);
    }
};



#endif //C_PROJECTS_KRENEVYCH_DOT_H