#include <iostream>
#include <ctime>

using namespace std;


const int D1 = 5000;
const int D2 = 10000;
const int D3 = 15000;

const short B = 2;

const float N = 0.15;


class Car{
private:
    float random(float a, float b) {
        short k = 1000;
        a *= k;
        b *= k;
        float rec = rand() % (int) (b - a) + a;
        return rec / k;
    }


public:
    float fuel_consumption;
    int other_costs;
    int price;

    Car(int st, float r, int z, float k0, float k1){
        price = st * random(k0, k1);
        fuel_consumption = r *  random(k0, k1);
        other_costs = z * random(k0, k1);
    }

    ~Car(){

    }

    float depreciation_of_cars(float n) const{
        return (float) price * n;
    }

    float gasoline_costs(int d, short b) const{
        return ((float) d/100) * fuel_consumption * b;
    }

    int calculate_expenses(float n, int d, short b) const{
        return depreciation_of_cars(n) + gasoline_costs(d, b) + other_costs;
    }
};

ostream& operator<< (ostream &out, const Car &car) {
    return out
        << "Price: " << car.price << endl
        << "Fuel_consumption: " << car.fuel_consumption << endl
        << "Other_costs: " << car.other_costs << endl;
}

int main() {
    const int st = 8000;
    const float r = 6.5;
    const int z = 600;
    const float k0 = 1.4;
    const float k1 = 2.3;

    Car car1(st, r, z, k0, k1);
    cout << "Create object car1" << endl;
    cout << car1 << endl;

    Car car2(st, r, z, k0, k1);
    cout << "Create object car2" << endl;
    cout << car2 << endl;

    Car car3(st, r, z, k0, k1);
    cout << "Create object car3" << endl;
    cout << car3 << endl;


    cout << "Kilometre: " << D1 << endl;
    cout << "Annual operating costs for car1\t" << car1.calculate_expenses(N, D1, B) << endl;
    cout << "Annual operating costs for car2\t" << car2.calculate_expenses(N, D1, B) << endl;
    cout << "Annual operating costs for car3\t" << car3.calculate_expenses(N, D1, B) << endl  << endl;


    cout << "Kilometre: " << D2 << endl;
    cout << "Annual operating costs for car1\t" << car1.calculate_expenses(N, D2, B) << endl;
    cout << "Annual operating costs for car2\t" << car2.calculate_expenses(N, D2, B) << endl;
    cout << "Annual operating costs for car3\t" << car3.calculate_expenses(N, D2, B) << endl  << endl;


    cout << "Kilometre: " << D3 << endl;
    cout << "Annual operating costs for car1\t" << car1.calculate_expenses(N, D3, B) << endl;
    cout << "Annual operating costs for car2\t" << car2.calculate_expenses(N, D3, B) << endl;
    cout << "Annual operating costs for car3\t" << car3.calculate_expenses(N, D3, B) << endl  << endl;
    return 0;
}
