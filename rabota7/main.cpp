#include <iostream>
#include <cmath>

using namespace std;

const unsigned int n = 10000;
const double pi = 3.1415926535;


//  variant_7
//_____________________________________________//
// y1 = x^2*e^(-x^2)
const double a1 = 0;
const double b1 = 2;
const double I_01 = 0.297427529679357;


double function_n1(double x) {
    return pow(x, 3)*exp(-pow(x, 3));
}
//_____________________________________________//

//_____________________________________________//
// y2 = (1+sin(x))^2
const double a2 = 0;
const double b2 = pi;
const double I_02 = 3.764068559415687;

double function_n2(double x) {
    return x * pow(sin(x),0.5);
}
//_____________________________________________//


class Integer
{
private:
    double a, b;
    int n;
    double (*f_x)(double);
    double rectangle_method() {
        double integral = 0;
        double s = (b-a)/n;
        for (int k = 1; k<=n; k++) {
            double w = s;
            double h = f_x(a + s * k);
            integral += w * h;
        }
        return integral;
    }

public:
    void set_limits_of_integration(double date_a, double date_b){
        a = date_a;
        b = date_b;
    }
    void set_count_of_interval_sections(int date_n){
        n = date_n;
    }
    void set_integrand_function(double (*date_f_x)(double)){
        f_x = date_f_x;
    }
    double get_integral(){
        return rectangle_method();
    }
};

int main(){
    double integral_;
    Integer integral;

    integral.set_limits_of_integration(a1, b2);
    integral.set_count_of_interval_sections(n);
    integral.set_integrand_function(function_n1);
    integral_ = integral.get_integral();

    cout << "Rectangle method" << endl;
    cout << "Number of Partitions: " << n << endl;
    cout << "Limits_of_integration: [" << a1 << "; " << b1 << "]" << endl;
    cout << "Integrand_function: y = x^2*e^(-x^2)"  << endl;
    cout << "The Value of the Integral: " << integral_ << endl;
    cout << "Calculation Error: " << (I_01 - integral_) << endl << endl;


    integral.set_limits_of_integration(a2, b2);
    integral.set_count_of_interval_sections(n);
    integral.set_integrand_function(function_n2);
    integral_ = integral.get_integral();

    cout << "Rectangle method" << endl;
    cout << "Number of Partitions: " << n << endl;
    cout << "Limits_of_integration: [" << a2 << "; " << b2 << "]" << endl;
    cout << "Integrand_function: y = (1+sin(x))^2"  << endl;
    cout << "The Value of the Integral: " << integral_ << endl;
    cout << "Calculation Error: " << (I_02 - integral_) << endl << endl;
};