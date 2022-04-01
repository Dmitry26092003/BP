//#include <iostream>
//#include "cmath"
//
//using namespace std;
//
//const double pi = 3.1415926535;
//
//const int N[5] = {10, 50, 100, 500, 1000};
//
////_____________________________________________//
//// y1 = x^2*e^(-x^2)
//const double a1 = 0;
//const double b1 = 3;
//const double I_01 = 0.442918559423631;
//
//double function_n1(double x) {
//    return pow(x, 2)*exp(-pow(x, 2));
//}
////_____________________________________________//
//
////_____________________________________________//
//// y2 = (1+sin(x))^2
//const double a2 = -pi/2;
//const double b2 = 3/2*pi;
//const double I_02 = 9.424777960769379;
//
//double function_n2(double x) {
//    return pow((1 + sin(x)), 2);
//}
////_____________________________________________//
//
//string set_spaces(int spaceQ){ // Табуляция для красивого вывода))
//    string result = "";
//    for (int i = 0; i < spaceQ; i++){
//        result += " ";
//    }
//    return result;
//}
//
//
//double rectangle_method(unsigned short int n, double a, double b, double (*f_x)(double)) {
//    double integral = 0;
//    double s = (b-a)/n;
//    for (int k = 1; k<=n; k++) {
//        double w = s;
//        double h = f_x(a + s * k);
//        integral += w * h;
//    }
//    return integral;
//}
//
//double trapezoid_method(unsigned short int n, double a, double b, double (*f_x)(double)) {
//    double integral = 0;
//    double s = (b-a)/n;
//    for (int k = 1; k<=n; k++) {
//        double base_1 = f_x(a + s * (k-1));
//        double base_2 = f_x(a + s * k);
//        double h = s;
//        integral += (base_1 + base_2) / 2 * h;
//    }
//    return integral;
//}
//
//double simpson_s_method(unsigned short int n, double a, double b, double (*f_x)(double)) {
//    double s = (b-a)/n;
//    int m = n/2;
//    double sum = 0;
//    for (int i = 1; i < m; i++) {
//        sum += 4*f_x(a+s*(2*i-1))+2*f_x(a+s*2*i);
//    }
//    double integral = s/3*(f_x(a)+f_x(b)+4*f_x(a+s*(2*m-1)))+s/3*sum;
//    return integral;
//}
//
//int main() {
//    cout.fill(' ');
//    cout.precision(8);
//    // function_n1
//    cout << endl << "Rectangle method" << endl;
//    cout << "Number of Partitions" << "\t" << "The Value of the Integral" << "\t" << "Calculation Error" << endl;
//    for (auto n:N) {
//        double integral = rectangle_method(n, a1, b1, function_n1);
//        cout.width(10); cout << n << set_spaces(15);
//        cout.width(15); cout << integral << set_spaces(17);
//        cout.setf(ios::scientific);
//        cout.width(15); cout << I_01 - integral << endl;
//        cout.setf(ios::fixed);
//    }
//
//    cout << endl << "Trapezoid method" << endl;
//    cout << "Number of Partitions" << "\t" << "The Value of the Integral" << "\t" << "Calculation Error" << endl;
//    for (auto n:N) {
//        double integral = trapezoid_method(n, a1, b1, function_n1);
//        cout.width(10); cout << n << set_spaces(15);
//        cout.width(15); cout << integral << set_spaces(17);
//        cout.setf(ios::scientific);
//        cout.width(15); cout << I_01 - integral << endl;
//        cout.setf(ios::fixed);
//    }
//
//    cout << endl << "Simpson's method" << endl;
//    cout << "Number of Partitions" << "\t" << "The Value of the Integral" << "\t" << "Calculation Error" << endl;
//    for (auto n:N) {
//        double integral = simpson_s_method(n, a1, b1, function_n1);
//        cout.width(10); cout << n << set_spaces(15);
//        cout.width(15); cout << integral << set_spaces(17);
//        cout.setf(ios::scientific);
//        cout.width(15); cout << I_01 - integral << endl;
//        cout.setf(ios::fixed);
//    }
//
//    // function_n2
//    cout << endl << "Rectangle method" << endl;
//    cout << "Number of Partitions" << "\t" << "The Value of the Integral" << "\t" << "Calculation Error" << endl;
//    for (auto n:N) {
//        double integral = rectangle_method(n, a2, b2, function_n2);
//        cout.width(10); cout << n << set_spaces(15);
//        cout.width(15); cout << integral << set_spaces(17);
//        cout.setf(ios::scientific);
//        cout.width(15); cout << I_02 - integral << endl;
//        cout.setf(ios::fixed);
//    }
//
//    cout << endl << "Trapezoid method" << endl;
//    cout << "Number of Partitions" << "\t" << "The Value of the Integral" << "\t" << "Calculation Error" << endl;
//    for (auto n:N) {
//        double integral = trapezoid_method(n, a2, b2, function_n2);
//        cout.width(10); cout << n << set_spaces(15);
//        cout.width(15); cout << integral << set_spaces(17);
//        cout.setf(ios::scientific);
//        cout.width(15); cout << I_02 - integral << endl;
//        cout.setf(ios::fixed);
//    }
//
//    cout << endl << "Simpson's method" << endl;
//    cout << "Number of Partitions" << "\t" << "The Value of the Integral" << "\t" << "Calculation Error" << endl;
//    for (auto n:N) {
//        double integral = simpson_s_method(n, a2, b2, function_n2);
//        cout.width(10); cout << n << set_spaces(15);
//        cout.width(15); cout << integral << set_spaces(17);
//        cout.setf(ios::scientific);
//        cout.width(15); cout << I_02 - integral << endl;
//        cout.setf(ios::fixed);
//    }
//    return 0;
//}
//

