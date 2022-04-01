#include <iostream>
#include "stdio.h"


using namespace std;

const int N = 10; // Размер Матрицы

const int a = 4; // Стартовое значение диапазона случайных чисел
const int b = 12; // Конечное значение ...

void print_matrix(int matrix[N][N]){
    for (int y=0; y<N; y++){
        for (int x=0; x<N; x++){
            printf("%6d", matrix[x][y]);
        }
        printf("\n");
    }
}

int main() {

    int M01[N][N]; // Обявление масива

    for (int y=0; y<N; y++){
        for (int x=0; x<N; x++){
            M01[x][y] = rand() % (b - a + 1) + a;
        }
    }
    printf("\nGenerated array:\n");
    print_matrix(M01);

    for (int i=0; i<N; i++){
        M01[i][i] = M01[0][0];
        M01[i][N-i-1] = M01[0][0];
    }
    printf("\nArray after executing step 3 from the file with options (changing diagonals):\n");
    print_matrix(M01);

    int M02[N][N];
    for (int y=0; y<N; y++){
        for (int x=0; x<N; x++){
            M02[N-1-x][y] = M01[y][x];
        }
    }
    printf("\nRotate the array by 90 degrees:\n");
    print_matrix(M02);

    int R01[N][N];
    for (int y=0; y<N; y++){
        for (int x=0; x<N; x++){
            R01[y][x] = M01[y][x]*M01[y][x]+M02[y][x]*M02[y][x];
        }
    }

    printf("\nSum of squares of elements of arrays M01 and M02:\n");
    print_matrix(R01);

    int R02[N][N];
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            R02[i][j] = 0;
            for (int p=0; p<N; p++){
                R02[i][j] += M02[i][p] * M01[p][j];
            }
        }
    }
    printf("\nProduct of arrays:\n");
    print_matrix(R02);

    return 0;
}
