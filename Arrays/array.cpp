#include <iostream>

using namespace std;

int main()
{
    const int length = 10;
    int array[length];
    for (int i = 0; i < length; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i < length; i++)
    {
        cout << "a[" << i << "] " << array[i] << " @ " << &array[i] << " or " << printf("%u", &array) << endl;
    }
    return 0;
}