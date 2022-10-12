#include <iostream>
#include "MultidimensionalArray.h"

using namespace std;

int main()
{
    int noOfDimensions = 3;
    int sizesOfDimensions[] = {2, 3, 4};
    MultidimensionalArray arr1(noOfDimensions, sizesOfDimensions);

    int item = 0;
    for (int k = 0; k < 2; k++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int i = 0; i < 4; i++)
            {
                int indices[] = {k, j, i};
                arr1.setItem(++item, indices);
            }
        }
    }

    cout << "\n" << endl;

    for (int k = 0; k < 2; k++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int i = 0; i < 4; i++)
            {
                int indices[] = {k, j, i};
                cout << k << " " << j << " " << i << " ";
                cout << arr1.getItem(indices) << " ";
                cout << arr1.getAddress(indices) << endl; 
            }
        }
    }
    
    return 0;
}