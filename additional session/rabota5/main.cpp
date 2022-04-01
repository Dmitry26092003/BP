#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void check(int rand01, int rand02, int Nrand){
    while ((Nrand <= 0) or (Nrand > (rand02 - rand01 + 1)) or (rand01 <= 0) or (rand02 <= 0)){
        cout << "Invalid input, please try again" << endl;
        cout << "Enter array size => ";
        cin >> Nrand;
        cout << "Enter smallers random number => ";
        cin >> rand01;
        cout << "Enter largest random number => ";
        cin >> rand02;
    }
}

int main(){
    srand(time(0));

    int rand01=0, rand02=0, Nrand=0;
    cout << "Enter array size => ";
    cin >> Nrand;
    cout << "Enter smallers random number => ";
    cin >> rand01;
    cout << "Enter largest random number => ";
    cin >> rand02;
    check(rand01, rand02, Nrand);

    int* mass= new int[Nrand];
    cout << "\nSequence of unique random numbers" << endl;
    cout << "Range from " << rand01 << " to " << rand02 << ", total " << Nrand << " numbers" << endl;

    for (int i = 0; i < Nrand; i++){
        mass[i] = rand() % rand02 + rand01;
    }

    //uniqueness check loop
    for (int i = 0; i < Nrand; i++){
        for (int j = Nrand; j > i; j--){
            if (mass[i] == mass[j] and i != j){
                mass[i] = rand() % rand02 + rand01;
                j = 90;
                i = 0;
            }
        }
    }

    //array output
    for (int i = 0; i < Nrand; i++){
        cout << setw(2) << i+1 << setw(8) << mass[i] << endl;
    }
}
