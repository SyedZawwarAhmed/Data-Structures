#include <iostream>
#include "HashMap.h"

using namespace std;

int main()
{
    HashMap hashMap(11);
    hashMap.insert(11);
    hashMap.insert(13);
    hashMap.insert(24);
    hashMap.insert(23);
    hashMap.insert(39);
    hashMap.insert(45);
    cout << hashMap.find(2) << endl;
    cout << hashMap.find(13) << endl;
    cout << hashMap.find(24) << endl;
    cout << hashMap.find(23) << endl;
    cout << hashMap.find(39) << endl;
    cout << hashMap.find(45) << endl;
    hashMap.print();
    return 0;
}