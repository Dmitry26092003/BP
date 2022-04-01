#include <iostream>

using namespace std;

int main () {
    int number;
    cout << "Enter the number" << endl;
    cin >> number;

    // делаем проверку на отрицательное число
    if(number <= 0){
        cout << "Error! Please, enter a positive number";
        return 0;
    }
    //выводим нечетные числа в строчку
    for(int i = 0; i < number; i++){
        cout << 1+2*i << " | ";
    }
    cout << endl;
    //выводим четные числа в строчку
    for(int i = 0; i < number; i++){
        cout << 2*i << endl;
    }
}