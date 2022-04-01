#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    int RandNum, pointsA = 0, pointsB = 0, NumGame = 1, Games = 5;
    int Player = 1;
    const int N = 6;
    //Set loop
    for (int Set = 1; Set < 3; Set++) {

        cout << " Set №" << Set << endl;
        cout << endl;
        NumGame = 1;
        //Game loop
        for (int j = 0; j < Games; j++) {
            int sumA = 0, sumB = 0;
            int ArrPlayerA[N] = {0, 0, 0, 0, 0, 0};
            int ArrPlayerB[N] = {0, 0, 0, 0, 0, 0};
            //Loop for player's A cube random value
            for (int i = 0; i < N; i++) {
                RandNum = rand() % 6;
                ArrPlayerA[RandNum] += RandNum + 1;
            }
            //Loop for player's B cube random value
            for (int i = 0; i < N; i++) {
                RandNum = rand() % 6;
                ArrPlayerB[RandNum] += RandNum + 1;
            }
            //Result loop
            for (int i = 1; i < N; i++) {
                sumA += ArrPlayerA[i];
                sumB += ArrPlayerB[i];
            }

            cout << " Game №" << NumGame << endl;
            cout << " Points A = " << sumA << endl;
            cout << " Points B = " << sumB << endl;


            cout << " Set №" << Set << " completed with points: A = " << pointsA << " B = " << pointsB << endl;
            cout << endl;
            cout << " Game total points: A = " << pointsA << " B = " << pointsB << endl;
            cout << endl;

        }
        // Winner output
        if (pointsA > pointsB) {
            cout << "\nPlayer A wins!";
        } else if (pointsB > pointsA) {
            cout << "\nPlayer B wins!";
        } else {
            cout << "\nDraw";
        }
        cout << endl;
    }
}