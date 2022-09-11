#include <iostream>

using namespace std;

int main()
{
    int noOfRows;
    int *noOfColumns = new int[noOfRows];
    cout << "Enter the number of rows: ";
    cin >> noOfRows;
    int **jaggedArray;
    jaggedArray = new int *[noOfRows];
    for (int i = 0; i < noOfRows; i++)
    {
        cout << "Enter the number of columns for row " << i << ": ";
        cin >> noOfColumns[i];
        jaggedArray[i] = new int[noOfColumns[i]];
        for (int j = 0; j < noOfColumns[i]; j++)
        {
            cout << "Enter the value for row " << i << " and column " << j << ": ";
            cin >> jaggedArray[i][j];
        }
    }

    for (int i = 0; i < noOfRows; i++)
    {
        for (int j = 0; j < noOfColumns[i]; j++)
        {
            cout << "jaggedArray[" << i << "][" << j << "] " << jaggedArray[i][j] << " " << printf("@ %u", &jaggedArray[i][j]) << endl;
        }
        cout << endl;
    }

    return 0;
}