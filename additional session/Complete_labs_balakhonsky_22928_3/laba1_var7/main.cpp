#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>
#include "LabsCode/customFunctions.h"

using namespace std;

const vector<int> N = { 5, 10, 15 };
const vector<double> X = { 0.5, 1.1, 1.7, 2.3, 2.9 };
const vector<double> E = { 0.001, 0.0001, 0.00001 };
const int tab = 4;

int main(){

    for(auto n : N){
        cout << "\nN = " << n << endl;
        cout << "_________________________________________________________\n";
        for(auto x : X){
            double biba = tailersRow_N(x, n); // Вычисление ln
            // Вывод в столбики
            cout.fill(' ');
            cout << "|" << set_spaces(tab) << "ln("; cout.width(3); cout << x; cout << ")" << set_spaces(tab); // Вывод Х
            cout << "|" << set_spaces(tab); cout.width(9); cout << biba; cout << set_spaces(tab); // Вывод результата Функции
            cout.setf(ios::scientific);
            cout << "|" << set_spaces(tab); cout.width(14); cout << biba-log(x); cout << set_spaces(tab); // Вывод погрешности
            cout.setf(ios::fixed);
            cout << "|" << "\n";
        }
        cout << "|________________________________________________________|\n";
    }

    /*

        ✔️ task 2 ✔️

    */

    for(auto e : E){
        cout << "\nE = " << e << endl;
        cout << "___________________________________________________________________\n";
        for(auto x : X){
            vector<double> biba = tailersRow_E(x, e); // Вычисление ln
            cout.fill(' ');
            cout << "|" << set_spaces(tab) << biba[1] << set_spaces(tab); // Вывод индекса
            cout << "|" << set_spaces(tab) << "ln("; cout.width(3); cout << x; cout << ")" << set_spaces(tab); // Вывод Х
            cout << "|" << set_spaces(tab); cout.width(9); cout << biba[0]; cout << set_spaces(tab); // Вывод результата Функции
            cout.setf(ios::scientific);
            cout << "|" << set_spaces(tab); cout.width(14); cout << biba[0]-log(x); cout << set_spaces(tab); // Вывод погрешности
            cout.setf(ios::fixed);
            cout << "|" << "\n";
        }
        cout << "|__________________________________________________________________|\n";
    }
}
