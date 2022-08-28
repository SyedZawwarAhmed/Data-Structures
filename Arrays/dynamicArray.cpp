#include <iostream>

using namespace std;

int main()
{
    try
    {
        int length;
        cin >> length;
        int *dynamicArray = new int[length];

        for (int i = 0; i < length; i++)
        {
            cin >> dynamicArray[i];
        }
        for (int i = 0; i < length; i++)
        {
            cout << "a[" << i << "] " << dynamicArray[i] << " @ " << &dynamicArray[i] << " or " << printf("%u", &dynamicArray) << endl;
            ;
        }
    }
    catch (const exception &e)
    {
    }

    return 0;
}