#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.1415926535;

const int N[5] = {10, 50, 100, 500, 1000};

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

string set_spaces(int spaceQ){
    string result = "";
    for (int i = 0; i < spaceQ; i++){
        result += " ";
    }
    return result;
}

double rectangle_method(unsigned short int n, double a, double b, double (*f_x)(double)) {
    double integral = 0;
    double s = (b-a)/n;
    for (int k = 1; k<=n; k++) {
        double w = s;
        double h = f_x(a + s * k);
        integral += w * h;
    }
    return integral;
}

double trapezoid_method(unsigned short int n, double a, double b, double (*f_x)(double)) {
    double integral = 0;
    double s = (b-a)/n;
    for (int k = 1; k<=n; k++) {
        double base_1 = f_x(a + s * (k-1));
        double base_2 = f_x(a + s * k);
        double h = s;
        integral += (base_1 + base_2) / 2 * h;
    }
    return integral;
}

double simpson_s_method(unsigned short int n, double a, double b, double (*f_x)(double)) {
    double s = (b-a)/n;
    int m = n/2;
    double sum = 0;
    for (int i = 1; i < m; i++) {
        sum += 4*f_x(a+s*(2*i-1))+2*f_x(a+s*2*i);
    }
    double integral = s/3*(f_x(a)+f_x(b)+4*f_x(a+s*(2*m-1)))+s/3*sum;
    return integral;
}

int main() {
    cout.fill(' ');
    cout.precision(8);
    // function_n1
    cout << endl << "Rectangle method" << endl;
    cout << "Number of Partitions" << "\t" << "The Value of the Integral" << "\t" << "Calculation Error" << endl;
    for (auto n:N) {
        double integral = rectangle_method(n, a1, b1, function_n1);
        cout.width(10); cout << n << set_spaces(15);
        cout.width(15); cout << integral << set_spaces(17);
        cout.setf(ios::scientific);
        cout.width(15); cout << I_01 - integral << endl;
        cout.setf(ios::fixed);
    }

    cout << endl << "Trapezoid method" << endl;
    cout << "Number of Partitions" << "\t" << "The Value of the Integral" << "\t" << "Calculation Error" << endl;
    for (auto n:N) {
        double integral = trapezoid_method(n, a1, b1, function_n1);
        cout.width(10); cout << n << set_spaces(15);
        cout.width(15); cout << integral << set_spaces(17);
        cout.setf(ios::scientific);
        cout.width(15); cout << I_01 - integral << endl;
        cout.setf(ios::fixed);
    }

    cout << endl << "Simpson's method" << endl;
    cout << "Number of Partitions" << "\t" << "The Value of the Integral" << "\t" << "Calculation Error" << endl;
    for (auto n:N) {
        double integral = simpson_s_method(n, a1, b1, function_n1);
        cout.width(10); cout << n << set_spaces(15);
        cout.width(15); cout << integral << set_spaces(17);
        cout.setf(ios::scientific);
        cout.width(15); cout << I_01 - integral << endl;
        cout.setf(ios::fixed);
    }

    // function_n2
    cout << endl << "Rectangle method" << endl;
    cout << "Number of Partitions" << "\t" << "The Value of the Integral" << "\t" << "Calculation Error" << endl;
    for (auto n:N) {
        double integral = rectangle_method(n, a2, b2, function_n2);
        cout.width(10); cout << n << set_spaces(15);
        cout.width(15); cout << integral << set_spaces(17);
        cout.setf(ios::scientific);
        cout.width(15); cout << I_02 - integral << endl;
        cout.setf(ios::fixed);
    }

    cout << endl << "Trapezoid method" << endl;
    cout << "Number of Partitions" << "\t" << "The Value of the Integral" << "\t" << "Calculation Error" << endl;
    for (auto n:N) {
        double integral = trapezoid_method(n, a2, b2, function_n2);
        cout.width(10); cout << n << set_spaces(15);
        cout.width(15); cout << integral << set_spaces(17);
        cout.setf(ios::scientific);
        cout.width(15); cout << I_02 - integral << endl;
        cout.setf(ios::fixed);
    }

    cout << endl << "Simpson's method" << endl;
    cout << "Number of Partitions" << "\t" << "The Value of the Integral" << "\t" << "Calculation Error" << endl;
    for (auto n:N) {
        double integral = simpson_s_method(n, a2, b2, function_n2);
        cout.width(10); cout << n << set_spaces(15);
        cout.width(15); cout << integral << set_spaces(17);
        cout.setf(ios::scientific);
        cout.width(15); cout << I_02 - integral << endl;
        cout.setf(ios::fixed);
    }
    return 0;
}
