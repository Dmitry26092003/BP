#include <iostream>

using namespace std;

int main()
{
    const int n = 8;
    int mass[n];
    for (int i = 0; i < n; i++)//Заполнения массива
    {
        mass[i] = i * i;
    }
    cout << "Array output" << endl;
    for (int mas : mass)
    {
        cout << mas << " ";//Вывод квадрата натурального числа
    }
}
