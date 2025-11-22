#include <iostream>
using namespace std;
#define N 10


class Car{
    protected:
        double mileage;
        double fuel;
    public:
        Car(double fuelAmount) : mileage(0), fuel(fuelAmount) {}
        virtual double fuelPerKm() const = 0;

        bool go(double distance) {
            double need = distance * fuelPerKm();

            if (need > fuel) {
                cout << "not enough fuel\n";
                return false;
            }

            fuel -= need;
            mileage += distance;
            cout << "went " << distance << " km. now you have: " << fuel << " litres of fuel\n";
            return true;
        }

        double get_fuel() const { return fuel; }
        double get_mileage() const { return mileage; }
};


class Personal : public Car {
    int passengers;
    double baseFuel;  // базова витрата

    public:
        Personal(double fuelAmount, int pass, double base) : Car(fuelAmount), passengers(pass), baseFuel(base) {}

    double fuelPerKm() const override {
        return baseFuel * (1 + 0.10 * passengers);
    }
};

class Truck: public Car {
    double mas_tons;
    double baseFuel;

    public:
    Truck(double fuelAmount, double tonsLoad, double base)
        : Car(fuelAmount), mas_tons(tonsLoad), baseFuel(base) {}

    double fuelPerKm() const override {
        return baseFuel * (1 + 0.25 * mas_tons);
    }
};



int main() {
    cout << "=== test personal ===\n";
    Personal car(50, 2, 0.1);   // 50 л, 2 пасажири, базова витрата 0.1 л/км
    car.go(100);

    cout << "\n=== test truck ===\n";
    Truck truck(120, 3, 0.25);  // 120 л, 3 тонни вантажу, базова 0.25 л/км
    truck.go(200);

    return 0;
}

