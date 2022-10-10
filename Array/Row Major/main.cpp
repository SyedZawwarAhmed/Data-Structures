#include <iostream>
#include "MultidimensionalArray.h"

using namespace std;

int main() {
    int noOfDimensions = 3;
    int sizesOfDimensions[] = {2,3,4};
    MultidimensionalArray arr1(noOfDimensions, sizesOfDimensions); 

    int item = 0;
    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<4; k++) {
                int indices[] = {i, j, k};
                arr1.setItem(++item, indices);
            }
        }
    }

    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<4; k++) {
                int indices[] = {i, j, k};
                cout << i << " " << j << " " << k << " "; 
                cout << arr1.getItem(indices) << " ";
                cout << arr1.getAddress(indices) << endl;
            }
        }
    }
    return 0;
}