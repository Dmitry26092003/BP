#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>


using namespace std;

const double S = 0.583333333247580;
const vector<int> N = {100, 10000, 1000000, 10000000};

double function_1(double x){
    return cbrt(x);
}

double function_2(double x){
    return pow(x, 5);
}

int main() {
    cout << "Figure area calculation with Monte Carlo's method." << endl;
    cout << "Accurate area: "<< setprecision(15) << S << endl << endl;

    for (auto n:N) {
        int point_counter = 0;
        for (int i = 0; i < n; i++) {
            double point_x = (double) (rand() % 1000) / 1000;
            double point_y = (double) (rand() % 1000) / 1000;
            if (point_y >= function_2(point_x) and point_y <= function_1(point_x))
                point_counter++;
        }
        cout << "Total points: " << n << endl;
        double area = (double) point_counter / (double) n;
        cout
            << "Figure area: " << setw(13) << left << setprecision(8) << area
            << "Inaccuracy: " << fixed << setprecision(10) << abs(area - S)
            << endl << endl;
    }

    return 0;
}
