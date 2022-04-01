#include <iostream>

using namespace std;

int main() {
    cout << "Task #1" << endl;
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;
    if (n < 0){
        cout << "Error! Please enter a positive number!";
    }
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) cout << i << " | ";
    }

    cout << "\n\nTask #2" << endl;

    int a, b;
    float x;

    for (int i = 0; i < 6; i++){
        a = rand() % 17;
        b = rand() % 17;

        cout
            << "A*X=B" << endl
            << "A = " << a << endl
            << "B = " << b << endl;
        if (a == 0){
            if (b == 0) cout << "X = any number" << endl;
            else cout << "The equation has no solutions" << endl;
        }
        else {
            x = (float)b / (float)a;
            cout << "X = " << x << endl;
        }
        cout << endl;

    }
    return 0;
}
