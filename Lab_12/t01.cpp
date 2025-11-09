#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x,y,z;
    cout << "Enter the value of x:";
    cin >> x;
    cout << "Enter the value of y:";
    cin >> y;
    z = pow(x,y);
    cout << z << "\n";
    cout << z << ", "<< scientific << z << "\n";
}