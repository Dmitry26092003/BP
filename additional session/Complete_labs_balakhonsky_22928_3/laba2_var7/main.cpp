#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

const int arraySizeFrom = 7;
const int arraySizeTo = 18;
const int arrayRangeFrom = 4;
const int arrayRangeTo = 11;
const int arrayShiftFrom = 4;
const int arrayShiftTo = 6;

int random(int from, int to){
    return rand() % (to - from + 1) + from;
}

const void arrayOutput(vector<int> arr){
    for(auto e : arr){
        cout << e <<  " | ";
    }
    cout << endl;
}

vector<int> arrayShiftLeft(vector<int> arr){
    int temp = arr[0];
    for(int i = 0; i < arr.size(); i++){
        arr[i] = arr[i + 1];
    }
    arr[arr.size() - 1] = temp;
    return arr;
}

vector<int> loopedArrayShiftLeft(vector<int> arr, int shiftingNumber){
    vector<int> test;
    for(int i = 0; i < shiftingNumber; i++){
        if (i == 0){
            test = arrayShiftLeft(arr);
        }else {
            test = arrayShiftLeft(test);
        }
    }
    return test;
}

vector<int> arrayShiftRight(vector<int> arr){
    int temp = arr[arr.size() - 1];
    for(int i = arr.size() - 2; i >= 0; i--){
        arr[i + 1] = arr[i];
    }
    arr[0] = temp;
    return arr;
}

vector<int> loopedArrayShiftRight(vector<int> arr, int shiftingNumber){
    vector<int> test;
    for(int i = 0; i < shiftingNumber; i++){
        if (i == 0){
            test = arrayShiftRight(arr);
        }else {
            test = arrayShiftRight(test);
        }
    }
    return test;
}

void bubbleSort(vector<int>& a, bool des = false){
    bool swapp = true;
    while(swapp){
        swapp = false;
        for (size_t i = 0; i < a.size() - 1; i++) {

            if (des){
                if (a[i] < a[i + 1] ){
                    a[i] += a[i + 1];
                    a[i + 1] = a[i] - a[i + 1];
                    a[i] -= a[i + 1];
                    swapp = true;
                }
            }else{
                if (a[i] > a[i + 1] ){
                    a[i] += a[i + 1];
                    a[i + 1] = a[i] - a[i + 1];
                    a[i] -= a[i + 1];
                    swapp = true;
                }
            }
        }
    }
}

int main(){
    // setting token for rand number
    srand(time(NULL));
    const int L = random(arraySizeFrom, arraySizeTo);
    vector<int> M01;

    //filling the array
    for(int i = 0; i < L; i++){
        M01.push_back(random(arrayRangeFrom, arrayRangeTo));
    }

    cout << "Array length: " << L << endl;
    cout << "\nGenerated array M01[" << L << "]:" << endl;
    arrayOutput(M01);

    vector<int> M02 = M01;

    for(int i = 0; i < L; i++){
        if (M02[i] <= 6) {
            M02[i] = M02[i] + 3 ;
        }
    }

    cout << "\nAdd 3 to array elements that are less than or equal to 6" << endl; // Ко всем элементам массива M02 , которые <= 6, прибавить 3;
    arrayOutput(M02);

    const int arrayShiftIndex = random(arrayShiftFrom, arrayShiftTo);
    if(M02[1] % 2 == 1){
        cout << "\nThe array was shifted left for "<< arrayShiftIndex <<" positions" << endl;
        arrayOutput(loopedArrayShiftLeft(M02, arrayShiftIndex));
    }else{
        cout << "\nThe array was shifted right for "<< arrayShiftIndex <<" positions" << endl;
        arrayOutput(loopedArrayShiftRight(M02, arrayShiftIndex));
    }

    bubbleSort(M02, true);

    cout << "\nThe array was bubble sorted in descending order" << endl;
    arrayOutput(M02);

    vector<int> M03 = {};
    for(int i = 0; i < L; i++){
        M03.push_back(0);
    }

    vector<int> M02C = M02;

    for(int i = 0; i < M02.size(); i++){
        int rIndex = random(0, M02C.size() - 1);
        M03[i] = M02C[rIndex];
        M02C.erase(M02C.begin() + rIndex);
    }

    cout << "\nThe array M03 was created randomly with M02's elements" << endl;
    arrayOutput(M03);
}
