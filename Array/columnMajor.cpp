#include <iostream>

using namespace std;

int main() {
    int x = 4;
    int y = 4;
    int matrix[x][y] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int twoDimensionalArray[x][y];
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++)
            twoDimensionalArray[i][j] = matrix[j][i];
    }

    uintptr_t baseAddress = (uintptr_t)&twoDimensionalArray[0][0];
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++)
            printf("twoDimensionalArray[%d][%d] %d @ Real Address:- %u | Calculated Address:- %u\n", i, j, twoDimensionalArray[j][i], &twoDimensionalArray[j][i], baseAddress + (j*y + i)*sizeof(int));
    }
    return 0;
}