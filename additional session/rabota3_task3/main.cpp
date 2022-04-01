#include <iostream>
#include "cmath"

using namespace std;

double disc_func(int a, int b, int c){
    return b*b-4*a*c;
}

int main() {
    int a, b, c;
    cout << "ax^2 bx + c = 0" << endl;
    cout << "Enter A --> "; cin >> a;
    cout << "Enter B --> "; cin >> b;
    cout << "Enter C --> "; cin >> c;

    double D = disc_func(a, b, c);
    cout << endl << "D = " << D << endl;

    if (D < 0)
        cout << "The equation has no solutions" << endl;
    else if (D > 0)
        cout << "x1 = " << (-b + sqrt(D)) << endl << "x2 = " << (-b - sqrt(D)) << endl;
    else
        cout << "x1 = x2 = " << -b/2*a << endl;
    return 0;
}
